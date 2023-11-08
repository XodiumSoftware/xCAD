@echo off

rem Check if MSYS2 is already installed
if exist C:\msys64 (
    echo MSYS2 is already installed.
    pause
    goto gcc_install
)

echo Installing MSYS2...
curl -O "https://repo.msys2.org/distrib/x86_64/msys2-x86_64-latest.exe"
msys2-x86_64-latest.exe /S
echo MSYS2 installation complete!

:gcc_install

echo Checking if mingw-w64-ucrt-x86_64-gcc is installed...
call C:\msys64\msys2_shell.cmd -mingw64 -no-start -defterm -here -c "pacman -Q mingw-w64-ucrt-x86_64-gcc"
if errorlevel 1 (
    echo Installing mingw-w64-ucrt-x86_64-gcc...
    call C:\msys64\msys2_shell.cmd -mingw64 -no-start -defterm -here -c "pacman -S mingw-w64-ucrt-x86_64-gcc"
    echo mingw-w64-ucrt-x86_64-gcc installation complete!
) else (
    echo mingw-w64-ucrt-x86_64-gcc is already installed.
)

:end