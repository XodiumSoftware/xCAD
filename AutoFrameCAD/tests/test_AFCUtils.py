import unittest
from tkinter import filedialog
from unittest.mock import MagicMock

import cairosvg  # type: ignore
from AFCUtils import Utils
from PIL import Image, ImageTk


class TestUtils(unittest.TestCase):
    def test_sanitize_str(self):
        # Arrange
        value = 'Hello, World!'

        # Act
        result = Utils.sanitize_str(value)

        # Assert
        self.assertEqual(result, 'hello_world')

    def test_get_sql_type(self):
        # Arrange
        values = [10, 3.14, 'text', b'data', None]
        expected_types = ['INTEGER', 'REAL', 'TEXT', 'BLOB', 'NULL']

        # Act & Assert
        for value, expected_type in zip(values, expected_types):
            result = Utils.get_sql_type(value)
            self.assertEqual(result, expected_type)

    def test_import_json_with_file(self):
        # Arrange
        filedialog.askopenfilename = MagicMock(
            return_value='/path/to/file.json'
        )
        expected_data = {'key': 'value'}

        # Act
        result = Utils.import_json()

        # Assert
        self.assertEqual(result, expected_data)

    def test_import_json_without_file(self):
        # Arrange
        filedialog.askopenfilename = MagicMock(return_value='')

        # Act
        result = Utils.import_json()

        # Assert
        self.assertIsNone(result)

    def test_svg2png(self):
        # Arrange
        path = '/path/to/image.svg'
        ImageTk.PhotoImage = MagicMock()
        Image.open = MagicMock()
        cairosvg.svg2png = MagicMock(return_value=b'image_data')

        # Act
        result = Utils.svg2png(path)

        # Assert
        self.assertIsNotNone(result)
        ImageTk.PhotoImage.assert_called_once_with(Image.open())
        cairosvg.svg2png.assert_called_once_with(url=str(path))


if __name__ == '__main__':
    unittest.main()
