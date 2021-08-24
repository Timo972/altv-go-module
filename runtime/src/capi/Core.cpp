#include "Core.h"

EXPORT void Core_LogInfo(const char *message)
{
    alt::ICore::Instance().LogInfo(message);
}

EXPORT void Core_LogDebug(const char *message)
{
    alt::ICore::Instance().LogDebug(message);
}

EXPORT void Core_LogWarning(const char *message)
{
    alt::ICore::Instance().LogWarning(message);
}

EXPORT void Core_LogError(const char *message)
{
    alt::ICore::Instance().LogError(message);
}

EXPORT void Core_LogColored(const char *message)
{
    alt::ICore::Instance().LogColored(message);
}

EXPORT void *Core_CreateMValueBool(int val)
{
    auto value = alt::ICore::Instance().CreateMValueBool(val);
    auto defaultMVal = value->Clone();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

// Works, others wrong
EXPORT void *Core_CreateMValueInt(long long val)
{
    auto value = alt::ICore::Instance().CreateMValueInt(val);
    auto defaultMVal = value->Clone();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT void *Core_CreateMValueUInt(unsigned long long val)
{
    auto value = alt::ICore::Instance().CreateMValueUInt(val);
    auto defaultMVal = value->Clone();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT void *Core_CreateMValueDouble(double val)
{
    auto value = alt::ICore::Instance().CreateMValueDouble(val);
    auto defaultMVal = value->Clone();
    defaultMVal->AddRef();

    return defaultMVal.Get();;
}

EXPORT void *Core_CreateMValueString(const char *val)
{
    auto value = alt::ICore::Instance().CreateMValueString(val);
    auto defaultMVal = value->Clone();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT void *Core_CreateMValueList(void* *values, unsigned long long size)
{
    auto value = alt::ICore::Instance().CreateMValueList(size);

    auto MValues = reinterpret_cast<alt::IMValue**>(values);

    for (unsigned long long i = 0; i < size; i++) {
        auto val = MValues[i];
        value->Push(val);
    }

    auto defaultMVal = value->Clone();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT void *Core_CreateMValueDict(const char * *keys, void* *values, unsigned long long size)
{
    auto value = alt::ICore::Instance().CreateMValueDict();
    auto MValues = reinterpret_cast<alt::IMValue**>(values);

    for (unsigned long long i = 0; i < size; i++) {
        auto key = keys[i];
        auto MValue = MValues[i];
        value->Set(key, MValue);
    }

    auto defaultMVal = value->Clone();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT bool Core_GetMValueBool(void *val)
{
    auto value = reinterpret_cast<alt::IMValue*>(val);
    auto boolValue = dynamic_cast<alt::IMValueBool*>(value);
    return boolValue->Value();
}


EXPORT long long Core_GetMValueInt(void *val)
{
    auto value = reinterpret_cast<alt::IMValue*>(val);
    auto intValue = dynamic_cast<alt::IMValueInt*>(value);
    return intValue->Value();
}

EXPORT unsigned long long Core_GetMValueUInt(void *val)
{
    auto value = reinterpret_cast<alt::IMValueUInt*>(val);
    auto uintValue = dynamic_cast<alt::IMValueUInt*>(value);
    return uintValue->Value();
}

EXPORT double Core_GetMValueDouble(void *val)
{
    auto value = reinterpret_cast<alt::IMValue*>(val);
    auto doubleValue = dynamic_cast<alt::IMValueDouble*>(value);
    return doubleValue->Value();
}

EXPORT const char *Core_GetMValueString(void *val)
{
    auto value = reinterpret_cast<alt::IMValue*>(val);
    auto stringValue = dynamic_cast<alt::IMValueString*>(value);

    return stringValue->Value().CStr();
}

EXPORT void *Core_CreateVehicle(unsigned long model, float posX, float posY, float posZ,
                           float rotX, float rotY, float rotZ)
{
    alt::Position position;
    position.x = posX;
    position.y = posY;
    position.z = posZ;

    alt::Rotation rotation;
    rotation.roll = rotX;
    rotation.pitch = rotY;
    rotation.yaw = rotZ;

    auto vehicle = alt::ICore::Instance().CreateVehicle(model, position, rotation);
    return vehicle.Get();
}

EXPORT void *Core_CreateCheckpoint(unsigned char type, float x, float y, float z, float radius, float height, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    alt::RGBA rgba;
    rgba.r = r;
    rgba.g = g;
    rgba.b = b;
    rgba.a = a;

    alt::Vector<float, 3, alt::PointLayout> pos;
    pos[0] = x;
    pos[1] = y;
    pos[2] = z;

    auto checkpoint = alt::ICore::Instance().CreateCheckpoint(type, pos, height, radius, rgba);
    return checkpoint.Get();
}

EXPORT void *Core_CreateVoiceChannel(int spacial, float maxDistance)
{
    auto voiceChannel = alt::ICore::Instance().CreateVoiceChannel(spacial, maxDistance);
    return voiceChannel.Get();
}

EXPORT const char *Core_GetVersion()
{
    return alt::ICore::Instance().GetVersion().CStr();
}

EXPORT const char *Core_GetBranch()
{
    return alt::ICore::Instance().GetBranch().CStr();
}

EXPORT int Core_IsDebug()
{
    return alt::ICore::Instance().IsDebug();
}

EXPORT unsigned long Core_Hash(const char *str)
{
    return alt::ICore::Instance().Hash(str);
}

EXPORT int Core_FileExists(const char *path)
{
    return alt::ICore::Instance().FileExists(path);
}

EXPORT const char *Core_ReadFile(const char *path)
{
    return alt::ICore::Instance().FileRead(path).CStr();
}

EXPORT Entity Core_GetEntityByID(unsigned short id)
{
    auto entity = alt::ICore::Instance().GetEntityByID(id);

    Entity e;
    e.Ptr = entity.Get();

    if (!entity.IsEmpty()) {
        e.Type = static_cast<unsigned char>(entity->GetType());
    }

    return e;
}

EXPORT Array Core_GetEntities()
{
    auto entities = alt::ICore::Instance().GetEntities();
    Array arr;
    arr.size = entities.GetSize();

#ifdef _WIN32
    auto entityRefs = new Entity [arr.size];
#else
    Entity entityRefs[arr.size];
#endif
    for(uint64_t i = 0; i < arr.size; i++) {
        auto entity = entities[i];
        Entity e;
        e.Ptr = entity.Get();
        e.Type = static_cast<unsigned char>(entity->GetType());
        entityRefs[i] = e;
    }

    arr.array = entityRefs;

    return arr;
}

EXPORT Array Core_GetPlayers()
{
    auto entities = alt::ICore::Instance().GetPlayers();
    Array arr;
    arr.size = entities.GetSize();

#ifdef _WIN32
    auto entityRefs = new void* [arr.size];
#else
    void *entityRefs[arr.size];
#endif
    for(uint64_t i = 0; i < arr.size; i++) {
        entityRefs[i] = entities[i].Get();
    }

    arr.array = entityRefs;

    return arr;
}


EXPORT Array Core_GetVehicles()
{
    auto entities = alt::ICore::Instance().GetVehicles();
    Array arr;
    arr.size = entities.GetSize();

#ifdef _WIN32
    auto entityRefs = new void* [arr.size];
#else
    void *entityRefs[arr.size];
#endif
    for(uint64_t i = 0; i < arr.size; i++) {
        entityRefs[i] = entities[i].Get();
    }

    arr.array = entityRefs;

    return arr;
}

EXPORT int Core_HasMetaData(const char *key)
{
    return alt::ICore::Instance().HasMetaData(key);
}

EXPORT MetaData Core_GetMetaData(const char *key)
{
    auto meta = alt::ICore::Instance().GetMetaData(key);
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
}

EXPORT void Core_SetMetaData(const char *key, void *val)
{
    auto value = reinterpret_cast<alt::IMValue*>(val);
    alt::ICore::Instance().SetMetaData(key, value);
}

EXPORT void Core_DeleteMetaData(const char *key)
{
    alt::ICore::Instance().DeleteMetaData(key);
}

EXPORT int Core_HasSyncedMetaData(const char *key)
{
    return alt::ICore::Instance().HasSyncedMetaData(key);
}

EXPORT MetaData Core_GetSyncedMetaData(const char *key)
{
    auto meta = alt::ICore::Instance().GetSyncedMetaData(key);
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
}

EXPORT Array Core_GetRequiredPermissions()
{
    auto perms = alt::ICore::Instance().GetRequiredPermissions();
    Array arr;
    arr.size = perms.GetSize();

#ifdef _WIN32
    auto permissions = new short [arr.size];
#else
    short permissions[arr.size];
#endif
    for(uint64_t i = 0; i < arr.size; i++) {
        permissions[i] = static_cast<short>(perms[i]);
    }

    arr.array = permissions;

    return arr;
}

EXPORT Array Core_GetOptionalPermissions()
{
    auto perms = alt::ICore::Instance().GetRequiredPermissions();
    Array arr;
    arr.size = perms.GetSize();

#ifdef _WIN32
    auto permissions = new short [arr.size];
#else
    short permissions[arr.size];
#endif
    for(uint64_t i = 0; i < arr.size; i++) {
        permissions[i] = static_cast<short>(perms[i]);
    }

    arr.array = permissions;

    return arr;
}

EXPORT void Core_DestroyBaseObject(void *h)
{
    auto handle = reinterpret_cast<alt::IBaseObject*>(h);
    alt::ICore::Instance().DestroyBaseObject(handle);
}

EXPORT const char *Core_GetRootDirectory()
{
    return alt::ICore::Instance().GetRootDirectory().CStr();
}

EXPORT int Core_StartResource(const char *name)
{
    return alt::ICore::Instance().StartResource(name)->IsStarted();
}

EXPORT void Core_StopResource(const char *name)
{
    alt::ICore::Instance().StopResource(name);
}

EXPORT int Core_RestartResource(const char *name)
{
    return alt::ICore::Instance().RestartResource(name)->IsStarted();
}

EXPORT void Core_SetSyncedMetaData(const char *key, void *val)
{
    auto value = reinterpret_cast<alt::IMValue*>(val);
    alt::ICore::Instance().SetSyncedMetaData(key,value);
}

EXPORT void Core_DeleteSyncedMetaData(const char *key)
{
    alt::ICore::Instance().DeleteSyncedMetaData(key);
}

EXPORT Array Core_GetPlayersByName(const char *name)
{
    auto players = alt::ICore::Instance().GetPlayersByName(name);
    Array arr;
    arr.size = players.GetSize();

#ifdef _WIN32
    auto playerRefs = new void* [arr.size];
#else
    void* playerRefs[arr.size];
#endif
    for(uint64_t i = 0; i < arr.size; i++) {
        playerRefs[i] = players[i].Get();
    }

    arr.array = playerRefs;

    return arr;
}

EXPORT unsigned int Core_GetNetTime()
{
    return alt::ICore::Instance().GetNetTime();
}

EXPORT void Core_SetPassword(const char *password)
{
    alt::ICore::Instance().SetPassword(password);
}

EXPORT unsigned int Core_GetSDKVersion()
{
    return alt::ICore::SDK_VERSION;
}

EXPORT void *Core_CreateColShapeSphere(float posX, float posY, float posZ, float radius)
{
    alt::Position position;
    position.x = posX;
    position.y = posY;
    position.z = posZ;

    auto colShape = alt::ICore::Instance().CreateColShapeSphere(position, radius);
    return colShape.Get();
}

EXPORT void *Core_CreateColShapeCircle(float posX, float posY, float posZ, float radius)
{
    alt::Position position;
    position.x = posX;
    position.y = posY;
    position.z = posZ;

    auto colShape = alt::ICore::Instance().CreateColShapeCircle(position, radius);
    return colShape.Get();
}

EXPORT void *Core_CreateColShapeRectangle(float x1, float y1, float x2, float y2, float z)
{

    auto colShape = alt::ICore::Instance().CreateColShapeRectangle(x1, y1, x2, y2, z);
    return colShape.Get();
}

EXPORT void *Core_CreateColShapeCube(float posX1, float posY1, float posZ1, float posX2, float posY2, float posZ2)
{
    alt::Position position;
    position.x = posX1;
    position.y = posY1;
    position.z = posZ1;

    alt::Position position2;
    position.x = posX2;
    position.y = posY2;
    position.z = posZ2;

    auto colShape = alt::ICore::Instance().CreateColShapeCube(position, position2);
    return colShape.Get();
}

EXPORT void *Core_CreateColShapeCylinder(float posX, float posY, float posZ, float radius, float height)
{
    alt::Position position;
    position.x = posX;
    position.y = posY;
    position.z = posZ;

    auto colShape = alt::ICore::Instance().CreateColShapeCylinder(position, radius, height);
    return colShape.Get();
}

EXPORT void Core_TriggerLocalEvent(const char *ev, CustomData *MValues, unsigned long long size)
{
    alt::MValueArgs args;

    for (unsigned long long i = 0; i < size; ++i) {
        if(static_cast<alt::IMValue::Type>(MValues[i].Type) == alt::IMValue::Type::STRING) {
            args.Push(reinterpret_cast<alt::IMValueString*>(MValues[i].mValue));
        }

        if(static_cast<alt::IMValue::Type>(MValues[i].Type) == alt::IMValue::Type::INT) {
            args.Push(reinterpret_cast<alt::IMValueInt*>(MValues[i].mValue));
        }

        std::cout << "mValue ptr: " << MValues[i].mValue << std::endl;
    }

    // call event
    alt::ICore::Instance().TriggerLocalEvent(ev, args);
}