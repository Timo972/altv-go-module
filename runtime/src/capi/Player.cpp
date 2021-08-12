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

EXPORT Position Player_GetPosition(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    auto pos = player->GetPosition();

    Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;

    return position;
}

EXPORT void Player_SetPosition(void *p, float x, float y, float z)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);

    alt::Position position;
    position.x = x;
    position.y = y;
    position.z = z;

    player->SetPosition(position);
}

EXPORT long Player_GetDimension(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    return player->GetDimension();
}

EXPORT void Player_SetDimension(void *p, long dimension)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetDimension(dimension);
}

EXPORT void Player_Spawn(void *p, float x, float y, float z, unsigned long delay)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);

    alt::Position position;
    position.x = x;
    position.y = y;
    position.z = z;

    player->Spawn(position, delay);
}

EXPORT void Player_SetModel(void *p, unsigned long model)
{
    auto player = reinterpret_cast<alt::IPlayer*>(p);
    player->SetModel(model);
}
