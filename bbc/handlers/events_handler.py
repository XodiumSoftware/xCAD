from functools import partial

from handlers.dialog_handler import DialogHandler
from PySide6.QtCore import QPointF
from PySide6.QtGui import QKeySequence, QShortcut
from PySide6.QtWidgets import QGraphicsItem, QGraphicsView, QWidget


class EventsHandler:
    """A class to handle events."""

    @staticmethod
    def quit_on_key_press_event(ui: QWidget, quit_application: bool = True) -> None:
        """Quit on Escape key or Ctrl+Q."""
        shortcuts = ["Escape", "Ctrl+Q"]
        for shortcut in shortcuts:
            key_sequence = QKeySequence(shortcut)
            shortcut = QShortcut(key_sequence, ui)
            shortcut.activated.connect(
                partial(DialogHandler.quit_dialog, quit_application)
            )
