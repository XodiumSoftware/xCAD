from PySide6.QtCore import Qt
from PySide6.QtGui import QFont
from PySide6.QtWidgets import QLabel, QVBoxLayout, QWidget

from constants import (
    COPYRIGHT_LABEL,
    COPYRIGHT_LABEL_SIZE,
    COPYRIGHT_LABEL_STYLE,
    UI_FONT_TYPE,
)

# TODO: Move handlers and events and etc. into their own files.
# CAREFUL! to not create circular imports, so import them first into SetupUI and then to the UIs.


class SetupUI(QWidget):
    def __init__(self):
        super().__init__()

        self.main_layout = QVBoxLayout(self)
        self.main_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.copyright_label()

    def copyright_label(self):
        """
        This function creates a QLabel object with a text string containing a copyright label.
        """
        self.crlabel = QLabel(COPYRIGHT_LABEL)
        self.crlabel.setFont(QFont(UI_FONT_TYPE, COPYRIGHT_LABEL_SIZE))
        self.crlabel.setStyleSheet(COPYRIGHT_LABEL_STYLE)
