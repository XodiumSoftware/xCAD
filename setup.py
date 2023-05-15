from Cython.Build import cythonize
from setuptools import setup

if __name__ == "__main__":
    setup(
        # Add the files in here otherwise it wont be loaded.
        ext_modules=cythonize("pline_cmd.pyx"),
    )
