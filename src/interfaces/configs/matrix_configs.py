from dataclasses import dataclass
from typing import Type

from PySide6.QtWidgets import QGridLayout

from interfaces.configs.label_configs import CopyrightLabelConfig
from interfaces.configs.push_button_configs import AutoFrameCADPushButtonConfig
from interfaces.modules.label_module import LabelModule
from interfaces.modules.push_button_module import PushButtonModule


@dataclass
class MatrixTypeHints:
    """A class used to represent matrix type hints."""

    layout: QGridLayout
    matrix: tuple[list[list[Type]], ...]


class MainUIStartUpMatrixConfig(MatrixTypeHints):
    """A class used to represent a matrix config."""

    def __init__(self):
        super().__init__(
            layout=QGridLayout(),
            matrix=(
                [
                    [
                        PushButtonModule(AutoFrameCADPushButtonConfig()),
                    ],
                ],
                [
                    [
                        LabelModule(CopyrightLabelConfig()),
                    ],
                ],
            ),
        )


class MainUIMenuConfig(MatrixTypeHints):
    """A class used to represent a matrix config."""

    def __init__(self):
        super().__init__(
            layout=QGridLayout(),
            matrix=(
                [
                    [
                        PushButtonModule(AutoFrameCADPushButtonConfig()),
                    ],
                ],
                [
                    [
                        LabelModule(CopyrightLabelConfig()),
                    ],
                ],
            ),
        )
