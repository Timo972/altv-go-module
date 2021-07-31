#pragma once

#include "Main.h"

class GoRuntime: public alt::IScriptRuntime {
private:
    static GoRuntime* Instance;
public:
    alt::IResource::Impl* CreateImpl(alt::IResource *resource) override;
    void DestroyImpl(alt::IResource::Impl* impl) override;
    static GoRuntime* GetInstance();

};
