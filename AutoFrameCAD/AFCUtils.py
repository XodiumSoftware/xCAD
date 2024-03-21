import json
import re
from io import BytesIO
from pathlib import Path
from tkinter import filedialog

import cairosvg  # type: ignore
from AFCDecorators import ErrorHandler as AFCErrorHandler
from PIL import Image, ImageTk


class Utils:
    """A class that contains utility functions."""

    @staticmethod
    @AFCErrorHandler(TypeError)
    def sanitize_str(value: str) -> str:
        """Sanitizes a string.

        Args:
            value (str): The string to be sanitized.
        """
        return (re.sub(r'\W+', '_', value)).lower()

    @staticmethod
    @AFCErrorHandler(TypeError)
    def get_sql_type(value: int | float | str | bytes | None) -> str:
        """Gets the sql type of a value.

        Args:
            value (int | float | str | bytes | None): The value to be checked.
        """
        return {
            int: 'INTEGER',
            float: 'REAL',
            str: 'TEXT',
            bytes: 'BLOB',
            type(None): 'NULL',
        }.get(type(value), 'NULL')

    @staticmethod
    @AFCErrorHandler(FileNotFoundError, IOError)
    def import_json() -> (
        dict[str, list[dict[str, int | float | str | bytes | None]]] | None
    ):
        """Loads a json file."""
        filename = filedialog.askopenfilename(
            initialdir=Path.home(),
            filetypes=[('JSON files', '*.json')],
        )
        if filename:
            with open(filename, 'r') as file:
                return json.load(file)
        else:
            return None

    # NOTE: Adjust when tk 8.7/9.0 is released,
    # since it will have native svg support.
    @staticmethod
    @AFCErrorHandler(TypeError)
    def svg2png(path: Path) -> ImageTk.PhotoImage:
        """Convert a svg to a photoimage.

        Args:
            path (Path): The file path name to use.
        """
        return ImageTk.PhotoImage(
            Image.open(BytesIO(cairosvg.svg2png(url=str(path))))  # type: ignore
        )
