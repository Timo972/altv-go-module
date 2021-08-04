#pragma once

#include "Main.h"
#include "Library.h"
#include "GoEventState.h"

namespace Go {
    class PlayerConnectEvent : public Go::IEventState {
    public:
        PlayerConnectEvent() = default;
        void Call(const alt::CEvent* ev, const std::string& resourceName, ModuleLibrary* module) override;
    };
}
