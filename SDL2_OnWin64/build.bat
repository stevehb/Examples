@echo off
cl simple.cpp /I .\SDL2-2.0.4\include /link /SUBSYSTEM:CONSOLE /LIBPATH:SDL2-2.0.4\lib\x64 SDL2.lib SDL2main.lib
