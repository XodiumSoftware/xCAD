import ctypes

from AFCConstants import LIB_FOLDER_PATH


class Wrapper:
    """A class to wrap C functions"""

    def __init__(self):
        """Initializes the C library"""
        self.lib = ctypes.CDLL(f"{LIB_FOLDER_PATH}/AFCUtils.so")
        (
            self.factorial,
            self.sumArray,
            self.isPalindrome,
            self.isPrime,
            self.maxArray,
            self.minArray,
            self.reverseString,
        ) = (
            self.lib.factorial,
            self.lib.sumArray,
            self.lib.isPalindrome,
            self.lib.isPrime,
            self.lib.maxArray,
            self.lib.minArray,
            self.lib.reverseString,
        )
        (
            self.factorial.argtypes,
            self.sumArray.argtypes,
            self.isPalindrome.argtypes,
            self.isPrime.argtypes,
            self.maxArray.argtypes,
            self.minArray.argtypes,
            self.reverseString.argtypes,
        ) = (
            [ctypes.c_int],
            [ctypes.POINTER(ctypes.c_int), ctypes.c_int],
            [ctypes.c_char_p],
            [ctypes.c_int],
            [ctypes.POINTER(ctypes.c_int), ctypes.c_int],
            [ctypes.POINTER(ctypes.c_int), ctypes.c_int],
            [ctypes.c_char_p],
        )
        (
            self.factorial.restype,
            self.sumArray.restype,
            self.isPalindrome.restype,
            self.isPrime.restype,
            self.maxArray.restype,
            self.minArray.restype,
            self.reverseString.restype,
        ) = (
            ctypes.c_int,
            ctypes.c_int,
            ctypes.c_bool,
            ctypes.c_bool,
            ctypes.c_int,
            ctypes.c_int,
            ctypes.c_char_p,
        )
