#pragma once

#include "Main.h"
#include "GoRuntime.h"
#include "GoEventManager.h"
#include "GoEventState.h"

namespace Go {
    class Resource : public alt::IResource::Impl, public Go::EventsManager {
        private:
            Go::Runtime* _runtime;
            alt::IResource* _resource;
        public:
            Resource(Go::Runtime* runtime, alt::IResource* resource);
            ~Resource() override = default;
            bool Start() override;
            bool Stop() override;
            bool OnEvent(const alt::CEvent *ev) override;
            void OnTick() override;
        };
}