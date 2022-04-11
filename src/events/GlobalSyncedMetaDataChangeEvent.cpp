#include "GlobalSyncedMetaDataChangeEvent.h"

Go::GlobalSyncedMetaDataChangeEvent::GlobalSyncedMetaDataChangeEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::GlobalSyncedMetaDataChangeEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altGlobalSyncedMetaDataChangeEvent", void (*)(const char* key, MetaData newValue, MetaData oldValue));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Could not call GlobalSyncedMetaDataChangeEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CGlobalSyncedMetaDataChangeEvent *>(ev);
    auto key = event->GetKey().c_str();
    auto newValueMeta = event->GetVal();
    auto oldValueMeta = event->GetOldVal();

    // Temporary
    MetaData newValue;
    newValue.Ptr = newValueMeta.Get();
    newValue.Type = static_cast<unsigned char>(newValueMeta->GetType());

    MetaData oldValue;
    oldValue.Ptr = oldValueMeta.Get();
    oldValue.Type = static_cast<unsigned char>(oldValueMeta->GetType());

    call(key, newValue, oldValue);
}
