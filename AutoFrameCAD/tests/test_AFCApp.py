import unittest
from tkinter import Tk
from unittest.mock import MagicMock

from AFCApp import App


class TestApp(unittest.TestCase):
    def test_init_runs_mainloop_for_each_module(self):
        # Arrange
        modules = [MagicMock(spec=Tk), MagicMock(spec=Tk), MagicMock(spec=Tk)]
        app = App(modules)

        # Act
        app.__init__(modules)

        # Assert
        for module in modules:
            module.mainloop.assert_called_once()

    def test_init_exits_application(self):
        # Arrange
        modules = [MagicMock(), MagicMock(), MagicMock()]
        app = App(modules)

        # Act
        with self.assertRaises(SystemExit):
            app.__init__(modules)


if __name__ == '__main__':
    unittest.main()
