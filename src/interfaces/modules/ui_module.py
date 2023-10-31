import qdarktheme
from PySide6.QtGui import QIcon, QKeySequence, QShortcut
from PySide6.QtWidgets import QMainWindow, QStackedWidget

from interfaces.configs.message_box_configs import QuitMessageBox
from interfaces.configs.ui_configs import UITypeHints
from interfaces.modules.message_box_module import MessageBoxModule


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
        self.setWindowIcon(QIcon(configs.IconPath))
        self.resize(*configs.InitSize)
        self.show() if configs.InitVisibility else self.hide()
        self.setContentsMargins(*configs.ContentMargins)
        self.setSizePolicy(*configs.SizePolicy)
        self.setStatusBar(configs.StatusBar)
        self.addToolBar(configs.ToolBar)
        self.setup_central_widget(configs)
        self.quit_on_key_press_event()

    def setup_central_widget(self, configs: UITypeHints) -> None:
        """Set up the central widget."""
        self._module_stack = QStackedWidget(self)
        if isinstance(configs.ModuleStack, tuple):
            for module in configs.ModuleStack:
                self._module_stack.addWidget(module)
        else:
            self._module_stack.addWidget(configs.ModuleStack)
        self.setCentralWidget(self._module_stack)

    # TODO: Make events modular.

    def quit_on_key_press_event(self) -> list[str]:
        """Quit on Escape key or Ctrl+Q."""
        shortcuts = ["Escape", "Ctrl+Q"]

        for shortcut_str in shortcuts:
            shortcut = QShortcut(QKeySequence(shortcut_str), self)
            shortcut.activated.connect(lambda: MessageBoxModule(QuitMessageBox()))

        return shortcuts
