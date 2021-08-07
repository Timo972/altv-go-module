#include "Player.h"

EXPORT const char *Player_GetName(void *p)
{
    auto player = reinterpret_cast<alt::IPlayer *>(p);
    return player->GetName().CStr();
}