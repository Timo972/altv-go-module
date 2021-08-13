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
    EXPORT int Player_HasSyncedMetaData(void* base, const char *key);
    EXPORT MetaData Player_GetSyncedMetaData(void* base, const char *key);
    EXPORT void Player_SetSyncedMetaData(void *base, const char *key, void *val);
    EXPORT void Player_DeleteSyncedMetaData(void *base, const char *key);
    EXPORT int Player_HasStreamSyncedMetaData(void* base, const char *key);
    EXPORT MetaData Player_GetStreamSyncedMetaData(void* base, const char *key);
    EXPORT void Player_SetStreamSyncedMetaData(void *base, const char *key, void *val);
    EXPORT void Player_DeleteStreamSyncedMetaData(void *base, const char *key);
    EXPORT Position Player_GetPosition(void *p);
    EXPORT void Player_SetPosition(void* p, float x, float y, float z);
    EXPORT Rotation Player_GetRotation(void *p);
    EXPORT void Player_SetRotation(void *p, float roll, float pitch, float yaw);
    EXPORT long Player_GetDimension(void* p);
    EXPORT void Player_SetDimension(void* p, long dimension);
    EXPORT void Player_Spawn(void *p, float x, float y, float z, unsigned long delay);
    EXPORT void Player_Despawn(void *p);
    EXPORT void Player_SetModel(void *p, unsigned long model);
    EXPORT unsigned long Player_GetModel(void *p);
    EXPORT unsigned long Player_GetHealth(void *p);
    EXPORT void Player_SetHealth(void *p, unsigned long health);
    EXPORT bool Player_HasWeaponComponent(void *p, unsigned long weapon, unsigned long component);
    //EXPORT alt::Array<unsigned int> Player_GetCurrentWeaponComponents(void *p);
    EXPORT unsigned long Player_GetWeaponTintIndex(void *p, unsigned long weapon);
    EXPORT unsigned long Player_GetCurrentWeaponTintIndex(void *p);
    EXPORT unsigned long Player_GetCurrentWeapon(void *p);
    EXPORT bool Player_IsDead(void *p);
    EXPORT bool Player_IsJumping(void *p);
    EXPORT bool Player_IsInRagdoll(void *p);
    EXPORT bool Player_IsAiming(void *p);
    EXPORT bool Player_IsShooting(void *p);
    EXPORT bool Player_IsReloading(void *p);
    EXPORT unsigned long Player_GetArmour(void *p);
    EXPORT void Player_SetArmour(void *p, unsigned long armour);
    EXPORT float Player_GetMoveSpeed(void *p);
    EXPORT Position Player_GetAimPos(void *p);
    EXPORT Rotation Player_GetHeadRotation(void *p);
    EXPORT bool Player_IsInVehicle(void *p);
    EXPORT void * Player_GetVehicle(void *p);
    EXPORT unsigned long Player_GetSeat(void *p);
    EXPORT void * Player_GetEntityAimingAt(void *p);
    EXPORT Position Player_GetEntityAimOffset(void *p);
    EXPORT bool Player_IsFlashlightActive(void *p);
    EXPORT bool Player_IsConnected(void *p);
    EXPORT unsigned long Player_GetPing(void *p);
    EXPORT const char* Player_GetIP(void *p);
    EXPORT unsigned long long Player_GetSocialID(void *p);
    EXPORT unsigned long long Player_GetHwidHash(void *p);
    EXPORT unsigned long long Player_GetHwidExHash(void *p);
    EXPORT const char* Player_GetAuthToken(void *p);
    EXPORT void Player_SetMaxArmour(void *p, unsigned long armour);
    EXPORT void Player_SetCurrentWeapon(void *p, unsigned long weapon);
    EXPORT void Player_SetWeaponTintIndex(void *p, unsigned long weapon, unsigned long tintIndex);
    EXPORT void Player_AddWeaponComponent(void *p, unsigned long weapon, unsigned long component);
    EXPORT void Player_RemoveWeaponComponent(void *p, unsigned long weapon, unsigned long component);
    EXPORT void Player_ClearBloodDamage(void *p);
    EXPORT void Player_SetMaxHealth(void *p, unsigned long health);
    EXPORT void Player_GiveWeapon(void *p, unsigned long weapon, unsigned long ammo, bool selectWeapon);
    EXPORT void Player_RemoveWeapon(void *p, unsigned long weapon);
    EXPORT void Player_RemoveAllWeapons(void *p);
    EXPORT void Player_SetDateTime(void *p, int day, int month, int year, int hour, int minute, int second);
    EXPORT void Player_SetWeather(void *p, unsigned long weather);
    EXPORT void Player_Kick(void *p, const char* reason);
    /**
     * Cloth and Prop Getters
     * */
    EXPORT void Player_SetClothes(void *p, unsigned long component, unsigned long drawable, unsigned long texture, unsigned long palette);
    EXPORT void Player_SetDlcClothes(void *p, unsigned long component, unsigned long drawable, unsigned long texture, unsigned long palette, unsigned long dlc);
    EXPORT void Player_SetProps(void *p, unsigned long component, unsigned long drawable, unsigned long texture);
    EXPORT void Player_SetDlcProps(void *p, unsigned long component, unsigned long drawable, unsigned long texture, unsigned long dlc);
    EXPORT void Player_ClearProps(void *p, unsigned long component);
    EXPORT bool Player_IsEntityInStreamingRange(void *p, void *entity);
    EXPORT unsigned long Player_GetMaxHealth(void *p);
    EXPORT unsigned long Player_GetMaxArmour(void *p);
    EXPORT void Player_Detach(void *p);
    EXPORT void Player_AttachToEntity(void *p, void *e, unsigned long otherBoneIndex, unsigned long myBoneIndex, Position position, Rotation rotation, bool collision, bool noFixedRotation);
    EXPORT void Player_SetVisible(void *p, bool toggle);
    EXPORT bool Player_GetVisible(void *p);
    EXPORT unsigned long Player_GetID(void *p);
    EXPORT void * Player_GetNetworkOwner(void *p);
    EXPORT void Player_SetNetworkOwner(void *p, void *owner, bool disableMigration);

#ifdef __cplusplus
}
#endif
