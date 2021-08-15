#include "StreamSyncedMetaDataChangeEvent.h"

Go::StreamSyncedMetaDataChangeEvent::StreamSyncedMetaDataChangeEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::StreamSyncedMetaDataChangeEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altStreamSyncedMetaDataChangeEvent", void (*)(alt::IEntity* entity, const char* key, MetaData newValue, MetaData oldValue));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Could not call StreamSyncedMetaDataChangeEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CStreamSyncedMetaDataChangeEvent *>(ev);
    auto entity = event->GetTarget().Get();
    auto key = event->GetKey().CStr();
    auto newValueMeta = event->GetVal();
    auto oldValueMeta = event->GetOldVal();

    // Temporary
    MetaData newValue;
    newValue.Ptr = newValueMeta.Get();
    newValue.Type = static_cast<unsigned char>(newValueMeta->GetType());

    MetaData oldValue;
    oldValue.Ptr = oldValueMeta.Get();
    oldValue.Type = static_cast<unsigned char>(oldValueMeta->GetType());

    call(entity, key, newValue, oldValue);
}
