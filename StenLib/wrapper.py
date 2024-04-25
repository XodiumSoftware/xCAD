import ctypes
from pathlib import Path
from typing import Any


class Wrapper:
    """A class that contains wrapper functions."""

    def __init__(self, path: Path) -> None:
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
        except Exception as e:
            raise OSError(
                f"Failed to initialize .so library at {path}: {str(e)}"
            )

    def __getattr__(self, func: str) -> Any:
        """Gets the function from the library.

        Args:
            func (str): The name of the function.

        Returns:
            Any: The function.

        Raises:
            AttributeError: If the function could not be found.
        """
        try:
            if isinstance(getattr(self.lib, func), ctypes._CFuncPtr):  # type: ignore
                return getattr(self.lib, func)
        except Exception as e:
            raise AttributeError(
                f"Failed to get function {func} from library: {str(e)}"
            )

    def __dir__(self) -> list[str]:
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
                for x in self.lib.__dict__.keys()
                if isinstance(getattr(self.lib, x), ctypes._CFuncPtr)  # type: ignore
            ]
        except Exception as e:
            raise Exception(f"Failed to get functions from library: {str(e)}")
