#include <sstream>
#include "Runtime.h"

EXPORT int RegisterAltEvent(const char *resourceName, unsigned short eventType) {
    auto resource = dynamic_cast<Go::Resource *>(Go::Runtime::GetInstance()->GetResource(resourceName));
    if (resource == nullptr) {
        return false;
    }

    resource->RegisterEvent(static_cast<alt::CEvent::Type>(eventType));
    return true;
}

EXPORT int UnregisterAltEvent(const char *resourceName, unsigned short eventType) {
    auto resource = dynamic_cast<Go::Resource *>(Go::Runtime::GetInstance()->GetResource(resourceName));
    if (resource == nullptr) {
        return false;
    }

    resource->UnregisterEvent(static_cast<alt::CEvent::Type>(eventType));
    return true;
}

EXPORT int RegisterAltExport(const char *resourceName, const char *exportName, CustomData data) {
    auto resource = dynamic_cast<Go::Resource *>(Go::Runtime::GetInstance()->GetResource(resourceName));
    if (resource == nullptr) {
        return 0;
    }

    if (resource->IsExportSet(exportName)) {
        return 0;
    }

    auto mValue = reinterpret_cast<alt::IMValue *>(data.mValue);

    resource->AddExport(exportName, mValue);

    return 1;
}

EXPORT void *CreateMValueFunction(const char *resourceName, unsigned long long id) {
    auto resource = dynamic_cast<Go::Resource *>(Go::Runtime::GetInstance()->GetResource(resourceName));
    if (resource == nullptr) {
        return 0;
    }

    auto func = new Go::Function(resource->Module, id);
    auto mValueFunc = alt::ICore::Instance().CreateMValueFunction(func);
    auto defaultMVal = mValueFunc.As<alt::IMValue>();
    defaultMVal->AddRef();

    return defaultMVal.Get();
}

EXPORT MetaData CallMValueFunction(void *ptr, CustomData *mValues, unsigned long long mValueSize) {
    MetaData data;

    auto mValRef = reinterpret_cast<alt::IMValue *>(ptr);
    auto func = dynamic_cast<alt::IMValueFunction *>(mValRef);

    alt::MValueArgs args;
    if (mValueSize > 0) {
        args = Go::Runtime::GetInstance()->CreateMValueArgs(mValues, mValueSize);
    }

    auto retVal = func->Call(args);

    retVal->AddRef();
    data.Ptr = retVal.Get();
    data.Type = static_cast<unsigned int>(retVal->GetType());

    return data;
}

EXPORT MetaData

GetAltExport(const char *targetResourceName, const char *exportName) {
    auto targetResource = alt::ICore::Instance().GetResource(targetResourceName);

    if (targetResource == nullptr) {
        std::stringstream ss;
        ss << "Failed to get export: " << exportName << " of resource: " << targetResourceName
           << ". Resource does not exist!";
        alt::ICore::Instance().LogError(ss.str());
        MetaData data;
        data.Ptr = nullptr;
        data.Type = static_cast<unsigned int>(alt::IMValue::Type::NONE);
        return data;
    }

    alt::MValueDict exports = targetResource->GetExports();

    if (exports.IsEmpty()) {
        std::stringstream ss;
        ss << "Failed to get export: " << exportName << " of resource: " << targetResourceName
           << ". Did you forgot to specify dependencies?";
        alt::ICore::Instance().LogError(ss.str());
        MetaData data;
        data.Ptr = nullptr;
        data.Type = static_cast<unsigned int>(alt::IMValue::Type::NONE);
        return data;
    }

    alt::MValue exportMVal = exports->Get(exportName);

    MetaData data;
    data.Ptr = exportMVal.Get();
    data.Type = static_cast<unsigned int>(exportMVal->GetType());

    return data;
}