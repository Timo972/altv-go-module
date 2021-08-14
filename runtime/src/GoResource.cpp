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

    start();
    return true;
}

bool Go::Resource::Stop()
{
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

