from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


class StatusBarTypeHints:
    """A class used to represent status bar type hints."""

    Status_tip: str
    Stylesheet: str
    Layout: QLayout
    SizePolicy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class MainUIStatusBarConfig(StatusBarTypeHints):
    """A class used to represent a status bar config."""

    Status_tip = "TODO: implement this."
    Stylesheet = "color: #fff;"
    Layout = QVBoxLayout()
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
