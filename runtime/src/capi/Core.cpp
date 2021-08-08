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

EXPORT void *Core_CreateMValueInt(long long val)
{
    auto value = alt::ICore::Instance().CreateMValueInt(val).Get();
    value->AddRef();

    return value;
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