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

#include "SDK.h"