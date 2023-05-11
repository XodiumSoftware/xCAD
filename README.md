# BriscCAD plug-in

GUI window for creating basic objects in BriscCad (e.g. walls)

# Installation

1. `python -m venv env` (creates environment for packages)
2. select the correct interpreter (env)
3. `pip install -e .`

# Running the software

To run the command window, use the following command on terminal: brisc

# Important 

- Files named `__init__.py` are a special type of file that tells python that a specfic directory is a module. These files are required for accessing all python modules from anywhere.

- setup.cfg file creates the `BriscCad` library and sets up the `brisc` command (to import a module from the library use `from bbc.--- import ---`)