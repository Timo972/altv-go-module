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
    auto value = alt::ICore::Instance().CreateMValueBool(val).Get();
    value->AddRef();

    return value;
}

// Works, others wrong
EXPORT void *Core_CreateMValueInt(long long val)
{
    auto value = alt::ICore::Instance().CreateMValueInt(val);
    value->AddRef();

    alt::ICore::Instance().LogError(std::to_string(reinterpret_cast<long long>(value.Get())));

    return value.Get();
}

EXPORT void *Core_CreateMValueUInt(unsigned long long val)
{
    auto value = alt::ICore::Instance().CreateMValueUInt(val).Get();
    value->AddRef();

    return value;
}

EXPORT void *Core_CreateMValueDouble(double val)
{
    auto value = alt::ICore::Instance().CreateMValueDouble(val).Get();
    value->AddRef();

    return value;
}

EXPORT void *Core_CreateMValueString(const char *val)
{
    auto value = alt::ICore::Instance().CreateMValueString(val).Get();
    value->AddRef();

    return value;
}

EXPORT bool Core_GetMValueBool(void *val)
{
    auto value = reinterpret_cast<alt::IMValueBool*>(val);
    return value->Value();
}

EXPORT long long Core_GetMValueInt(void *val)
{
    auto value = reinterpret_cast<alt::IMValueInt*>(val);
    alt::ICore::Instance().LogError(std::to_string(value->Value()));
    return value->Value();
}

EXPORT unsigned long long Core_GetMValueUInt(void *val)
{
    auto value = reinterpret_cast<alt::IMValueUInt*>(val);
    return value->Value();
}

EXPORT double Core_GetMValueDouble(void *val)
{
    auto value = reinterpret_cast<alt::IMValueDouble*>(val);
    return value->Value();
}

EXPORT const char *Core_GetMValueString(void *val)
{
    auto value = reinterpret_cast<alt::IMValueString*>(val);
    return value->Value().CStr();
}

/*
EXPORT void *Core_CreateMValueList()
{

}
*/

/*
EXPORT void *Core_CreateMValueDict()
{

}
*/

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

EXPORT void *Core_CreateCheckpoint(unsigned short type, float x, float y, float z, float radius, float height, unsigned short r, unsigned short g, unsigned short b, unsigned short a)
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