import unittest

from AutoFrameCAD.UIs import PrimaryUI


class TestPrimaryUI(unittest.TestCase):
    def setUp(self):
        self.primary_ui = PrimaryUI()

    def test_ui_settings(self):
        test_cases = [
            {
                "method": "resizable",
                "input": (True, True),
                "expected": (True, True),
            },
            {
                "method": "iconphoto",
                "input": (False, None, "icon.png"),
                "expected": "icon.png",
            },
            {"method": "geometry", "input": "800x600", "expected": "800x600"},
            {"method": "minsize", "input": (800, 600), "expected": (800, 600)},
        ]

        for test_case in test_cases:
            with self.subTest(test_case=test_case):
                method = getattr(self.primary_ui, test_case["method"])  # type: ignore
                result = method(
                    *test_case["input"]
                    if isinstance(test_case["input"], tuple)
                    else test_case["input"]
                )
                self.assertEqual(result, test_case["expected"])


if __name__ == "__main__":
    unittest.main()
