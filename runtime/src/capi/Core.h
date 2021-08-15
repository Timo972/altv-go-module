#pragma once

#include <iostream>
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
    EXPORT void *Core_CreateMValueBool(int value);
    EXPORT void *Core_CreateMValueInt(long long val);
    EXPORT void *Core_CreateMValueUInt(unsigned long long val);
    EXPORT void *Core_CreateMValueDouble(double val);
    EXPORT void *Core_CreateMValueString(const char *val);
    EXPORT bool Core_GetMValueBool(void *val);
    EXPORT long long Core_GetMValueInt(void *val); 
    EXPORT unsigned long long Core_GetMValueUInt(void *val);
    EXPORT double Core_GetMValueDouble(void *val);
    EXPORT const char *Core_GetMValueString(void *val);
    EXPORT void *Core_CreateVehicle(unsigned long model, float posX, float posY, float posZ,
                               float rotX, float rotY, float rotZ);
    EXPORT const char *Core_GetVersion();
    EXPORT const char *Core_GetBranch();
    EXPORT int Core_IsDebug();
    EXPORT unsigned long Core_Hash(const char *str);
    EXPORT int Core_FileExists(const char *path);
    EXPORT const char *Core_ReadFile(const char *path);
    EXPORT Entity Core_GetEntityByID(unsigned short id);
    EXPORT Array Core_GetEntities();
    EXPORT Array Core_GetPlayers();
    EXPORT Array Core_GetVehicles();
    EXPORT int Core_HasMetaData(const char *key);
    EXPORT MetaData Core_GetMetaData(const char *key);
    EXPORT void Core_SetMetaData(const char *key, void *val);
    EXPORT void Core_DeleteMetaData(const char *key);
    EXPORT int Core_HasSyncedMeta(const char *key);
    EXPORT MetaData Core_GetSyncedMeta(const char *key);
    EXPORT Array Core_GetRequiredPermissions();
    EXPORT Array Core_GetOptionalPermissions();
    EXPORT void Core_DestroyBaseObject(void *h);
    EXPORT const char *Core_GetRootDirectory();
    EXPORT void *Core_StartResource(const char *name);
    EXPORT void Core_StopResource(const char *name);
    EXPORT void *Core_RestartResource(const char *name);
    EXPORT void Core_SetSyncedMetaData(const char *key, void *val);
    EXPORT void Core_DeleteSyncedMetaData(const char *key);
    EXPORT Array Core_GetPlayersByName(const char *name);
    EXPORT unsigned int Core_GetNetTime();
    EXPORT void Core_SetPassword(const char *password);
#ifdef __cplusplus
}
#endif
