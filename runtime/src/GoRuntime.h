#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "Main.h"
#include "rapidjson/document.h"

namespace Go
{
    class Runtime : public alt::IScriptRuntime
    {
    private:
        static Runtime *Instance;
        std::vector<std::map<std::string, alt::IResource::Impl *>> _resources;
    public:
        Runtime() = default;
        alt::IResource::Impl *CreateImpl(alt::IResource *resource) override;
        void DestroyImpl(alt::IResource::Impl *impl) override;
        alt::IResource::Impl *GetResource(const std::string &name);
        alt::MValueArgs CreateMValueArgs(CustomData *MValues, unsigned long long size);
        alt::RefBase<alt::RefStore<alt::IMValue>> CreateMValueFromJSONValue(rapidjson::Value &value);
        static Go::Runtime *GetInstance();
    };
}