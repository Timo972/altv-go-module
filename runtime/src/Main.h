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

typedef struct array {
    unsigned long long size;
    unsigned int* array;
} Array;

#include "SDK.h"