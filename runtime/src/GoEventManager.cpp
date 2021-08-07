#include "GoEventManager.h"

Go::EventsManager::EventsManager() : _eventContext(new Go::EventContext) {}

bool Go::EventsManager::RegisterEvent(alt::CEvent::Type type)
{
    _registeredEvents.push_back(type);
    return true;
}

bool Go::EventsManager::UnregisterEvent(alt::CEvent::Type type)
{
    auto i = std::find(_registeredEvents.begin(), _registeredEvents.end(), type);

    if (i == _registeredEvents.end())
        return false;

    _registeredEvents.erase(i);
    return true;
}

bool Go::EventsManager::IsEventRegistered(alt::CEvent::Type type)
{
    return std::find(_registeredEvents.begin(), _registeredEvents.end(), type) != _registeredEvents.end();
}

void Go::EventsManager::NotifyEvent(const alt::CEvent *ev, const std::string &resourceName, ModuleLibrary *module)
{
    auto type = ev->GetType();

    switch (type)
    {
    case alt::CEvent::Type::NONE:
        break;
    case alt::CEvent::Type::PLAYER_CONNECT:
        _eventContext->SetState(new Go::PlayerConnectEvent());
        break;
    case alt::CEvent::Type::PLAYER_DISCONNECT:
        break;
    case alt::CEvent::Type::RESOURCE_START:
        break;
    case alt::CEvent::Type::RESOURCE_STOP:
        break;
    case alt::CEvent::Type::RESOURCE_ERROR:
        break;
    case alt::CEvent::Type::SERVER_SCRIPT_EVENT:
        break;
    case alt::CEvent::Type::CLIENT_SCRIPT_EVENT:
        break;
    case alt::CEvent::Type::META_CHANGE:
        break;
    case alt::CEvent::Type::SYNCED_META_CHANGE:
        break;
    case alt::CEvent::Type::STREAM_SYNCED_META_CHANGE:
        break;
    case alt::CEvent::Type::GLOBAL_META_CHANGE:
        break;
    case alt::CEvent::Type::GLOBAL_SYNCED_META_CHANGE:
        break;
    case alt::CEvent::Type::PLAYER_DAMAGE:
        break;
    case alt::CEvent::Type::PLAYER_DEATH:
        break;
    case alt::CEvent::Type::FIRE_EVENT:
        break;
    case alt::CEvent::Type::EXPLOSION_EVENT:
        break;
    case alt::CEvent::Type::START_PROJECTILE_EVENT:
        break;
    case alt::CEvent::Type::WEAPON_DAMAGE_EVENT:
        break;
    case alt::CEvent::Type::VEHICLE_DESTROY:
        break;
    case alt::CEvent::Type::CHECKPOINT_EVENT:
        break;
    case alt::CEvent::Type::COLSHAPE_EVENT:
        break;
    case alt::CEvent::Type::PLAYER_ENTER_VEHICLE:
        break;
    case alt::CEvent::Type::PLAYER_ENTERING_VEHICLE:
        break;
    case alt::CEvent::Type::PLAYER_LEAVE_VEHICLE:
        break;
    case alt::CEvent::Type::PLAYER_CHANGE_VEHICLE_SEAT:
        break;
    case alt::CEvent::Type::PLAYER_WEAPON_CHANGE:
        break;
    case alt::CEvent::Type::VEHICLE_ATTACH:
        break;
    case alt::CEvent::Type::VEHICLE_DETACH:
        break;
    case alt::CEvent::Type::NETOWNER_CHANGE:
        break;
    case alt::CEvent::Type::REMOVE_ENTITY_EVENT:
        break;
    case alt::CEvent::Type::CREATE_BASE_OBJECT_EVENT:
        break;
    case alt::CEvent::Type::REMOVE_BASE_OBJECT_EVENT:
        break;
    case alt::CEvent::Type::DATA_NODE_RECEIVED_EVENT:
        break;
    case alt::CEvent::Type::CONSOLE_COMMAND_EVENT:
        break;
    case alt::CEvent::Type::CONNECTION_COMPLETE:
        break;
    case alt::CEvent::Type::DISCONNECT_EVENT:
        break;
    case alt::CEvent::Type::WEB_VIEW_EVENT:
        break;
    case alt::CEvent::Type::KEYBOARD_EVENT:
        break;
    case alt::CEvent::Type::GAME_ENTITY_CREATE:
        break;
    case alt::CEvent::Type::GAME_ENTITY_DESTROY:
        break;
    case alt::CEvent::Type::RENDER:
        break;
    case alt::CEvent::Type::WEB_SOCKET_CLIENT_EVENT:
        break;
    case alt::CEvent::Type::AUDIO_EVENT:
        break;
    case alt::CEvent::Type::ALL:
        break;
    case alt::CEvent::Type::SIZE:
        break;
    }

    _eventContext->Request(ev, resourceName, module);
}
