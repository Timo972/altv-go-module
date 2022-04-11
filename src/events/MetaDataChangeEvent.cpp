#include "MetaDataChangeEvent.h"
// cpp-sdk does not include it by default??
#include "events/CMetaDataChangeEvent.h"

Go::MetaDataChangeEvent::MetaDataChangeEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::MetaDataChangeEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altMetaDataChangeEvent", void (*)(const char* key, MetaData newValue, MetaData oldValue));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Could not call MetaDataChangeEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CMetaChangeEvent *>(ev);
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
