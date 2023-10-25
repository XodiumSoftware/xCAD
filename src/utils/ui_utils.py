from typing import List

from PySide6.QtCore import QPoint
from PySide6.QtWidgets import QApplication, QWidget


class UiUtils(QWidget):
    """A collection of helper functions."""

    def center_ui_on_screen(self) -> None:
        """Centers a QWidget on the screen."""
        self.move(
            QApplication.primaryScreen().geometry().center()
            - QPoint(self.size().width() // 2, self.size().height() // 2)
        )

    def toggle_ui_visibility(self, uis: List[QWidget]) -> None:
        """
        Toggles the visibility of a list of QWidgets.

        Args:
            uis (list[QWidget]): List of QWidgets whose visibility will be toggled.
        """
        for ui in uis:
            ui.setVisible(not ui.isVisible())
            if ui.isVisible():
                self.center_ui_on_screen()
