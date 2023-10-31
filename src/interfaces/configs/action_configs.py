from interfaces.configs.ui_configs import UI_ICON_PATH


class ActionTypeHints:
    """A class used to represent label type hints."""

    Icon: str
    Tooltip: str


class DefaultActionConfig(ActionTypeHints):
    """A class used to represent a label config."""

    Icon = UI_ICON_PATH
    Tooltip = "Tooltip text"
