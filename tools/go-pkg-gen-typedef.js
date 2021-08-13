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

function camelCaseToSnakeCase(str) {
  for (var i = 0; i < str.length; i++) {
    const char = str.charAt(i);

    const isUpper = /[A-Z]/g.test(char);

    if (i === 0 && isUpper)
      str = char.toLocaleLowerCase() + str.substring(1, str.length);
    else if (isUpper)
      str =
        str.substring(0, i) +
        "_" +
        char.toLocaleLowerCase() +
        str.substring(i + 1, str.length);
  }

  return str;
}

function generateCTypedef(returnValue, className, methodName, args) {
    const fn = `capi_${camelCaseToSnakeCase(
        className + methodName
      )}`;
  const typedef = `typedef ${returnValue} (*${fn})(${args});\n`;

  return [typedef, fn];
}

function generateCFuncDef(returnValue, className, methodName, args) {
    const func = `${returnValue} ${camelCaseToSnakeCase(className+methodName)}(${args});\n`

    return func;
}

function generateCFuncInit(typedefName, pureName) {
    const callName = `g_call_${pureName}`;
    return [`${typedefName} ${callName};\n`,callName];
}

function generateCGetFunc(cFuncInitName, className, methodName, typedefName) {
    return `${cFuncInitName} = GET_FUNC(module, "${className}_${methodName}", ${typedefName});\n`;
}

function generateCFuncBody(returnType, pureName, argStr) {
    const args = argStr.split(",").map((val) => {
        const lastIdxOfSpace = val.lastIndexOf(" ") + 1;
        let type = val.substring(0, lastIdxOfSpace).trim();
        let name = val.substring(lastIdxOfSpace, val.length);
        if (name.charAt(0) === "*") {
          name = name.substring(1, name.length);
          type += " *";
        }
        return name;
      });
    return `
${returnType} ${pureName}(${argStr})
{
    return g_call_${pureName}(${args.join(', ')});
}\n`;
}

async function main() {
  if (process.argv.length <= 2 || process.argv.length > 3) {
    console.log(`
    Correct usage:
    node go-pkg-gen-typedef.js [relative path to .h file]
            `);
    return;
  }

  const relativeDefinitionPath = process.argv[2];
  const definitionPath = path.join(process.cwd(), relativeDefinitionPath);

  if (!fs.existsSync(definitionPath)) {
    throw new Error(`Could not find definition file: ${definitionPath}`);
  }

  const definitionContent = await readFile(definitionPath, {
    encoding: "utf8",
  });

  const [hContent, cContent] = await new Promise((resolve, reject) => {
    let hContent = "// copy this into Module.h\n";
    let hFuncDefs = "// copy this into Module.h\n";
    let cContent = "// copy this into Module.c\n";
    let cLoadModuleFunc = "// copy this into int load_module(const char *path);\n";
    let cFuncBodys = "// copy into Module.c\n";
    let match;

    while ((match = definitionRegex.exec(definitionContent)) != null) {
      if (match.index === definitionRegex.lastIndex) {
        definitionRegex.lastIndex++;
      }

      const returnType = match[1].trim();

      const [typedef, name] = generateCTypedef(returnType, match[2], match[3], match[4]);
      const func = generateCFuncDef(returnType, match[2], match[3], match[4]);

      const snakeName = name.substring(5, name.length);

      const [cInit, callName] = generateCFuncInit(name, snakeName);
      const cFunc = generateCGetFunc(callName, match[2], match[3], name);
      const cFuncBody = generateCFuncBody(returnType, snakeName, match[4]);

      if (typeof typedef !== "string" || typeof func !== "string" || typeof cInit !== "string" || typeof cFunc !== "string" || typeof cFuncBody !== "string" || typeof callName !== "string") {
        throw new Error(`Invalid return of generateCTypedef, check script!`);
      } else 
        hContent += typedef;
        cContent += cInit;
        hFuncDefs += func;
        cLoadModuleFunc += cFunc;
        cFuncBodys += cFuncBody;
    }

    cContent += "\n\n";
    hContent += "\n\n";
    hContent += hFuncDefs;
    cContent += cLoadModuleFunc;
    cContent += "\n\n";
    cContent += cFuncBodys;

    resolve([hContent, cContent]);
  }).catch((e) => {
    console.error(`Could not match definition`);
    throw new Error(e);
  });

  await writeFile(`Module.h`, hContent);
  await writeFile(`Module.c`, cContent);
}

main();
