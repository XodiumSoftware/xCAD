# AutoFrameCAD

A BricsCAD plug-in which includes GUI for creating basic objects (e.g. walls)

# Installation:

1. `python -m venv env` (creates environment for packages)
2. select the correct interpreter (`env`)
3. `pip install -e .`

# Running the software:

To run the command window, use the following command on terminal: `brics`

# Important:

- Files named `__init__.py` are a special type of file that tells python that a specfic directory is a module. These files are required for accessing all python modules from anywhere.

- setup.cfg file creates the `BricsCad` library and sets up the `brics` command (to import a module from the library use `from bbc.[module] import [function]`) replace `[module]` & `[function]` with the name of the module and function.

# To read the library docs:

This ensures that the css files run and the docs are readable.

1. Install `XAMPP`
2. Start action on `Apache` module
3. Click on Explorer and go to `OS\XAMPP\htdocs`
4. Move there a copy of the folder you wanna read (`docs`)
5. Double click on `Admin` to open `localhost\dashboard`
6. Rename the address in the address bar to `localhost\[name of the folder]` (localhost\docs)

# To cythonize code:

Run the following cmd:

1. python setup.py build_ext --inplace
