#pragma once

#include "Main.h"
#include "Library.h"
#include "GoRuntime.h"
#include "GoEventManager.h"

#include "events/PlayerConnectEvent.h"
#include "events/PlayerDisconnectEvent.h"
#include "events/PlayerDamageEvent.h"
#include "events/PlayerDeathEvent.h"
#include "events/PlayerEnterVehicleEvent.h"

namespace Go
{
    class Resource : public alt::IResource::Impl, public Go::EventsManager
    {
    private:
        Go::Runtime *_runtime;
        alt::IResource *_resource;

    public:
        ModuleLibrary *Module = nullptr;
        Resource(Go::Runtime *runtime, alt::IResource *resource);
        ~Resource() override = default;
        bool Start() override;
        bool Stop() override;
        bool OnEvent(const alt::CEvent *ev) override;
        void OnTick() override;
    };
}