#include "Core.h"

EXPORT void Core_LogInfo(char* message)
{
    alt::ICore::Instance().LogInfo(message);
}

EXPORT void Core_LogDebug(char* message)
{
    alt::ICore::Instance().LogDebug(message);
}

EXPORT void Core_LogWarning(char* message)
{
    alt::ICore::Instance().LogWarning(message);
}

EXPORT void Core_LogError(char* message)
{
    alt::ICore::Instance().LogError(message);
}

EXPORT void Core_LogColored(char* message)
{
    alt::ICore::Instance().LogColored(message);
}