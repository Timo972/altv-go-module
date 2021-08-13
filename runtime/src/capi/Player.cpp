#include "Player.h"

EXPORT const char *Player_GetName(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer *>(p);
    return player->GetName().CStr();
}

EXPORT int Player_HasMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    return baseObject->HasMetaData(key);
}

EXPORT MetaData Player_GetMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    auto meta = baseObject->GetMetaData(key);

    // Temporary
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
}

EXPORT void Player_SetMetaData(void *base, const char *key, void *val)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    auto value = reinterpret_cast<alt::IMValue*>(val);

    baseObject->SetMetaData(key, value);
}

EXPORT void Player_DeleteMetaData(void *base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    baseObject->DeleteMetaData(key);
    baseObject->RemoveRef();
}

EXPORT int Player_HasSyncedMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    return baseObject->HasSyncedMetaData(key);
}


EXPORT MetaData Player_GetSyncedMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    auto meta = baseObject->GetSyncedMetaData(key);

    // Temporary
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
}

EXPORT void Player_SetSyncedMetaData(void *base, const char *key, void *val)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    auto value = reinterpret_cast<alt::IMValue*>(val);

    baseObject->SetSyncedMetaData(key, value);
}

EXPORT void Player_DeleteSyncedMetaData(void *base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    baseObject->DeleteSyncedMetaData(key);
    baseObject->RemoveRef();
}

EXPORT int Player_HasStreamSyncedMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    return baseObject->HasStreamSyncedMetaData(key);
}


EXPORT MetaData Player_GetStreamSyncedMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    auto meta = baseObject->GetStreamSyncedMetaData(key);

    // Temporary
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
}

EXPORT void Player_SetStreamSyncedMetaData(void *base, const char *key, void *val)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    auto value = reinterpret_cast<alt::IMValue*>(val);

    baseObject->SetStreamSyncedMetaData(key, value);
}

EXPORT void Player_DeleteStreamSyncedMetaData(void *base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    baseObject->DeleteStreamSyncedMetaData(key);
    baseObject->RemoveRef();
}

EXPORT Position Player_GetPosition(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    auto pos = player->GetPosition();

    Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;

    return position;
}

EXPORT void Player_SetPosition(void *p, float x, float y, float z)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);

    alt::Position position;
    position.x = x;
    position.y = y;
    position.z = z;

    player->SetPosition(position);
}

EXPORT Rotation Player_GetRotation(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    auto rot = player->GetRotation();

    Rotation rotation;
    rotation.pitch = rot.pitch;
    rotation.yaw = rot.yaw;
    rotation.roll = rot.roll;

    return rotation;
}

EXPORT void Player_SetRotation(void *p, float roll, float pitch, float yaw)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);

    alt::Rotation rotation;
    rotation.roll = roll;
    rotation.pitch = pitch;
    rotation.yaw = yaw;

    player->SetRotation(rotation);
}

EXPORT long Player_GetDimension(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetDimension();
}

EXPORT void Player_SetDimension(void *p, long dimension)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetDimension(dimension);
}

EXPORT void Player_Spawn(void *p, float x, float y, float z, unsigned long delay)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);

    alt::Position position;
    position.x = x;
    position.y = y;
    position.z = z;

    player->Spawn(position, delay);
}

EXPORT void Player_Despawn(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->Despawn();
}

EXPORT unsigned long Player_GetModel(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetModel();
}

EXPORT void Player_SetModel(void *p, unsigned long model)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetModel(model);
}

EXPORT unsigned long Player_GetHealth(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetHealth();
}

EXPORT void Player_SetHealth(void *p, unsigned long health)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetHealth(health);
}

EXPORT bool Player_HasWeaponComponent(void *p, unsigned long weapon, unsigned long component)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->HasWeaponComponent(weapon, component);
}

/*EXPORT alt::Array<unsigned int> Player_GetCurrentWeaponComponents(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    auto components = player->GetCurrentWeaponComponents();

    return components;
}*/

EXPORT unsigned long Player_GetWeaponTintIndex(void *p, unsigned long weapon)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetWeaponTintIndex(weapon);
}

EXPORT unsigned long Player_GetCurrentWeaponTintIndex(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetCurrentWeaponTintIndex();
}

EXPORT unsigned long Player_GetCurrentWeapon(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetCurrentWeapon();
}

EXPORT bool Player_IsDead(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->IsDead();
}

EXPORT bool Player_IsJumping(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->IsJumping();
}

EXPORT bool Player_IsInRagdoll(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->IsInRagdoll();
}

EXPORT bool Player_IsAiming(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->IsAiming();
}

EXPORT bool Player_IsShooting(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->IsShooting();
}

EXPORT bool Player_IsReloading(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->IsReloading();
}

EXPORT unsigned long Player_GetArmour(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetArmour();
}

EXPORT void Player_SetArmour(void *p, unsigned long armour)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetArmour(armour);
}

EXPORT float Player_GetMoveSpeed(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetMoveSpeed();
}

EXPORT Position Player_GetAimPos(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    auto pos = player->GetAimPos();

    Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;

    return position;
}

EXPORT Rotation Player_GetHeadRotation(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    auto rot = player->GetHeadRotation();

    Rotation rotation;
    rotation.pitch = rot.pitch;
    rotation.roll = rot.roll;
    rotation.yaw = rot.yaw;

    return rotation;
}

EXPORT bool Player_IsInVehicle(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->IsInVehicle();
}

EXPORT void * Player_GetVehicle(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetVehicle().Get();
}

EXPORT unsigned long Player_GetSeat(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetSeat();
}

EXPORT void * Player_GetEntityAimingAt(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetEntityAimingAt().Get();
}

EXPORT Position Player_GetEntityAimOffset(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    auto pos = player->GetEntityAimOffset();

    Position offset;
    offset.x = pos.x;
    offset.y = pos.y;
    offset.z = pos.z;

    return offset;
}

EXPORT bool Player_IsFlashlightActive(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->IsFlashlightActive();
}

EXPORT bool Player_IsConnected(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->IsConnected();
}

EXPORT unsigned long Player_GetPing(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetPing();
}

EXPORT const char* Player_GetIP(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetIP().CStr();
}

EXPORT unsigned long long Player_GetSocialID(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetSocialID();
}

EXPORT unsigned long long Player_GetHwidHash(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetHwidHash();
}

EXPORT unsigned long long Player_GetHwidExHash(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetHwidExHash();
}

EXPORT const char* Player_GetAuthToken(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetAuthToken().CStr();
}

EXPORT void Player_SetMaxArmour(void *p, unsigned long armour)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetMaxArmour(armour);
}

EXPORT void Player_SetCurrentWeapon(void *p, unsigned long weapon)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetCurrentWeapon(weapon);
}

EXPORT void Player_SetWeaponTintIndex(void *p, unsigned long weapon, unsigned long tintIndex)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetWeaponTintIndex(weapon, tintIndex);
}

EXPORT void Player_AddWeaponComponent(void *p, unsigned long weapon, unsigned long component)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->AddWeaponComponent(weapon, component);
}

EXPORT void Player_RemoveWeaponComponent(void *p, unsigned long weapon, unsigned long component)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->RemoveWeaponComponent(weapon, component);
}

EXPORT void Player_ClearBloodDamage(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->ClearBloodDamage();
}

EXPORT void Player_SetMaxHealth(void *p, unsigned long health)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetMaxHealth(health);
}

EXPORT void Player_GiveWeapon(void *p, unsigned long weapon, unsigned long ammo, bool selectWeapon)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->GiveWeapon(weapon, ammo, selectWeapon);
}

EXPORT void Player_RemoveWeapon(void *p, unsigned long weapon)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->RemoveWeapon(weapon);
}

EXPORT void Player_RemoveAllWeapons(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->RemoveAllWeapons();
}

EXPORT void Player_SetDateTime(void *p, int day, int month, int year, int hour, int minute, int second)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetDateTime(day, month, year, hour, minute, second);
}

EXPORT void Player_SetWeather(void *p, unsigned long weather)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetWeather(weather);
}

EXPORT void Player_Kick(void *p, const char* reason)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->Kick(reason);
}

EXPORT void Player_SetClothes(void *p, unsigned long component, unsigned long drawable, unsigned long texture, unsigned long palette)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetClothes(component, drawable, texture, palette);
}

EXPORT void Player_SetDlcClothes(void *p, unsigned long component, unsigned long drawable, unsigned long texture, unsigned long palette, unsigned long dlc)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetDlcClothes(component, drawable, texture, palette, dlc);
}

EXPORT void Player_SetProps(void *p, unsigned long component, unsigned long drawable, unsigned long texture)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetProps(component, drawable, texture);
}

EXPORT void Player_SetDlcProps(void *p, unsigned long component, unsigned long drawable, unsigned long texture, unsigned long dlc)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetDlcProps(component, drawable, texture, dlc);
}

EXPORT void Player_ClearProps(void *p, unsigned long component)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->ClearProps(component);
}

EXPORT bool Player_IsEntityInStreamingRange(void *p, void *e) {
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    auto entity = reinterpret_cast<alt::IEntity*>(e);
    return player->IsEntityInStreamingRange(entity);
}

EXPORT unsigned long Player_GetMaxHealth(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetMaxHealth();
}

EXPORT unsigned long Player_GetMaxArmour(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetMaxArmour();
}

EXPORT void Player_Detach(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->Detach();
}

EXPORT void Player_AttachToEntity(void *p, void *e, unsigned long otherBoneIndex, unsigned long myBoneIndex, Position pos, Rotation rot, bool collision, bool noFixedRotation)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    auto entity = reinterpret_cast<alt::IEntity*>(e);
    auto position = new alt::Position(pos.x, pos.y, pos.z);
    auto rotation = new alt::Rotation(rot.roll, rot.pitch, rot.yaw);
    player->AttachToEntity(entity, otherBoneIndex, myBoneIndex, *position, *rotation, collision, noFixedRotation);
}

EXPORT void Player_SetVisible(void *p, bool toggle)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetVisible(toggle);
}

EXPORT bool Player_GetVisible(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetVisible();
}

EXPORT unsigned long Player_GetID(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetID();
}

EXPORT void * Player_GetNetworkOwner(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetNetworkOwner().Get();
}

EXPORT void Player_SetNetworkOwner(void *p, void *o, bool disableMigration){
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    auto owner = reinterpret_cast<alt::IPlayer*>(o);
    player->SetNetworkOwner(owner, disableMigration);
}