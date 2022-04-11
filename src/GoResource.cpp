#include "GoResource.h"

Go::Resource::Resource(Go::Runtime *runtime, alt::IResource *resource) : _runtime(runtime), _resource(resource) {}

bool Go::Resource::Start()
{
    Module = LOAD_LIB((_resource->GetPath().ToString() + SEPARATOR + _resource->GetMain().ToString()).c_str());
    if (Module == nullptr)
    {
        alt::ICore::Instance()
            .LogError("Failed to open main file");

        return false;
    }

    auto resourceName = _resource->GetName().CStr();
    auto resourcePath = _resource->GetPath().CStr();
    auto go = GET_FUNC(Module, "initGoResource", void (*)(alt::IResource * resourcePtr, const char *resourceName, const char *ResourcePath));
    if (go == nullptr)
    {
        alt::ICore::Instance()
            .LogError("Error while initializing Go Resource");

        return false;
    }

    go(_resource, resourceName, resourcePath);


    auto start = GET_FUNC(Module, "OnStart", void (*)());
    if (start == nullptr)
    {
        alt::ICore::Instance().LogError("Main entrypoint not found");
        return false;
    }

    RegisterEventHandler(Go::EventType::PLAYER_CONNECT, new PlayerConnectEvent(Module));
    RegisterEventHandler(Go::EventType::PLAYER_DISCONNECT, new PlayerDisconnectEvent(Module));
    RegisterEventHandler(Go::EventType::PLAYER_DAMAGE, new PlayerDamageEvent(Module));
    RegisterEventHandler(Go::EventType::PLAYER_DEATH, new PlayerDeathEvent(Module));
    RegisterEventHandler(Go::EventType::PLAYER_ENTER_VEHICLE, new PlayerEnterVehicleEvent(Module));
    RegisterEventHandler(Go::EventType::PLAYER_LEAVE_VEHICLE, new PlayerLeaveVehicleEvent(Module));
    RegisterEventHandler(Go::EventType::PLAYER_CHANGE_VEHICLE_SEAT, new PlayerChangeVehicleSeatEvent(Module));
    RegisterEventHandler(Go::EventType::REMOVE_ENTITY_EVENT, new RemoveEntityEvent(Module));
    RegisterEventHandler(Go::EventType::CONSOLE_COMMAND_EVENT, new ConsoleCommandEvent(Module));
    RegisterEventHandler(Go::EventType::WEAPON_DAMAGE_EVENT, new WeaponDamageEvent(Module));
    RegisterEventHandler(Go::EventType::EXPLOSION_EVENT, new ExplosionEvent(Module));
    RegisterEventHandler(Go::EventType::RESOURCE_START, new ResourceStartEvent(Module));
    RegisterEventHandler(Go::EventType::COLSHAPE_EVENT, new ColShapeEvent(Module));
    RegisterEventHandler(Go::EventType::FIRE_EVENT, new FireEvent(Module));
    RegisterEventHandler(Go::EventType::SYNCED_META_CHANGE, new SyncedMetaDataChangeEvent(Module));
    RegisterEventHandler(Go::EventType::STREAM_SYNCED_META_CHANGE, new StreamSyncedMetaDataChangeEvent(Module));
    RegisterEventHandler(Go::EventType::GLOBAL_META_CHANGE, new GlobalMetaDataChangeEvent(Module));
    RegisterEventHandler(Go::EventType::GLOBAL_SYNCED_META_CHANGE, new GlobalSyncedMetaDataChangeEvent(Module));
    RegisterEventHandler(Go::EventType::RESOURCE_STOP, new ResourceStopEvent(Module));
    RegisterEventHandler(Go::EventType::RESOURCE_ERROR, new ResourceErrorEvent(Module));
    RegisterEventHandler(Go::EventType::VEHICLE_DESTROY, new VehicleDestroyEvent(Module));
    RegisterEventHandler(Go::EventType::START_PROJECTILE_EVENT, new StartProjectileEvent(Module));
    RegisterEventHandler(Go::EventType::PLAYER_WEAPON_CHANGE, new PlayerWeaponChangeEvent(Module));
    RegisterEventHandler(Go::EventType::VEHICLE_ATTACH, new VehicleAttachEvent(Module));
    RegisterEventHandler(Go::EventType::VEHICLE_DETACH, new VehicleDetachEvent(Module));
    RegisterEventHandler(Go::EventType::NETOWNER_CHANGE, new NetOwnerChangeEvent(Module));
    RegisterEventHandler(Go::EventType::PLAYER_ENTERING_VEHICLE, new PlayerEnteringVehicleEvent(Module));
    RegisterEventHandler(Go::EventType::SERVER_SCRIPT_EVENT, new ServerScriptEvent(Module));
    RegisterEventHandler(Go::EventType::CLIENT_SCRIPT_EVENT, new ClientScriptEvent(Module));
    RegisterEventHandler(Go::EventType::VEHICLE_DAMAGE, new VehicleDamageEvent(Module));

    start();

    _resource->SetExports(_registeredExports);

    return true;
}

bool Go::Resource::Stop()
{
    auto stop = GET_FUNC(Module, "OnStop", void (*)());
    if (stop == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't call OnStop.");
        return false;
    }

    stop();
    return true;
}

bool Go::Resource::OnEvent(const alt::CEvent *ev)
{
    auto type = ev->GetType();

    if (!IsEventRegistered(type))
    {
        return false;
    }

    NotifyEvent(ev, _resource->GetName().CStr());
    return true;
}

void Go::Resource::OnTick() {}
