@echo off

REM Run the PackageSetup class from the setup script
python -c "from setup import VENVSetup; VENVSetup()"
