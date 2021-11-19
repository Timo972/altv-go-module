#include "ClientScriptEvent.h"

Go::ClientScriptEvent::ClientScriptEvent(ModuleLibrary *module) : IEvent(module) {}

void Go::ClientScriptEvent::Call(const alt::CEvent *ev) {
    static auto call = GET_FUNC(Library, "altClientScriptEvent", bool (*)(alt::IPlayer* player, const char *name,
            void *args, unsigned long long size));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't call ClientScriptEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CClientScriptEvent*>(ev);
    auto player = event->GetTarget().Get();
    auto name = event->GetName().CStr();
    const auto& args = event->GetArgs();
    auto size = args.GetSize();

#ifdef _WIN32
    auto constArgs = new MetaData [size];
#else
    MetaData constArgs[size];
#endif

    for (unsigned long long i = 0; i < size; ++i) {
        MetaData data;
        data.Ptr = args[i].Get();
        data.Type = static_cast<unsigned char>(args[i]->GetType());
        constArgs[i] = data;
    }

    call(player, name, constArgs, size);

#ifdef _WIN32
    delete[] constArgs;
#endif
}
