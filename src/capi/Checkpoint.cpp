#include "Checkpoint.h"

// BaseObject inherited
EXPORT int Checkpoint_GetType(void *c)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    return static_cast<int>(checkpoint->GetType());
}

EXPORT int Checkpoint_HasMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::ICheckpoint*>(base);
    return baseObject->HasMetaData(key);
}

EXPORT MetaData Checkpoint_GetMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::ICheckpoint*>(base);
    auto meta = baseObject->GetMetaData(key);

    // Temporary
    MetaData metaData;
    metaData.Ptr = meta.Get();
    metaData.Type = static_cast<unsigned char>(meta->GetType());

    return metaData;
}

EXPORT void Checkpoint_SetMetaData(void *base, const char *key, void *val)
{
    auto baseObject = reinterpret_cast<alt::ICheckpoint*>(base);
    auto value = reinterpret_cast<alt::IMValue*>(val);

    baseObject->SetMetaData(key, value);
}

EXPORT void Checkpoint_DeleteMetaData(void *base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::ICheckpoint*>(base);
    baseObject->DeleteMetaData(key);
    baseObject->RemoveRef();
}

EXPORT void Checkpoint_Destroy(void *b)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(b);
    alt::ICore::Instance().DestroyBaseObject(checkpoint);
}

// WorldObject inherited
EXPORT Position Checkpoint_GetPosition(void *p)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(p);
    auto pos = checkpoint->GetPosition();

    Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;

    return position;
}

EXPORT void Checkpoint_SetPosition(void *p, float x, float y, float z)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(p);

    alt::Position position;
    position.x = x;
    position.y = y;
    position.z = z;

    checkpoint->SetPosition(position);
}

EXPORT long Checkpoint_GetDimension(void *p)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(p);
    return checkpoint->GetDimension();
}

EXPORT void Checkpoint_SetDimension(void *p, long dimension)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(p);
    checkpoint->SetDimension(dimension);
}

// ColShape inherited
EXPORT int Checkpoint_GetColShapeType(void *c)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    return static_cast<int>(checkpoint->GetColshapeType());
}

EXPORT int Checkpoint_IsEntityIn(void *c, void *e)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    auto entity = reinterpret_cast<alt::IEntity*>(e);
    return checkpoint->IsEntityIn(entity);
}

EXPORT int Checkpoint_IsPointIn(void *c, float x, float y, float z)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);

    alt::Position pos;
    pos.x = x;
    pos.y = y;
    pos.z = z;

    return checkpoint->IsPointIn(pos);
}

EXPORT void Checkpoint_SetPlayersOnly(void *c, int state)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    checkpoint->SetPlayersOnly(state);
}

EXPORT int Checkpoint_IsPlayersOnly(void *c)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    return checkpoint->IsPlayersOnly();
}

// Checkpoint methods
EXPORT unsigned char Checkpoint_GetCheckpointType(void *c)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    return checkpoint->GetCheckpointType();
}

EXPORT float Checkpoint_GetHeight(void *c)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    return checkpoint->GetHeight();
}

EXPORT float Checkpoint_GetRadius(void *c)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    return checkpoint->GetRadius();
}

EXPORT RGBA Checkpoint_GetColor(void *c)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    auto rgba = checkpoint->GetColor();

    RGBA color;
    color.r = rgba.r;
    color.g = rgba.g;
    color.b = rgba.b;
    color.a = rgba.a;

    return color;
}

EXPORT Position Checkpoint_GetNextPosition(void *c)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    auto pos = checkpoint->GetNextPosition();

    Position position;
    position.x = pos.x;
    position.y = pos.y;
    position.z = pos.z;

    return position;
}

EXPORT void Checkpoint_SetCheckpointType(void *c, unsigned char type)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    checkpoint->SetCheckpointType(type);
}

EXPORT void Checkpoint_SetHeight(void *c, float height)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    checkpoint->SetHeight(height);
}

EXPORT void Checkpoint_SetRadius(void *c, float radius)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);
    checkpoint->SetRadius(radius);
}

EXPORT void Checkpoint_SetColor(void *c, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);

    alt::RGBA color;
    color.r = r;
    color.b = b;
    color.g = g;
    color.a = a;

    checkpoint->SetColor(color);
}

EXPORT void Checkpoint_SetNextPosition(void *c, float x, float y, float z)
{
    auto checkpoint = reinterpret_cast<alt::ICheckpoint*>(c);

    alt::Position pos;
    pos.x = x;
    pos.y = y;
    pos.z = z;

    checkpoint->SetNextPosition(pos);
}

EXPORT int Checkpoint_IsValid(void *p)
{
    auto cp = reinterpret_cast<alt::ICheckpoint*>(p);
    return cp ? 1 : 0;
}