import os
from typing import LiteralString, Optional

import darkdetect
from PySide6.QtCore import Qt
from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout

from constants import ICONS_FOLDER_PATH


class PushButtonTypeHints:
    """A class used to represent pushbutton type hints."""

    Title: str | tuple[str, str]
    Icon_path: Optional[tuple[LiteralString]]
    Size: Optional[list]
    Layout: QLayout
    Margin: int
    Alignment: Qt.AlignmentFlag
    SizePolicy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]
    Stylesheet: str | tuple[str, str]


class AutoFrameCADPushButtonConfig(PushButtonTypeHints):
    """A class used to represent a pushbutton widget"""

    Title = ("AutoFrameCAD", "Click on title to start!")
    Icon_path = None
    Size = None
    Layout = QVBoxLayout()
    Margin = 0
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
    Stylesheet = (
        "QLabel {font-size: 48px;font-weight: bold;font-style: normal;border: none;}",
        "QLabel {font-size: 12px;font-weight: normal;font-style: normal;border: none;}",
    )


class SavePushButtonConfig(PushButtonTypeHints):
    """A class used to represent a pushbutton widget"""

    Title = "Save"
    Icon_path = None
    Size = [50, 30]
    Layout = QVBoxLayout()
    Margin = 0
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
    Stylesheet = "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}"


class DiscardPushButtonConfig(PushButtonTypeHints):
    """A class used to represent a pushbutton widget"""

    Title = "Discard"
    Icon_path = None
    Size = [50, 30]
    Layout = QVBoxLayout()
    Margin = 0
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
    Stylesheet = "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}"


class ResetPushButtonConfig(PushButtonTypeHints):
    """A class used to represent a pushbutton widget"""

    Title = "Reset"
    Icon_path = None
    Size = [50, 30]
    Layout = QVBoxLayout()
    Margin = 0
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
    Stylesheet = "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}"


class StartupPagePushButtonConfig(PushButtonTypeHints):
    """A class used to represent a pushbutton widget"""

    Title = "Startup page"
    Icon_path = (
        os.path.join(
            ICONS_FOLDER_PATH,
            "home_icon_light.png" if darkdetect.isDark() else "home_icon_dark.png",
        ),
    )
    Size = [30, 30]
    Layout = QVBoxLayout()
    Margin = 0
    Alignment = Qt.AlignmentFlag.AlignBottom
    SizePolicy = (
        QSizePolicy.Policy.Minimum,
        QSizePolicy.Policy.Minimum,
    )
    Stylesheet = "QPushButton {font-size: 12px;font-weight: normal;font-style: normal;}"
