#include "GoRuntime.h"
#include "GoResource.h"

Go::Runtime* Go::Runtime::Instance = nullptr;

Go::Runtime* Go::Runtime::GetInstance() {
    if (Instance == nullptr) Instance = new Runtime();

    return Instance;
}

alt::IResource::Impl* Go::Runtime::CreateImpl(alt::IResource* impl) {
    auto resource = new Go::Resource(this, impl);

    return resource;
}

void Go::Runtime::DestroyImpl(alt::IResource::Impl* impl) {
    auto resource = dynamic_cast<Go::Resource*>(impl);

    if(resource != nullptr) delete resource;
}

