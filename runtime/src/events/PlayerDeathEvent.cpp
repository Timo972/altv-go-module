#include "PlayerDeathEvent.h"

Go::PlayerDeathEvent::PlayerDeathEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::PlayerDeathEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altPlayerDeathEvent", void (*)(alt::IPlayer *playerObject, alt::IEntity *killerObject, unsigned long weapon));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call PlayerDeathEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CPlayerDeathEvent *>(ev);
    auto player = event->GetTarget().Get();
    auto killer = event->GetKiller().Get();
    auto weapon = event->GetWeapon();

    call(player, killer, weapon);
}
