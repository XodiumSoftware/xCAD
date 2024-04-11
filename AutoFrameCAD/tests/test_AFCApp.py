import unittest
from tkinter import Tk
from unittest.mock import create_autospec

from ..AFCApp import App


class TestApp(unittest.TestCase):
    def setUp(self):
        self.modules = [
            create_autospec(Tk),
            create_autospec(Tk),
            create_autospec(Tk),
        ]
        self.app = App(self.modules)

    def test_mainloop_runs_for_each_module_on_initialization(self):
        for module in self.modules:
            module.mainloop.assert_called_once()

    def test_initialization_exits_application(self):
        with self.assertRaises(SystemExit):
            App(self.modules)


if __name__ == "__main__":
    unittest.main()
