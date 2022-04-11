#pragma once

#define ALT_SERVER_API

// Temporary
typedef struct meta {
    const void *Ptr;
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
    unsigned char left;
    unsigned char right;
    unsigned char front;
    unsigned char back;
} VehicleNeonState;

typedef struct entity {
    unsigned char Type;
    const void *Ptr;
} Entity;

typedef struct array {
    unsigned long long size;
    void *array;
} Array;

typedef struct data {
    void *mValue;
    unsigned int Type;
} CustomData;

typedef struct connectionInfo {
    const char *name;
    unsigned long long socialID;
    unsigned long long hwidHash;
    unsigned long long hwidExHash;
    const char *authToken;
    unsigned char isDebug;
    const char *branch;
    unsigned int build;
    const char *cdnUrl;
    unsigned long long passwordHash;
    const char *ip;
    const char *discordUserID;
} ConnectionInfo;

typedef struct weapon {
    unsigned int hash;
    unsigned char tintIndex;
    Array components;
} Weapon;

typedef struct headBlendData {
    unsigned int shapeFirstID;
    unsigned int shapeSecondID;
    unsigned int shapeThirdID;
    unsigned int skinFirstID;
    unsigned int skinSecondID;
    unsigned int skinThirdID;
    float shapeMix;
    float skinMix;
    float thirdMix;
} HeadBlendData;

typedef struct headOverlay {
    unsigned char index = 0;
    float opacity = 0;
    unsigned char colorType;
    unsigned char colorIndex = 0;
    unsigned char secondColorIndex = 0;
} HeadOverlay;

#include "SDK.h"