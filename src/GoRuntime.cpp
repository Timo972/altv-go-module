#include "GoRuntime.h"
#include "GoResource.h"

GoRuntime* GoRuntime::Instance = nullptr;

GoRuntime *GoRuntime::GetInstance() {
    if (Instance == nullptr) Instance = new GoRuntime();

    return Instance;
}

alt::IResource::Impl *GoRuntime::CreateImpl(alt::IResource *resource) {
    return new GoResource(this, resource);
}

// Not implemented
void GoRuntime::DestroyImpl(alt::IResource::Impl *impl) { }
