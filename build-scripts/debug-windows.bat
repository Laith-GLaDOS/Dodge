@echo off
gcc .\src\main.c -o .\bin\debug\dodge.exe -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer && cd .\bin\debug\ && .\dodge.exe && cd ..\..\