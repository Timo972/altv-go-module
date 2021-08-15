#include "PlayerWeaponChangeEvent.h"

Go::PlayerWeaponChangeEvent::PlayerWeaponChangeEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::PlayerWeaponChangeEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altPlayerWeaponChangeEvent", void (*)(alt::IPlayer* player, unsigned long oldWeapon, unsigned long newWeapon));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call PlayerWeaponChangeEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CPlayerWeaponChangeEvent *>(ev);
    auto player = event->GetTarget().Get();
    auto oldWeapon = event->GetOldWeapon();
    auto newWeapon = event->GetNewWeapon();

    call(player, oldWeapon, newWeapon);
}
