#include "GoRuntime.h"
#include "GoResource.h"

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

alt::RefBase<alt::RefStore<alt::IMValue>> Go::Runtime::CreateMValueFromJSONValue(rapidjson::Value &value) {
    switch (value.GetType()) {
        case rapidjson::kNullType:
            return alt::ICore::Instance().CreateMValueNone();
        case rapidjson::kFalseType:
        case rapidjson::kTrueType:
            return alt::ICore::Instance().CreateMValueBool(value.GetBool());
        case rapidjson::kObjectType:
            break;
        case rapidjson::kArrayType: {
            alt::RefBase<alt::RefStore<alt::IMValueList>> list = alt::ICore::Instance().CreateMValueList(
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

Entity Go::Runtime::GetEntity(alt::Ref<alt::IEntity> entity) {
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

ConnectionInfo Go::Runtime::GetConnectionInfo(alt::Ref<alt::IConnectionInfo> info) {
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
