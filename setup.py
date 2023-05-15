from Cython.Build import cythonize
from setuptools import setup

setup(
    ext_modules=cythonize("pline_cmd.py"),
)

if __name__ == "__main__":
    setup()
