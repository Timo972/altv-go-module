#include "GoRuntime.h"
#include "GoResource.h"

Go::Runtime *Go::Runtime::Instance = nullptr;

Go::Runtime *Go::Runtime::GetInstance() {
    if (Instance == nullptr)
        Instance = new Runtime();

    return Instance;
}

alt::IResource::Impl *Go::Runtime::CreateImpl(alt::IResource *impl) {
    auto resource = new Go::Resource(this, impl);
    _resources.push_back({{impl->GetName().CStr(), resource}});

    return resource;
}

void Go::Runtime::DestroyImpl(alt::IResource::Impl *impl) {
    auto resource = dynamic_cast<Go::Resource *>(impl);

    if (resource != nullptr)
        delete resource;
}

alt::IResource::Impl *Go::Runtime::GetResource(const std::string &name) {
    for (auto &resource : _resources) {
        if (resource.find(name) != resource.end()) {
            return resource[name];
        }
    }

    return nullptr;
}

alt::MValueArgs Go::Runtime::CreateMValueArgs(CustomData *MValues, unsigned long long size) {
    alt::MValueArgs args;

    for (unsigned long long i = 0; i < size; ++i) {
        switch (static_cast<alt::IMValue::Type>(MValues[i].Type)) {
            case alt::IMValue::Type::STRING:
                args.Push(reinterpret_cast<alt::IMValueString *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::INT:
                args.Push(reinterpret_cast<alt::IMValueInt *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::UINT:
                args.Push(reinterpret_cast<alt::IMValueUInt *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::DOUBLE:
                args.Push(reinterpret_cast<alt::IMValueDouble *>(MValues[i].mValue));
                break;
            case alt::IMValue::Type::BOOL:
                args.Push(reinterpret_cast<alt::IMValueBool *>(MValues[i].mValue));
                break;
        }
    }

    return args;
}