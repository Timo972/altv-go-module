#include "ServerScriptEvent.h"

Go::ServerScriptEvent::ServerScriptEvent(ModuleLibrary *module) : IEvent(module) {}

void Go::ServerScriptEvent::Call(const alt::CEvent *ev) {
    static auto call = GET_FUNC(Library, "altServerScriptEvent", bool (*)(const char *name,
            void *args, unsigned long long size));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call ServerScriptEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
    auto name = event->GetName().c_str();
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

    call(name, constArgs, size);

#ifdef _WIN32
    delete[] constArgs;
#endif
}
