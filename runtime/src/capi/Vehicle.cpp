#include "Vehicle.h"

EXPORT int Vehicle_HasMetaData(void* base, const char *key)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
   return vehicle->HasMetaData(key);
}

EXPORT MetaData Vehicle_GetMetaData(void* base, const char *key)
{

    auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
    auto meta = vehicle->GetMetaData(key);

    // Temporary
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
}

EXPORT void Vehicle_SetMetaData(void *base, const char *key, void *val)
{

    auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
    auto value = reinterpret_cast<alt::IMValue*>(val);

    vehicle->SetMetaData(key, value);
}

EXPORT void Vehicle_DeleteMetaData(void *base, const char *key)
{

    auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
    vehicle->DeleteMetaData(key);
    vehicle->RemoveRef();
}

EXPORT int Vehicle_HasSyncedMetaData(void* base, const char *key)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
   return vehicle->HasSyncedMetaData(key);
}

EXPORT MetaData Vehicle_GetSyncedMetaData(void* base, const char *key)
{

    auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
    auto meta = vehicle->GetSyncedMetaData(key);

    // Temporary
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
}

EXPORT void Vehicle_SetSyncedMetaData(void *base, const char *key, void *val)
{

    auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
    auto value = reinterpret_cast<alt::IMValue*>(val);

    vehicle->SetSyncedMetaData(key, value);
}

EXPORT void Vehicle_DeleteSyncedMetaData(void *base, const char *key)
{

    auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
    vehicle->DeleteSyncedMetaData(key);
    vehicle->RemoveRef();
}

EXPORT int Vehicle_HasStreamSyncedMetaData(void* base, const char *key)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
   return vehicle->HasStreamSyncedMetaData(key);
}

EXPORT MetaData Vehicle_GetStreamSyncedMetaData(void* base, const char *key)
{

    auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
    auto meta = vehicle->GetStreamSyncedMetaData(key);

    // Temporary
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
}

EXPORT void Vehicle_SetStreamSyncedMetaData(void *base, const char *key, void *val)
{

    auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
    auto value = reinterpret_cast<alt::IMValue*>(val);

    vehicle->SetStreamSyncedMetaData(key, value);
}

EXPORT void Vehicle_DeleteStreamSyncedMetaData(void *base, const char *key)
{

    auto vehicle = reinterpret_cast<alt::IVehicle*>(base);
    vehicle->DeleteStreamSyncedMetaData(key);
    vehicle->RemoveRef();
}

EXPORT Position Vehicle_GetPosition(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   auto pos = vehicle->GetPosition();

   Position position;
   position.x = pos.x;
   position.y = pos.y;
   position.z = pos.z;

   return position;
}

EXPORT void Vehicle_SetPosition(void *v, float x, float y, float z)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPosition(x, y, z);
}

EXPORT Rotation Vehicle_GetRotation(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   auto rot = vehicle->GetRotation();

   Rotation rotation;
   rotation.pitch = rot.pitch;
   rotation.yaw = rot.yaw;
   rotation.roll = rot.roll;

   return rotation;
}

EXPORT void Vehicle_SetRotation(void *v, float roll, float pitch, float yaw)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetRotation(roll, pitch, yaw);
}

EXPORT long Vehicle_GetDimension(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetDimension();
}

EXPORT void Vehicle_SetDimension(void *v, long dimension)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetDimension(dimension);
}

EXPORT unsigned long Vehicle_GetID(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetID();
}

EXPORT unsigned long Vehicle_GetModel(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetModel();
}

EXPORT void Player_Despawn(void *p)
{
   auto player = reinterpret_cast<alt::IPlayer*>(p);
   player->Despawn();
}

EXPORT void Vehicle_Detach(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->Detach();
}

EXPORT void Vehicle_AttachToEntity(void *v, void *e, unsigned long otherBoneIndex, unsigned long myBoneIndex, Position position, Rotation rotation, bool collision, bool noFixedRotation)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->AttachToEntity(e, otherBoneIndex, myBoneIndex, position, rotation, collision, noFixedRotation);
}

EXPORT void Vehicle_SetVisible(void *v, bool toggle)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetVisible(toggle);
}

EXPORT bool Vehicle_GetVisible(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetVisible();
}

EXPORT void * Vehicle_GetNetworkOwner(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetNetworkOwner().Get();
}

EXPORT void Vehicle_SetNetworkOwner(void *v, void *owner, bool disableMigration)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetNetworkOwner(owner, disableMigration);
}

EXPORT void * Vehicle_GetDriver(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetDriver().Get();
}

EXPORT bool Vehicle_IsDestroyed(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsDestroyed();
}

EXPORT unsigned long Vehicle_GetMod(void *v, unsigned long category)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetMod(category);
}

EXPORT unsigned long Vehicle_GetModsCount(void *v, unsigned long category)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetModsCount(category);
}

EXPORT unsigned long Vehicle_GetModKitsCount(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetModKitsCount();
}

EXPORT unsigned long Vehicle_GetModKit(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetModKit();
}

EXPORT bool Vehicle_IsPrimaryColorRGB(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsPrimaryColorRGB();
}

EXPORT unsigned long Vehicle_GetPrimaryColor(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetPrimaryColor();
}

EXPORT RGBA Vehicle_GetPrimaryColorRGB(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   auto rgb = vehicle->GetPrimaryColorRGB();

   RGBA rgba;
   rgba.r = rgb.r;
   rgba.g = rgb.g;
   rgba.b = rgb.b;
   rgba.a = rgb.a;

   return rgba;
}

EXPORT bool Vehicle_IsSecondaryColorRGB(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsSecondaryColorRGB();
}

EXPORT unsigned long Vehicle_GetSecondaryColor(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetSecondaryColor();
}

EXPORT RGBA Vehicle_GetSecondaryColorRGB(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   auto rgb = vehicle->GetSecondaryColorRGB();

   RGBA rgba;
   rgba.r = rgb.r;
   rgba.g = rgb.g;
   rgba.b = rgb.b;
   rgba.a = rgb.a;

   return rgba;
}

EXPORT unsigned long Vehicle_GetPearlColor(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetPearlColor();
}

EXPORT unsigned long Vehicle_GetWheelColor(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetWheelColor();
}

EXPORT unsigned long Vehicle_GetInteriorColor(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetInteriorColor();
}

EXPORT unsigned long Vehicle_GetDashboardColor(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetDashboardColor();
}

EXPORT bool Vehicle_IsTireSmokeColorCustom(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsTireSmokeColorCustom();
}

EXPORT RGBA Vehicle_GetTireSmokeColor(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   auto rgb = vehicle->GetTireSmokeColor();

   RGBA rgba;
   rgba.r = rgb.r;
   rgba.g = rgb.g;
   rgba.b = rgb.b;
   rgba.a = rgb.a;

   return rgba;
}

EXPORT unsigned long Vehicle_GetWheelType(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetWheelType();
}

EXPORT unsigned long Vehicle_GetWheelVariation(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetWheelVariation();
}

EXPORT unsigned long Vehicle_GetRearWheelVariation(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetRearWheelVariation();
}

EXPORT bool Vehicle_GetCustomTires(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetCustomTires();
}

EXPORT unsigned long Vehicle_GetSpecialDarkness(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetSpecialDarkness();
}

EXPORT unsigned long Vehicle_GetNumberplateIndex(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetNumberplateIndex();
}

EXPORT const char* Vehicle_GetNumberplateText(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetNumberplateText().CStr();
}

EXPORT unsigned long Vehicle_GetWindowTint(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetWindowTint();
}

EXPORT unsigned long Vehicle_GetDirtLevel(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetDirtLevel();
}

EXPORT bool Vehicle_IsExtraOn(void *v, unsigned long extraID)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsExtraOn(extraID);
}

EXPORT bool Vehicle_IsNeonActive(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsNeonActive();
}

EXPORT void Vehicle_GetNeonActive(void *v, bool *left, bool *right, bool *front, bool *back)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->GetNeonActive(left, right, front, back);
}

EXPORT RGBA Vehicle_GetNeonColor(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   auto rgb = vehicle->GetNeonColor();

   RGBA rgba;
   rgba.r = rgb.r;
   rgba.g = rgb.g;
   rgba.b = rgb.b;
   rgba.a = rgb.a;

   return rgba;
}

EXPORT unsigned long Vehicle_GetLivery(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetLivery();
}

EXPORT unsigned long Vehicle_GetRoofLivery(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetRoofLivery();
}

EXPORT bool Vehicle_IsEngineOn(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsEngineOn();
}

EXPORT bool Vehicle_IsHandbrakeActive(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsHandbrakeActive();
}

EXPORT unsigned long Vehicle_GetHeadlightColor(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetHeadlightColor();
}

EXPORT unsigned long Vehicle_GetRadioStationIndex(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetRadioStationIndex();
}

EXPORT bool Vehicle_IsSirenActive(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsSirenActive();
}

EXPORT unsigned long Vehicle_GetLockState(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetLockState();
}

EXPORT unsigned long Vehicle_GetDoorState(void *v, unsigned long doorId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetDoorState(doorId);
}

EXPORT bool Vehicle_IsWindowOpened(void *v, unsigned long windowId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsWindowOpened(windowId);
}

EXPORT bool Vehicle_IsDaylightOn(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsDaylightOn();
}

EXPORT bool Vehicle_IsNightlightOn(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsNightlightOn();
}

EXPORT unsigned long Vehicle_GetRoofState(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetRoofState();
}

EXPORT bool Vehicle_IsFlamethrowerActive(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsFlamethrowerActive();
}

EXPORT float Vehicle_GetLightsMultiplier(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetLightsMultiplier();
}

EXPORT unsigned long Vehicle_GetEngineHealth(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetEngineHealth();
}

EXPORT unsigned long Vehicle_GetPetrolTankHealth(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetPetrolTankHealth();
}

EXPORT unsigned long Vehicle_GetWheelsCount(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetWheelsCount();
}

EXPORT bool Vehicle_IsWheelBurst(void *v, unsigned long wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsWheelBurst(wheelId);
}

EXPORT bool Vehicle_DoesWheelHasTire(void *v, unsigned long wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->DoesWheelHasTire(wheelId);
}

EXPORT bool Vehicle_IsWheelDetached(void *v, unsigned long wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsWheelDetached(wheelId);
}

EXPORT bool Vehicle_IsWheelOnFire(void *v, unsigned long wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsWheelOnFire(wheelId);
}

EXPORT float Vehicle_GetWHeelHealth(void *v, unsigned long wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetWHeelHealth(wheelId);
}

EXPORT unsigned long Vehicle_GetRepairsCount(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetRepairsCount();
}

EXPORT unsigned long Vehicle_GetBodyHealth(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetBodyHealth();
}

EXPORT unsigned long Vehicle_GetBodyAdditionalHealth(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetBodyAdditionalHealth();
}

EXPORT unsigned long Vehicle_GetPartDamageLevel(void *v, unsigned long partId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetPartDamageLevel(partId);
}

EXPORT unsigned long Vehicle_GetPartBulletHoles(void *v, unsigned long partId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetPartBulletHoles(partId);
}

EXPORT bool Vehicle_IsLightDamaged(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsLightDamaged();
}

EXPORT bool Vehicle_IsWindowDamaged(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsWindowDamaged();
}

EXPORT bool Vehicle_IsSpecialLightDamaged(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsSpecialLightDamaged();
}

EXPORT bool Vehicle_HasArmoredWindows(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->HasArmoredWindows();
}

EXPORT float Vehicle_GetArmoredWindowHealth(void *v, unsigned long windowId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetArmoredWindowHealth(windowId);
}

EXPORT unsigned long Vehicle_GetArmoredWindowShootCount(void *v, unsigned long windowId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetArmoredWindowShootCount(windowId);
}

EXPORT unsigned long Vehicle_GetBumperDamageLevel(void *v, unsigned long bumperId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetBumperDamageLevel(bumperId);
}

EXPORT bool Vehicle_IsManualEngineControl(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsManualEngineControl();
}

EXPORT void Vehicle_ToggleExtra(void *v, unsigned long extraID, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->ToggleExtra(extraID, state);
}

EXPORT void Vehicle_SetFixed(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetFixed();
}

EXPORT bool Vehicle_SetMod(void *v, unsigned long category, unsigned long id)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->SetMod(category, id);
}

EXPORT bool Vehicle_SetModKit(void *v, unsigned long id)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->SetModKit(id);
}

EXPORT void Vehicle_SetPrimaryColor(void *v, unsigned long color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPrimaryColor(color);
}

EXPORT void Vehicle_SetPrimaryColorRGB(void *v, unsigned long r, unsigned long g, unsigned long b, unsigned long a)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPrimaryColorRGB(r, g, b, a);
}

EXPORT void Vehicle_SetSecondaryColor(void *v, unsigned long color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetSecondaryColor(color);
}

EXPORT void Vehicle_SetSecondaryColorRGB(void *v, unsigned long r, unsigned long g, unsigned long b, unsigned long a)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetSecondaryColorRGB(r, g, b, a);
}

EXPORT void Vehicle_SetPearlColor(void *v, unsigned long color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPearlColor(color);
}

EXPORT void Vehicle_SetWheelColor(void *v, unsigned long color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelColor(color);
}

EXPORT void Vehicle_SetInteriorColor(void *v, unsigned long color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetInteriorColor(color);
}

EXPORT void Vehicle_SetDashboardColor(void *v, unsigned long color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetDashboardColor(color);
}

EXPORT void Vehicle_SetTireSmokeColor(void *v, unsigned long color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetTireSmokeColor(color);
}

EXPORT void Vehicle_SetWheels(void *v, unsigned long type, unsigned long variation)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheels(type, variation);
}

EXPORT void Vehicle_SetRearWheels(void *v, unsigned long variation)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetRearWheels(variation);
}

EXPORT void Vehicle_SetCustomTires(void *v, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetCustomTires(state);
}

EXPORT void Vehicle_SetSpecialDarkness(void *v, unsigned long value)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetSpecialDarkness(value);
}

EXPORT void Vehicle_SetNumberplateIndex(void *v, unsigned long index)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetNumberplateIndex(index);
}

EXPORT void Vehicle_SetNumberplateText(void *v, const char* text)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetNumberplateText(text);
}

EXPORT void Vehicle_SetWindowTint(void *v, unsigned long tint)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWindowTint(tint);
}

EXPORT void Vehicle_SetDirtLevel(void *v, unsigned long level)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetDirtLevel(level);
}

EXPORT void Vehicle_SetNeonActive(void *v, bool left, bool right, bool front, bool back)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetNeonActive(left, right, front, back);
}

EXPORT void Vehicle_SetNeonColor(void *v, unsigned long r, unsigned long g, unsigned long b, unsigned long a)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);

   alt::RGBA rgba;

   rgba.r = r;
   rgba.g = g;
   rgba.b = b;
   rgba.a = a;

   vehicle->SetNeonColor(rgba);
}

EXPORT void Vehicle_SetLivery(void *v, unsigned long livery)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetLivery(livery);
}

EXPORT void Vehicle_SetRoofLivery(void *v, unsigned long roofLivery)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetRoofLivery(roofLivery);
}

EXPORT void Vehicle_SetEngineOn(void *v, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetEngineOn(state);
}

EXPORT void Vehicle_SetHeadlightColor(void *v, unsigned long color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetHeadlightColor(color);
}

EXPORT void Vehicle_SetRadioStationIndex(void *v, unsigned long stationIndex)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetRadioStationIndex(stationIndex);
}

EXPORT void Vehicle_SetSirenActive(void *v, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetSirenActive(state);
}

EXPORT void Vehicle_SetLockState(void *v, unsigned long state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetLockState(state);
}

EXPORT void Vehicle_SetDoorState(void *v, unsigned long doorId, unsigned long state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetDoorState(doorId, state);
}

EXPORT void Vehicle_SetWindowOpened(void *v, unsigned long windowId, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWindowOpened(windowId, state);
}

EXPORT void Vehicle_SetRoofState(void *v, unsigned long state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetRoofState(state);
}

EXPORT void Vehicle_SetLightsMultiplier(void *v, float multiplier)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetLightsMultiplier(multiplier);
}

EXPORT void Vehicle_SetEngineHealth(void *v, unsigned long health)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetEngineHealth(health);
}

EXPORT void Vehicle_SetPetrolTankHealth(void *v, unsigned long health)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPetrolTankHealth(health);
}

EXPORT void Vehicle_SetWheelBurst(void *v, unsigned long wheelId, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelBurst(wheelId, state);
}

EXPORT void Vehicle_SetWheelHasTire(void *v, unsigned long wheelId, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelHasTire(wheelId, state);
}

EXPORT void Vehicle_SetWheelDetached(void *v, unsigned long wheelId, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelDetached(wheelId, state);
}

EXPORT void Vehicle_SetWheelOnFire(void *v, unsigned long wheelId, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelOnFire(wheelId, state);
}

EXPORT void Vehicle_SetWheelHealth(void *v, unsigned long wheelId, float health)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelHealth(wheelId, health);
}

EXPORT void Vehicle_SetWheelFixed(void *v, unsigned long wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelFixed(wheelId);
}

EXPORT void Vehicle_SetBodyHealth(void *v, unsigned long health)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetBodyHealth(health);
}

EXPORT void Vehicle_SetBodyAdditionalHealth(void *v, unsigned long health)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetBodyAdditionalHealth(health);
}

EXPORT void Vehicle_SetPartDamageLevel(void *v, unsigned long partId, unsigned long damage)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPartDamageLevel(partId, damage);
}

EXPORT void Vehicle_SetPartBulletHoles(void *v, unsigned long partId, unsigned long shootsCount)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPartBulletHoles(partId, shootsCount);
}

EXPORT void Vehicle_SetLightDamaged(void *v, unsigned long lightId, bool isDamaged)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetLightDamaged(lightId, isDamaged);
}

EXPORT void Vehicle_SetWindowDamaged(void *v, unsigned long windowId, bool isDamaged)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWindowDamaged(windowId, isDamaged);
}

EXPORT void Vehicle_SetSpecialLightDamaged(void *v, unsigned long specialLightId, bool isDamaged)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetSpecialLightDamaged(specialLightId, isDamaged);
}

EXPORT void Vehicle_SetArmoredWindowHealth(void *v, unsigned long windowId, float health)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetArmoredWindowHealth(windowId, health);
}

EXPORT void Vehicle_SetArmoredWindowShootCount(void *v, unsigned long windowId, unsigned long count)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetArmoredWindowShootCount(windowId, count);
}

EXPORT void Vehicle_SetBumperDamageLevel(void *v, unsigned long bumperId, unsigned long damageLevel)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetBumperDamageLevel(bumperId, damageLevel);
}

EXPORT void Vehicle_SetManualEngineControl(void *v, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetManualEngineControl(state);
}

EXPORT void * Vehicle_GetAttached(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetAttached().Get();
}

EXPORT void * Vehicle_GetAttachedTo(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetAttachedTo().Get();
}

