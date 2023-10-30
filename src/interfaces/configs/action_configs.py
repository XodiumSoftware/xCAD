from PySide6.QtGui import QIcon


class ActionTypeHints:
    """A class used to represent label type hints."""

    Icon: QIcon
    Tooltip: str


class DefaultActionConfig(ActionTypeHints):
    """A class used to represent a label config."""

    Icon = QIcon("icon.png")
    Tooltip = "Tooltip text"
