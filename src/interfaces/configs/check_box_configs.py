from PySide6.QtWidgets import QSizePolicy, QVBoxLayout


class CheckBoxTypeHints:
    """A class used to represent checkbox type hints."""

    Title: str
    Stylesheet: str
    Layout: QVBoxLayout
    SizePolicy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]


class ToggleStartupPageCheckBoxConfig(CheckBoxTypeHints):
    """A class used to represent a checkbox config."""

    Title = "Toggle startup page"
    Stylesheet = "QCheckBox { font-size: 12px; }"
    Layout = QVBoxLayout()
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
