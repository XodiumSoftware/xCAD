import tkinter as tk
import tkinter.ttk as ttk
import unittest
from unittest.mock import ANY, patch

import numpy as np
from AFCHandlers import UIHandler


class TestUIHandler(unittest.TestCase):
    def setUp(self):
        self.ui_handler = UIHandler()
        self.patchers = {
            'set_theme': patch('sv_ttk.set_theme'),
            'deiconify': patch.object(self.ui_handler, 'deiconify'),
            'withdraw': patch.object(self.ui_handler, 'withdraw'),
            'bind': patch.object(self.ui_handler, 'bind'),
            'frame': patch('ttk.Frame'),
            'grid': patch.object(self.ui_handler, 'grid'),
            'rowconfigure': patch.object(self.ui_handler, 'rowconfigure'),
            'columnconfigure': patch.object(
                self.ui_handler, 'columnconfigure'
            ),
        }
        self.mocks = {
            name: patcher.start() for name, patcher in self.patchers.items()
        }

    def tearDown(self):
        for patcher in self.patchers.values():
            patcher.stop()

    def test_theme_sets_ttk_theme(self):
        theme = 'default'
        self.ui_handler.theme(theme)
        self.mocks['set_theme'].assert_called_once_with(theme)

    def test_visible_shows_ui(self):
        self.ui_handler.visible(True)
        self.mocks['deiconify'].assert_called_once()
        self.mocks['withdraw'].assert_not_called()

    def test_visible_hides_ui(self):
        self.ui_handler.visible(False)
        self.mocks['withdraw'].assert_called_once()
        self.mocks['deiconify'].assert_not_called()

    def test_events_binds_events(self):
        events = ['<Button-1>', '<Button-2>']
        self.ui_handler.events(events)
        for event in events:
            self.mocks['bind'].assert_any_call(event, ANY)

    def test_matrix_creates_widgets(self):
        matrix = np.array([[1, 2], [3, 4]])
        self.ui_handler.matrix(matrix)
        for (i, j), value in np.ndenumerate(matrix):
            if not isinstance(value, ttk.Widget):
                self.mocks['frame'].assert_called_with(self.ui_handler)
            self.mocks['grid'].assert_called_with(
                row=i, column=j, sticky=tk.NSEW
            )
            self.mocks['rowconfigure'].assert_called_with(i, weight=1)
            self.mocks['columnconfigure'].assert_called_with(j, weight=1)


if __name__ == '__main__':
    unittest.main()
