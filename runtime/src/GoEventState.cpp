#include "GoEventState.h"

Go::EventContext::EventContext() : _state(nullptr) { }

Go::EventContext::~EventContext() {
    delete _state;
}

void Go::EventContext::SetState(IEventState* const s) {
    if(_state) {
        delete _state;
    }

    _state = s;
}

void Go::EventContext::Request(const alt::CEvent* ev,  const std::string& resourceName, ModuleLibrary* module) {
    _state->Call(ev, resourceName, module);
}

