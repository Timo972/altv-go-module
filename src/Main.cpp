#include "version/version.h"
#include "Main.h"
#include "GoRuntime.h"

EXPORT bool altMain(alt::ICore* core) {
    alt::ICore::SetInstance(core);

    auto runtime = Go::Runtime::GetInstance();

    core->RegisterScriptRuntime("go", runtime);
    core->LogInfo("Go Module Loaded");

    return true;
}

EXPORT const char* GetSDKHash() {
    return ALT_SDK_VERSION;
}
