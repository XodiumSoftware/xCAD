import unittest
from pathlib import Path

import AFCConstants


class TestAFCConstants(unittest.TestCase):
    def setUp(self):
        self.test_cases = {
            "database_path": Path(
                "/workspaces/AutoFrameCAD/AutoFrameCAD/db/AFCDatabase.sqlite"
            ),
            "ui_icon_path": Path(
                "/workspaces/AutoFrameCAD/AutoFrameCAD/icons/ui.svg"
            ),
        }

    def test_paths(self):
        for attr, expected_path in self.test_cases.items():
            with self.subTest(attr=attr):
                self.assertEqual(
                    getattr(AFCConstants, attr.upper()), expected_path
                )


if __name__ == "__main__":
    unittest.main()
