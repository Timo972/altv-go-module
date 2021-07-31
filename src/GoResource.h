#pragma once

#include "Main.h"
#include "GoRuntime.h"

class GoResource : public alt::IResource::Impl {
private:
    GoRuntime* _runtime;
    alt::IResource* _resource;
public:
    GoResource(GoRuntime *runtime, alt::IResource *resource) : _runtime(runtime), _resource(resource) {}
    bool Start() override;
    bool Stop() override;
};

