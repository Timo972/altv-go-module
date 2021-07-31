#include "GoRuntime.h"
#include "GoResource.h"

Go::Runtime* Go::Runtime::Instance = nullptr;

Go::Runtime *Go::Runtime::GetInstance() {
    if (Instance == nullptr) Instance = new Runtime();

    return Instance;
}

alt::IResource::Impl *Go::Runtime::CreateImpl(alt::IResource *resource) {
    return new Go::Resource(this, resource);
}

// Not implemented
void Go::Runtime::DestroyImpl(alt::IResource::Impl *impl) { }
