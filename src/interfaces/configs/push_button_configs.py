import os
from dataclasses import dataclass
from typing import Optional

import darkdetect
from PySide6.QtCore import Qt, Signal
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout

from constants import ICONS_FOLDER_PATH
from interfaces.handlers.signal_handler import SignalHandler


@dataclass
class PushButtonTypeHints:
    """A class used to represent pushbutton type hints."""

    title: str | tuple[str, ...]
    icon_path: Optional[QIcon]
    stylesheet: str | tuple[str, ...]
    text_alignment: Qt.AlignmentFlag | tuple[Qt.AlignmentFlag, ...]
    size: Optional[list]
    layout: QLayout
    size_policy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]
    signal: Optional[Signal | tuple[Signal, ...]]
    signals: Optional[Signal | tuple[Signal, ...]]


class AutoFrameCADPushButtonConfig(PushButtonTypeHints):
    """A class used to represent a pushbutton widget"""

    def __init__(self):
        super().__init__(
            title=(
                "AutoFrameCAD",
                "Click on title to start!",
            ),
            icon_path=None,
            stylesheet=(
                "QLabel {font-size: 48px;font-weight: bold;font-style: normal;border: none;}",
                "QLabel {font-size: 12px;font-weight: normal;font-style: normal;border: none;}",
            ),
            text_alignment=(Qt.AlignmentFlag.AlignCenter, Qt.AlignmentFlag.AlignCenter),
            size=None,
            layout=QVBoxLayout(),
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
            signal=SignalHandler.clicked_signal,
            signals=SignalHandler.clicked_signal,
        )


class SavePushButtonConfig(PushButtonTypeHints):
    """A class used to represent a pushbutton widget"""

    def __init__(self):
        super().__init__(
            title="Save",
            icon_path=None,
            stylesheet="QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
            text_alignment=Qt.AlignmentFlag.AlignCenter,
            size=[50, 30],
            layout=QVBoxLayout(),
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
            signal=None,
            signals=None,
        )


class DiscardPushButtonConfig(PushButtonTypeHints):
    """A class used to represent a pushbutton widget"""

    def __init__(self):
        super().__init__(
            title="Discard",
            icon_path=None,
            stylesheet="QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
            text_alignment=Qt.AlignmentFlag.AlignCenter,
            size=[50, 30],
            layout=QVBoxLayout(),
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
            signal=None,
            signals=None,
        )


class ResetPushButtonConfig(PushButtonTypeHints):
    """A class used to represent a pushbutton widget"""

    def __init__(self):
        super().__init__(
            title="Reset",
            icon_path=None,
            stylesheet="QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
            text_alignment=Qt.AlignmentFlag.AlignCenter,
            size=[50, 30],
            layout=QVBoxLayout(),
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
            signal=None,
            signals=None,
        )


class StartupPagePushButtonConfig(PushButtonTypeHints):
    """A class used to represent a pushbutton widget"""

    def __init__(self):
        super().__init__(
            title="Startup page",
            icon_path=QIcon(
                os.path.join(
                    ICONS_FOLDER_PATH,
                    "home_icon_light.png"
                    if darkdetect.isDark()
                    else "home_icon_dark.png",
                ),
            ),
            stylesheet="QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}",
            text_alignment=Qt.AlignmentFlag.AlignCenter,
            size=[30, 30],
            layout=QVBoxLayout(),
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
            signal=None,
            signals=None,
        )
