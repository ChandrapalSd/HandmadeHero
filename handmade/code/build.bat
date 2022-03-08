@REM "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvarsall.bat" x86_amd64
@echo off

IF NOT EXIST ..\..\build mkdir ..\..\build
pushd ..\..\build
cl -MT -nologo -Gm- -GR- -EHa- -Od -Oi -WX -W4 -wd4201 -wd4100 -wd4189 -DHANDMADE_INTERNAL=1 -DHANDMADE_SLOW=1 -DHANDMADE_WIN32=1 -FC -Z7 -Fmwin32_handmade.map ..\handmade\code\win32_handmade.cpp /link -opt:ref -subsystem:windows user32.lib gdi32.lib 
popd
