#pragma once

#include "Main.h"

#ifdef __cplusplus
extern "C"
{
#endif
    EXPORT void Core_LogInfo(const char *message);
    EXPORT void Core_LogDebug(const char *message);
    EXPORT void Core_LogWarning(const char *message);
    EXPORT void Core_LogError(const char *message);
    EXPORT void Core_LogColored(const char *message);
#ifdef __cplusplus
}
#endif
