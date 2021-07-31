#include "Main.h"
#include "GoRuntime.h"

EXPORT bool altMain(alt::ICore* core) {
    alt::ICore::SetInstance(core);

    auto runtime = GoRuntime::GetInstance();
    std::cout << &runtime << std::endl;
    core->RegisterScriptRuntime("go", runtime);
    core->LogInfo("Go Module Loaded");

    return true;
}

EXPORT int GetSDKVersion() {
    return alt::ICore::SDK_VERSION;
}
