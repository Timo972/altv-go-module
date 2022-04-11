#include "PlayerBeforeConnectEvent.h"

Go::PlayerBeforeConnectEvent::PlayerBeforeConnectEvent(ModuleLibrary *module) : IEvent(module) {}

void Go::PlayerBeforeConnectEvent::Call(const alt::CEvent *ev) {
    static auto call = GET_FUNC(Library, "altPlayerBeforeConnectEvent",
                                const char * (*)(connectionInfo info, const char *reason));

    if (call == nullptr) {
        alt::ICore::Instance().LogError("Couldn't not call PlayerBeforeConnectEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CPlayerBeforeConnectEvent *>(ev);
    auto info = event->GetConnectionInfo();
    auto reason = event->GetReason().c_str();
    auto conn = Go::Runtime::GetInstance()->GetConnectionInfo(info);

    auto result = std::string(call(conn, reason));
    if (result.empty())
        info->Accept();
    else
        info->Decline(result);
}
