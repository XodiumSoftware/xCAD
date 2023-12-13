import qdarktheme
from interfaces.configs.ui_configs import UITypeHints
from interfaces.events.events import Events
from PySide6.QtWidgets import QMainWindow


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
        if configs.init_visibility:
            self.show()
        else:
            self.hide()
        self.setContentsMargins(*configs.content_margins)
        self.setSizePolicy(*configs.size_policy)
        self.setStatusBar(configs.status_bar)
        self.addToolBar(configs.tool_bar)
        self.setCentralWidget(configs.stack_module)
        self.setup_actions()

    # TODO: Make it modular.
    def setup_actions(self):
        """Setup the actions."""
        Events.quit_on_key_press_event(self)
