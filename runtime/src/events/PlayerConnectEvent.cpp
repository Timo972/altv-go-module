#include "PlayerConnectEvent.h"

void Go::PlayerConnectEvent::Call(const alt::CEvent *ev, ModuleLibrary *module)
{
    static auto call = GET_FUNC(module, "altPlayerConnectEvent", void (*)(alt::IPlayer *playerObject));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call PlayerConnectEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CPlayerConnectEvent *>(ev);
    auto player = event->GetTarget().Get();

    call(player);
}

