#include "ServerScriptEvent.h"

Go::ServerScriptEvent::ServerScriptEvent(ModuleLibrary *module) : IEvent(module) {

}

void Go::ServerScriptEvent::Call(const alt::CEvent *ev) {
    static auto call = GET_FUNC(Library, "altServerScriptEvent", bool (*)(const char *name,
            CustomData *args, unsigned long long int size));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call ServerScriptEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CServerScriptEvent*>(ev);
    auto name = event->GetName().CStr();
    const auto &args = event->GetArgs();
    auto size = args.GetSize();

#ifdef _WIN32
    auto constArgs = new CustomData[size];
#else
    CustomData constArgs[size];
#endif

    for (int i = 0; i < size; ++i) {
        CustomData eventData = {(void *) args[i].Get(), static_cast<unsigned int>(args[i]->GetType())};
        constArgs[i] = eventData;
    }

    call(name, constArgs, size);

#ifdef _WIN32
    delete[] constArgs;
#endif
}
