#pragma once

#define ALT_SERVER_API

// Temporary
typedef struct meta {
    const void* Ptr;
    unsigned char Type;
} MetaData;

typedef struct pos {
    float x;
    float y;
    float z;
} Position;

typedef struct rot {
    float roll;
    float pitch;
    float yaw;
} Rotation;

typedef struct rgba {
    unsigned long r;
    unsigned long g;
    unsigned long b;
    unsigned long a;
} RGBA;

typedef struct cloth {
    unsigned int drawableId;
    unsigned int textureId;
    unsigned int paletteId;
} Cloth;

typedef struct dlcCloth {
    unsigned long dlc;
    unsigned int drawableId;
    unsigned int textureId;
    unsigned int paletteId;
} DlcCloth;

typedef struct prop {
    unsigned int drawableId;
    unsigned int textureId;
} Prop;

typedef struct dlcProp {
    unsigned long dlc;
    unsigned int drawableId;
    unsigned int textureId;
} DlcProp;

#include "SDK.h"