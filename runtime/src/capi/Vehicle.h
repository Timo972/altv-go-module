#pragma once

#include "Main.h"

#ifdef __cplusplus
extern "C"
{
#endif
    EXPORT void * Vehicle_GetDriver(void *v);
    EXPORT bool Vehicle_IsDestroyed(void *v);
    EXPORT unsigned long Vehicle_GetMod(void *v, unsigned long category);
    EXPORT unsigned long Vehicle_GetModsCount(void *v, unsigned long category);
    EXPORT unsigned long Vehicle_GetModKitsCount(void *v);
    EXPORT unsigned long Vehicle_GetModKit(void *v);
    EXPORT bool Vehicle_IsPrimaryColorRGB(void *v);
    EXPORT unsigned long Vehicle_GetPrimaryColor(void *v);
    EXPORT RGBA Vehicle_GetPrimaryColorRGBA(void *v);
    EXPORT bool Vehicle_IsSecondaryColorRGB(void *v);
    EXPORT unsigned long Vehicle_GetSecondaryColor(void *v);
    EXPORT RGBA Vehicle_GetSecondaryColorRGBA(void *v);
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
    EXPORT bool Vehicle_IsExtraOn(void *v, unsigned long extraID);
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
    EXPORT unsigned long Vehicle_GetDoorState(void *v, unsigned long doorId);
    EXPORT bool Vehicle_IsWindowOpened(void *v, unsigned long windowId);
    EXPORT bool Vehicle_IsDaylightOn(void *v);
    EXPORT bool Vehicle_IsNeonlightOn(void *v);
    EXPORT unsigned long Vehicle_GetRoofState(void *v);
    EXPORT bool Vehicle_IsFlamethrowerActive(void *v);
    EXPORT float Vehicle_GetLightsMultiplier(void *v);
    EXPORT const char* Vehicle_GetGameStateBase64(void *v);
    EXPORT unsigned long Vehicle_GetEngineHealth(void *v);
    EXPORT unsigned long Vehicle_GetPetrolTankHealth(void *v);
    EXPORT unsigned long Vehicle_GetWheelsCount(void *v);
    EXPORT bool Vehicle_IsWheelBurst(void *v, unsigned long wheelId);
    EXPORT bool Vehicle_DoesWheelHasTire(void *v, unsigned long wheelId);
    EXPORT bool Vehicle_IsWheelDetached(void *v, unsigned long wheelId);
    EXPORT bool Vehicle_IsWheelOnFire(void *v, unsigned long wheelId);
    EXPORT float Vehicle_GetWHeelHealth(void *v, unsigned long wheelId);
    EXPORT unsigned long Vehicle_GetRepairsCount(void *v);
    EXPORT unsigned long Vehicle_GetBodyHealth(void *v);
    EXPORT unsigned long Vehicle_GetBodyAdditionalHealth(void *v);
    EXPORT const char* Vehicle_GetHealthDataBase64(void *v);
    EXPORT unsigned long Vehicle_GetPartDamageLevel(void *v, unsigned long partId);
    EXPORT unsigned long Vehicle_GetPartBulletHoles(void *v, unsigned long partId);
    EXPORT bool Vehicle_IsLightDamaged(void *v);
    EXPORT bool Vehicle_IsWindowDamaged(void *v);
    EXPORT bool Vehicle_IsSpecialLightDamaged(void *v);
    EXPORT bool Vehicle_HasArmoredWindows(void *v);
    EXPORT float Vehicle_GetArmoredWindowHealth(void *v, unsigned long windowId);
    EXPORT unsigned long Vehicle_GetArmoredWindowShootCount(void *v, unsigned long windowId);
    EXPORT unsigned long Vehicle_GetBumperDamageLevel(void *v, unsigned long bumperId);
    EXPORT const char* Vehicle_GetDamageDataBase64(void *v);
    EXPORT bool Vehicle_IsManualEngineControl(void *v);
    EXPORT const char* Vehicle_GetScriptDataBase64(void *v);
    EXPORT void Vehicle_ToggleExtra(void *v, unsigned long extraID, bool state);

#ifdef __cplusplus
}
#endif
