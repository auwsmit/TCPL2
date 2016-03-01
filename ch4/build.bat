@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64
mkdir build
pushd build
cl /FC /Zi %1 user32.lib Gdi32.lib
popd
