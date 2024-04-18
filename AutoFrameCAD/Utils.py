import logging
from io import BytesIO
from pathlib import Path

import cairosvg  # type: ignore
from PIL import Image, ImageTk


class Forge:
    """A class that contains forge functions."""

    @staticmethod
    def _forge_dir(
        path: Path,
        mode: int = 511,
        parents: bool = True,
        exist_ok: bool = True,
    ) -> Path:
        """Forge a directory if it does not exist."""
        return (
            path.mkdir(mode=mode, parents=parents, exist_ok=exist_ok) or path
        )

    dir = _forge_dir

    @staticmethod
    def _forge_file(
        path: Path, mode: int = 438, exist_ok: bool = True
    ) -> Path:
        """Forge a file if it does not exist."""
        return path.touch(mode=mode, exist_ok=exist_ok) or path

    file = _forge_file


class Utils:
    """A class that contains utility functions."""

    forge = Forge()

    # NOTE: Adjust when tk 8.7/9.0 is released,
    # since it will have native svg support.
    @staticmethod
    def _svg2png(path: Path) -> ImageTk.PhotoImage:
        """Convert a svg to a photoimage."""
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
