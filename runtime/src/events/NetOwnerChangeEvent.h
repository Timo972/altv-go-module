#pragma once

#include "Main.h"
#include "Library.h"
#include "GoEventFactory.h"

namespace Go
{
    class NetOwnerChangeEvent : public Go::IEvent
            {
            public:
                explicit NetOwnerChangeEvent(ModuleLibrary *module);
                void Call(const alt::CEvent *ev) override;
            };
}