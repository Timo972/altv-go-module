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

    auto resourceName = _resource->GetName().CStr();
    auto resourcePath = _resource->GetPath().CStr();
    auto resourcePtr = _resource;

    auto go = GET_FUNC(Module, "initGoResource", void(*)(alt::IResource* resourcePtr,
            const char* resourceName, const char* ResourcePath));
    if(go == nullptr) {
        alt::ICore::Instance()
            .LogError("Error while initializing Go Resource");

        return false;
    }

    go(resourcePtr, resourceName, resourcePath);

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


