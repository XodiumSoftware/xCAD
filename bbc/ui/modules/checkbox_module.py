from constants import CHECKBOXES, QSETTINGS
from handlers.ui_handler import UIHandler
from PySide6.QtCore import QSettings
from PySide6.QtWidgets import QCheckBox, QVBoxLayout, QWidget


class CheckBoxModule(QWidget):
    def __init__(self, checkbox_index, parent=None):
        """
        Initialize the CheckBoxModule.
        """
        super().__init__(parent)

        self._settings = QSettings(QSETTINGS)
        self._ui_handler = UIHandler(self)

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
            checkbox = self.create_checkbox_module(checkbox_data)
            layout.addWidget(checkbox)

        self.setLayout(layout)

    def create_checkbox_module(self, checkbox_data):
        """
        Create a checkbox module.
        """
        checkbox = QCheckBox(checkbox_data["title"])
        checkbox.setStyleSheet(checkbox_data["stylesheet"])
        checkbox.setSizePolicy(*checkbox_data["size_policy"])
        checkbox.setChecked(bool(self._settings.value("checkbox_state", True)))

        return checkbox
