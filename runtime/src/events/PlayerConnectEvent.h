#pragma once

#include "Main.h"
#include "GoEventState.h"

namespace Go {
    class PlayerConnectEvent : public Go::IEventState {
    public:
        PlayerConnectEvent() = default;
        void Call(const alt::CEvent* ev) override;
    };
}
