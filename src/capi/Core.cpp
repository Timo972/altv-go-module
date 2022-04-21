#include "Core.h"
#include "Runtime.h"
#include "rapidjson/document.h"

EXPORT void Core_LogInfo(const char *message) {
    alt::ICore::Instance().LogInfo(message);
}

EXPORT void Core_LogDebug(const char *message) {
    alt::ICore::Instance().LogDebug(message);
}

EXPORT void Core_LogWarning(const char *message) {
    alt::ICore::Instance().LogWarning(message);
}

EXPORT void Core_LogError(const char *message) {
    alt::ICore::Instance().LogError(message);
}

EXPORT void Core_LogColored(const char *message) {
    alt::ICore::Instance().LogColored(message);
}

EXPORT void *Core_CreateMValueBool(int val) {
    auto value = alt::ICore::Instance().CreateMValueBool(val);
    auto defaultMVal = value.As<alt::IMValue>();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

// Works, others wrong
EXPORT void *Core_CreateMValueInt(long long val) {
    auto value = alt::ICore::Instance().CreateMValueInt(val);
    auto defaultMVal = value.As<alt::IMValue>();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT void *Core_CreateMValueUInt(unsigned long long val) {
    auto value = alt::ICore::Instance().CreateMValueUInt(val);
    auto defaultMVal = value.As<alt::IMValue>();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT void *Core_CreateMValueDouble(double val) {
    auto value = alt::ICore::Instance().CreateMValueDouble(val);
    auto defaultMVal = value.As<alt::IMValue>();
    defaultMVal->AddRef();

    return defaultMVal.Get();;
}

EXPORT void *Core_CreateMValueString(const char *val) {
    auto value = alt::ICore::Instance().CreateMValueString(val);
    auto defaultMVal = value.As<alt::IMValue>();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

/*EXPORT void *Core_CreateMValueList(const char *val, unsigned long long size) {
    auto value = alt::ICore::Instance().CreateMValueList(size);

    rapidjson::Document document;
    document.Parse(val);

    if (!document.IsArray()) {
        value->Push(alt::ICore::Instance().CreateMValueNone());
        return value.Get();
    }

    for (auto &member: document.GetArray()) {
        if (member.IsObject()) {
            value->Push(alt::ICore::Instance().CreateMValueNone());
            continue;
        }

        auto MValue = Go::Runtime::GetInstance()->CreateMValueFromJSONValue(member);
        value->Push(MValue);
    }

    return value.Get();
}*/

EXPORT void *Core_CreateMValueList(void **values, unsigned long long size) {
    auto value = alt::ICore::Instance().CreateMValueList(size);

    auto MValues = reinterpret_cast<alt::IMValue **>(values);

    for (unsigned long long i = 0; i < size; i++) {
        auto val = MValues[i];
        value->Set(i, val);
    }

    auto defaultMVal = value->Clone();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT void *Core_CreateMValueDict(const char **keys, void **values, unsigned long long size) {
    auto value = alt::ICore::Instance().CreateMValueDict();
    auto MValues = reinterpret_cast<alt::IMValue **>(values);

    for (unsigned long long i = 0; i < size; i++) {
        auto key = keys[i];
        auto MValue = MValues[i];
        value->Set(key, MValue);
    }

    auto defaultMVal = value.As<alt::IMValue>();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT void *Core_CreateMValueBaseObject(unsigned char type, void *o) {
    auto objectType = static_cast<alt::IBaseObject::Type>(type);
    if (objectType == alt::IBaseObject::Type::PLAYER) {
        auto player = reinterpret_cast<alt::IPlayer *>(o);
        auto ref = alt::Ref<alt::IPlayer>(player);
        auto mVal = alt::ICore::Instance().CreateMValueBaseObject(ref);
        auto defaultVal = mVal.As<alt::IMValue>();
        defaultVal->AddRef();
        return defaultVal.Get();
    } else if (objectType == alt::IBaseObject::Type::VEHICLE) {
        auto veh = reinterpret_cast<alt::IVehicle *>(o);
        auto ref = alt::Ref<alt::IVehicle>(veh);
        auto mVal = alt::ICore::Instance().CreateMValueBaseObject(ref);
        auto defaultVal = mVal.As<alt::IMValue>();
        defaultVal->AddRef();
        return defaultVal.Get();
    } else if (objectType == alt::IBaseObject::Type::CHECKPOINT) {
        auto cp = reinterpret_cast<alt::ICheckpoint *>(o);
        auto ref = alt::Ref<alt::ICheckpoint>(cp);
        auto mVal = alt::ICore::Instance().CreateMValueBaseObject(ref);
        auto defaultVal = mVal.As<alt::IMValue>();
        defaultVal->AddRef();
        return defaultVal.Get();
    } else if (objectType == alt::IBaseObject::Type::COLSHAPE) {
        auto cs = reinterpret_cast<alt::IColShape *>(o);
        auto ref = alt::Ref<alt::IColShape>(cs);
        auto mVal = alt::ICore::Instance().CreateMValueBaseObject(ref);
        auto defaultVal = mVal.As<alt::IMValue>();
        defaultVal->AddRef();
        return defaultVal.Get();
    } else if (objectType == alt::IBaseObject::Type::VOICE_CHANNEL) {
        auto vc = reinterpret_cast<alt::IVoiceChannel *>(o);
        auto ref = alt::Ref<alt::IVoiceChannel>(vc);
        auto mVal = alt::ICore::Instance().CreateMValueBaseObject(ref);
        auto defaultVal = mVal.As<alt::IMValue>();
        defaultVal->AddRef();
        return defaultVal.Get();
    } else
        return alt::ICore::Instance().CreateMValueNone().Get();
}

EXPORT void *Core_CreateMValueVector2(float x, float y) {
    alt::Vector2f v2;
    v2[0] = x;
    v2[1] = y;

    auto val = alt::ICore::Instance().CreateMValueVector2(v2);
    auto value = val.As<alt::IMValue>();
    value->AddRef();

    return value.Get();
}

EXPORT void *Core_CreateMValueVector3(float x, float y, float z) {
    alt::Vector3f v3;
    v3[0] = x;
    v3[1] = y;
    v3[2] = z;

    auto value = alt::ICore::Instance().CreateMValueVector3(v3);
    auto defaultMVal = value.As<alt::IMValue>();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT void *Core_CreateMValueRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    alt::RGBA color(r, g, b, a);
    auto mValue = alt::ICore::Instance().CreateMValueRGBA(color);
    auto defaultMVal = mValue.As<alt::IMValue>();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT void *Core_CreateMValueByteArray(unsigned char *data, unsigned long long size) {
    auto mValue = alt::ICore::Instance().CreateMValueByteArray(data, size);
    auto defaultMVal = mValue.As<alt::IMValue>();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT int Core_GetMValueBool(void *val) {
    auto value = reinterpret_cast<alt::IMValue *>(val);
    auto boolValue = dynamic_cast<alt::IMValueBool *>(value);
    return boolValue->Value();
}


EXPORT long long Core_GetMValueInt(void *val) {
    auto value = reinterpret_cast<alt::IMValue *>(val);
    auto intValue = dynamic_cast<alt::IMValueInt *>(value);
    return intValue->Value();
}

EXPORT unsigned long long Core_GetMValueUInt(void *val) {
    auto value = reinterpret_cast<alt::IMValue *>(val);
    auto uintValue = dynamic_cast<alt::IMValueUInt *>(value);
    return uintValue->Value();
}

EXPORT double Core_GetMValueDouble(void *val) {
    auto value = reinterpret_cast<alt::IMValue *>(val);
    auto doubleValue = dynamic_cast<alt::IMValueDouble *>(value);
    return doubleValue->Value();
}

EXPORT const char *Core_GetMValueString(void *val) {
    auto value = reinterpret_cast<alt::IMValue *>(val);
    auto stringValue = dynamic_cast<alt::IMValueString *>(value);

    return stringValue->Value().c_str();
}

EXPORT Entity Core_GetMValueBaseObject(void *val) {
    auto value = reinterpret_cast<alt::IMValue *>(val);
    auto objectValue = dynamic_cast<alt::IMValueBaseObject *>(value);

    auto object = objectValue->Value();
    auto type = object->GetType();

    Entity e;
    e.Type = static_cast<unsigned char>(type);

    if (type == alt::IBaseObject::Type::PLAYER) {
        e.Ptr = dynamic_cast<alt::IPlayer *>(object.Get());
    } else if (type == alt::IBaseObject::Type::VEHICLE) {
        e.Ptr = dynamic_cast<alt::IVehicle *>(object.Get());
    } else if (type == alt::IBaseObject::Type::COLSHAPE) {
        e.Ptr = dynamic_cast<alt::IColShape *>(object.Get());
    } else if (type == alt::IBaseObject::Type::VOICE_CHANNEL) {
        e.Ptr = dynamic_cast<alt::IVoiceChannel *>(object.Get());
    } else if (type == alt::IBaseObject::Type::CHECKPOINT) {
        e.Ptr = dynamic_cast<alt::ICheckpoint *>(object.Get());
    } else if (type == alt::IBaseObject::Type::BLIP) {
        e.Ptr = dynamic_cast<alt::IBlip *>(object.Get());
    }

    return e;
}

EXPORT Vector2 Core_GetMValueVector2(void *val) {
    auto mValue = reinterpret_cast<alt::IMValue *>(val);
    auto v2MValue = dynamic_cast<alt::IMValueVector2 *>(mValue);
    auto value = v2MValue->Value();

    Vector2 pos;
    pos.x = value[0];
    pos.y = value[1];

    return pos;
}

EXPORT Position Core_GetMValueVector3(void *val) {
    auto mValue = reinterpret_cast<alt::IMValue *>(val);
    auto v3MValue = dynamic_cast<alt::IMValueVector3 *>(mValue);
    auto value = v3MValue->Value();

    Position pos;
    pos.x = value[0];
    pos.y = value[1];
    pos.z = value[2];

    return pos;
}

EXPORT RGBA Core_GetMValueRGBA(void *val) {
    auto mValue = reinterpret_cast<alt::IMValue *>(val);
    auto rgbaMValue = dynamic_cast<alt::IMValueRGBA *>(mValue);
    auto value = rgbaMValue->Value();

    RGBA color;
    color.r = value.r;
    color.g = value.g;
    color.b = value.b;
    color.a = value.a;

    return color;
}

EXPORT Array Core_GetMValueByteArray(void *val) {
    auto mValue = reinterpret_cast<alt::IMValue *>(val);
    auto byteMValue = dynamic_cast<alt::IMValueByteArray *>(mValue);

    Array byteArray;
    byteArray.array = byteMValue->GetData();
    byteArray.size = byteMValue->GetSize();

    return byteArray;
}

EXPORT Array Core_GetMValueList(void *val) {
    auto mValue = reinterpret_cast<alt::IMValue *>(val);
    auto listMValue = dynamic_cast<alt::IMValueList *>(mValue);

    Array arr;
    arr.size = listMValue->GetSize();

#ifdef _WIN32
    auto mValues = new MetaData[arr.size];
#else
    MetaData mValues[arr.size];
#endif

    for (int i = 0; i < arr.size; i++) {
        auto v = listMValue->Get(i);
        MetaData data;
        data.Type = static_cast<unsigned char>(v->GetType());
        data.Ptr = v.Get();
        mValues[i] = data;
    }

    arr.array = mValues;

    return arr;
}

EXPORT MValueDict Core_GetMValueDict(void *val) {
    auto mValue = reinterpret_cast<alt::IMValue *>(val);
    auto dictMValue = dynamic_cast<alt::IMValueDict *>(mValue);

    MValueDict dict;
    dict.size = dictMValue->GetSize();

#ifdef _WIN32
    auto keys = new const char *[dict.size];
#else
    const char* keys[dict.size];
#endif

#ifdef _WIN32
    auto values = new MetaData[dict.size];
#else
    MetaData values[dict.size];
#endif

    int64_t i = 0;
    for (auto it = dictMValue->Begin(); it; it = dictMValue->Next()) {
        auto v = it->GetValue();

        MetaData data;
        data.Type = static_cast<unsigned char>(v->GetType());
        data.Ptr = v.Get();

        auto key = it->GetKey();
        auto keySize = key.size();
        auto keyArray = new char[keySize + 1];
        memcpy(keyArray, key.c_str(), keySize);
        keyArray[keySize] = '\0';
        keys[i] = keyArray;
        values[i] = data;
        i++;
    }

    dict.keys = keys;
    dict.values = values;

    return dict;
}

EXPORT void *Core_CreateVehicle(unsigned long model, float posX, float posY, float posZ,
                                float rotX, float rotY, float rotZ) {
    alt::Position position(posX, posY, posZ);
    alt::Rotation rotation(rotX, rotY, rotZ);

    auto vehicle = alt::ICore::Instance().CreateVehicle(model, position, rotation);
    return vehicle.Get();
}

EXPORT void *
Core_CreateCheckpoint(unsigned char type, float x, float y, float z, float radius, float height, unsigned char r,
                      unsigned char g, unsigned char b, unsigned char a) {
    alt::RGBA rgba(r, g, b, a);
    alt::Vector<float, 3, alt::PointLayout> pos;
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;

    auto checkpoint = alt::ICore::Instance().CreateCheckpoint(type, pos, radius, height, rgba);
    return checkpoint.Get();
}

EXPORT void *Core_CreateVoiceChannel(int spacial, float maxDistance) {
    auto voiceChannel = alt::ICore::Instance().CreateVoiceChannel(spacial, maxDistance);
    return voiceChannel.Get();
}

EXPORT const char *Core_GetVersion() {
    static std::string ver = alt::ICore::Instance().GetVersion();
    return ver.c_str();
}

EXPORT const char *Core_GetBranch() {
    static std::string branch = alt::ICore::Instance().GetBranch();
    return branch.c_str();
}

EXPORT int Core_IsDebug() {
    return alt::ICore::Instance().IsDebug();
}

EXPORT unsigned long Core_Hash(const char *str) {
    return alt::ICore::Instance().Hash(str);
}

EXPORT int Core_FileExists(const char *path) {
    return alt::ICore::Instance().FileExists(path);
}

EXPORT const char *Core_ReadFile(const char *path) {
    static std::string content = alt::ICore::Instance().FileRead(path);
    return content.c_str();
}

EXPORT Entity Core_GetEntityByID(unsigned short id) {
    auto entity = alt::ICore::Instance().GetEntityByID(id);

    return Go::Runtime::GetEntity(entity);
}

EXPORT Array Core_GetEntities() {
    auto entities = alt::ICore::Instance().GetEntities();
    Array arr;
    arr.size = entities.GetSize();

#ifdef _WIN32
    auto entityRefs = new Entity[arr.size];
#else
    Entity entityRefs[arr.size];
#endif

    for (uint64_t i = 0; i < arr.size; i++) {
        auto entity = entities[i];

        entityRefs[i] = Go::Runtime::GetEntity(entity);
    }

    arr.array = entityRefs;

    return arr;
}

EXPORT Array Core_GetPlayers() {
    auto entities = alt::ICore::Instance().GetPlayers();
    return Go::Runtime::GetInstance()->CreatePointerArray(entities);
}


EXPORT Array Core_GetVehicles() {
    auto entities = alt::ICore::Instance().GetVehicles();
    return Go::Runtime::GetInstance()->CreatePointerArray(entities);
}

EXPORT int Core_HasMetaData(const char *key) {
    return alt::ICore::Instance().HasMetaData(key);
}

EXPORT Array Core_GetMetaData(const char *key) {
    auto meta = alt::ICore::Instance().GetMetaData(key);
    auto metaData = Go::Runtime::MValueToProtoBytes(meta);

    return metaData;
}

EXPORT void Core_SetMetaData(const char *key, unsigned char *data, unsigned long long size) {
    auto value = Go::Runtime::ProtoToMValue(data, size);
    alt::ICore::Instance().SetMetaData(key, value);
}

EXPORT void Core_DeleteMetaData(const char *key) {
    alt::ICore::Instance().DeleteMetaData(key);
}

EXPORT int Core_HasSyncedMetaData(const char *key) {
    return alt::ICore::Instance().HasSyncedMetaData(key);
}

EXPORT Array Core_GetSyncedMetaData(const char *key) {
    auto meta = alt::ICore::Instance().GetSyncedMetaData(key);
    auto metaData = Go::Runtime::MValueToProtoBytes(meta);

    return metaData;
}

EXPORT Array Core_GetRequiredPermissions() {
    auto perms = alt::ICore::Instance().GetRequiredPermissions();
    return Go::Runtime::GetInstance()->CreateArray<alt::Permission, unsigned char>(perms);
}

EXPORT Array Core_GetOptionalPermissions() {
    auto perms = alt::ICore::Instance().GetOptionalPermissions();
    return Go::Runtime::GetInstance()->CreateArray<alt::Permission, unsigned char>(perms);
}

EXPORT void Core_DestroyBaseObject(void *h) {
    auto handle = reinterpret_cast<alt::IBaseObject *>(h);
    alt::ICore::Instance().DestroyBaseObject(handle);
}

EXPORT const char *Core_GetRootDirectory() {
    return alt::ICore::Instance().GetRootDirectory().c_str();
}

EXPORT int Core_StartResource(const char *name) {
    return alt::ICore::Instance().StartResource(name)->IsStarted();
}

EXPORT void Core_StopResource(const char *name) {
    alt::ICore::Instance().StopResource(name);
}

EXPORT void Core_RestartResource(const char *name) {
    alt::ICore::Instance().RestartResource(name);
}

EXPORT void Core_SetSyncedMetaData(const char *key, unsigned char *data, unsigned long long size) {
    auto value = Go::Runtime::ProtoToMValue(data, size);
    alt::ICore::Instance().SetSyncedMetaData(key, value);
}

EXPORT void Core_DeleteSyncedMetaData(const char *key) {
    alt::ICore::Instance().DeleteSyncedMetaData(key);
}

EXPORT Array Core_GetPlayersByName(const char *name) {
    auto players = alt::ICore::Instance().GetPlayersByName(name);

    return Go::Runtime::GetInstance()->CreatePointerArray(players);
}

EXPORT unsigned int Core_GetNetTime() {
    return alt::ICore::Instance().GetNetTime();
}

EXPORT void Core_SetPassword(const char *password) {
    alt::ICore::Instance().SetPassword(password);
}

EXPORT const char *Core_GetSDKHash() {
    return ALT_SDK_VERSION;
}

EXPORT void *Core_CreateColShapeSphere(float posX, float posY, float posZ, float radius) {
    alt::Position position(posX, posY, posZ);

    auto colShape = alt::ICore::Instance().CreateColShapeSphere(position, radius);
    return colShape.Get();
}

EXPORT void *Core_CreateColShapeCircle(float posX, float posY, float posZ, float radius) {
    alt::Position position(posX, posY, posZ);

    auto colShape = alt::ICore::Instance().CreateColShapeCircle(position, radius);
    return colShape.Get();
}

EXPORT void *Core_CreateColShapeRectangle(float x1, float y1, float x2, float y2, float z) {

    auto colShape = alt::ICore::Instance().CreateColShapeRectangle(x1, y1, x2, y2, z);
    return colShape.Get();
}

EXPORT void *Core_CreateColShapeCube(float posX1, float posY1, float posZ1, float posX2, float posY2, float posZ2) {
    alt::Position position(posX1, posY1, posZ1);
    alt::Position position2(posX2, posY2, posZ2);

    auto colShape = alt::ICore::Instance().CreateColShapeCube(position, position2);
    return colShape.Get();
}

EXPORT void *Core_CreateColShapeCylinder(float posX, float posY, float posZ, float radius, float height) {
    alt::Position position(posX, posY, posZ);

    auto colShape = alt::ICore::Instance().CreateColShapeCylinder(position, radius, height);
    return colShape.Get();
}

EXPORT void Core_TriggerLocalEvent(const char *ev, Array data) {
    auto args = Go::Runtime::ProtoToMValueArgs(data);
    // call event
    alt::ICore::Instance().TriggerLocalEvent(ev, args);
}

EXPORT void Core_TriggerClientEvent(void *p, const char *ev, Array data) {

    auto player = reinterpret_cast<alt::IPlayer *>(p);
    auto args = Go::Runtime::ProtoToMValueArgs(data);
    // call event
    alt::ICore::Instance().TriggerClientEvent(alt::Ref<alt::IPlayer>(player), ev, args);
}

EXPORT void Core_TriggerClientEventFor(Array clients, const char *ev, Array data) {
    alt::Array<alt::Ref<alt::IPlayer>> players;

    auto playerRefs = reinterpret_cast<alt::IPlayer**>(clients.array);

    for (unsigned long long i = 0; i < clients.size; i++) {
        players.Push(alt::Ref<alt::IPlayer>(playerRefs[i]));
    }

    auto args = Go::Runtime::ProtoToMValueArgs(data);

    alt::ICore::Instance().TriggerClientEvent(players, ev, args);
}

EXPORT void Core_TriggerClientEventForAll(const char *ev, Array data) {
    auto args = Go::Runtime::ProtoToMValueArgs(data);

    alt::ICore::Instance().TriggerClientEventForAll(ev, args);
}

EXPORT void *Core_CreatePointBlipPosition(float x, float y, float z) {
    auto blip = alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::DESTINATION, alt::Position(x, y, z));
    return blip.Get();
}

EXPORT void *Core_CreatePointBlipEntity(Entity
                                        entity) {
// FIXME: Entity struct to alt::IEntity and pass then
    auto blip = alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::DESTINATION, nullptr);
    return blip.

            Get();

}

EXPORT void *Core_CreateAreaBlip(float x, float y, float z, float width, float height) {
    auto blip = alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::AREA, alt::Position(x, y, z));
    blip->SetScaleXY({width, height});

    return blip.Get();
}

EXPORT void *Core_CreateRadiusBlip(float x, float y, float z, float radius) {
    auto blip = alt::ICore::Instance().CreateBlip(nullptr, alt::IBlip::BlipType::RADIUS, alt::Position(x, y, z));
    blip->SetScaleXY({radius, radius});

    return blip.Get();
}

EXPORT void *Core_CreateColShapePolygon(float minZ, float maxZ, Array points) {
    // auto cs = alt::ICore::Instance().CreateColShapePolygon(minZ, maxZ, );
    // return cs.Get();
    return nullptr;
}

EXPORT Array Core_GetBlips() {
    auto blips = alt::ICore::Instance().GetBlips();
    return Go::Runtime::GetInstance()->CreatePointerArray(blips);
}

EXPORT Array Core_GetAllResources() {
    auto resources = alt::ICore::Instance().GetAllResources();
    Array arr;
    arr.size = resources.size();

#ifdef _WIN32
    auto entityRefs = new void *[arr.size];
#else
    void *entityRefs[arr.size];
#endif
    for (uint64_t i = 0; i < arr.size; i++) {
        entityRefs[i] = resources.at(i);
    }

    arr.array = entityRefs;

    return arr;
}

EXPORT const char *Core_StringToSHA256(const char *str) {
    static std::string hash = alt::ICore::Instance().StringToSHA256(str);
    return hash.c_str();
}

EXPORT void Core_StopServer() {
    alt::ICore::Instance().StopServer();
}

EXPORT VehicleModelInfo Core_GetVehicleModelByHash(unsigned int hash) {
    auto modelInfo = alt::ICore::Instance().GetVehicleModelByHash(hash);

    VehicleModelInfo m;

    m.title = modelInfo.title.c_str();
    m.modelType = static_cast<unsigned char>(modelInfo.modelType);
    m.wheelsCount = modelInfo.wheelsCount;
    m.hasArmoredWindows = modelInfo.hasArmoredWindows;
    m.primaryColor = modelInfo.primaryColor;
    m.secondaryColor = modelInfo.secondaryColor;
    m.pearlColor = modelInfo.pearlColor;
    m.wheelsColor = modelInfo.wheelsColor;
    m.interiorColor = modelInfo.interiorColor;
    m.dashboardColor = modelInfo.dashboardColor;

    m.modKits[0] = modelInfo.modkits[0];
    m.modKits[1] = modelInfo.modkits[1];

    m.extras = modelInfo.extras;
    m.defaultExtras = modelInfo.defaultExtras;

    return m;
}

EXPORT const char *Core_GetServerConfig() {
    auto config = alt::ICore::Instance().GetServerConfig();
    return Go::Runtime::GetInstance()->SerializeConfig(config);
}

EXPORT unsigned long long Core_HashServerPassword(const char *password) {
    return alt::ICore::Instance().HashServerPassword(password);
}