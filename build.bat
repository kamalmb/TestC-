@echo off
setlocal

echo Compiling Word.cpp...
g++ -c -w Word.cpp -o Word.o

echo Compiling main.cpp...
g++ -c -w main.cpp -o main.o

echo Linking object files...
g++ -o myOutput.exe main.o Word.o

echo Build complete.

endlocal
