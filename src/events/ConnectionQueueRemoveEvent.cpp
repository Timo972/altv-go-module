#include "ConnectionQueueRemoveEvent.h"

Go::ConnectionQueueRemoveEvent::ConnectionQueueRemoveEvent(ModuleLibrary *module) : IEvent(module) {}

void Go::ConnectionQueueRemoveEvent::Call(const alt::CEvent *ev) {
    static auto call = GET_FUNC(Library, "altConnectionQueueRemoveEvent",
                               void (*)(connectionInfo info));

    if (call == nullptr) {
        alt::ICore::Instance().LogError("Couldn't not call ConnectionQueueRemoveEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CConnectionQueueAddEvent *>(ev);
    auto info = event->GetConnectionInfo();
    auto conn = Go::Runtime::GetInstance()->GetConnectionInfo(info);

    call(conn);
}
