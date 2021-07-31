#pragma once

#include "Main.h"
#include "GoRuntime.h"

//class Runtime;

namespace Go {
    class Resource : public alt::IResource::Impl {
    private:
        Go::Runtime* _runtime;
        alt::IResource* _resource;
    public:
        Resource(Go::Runtime *runtime, alt::IResource *resource) : _runtime(runtime), _resource(resource) { }
        bool Start() override;
        bool Stop() override;
    };
}
