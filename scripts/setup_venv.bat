@echo off

if not exist .\.venv (
    echo Installing Virtual Environment...
    python -m venv .venv
    echo Virtual Environment installation complete!
) else (
    echo Virtual Environment is already set up.
)
