@echo off
cd %~dp0

echo Running setup_venv.bat...
call .\scripts\setup_venv.bat
if errorlevel 1 (
    echo An error occurred during virtual environment setup.
    exit /b
)

pause

echo Running setup_msys2.bat...
call .\scripts\setup_msys2.bat
if errorlevel 1 (
    echo An error occurred during MSYS2 setup.
    exit /b
)

echo Setup complete!
pause
cls