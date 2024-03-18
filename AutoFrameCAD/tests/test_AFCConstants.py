import unittest
from pathlib import Path

from AFCConstants import DATABASE_PATH, UI_ICON_PATH


class TestAFCConstants(unittest.TestCase):
    def test_database_path(self):
        expected_path = Path(
            '/workspaces/AutoFrameCAD/AutoFrameCAD/db/AFCDatabase.sqlite'
        )
        self.assertEqual(DATABASE_PATH, expected_path)

    def test_ui_icon_path(self):
        expected_path = Path(
            '/workspaces/AutoFrameCAD/AutoFrameCAD/icons/ui.svg'
        )
        self.assertEqual(UI_ICON_PATH, expected_path)


if __name__ == '__main__':
    unittest.main()
