#include "ConsoleCommandEvent.h"

Go::ConsoleCommandEvent::ConsoleCommandEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::ConsoleCommandEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altConsoleCommandEvent", void (*)(const char* name, const char* *args, unsigned long long size));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call ConsoleCommandEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CConsoleCommandEvent *>(ev);
    auto name = event->GetName();
    auto args = event->GetArgs();

    uint64_t size = args.GetSize();

#ifdef _WIN32
    auto constArgs = new const char* [size];
#else
    const char* constArgs[size];
#endif

    call(name.CStr(), constArgs, size);
}
