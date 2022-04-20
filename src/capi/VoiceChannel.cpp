#include "VoiceChannel.h"
#include "GoRuntime.h"

EXPORT int VoiceChannel_GetType(void *c) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(c);
    return static_cast<int>(channel->GetType());
}

EXPORT int VoiceChannel_HasMetaData(void *base, const char *key) {
    auto baseObject = reinterpret_cast<alt::IVoiceChannel *>(base);
    return baseObject->HasMetaData(key);
}

EXPORT Array VoiceChannel_GetMetaData(void *base, const char *key) {

    auto channel = reinterpret_cast<alt::IVoiceChannel *>(base);
    auto meta = channel->GetMetaData(key);

    auto metaData = Go::Runtime::MValueToProtoBytes(meta);

    return metaData;
}

EXPORT void VoiceChannel_SetMetaData(void *base, const char *key, unsigned char *data, unsigned long long size) {

    auto channel = reinterpret_cast<alt::IVoiceChannel *>(base);
    auto value = Go::Runtime::ProtoToMValue(data, size);

    channel->SetMetaData(key, value);
}

EXPORT void VoiceChannel_DeleteMetaData(void *base, const char *key) {

    auto channel = reinterpret_cast<alt::IVoiceChannel *>(base);
    channel->DeleteMetaData(key);
    // channel->RemoveRef();
}

EXPORT void VoiceChannel_Destroy(void *b) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(b);
    alt::ICore::Instance().DestroyBaseObject(channel);
}

EXPORT int VoiceChannel_IsValid(void *p) {
    auto vc = reinterpret_cast<alt::IVoiceChannel *>(p);
    return vc ? 1 : 0;
}

EXPORT int VoiceChannel_IsSpatial(void *v) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(v);
    return channel->IsSpatial();
}

EXPORT float VoiceChannel_GetMaxDistance(void *v) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(v);
    return channel->GetMaxDistance();
}

EXPORT int VoiceChannel_HasPlayer(void *v, void *p) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(v);
    auto player = reinterpret_cast<alt::IPlayer *>(p);
    return channel->HasPlayer(player);
}

EXPORT void VoiceChannel_AddPlayer(void *v, void *p) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(v);
    auto player = reinterpret_cast<alt::IPlayer *>(p);
    channel->AddPlayer(player);
}

EXPORT void VoiceChannel_RemovePlayer(void *v, void *p) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(v);
    auto player = reinterpret_cast<alt::IPlayer *>(p);
    channel->RemovePlayer(player);
}

EXPORT int VoiceChannel_IsPlayerMuted(void *v, void *p) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(v);
    auto player = reinterpret_cast<alt::IPlayer *>(p);
    return channel->IsPlayerMuted(player);
}

EXPORT void VoiceChannel_MutePlayer(void *v, void *p) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(v);
    auto player = reinterpret_cast<alt::IPlayer *>(p);
    channel->MutePlayer(player);
}

EXPORT void VoiceChannel_UnmutePlayer(void *v, void *p) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(v);
    auto player = reinterpret_cast<alt::IPlayer *>(p);
    channel->UnmutePlayer(player);
}

EXPORT unsigned long long VoiceChannel_GetPlayerCount(void *v) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(v);
    return channel->GetPlayerCount();
}

EXPORT Array VoiceChannel_GetPlayers(void *v) {
    auto channel = reinterpret_cast<alt::IVoiceChannel *>(v);
    auto players = channel->GetPlayers();

    return Go::Runtime::GetInstance()->CreatePointerArray(players);
}