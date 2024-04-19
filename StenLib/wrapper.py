import ctypes
from pathlib import Path
from typing import Any


class Wrapper:
    """A class that contains wrapper functions."""

    def __init__(self, path: Path) -> None:
        """Initializes the .so library.

        Args:
            path (Path): The path to the .so library.
        """
        self.lib = ctypes.CDLL(f"{path}")

    def __getattr__(self, func: str) -> Any:
        """Gets the function from the library.

        Args:
            func (str): The name of the function.

        Returns:
            Any: The function.
        """
        try:
            if isinstance(getattr(self.lib, func), ctypes._CFuncPtr):  # type: ignore
                return getattr(self.lib, func)
        except Exception:
            raise AttributeError(f"No function named {func} in the library")

    def __dir__(self) -> list[str]:
        """Gets the functions in the library.

        Returns:
            list[str]: The functions in the library.
        """
        return [
            x
            for x in self.lib.__dict__.keys()
            if isinstance(getattr(self.lib, x), ctypes._CFuncPtr)  # type: ignore
        ]
