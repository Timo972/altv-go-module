#include "PlayerEnterVehicleEvent.h"

Go::PlayerEnterVehicleEvent::PlayerEnterVehicleEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::PlayerEnterVehicleEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altPlayerEnterVehicleEvent", bool (*)(alt::IPlayer *playerObject, alt::IVehicle *vehicleObject, unsigned char seat));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call PlayerEnterVehicleEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CPlayerEnterVehicleEvent *>(ev);
    auto vehicle = event->GetTarget().Get();
    auto player = event->GetPlayer().Get();
    auto seat = event->GetSeat();

    auto cancel = call(player, vehicle, seat);

    if(cancel) {
        event->Cancel();
    }
}
