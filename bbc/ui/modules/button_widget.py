import functools

from constants import BUTTONS, ICONS_FILE_PATHS
from handlers.theme_handler import ThemeHandler
from PySide6.QtCore import Qt
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QHBoxLayout,
    QPushButton,
    QSizePolicy,
    QSpacerItem,
    QWidget,
)


class ButtonWidget(QWidget):
    def __init__(self, events_handler, settings, current_theme, parent=None):
        """
        Initialize the ButtonWidget.
        """
        super().__init__(parent)
        self._settings = settings
        self._events_handler = events_handler
        self._current_theme = current_theme

        self.init_button_widget()

    def init_button_widget(self):
        """
        Initialize the button widget.
        """
        self.button_container_0 = self.create_button_container_layout(
            [0, 1], alignment=Qt.AlignmentFlag.AlignLeft, spacing=-1
        )

        self.button_container_1 = self.create_button_container_layout(
            [2, 3], alignment=Qt.AlignmentFlag.AlignRight, spacing=0
        )

    def create_button_container_layout(self, button_indices, alignment, spacing):
        """
        Create the button layout.
        """
        container_widget = QWidget()
        button_layout = QHBoxLayout()
        button_layout.setAlignment(alignment)

        container_widget.setLayout(button_layout)

        theme_handler = ThemeHandler(self._settings, self._current_theme)
        current_theme = theme_handler.get_current_theme()

        for button_index in button_indices:
            if len(BUTTONS) > button_index:
                button_data = BUTTONS[button_index]

                button = QPushButton(self)
                button.setObjectName(button_data["title"])
                button.setFixedSize(*button_data["size"])

                if button_data["icon_path"] != None:
                    if button_data["index"] == 0:
                        theme_icon_path = ICONS_FILE_PATHS["theme"][current_theme]
                        button.setIcon(QIcon(theme_icon_path))
                    elif button_data["index"] == 1:
                        viewer_icon_path = ICONS_FILE_PATHS["viewer"][current_theme]
                        button.setIcon(QIcon(viewer_icon_path))
                elif button_data["icon_path"] == None:
                    button.setText(button_data["title"])

                button.setProperty("index", button_data["index"])

                button_layout.addWidget(button)

                if button_index != button_indices[-1]:
                    if spacing == -1:
                        spacer_item = QSpacerItem(
                            button.sizeHint().width(),
                            button.sizeHint().height(),
                            QSizePolicy.Policy.Expanding,
                            QSizePolicy.Policy.Minimum,
                        )
                        button_layout.addItem(spacer_item)
                    else:
                        button_layout.addSpacing(spacing)

                button.clicked.connect(
                    functools.partial(
                        self._events_handler.on_button_clicked_event,
                        button_data["index"],
                    )
                )

        return container_widget
