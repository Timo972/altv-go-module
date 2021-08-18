#include "Runtime.h"

EXPORT int RegisterAltEvent(const char *resourceName, unsigned short eventType)
{
    auto resource = dynamic_cast<Go::Resource *>(Go::Runtime::GetInstance()->GetResource(resourceName));
    if (resource == nullptr)
    {
        return false;
    }

    resource->RegisterEvent(static_cast<alt::CEvent::Type>(eventType));
    return true;
}

EXPORT int UnregisterAltEvent(const char *resourceName, unsigned short eventType)
{
    auto resource = dynamic_cast<Go::Resource *>(Go::Runtime::GetInstance()->GetResource(resourceName));
    if (resource == nullptr)
    {
        return false;
    }

    resource->UnregisterEvent(static_cast<alt::CEvent::Type>(eventType));
    return true;
}