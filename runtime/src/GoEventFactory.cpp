#include "GoEventFactory.h"

void Go::EventFactory::CallEvent(const alt::CEvent *ev, ModuleLibrary *module) {
    auto event = EventsMap.find(static_cast<const unsigned short>(ev->GetType()));

    if(event == EventsMap.end())
    {
        return;
    }

    event->second->Call(ev, module);
}

void Go::EventFactory::RegisterEventHandler(uint16_t type, Go::IEvent *handler) {
    EventsMap.insert({{type, handler}});
}
