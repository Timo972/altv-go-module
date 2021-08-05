#include "GoRuntime.h"
#include "GoResource.h"

Go::Runtime* Go::Runtime::Instance = nullptr;

Go::Runtime* Go::Runtime::GetInstance() {
    if (Instance == nullptr) Instance = new Runtime();

    return Instance;
}

alt::IResource::Impl* Go::Runtime::CreateImpl(alt::IResource* impl) {
    auto resource = new Go::Resource(this, impl);
    _resources.push_back({{impl->GetName().CStr(), resource}});

    return resource;
}

void Go::Runtime::DestroyImpl(alt::IResource::Impl* impl) {
    auto resource = dynamic_cast<Go::Resource*>(impl);

    if(resource != nullptr) delete resource;
}


alt::IResource::Impl *Go::Runtime::GetResource(const std::string& name) {
    for (auto& resource : _resources) {
       if (resource.find(name) != resource.end()) {
           return resource[name];
       }
    }

    return nullptr;
}

