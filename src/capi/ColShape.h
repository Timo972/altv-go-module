#pragma once

#include <iostream>
#include "Main.h"

#ifdef __cplusplus
extern "C"
{
#endif
    // BaseObject inherited
    EXPORT int ColShape_GetType(void *c);
    EXPORT int ColShape_HasMetaData(void* base, const char *key);
    EXPORT MetaData ColShape_GetMetaData(void* base, const char *key);
    EXPORT void ColShape_SetMetaData(void *base, const char *key, void *val);
    EXPORT void ColShape_DeleteMetaData(void *base, const char *key);
    EXPORT void ColShape_Destroy(void *b);
    EXPORT int ColShape_IsValid(void *p);

    // WorldObject inherited
    EXPORT Position ColShape_GetPosition(void *p);
    EXPORT void ColShape_SetPosition(void* p, float x, float y, float z);
    EXPORT long ColShape_GetDimension(void* p);
    EXPORT void ColShape_SetDimension(void* p, long dimension);

    // ColShape inherited
    EXPORT int ColShape_GetColShapeType(void *c);
    EXPORT int ColShape_IsEntityIn(void *c, Entity e);
    EXPORT int ColShape_IsPointIn(void *c, float x, float y, float z);
    EXPORT void ColShape_SetPlayersOnly(void *c, int state);
    EXPORT int ColShape_IsPlayersOnly(void *c);

#ifdef __cplusplus
}
#endif
