@echo off

REM Deactivate the virtual environment if it's active
deactivate 2>nul

REM Run the setup script
python setup.py

REM Activate the virtual environment
.venv\Scripts\activate
