#include "ColShapeEvent.h"

Go::ColShapeEvent::ColShapeEvent(ModuleLibrary *module) : IEvent(module) { }

void Go::ColShapeEvent::Call(const alt::CEvent *ev)
{
    static auto call = GET_FUNC(Library, "altColShapeEvent", void (*)(alt::IColShape* colshape, Entity entity, int state));

    if (call == nullptr)
    {
        alt::ICore::Instance().LogError("Could not call altColShapeEvent.");
        return;
    }

    auto event = dynamic_cast<const alt::CColShapeEvent *>(ev);
    auto state = event->GetState();

    auto colShape = event->GetTarget().Get();
    auto entity = event->GetEntity();

    Entity e;
    e.Ptr = entity.Get();
    e.Type = static_cast<unsigned char>(entity->GetType());


    call(colShape, e, state);
}
