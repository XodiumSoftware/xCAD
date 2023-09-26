from functools import partial

from PySide6.QtGui import QKeySequence, QShortcut
from PySide6.QtWidgets import QWidget

from configs.module_configs import MessageBoxes
from delegates.message_box_delegate import MessageBoxDelegate


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
