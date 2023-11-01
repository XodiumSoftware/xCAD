from dataclasses import dataclass

from PySide6.QtGui import QIcon
from PySide6.QtWidgets import QLayout, QSizePolicy, QVBoxLayout, QWidget

from constants import UI_ICON_PATH
from interfaces.configs.action_configs import DefaultActionConfig
from interfaces.configs.matrix_configs import (
    MainUIMenuConfig,
    MainUIStartUpMatrixConfig,
)
from interfaces.configs.status_bar_configs import MainUIStatusBarConfig
from interfaces.configs.tool_bar_configs import MainUIToolBarConfig
from interfaces.modules.action_module import ActionModule
from interfaces.modules.matrix_module import MatrixModule
from interfaces.modules.status_bar_module import StatusBarModule
from interfaces.modules.tool_bar_module import ToolBarModule


@dataclass
class UITypeHints:
    """A class used to represent main UI type hints."""

    title: str
    layout: QLayout
    icon_path: QIcon
    init_size: tuple[int, int]
    init_visibility: bool
    content_margins: tuple[int, int, int, int]
    size_policy: tuple[QSizePolicy.Policy, QSizePolicy.Policy]
    status_bar: StatusBarModule
    tool_bar: ToolBarModule
    module_stack: tuple[QWidget, ...]


class MainUIConfig(UITypeHints):
    """A class to represent the main UI."""

    def __init__(self):
        super().__init__(
            title="AFC",
            layout=QVBoxLayout(),
            icon_path=QIcon(UI_ICON_PATH),
            init_size=(600, 400),
            init_visibility=True,
            content_margins=(10, 10, 10, 10),
            size_policy=(
                QSizePolicy.Policy.Minimum,
                QSizePolicy.Policy.Minimum,
            ),
            status_bar=StatusBarModule(MainUIStatusBarConfig()),
            tool_bar=ToolBarModule(
                MainUIToolBarConfig(),
                ActionModule(
                    DefaultActionConfig(),
                ),
            ),
            module_stack=(
                MatrixModule(MainUIStartUpMatrixConfig()),
                MatrixModule(MainUIMenuConfig()),
            ),
        )
