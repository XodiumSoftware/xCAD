import unittest
from tkinter import filedialog
from unittest.mock import MagicMock

import cairosvg  # type: ignore
from AFCUtils import Utils
from PIL import Image, ImageTk


class TestUtils(unittest.TestCase):
    def setUp(self):
        self.utils = Utils()

    def test_sanitize_str(self):
        self.assertEqual(self.utils.sanitizer('Hello, World!'), 'hello_world')

    def test_get_sql_type(self):
        test_cases = [
            (10, 'INTEGER'),
            (3.14, 'REAL'),
            ('text', 'TEXT'),
            (b'data', 'BLOB'),
            (None, 'NULL'),
        ]

        for value, expected in test_cases:
            with self.subTest(value=value):
                self.assertEqual(self.utils.get_sql_type(value), expected)

    def test_import_json_with_file(self):
        filedialog.askopenfilename = MagicMock(
            return_value='/path/to/file.json'
        )
        self.assertEqual(self.utils.json_importer(), {'key': 'value'})

    def test_import_json_without_file(self):
        filedialog.askopenfilename = MagicMock(return_value='')
        self.assertIsNone(self.utils.json_importer())

    def test_svg2png(self):
        path = '/path/to/image.svg'
        ImageTk.PhotoImage = MagicMock()
        Image.open = MagicMock()
        cairosvg.svg2png = MagicMock(return_value=b'image_data')

        self.assertIsNotNone(self.utils.svg2png(path))
        ImageTk.PhotoImage.assert_called_once_with(Image.open())
        cairosvg.svg2png.assert_called_once_with(url=str(path))


if __name__ == '__main__':
    unittest.main()
