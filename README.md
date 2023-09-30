# Welcome to:

<p align="center">
  <a href="https://illyrius.me/AutoFrameCAD">
    <img src="https://github.com/illyrius666/illyrius666/blob/master/images/AutoFrameCAD.png" alt="AutoFrameCAD">
  </a>
</p>
<p align="center">
  <a href="https://app.deepsource.com/gh/illyrius666/AutoFrameCAD/?ref=repository-badge}">
    <img src="https://app.deepsource.com/gh/illyrius666/AutoFrameCAD.svg/?label=active+issues&show_trend=true&token=gg3m5X6BzRWozQJG-KF3tijs" alt="DeepSource">
    <img src="https://app.deepsource.com/gh/illyrius666/AutoFrameCAD.svg/?label=resolved+issues&show_trend=true&token=gg3m5X6BzRWozQJG-KF3tijs" alt="DeepSource">
  </a>
</p>

## Virtual Environment Setup:

1. `python -m venv .venv` (creates environment for packages).
2. select the correct interpreter (`.venv`).
3. activate the environment. `./.venv/Scripts/activate` (Windows) or source `./.venv/bin/activate` (Linux).
4. `python -m pip install -e .`.

## Running the software:

To run the command window, use the following cmd in the CAD software: `afc`

## Installing QeLib:

1. `pyhton -m pip install -i https://test.pypi.org/simple/ QeLib`

## Build package, Release on Github & Upload to TestPyPi:

1. In the push message use the keyword `.deploy`.
