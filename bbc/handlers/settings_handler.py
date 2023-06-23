from PySide6.QtCore import QSettings


class SettingsHandler:
    def __init__(self):
        """
        Initialize the SettingsHandler.
        """
        super().__init__()
        self._settings = QSettings()

    def load_visibility_state(self, widget):
        """
        Load the visibility state of the widget.
        """
        visibility = self._settings.value(
            f"{widget.objectName()}_visibility", True, type=bool
        )
        widget.setVisible(visibility)

    def save_visibility_state(self, widget):
        """
        Save the visibility state of the widget.
        """
        self._settings.setValue(f"{widget.objectName()}_visibility", widget.isVisible())
