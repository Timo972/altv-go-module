#include "GoResource.h"

#ifndef IS_UNIX
#include "windows.h"
#define LOAD_LIB(path) LoadLibrary(path)
#define GET_FUNC(module, name, type) (type)GetProcAddress(module, name);
#else
#include <dlfcn.h>
#define LOAD_LIBRARY(name) dlopen(name, RTLD_NOW);
#define GET_FUNC(module, name, type) (type)dlsym(module, name);
#endif

Go::Resource::Resource(Go::Runtime* runtime, alt::IResource* resource) : _runtime(runtime), _resource(resource) { }

bool Go::Resource::Start() {
    auto module = LOAD_LIB((_resource->GetPath().ToString() + SEPARATOR
            + _resource->GetMain().ToString()).c_str());
    if(module == nullptr)
    {
        alt::ICore::Instance()
            .LogError("Failed to open main file");

        return false;
    }

    auto main = GET_FUNC(module, "start", void(*)());
    if(main == nullptr)
    {
        alt::ICore::Instance()
            .LogError("Main entrypoint not found");

        return false;
    }

    main();
    return true;
}

bool Go::Resource::Stop() {
    return true;
}

bool Go::Resource::OnEvent(const alt::CEvent* ev) {
    return true;
}

void Go::Resource::OnTick() { }


