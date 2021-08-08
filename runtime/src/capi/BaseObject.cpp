#include "BaseObject.h"

EXPORT int BaseObject_HasMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IBaseObject*>(base);
    return baseObject->HasMetaData(key);
}

EXPORT SentData BaseObject_GetMetaData(void* base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IBaseObject*>(base);
    auto meta = baseObject->GetMetaData(key).Get();

    SentData sentData;
    sentData.Ptr = meta;
    sentData.Type = static_cast<unsigned int>(meta->GetType());

    return sentData;
}

EXPORT void BaseObject_SetMetaData(void *base, const char *key, void *val)
{
    auto baseObject = reinterpret_cast<alt::IBaseObject*>(base);
    auto value = reinterpret_cast<alt::IMValue*>(val);

    baseObject->SetMetaData(key, value);
}

EXPORT void BaseObject_DeleteMetaData(void *base, const char *key)
{
    auto baseObject = reinterpret_cast<alt::IBaseObject*>(base);
    baseObject->DeleteMetaData(key);
    baseObject->RemoveRef();
}