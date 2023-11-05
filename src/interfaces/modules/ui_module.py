import qdarktheme
from PySide6.QtWidgets import QMainWindow, QStackedWidget

from interfaces.configs.ui_configs import UITypeHints
from interfaces.events.events import Events


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
        self.setWindowTitle(configs.title)
        self.setLayout(configs.layout)
        self.setWindowIcon(configs.icon_path)
        self.resize(*configs.init_size)
        self.show() if configs.init_visibility else self.hide()
        self.setContentsMargins(*configs.content_margins)
        self.setSizePolicy(*configs.size_policy)
        self.setStatusBar(configs.status_bar)
        self.addToolBar(configs.tool_bar)
        self.setup_central_widget(configs)
        self.setup_actions()

    def setup_actions(self):
        """Setup the actions."""
        Events.quit_on_key_press_event(self)

    # TODO: make this its own module
    def setup_central_widget(self, configs: UITypeHints) -> None:
        """Set up the central widget."""
        self._module_stack = QStackedWidget(self)
        if isinstance(configs.module_stack, tuple):
            for module in configs.module_stack:
                self._module_stack.addWidget(module)
        else:
            self._module_stack.addWidget(configs.module_stack)
        self.setCentralWidget(self._module_stack)
