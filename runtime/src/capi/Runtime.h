#pragma once

#include "Main.h"
#include "GoRuntime.h"
#include "GoResource.h"

#ifdef __cplusplus
extern "C"
{
#endif
    EXPORT int RegisterAltEvent(const char *resourceName, unsigned short eventType);
    EXPORT int UnregisterAltEvent(const char *resourceName, unsigned short eventType);
#ifdef __cplusplus
}
#endif
