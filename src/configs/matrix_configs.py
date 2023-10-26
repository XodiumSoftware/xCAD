from enum import Enum

from PySide6.QtCore import Qt
from PySide6.QtWidgets import QSizePolicy, QVBoxLayout

from configs.module_configs import GraphicsViews, Labels, PushButtons


class Matrices(Enum):
    """A class to store the matrices."""

    MainMatrix0 = [
        [
            {
                "module": PushButtons.AutoFrameCAD,
                "layout": QVBoxLayout,
                "margins": None,
                "alignment": Qt.AlignmentFlag.AlignCenter,
                "sizepolicy": (
                    QSizePolicy.Policy.Expanding,
                    QSizePolicy.Policy.Expanding,
                ),
            },
        ],
        [
            {
                "module": Labels.Copyright,
                "layout": QVBoxLayout,
                "margins": None,
                "alignment": Qt.AlignmentFlag.AlignBottom,
                "sizepolicy": (
                    QSizePolicy.Policy.Minimum,
                    QSizePolicy.Policy.Minimum,
                ),
            },
        ],
    ]
    MainMatrix1 = [
        [
            {
                "module": GraphicsViews.StructureView,
                "layout": QVBoxLayout,
                "margins": None,
                "alignment": Qt.AlignmentFlag.AlignCenter,
                "sizepolicy": (
                    QSizePolicy.Policy.Expanding,
                    QSizePolicy.Policy.Expanding,
                ),
            },
        ],
        [
            {
                "module": PushButtons.Save,
                "layout": QVBoxLayout,
                "margins": None,
                "alignment": Qt.AlignmentFlag.AlignCenter,
                "sizepolicy": (
                    QSizePolicy.Policy.Minimum,
                    QSizePolicy.Policy.Minimum,
                ),
            },
            {
                "module": PushButtons.Discard,
                "layout": QVBoxLayout,
                "margins": None,
                "alignment": Qt.AlignmentFlag.AlignCenter,
                "sizepolicy": (
                    QSizePolicy.Policy.Minimum,
                    QSizePolicy.Policy.Minimum,
                ),
            },
            {
                "module": PushButtons.Reset,
                "layout": QVBoxLayout,
                "margins": None,
                "alignment": Qt.AlignmentFlag.AlignCenter,
                "sizepolicy": (
                    QSizePolicy.Policy.Minimum,
                    QSizePolicy.Policy.Minimum,
                ),
            },
        ],
        [
            {
                "module": PushButtons.StartupPage,
                "layout": QVBoxLayout,
                "margins": None,
                "alignment": Qt.AlignmentFlag.AlignLeft,
                "sizepolicy": (
                    QSizePolicy.Policy.Minimum,
                    QSizePolicy.Policy.Minimum,
                ),
            },
        ],
        [
            {
                "module": Labels.Copyright,
                "layout": QVBoxLayout,
                "margins": None,
                "alignment": Qt.AlignmentFlag.AlignLeft,
                "sizepolicy": (
                    QSizePolicy.Policy.Minimum,
                    QSizePolicy.Policy.Minimum,
                ),
            },
        ],
    ]
