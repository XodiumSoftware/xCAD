from functools import partial

from delegates.message_box_delegate import MessageBoxDelegate
from enums.module_enums import MessageBoxes
from enums.q_enums import AspectRatioModeTypes
from PySide6.QtGui import QKeySequence, QShortcut
from PySide6.QtWidgets import QGraphicsView, QWidget


class EventsHandler:
    """A class to handle events."""

    @staticmethod
    def quit_on_key_press_event(ui: QWidget) -> None:
        """Quit on Escape key or Ctrl+Q."""
        shortcuts = ["Escape", "Ctrl+Q"]
        for shortcut_str in shortcuts:
            shortcut = QShortcut(QKeySequence(shortcut_str), ui)
            shortcut.activated.connect(
                partial(MessageBoxDelegate, MessageBoxes.QuitMessage.value)
            )

    @staticmethod
    def fit_scene_in_view(instance: QGraphicsView) -> None:
        """Fits the scene in the view."""
        instance.fitInView(
            instance.sceneRect(), AspectRatioModeTypes.KeepAspectRatio.value
        )
