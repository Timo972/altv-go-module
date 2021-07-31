#pragma once

#include "Main.h"

namespace Go {
    class Runtime: public alt::IScriptRuntime {
    private:
        Runtime() = default;
        static Runtime* Instance;
    public:
        alt::IResource::Impl * CreateImpl(alt::IResource *resource) override;
        void DestroyImpl(alt::IResource::Impl *impl) override;
        static Runtime *GetInstance();
    };
}

