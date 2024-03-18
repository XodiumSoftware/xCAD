import tkinter as tk
import tkinter.ttk as ttk
import unittest
from unittest.mock import MagicMock

import numpy as np
import sv_ttk
from AFCHandlers import UIHandler


class TestUIHandler(unittest.TestCase):
    def setUp(self):
        self.ui_handler = UIHandler()

    def test_theme_sets_ttk_theme(self):
        # Arrange
        theme = 'default'

        # Act
        self.ui_handler.theme(theme)

        # Assert
        sv_ttk.set_theme.assert_called_once_with(theme)

    def test_visible_shows_ui(self):
        # Arrange
        self.ui_handler.withdraw = MagicMock()

        # Act
        self.ui_handler.visible(True)

        # Assert
        self.ui_handler.deiconify.assert_called_once()
        self.ui_handler.withdraw.assert_not_called()

    def test_visible_hides_ui(self):
        # Arrange
        self.ui_handler.deiconify = MagicMock()

        # Act
        self.ui_handler.visible(False)

        # Assert
        self.ui_handler.withdraw.assert_called_once()
        self.ui_handler.deiconify.assert_not_called()

    def test_events_binds_events(self):
        # Arrange
        events = ['<Button-1>', '<Button-2>']

        # Act
        self.ui_handler.events(events)

        # Assert
        for event in events:
            self.ui_handler.bind.assert_any_call(event, unittest.mock.ANY)

    def test_matrix_creates_widgets(self):
        # Arrange
        matrix = np.array([[1, 2], [3, 4]])

        # Act
        self.ui_handler.matrix(matrix)

        # Assert
        for (i, j), value in np.ndenumerate(matrix):
            if not isinstance(value, ttk.Widget):
                ttk.Frame.assert_called_with(self.ui_handler)
            self.ui_handler.grid.assert_called_with(
                row=i, column=j, sticky=tk.NSEW
            )
            self.ui_handler.rowconfigure.assert_called_with(i, weight=1)
            self.ui_handler.columnconfigure.assert_called_with(j, weight=1)


if __name__ == '__main__':
    unittest.main()
