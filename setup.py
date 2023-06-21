from distutils.extension import Extension

from Cython.Build import cythonize
from setuptools import setup

ext_modules = [
    Extension(
        "afc",
        sources=["bbc/*/*.pyx"],
        libraries=["bbc/libs/bricscad/*.lib"],
        library_dirs=["bbc/libs/bricscad/"],
        include_dirs=["bbc/libs/BRXSDK_Bcad_V23_2_03/inc/"],
    )
]
if __name__ == "__main__":
    setup(ext_modules=cythonize(ext_modules))
