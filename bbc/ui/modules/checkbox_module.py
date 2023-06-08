from functools import partial

from constants import CHECKBOXES
from PySide6.QtCore import QSettings, Signal
from PySide6.QtWidgets import QCheckBox, QVBoxLayout, QWidget


class CheckBoxModule(QWidget):
    onCheckBoxClicked = Signal(int)

    def __init__(self, checkbox_index, parent=None):
        """
        Initialize the CheckBoxModule.
        """
        super().__init__(parent)
        self._settings = QSettings()
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
                partial(self.onCheckBoxClicked.emit, checkbox_index)
            )
            layout.addWidget(checkbox)

        layout.setContentsMargins(0, 0, 0, 0)

        self.setLayout(layout)

    def create_checkbox_module(self, checkbox_data, checkbox_index):
        """
        Create a checkbox module.
        """
        checkbox = QCheckBox(checkbox_data["title"])
        checkbox.setStyleSheet(checkbox_data["stylesheet"])
        checkbox.setSizePolicy(*checkbox_data["size_policy"])

        if checkbox_index == 0:
            checked_state = self._settings.value("main_ui_page_visibility_state") == 0
            checkbox.setChecked(bool(checked_state))

        return checkbox
