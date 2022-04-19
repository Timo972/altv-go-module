@echo off
IF NOT EXIST build\ (
    mkdir build
)

IF NOT EXIST bin\ (
    mkdir bin
)
pushd build
cmake -G"Visual Studio 17" -A x64 ..
cmake --build . --config Release
popd
