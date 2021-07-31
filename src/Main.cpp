#include "Main.h"

EXPORT bool altMain(alt::ICore* core) {
    alt::ICore::SetInstance(core);
    core->LogInfo("Go Module Loaded");
    return true;
}

EXPORT int GetSDKVersion() {
    return alt::ICore::SDK_VERSION;
}
