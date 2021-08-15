#include "ColShapeEvent.h"

Go::ColShapeEvent::ColShapeEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::ColShapeEvent::Call(const alt::CEvent *ev)
{
    static auto callEnter = GET_FUNC(Library, "altEntityEnterColShapeEvent", void (*)(alt::IColShape* colshape, alt::IEntity* entity));
    static auto callLeave = GET_FUNC(Library, "altEntityLeaveColShapeEvent", void (*)(alt::IColShape* colshape, alt::IEntity* entity));

    if (callEnter == nullptr)
    {
        alt::ICore::Instance().LogError("Could not call altEntityEnterColShapeEvent.");
        return;
    }

    if (callLeave == nullptr)
    {
        alt::ICore::Instance().LogError("Could not call altEntityLeaveColShapeEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CColShapeEvent *>(ev);
    auto state = event->GetState();

    auto colShape = event->GetTarget().Get();
    auto entity = event->GetEntity().Get();

    if(state) {
        callEnter(colShape, entity);
    } else {
        callLeave(colShape, entity);
    }
}
