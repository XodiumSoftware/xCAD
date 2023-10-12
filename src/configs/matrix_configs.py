from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QSizePolicy, QVBoxLayout

from configs.module_configs import GraphicsViews, Labels, PushButtons


class Matrices(Enum):
    """A class to store the matrices."""

    MainMatrix0 = [
        [
            [
                QVBoxLayout,
                PushButtons.AutoFrameCAD,
                None,
                Qt.AlignmentFlag.AlignCenter,
                (QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding),
            ],
        ],
        [
            [
                QVBoxLayout,
                Labels.Copyright,
                None,
                Qt.AlignmentFlag.AlignBottom,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
        ],
    ]
    MainMatrix1 = [
        [
            [
                QVBoxLayout,
                GraphicsViews.StructureView,
                None,
                Qt.AlignmentFlag.AlignCenter,
                (QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding),
            ],
        ],
        [
            [
                QVBoxLayout,
                PushButtons.Save,
                None,
                Qt.AlignmentFlag.AlignCenter,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
            [
                QVBoxLayout,
                PushButtons.Discard,
                None,
                Qt.AlignmentFlag.AlignCenter,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
            [
                QVBoxLayout,
                PushButtons.Reset,
                None,
                Qt.AlignmentFlag.AlignCenter,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
        ],
        [
            [
                QVBoxLayout,
                PushButtons.StartupPage,
                None,
                Qt.AlignmentFlag.AlignLeft,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
        ],
        [
            [
                QVBoxLayout,
                Labels.Copyright,
                None,
                Qt.AlignmentFlag.AlignLeft,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
        ],
    ]
