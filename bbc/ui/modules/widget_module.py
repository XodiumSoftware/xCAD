from constants import (
    DEBUG_NAME,
    MAIN_UI_BUTTON_SIZE,
    MAIN_UI_GROUPBOX_TITLE,
    THEME_BUTTON_ICON_DEFAULT_PATH,
    UI_CONTENTS_MARGINS,
    VIEWER_UI_BUTTON_ICON_LIGHT_PATH,
    WIDGET_MODULE_STYLESHEET,
)
from handlers.events_handler import EventsHandler
from PySide6.QtGui import QIcon, Qt
from PySide6.QtWidgets import (
    QFrame,
    QHBoxLayout,
    QLabel,
    QPushButton,
    QScrollArea,
    QSizePolicy,
    QVBoxLayout,
    QWidget,
)


class WidgetModule(QWidget, EventsHandler):
    def __init__(self):
        super().__init__()

        # Creation of the widget's layout
        wm_layout = QVBoxLayout(self)

        # Add functions to the layout
        wm_layout.addWidget(self.button_setup())
        wm_layout.addWidget(self.widget_setup())

    def widget_setup(self):
        # Creation of a new QWidget object
        widget_setup = QWidget(self)

        # Create a new QFrame object to use as a container for the inner widgets
        inner_container = QFrame(widget_setup)
        inner_container.setObjectName("InnerContainer")
        inner_container_layout = QHBoxLayout(inner_container)
        inner_container_layout.setContentsMargins(*UI_CONTENTS_MARGINS)
        inner_container_layout.setSpacing(10)

        # Create some inner widgets and add them to the inner container layout
        label = QLabel(MAIN_UI_GROUPBOX_TITLE, inner_container)
        label.setObjectName("MyLabel")
        label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        inner_container_layout.addWidget(label)

        # Add the inner container to the main widget layout
        wm_layout = QVBoxLayout(widget_setup)
        wm_layout.addWidget(inner_container)

        # Set the stylesheet for the widget
        widget_setup.setStyleSheet(WIDGET_MODULE_STYLESHEET)

        return widget_setup

    def button_setup(self):
        # Create a new QWidget object
        button_widget = QWidget(self)

        # Create a layout for the widget
        button_layout = QHBoxLayout(button_widget)

        # Create the theme button
        theme_button = QPushButton(button_widget)
        theme_button.setObjectName("ThemeButton")
        theme_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
        theme_button.setIcon(QIcon(THEME_BUTTON_ICON_DEFAULT_PATH))

        # Create the viewer button
        viewer_button = QPushButton(button_widget)
        viewer_button.setObjectName("ViewerButton")
        viewer_button.setFixedSize(*MAIN_UI_BUTTON_SIZE)
        viewer_button.setIcon(QIcon(VIEWER_UI_BUTTON_ICON_LIGHT_PATH))

        # Add the buttons to the widget layout
        button_layout.addWidget(theme_button)
        button_layout.addStretch(1)
        button_layout.addWidget(viewer_button)

        # Connect the clicked signal to the EventsHandler.on_button_clicked_event method
        theme_button.clicked.connect(self.on_button_clicked_event)
        viewer_button.clicked.connect(self.on_button_clicked_event)

        # Set the fixed height of the button widget to match the height of the buttons
        button_widget.setFixedHeight(theme_button.height() + 10)

        # Return the button widget
        return button_widget

    def input_setup(self):
        # Create a QScrollArea object
        scroll_area = QScrollArea()
        scroll_area.setVerticalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAsNeeded)
        scroll_area.setHorizontalScrollBarPolicy(Qt.ScrollBarPolicy.ScrollBarAsNeeded)
        scroll_area.setStyleSheet("")  # TODO: Add style sheet.
        scroll_area.setSizePolicy(
            QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
        )

        # Add the QScrollArea to the layout

        # Call widgets
