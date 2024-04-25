"""This module contains the wrapper class."""

import ctypes
from collections.abc import Callable
from pathlib import Path
from typing import Any


class Wrapper:
    """A class that contains wrapper functions."""

    def __init__(self: "Wrapper", path: Path) -> None:
        """Initializes the .so library.

        Args:
            path (Path): The path to the .so library.

        Returns:
            None

        Raises:
            OSError: If the .so library could not be initialized.
        """
        try:
            self.lib = ctypes.CDLL(f"{path}")
        except OSError as e:
            error_msg = (
                f"Failed to initialize .so library: {path}. Error: {e!s}"
            )
            raise OSError(error_msg) from e

    def __getattr__(self: "Wrapper", func: str) -> Callable[..., Any]:
        """Gets the function from the library.

        Args:
            func (str): The name of the function.

        Returns:
            Callable[..., Any]: The function.

        Raises:
            AttributeError: If the function could not be found.
        """
        try:
            if isinstance(getattr(self.lib, func), ctypes._CFuncPtr):  # type: ignore[attr] # noqa: SLF001
                return getattr(self.lib, func)
        except AttributeError as e:
            error_msg = f"Failed to get function: {func}. Error: {e!s}"
            raise AttributeError(error_msg) from e
        return self.__getattr__(func)

    def __dir__(self: "Wrapper") -> list[str]:
        """Gets the functions in the library.

        Args:
            None

        Returns:
            list[str]: The functions in the library.

        Raises:
            Exception: If the functions could not be retrieved.
        """
        try:
            return [
                x
                for x in self.lib.__dict__
                if isinstance(getattr(self.lib, x), ctypes._CFuncPtr)  # type: ignore[attr] # noqa: SLF001
            ]
        except AttributeError as e:
            error_msg = f"Failed to get functions: {e!s}"
            raise AttributeError(error_msg) from e
