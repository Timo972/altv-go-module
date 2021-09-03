# altv-go-module
Go module for alt:V Multiplayer.
Go package for creating custom game-modes can be found [here](https://github.com/shockdev04/altv-go-pkg).

Module is still under heavy development, and it's not suitable for production usage.  
Right now the module should cover most of the alt:V API but its untested.

If you find a bug or missing function please open an issue for it.

## Installation
Installing the module is very simple:
1. Download ``go-module.dll`` for windows or ``libgo-module.so`` for linux from [Releases](https://github.com/shockdev04/altv-go-module/releases)
2. Put the downloaded file into the your servers module folder
3. Edit the server.cfg and add the module:
```
modules: [
    go
]
```
Thats it!

## TODO
- [ ] Fix timers
- [ ] performance improvement for MValueList and Dict using serialization