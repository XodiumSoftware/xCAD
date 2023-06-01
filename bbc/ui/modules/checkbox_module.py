from constants import CHECKBOXES, QSETTINGS
from handlers.ui_handler import UIHandler
from PySide6.QtCore import QSettings
from PySide6.QtWidgets import QCheckBox, QVBoxLayout, QWidget


class CheckBoxModule(QWidget):
    _settings = QSettings(QSETTINGS)
    _ui_handler = UIHandler()

    def __init__(self, checkbox_index, parent=None):
        """
        Initialize the CheckBoxModule.
        """
        super().__init__(parent)
        self.init_checkbox_module(checkbox_index)

    def init_checkbox_module(self, checkbox_index):
        """
        Initialize the label widget.
        """
        layout = QVBoxLayout(self)

        checkbox_data = next(
            (
                checkbox
                for checkbox in CHECKBOXES
                if checkbox["index"] == checkbox_index
            ),
        )

        if checkbox_data:
            checkbox = self.create_checkbox(checkbox_data)
            layout.addWidget(checkbox)

        self.setLayout(layout)

    def create_checkbox(self, checkbox_data):
        """
        Create the checkbox.
        """
        checkbox = QCheckBox(checkbox_data["title"])
        checkbox.setStyleSheet(checkbox_data["stylesheet"])
        checkbox.setChecked(checkbox_data["checked"])
        checkbox.setSizePolicy(*checkbox_data["size_policy"])

        state = bool(self._settings.value("checkbox_state", True, bool))
        checkbox.setChecked(state)
        return checkbox

    @property
    def modular_checkbox(self):
        """
        Create and configure the checkbox.
        """
        if not hasattr(self, "_modular_checkbox"):
            checkbox = QCheckBox("")
            checkbox.setChecked(bool(self._settings.value("checkbox_state", True, bool)))
            checkbox.stateChanged.connect(
                lambda state: self._ui_handler.toggle_ui_visibility_state_handler(
                    self, state
                )
            )
            self._modular_checkbox = checkbox

        return self._modular_checkbox
