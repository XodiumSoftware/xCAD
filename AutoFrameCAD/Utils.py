import logging
from io import BytesIO

import cairosvg  # type: ignore
from PIL import Image, ImageTk


class Utils:
    """A class that contains utility functions."""

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
    def _logger(name: str) -> logging.Logger:
        """Set up a logger."""
        logger = logging.getLogger(name)
        logger.setLevel(logging.INFO)
        handler = logging.StreamHandler()
        formatter = logging.Formatter(
            "%(asctime)s - %(name)s - %(levelname)s - %(message)s"
        )
        handler.setFormatter(formatter)
        logger.addHandler(handler)
        return logger

    logger = _logger
