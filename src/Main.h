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
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
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

typedef struct fireInfo {
    Position position;
    unsigned long weaponHash;
} FireInfo;

typedef struct neonState {
    int left;
    int right;
    int front;
    int back;
} VehicleNeonState;

typedef struct entity {
    unsigned char Type;
    const void *Ptr;
} Entity;

typedef struct array {
    unsigned long long size;
    void* array;
} Array;

typedef struct data {
    void* mValue;
    unsigned int Type;
} CustomData;

#include "SDK.h"