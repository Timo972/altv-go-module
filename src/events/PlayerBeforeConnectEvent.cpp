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

    connectionInfo conn;
    conn.authToken = info->GetAuthToken().c_str();
    conn.branch = info->GetBranch().c_str();
    conn.build = info->GetBuild();
    conn.cdnUrl = info->GetCdnUrl().c_str();
    conn.discordUserID = info->GetDiscordUserID().c_str();
    conn.hwidExHash = info->GetHwIdExHash();
    conn.hwidHash = info->GetHwIdHash();
    conn.ip = info->GetIp().c_str();
    conn.isDebug = info->GetIsDebug();
    conn.name = info->GetName().c_str();
    conn.passwordHash = info->GetPasswordHash();
    conn.socialID = info->GetSocialId();

    auto result = call(conn, reason);
    if (result == "")
        info->Accept();
    else
        info->Decline(result);
}
