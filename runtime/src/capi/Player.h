#pragma once

#include "Main.h"

#ifdef __cplusplus
extern "C"
{
#endif
    EXPORT const char *Player_GetName(void *p);
    EXPORT int Player_HasMetaData(void* base, const char *key);
    EXPORT MetaData Player_GetMetaData(void* base, const char *key);
    EXPORT void Player_SetMetaData(void *base, const char *key, void *val);
    EXPORT void Player_DeleteMetaData(void *base, const char *key);
#ifdef __cplusplus
}
#endif
