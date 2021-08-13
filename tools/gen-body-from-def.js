const fs = require("fs");
const path = require("path");
const { promisify } = require("util");

const readFile = promisify(fs.readFile);
const writeFile = promisify(fs.writeFile);

const definitionRegex =
  /EXPORT\s([a-zA-Z\s\*]{1,})([A-Z]{1,1}[a-z]{1,})_([a-zA-Z]{1,})\(([a-zA-Z\s\*\,]{1,})\);/gm;
// match: whole line
// group 1: return type
// group 2: class name
// group 3: cpp-sdk func name
// group 4: arg as string, seperated by comma

const reinterprets = {
  Player: "alt::IPlayer*",
  Vehicle: "alt::IVehicle*",
};

const returnsWithImplicitOrNoCast = [
  "long",
  "bool",
  "float",
  "unsigned long",
  "int",
];

const defaultGetMeta = (varName, cast, base, args) =>
  `
    auto ${varName} = reinterpret_cast<${cast}>(${base.name});
    auto meta = ${varName}->GetMetaData(${args[0].name});

    // Temporary
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
`;
const defaultSetMeta = (varName, cast, base, args) =>
  `
    auto ${varName} = reinterpret_cast<${cast}>(${base.name});
    auto value = reinterpret_cast<alt::IMValue*>(${args[1].name});

    ${varName}->SetMetaData(${args[0].name}, value);
`;
const defaultDeleteMeta = (varName, cast, base, args) =>
  `
    auto ${varName} = reinterpret_cast<${cast}>(${base.name});
    ${varName}->DeleteMetaData(${args[0].name});
    ${varName}->RemoveRef();
`;

const defaultCast = (varName, cast, base) =>
  `auto ${varName} = reinterpret_cast<${cast}>(${base.name});`;
const defaultFunc = (varName, funcName, args) =>
  `${varName}->${funcName}(${args.map((x) => x.name).join(", ")});`;
const cStrFunc = (varName, funcName, args) =>
  `${varName}->${funcName}(${args.map((x) => x.name).join(", ")}).CStr();`;
const voidRefFunc = (varName, funcName, args) =>
  `${varName}->${funcName}(${args.map((x) => x.name).join(", ")}).Get();`;

const emptyTemplate = (definition) => `${definition}\n{\n\n}\n`;
const fullTemplate = (definition, body) => `${definition}\n${body}`;

function validateSetMetaDefinition(args) {
  if (args[0].type.replace(/\s/g, "") !== "constchar*") return false;
  if (args[1].type.replace(/\s/g, "") !== "void*") return false;
  return true;
}

function validateGetAndDeleteMetaDefinition(args) {
  if (args[0].type.replace(/\s/g, "") !== "constchar*") return false;
  return true;
}

function generateCAPIFunction(match, className, funcName, returnType, argStr) {
  const definition = match.substring(0, match.length - 1);
  const mainVarName = className.toLowerCase();
  const castTo = reinterprets[className];
  const trimmedReturnType = returnType.trim();
  const args = argStr.split(",").map((val) => {
    const lastIdxOfSpace = val.lastIndexOf(" ") + 1;
    let type = val.substring(0, lastIdxOfSpace).trim();
    let name = val.substring(lastIdxOfSpace, val.length);
    if (name.charAt(0) === "*") {
      name = name.substring(1, name.length);
      type += " *";
    }
    return {
      type,
      name,
    };
  });
  const base = args.shift();

  let valid = true;
  let isMeta = true;
  let funcBody = `{\n`;

  if (typeof castTo == "undefined")
    throw new Error(`Could not find cast for class ${className}`);

  if (funcName.includes("Set") && funcName.includes("MetaData")) {
    if (validateSetMetaDefinition(args)) {
      funcBody += defaultSetMeta(mainVarName, castTo, base, args);
    } else return [emptyTemplate(definition), false];
  } else if (funcName.includes("Get") && funcName.includes("MetaData")) {
    if (validateGetAndDeleteMetaDefinition(args)) {
      funcBody += defaultGetMeta(mainVarName, castTo, base, args);
    } else return [emptyTemplate(definition), false];
  } else if (funcName.includes("Delete") && funcName.includes("MetaData")) {
    if (validateGetAndDeleteMetaDefinition(args)) {
      funcBody += defaultDeleteMeta(mainVarName, castTo, base, args);
    } else return [emptyTemplate(definition), false];
  } else {
    isMeta = false;
  }

  if (!isMeta) {
    funcBody += `   ${defaultCast(mainVarName, castTo, base)}\n`;

    if (returnsWithImplicitOrNoCast.includes(trimmedReturnType)) {
      // console.log(`Processing easy getter: ${className}_${funcName}`);
      funcBody += `   return ${defaultFunc(mainVarName, funcName, args)}\n`;
    } else if (trimmedReturnType === "void") {
      // console.log(`Processing setter: ${className}_${funcName}`);
      funcBody += `   ${defaultFunc(mainVarName, funcName, args)}\n`;
    } else if (trimmedReturnType === "const char *") {
      // console.log(`Processing c_str getter: ${className}_${funcName}`);
      funcBody += `   return ${cStrFunc(mainVarName, funcName, args)}\n`;
    } else if (trimmedReturnType.replace(" ", "") === "void*") {
      // console.log(`Processing void* getter: ${className}_${funcName}`);
      funcBody += `   return ${voidRefFunc(mainVarName, funcName, args)}\n`;
    } else {
      //funcBody += defaultCast(mainVarName, castTo, base);
      valid = false;
    }
  }

  funcBody += `}\n\n`;

  return [fullTemplate(definition, funcBody), valid];
}

async function main() {
  if (process.argv.length <= 2 || process.argv.length > 4) {
    console.log(`
Correct usage:
node gen-body-from-def.js [relative path to .h file] [relative path to .cpp file that will be generated]
        `);
    return;
  }

  const relativeDefinitionPath = process.argv[2];
  const relativeTargetPath = process.argv[3];
  const definitionPath = path.join(process.cwd(), relativeDefinitionPath);
  const targetPath = path.join(process.cwd(), relativeTargetPath);

  const definitionFile = path.parse(definitionPath);

  definitionFile.name;

  if (!fs.existsSync(definitionPath)) {
    throw new Error(`Could not find definition file: ${definitionPath}`);
  }

  if (fs.existsSync(targetPath)) {
    throw new Error(`File already exists: ${definitionPath}`);
  }

  const definitionContent = await readFile(definitionPath, {
    encoding: "utf8",
  });

  const targetContent = await new Promise((resolve, reject) => {
    let cppFile = `#include "${definitionFile.base}"\n\n`;

    let match;

    while ((match = definitionRegex.exec(definitionContent)) != null) {
      if (match.index === definitionRegex.lastIndex) {
        definitionRegex.lastIndex++;
      }

      /*
        match.forEach((match, groupIndex) => {
            console.log(`Found match, group ${groupIndex}: ${match}`);
        });
      */

      const [func, valid] = generateCAPIFunction(
        match[0],
        match[2],
        match[3],
        match[1],
        match[4]
      );

      if (typeof func !== "string") {
        throw new Error(
          `Invalid return of generateCAPIFunction, check script!`
        );
      }

      if (!valid)
        console.warn(
          `
Could not process function ${match[2]}_${match[3]}. Manual intervention needed!
Line: ${targetPath}:${cppFile.split("\n").length}
          `
        );
      //console.log(
      //  `Successfully implemented ${match[2]}_${match[3]} function body!`
      //);
      cppFile += func;
    }

    resolve(cppFile);
  }).catch((e) => {
    console.error(`Could not match definition`);
    throw new Error(e);
  });

  await writeFile(targetPath, targetContent, { encoding: "utf8" }).catch(
    (e) => {
      console.error(`Could not write to target`);
      throw new Error(e);
    }
  );

  console.log(`Done!`);
}

main();
