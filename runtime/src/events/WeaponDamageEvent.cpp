#include "WeaponDamageEvent.h"

Go::WeaponDamageEvent::WeaponDamageEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::WeaponDamageEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altWeaponDamageEvent", bool (*)(alt::IPlayer* source, alt::IEntity* target, unsigned long weapon, unsigned short damage));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call WeaponDamageEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CWeaponDamageEvent *>(ev);
    auto target = event->GetTarget().Get();
    auto source = event->GetSource().Get();
    auto bodyPart = event->GetBodyPart();
    auto damage = event->GetDamageValue();
    auto weapon = event->GetWeaponHash();
    auto offset = event->GetShotOffset();

    // TODO
    // Position cOffset;
    // cOffset.x = offset.x;
    // cOffset.y = offset.y;
    // cOffset.z = offset.z;

    // TODO add bodyPart enum
    auto cancel = call(source, target, weapon, damage);

    if(cancel) {
        event->Cancel();
    }
}
