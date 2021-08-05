#include "PlayerConnectEvent.h"

void Go::PlayerConnectEvent::Call(const alt::CEvent *ev, const std::string& resourceName, ModuleLibrary* module) {
    auto call = GET_FUNC(module, "altPlayerConnectEvent", void(*)(const std::string& resource,
            alt::IPlayer* playerObject));
    if(call == nullptr) {
        alt::ICore::Instance().LogError("Couldn't not call PlayerConnectEvent");
        return;
    }

    auto event = dynamic_cast<const alt::CPlayerConnectEvent*>(ev);
    auto player = event->GetTarget().Get();

    call(resourceName, player);
}