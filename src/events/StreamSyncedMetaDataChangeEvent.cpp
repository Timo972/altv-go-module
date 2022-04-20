#include "StreamSyncedMetaDataChangeEvent.h"
#include "GoRuntime.h"

Go::StreamSyncedMetaDataChangeEvent::StreamSyncedMetaDataChangeEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::StreamSyncedMetaDataChangeEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altStreamSyncedMetaDataChangeEvent", void (*)(Entity entity, const char* key, Array newValue, Array oldValue));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Could not call StreamSyncedMetaDataChangeEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CStreamSyncedMetaDataChangeEvent *>(ev);
    auto entity = event->GetTarget();
    auto key = event->GetKey().c_str();
    auto newValueMeta = event->GetVal();
    auto oldValueMeta = event->GetOldVal();

    Entity e = Go::Runtime::GetEntity(entity);

    auto newValue = Go::Runtime::MValueToProtoBytes(newValueMeta);
    auto oldValue = Go::Runtime::MValueToProtoBytes(oldValueMeta);

    call(e, key, newValue, oldValue);
}
