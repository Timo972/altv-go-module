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
    EXPORT void *Core_CreateColShapeCylinder(float posX, float posY, float posZ, float radius, float height);
    EXPORT void *Core_CreateColShapeCube(float posX1, float posY1, float posZ1, float posX2, float posY2, float posZ2);
    EXPORT void *Core_CreateColShapeRectangle(float x1, float y1, float x2, float y2, float z);
    EXPORT void *Core_CreateColShapeCircle(float posX, float posY, float posZ, float radius);
    EXPORT void *Core_CreateColShapeSphere(float posX, float posY, float posZ, float radius);
#ifdef __cplusplus
}
#endif
