#pragma once

#include <iostream>
#include <map>
#include <vector>

#include "Main.h"
#include "rapidjson/document.h"

namespace Go {
    class Runtime : public alt::IScriptRuntime {
    private:
        static Runtime *Instance;
        std::vector<std::map<std::string, alt::IResource::Impl *>> _resources;
    public:
        Runtime() = default;

        alt::IResource::Impl *CreateImpl(alt::IResource *resource) override;

        void DestroyImpl(alt::IResource::Impl *impl) override;

        alt::IResource::Impl *GetResource(const std::string &name);

        static alt::MValueArgs CreateMValueArgs(CustomData *MValues, unsigned long long size);

        alt::MValue CreateMValueFromJSONValue(rapidjson::Value &value);

        static Entity GetEntity(alt::Ref<alt::IEntity> entity);

        static alt::IEntity *GetEntityRef(Entity entity);

        static ConnectionInfo GetConnectionInfo(alt::Ref<alt::IConnectionInfo> info);

        rapidjson::Document SerializeConfigNode(alt::config::Node node);

        const char *SerializeConfig(alt::config::Node rootNode);

        // Array helper stuff
        template<class ClassInstance>
        Array CreatePointerArray(alt::Array<alt::Ref<ClassInstance>> objects) {
            Array arr;
            arr.size = objects.GetSize();

#ifdef _WIN32
            auto playerRefs = new void *[arr.size];
#else
            void* playerRefs[arr.size];
#endif
            for (uint64_t i = 0; i < arr.size; i++) {
                playerRefs[i] = objects[i].Get();
            }

            arr.array = playerRefs;

            return arr;
        }

        template<class ClassInstance>
        Array CreatePointerArray(std::vector<alt::Ref<ClassInstance>> objects) {
            Array arr;
            arr.size = objects.size();

#ifdef _WIN32
            auto playerRefs = new void *[arr.size];
#else
            void* playerRefs[arr.size];
#endif
            for (uint64_t i = 0; i < arr.size; i++) {
                playerRefs[i] = objects[i].Get();
            }

            arr.array = playerRefs;

            return arr;
        }

        template<typename Type, typename TargetType>
        Array CreateArray(alt::Array<Type> altArr) {
            Array arr;
            arr.size = altArr.GetSize();

#ifdef _WIN32
            auto cArray = new TargetType[arr.size];
#else
            TargetType cArray[arr.size];
#endif
            for (uint64_t i = 0; i < arr.size; i++) {
                cArray[i] = static_cast<TargetType>(altArr[i]);
            }

            arr.array = cArray;

            return arr;
        }

        template<typename Type, typename TargetType>
        Array CreateArray(std::unordered_set<Type> set) {
            Array arr;

            arr.size = set.size();
#ifdef _WIN32
            auto cset = new TargetType[arr.size];
#else
            TargetType cset[arr.size];
#endif
            uint64_t i = 0;
            for (const auto &item: set) {
                cset[i] = item;
                i++;
            }

            arr.array = cset;

            return arr;
        }

/*        template<typename Type, typename TargetType>
        Array CreateArray(std::vector<Type> vec) {
            Array arr;

            arr.size = vec.size();
#ifdef _WIN32
            auto cset = new TargetType[arr.size];
#else
            TargetType cset[size];
#endif
            for (uint64_t i = 0; i < arr.size; i++) {
                cset[i] = vec[i];
                i++;
            }

            arr.array = cset;

            return arr;
        }*/

        static Go::Runtime *GetInstance();
    };
}