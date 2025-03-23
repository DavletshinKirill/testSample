@echo off
g++ --version >nul 2>&1
if errorlevel 1 (
    echo g++ is not installed. Please install it and add it to your PATH.
    exit /b 1
)

if not exist "./bin" (
    mkdir "./bin"
)

g++ -O2 ./src/main.cpp -o ./bin/main.exe

if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)

echo Compilation successful. You can run the program with .\bin\main.exe
