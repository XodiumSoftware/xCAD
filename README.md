# Welcome to:

<p align="center">
  <a href="https://illyrius.me/AutoFrameCAD">
    <img src="https://github.com/illyrius666/illyrius666/blob/master/images/AutoFrameCAD.png" alt="AutoFrameCAD">
  </a>
</p>
<p align="center">
  <a href="https://app.deepsource.com/gh/illyrius666/AutoFrameCAD/">
    <img src="https://app.deepsource.com/gh/Structura-Engineering/AutoFrameCAD.svg/?label=active+issues&show_trend=true&token=6a6PKnYxd3B1-AhQ2dLn8MoS" alt="DeepSource">
    <img src="https://app.deepsource.com/gh/Structura-Engineering/AutoFrameCAD.svg/?label=resolved+issues&show_trend=true&token=6a6PKnYxd3B1-AhQ2dLn8MoS" alt="DeepSource">
  </a>
</p>

## Setup the environment:

1. `.\venv.bat` (Windows) or `./venv.sh` (Linux)
2. SET interpreter to `.venv\Scripts\python.exe` (Windows) or `.venv/bin/python` (Linux)

3. TO UPDATE: deactivate venv and revert interpreter back to local python installation, then follow steps 1 & 2 again.

## Running the software:

To run the command window, use the following cmd in the CAD software: `afc`

## Build package, Release on Github & Upload to (Test)PyPi:

1. FOR `TestPyPi`: In the push message use the keyword `.test .tag[x]`.
2. FOR `PyPi`: In the push message use the keyword `.deploy .tag[x]`.
