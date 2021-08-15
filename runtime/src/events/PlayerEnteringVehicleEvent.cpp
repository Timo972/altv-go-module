#include "PlayerEnteringVehicleEvent.h"

Go::PlayerEnteringVehicleEvent::PlayerEnteringVehicleEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::PlayerEnteringVehicleEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altPlayerEnteringVehicleEvent", bool (*)(alt::IPlayer* player, alt::IVehicle* vehicle, unsigned short seat));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Couldn't not call PlayerEnteringVehicleEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CPlayerEnteringVehicleEvent *>(ev);
    auto vehicle = event->GetTarget().Get();
    auto player = event->GetPlayer().Get();
    auto seat = event->GetSeat();

    auto cancel = call(player, vehicle, seat);

    if(cancel) {
        event->Cancel();
    }
}
