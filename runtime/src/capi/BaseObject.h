#pragma once

#include "Main.h"

#ifdef __cplusplus
extern "C"
{
#endif
    EXPORT unsigned char BaseObject_GetType(void* base);
    EXPORT int BaseObject_HasMetaData(void *base, const char *key);
    EXPORT SentData BaseObject_GetMetaData(void *base, const char *key);
    EXPORT void BaseObject_SetMetaData(void *base, const char *key, void *val);
    EXPORT void BaseObject_DeleteMetaData(void *base, const char *key);
#ifdef __cplusplus
}
#endif
