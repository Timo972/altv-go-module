#include "LocalSyncedMetaDataChangeEvent.h"
// cpp-sdk does not include it by default??
#include "events/CLocalMetaDataChangeEvent.h"

Go::LocalSyncedMetaDataChangeEvent::LocalSyncedMetaDataChangeEvent(ModuleLibrary *module) : IEvent(module) {}

void Go::LocalSyncedMetaDataChangeEvent::Call(const alt::CEvent *ev) {
    static auto call = GET_FUNC(Library, "altLocalSyncedMetaDataChangeEvent",
                                void(*)(void *p, const char* key, MetaData newValue, MetaData oldValue));

    if (call == nullptr) {
        alt::ICore::Instance().LogError("Could not call LocalSyncedMetaDataChangeEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CLocalMetaDataChangeEvent *>(ev);
    auto player = event->GetTarget().Get();
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

    call(player, key, newValue, oldValue);
}
