#pragma once

#include <iostream>

#include "Main.h"
#include "Library.h"

namespace Go {
    enum class EventType : uint16_t
    {
        NONE,
        // Shared
        PLAYER_CONNECT,
        PLAYER_DISCONNECT,
        RESOURCE_START,
        RESOURCE_STOP,
        RESOURCE_ERROR,
        SERVER_SCRIPT_EVENT,
        CLIENT_SCRIPT_EVENT,
        META_CHANGE,
        SYNCED_META_CHANGE,
        STREAM_SYNCED_META_CHANGE,
        GLOBAL_META_CHANGE,
        GLOBAL_SYNCED_META_CHANGE,
        PLAYER_DAMAGE,
        PLAYER_DEATH,
        FIRE_EVENT,
        EXPLOSION_EVENT,
        START_PROJECTILE_EVENT,
        WEAPON_DAMAGE_EVENT,
        VEHICLE_DESTROY,
        VEHICLE_DAMAGE,
        CHECKPOINT_EVENT,
        COLSHAPE_EVENT,
        PLAYER_ENTER_VEHICLE,
        PLAYER_ENTERING_VEHICLE,
        PLAYER_LEAVE_VEHICLE,
        PLAYER_CHANGE_VEHICLE_SEAT,
        PLAYER_WEAPON_CHANGE,
        VEHICLE_ATTACH,
        VEHICLE_DETACH,
        NETOWNER_CHANGE,
        REMOVE_ENTITY_EVENT,
        CREATE_BASE_OBJECT_EVENT,
        REMOVE_BASE_OBJECT_EVENT,
        DATA_NODE_RECEIVED_EVENT,
        CONSOLE_COMMAND_EVENT,
        // Client
        CONNECTION_COMPLETE,
        DISCONNECT_EVENT,
        WEB_VIEW_EVENT,
        KEYBOARD_EVENT,
        GAME_ENTITY_CREATE,
        GAME_ENTITY_DESTROY,
        RENDER,
        WEB_SOCKET_CLIENT_EVENT,
        AUDIO_EVENT,
        TASK_CHANGE,
        ALL,
        SIZE
    };

    class IEvent {
    public:
        explicit IEvent(ModuleLibrary *module);
        virtual void Call(const alt::CEvent *ev) = 0;
    protected:
        ModuleLibrary *Library;
    };

    class EventFactory {
    private:
        std::unordered_map<Go::EventType, IEvent*> EventsMap;
    public:
        void RegisterEventHandler(Go::EventType type, IEvent *handler);
        void CallEvent(const alt::CEvent *ev);
    };
}