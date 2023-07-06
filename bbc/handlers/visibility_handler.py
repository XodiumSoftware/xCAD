from constants import DEBUG_NAME
from PySide6.QtCore import QSettings


class VisibilityHandler:
    def __init__(self):
        """
        Initialize the VisibilityHandler.
        """
        self.settings = QSettings()

    def toggle_visibility_state(self, module, module_type, module_index):
        """
        Toggle the visibility of the module.
        """
        module.setVisible(not module.isVisible())
        self.save_visibility_state(module.isVisible(), module_type, module_index)

    def load_visibility_state(self, module, module_index):
        """
        Load the visibility state from QSettings and apply it to the module.
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
        module.setVisible(visibility_state)

    def save_visibility_state(self, visibility_state, module_type, module_index):
        """
        Save the visibility state to QSettings.
        """
        self.settings.setValue(
            f"visibility_state_module_{module_type}_index_{module_index}",
            visibility_state,
        )
        print(
            DEBUG_NAME
            + f"Saved visibility state for module_{module_type}_{module_index}: {visibility_state}"
        )
