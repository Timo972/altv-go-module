#include "PlayerDamageEvent.h"

Go::PlayerDamageEvent::PlayerDamageEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::PlayerDamageEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altPlayerDamageEvent", void (*)(alt::IPlayer *playerObject, alt::IEntity *attackerObject, unsigned short damage, unsigned long weapon));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call PlayerDamageEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CPlayerDamageEvent *>(ev);
    auto player = event->GetTarget().Get();
    auto attacker = event->GetAttacker().Get();
    auto damage = event->GetDamage();
    auto weapon = event->GetWeapon();

    call(player, attacker, damage, weapon);
}
