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

   alt::Position pos;
   pos.x = x;
   pos.y = y;
   pos.z = z;

   vehicle->SetPosition(pos);
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

   alt::Rotation rot;
   rot.roll = roll;
   rot.pitch = pitch;
   rot.yaw = yaw;

   vehicle->SetRotation(rot);
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

EXPORT void Vehicle_Detach(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->Detach();
}

EXPORT void Vehicle_AttachToEntity(void *v, void *e, int otherBoneIndex, int myBoneIndex, Position pos, Rotation rot, bool collision, bool noFixedRotation)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   auto entity = reinterpret_cast<alt::IEntity*>(e);

   auto position = alt::Position(pos.x, pos.y, pos.z);
   auto rotation = alt::Rotation(rot.roll, rot.pitch, rot.yaw);

   vehicle->AttachToEntity(entity, otherBoneIndex, myBoneIndex, position, rotation, collision, noFixedRotation);
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

EXPORT void Vehicle_SetNetworkOwner(void *v, void *o, bool disableMigration)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   auto owner = reinterpret_cast<alt::IPlayer*>(o);
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

EXPORT unsigned long Vehicle_GetMod(void *v, unsigned int category)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetMod(category);
}

EXPORT unsigned long Vehicle_GetModsCount(void *v, unsigned int category)
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

EXPORT bool Vehicle_IsExtraOn(void *v, unsigned int extraID)
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

EXPORT unsigned long Vehicle_GetDoorState(void *v, unsigned int doorId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetDoorState(doorId);
}

EXPORT bool Vehicle_IsWindowOpened(void *v, unsigned int windowId)
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

EXPORT bool Vehicle_IsWheelBurst(void *v, unsigned int wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsWheelBurst(wheelId);
}

EXPORT bool Vehicle_DoesWheelHasTire(void *v, unsigned int wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->DoesWheelHasTire(wheelId);
}

EXPORT bool Vehicle_IsWheelDetached(void *v, unsigned int wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsWheelDetached(wheelId);
}

EXPORT bool Vehicle_IsWheelOnFire(void *v, unsigned int wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsWheelOnFire(wheelId);
}

EXPORT float Vehicle_GetWheelHealth(void *v, unsigned int wheelId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetWheelHealth(wheelId);
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

EXPORT unsigned long Vehicle_GetPartDamageLevel(void *v, unsigned int partId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetPartDamageLevel(partId);
}

EXPORT unsigned long Vehicle_GetPartBulletHoles(void *v, unsigned int partId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetPartBulletHoles(partId);
}

EXPORT bool Vehicle_IsLightDamaged(void *v, unsigned int lightId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsLightDamaged(lightId);
}

EXPORT bool Vehicle_IsWindowDamaged(void *v, unsigned int windowId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsWindowDamaged(windowId);
}

EXPORT bool Vehicle_IsSpecialLightDamaged(void *v, unsigned int specialLightId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsSpecialLightDamaged(specialLightId);
}

EXPORT bool Vehicle_HasArmoredWindows(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->HasArmoredWindows();
}

EXPORT float Vehicle_GetArmoredWindowHealth(void *v, unsigned int windowId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetArmoredWindowHealth(windowId);
}

EXPORT unsigned long Vehicle_GetArmoredWindowShootCount(void *v, unsigned int windowId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetArmoredWindowShootCount(windowId);
}

EXPORT unsigned long Vehicle_GetBumperDamageLevel(void *v, unsigned int bumperId)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->GetBumperDamageLevel(bumperId);
}

EXPORT bool Vehicle_IsManualEngineControl(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->IsManualEngineControl();
}

EXPORT void Vehicle_ToggleExtra(void *v, unsigned int extraID, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->ToggleExtra(extraID, state);
}

EXPORT void Vehicle_SetFixed(void *v)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetFixed();
}

EXPORT bool Vehicle_SetMod(void *v, unsigned int category, unsigned int id)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->SetMod(category, id);
}

EXPORT bool Vehicle_SetModKit(void *v, unsigned int id)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   return vehicle->SetModKit(id);
}

EXPORT void Vehicle_SetPrimaryColor(void *v, unsigned int color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPrimaryColor(color);
}

EXPORT void Vehicle_SetPrimaryColorRGB(void *v, unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);

   alt::RGBA rgba;

   rgba.r = r;
   rgba.g = g;
   rgba.b = b;
   rgba.a = a;

   vehicle->SetPrimaryColorRGB(rgba);
}

EXPORT void Vehicle_SetSecondaryColor(void *v, unsigned int color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetSecondaryColor(color);
}

EXPORT void Vehicle_SetSecondaryColorRGB(void *v, unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);

   alt::RGBA rgba;

   rgba.r = r;
   rgba.g = g;
   rgba.b = b;
   rgba.a = a;

   vehicle->SetSecondaryColorRGB(rgba);
}

EXPORT void Vehicle_SetPearlColor(void *v, unsigned int color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPearlColor(color);
}

EXPORT void Vehicle_SetWheelColor(void *v, unsigned int color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelColor(color);
}

EXPORT void Vehicle_SetInteriorColor(void *v, unsigned int color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetInteriorColor(color);
}

EXPORT void Vehicle_SetDashboardColor(void *v, unsigned int color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetDashboardColor(color);
}

EXPORT void Vehicle_SetTireSmokeColor(void *v, unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);

   alt::RGBA rgba;

   rgba.r = r;
   rgba.g = g;
   rgba.b = b;
   rgba.a = a;

   vehicle->SetTireSmokeColor(rgba);
}

EXPORT void Vehicle_SetWheels(void *v, unsigned int type, unsigned int variation)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheels(type, variation);
}

EXPORT void Vehicle_SetRearWheels(void *v, unsigned int variation)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetRearWheels(variation);
}

EXPORT void Vehicle_SetCustomTires(void *v, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetCustomTires(state);
}

EXPORT void Vehicle_SetSpecialDarkness(void *v, unsigned int value)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetSpecialDarkness(value);
}

EXPORT void Vehicle_SetNumberplateIndex(void *v, unsigned int index)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetNumberplateIndex(index);
}

EXPORT void Vehicle_SetNumberplateText(void *v, const char* text)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetNumberplateText(text);
}

EXPORT void Vehicle_SetWindowTint(void *v, unsigned int tint)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWindowTint(tint);
}

EXPORT void Vehicle_SetDirtLevel(void *v, unsigned int level)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetDirtLevel(level);
}

EXPORT void Vehicle_SetNeonActive(void *v, bool left, bool right, bool front, bool back)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetNeonActive(left, right, front, back);
}

EXPORT void Vehicle_SetNeonColor(void *v, unsigned int r, unsigned int g, unsigned int b, unsigned int a)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);

   alt::RGBA rgba;

   rgba.r = r;
   rgba.g = g;
   rgba.b = b;
   rgba.a = a;

   vehicle->SetNeonColor(rgba);
}

EXPORT void Vehicle_SetLivery(void *v, unsigned int livery)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetLivery(livery);
}

EXPORT void Vehicle_SetRoofLivery(void *v, unsigned int roofLivery)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetRoofLivery(roofLivery);
}

EXPORT void Vehicle_SetEngineOn(void *v, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetEngineOn(state);
}

EXPORT void Vehicle_SetHeadlightColor(void *v, unsigned int color)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetHeadlightColor(color);
}

EXPORT void Vehicle_SetRadioStationIndex(void *v, unsigned int stationIndex)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetRadioStationIndex(stationIndex);
}

EXPORT void Vehicle_SetSirenActive(void *v, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetSirenActive(state);
}

EXPORT void Vehicle_SetLockState(void *v, unsigned int state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetLockState(state);
}

EXPORT void Vehicle_SetDoorState(void *v, unsigned int doorId, unsigned int state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetDoorState(doorId, state);
}

EXPORT void Vehicle_SetWindowOpened(void *v, unsigned int windowId, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWindowOpened(windowId, state);
}

EXPORT void Vehicle_SetRoofState(void *v, unsigned int state)
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

EXPORT void Vehicle_SetWheelBurst(void *v, unsigned int wheelId, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelBurst(wheelId, state);
}

EXPORT void Vehicle_SetWheelHasTire(void *v, unsigned int wheelId, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelHasTire(wheelId, state);
}

EXPORT void Vehicle_SetWheelDetached(void *v, unsigned int wheelId, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelDetached(wheelId, state);
}

EXPORT void Vehicle_SetWheelOnFire(void *v, unsigned int wheelId, bool state)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelOnFire(wheelId, state);
}

EXPORT void Vehicle_SetWheelHealth(void *v, unsigned int wheelId, float health)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWheelHealth(wheelId, health);
}

EXPORT void Vehicle_SetWheelFixed(void *v, unsigned int wheelId)
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

EXPORT void Vehicle_SetPartDamageLevel(void *v, unsigned int partId, unsigned int damage)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPartDamageLevel(partId, damage);
}

EXPORT void Vehicle_SetPartBulletHoles(void *v, unsigned int partId, unsigned int shootsCount)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetPartBulletHoles(partId, shootsCount);
}

EXPORT void Vehicle_SetLightDamaged(void *v, unsigned int lightId, bool isDamaged)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetLightDamaged(lightId, isDamaged);
}

EXPORT void Vehicle_SetWindowDamaged(void *v, unsigned int windowId, bool isDamaged)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetWindowDamaged(windowId, isDamaged);
}

EXPORT void Vehicle_SetSpecialLightDamaged(void *v, unsigned int specialLightId, bool isDamaged)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetSpecialLightDamaged(specialLightId, isDamaged);
}

EXPORT void Vehicle_SetArmoredWindowHealth(void *v, unsigned int windowId, float health)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetArmoredWindowHealth(windowId, health);
}

EXPORT void Vehicle_SetArmoredWindowShootCount(void *v, unsigned int windowId, unsigned int count)
{
   auto vehicle = reinterpret_cast<alt::IVehicle*>(v);
   vehicle->SetArmoredWindowShootCount(windowId, count);
}

EXPORT void Vehicle_SetBumperDamageLevel(void *v, unsigned int bumperId, unsigned int damageLevel)
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
