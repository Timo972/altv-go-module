#include "ConnectionQueueAddEvent.h"

Go::ConnectionQueueAddEvent::ConnectionQueueAddEvent(ModuleLibrary *module) : IEvent(module) {}

void Go::ConnectionQueueAddEvent::Call(const alt::CEvent *ev) {
    static auto call = GET_FUNC(Library, "altConnectionQueueAddEvent",
                                const char * (*)(connectionInfo info));

    if (call == nullptr) {
        alt::ICore::Instance().LogError("Couldn't not call ConnectionQueueAddEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CConnectionQueueAddEvent *>(ev);
    auto info = event->GetConnectionInfo();
    auto conn = Go::Runtime::GetConnectionInfo(info);

    auto result = std::string(call(conn));
    if (result.empty())
        info->Accept();
    else {
        info->Decline(result);
        // FIXME: not sure how queue denying is supposed to be done
        // event->Cancel();
    }
}
