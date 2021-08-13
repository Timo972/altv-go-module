#pragma once

#include "Main.h"

#ifdef __cplusplus
extern "C"
{
#endif
    EXPORT int Vehicle_HasMetaData(void* base, const char *key);
    EXPORT MetaData Vehicle_GetMetaData(void* base, const char *key);
    EXPORT void Vehicle_SetMetaData(void *base, const char *key, void *val);
    EXPORT void Vehicle_DeleteMetaData(void *base, const char *key);
    EXPORT int Vehicle_HasSyncedMetaData(void* base, const char *key);
    EXPORT MetaData Vehicle_GetSyncedMetaData(void* base, const char *key);
    EXPORT void Vehicle_SetSyncedMetaData(void *base, const char *key, void *val);
    EXPORT void Vehicle_DeleteSyncedMetaData(void *base, const char *key);
    EXPORT int Vehicle_HasStreamSyncedMetaData(void* base, const char *key);
    EXPORT MetaData Vehicle_GetStreamSyncedMetaData(void* base, const char *key);
    EXPORT void Vehicle_SetStreamSyncedMetaData(void *base, const char *key, void *val);
    EXPORT void Vehicle_DeleteStreamSyncedMetaData(void *base, const char *key);
    
    EXPORT Position Vehicle_GetPosition(void *v);
    EXPORT void Vehicle_SetPosition(void *v, float x, float y, float z);
    EXPORT Rotation Vehicle_GetRotation(void *v);
    EXPORT void Vehicle_SetRotation(void *v, float roll, float pitch, float yaw);
    EXPORT long Vehicle_GetDimension(void *v);
    EXPORT void Vehicle_SetDimension(void *v, long dimension);

    EXPORT unsigned long Vehicle_GetID(void *v);
    EXPORT unsigned long Vehicle_GetModel(void *v);
    
    EXPORT void Vehicle_Detach(void *v);
    EXPORT void Vehicle_AttachToEntity(void *v, void *e, unsigned int otherBoneIndex, unsigned int myBoneIndex, Position position, Rotation rotation, bool collision, bool noFixedRotation);
    EXPORT void Vehicle_SetVisible(void *v, bool toggle);
    EXPORT bool Vehicle_GetVisible(void *v);
    EXPORT void * Vehicle_GetNetworkOwner(void *v);
    EXPORT void Vehicle_SetNetworkOwner(void *v, void *owner, bool disableMigration);

    EXPORT void * Vehicle_GetDriver(void *v);
    EXPORT bool Vehicle_IsDestroyed(void *v);
    EXPORT unsigned long Vehicle_GetMod(void *v, unsigned int category);
    EXPORT unsigned long Vehicle_GetModsCount(void *v, unsigned int category);
    EXPORT unsigned long Vehicle_GetModKitsCount(void *v);
    EXPORT unsigned long Vehicle_GetModKit(void *v);
    EXPORT bool Vehicle_IsPrimaryColorRGB(void *v);
    EXPORT unsigned long Vehicle_GetPrimaryColor(void *v);
    EXPORT RGBA Vehicle_GetPrimaryColorRGB(void *v);
    EXPORT bool Vehicle_IsSecondaryColorRGB(void *v);
    EXPORT unsigned long Vehicle_GetSecondaryColor(void *v);
    EXPORT RGBA Vehicle_GetSecondaryColorRGB(void *v);
    EXPORT unsigned long Vehicle_GetPearlColor(void *v);
    EXPORT unsigned long Vehicle_GetWheelColor(void *v);
    EXPORT unsigned long Vehicle_GetInteriorColor(void *v);
    EXPORT unsigned long Vehicle_GetDashboardColor(void *v);
    EXPORT bool Vehicle_IsTireSmokeColorCustom(void *v);
    EXPORT RGBA Vehicle_GetTireSmokeColor(void *v);
    EXPORT unsigned long Vehicle_GetWheelType(void *v);
    EXPORT unsigned long Vehicle_GetWheelVariation(void *v);
    EXPORT unsigned long Vehicle_GetRearWheelVariation(void *v);
    EXPORT bool Vehicle_GetCustomTires(void *v);
    EXPORT unsigned long Vehicle_GetSpecialDarkness(void *v);
    EXPORT unsigned long Vehicle_GetNumberplateIndex(void *v);
    EXPORT const char* Vehicle_GetNumberplateText(void *v);
    EXPORT unsigned long Vehicle_GetWindowTint(void *v);
    EXPORT unsigned long Vehicle_GetDirtLevel(void *v);
    EXPORT bool Vehicle_IsExtraOn(void *v, unsigned int extraID);
    EXPORT bool Vehicle_IsNeonActive(void *v);
    EXPORT void Vehicle_GetNeonActive(void *v, bool *left, bool *right, bool *front, bool *back);
    EXPORT RGBA Vehicle_GetNeonColor(void *v);
    EXPORT unsigned long Vehicle_GetLivery(void *v);
    EXPORT unsigned long Vehicle_GetRoofLivery(void *v);
    EXPORT const char* Vehicle_GetAppearanceDataBase64(void *v);
    EXPORT bool Vehicle_IsEngineOn(void *v);
    EXPORT bool Vehicle_IsHandbrakeActive(void *v);
    EXPORT unsigned long Vehicle_GetHeadlightColor(void *v);
    EXPORT unsigned long Vehicle_GetRadioStationIndex(void *v);
    EXPORT bool Vehicle_IsSirenActive(void *v);
    EXPORT unsigned long Vehicle_GetLockState(void *v);
    EXPORT unsigned long Vehicle_GetDoorState(void *v, unsigned int doorId);
    EXPORT bool Vehicle_IsWindowOpened(void *v, unsigned int windowId);
    EXPORT bool Vehicle_IsDaylightOn(void *v);
    EXPORT bool Vehicle_IsNightlightOn(void *v);
    EXPORT unsigned long Vehicle_GetRoofState(void *v);
    EXPORT bool Vehicle_IsFlamethrowerActive(void *v);
    EXPORT float Vehicle_GetLightsMultiplier(void *v);
    EXPORT const char* Vehicle_GetGameStateBase64(void *v);
    EXPORT unsigned long Vehicle_GetEngineHealth(void *v);
    EXPORT unsigned long Vehicle_GetPetrolTankHealth(void *v);
    EXPORT unsigned long Vehicle_GetWheelsCount(void *v);
    EXPORT bool Vehicle_IsWheelBurst(void *v, unsigned int wheelId);
    EXPORT bool Vehicle_DoesWheelHasTire(void *v, unsigned int wheelId);
    EXPORT bool Vehicle_IsWheelDetached(void *v, unsigned int wheelId);
    EXPORT bool Vehicle_IsWheelOnFire(void *v, unsigned int wheelId);
    EXPORT float Vehicle_GetWheelHealth(void *v, unsigned int wheelId);
    EXPORT unsigned long Vehicle_GetRepairsCount(void *v);
    EXPORT unsigned long Vehicle_GetBodyHealth(void *v);
    EXPORT unsigned long Vehicle_GetBodyAdditionalHealth(void *v);
    EXPORT const char* Vehicle_GetHealthDataBase64(void *v);
    EXPORT unsigned long Vehicle_GetPartDamageLevel(void *v, unsigned int partId);
    EXPORT unsigned long Vehicle_GetPartBulletHoles(void *v, unsigned int partId);
    EXPORT bool Vehicle_IsLightDamaged(void *v, unsigned int lightId);
    EXPORT bool Vehicle_IsWindowDamaged(void *v, unsigned int windowId);
    EXPORT bool Vehicle_IsSpecialLightDamaged(void *v, unsigned int specialLightId);
    EXPORT bool Vehicle_HasArmoredWindows(void *v);
    EXPORT float Vehicle_GetArmoredWindowHealth(void *v, unsigned int windowId);
    EXPORT unsigned long Vehicle_GetArmoredWindowShootCount(void *v, unsigned int windowId);
    EXPORT unsigned long Vehicle_GetBumperDamageLevel(void *v, unsigned int bumperId);
    EXPORT const char* Vehicle_GetDamageDataBase64(void *v);
    EXPORT bool Vehicle_IsManualEngineControl(void *v);
    EXPORT const char* Vehicle_GetScriptDataBase64(void *v);
    EXPORT void Vehicle_ToggleExtra(void *v, unsigned int extraID, bool state);

    EXPORT void Vehicle_SetFixed(void *v);
    EXPORT bool Vehicle_SetMod(void *v, unsigned int category, unsigned int id);
    EXPORT bool Vehicle_SetModKit(void *v, unsigned int id);
    EXPORT void Vehicle_SetPrimaryColor(void *v, unsigned int color);
    EXPORT void Vehicle_SetPrimaryColorRGB(void *v, unsigned int r, unsigned int g, unsigned int b, unsigned int a);
    EXPORT void Vehicle_SetSecondaryColor(void *v, unsigned int color);
    EXPORT void Vehicle_SetSecondaryColorRGB(void *v, unsigned int r, unsigned int g, unsigned int b, unsigned int a);
    EXPORT void Vehicle_SetPearlColor(void *v, unsigned int color);
    EXPORT void Vehicle_SetWheelColor(void *v, unsigned int color);
    EXPORT void Vehicle_SetInteriorColor(void *v, unsigned int color);
    EXPORT void Vehicle_SetDashboardColor(void *v, unsigned int color);
    EXPORT void Vehicle_SetTireSmokeColor(void *v, unsigned int r, unsigned int g, unsigned int b, unsigned int a);
    EXPORT void Vehicle_SetWheels(void *v, unsigned int type, unsigned int variation);
    EXPORT void Vehicle_SetRearWheels(void *v, unsigned int variation);
    EXPORT void Vehicle_SetCustomTires(void *v, bool state);
    EXPORT void Vehicle_SetSpecialDarkness(void *v, unsigned int value);
    EXPORT void Vehicle_SetNumberplateIndex(void *v, unsigned int index);
    EXPORT void Vehicle_SetNumberplateText(void *v, const char* text);
    EXPORT void Vehicle_SetWindowTint(void *v, unsigned int tint);
    EXPORT void Vehicle_SetDirtLevel(void *v, unsigned int level);
    EXPORT void Vehicle_SetNeonActive(void *v, bool left, bool right, bool front, bool back);
    EXPORT void Vehicle_SetNeonColor(void *v, unsigned int r, unsigned int g, unsigned int b, unsigned int a);
    EXPORT void Vehicle_SetLivery(void *v, unsigned int livery);
    EXPORT void Vehicle_SetRoofLivery(void *v, unsigned int roofLivery);
    EXPORT void Vehicle_LoadAppearanceDataFromBase64(void *v, const char* base64);
    EXPORT void Vehicle_SetEngineOn(void *v, bool state);
    EXPORT void Vehicle_SetHeadlightColor(void *v, unsigned int color);
    EXPORT void Vehicle_SetRadioStationIndex(void *v, unsigned int stationIndex);
    EXPORT void Vehicle_SetSirenActive(void *v, bool state);
    EXPORT void Vehicle_SetLockState(void *v, unsigned int state);
    EXPORT void Vehicle_SetDoorState(void *v, unsigned int doorId, unsigned int state);
    EXPORT void Vehicle_SetWindowOpened(void *v, unsigned int windowId, bool state);
    EXPORT void Vehicle_SetRoofState(void *v, unsigned int state);
    EXPORT void Vehicle_SetLightsMultiplier(void *v, float multiplier);
    EXPORT void Vehicle_SetEngineHealth(void *v, unsigned long health);
    EXPORT void Vehicle_SetPetrolTankHealth(void *v, unsigned long health);
    EXPORT void Vehicle_SetWheelBurst(void *v, unsigned int wheelId, bool state);
    EXPORT void Vehicle_SetWheelHasTire(void *v, unsigned int wheelId, bool state);
    EXPORT void Vehicle_SetWheelDetached(void *v, unsigned int wheelId, bool state);
    EXPORT void Vehicle_SetWheelOnFire(void *v, unsigned int wheelId, bool state);
    EXPORT void Vehicle_SetWheelHealth(void *v, unsigned int wheelId, float health);
    EXPORT void Vehicle_SetWheelFixed(void *v, unsigned int wheelId);
    EXPORT void Vehicle_SetBodyHealth(void *v, unsigned long health);
    EXPORT void Vehicle_SetBodyAdditionalHealth(void *v, unsigned long health);
    EXPORT void Vehicle_SetPartDamageLevel(void *v, unsigned int partId, unsigned int damage);
    EXPORT void Vehicle_SetPartBulletHoles(void *v, unsigned int partId, unsigned int shootsCount);
    EXPORT void Vehicle_SetLightDamaged(void *v, unsigned int lightId, bool isDamaged);
    EXPORT void Vehicle_SetWindowDamaged(void *v, unsigned int windowId, bool isDamaged);
    EXPORT void Vehicle_SetSpecialLightDamaged(void *v, unsigned int specialLightId, bool isDamaged);
    EXPORT void Vehicle_SetArmoredWindowHealth(void *v, unsigned int windowId, float health);
    EXPORT void Vehicle_SetArmoredWindowShootCount(void *v, unsigned int windowId, unsigned int count);
    EXPORT void Vehicle_SetBumperDamageLevel(void *v, unsigned int bumperId, unsigned int damageLevel);
    EXPORT void Vehicle_SetManualEngineControl(void *v, bool state);
    EXPORT void Vehicle_LoadDamageDataFromBase64(void *v, const char* base64);
    EXPORT void Vehicle_LoadScriptDataFromBase64(void *v, const char* base64);
    EXPORT void Vehicle_LoadGameStateFromBase64(void *v, const char* base64);
    EXPORT void Vehicle_LoadHealthDataFromBase64(void *v, const char* base64);
    EXPORT void * Vehicle_GetAttached(void *v);
    EXPORT void * Vehicle_GetAttachedTo(void *v);

#ifdef __cplusplus
}
#endif
