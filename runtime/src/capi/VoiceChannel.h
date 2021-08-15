#pragma once

#include "Main.h"

#ifdef __cplusplus
extern "C"
{
#endif
    // BaseObject inherited
    EXPORT int VoiceChannel_GetType(void *c);
    EXPORT int VoiceChannel_HasMetaData(void* base, const char *key);
    EXPORT MetaData VoiceChannel_GetMetaData(void* base, const char *key);
    EXPORT void VoiceChannel_SetMetaData(void *base, const char *key, void *val);
    EXPORT void VoiceChannel_DeleteMetaData(void *base, const char *key);

    // VoiceChannel methods
    EXPORT int VoiceChannel_IsSpatial(void *v);
    EXPORT float VoiceChannel_GetMaxDistance(void *v);
    EXPORT int VoiceChannel_HasPlayer(void *v, void *p);
    EXPORT void VoiceChannel_AddPlayer(void *v, void *p);
    EXPORT void VoiceChannel_RemovePlayer(void *v, void *p);
    EXPORT int VoiceChannel_IsPlayerMuted(void *v, void *p);
    EXPORT void VoiceChannel_MutePlayer(void *v, void *p);
    EXPORT void VoiceChannel_UnmutePlayer(void *v, void *p);
#ifdef __cplusplus
}
#endif
