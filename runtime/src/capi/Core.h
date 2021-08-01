#pragma once

#include "Main.h"

#ifdef __cplusplus
extern "C" {
#endif
    EXPORT void Core_LogInfo(char* message);
    EXPORT void Core_LogDebug(char* message);
    EXPORT void Core_LogWarning(char* message);
    EXPORT void Core_LogError(char* message);
    EXPORT void Core_LogColored(char* message);
#ifdef __cplusplus
}
#endif
