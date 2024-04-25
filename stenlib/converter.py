"""This module contains the Converter class."""

from io import BytesIO
from pathlib import Path

import cairosvg  # type: ignore[import]
from PIL import Image, ImageTk


class Converter:
    """A class that contains conversion functions."""

    # NOTE: Adjust when tk 8.7/9.0 is released,
    # since it will have native svg support.
    @staticmethod
    def _svg2png(path: Path) -> ImageTk.PhotoImage:
        """Convert a svg to a photoimage.

        Args:
            path (Path): The path to the svg.

        Returns:
            ImageTk.PhotoImage: The photoimage.

        Raises:
            OSError: If the svg could not be converted.
        """
        try:
            return ImageTk.PhotoImage(
                Image.open(BytesIO(cairosvg.svg2png(url=str(path)))),  # type: ignore[call-arg]
            )
        except Exception as e:  # noqa: BLE001
            error_msg = f"Failed to convert svg to png: {path}. Error: {e!s}"
            raise OSError(error_msg) from e

    svg2png = _svg2png
