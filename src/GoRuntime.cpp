#include "GoRuntime.h"
#include "GoResource.h"
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include <google/protobuf/text_format.h>
#include <cstdio>

Go::Runtime *Go::Runtime::Instance = nullptr;

Go::Runtime *Go::Runtime::GetInstance() {
    if (Instance == nullptr)
        Instance = new Runtime();

    return Instance;
}

alt::IResource::Impl *Go::Runtime::CreateImpl(alt::IResource *impl) {
    auto resource = new Go::Resource(this, impl);
    _resources.push_back({{impl->GetName().c_str(), resource}});

    return resource;
}

void Go::Runtime::DestroyImpl(alt::IResource::Impl *impl) {
    auto resource = dynamic_cast<Go::Resource *>(impl);

    if (resource != nullptr)
        delete resource;
}

void Go::Runtime::OnDispose() {
    // Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();
}

alt::IResource::Impl *Go::Runtime::GetResource(const std::string &name) {
    for (auto &resource: _resources) {
        if (resource.find(name) != resource.end()) {
            return resource[name];
        }
    }

    return nullptr;
}

alt::MValueArgs Go::Runtime::CreateMValueArgs(CustomData *MValues, unsigned long long size) {
    alt::MValueArgs args;

    for (unsigned long long i = 0; i < size; ++i) {
        switch (static_cast<alt::IMValue::Type>(MValues[i].Type)) {
            case alt::IMValue::Type::STRING:
                args.Push(reinterpret_cast<alt::IMValueString *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::INT:
                args.Push(reinterpret_cast<alt::IMValueInt *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::UINT:
                args.Push(reinterpret_cast<alt::IMValueUInt *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::DOUBLE:
                args.Push(reinterpret_cast<alt::IMValueDouble *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::BOOL:
                args.Push(reinterpret_cast<alt::IMValueBool *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::RGBA:
                args.Push(reinterpret_cast<alt::IMValueRGBA *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::VECTOR2:
                args.Push(reinterpret_cast<alt::IMValueVector2 *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::VECTOR3:
                args.Push(reinterpret_cast<alt::IMValueVector3 *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::BYTE_ARRAY:
                args.Push(reinterpret_cast<alt::IMValueByteArray *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::BASE_OBJECT:
                args.Push(reinterpret_cast<alt::IMValueBaseObject *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::FUNCTION:
                args.Push(reinterpret_cast<alt::IMValueBool *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::LIST:
                args.Push(reinterpret_cast<alt::IMValueList *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::DICT:
                args.Push(reinterpret_cast<alt::IMValueDict *>(MValues[i].mValue));
                break;
        }
    }

    return args;
}

alt::RefBase <alt::RefStore<alt::IMValue>> Go::Runtime::CreateMValueFromJSONValue(rapidjson::Value &value) {
    switch (value.GetType()) {
        case rapidjson::kNullType:
            return alt::ICore::Instance().CreateMValueNone();
        case rapidjson::kFalseType:
        case rapidjson::kTrueType:
            return alt::ICore::Instance().CreateMValueBool(value.GetBool());
        case rapidjson::kObjectType:
            break;
        case rapidjson::kArrayType: {
            alt::RefBase <alt::RefStore<alt::IMValueList>> list = alt::ICore::Instance().CreateMValueList(
                    value.GetArray().Size());
            list->Push(CreateMValueFromJSONValue(value));

            return list;
        }
        case rapidjson::kStringType:
            return alt::ICore::Instance().CreateMValueString(value.GetString());
        case rapidjson::kNumberType:
            return alt::ICore::Instance().CreateMValueInt(value.GetInt());
    }
}

Entity Go::Runtime::GetEntity(alt::Ref <alt::IEntity> entity) {
    Entity e;

    if (!entity.IsEmpty()) {
        auto entityType = entity->GetType();
        e.Type = static_cast<unsigned char>(entityType);

        switch (entityType) {
            case alt::IEntity::Type::PLAYER:
                e.Ptr = entity.As<alt::IPlayer>().Get();
                break;
            case alt::IEntity::Type::VEHICLE:
                e.Ptr = entity.As<alt::IVehicle>().Get();
                break;
        }
    } else {
        e.Ptr = nullptr;
    }

    return e;
}

ConnectionInfo Go::Runtime::GetConnectionInfo(alt::Ref <alt::IConnectionInfo> info) {
    connectionInfo conn;
    conn.authToken = info->GetAuthToken().c_str();
    conn.branch = info->GetBranch().c_str();
    conn.build = info->GetBuild();
    conn.cdnUrl = info->GetCdnUrl().c_str();
    conn.discordUserID = info->GetDiscordUserID().c_str();
    conn.hwidExHash = info->GetHwIdExHash();
    conn.hwidHash = info->GetHwIdHash();
    conn.ip = info->GetIp().c_str();
    conn.isDebug = info->GetIsDebug();
    conn.name = info->GetName().c_str();
    conn.passwordHash = info->GetPasswordHash();
    conn.socialID = info->GetSocialId();

    return conn;
}

rapidjson::Document Go::Runtime::SerializeConfigNode(alt::config::Node node) {
    alt::config::Node::Type type = node.GetType();
    rapidjson::Document doc;

    if (type == alt::config::Node::Type::DICT) {
        auto dict = node.ToDict();
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            auto key = it->first;
            auto value = SerializeConfigNode(it->second);

            doc.AddMember(rapidjson::Value(key.c_str(), key.size()), value, doc.GetAllocator());
        }
    } else if (type == alt::config::Node::Type::LIST) {
        auto list = node.ToList();

        for (auto it = list.begin(); it != list.end(); ++it) {
            auto value = SerializeConfigNode(*it);

            doc.PushBack(value.Move(), doc.GetAllocator());
        }
    } else if (type == alt::config::Node::Type::SCALAR) {
        for (uint8_t i = 0; i < 3; i++) {
            try {
                if (i == 0) {
                    //doc.Bool(node.ToBool());
                    doc.SetBool(node.ToBool());
                } else if (i == 1) {
                    //doc.Double(node.ToNumber());
                    doc.SetDouble(node.ToNumber());
                } else if (i == 2) {
                    auto str = node.ToString();
                    //doc.String(str.c_str(), str.size(), true);
                    doc.SetString(str.c_str(), str.size());
                }
            } catch (...) {
                continue;
            }
        }

    }

    return doc;
}

const char *Go::Runtime::SerializeConfig(alt::config::Node rootNode) {
    if (!rootNode.IsDict()) {
        return "{}";
    }

    auto root = rootNode.ToDict();

    rapidjson::Document doc = SerializeConfigNode(rootNode);

    rapidjson::StringBuffer buffer;
    rapidjson::Writer <rapidjson::StringBuffer> writer(buffer);

    doc.Accept(writer);

    return buffer.GetString();
}

alt::IEntity *Go::Runtime::GetEntityRef(Entity entity) {
    auto type = static_cast<alt::IEntity::Type>(entity.Type);

    switch (type) {
        case alt::IEntity::Type::PLAYER:
            return reinterpret_cast<alt::IPlayer *>(entity.Ptr);

        case alt::IEntity::Type::VEHICLE:
            return reinterpret_cast<alt::IVehicle *>(entity.Ptr);

        default:
            return nullptr;
    }
}

/*alt::MValue Go::Runtime::ToMValue(unsigned char *data, unsigned long long size) {
    MValue::MValue mValue;
    mValue.ParseFromArray(data, size);
    return ToMValue(mValue);
}

alt::MValue Go::Runtime::ToMValue(MValue::MValue mValue) {
    if (mValue.has_boolvalue()) {
        return alt::ICore::Instance().CreateMValueBool(mValue.boolvalue());
    } else if (mValue.has_uintvalue()) {
        return alt::ICore::Instance().CreateMValueUInt(mValue.uintvalue());
    } else if (mValue.has_intvalue()) {
        return alt::ICore::Instance().CreateMValueInt(mValue.intvalue());
    } else if (mValue.has_doublevalue()) {
        return alt::ICore::Instance().CreateMValueDouble(mValue.doublevalue());
    } else if (mValue.has_stringvalue()) {
        return alt::ICore::Instance().CreateMValueString(mValue.stringvalue());
    } else if (mValue.has_baseobjectvalue()) {
        const auto &baseObject = mValue.baseobjectvalue();
        Entity e;
        sscanf(baseObject.ptr().c_str(), "%p", &e.Ptr);
        e.Type = baseObject.type();
        // FIXME: only works for player and vehicle currently
        auto altBaseObject = GetEntityRef(e);
        return alt::ICore::Instance().CreateMValueBaseObject(altBaseObject);
    } else if (mValue.has_bytesvalue()) {
        auto bytes = mValue.bytesvalue();
        return alt::ICore::Instance().CreateMValueByteArray(reinterpret_cast<const uint8_t *>(bytes.data()),
                                                            bytes.size());
    } else if (mValue.has_rgbavalue()) {
        const auto &rgba = mValue.rgbavalue();
        return alt::ICore::Instance().CreateMValueRGBA(alt::RGBA(rgba.r(), rgba.g(), rgba.b(), rgba.a()));
    } else if (mValue.has_vector2value()) {
        const auto &vector2 = mValue.vector2value();
        auto v2 = alt::Vector2f();
        v2[0] = vector2.x();
        v2[1] = vector2.y();
        return alt::ICore::Instance().CreateMValueVector2(v2);
    } else if (mValue.has_vector3value()) {
        const auto &vector3 = mValue.vector3value();
        auto v3 = alt::Vector3f();
        v3[0] = vector3.x();
        v3[1] = vector3.y();
        v3[2] = vector3.z();
        return alt::ICore::Instance().CreateMValueVector3(v3);
    } else if (mValue.has_functionvalue()) {
        const auto &func = mValue.functionvalue();
        auto resource = dynamic_cast<Go::Resource *>(Go::Runtime::GetInstance()->GetResource(func.resourcename()));
        if (resource == nullptr) {
            return alt::ICore::Instance().CreateMValueNil();
        }

        auto goFunc = new Go::Function(resource->Module, func.id());
        return alt::ICore::Instance().CreateMValueFunction(goFunc);
    } else if (mValue.dict_size() > 0) {
        auto dictSize = mValue.dict_size();
        auto dict = alt::ICore::Instance().CreateMValueDict();

        for (auto i = 0; i < dictSize; i++) {
            const auto &key = mValue.dict(i);
            const auto &value = mValue.list(i);

            auto val = ToMValue(value);

            dict->Set(key, val);
        }

        return dict;
    } else if (mValue.list_size() > 0) {
        auto listSize = mValue.list_size();
        auto list = alt::ICore::Instance().CreateMValueList(listSize);

        for (auto i = 0; i < listSize; i++) {
            const auto &value = mValue.list(i);

            auto val = ToMValue(value);

            list->Set(i, val);
        }

        return list;
    } else if (mValue.has_nonevalue()) {
        return alt::ICore::Instance().CreateMValueNone();
    } else {
        return alt::ICore::Instance().CreateMValueNil();
    }
}

Array Go::Runtime::ToProtoMessage(alt::MValue mValue) {
    MValue::MValue value;

    switch (mValue->GetType()) {
        case alt::IMValue::Type::BOOL:
            value.set_boolvalue(static_cast<alt::MValueBool>(mValue)->Value());
            break;
        case alt::IMValue::Type::UINT: {
            auto mValueUint = static_cast<alt::MValueUInt>(mValue);
            value.set_uintvalue(mValueUint->Value());
            break;
        }
        case alt::IMValue::Type::INT: {
            auto mValueInt = static_cast<alt::MValueInt>(mValue);
            value.set_intvalue(mValueInt->Value());
            break;
        }
        case alt::IMValue::Type::DOUBLE: {
            auto mValueDouble = static_cast<alt::MValueDouble>(mValue);
            value.set_doublevalue(mValueDouble->Value());
            break;
        }
        case alt::IMValue::Type::STRING: {
            auto mValueString = static_cast<alt::MValueString>(mValue);
            value.set_stringvalue(mValueString->Value());
            break;
        }
        case alt::IMValue::Type::BASE_OBJECT: {
            auto mValueBaseObject = static_cast<alt::MValueBaseObject>(mValue);
            break;
        }
        case alt::IMValue::Type::BYTE_ARRAY: {
            auto mValueByteArray = static_cast<alt::MValueByteArray>(mValue);
            break;
        }
        case alt::IMValue::Type::RGBA: {
            auto mValueRGBA = static_cast<alt::MValueRGBA>(mValue);
            break;
        }
        case alt::IMValue::Type::VECTOR2: {
            auto mValueV2 = static_cast<alt::MValueVector2>(mValue);
            break;
        }
        case alt::IMValue::Type::VECTOR3: {
            auto mValueV3 = static_cast<alt::MValueVector3>(mValue);
            break;
        }
        case alt::IMValue::Type::FUNCTION: {
            auto mValueFunc = static_cast<alt::MValueFunction>(mValue);
            break;
        }
        case alt::IMValue::Type::DICT: {
            auto mValueDict = static_cast<alt::MValueDict>(mValue);
            break;
        }
        case alt::IMValue::Type::LIST: {
            auto mValueList = static_cast<alt::MValueList>(mValue);
            break;
        }
        case alt::IMValue::Type::NONE: {
            value.set_nonevalue(true);
            break;
        }
        default:
            value.set_nilvalue(true);
            break;
    }

    Array arr;
    arr.size = value.ByteSize();

    unsigned char *byteArray = new unsigned char[arr.size];
    value.SerializeToArray(byteArray, arr.size);
    arr.array = byteArray;

    return arr;
}

Array Go::Runtime::ToProtoMessage(alt::MValueConst mValue) {
    return Array{};
}*/