from constants import DEBUG_NAME
from PySide6.QtCore import QSettings


# FIXME: We need it to save the visibility state of the modules_index but also save if its a table or button or etc.
class VisibilityHandler:
    def __init__(self):
        """
        Initialize the VisibilityHandler.
        """
        self.settings = QSettings()

    def toggle_visibility_state(self, widget, module_index):
        """
        Toggle the visibility of the widget.
        """
        widget.setVisible(not widget.isVisible())
        self.save_visibility_state(widget.isVisible(), module_index)

    def load_visibility_state(self, widget, module_index):
        """
        Load the visibility state from QSettings and apply it to the widget.
        """
        visibility_state = self.settings.value(
            f"visibility_state_module_{module_index}",
            defaultValue=True,
            type=bool,
        )
        print(
            DEBUG_NAME
            + f"Loaded visibility_state for module_{module_index}: {visibility_state}"
        )
        widget.setVisible(visibility_state)

    def save_visibility_state(self, visibility_state, module_index):
        """
        Save the visibility state to QSettings.
        """
        self.settings.setValue(
            f"visibility_state_module_{module_index}", visibility_state
        )
        print(
            DEBUG_NAME
            + f"Saved visibility_state for module_{module_index}: {visibility_state}"
        )
