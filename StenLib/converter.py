from io import BytesIO
from pathlib import Path

import cairosvg  # type: ignore
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
        """
        return ImageTk.PhotoImage(
            Image.open(BytesIO(cairosvg.svg2png(url=str(path))))  # type: ignore
        )

    svg2png = _svg2png
