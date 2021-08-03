#pragma once

#include "Main.h"

namespace Go {
    class IEventState {
    public:
        virtual ~IEventState() = default;
        virtual void Call(const alt::CEvent* ev) = 0;
    };

    class EventContext {
    private:
        IEventState* _state;
    public:
        EventContext();
        ~EventContext();
        void SetState(IEventState* s);
        void Request(const alt::CEvent* ev);
    };
}
