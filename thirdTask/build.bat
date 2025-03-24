@echo off
g++ --version >nul 2>&1
if errorlevel 1 (
    echo g++ is not installed. Please install it and add it to your PATH.
    exit /b 1
)

if not exist "./bin" (
    mkdir "./bin"
)

g++ -O2 .\src\client_starter.cpp -o .\bin\client_starter.exe -lws2_32
g++ -O2 .\src\server_starter.cpp -o .\bin\server_starter.exe -lws2_32

if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)

echo Compilation successful. You can run the programs with .\bin\server_starter.exe and .\bin\client_starter.exe
