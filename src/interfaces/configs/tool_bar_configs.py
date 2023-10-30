from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


class ToolBarTypeHints:
    """A class used to represent tool bar type hints."""

    Title: str
    Stylesheet: str
    Layout: QLayout
    SizePolicy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class MainUIToolBarConfig(ToolBarTypeHints):
    """A class used to represent a tool bar config."""

    Title = "TODO: implement this."
    Stylesheet = "color : white;"
    Layout = QVBoxLayout()
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
