@echo off

rem Check if .venv folder already exists
if exist .\.venv (
    echo Virtual Environment is already set up.
    goto end
)

echo Installing Virtual Environment...
python setup_venv.py
echo Virtual Environment installation complete!

:end