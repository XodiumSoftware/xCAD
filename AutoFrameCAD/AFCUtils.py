import json
import re
from tkinter import filedialog


class Utils:
    """A class that contains utility functions."""

    @staticmethod
    def sanitize_str(value: str) -> str:
        """Sanitizes a string.

        Args:
            value (str): The string to be sanitized.
        """
        return (re.sub(r'\W+', '_', value)).lower()

    @staticmethod
    def get_sql_type(value: int | float | str | bytes | None) -> str:
        """Gets the sql type of a value.

        Args:
            value (int | float | str | bytes): The value to be checked.
        """
        if value is None:
            return 'NULL'
        return {
            int: 'INTEGER',
            float: 'REAL',
            str: 'TEXT',
            bytes: 'BLOB',
        }.get(type(value), 'NULL')

    @staticmethod
    def load_json():
        """Loads a json file."""
        filename = filedialog.askopenfilename(
            filetypes=[('JSON files', '*.json')]
        )
        if filename:
            with open(filename, 'r') as f:
                data = json.load(f)
            return data
