#include "Player.h"

EXPORT const char *Player_GetName(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer *>(p);
    return player->GetName().CStr();
}

EXPORT int Player_HasMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    return baseObject->HasMetaData(key);
}

EXPORT MetaData Player_GetMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    auto meta = baseObject->GetMetaData(key);

    // Temporary
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
}

EXPORT void Player_SetMetaData(void *base, const char *key, void *val)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    auto value = reinterpret_cast<alt::IMValue*>(val);

    baseObject->SetMetaData(key, value);
}

EXPORT void Player_DeleteMetaData(void *base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IPlayer*>(base);
    baseObject->DeleteMetaData(key);
    baseObject->RemoveRef();
}