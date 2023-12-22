from dataclasses import dataclass

from interfaces.configs.label_configs import CopyrightLabelConfig
from interfaces.configs.push_button_configs import AutoFrameCADPushButtonConfig
from interfaces.modules.label_module import LabelModule
from interfaces.modules.push_button_module import PushButtonModule
from PySide6.QtCore import Qt
from PySide6.QtWidgets import QGridLayout, QSizePolicy, QWidget


@dataclass
class ModuleConfig:
    """A class used to represent a module config."""

    module: QWidget
    row_span: int
    col_span: int
    alignment: Qt.AlignmentFlag


@dataclass
class MatrixTypeHints:
    """A class used to represent matrix type hints."""

    layout: QGridLayout
    size_policy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]
    matrix: tuple[list[list[ModuleConfig]], ...]


class MainUIStartUpMatrixConfig(MatrixTypeHints):
    """A class used to represent a matrix config."""

    def __init__(self):
        super().__init__(
            layout=QGridLayout(),
            size_policy=(
                QSizePolicy.Policy.Expanding,
                QSizePolicy.Policy.Expanding,
            ),
            matrix=(
                [
                    [
                        ModuleConfig(
                            module=PushButtonModule(AutoFrameCADPushButtonConfig()),
                            row_span=1,
                            col_span=1,
                            alignment=Qt.AlignmentFlag.AlignCenter,
                        )
                    ],
                ],
                [
                    [
                        ModuleConfig(
                            module=LabelModule(CopyrightLabelConfig()),
                            row_span=1,
                            col_span=1,
                            alignment=Qt.AlignmentFlag.AlignBottom
                            | Qt.AlignmentFlag.AlignLeft,
                        )
                    ],
                ],
            ),
        )


class MainUIMenuConfig(MatrixTypeHints):
    """A class used to represent a matrix config."""

    def __init__(self):
        super().__init__(
            layout=QGridLayout(),
            size_policy=(
                QSizePolicy.Policy.Expanding,
                QSizePolicy.Policy.Expanding,
            ),
            matrix=(
                [
                    [
                        ModuleConfig(
                            module=PushButtonModule(AutoFrameCADPushButtonConfig()),
                            row_span=1,
                            col_span=1,
                            alignment=Qt.AlignmentFlag.AlignCenter,
                        )
                    ],
                ],
                [
                    [
                        ModuleConfig(
                            module=LabelModule(CopyrightLabelConfig()),
                            row_span=1,
                            col_span=1,
                            alignment=Qt.AlignmentFlag.AlignBottom
                            | Qt.AlignmentFlag.AlignLeft,
                        )
                    ],
                ],
            ),
        )
