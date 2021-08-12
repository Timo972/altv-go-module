#pragma once

#include <iostream>

#include "Main.h"
#include "Library.h"

namespace Go {
    class IEvent {
    public:
        virtual void Call(const alt::CEvent *ev, ModuleLibrary *module) = 0;
    };

    class EventFactory {
    private:
        std::unordered_map<uint16_t, IEvent*> EventsMap;
    public:
        void RegisterEventHandler(uint16_t type, IEvent *handler);
        void CallEvent(const alt::CEvent *ev, ModuleLibrary *module);
    };
}