# altv-go-module
Go module for alt:V Multiplayer.
>⚠️This repo got merged into [altv-go](https://github.com/Timo972/altv-go). You can find an up 2 date module version there.⚠️

Go package for creating custom game-modes can be found [here](https://github.com/timo972/altv-go).

Module is still under heavy development, and it's not suitable for production usage.  
Right now the module should cover most of the alt:V API but its untested.

If you find a bug or missing function please open an issue for it.

## Installation
Installing the module is very simple:
1. Download ``go-module.dll`` for windows or ``libgo-module.so`` for linux from [Releases](https://github.com/timo972/altv-go-module/releases)
2. Put the downloaded file into the your servers module folder
3. Edit the server.cfg and add the module:
```
modules: [
    go
]
```
Thats it!

## Building
**To build the module there are some prerequisites needed:**
- [Windows] Visual Studio 2019 or later
- [Linux] GCC 8
- [CMake](https://cmake.org/download/)
- [ProtoC 3.19.4](https://github.com/protocolbuffers/protobuf/releases/tag/v3.19.4)

Then just run ``build.bat`` or ``build.sh`` in the root folder (depending on os).
