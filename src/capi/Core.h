#pragma once

#include <iostream>
#include "Main.h"
#include "version/version.h"

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
//EXPORT void *Core_CreateMValueList(const char *val, unsigned long long size);
EXPORT void *Core_CreateMValueList(void* *val, unsigned long long size);
EXPORT void *Core_CreateMValueDict(const char **keys, void **values, unsigned long long size);
EXPORT void *Core_CreateMValueBaseObject(unsigned char type, void *o);
EXPORT void *Core_CreateMValueVector2(float x, float y);
EXPORT void *Core_CreateMValueVector3(float x, float y, float z);
EXPORT void *Core_CreateMValueRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
EXPORT void *Core_CreateMValueByteArray(unsigned char *data, unsigned long long size);
EXPORT bool Core_GetMValueBool(void *val);
EXPORT long long Core_GetMValueInt(void *val);
EXPORT unsigned long long Core_GetMValueUInt(void *val);
EXPORT double Core_GetMValueDouble(void *val);
EXPORT const char *Core_GetMValueString(void *val);
EXPORT Entity Core_GetMValueBaseObject(void *val);
EXPORT Vector2 Core_GetMValueVector2(void *val);
EXPORT Position Core_GetMValueVector3(void *val);
EXPORT RGBA Core_GetMValueRGBA(void *val);
EXPORT Array Core_GetMValueByteArray(void *val);
EXPORT Array Core_GetMValueList(void *val);
EXPORT MValueDict Core_GetMValueDict(void *val);
EXPORT void *Core_CreateVehicle(unsigned long model, float posX, float posY, float posZ,
                                float rotX, float rotY, float rotZ);
EXPORT void *
Core_CreateCheckpoint(unsigned char type, float x, float y, float z, float radius, float height, unsigned char r,
                      unsigned char g, unsigned char b, unsigned char a);
EXPORT void *Core_CreateVoiceChannel(int spacial, float maxDistance);
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
EXPORT int Core_HasSyncedMetaData(const char *key);
EXPORT MetaData Core_GetSyncedMetaData(const char *key);
EXPORT Array Core_GetRequiredPermissions();
EXPORT Array Core_GetOptionalPermissions();
EXPORT void Core_DestroyBaseObject(void *h);
EXPORT const char *Core_GetRootDirectory();
EXPORT int Core_StartResource(const char *name);
EXPORT void Core_StopResource(const char *name);
EXPORT void Core_RestartResource(const char *name);
EXPORT void Core_SetSyncedMetaData(const char *key, void *val);
EXPORT void Core_DeleteSyncedMetaData(const char *key);
EXPORT Array Core_GetPlayersByName(const char *name);
EXPORT unsigned int Core_GetNetTime();
EXPORT void Core_SetPassword(const char *password);
EXPORT const char *Core_GetSDKHash();
EXPORT void *Core_CreateColShapeCylinder(float posX, float posY, float posZ, float radius, float height);
EXPORT void *Core_CreateColShapeCube(float posX1, float posY1, float posZ1, float posX2, float posY2, float posZ2);
EXPORT void *Core_CreateColShapeRectangle(float x1, float y1, float x2, float y2, float z);
EXPORT void *Core_CreateColShapeCircle(float posX, float posY, float posZ, float radius);
EXPORT void *Core_CreateColShapeSphere(float posX, float posY, float posZ, float radius);
EXPORT void Core_TriggerLocalEvent(const char *ev, CustomData *MValues, unsigned long long mValuesSize);
EXPORT void *Core_CreatePointBlipPosition(float x, float y, float z);
EXPORT void *Core_CreatePointBlipEntity(Entity entity);
EXPORT void *Core_CreateAreaBlip(float x, float y, float z, float width, float height);
EXPORT void *Core_CreateRadiusBlip(float x, float y, float z, float radius);
EXPORT void *Core_CreateColShapePolygon(float minZ, float maxZ, Array points);
EXPORT Array Core_GetBlips();
EXPORT Array Core_GetAllResources();
EXPORT const char *Core_StringToSHA256(const char *str);
EXPORT void Core_StopServer();
EXPORT VehicleModelInfo Core_GetVehicleModelByHash(unsigned int hash);
EXPORT const char *Core_GetServerConfig();
EXPORT unsigned long long Core_HashServerPassword(const char *password);
#ifdef __cplusplus
}
#endif
