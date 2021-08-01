#include "Main.h"
#include "GoRuntime.h"

EXPORT bool altMain(alt::ICore* core) {
    alt::ICore::SetInstance(core);

    auto runtime = Go::Runtime::GetInstance();

    core->RegisterScriptRuntime("go", runtime);
    core->LogInfo("Go Module Loaded");

    return true;
}

EXPORT int GetSDKVersion() {
    return alt::ICore::SDK_VERSION;
}
