import unittest
from pathlib import Path
from tkinter import ttk as tkttk

import numpy as np
import sv_ttk
from AFCConstants import DATABASE_PATH
from AFCDatabase import Database as AFCDatabase
from AFCDataclasses import UIDataclass


class TestUIDataclass(unittest.TestCase):
    def test_primary_typing(self):
        ui_data = UIDataclass()
        primary_typing = ui_data.PRIMARY

        self.assertEqual(primary_typing.TITLE, 'AutoFrameCAD')
        self.assertEqual(primary_typing.THEME, 'dark')
        self.assertTrue(primary_typing.VISIBILITY)
        self.assertTrue(primary_typing.RESIZABLE)
        self.assertTrue(primary_typing.ICON)
        self.assertEqual(primary_typing.ICON_PATH, Path('/path/to/icon'))
        self.assertEqual(primary_typing.GEOM_X, 1200)
        self.assertEqual(primary_typing.GEOM_Y, 800)
        self.assertEqual(primary_typing.EVENTS, ['<Escape>', '<Control-q>'])
        self.assertTrue(
            np.array_equal(
                primary_typing.MATRIX,
                np.array(
                    [
                        [
                            tkttk.Label(text='Structura Engineering'),
                            None,
                        ],
                        [
                            tkttk.Button(
                                text='TEST1',
                                command=AFCDatabase(DATABASE_PATH).add_data,
                            ),
                            tkttk.Button(
                                text='TEST0', command=sv_ttk.toggle_theme
                            ),
                        ],
                    ],
                    dtype=object,
                ),
            )
        )


if __name__ == '__main__':
    unittest.main()
