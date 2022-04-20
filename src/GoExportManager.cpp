#include "GoExportManager.h"
#include "GoRuntime.h"

alt::MValue Go::Function::Call(alt::MValueArgs args) const {
    static auto call = GET_FUNC(Library, "altCallFunction",
                                Array (*)(unsigned long long id, const void *args, unsigned long long size));

    if (call == nullptr) {
        alt::ICore::Instance().LogError("Couldn't not call altCallFunction.");
        return alt::ICore::Instance().CreateMValueNone();
    }

    auto size = args.GetSize();

#ifdef _WIN32
    auto mValRefs = new MetaData[size];
#else
    MetaData mValRefs[size];
#endif

    for (unsigned long long i = 0; i < size; i++) {
        MetaData data;
        data.Ptr = args[i].Get();
        data.Type = static_cast<unsigned char>(args[i]->GetType());
        mValRefs[i] = data;
    }

    Array proto = call(id, mValRefs, size);

#ifdef _WIN32
    delete[] mValRefs;
#endif

    // TODO: free proto.array
    auto bytes = reinterpret_cast<unsigned char*>(proto.array);
    auto retValue = Go::Runtime::ProtoToMValue(bytes, proto.size);
    return retValue;
}

void Go::ExportsManager::AddExport(const char *exportName, alt::MValue data) {
    if (IsExportSet(exportName))
        return;
    _registeredExports->Set(exportName, data);
}

bool Go::ExportsManager::IsExportSet(const char *exportName) {
    return _registeredExports->Get(exportName)->GetType() != alt::IMValue::Type::NONE;
}