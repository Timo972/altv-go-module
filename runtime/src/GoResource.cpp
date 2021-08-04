#include "GoResource.h"

Go::Resource::Resource(Go::Runtime* runtime, alt::IResource* resource) : _runtime(runtime), _resource(resource) { }

bool Go::Resource::Start() {
    Module = LOAD_LIB((_resource->GetPath().ToString() + SEPARATOR
            + _resource->GetMain().ToString()).c_str());
    if(Module == nullptr)
    {
        alt::ICore::Instance()
            .LogError("Failed to open main file");

        return false;
    }

    auto start = GET_FUNC(Module, "Start", void(*)());
    if(start == nullptr)
    {
        alt::ICore::Instance()
            .LogError("Main entrypoint not found");

        return false;
    }

    start();
    return true;
}

bool Go::Resource::Stop() {
    return true;
}

bool Go::Resource::OnEvent(const alt::CEvent* ev) {
    auto type = ev->GetType();

    if(!IsEventRegistered(type)) {
        return false;
    }

    NotifyEvent(ev, _resource->GetName().CStr(), Module);
    return true;
}

void Go::Resource::OnTick() { }


