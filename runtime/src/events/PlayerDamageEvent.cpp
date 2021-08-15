#include "PlayerDamageEvent.h"

Go::PlayerDamageEvent::PlayerDamageEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::PlayerDamageEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altPlayerDamageEvent", bool (*)(alt::IPlayer *playerObject, Entity attackerObject, unsigned short damage, unsigned long weapon));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call PlayerDamageEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CPlayerDamageEvent *>(ev);
    auto player = event->GetTarget().Get();
    auto attacker = event->GetAttacker();
    auto damage = event->GetDamage();
    auto weapon = event->GetWeapon();

    Entity e;
    e.Ptr = attacker.Get();
    e.Type = static_cast<unsigned char>(attacker->GetType());

    auto cancel = call(player, e, damage, weapon);

    if(cancel) {
        event->Cancel();
    }
}
