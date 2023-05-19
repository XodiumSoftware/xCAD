from constants import UI_ICON_PATH, UI_TITLE
from handlers.events_handler import EventsHandler
from handlers.theme_handler import ThemeHandler
from handlers.ui_handler import UIHandler
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QGridLayout,
    QMainWindow,
    QSizePolicy,
    QSpacerItem,
    QWidget,
)
from ui.modules.button_widget import ButtonWidget
from ui.modules.label_widget import LabelWidget
from ui.modules.object_viewer_widget import ObjectViewerWidget
from ui.modules.settings_list_widget import SettingsListWidget


class MainUI(QMainWindow, UIHandler, ThemeHandler, EventsHandler):
    def __init__(self):
        super().__init__()

        # Call functions here.
        self.setCentralWidget(QWidget())
        self.initMainUI()
        self.quit_on_key_press_event()
        # self.load_theme_handler()

    def initMainUI(self):
        # Set up the main window
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))

        # Add the widget classes
        settings_widget = SettingsListWidget(self)
        button_widget = ButtonWidget(self)
        label_widget = LabelWidget(0, self)
        object_viewer_ui = ObjectViewerWidget(self)

        # Create a new layout for the central widget
        main_ui_layout = QGridLayout()
        main_ui_layout.setVerticalSpacing(5)
        main_ui_layout.setHorizontalSpacing(5)
        main_ui_layout.setContentsMargins(5, 5, 5, 5)

        # Add Modules to the layout
        main_ui_layout.addWidget(button_widget, 0, 0)
        main_ui_layout.addWidget(settings_widget, 1, 0)
        main_ui_layout.addWidget(label_widget, 2, 0)

        if object_viewer_ui.isVisible():
            # Add an empty spacer item to push the widgets to the left
            main_ui_layout.addItem(
                QSpacerItem(
                    0, 0, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Preferred
                ),
                0,
                1,
            )
            main_ui_layout.addWidget(object_viewer_ui, 1, 1)

        # Set the central widget
        central_widget = QWidget()
        central_widget.setLayout(main_ui_layout)
        self.setCentralWidget(central_widget)

        # Calculate the desired width of the main window
        total_columns_width = settings_widget.get_total_columns_width()
        total_columns_width += main_ui_layout.horizontalSpacing() * (
            settings_widget.table_widget.columnCount() - 1
        )
        window_width = (
            total_columns_width
            + main_ui_layout.contentsMargins().left()
            + main_ui_layout.contentsMargins().right()
        )

        # Set the initial width of the main window and allow manual resizing
        self.resize(window_width, self.height())

        # Center the window on the primary screen
        self.center_ui_on_screen_handler(self)
