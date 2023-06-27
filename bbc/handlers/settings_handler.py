from PySide6.QtCore import QSettings


class SettingsHandler:
    def __init__(self, widget=None, index_number=None):
        """
        Initialize the SettingsHandler.
        """
        self.settings = QSettings()
        self.widget = widget
        self.index_number = index_number

        if self.widget is not None:
            self.load_visibility_state()

    def load_visibility_state(self):
        """
        Load the visibility state of the widget.
        """
        visibility = self.settings.value(
            f"{self.widget.objectName()}_{self.index_number}_visibility",
            True,
            type=bool,
        )
        self.widget.setVisible(visibility)

    def save_visibility_state(self):
        """
        Save the visibility state of the widget.
        """
        self.settings.setValue(
            f"{self.widget.objectName()}_{self.index_number}_visibility",
            self.widget.isVisible(),
        )

    def toggle_visibility_state(self):
        """
        Toggle the visibility of the widget.
        """
        visible = not self.widget.isVisible()
        self.widget.setVisible(visible)
        self.save_visibility_state()
