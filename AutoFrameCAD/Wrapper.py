import ctypes
from typing import Any

from Constants import LIB_FOLDER_PATH


class Wrapper:
    """A class to wrap C functions."""

    def __init__(self):
        """Initializes the C library."""
        self.lib = ctypes.CDLL(f"{LIB_FOLDER_PATH}/Utils.so")

        funcs = {
            "factorial": ([ctypes.c_int], ctypes.c_int),
            "sumArray": (
                [ctypes.POINTER(ctypes.c_int), ctypes.c_int],
                ctypes.c_int,
            ),
            "isPalindrome": ([ctypes.c_char_p], ctypes.c_bool),
            "isPrime": ([ctypes.c_int], ctypes.c_bool),
            "maxArray": (
                [ctypes.POINTER(ctypes.c_int), ctypes.c_int],
                ctypes.c_int,
            ),
            "minArray": (
                [ctypes.POINTER(ctypes.c_int), ctypes.c_int],
                ctypes.c_int,
            ),
        }

        self.functions = {f: self.set_func(f, *funcs[f]) for f in funcs}

    def _set_func(
        self, func_name: str, argtypes: list[Any], restype: Any
    ) -> Any:
        """Sets the function signature.

        Args:
            func_name (str): The name of the function.
            argtypes (list): The argument types.
            restype (Any): The return type.
        """
        func = getattr(self.lib, func_name)
        func.argtypes, func.restype = argtypes, restype
        return func

    set_func = _set_func

    def test(self, use: bool = True) -> None:
        """Tests the C functions.

        Args:
            use (bool): If True, the functions will be tested.
                defaults to True.
        """
        if not use:
            return
        else:
            prefix = "[TEST]"
            list = range(0, 5)
            arr = (ctypes.c_int * len(list))(*list)
            for func_name, func in self.functions.items():
                try:
                    if func_name in ["sumArray", "maxArray", "minArray"]:
                        print(f"{prefix} {func_name}: {func(arr, len(list))}")
                    elif func_name == "isPalindrome":
                        print(f"{prefix} {func_name}: {func(b'racecar')}")
                    elif func_name in ["factorial", "isPrime"]:
                        print(f"{prefix} {func_name}: {func(5)}")
                    print(f"{prefix} {func_name} tested successfully")
                except Exception as e:
                    print(f"[ERROR] Failed to test {func_name}")
                    print(f"[ERROR] {e}")
