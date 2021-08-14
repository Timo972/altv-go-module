#include "ConsoleCommandEvent.h"

Go::ConsoleCommandEvent::ConsoleCommandEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::ConsoleCommandEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altConsoleCommandEvent", void (*)(const char* name));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call ConsoleCommandEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CConsoleCommandEvent *>(ev);
    auto name = event->GetName();
    auto args = event->GetArgs();

    // TODO pass args array correctly
    call(name.CStr());
}
