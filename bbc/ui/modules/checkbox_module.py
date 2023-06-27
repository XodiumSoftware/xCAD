from functools import partial

from constants import CHECKBOXES, DEBUG_NAME
from PySide6.QtCore import QSettings, Signal
from PySide6.QtWidgets import QCheckBox, QVBoxLayout, QWidget


class CheckBoxModule(QWidget):
    on_checkbox_clicked = Signal(int)

    def __init__(
        self, checkbox_index, margins=None, alignment=None, visible=None, parent=None
    ):
        """
        Initialize the CheckBoxModule.
        """
        super().__init__(parent)
        self._settings = QSettings()
        self.margins = margins
        self.alignment = alignment
        self.visible = visible
        self.setup_checkbox_module(checkbox_index)

    def setup_checkbox_module(self, checkbox_index):
        """
        Setup the CheckBoxModule.
        """
        layout = QVBoxLayout(self)

        checkbox_data = next(
            (
                checkbox
                for checkbox in CHECKBOXES
                if checkbox["index"] == checkbox_index
            ),
            None,
        )

        if checkbox_data:
            checkbox = self.create_checkbox_module(checkbox_data, checkbox_index)
            checkbox.clicked.connect(
                partial(self.on_checkbox_clicked.emit, checkbox_index)
            )
            layout.addWidget(checkbox)

        else:
            print(DEBUG_NAME + f'"index" {checkbox_index} not found in CHECKBOXES')

        if self.margins is not None:
            layout.setContentsMargins(*self.margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if self.alignment is not None:
            layout.setAlignment(*self.alignment)

        if self.visible is not None:
            self.setVisible(self.visible)

        self.setLayout(layout)

    def create_checkbox_module(self, checkbox_data):
        """
        Create a checkbox module.
        """
        checkbox = QCheckBox(checkbox_data["title"])
        checkbox.setStyleSheet(checkbox_data["stylesheet"])

        return checkbox

    def toggle_visibility(self):
        """
        Toggle the visibility of the checkbox.
        """
        self.setVisible(not self.isVisible())
