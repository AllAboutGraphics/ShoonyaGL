@echo off
echo Initializing Git submodules...
git submodule init

echo Updating Git submodules...
git submodule update

echo Submodules initialized and updated successfully.

call dependencies\premake\premake5.exe vs2022
PAUSE