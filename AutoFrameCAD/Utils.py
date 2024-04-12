import json
import logging
import re
from io import BytesIO
from pathlib import Path
from tkinter import filedialog

import cairosvg  # type: ignore
from PIL import Image, ImageTk


class Utils:
    """A class that contains utility functions."""

    @staticmethod
    def _sanitizer(value: str) -> str:
        """Sanitizes a string.

        Args:
            value (str): The string to be sanitized.
        """
        return (re.sub(r"\W+", "_", value)).lower()

    sanitizer = _sanitizer

    @staticmethod
    def _get_sql_type(value: int | float | str | bytes | None) -> str:
        """Gets the sql type of a value.

        Args:
            value (int | float | str | bytes | None): The value to be checked.
        """
        return {
            int: "INTEGER",
            float: "REAL",
            str: "TEXT",
            bytes: "BLOB",
            type(None): "NULL",
        }.get(type(value), "NULL")

    get_sql_type = _get_sql_type

    @staticmethod
    def _import_json(
        initialdir: Path = Path.home(),
    ) -> dict[str, list[dict[str, int | float | str | bytes | None]]] | None:
        """Loads a JSON file.

        Args:
            initialdir (Path): The initial directory to use.
        """
        with open(
            filedialog.askopenfilename(
                initialdir=initialdir, filetypes=[("JSON files", "*.json")]
            ),
            "r",
        ) as file:
            return json.load(file) or None

    import_json = _import_json

    # NOTE: Adjust when tk 8.7/9.0 is released,
    # since it will have native svg support.
    @staticmethod
    def _svg2png(path: str) -> ImageTk.PhotoImage:
        """Convert a svg to a photoimage.

        Args:
            path (str): The file path name to use.
        """
        return ImageTk.PhotoImage(
            Image.open(BytesIO(cairosvg.svg2png(url=path)))  # type: ignore
        )

    svg2png = _svg2png

    @staticmethod
    def _logger(level: int = logging.INFO) -> logging.Logger:
        """Get the logger.

        Args:
            level (int): The logging level."""
        logging.basicConfig(level=level)
        return logging.getLogger(__name__)

    logger = _logger
