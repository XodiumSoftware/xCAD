from functools import partial

from PySide6.QtGui import QKeySequence, QShortcut
from PySide6.QtWidgets import QStackedWidget, QWidget

from delegates.message_box_delegate import MessageBoxDelegate
from interfaces.configs.module_configs import MessageBoxes


class EventsHandler:
    """A class to handle events."""

    @staticmethod
    def quit_on_key_press_event(ui: QWidget) -> None:
        """Quit on Escape key or Ctrl+Q."""
        [
            QShortcut(QKeySequence(shortcut_str), ui).activated.connect(
                partial(MessageBoxDelegate, MessageBoxes.QuitMessage.value)
            )
            for shortcut_str in ["Escape", "Ctrl+Q"]
        ]

    @staticmethod
    def switch_modules_on_event(module: QStackedWidget) -> None:
        """Switches the current module in a QStackedWidget."""
        module.setCurrentIndex((module.currentIndex() + 1) % module.count())
