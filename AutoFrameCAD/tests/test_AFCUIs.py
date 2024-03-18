import unittest
from tkinter import ttk
from unittest.mock import MagicMock

import numpy as np
import sv_ttk
from AFCUIs import PrimaryUI


class TestPrimaryUI(unittest.TestCase):
    def setUp(self):
        self.primary_ui = PrimaryUI()

    def test_title_sets_title(self):
        # Arrange
        title = 'AutoFrameCAD'

        # Act
        self.primary_ui.title(title)

        # Assert
        self.assertEqual(self.primary_ui.title(), title)

    def test_theme_sets_ttk_theme(self):
        # Arrange
        theme = 'default'

        # Act
        self.primary_ui.theme(theme)

        # Assert
        sv_ttk.set_theme.assert_called_once_with(theme)

    def test_visible_shows_ui(self):
        # Arrange
        self.primary_ui.withdraw = MagicMock()

        # Act
        self.primary_ui.visible(True)

        # Assert
        self.primary_ui.deiconify.assert_called_once()
        self.primary_ui.withdraw.assert_not_called()

    def test_visible_hides_ui(self):
        # Arrange
        self.primary_ui.deiconify = MagicMock()

        # Act
        self.primary_ui.visible(False)

        # Assert
        self.primary_ui.withdraw.assert_called_once()
        self.primary_ui.deiconify.assert_not_called()

    def test_resizable_sets_resizable(self):
        # Arrange
        resizable = (True, True)

        # Act
        self.primary_ui.resizable(*resizable)

        # Assert
        self.assertEqual(self.primary_ui.resizable(), resizable)

    def test_iconphoto_sets_iconphoto(self):
        # Arrange
        icon = 'icon.png'

        # Act
        self.primary_ui.iconphoto(icon)

        # Assert
        self.assertEqual(self.primary_ui.iconphoto(), icon)

    def test_geometry_sets_geometry(self):
        # Arrange
        geometry = '800x600'

        # Act
        self.primary_ui.geometry(geometry)

        # Assert
        self.assertEqual(self.primary_ui.geometry(), geometry)

    def test_minsize_sets_minsize(self):
        # Arrange
        width = 800
        height = 600

        # Act
        self.primary_ui.minsize(width, height)

        # Assert
        self.assertEqual(self.primary_ui.minsize(), (width, height))

    def test_events_binds_events(self):
        # Arrange
        events = ['<Button-1>', '<Button-2>']

        # Act
        self.primary_ui.events(events)

        # Assert
        for event in events:
            self.primary_ui.bind.assert_any_call(event, unittest.mock.ANY)

    def test_matrix_creates_widgets(self):
        # Arrange
        matrix = np.array([[1, 2], [3, 4]])

        # Act
        self.primary_ui.matrix(matrix)

        # Assert
        for (i, j), value in np.ndenumerate(matrix):
            if not isinstance(value, ttk.Widget):
                ttk.Frame.assert_called_with(self.primary_ui)
            self.primary_ui.grid.assert_called_with(
                row=i, column=j, sticky=tk.NSEW
            )
            self.primary_ui.rowconfigure.assert_called_with(i, weight=1)
            self.primary_ui.columnconfigure.assert_called_with(j, weight=1)


if __name__ == '__main__':
    unittest.main()
