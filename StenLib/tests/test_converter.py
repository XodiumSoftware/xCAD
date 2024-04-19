import unittest
from io import BytesIO
from pathlib import Path
from unittest.mock import MagicMock, patch

from PIL import Image, ImageTk

from StenLib.converter import Converter


class TestConverter(unittest.TestCase):
    """A class to test the Converter class"""

    @classmethod
    def setUpClass(cls) -> None:
        """Sets up the test"""
        cls.path = MagicMock(spec=Path)
        cls.image_mock = MagicMock(spec=Image.Image)
        cls.bytes_io_instance = BytesIO(b"png_data")
        cls.bytes_io_mock = MagicMock(
            spec=BytesIO, return_value=cls.bytes_io_instance
        )
        cls.image_open_mock = MagicMock(return_value=cls.image_mock)
        cls.image_tk_mock = MagicMock(spec=ImageTk.PhotoImage)
        cls.image_tk_mock.return_value = cls.image_tk_mock

    def test_svg2png(self) -> None:
        """Tests the svg2png method"""
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
            self.assertEqual(
                self.image_open_mock.call_args[0][0].getvalue(),
                self.bytes_io_instance.getvalue(),
            )
            svg2png_mock.assert_called_once_with(url=str(self.path))
            self.image_tk_mock.assert_called_once_with(self.image_mock)

            self.assertIs(result, self.image_tk_mock)
