#include "GoExportManager.h"

alt::MValue Go::Function::Call(alt::MValueArgs args) const {
    static auto call = GET_FUNC(Library, "altCallFunction",
                                CustomData (*)(unsigned long long id, const void *args, unsigned long long size));

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

    auto returnMetaData = call(id, mValRefs, size);

#ifdef _WIN32
    delete[] mValRefs;
#endif

    if (returnMetaData.mValue == nullptr) {
        return alt::ICore::Instance().CreateMValueNone();
    }

    auto returnMValue = reinterpret_cast<alt::IMValue *>(returnMetaData.mValue);

    return returnMValue;
}

void Go::ExportsManager::AddExport(const char *exportName, alt::MValue data) {
    if (IsExportSet(exportName))
        return;
    _registeredExports->Set(exportName, data);
}

bool Go::ExportsManager::IsExportSet(const char *exportName) {
    return _registeredExports->Get(exportName)->GetType() != alt::IMValue::Type::NONE;
}