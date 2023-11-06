from PySide6.QtGui import QKeySequence, QShortcut
from PySide6.QtWidgets import QStackedWidget, QWidget

from interfaces.configs.message_box_configs import QuitMessageBox
from interfaces.modules.message_box_module import MessageBoxModule

# TODO


class Events:
    """Class for handling events."""

    @staticmethod
    def quit_on_key_press_event(parent: QWidget) -> list[str]:
        """Quit on Escape key or Ctrl+Q."""
        shortcuts = ["Escape", "Ctrl+Q"]

        for shortcut_str in shortcuts:
            shortcut = QShortcut(QKeySequence(shortcut_str), parent)
            shortcut.activated.connect(lambda: MessageBoxModule(QuitMessageBox()))

        return shortcuts

    @staticmethod
    def switch_modules_on_action(module: QStackedWidget) -> None:
        """Switches the current module in a QStackedWidget."""
        module.setCurrentIndex((module.currentIndex() + 1) % module.count())