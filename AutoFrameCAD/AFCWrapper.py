import ctypes
from typing import Callable


class Wrapper:
    """A wrapper class for interacting with a C++ library."""

    # TODO: Replace the path to the C++ library.
    cpp_lib = ctypes.CDLL('path/to/your/cpp/library.so')
    cpp_lib.cpp_add.argtypes = [ctypes.c_int, ctypes.c_int]
    cpp_lib.cpp_add.restype = ctypes.c_int
    cpp_lib.cpp_get_string.restype = ctypes.c_char_p
    cpp_lib.cpp_print_string.argtypes = [ctypes.c_char_p]
    callback_func = ctypes.CFUNCTYPE(None)

    def cpp_function(self) -> None:
        """Calls a C++ function."""
        self.cpp_lib.cpp_function()

    def cpp_add(self, a: int, b: int) -> int:
        """Adds two integers using a C++ function.

        Args:
            a (int): The first integer.
            b (int): The second integer.
        """
        return self.cpp_lib.cpp_add(a, b)

    def cpp_get_string(self) -> str:
        """Retrieves a string from a C++ function."""
        return self.cpp_lib.cpp_get_string().decode('utf-8')

    def cpp_print_string(self, string: str) -> None:
        """Prints a string using a C++ function.

        Args:
            string (str): The string to be printed.
        """
        self.cpp_lib.cpp_print_string(ctypes.c_char_p(string.encode('utf-8')))

    def cpp_set_callback(self, callback: Callable[[], None]) -> None:
        """Sets a callback function to be called by a C++ function.

        Args:
            callback (Callable[[], None]): The callback function.
        """
        self.cpp_lib.cpp_set_callback.argtypes = [self.callback_func]
        self.cpp_lib.cpp_set_callback(callback)
