#pragma once

#include "Main.h"

#ifdef __cplusplus
extern "C"
{
#endif
EXPORT const char *Player_GetName(void *p);
EXPORT int Player_HasMetaData(void *base, const char *key);
EXPORT MetaData Player_GetMetaData(void *base, const char *key);
EXPORT void Player_SetMetaData(void *base, const char *key, void *val);
EXPORT void Player_DeleteMetaData(void *base, const char *key);
EXPORT int Player_HasSyncedMetaData(void *base, const char *key);
EXPORT MetaData Player_GetSyncedMetaData(void *base, const char *key);
EXPORT void Player_SetSyncedMetaData(void *base, const char *key, void *val);
EXPORT void Player_DeleteSyncedMetaData(void *base, const char *key);
EXPORT int Player_HasStreamSyncedMetaData(void *base, const char *key);
EXPORT MetaData Player_GetStreamSyncedMetaData(void *base, const char *key);
EXPORT void Player_SetStreamSyncedMetaData(void *base, const char *key, void *val);
EXPORT void Player_DeleteStreamSyncedMetaData(void *base, const char *key);
EXPORT Position Player_GetPosition(void *p);
EXPORT void Player_SetPosition(void *p, float x, float y, float z);
EXPORT Rotation Player_GetRotation(void *p);
EXPORT void Player_SetRotation(void *p, float roll, float pitch, float yaw);
EXPORT long Player_GetDimension(void *p);
EXPORT void Player_SetDimension(void *p, long dimension);
EXPORT void Player_Spawn(void *p, float x, float y, float z, unsigned long delay);
EXPORT void Player_Despawn(void *p);
EXPORT void Player_SetModel(void *p, unsigned long model);
EXPORT unsigned long Player_GetModel(void *p);
EXPORT unsigned int Player_GetHealth(void *p);
EXPORT void Player_SetHealth(void *p, unsigned int health);
EXPORT int Player_HasWeaponComponent(void *p, unsigned long weapon, unsigned long component);
EXPORT Array Player_GetCurrentWeaponComponents(void *p);
EXPORT unsigned int Player_GetWeaponTintIndex(void *p, unsigned long weapon);
EXPORT unsigned int Player_GetCurrentWeaponTintIndex(void *p);
EXPORT unsigned long Player_GetCurrentWeapon(void *p);
EXPORT int Player_IsDead(void *p);
EXPORT int Player_IsJumping(void *p);
EXPORT int Player_IsInRagdoll(void *p);
EXPORT int Player_IsAiming(void *p);
EXPORT int Player_IsShooting(void *p);
EXPORT int Player_IsReloading(void *p);
EXPORT unsigned int Player_GetArmour(void *p);
EXPORT void Player_SetArmour(void *p, unsigned int armour);
EXPORT float Player_GetMoveSpeed(void *p);
EXPORT Position Player_GetAimPos(void *p);
EXPORT Rotation Player_GetHeadRotation(void *p);
EXPORT int Player_IsInVehicle(void *p);
EXPORT void *Player_GetVehicle(void *p);
EXPORT unsigned int Player_GetSeat(void *p);
EXPORT void *Player_GetEntityAimingAt(void *p);
EXPORT Position Player_GetEntityAimOffset(void *p);
EXPORT int Player_IsFlashlightActive(void *p);
EXPORT int Player_IsConnected(void *p);
EXPORT unsigned long Player_GetPing(void *p);
EXPORT const char *Player_GetIP(void *p);
EXPORT unsigned long long Player_GetSocialID(void *p);
EXPORT unsigned long long Player_GetHwidHash(void *p);
EXPORT unsigned long long Player_GetHwidExHash(void *p);
EXPORT const char *Player_GetAuthToken(void *p);
EXPORT void Player_SetMaxArmour(void *p, unsigned int armour);
EXPORT void Player_SetCurrentWeapon(void *p, unsigned long weapon);
EXPORT void Player_SetWeaponTintIndex(void *p, unsigned long weapon, unsigned int tintIndex);
EXPORT void Player_AddWeaponComponent(void *p, unsigned long weapon, unsigned long component);
EXPORT void Player_RemoveWeaponComponent(void *p, unsigned long weapon, unsigned long component);
EXPORT void Player_ClearBloodDamage(void *p);
EXPORT void Player_SetMaxHealth(void *p, unsigned int health);
EXPORT void Player_GiveWeapon(void *p, unsigned long weapon, long ammo, int selectWeapon);
EXPORT void Player_RemoveWeapon(void *p, unsigned long weapon);
EXPORT void Player_RemoveAllWeapons(void *p);
EXPORT void Player_SetDateTime(void *p, int day, int month, int year, int hour, int minute, int second);
EXPORT void Player_SetWeather(void *p, unsigned long weather);
EXPORT void Player_Kick(void *p, const char *reason);
EXPORT Cloth Player_GetClothes(void *p, unsigned int component);
EXPORT DlcCloth Player_GetDlcClothes(void *p, unsigned int component);
EXPORT Prop Player_GetProps(void *p, unsigned int component);
EXPORT DlcProp Player_GetDlcProps(void *p, unsigned int component);
EXPORT void
Player_SetClothes(void *p, unsigned int component, unsigned int drawable, unsigned int texture, unsigned int palette);
EXPORT void
Player_SetDlcClothes(void *p, unsigned int component, unsigned int drawable, unsigned int texture, unsigned int palette,
                     unsigned long dlc);
EXPORT void Player_SetProps(void *p, unsigned int component, unsigned int drawable, unsigned int texture);
EXPORT void
Player_SetDlcProps(void *p, unsigned int component, unsigned int drawable, unsigned int texture, unsigned long dlc);
EXPORT void Player_ClearProps(void *p, unsigned int component);
EXPORT int Player_IsEntityInStreamingRange(void *p, void *entity);
EXPORT unsigned int Player_GetMaxHealth(void *p);
EXPORT unsigned int Player_GetMaxArmour(void *p);
EXPORT void Player_Detach(void *p);
EXPORT void
Player_AttachToEntity(void *p, void *e, int otherBoneIndex, int myBoneIndex, Position position, Rotation rotation,
                      int collision, int noFixedRotation);
EXPORT void Player_SetVisible(void *p, int toggle);
EXPORT int Player_GetVisible(void *p);
EXPORT unsigned long Player_GetID(void *p);
EXPORT void *Player_GetNetworkOwner(void *p);
EXPORT void Player_SetNetworkOwner(void *p, void *owner, int disableMigration);
EXPORT void Player_Destroy(void *p);
EXPORT int Player_IsValid(void *p);
EXPORT int Player_GetStreamed(void *p);
EXPORT void Player_SetStreamed(void *p, int toggle);
EXPORT int Player_GetInvincible(void *p);
EXPORT void Player_SetInvincible(void *p, int toggle);
EXPORT void Player_SetIntoVehicle(void *p, void *v, unsigned char seat);

EXPORT int Player_IsFrozen(void *p);
EXPORT void Player_SetFrozen(void *p, int state);
EXPORT int Player_HasCollision(void *p);
EXPORT void Player_SetCollision(void *p, int state);
#ifdef __cplusplus
}
#endif
