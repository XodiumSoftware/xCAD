import qdarktheme

# TODO: this file
from PySide6.QtGui import QIcon, QKeySequence, QShortcut
from PySide6.QtWidgets import QMainWindow, QStackedWidget

from interfaces.configs.label_configs import CopyrightLabelConfig
from interfaces.configs.message_box_configs import QuitMessageBox
from interfaces.configs.status_bar_configs import MainUIStatusBarConfig
from interfaces.configs.tool_bar_configs import MainUIToolBarConfig
from interfaces.configs.ui_configs import UITypeHints
from interfaces.modules.label_module import LabelModule
from interfaces.modules.message_box_module import MessageBoxDelegate
from interfaces.modules.status_bar_module import StatusBarModule
from interfaces.modules.tool_bar_module import ToolBarModule


class MainUIModule(QMainWindow):
    """A class used to represent a ui module."""

    def __init__(self, configs: UITypeHints) -> None:
        """Initialize the class.

        Args:
            configs (UITypeHints): A configuration.
        """
        super().__init__()
        qdarktheme.setup_theme("auto")

        self.setup_props(configs)

    def setup_props(self, configs: UITypeHints) -> None:
        """Setup the properties.

        Args:
            configs (UITypeHints): A configuration.
        """
        self.setWindowTitle(configs.Title)
        self.setLayout(configs.Layout)
        self.setWindowIcon(QIcon(configs.Icon_path))
        self.resize(*configs.Init_size)
        self.setup_visibility(configs)
        self.setContentsMargins(*configs.Content_margins)
        self.setSizePolicy(*configs.SizePolicy)
        self.setStatusBar(StatusBarModule(MainUIStatusBarConfig()))
        self.addToolBar(ToolBarModule(MainUIToolBarConfig()))
        self.setup_central_widget()
        self._events = self.quit_on_key_press_event()

    def setup_central_widget(self) -> None:
        """Set up the central widget."""
        self._main_modules_stack = QStackedWidget(self)
        self._main_modules_stack.addWidget(LabelModule(CopyrightLabelConfig()))
        self.setCentralWidget(self._main_modules_stack)

    def setup_visibility(self, configs: UITypeHints) -> None:
        """Set up initial visibility."""

        self.show() if configs.Init_visibility else self.hide()

    def quit_on_key_press_event(self) -> list[str]:
        """Quit on Escape key or Ctrl+Q."""
        shortcuts = ["Escape", "Ctrl+Q"]

        for shortcut_str in shortcuts:
            shortcut = QShortcut(QKeySequence(shortcut_str), self)
            shortcut.activated.connect(lambda: MessageBoxDelegate(QuitMessageBox()))

        return shortcuts
