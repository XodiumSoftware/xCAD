from PySide6.QtGui import QFont
from PySide6.QtWidgets import QLabel, QWidget

from constants import (
    COPYRIGHT_LABEL,
    COPYRIGHT_LABEL_SIZE,
    COPYRIGHT_LABEL_STYLE,
    UI_FONT_TYPE,
)

# TODO: Move handlers and events and etc. into their own files.
# CAREFUL! to not create circular imports, so import them first into SetupUI and then to the UIs.


class SetupUI(QWidget):
    def create_crlabel(self) -> QLabel:
        """
        This function creates a QLabel object with a text string containing a copyright label.
        """
        self.crlabel = QLabel(COPYRIGHT_LABEL)
        self.crlabel.setFont(QFont(UI_FONT_TYPE, COPYRIGHT_LABEL_SIZE))
        self.crlabel.setStyleSheet(COPYRIGHT_LABEL_STYLE)

        return self.crlabel
