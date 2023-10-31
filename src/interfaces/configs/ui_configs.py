from typing import Union

from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout, QWidget

from constants import UI_ICON_PATH
from interfaces.configs.action_configs import DefaultActionConfig
from interfaces.configs.matrix_configs import MainUIMatrixConfig
from interfaces.configs.status_bar_configs import MainUIStatusBarConfig
from interfaces.configs.tool_bar_configs import MainUIToolBarConfig
from interfaces.modules.action_module import ActionModule
from interfaces.modules.matrix_module import MatrixModule
from interfaces.modules.status_bar_module import StatusBarModule
from interfaces.modules.tool_bar_module import ToolBarModule


class UITypeHints:
    """A class used to represent main UI type hints."""

    Title: str
    Layout: QLayout
    IconPath: str
    InitSize: tuple[int, int]
    InitVisibility: bool
    ContentMargins: tuple[int, int, int, int]
    SizePolicy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]
    StatusBar: StatusBarModule
    ToolBar: ToolBarModule
    ModuleStack: Union[QWidget, tuple[QWidget]]


class MainUIConfig(UITypeHints):
    """A class to represent the main UI."""

    @property
    def Title(self) -> str:
        return "AFC"

    @property
    def Layout(self) -> QVBoxLayout:
        return QVBoxLayout()

    @property
    def IconPath(self) -> str:
        return UI_ICON_PATH

    @property
    def InitSize(self) -> tuple[int, int]:
        return (600, 400)

    @property
    def InitVisibility(self) -> bool:
        return True

    @property
    def ContentMargins(self) -> tuple[int, int, int, int]:
        return (10, 10, 10, 10)

    @property
    def SizePolicy(self) -> tuple[QSizePolicy.Policy, QSizePolicy.Policy]:
        return (
            QSizePolicy.Policy.Minimum,
            QSizePolicy.Policy.Minimum,
        )

    @property
    def StatusBar(self) -> StatusBarModule:
        return StatusBarModule(MainUIStatusBarConfig())

    @property
    def ToolBar(self) -> ToolBarModule:
        return ToolBarModule(
            MainUIToolBarConfig(),
            ActionModule(
                DefaultActionConfig(),
            ),
        )

    @property
    def ModuleStack(self) -> Union[QWidget, tuple[QWidget]]:
        return MatrixModule(MainUIMatrixConfig())
