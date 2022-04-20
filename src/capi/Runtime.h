#pragma once

#include "Main.h"
#include "GoRuntime.h"
#include "GoResource.h"

#ifdef __cplusplus
extern "C"
{
#endif
    EXPORT int Runtime_RegisterAltEvent(const char *resourceName, unsigned short eventType);
    EXPORT int Runtime_UnregisterAltEvent(const char *resourceName, unsigned short eventType);
    EXPORT int Runtime_RegisterAltExport(const char *resourceName, const char *exportName, unsigned char *data, unsigned long long size);
    EXPORT Array Runtime_GetAltExport(const char *targetResourceName, const char *exportName);
    EXPORT void *Runtime_CreateMValueFunction(const char *resourceName, unsigned long long id);
    EXPORT Array Runtime_CallMValueFunction(void *ptr, unsigned char *data, unsigned long long mValueSize);
#ifdef __cplusplus
}
#endif
