#pragma once

#include <iostream>
#include <algorithm>
#include <set>
#include "Main.h"
#include "GoEventState.h"

#include "./events/PlayerConnectEvent.h"

namespace Go {
    class EventsManager {
    private:
        std::vector<alt::CEvent::Type> _registeredEvents;
        Go::EventContext *_eventContext;
    public:
        EventsManager();
        bool RegisterEvent(alt::CEvent::Type type);
        bool UnregisterEvent(alt::CEvent::Type type);
        bool IsEventRegistered(alt::CEvent::Type type);
        void NotifyEvent(const alt::CEvent* ev);
    };
}
