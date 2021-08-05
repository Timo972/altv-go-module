#pragma once

#include "Main.h"
#include "GoRuntime.h"
#include "GoResource.h"

#ifdef __cplusplus
extern "C" {
#endif
    EXPORT bool RegisterAltEvent(const char* resourceName, unsigned short eventType);
#ifdef __cplusplus
}
#endif
