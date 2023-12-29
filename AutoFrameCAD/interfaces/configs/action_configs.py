from dataclasses import dataclass

from interfaces.configs.ui_configs import UI_ICON_PATH
from PySide6.QtGui import QIcon


@dataclass
class ActionTypeHints:
    """A class used to represent label type hints."""

    icon: QIcon
    tooltip: str


class DefaultActionConfig(ActionTypeHints):
    """A class used to represent a label config."""

    def __init__(self):
        super().__init__(
            icon=QIcon(UI_ICON_PATH),
            tooltip="Tooltip text",
        )