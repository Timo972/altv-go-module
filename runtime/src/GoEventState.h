#pragma once

#include "Main.h"
#include "Library.h"

namespace Go
{
    class IEventState
    {
    public:
        virtual ~IEventState() = default;
        virtual void Call(const alt::CEvent *ev, const std::string &resourceName, ModuleLibrary *module) = 0;
    };

    class EventContext
    {
    private:
        IEventState *_state;

    public:
        EventContext();
        ~EventContext();
        void SetState(IEventState *s);
        void Request(const alt::CEvent *ev, const std::string &resourceName, ModuleLibrary *module);
    };
}
