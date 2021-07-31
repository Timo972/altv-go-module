#include "GoResource.h"

#ifndef IS_UNIX
#include "windows.h"
#define _getlib(name) LoadLibraryA(name)
#define _getfunc(module, name, type) (type)GetProcAddress(module, name);
#define _seperator "\\"
#else
#include <dlfcn.h>
#define _getlib(name) dlopen(name, RTLD_NOW);
#define _getfunc(module, name, type) (type)dlsym(module, name);
#define _seperator "/"
#endif

bool GoResource::Start() {
    // logic
    auto module = _getlib((_resource->GetPath().ToString() + _seperator + _resource->GetMain().ToString()).c_str() );
    if(module == nullptr)
    {
        alt::ICore::Instance().LogError("Failed to open main file");
        return false;
    }

    auto main = _getfunc(module, "start", void(*)());
    if(main == nullptr)
    {
        alt::ICore::Instance().LogError("Main entrypoint not found");
        return false;
    }

    main();
    return true;
}

bool GoResource::Stop() {
    // logic
    return true;
}
