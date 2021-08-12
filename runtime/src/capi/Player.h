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
    EXPORT Position Player_GetPosition(void *p);
    EXPORT void Player_SetPosition(void* p, float x, float y, float z);
    EXPORT long Player_GetDimension(void* p);
    EXPORT void Player_SetDimension(void* p, long dimension);
    EXPORT void Player_Spawn(void *p, float x, float y, float z, unsigned long delay);
    EXPORT void Player_SetModel(void *p, unsigned long model);
#ifdef __cplusplus
}
#endif
