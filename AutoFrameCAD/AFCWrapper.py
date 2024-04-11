import ctypes

from AFCConstants import LIB_FOLDER_PATH


class Wrapper:
    """A class to wrap C++ functions"""

    def __init__(self):
        """Initializes the C++ library"""
        self.lib = ctypes.CDLL(f"{LIB_FOLDER_PATH}/AFCExample.so")
        self.factorial = self.lib.factorial
        self.factorial.argtypes = [ctypes.c_int]
        self.factorial.restype = ctypes.c_int
