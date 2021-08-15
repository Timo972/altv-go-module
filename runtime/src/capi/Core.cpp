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
