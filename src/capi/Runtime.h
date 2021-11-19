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
    EXPORT int RegisterAltExport(const char *resourceName, const char *exportName, CustomData data);
    EXPORT MetaData GetAltExport(const char *targetResourceName, const char *exportName);
    EXPORT void *CreateMValueFunction(const char *resourceName, unsigned long long id);
    EXPORT MetaData CallMValueFunction(void *ptr, CustomData *mValues, unsigned long long mValueSize);
#ifdef __cplusplus
}
#endif
