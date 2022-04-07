# Dodge!  
A game made in SDL2 and C  
Basically, you play as a circle, and you have to move it from the lasers, if it gets hit by a laser, it explodes and you have to replay.  
This game has no levels, its just endless survival, and before the lasers fire, there will be a warning sign on where they will fire.  
The lasers fire more quickly and more of them start appearing as time passes.  
Your high score is basically how many waves of lasers you survived.  
  
# Building documentation:  
### Linux:  
First, make sure you have `gcc` and `git` installed, then do these commands:
```bash
git clone https://github.com/Laith-GLaDOS/Dodge.git
cd Dodge
chmod +x ./build-scripts/*
./build-scripts/release-linux
```
  
And you will have your output in `bin/release/linux/dodge`  
If you want to debug (aka build without stripping symbols and optimisation then run the game automatically), do `./build-scripts/debug-linux` instead  
  
### Windows:  
First, make sure you have MinGW and `gcc` installed using MinGW, many tutorials out there exist for this.  
Then, download the source code of this repo.  
Then finally, open a command prompt and `cd (path to the downloaded folder)` and do `.\build-scripts\release-windows.bat`
And you will have your output in `bin\release\windows\dodge.exe`  
If you want to debug (aka build without stripping symbols and optimisation then run the game automatically), do `.\build-scripts\debug-windows.bat` instead
  
# Notes:  
 - This is just a project for fun, no serious business here or something.  
 - Feel free to contribute.