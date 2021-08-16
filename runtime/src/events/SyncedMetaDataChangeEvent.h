#pragma once

#include "Main.h"
#include "Library.h"
#include "GoEventFactory.h"

namespace Go
{
    class SyncedMetaDataChangeEvent : public Go::IEvent
            {
            public:
                explicit SyncedMetaDataChangeEvent(ModuleLibrary *module);
                void Call(const alt::CEvent *ev) override;
            };
}