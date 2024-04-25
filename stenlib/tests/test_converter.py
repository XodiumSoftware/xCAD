"""This module contains unit tests for the Converter class."""

import unittest
from io import BytesIO
from pathlib import Path
from unittest.mock import MagicMock, patch

from PIL import Image, ImageTk

from stenlib.converter import Converter


class ImageOpenMockCallError(AssertionError):
    """Raised when the call argument doesn't match expected value."""

    def __init__(self: "ImageOpenMockCallError") -> None:
        """Initialize the ImageOpenMockCallError class."""
        super().__init__(
            "image_open_mock call argument does not match expected value",
        )


class ResultNotEqualToImageTkMockError(AssertionError):
    """Raised when the result is not equal to self.image_tk_mock."""

    def __init__(self: "ResultNotEqualToImageTkMockError") -> None:
        """Initialize the ResultNotEqualToImageTkMockError class."""
        super().__init__("result is not equal to self.image_tk_mock")


class TestConverter(unittest.TestCase):
    """A class to test the Converter class."""

    @classmethod
    def setUpClass(cls: type["TestConverter"]) -> None:
        """Sets up the test."""
        cls.path = MagicMock(spec=Path)
        cls.image_mock = MagicMock(spec=Image.Image)
        cls.bytes_io_instance = BytesIO(b"png_data")
        cls.bytes_io_mock = MagicMock(
            spec=BytesIO,
            return_value=cls.bytes_io_instance,
        )
        cls.image_open_mock = MagicMock(return_value=cls.image_mock)
        cls.image_tk_mock = MagicMock(spec=ImageTk.PhotoImage)
        cls.image_tk_mock.return_value = cls.image_tk_mock

    def test_svg2png(self: "TestConverter") -> None:
        """Tests the svg2png method."""
        with (
            patch("PIL.Image.open", self.image_open_mock),
            patch("PIL.ImageTk.PhotoImage", self.image_tk_mock),
            patch(
                "cairosvg.svg2png",
                return_value=self.bytes_io_instance.getvalue(),
            ) as svg2png_mock,
        ):
            converter = Converter()
            result = converter.svg2png(self.path)

            self.image_open_mock.assert_called_once()
            if (
                self.image_open_mock.call_args[0][0].getvalue()
                != self.bytes_io_instance.getvalue()
            ):
                raise ImageOpenMockCallError

            svg2png_mock.assert_called_once_with(url=str(self.path))
            self.image_tk_mock.assert_called_once_with(self.image_mock)

            if result is not self.image_tk_mock:
                raise ResultNotEqualToImageTkMockError
