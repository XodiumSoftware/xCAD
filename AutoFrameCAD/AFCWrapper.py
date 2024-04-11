import ctypes


class Wrapper:
    """A class to wrap C++ functions"""

    def __init__(self):
        """Initializes the C++ library"""
        self.lib = ctypes.CDLL("AutoFrameCAD/build/example.so")
        self.my_function = self.lib.my_function
        self.my_function.argtypes = [ctypes.c_int]
        self.my_function.restype = ctypes.c_int
