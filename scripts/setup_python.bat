@echo off

where python >nul 2>nul
if %errorlevel% neq 0 (
    echo Python is not installed. Installing Python...
    powershell -Command "& {Invoke-WebRequest https://www.python.org/ftp/python/3.9.7/python-3.9.7-amd64.exe -OutFile python-installer.exe}"
    start /wait python-installer.exe /quiet InstallAllUsers=1 PrependPath=1 Include_test=0
    del python-installer.exe
    echo Python installation complete!
) else (
    echo Python is already installed.
)