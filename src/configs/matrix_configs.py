from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QSizePolicy, QVBoxLayout

from configs.module_configs import GraphicsViews, Labels, PushButtons


class Matrices(Enum):
    """A class to store the matrices."""

    MainMatrix0 = [
        [
            [
                PushButtons.AutoFrameCAD,
                QVBoxLayout,
                None,
                Qt.AlignmentFlag.AlignCenter,
                (QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding),
            ],
        ],
        [
            [
                Labels.Copyright,
                QVBoxLayout,
                None,
                Qt.AlignmentFlag.AlignBottom,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
        ],
    ]
    MainMatrix1 = [
        [
            [
                GraphicsViews.StructureView,
                QVBoxLayout,
                None,
                Qt.AlignmentFlag.AlignCenter,
                (QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding),
            ],
        ],
        [
            [
                PushButtons.Save,
                QVBoxLayout,
                None,
                Qt.AlignmentFlag.AlignCenter,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
            [
                PushButtons.Discard,
                QVBoxLayout,
                None,
                Qt.AlignmentFlag.AlignCenter,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
            [
                PushButtons.Reset,
                QVBoxLayout,
                None,
                Qt.AlignmentFlag.AlignCenter,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
        ],
        [
            [
                PushButtons.StartupPage,
                QVBoxLayout,
                None,
                Qt.AlignmentFlag.AlignLeft,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
        ],
        [
            [
                Labels.Copyright,
                QVBoxLayout,
                None,
                Qt.AlignmentFlag.AlignLeft,
                (QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum),
            ],
        ],
    ]
