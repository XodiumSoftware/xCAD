from Cython.Build import cythonize
from setuptools import setup

if __name__ == "__main__":
    setup(
        ext_modules=cythonize("pline_cmd.py"),
    )
