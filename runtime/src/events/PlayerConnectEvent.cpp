#include "PlayerConnectEvent.h"

void Go::PlayerConnectEvent::Call(const alt::CEvent *ev) {
    auto event = dynamic_cast<const alt::CPlayerConnectEvent*>(ev);
    auto player = event->GetTarget();
}