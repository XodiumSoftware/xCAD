import json
import re
from pathlib import Path
from tkinter import filedialog

from AFCDecorators import ErrorHandler as AFCErrorHandler


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
    def import_json():
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
