#include <sstream>
#include "Runtime.h"

EXPORT int Runtime_RegisterAltEvent(const char *resourceName, unsigned short eventType) {
    auto resource = dynamic_cast<Go::Resource *>(Go::Runtime::GetInstance()->GetResource(resourceName));
    if (resource == nullptr) {
        return false;
    }

    resource->RegisterEvent(static_cast<alt::CEvent::Type>(eventType));
    return true;
}

EXPORT int Runtime_UnregisterAltEvent(const char *resourceName, unsigned short eventType) {
    auto resource = dynamic_cast<Go::Resource *>(Go::Runtime::GetInstance()->GetResource(resourceName));
    if (resource == nullptr) {
        return false;
    }

    resource->UnregisterEvent(static_cast<alt::CEvent::Type>(eventType));
    return true;
}

EXPORT int Runtime_RegisterAltExport(const char *resourceName, const char *exportName, unsigned char *data, unsigned long long size) {
    auto resource = dynamic_cast<Go::Resource *>(Go::Runtime::GetInstance()->GetResource(resourceName));
    if (resource == nullptr) {
        return 0;
    }

    if (resource->IsExportSet(exportName)) {
        return 0;
    }

    auto mValue = Go::Runtime::ProtoToMValue(data, size);

    resource->AddExport(exportName, mValue);

    return 1;
}

EXPORT void *Runtime_CreateMValueFunction(const char *resourceName, unsigned long long id) {
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

EXPORT Array Runtime_CallMValueFunction(void *ptr, Array data) {
    auto mValRef = reinterpret_cast<alt::IMValue *>(ptr);
    auto func = dynamic_cast<alt::IMValueFunction *>(mValRef);

    auto args = Go::Runtime::ProtoToMValueArgs(data);
    alt::MValue retValue = func->Call(args);

    auto bytes = Go::Runtime::MValueToProtoBytes(retValue);
    return bytes;
}

EXPORT Array Runtime_GetAltExport(const char *targetResourceName, const char *exportName) {
    auto targetResource = alt::ICore::Instance().GetResource(targetResourceName);

    if (targetResource == nullptr) {
        std::stringstream ss;
        ss << "Failed to get export: " << exportName << " of resource: " << targetResourceName
           << ". Resource does not exist!";
        alt::ICore::Instance().LogError(ss.str());
        
        alt::MValue none = alt::ICore::Instance().CreateMValueNone();
        auto data = Go::Runtime::MValueToProtoBytes(none);
        return data;
    }

    alt::MValueDict exports = targetResource->GetExports();

    if (exports.IsEmpty()) {
        std::stringstream ss;
        ss << "Failed to get export: " << exportName << " of resource: " << targetResourceName
           << ". Did you forgot to specify dependencies?";
        alt::ICore::Instance().LogError(ss.str());
        alt::MValue none = alt::ICore::Instance().CreateMValueNone();
        auto data = Go::Runtime::MValueToProtoBytes(none);
        return data;
    }

    alt::MValue exportMVal = exports->Get(exportName);

    auto data = Go::Runtime::MValueToProtoBytes(exportMVal);
    return data;
}

EXPORT void Connection_Accept(void* handle) {
    auto conn = reinterpret_cast<alt::IConnectionInfo*>(handle);
    conn->Accept();
}

EXPORT void Connection_Decline(void* handle, const char* reason) {
    auto conn = reinterpret_cast<alt::IConnectionInfo*>(handle);
    conn->Decline(reason);
}

EXPORT int Connection_IsAccepted(void* handle) {
    auto conn = reinterpret_cast<alt::IConnectionInfo*>(handle);
    return conn->IsAccepted();
}