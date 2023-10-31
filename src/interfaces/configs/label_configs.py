from PySide6.QtCore import Qt
from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout


class LabelTypeHints:
    """A class used to represent label type hints."""

    def __init__(
        self,
        title: str,
        stylesheet: str,
        layout: QLayout,
        margin: int,
        alignment: Qt.AlignmentFlag,
        size_policy: tuple[QSizePolicy.Policy, QSizePolicy.Policy],
    ):
        self.__dict__.update(locals())

    def __getattr__(self, name):
        return self.__dict__.get(name, AttributeError(name))

    @property
    def Title(self) -> str:
        """Get the title."""
        return self.title

    @property
    def Stylesheet(self) -> str:
        """Get the stylesheet."""
        return self.stylesheet

    @property
    def Layout(self) -> QLayout:
        """Get the layout."""
        return self.layout

    @property
    def Margin(self) -> int:
        """Get the margin."""
        return self.margin

    @property
    def Alignment(self) -> Qt.AlignmentFlag:
        """Get the alignment."""
        return self.alignment

    @property
    def SizePolicy(self) -> tuple[QSizePolicy.Policy, QSizePolicy.Policy]:
        """Get the size policy."""
        return self.size_policy


class CopyrightLabelConfig(LabelTypeHints):
    """A class used to represent a label config."""

    def __init__(self):
        super().__init__(
            title="© 2023 Qerimi Engineering. All rights reserved.",
            stylesheet="QLabel { font-size: 12px; font-style: italic; }",
            layout=QVBoxLayout(),
            margin=0,
            alignment=Qt.AlignmentFlag.AlignBottom,
            size_policy=(QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
        )
