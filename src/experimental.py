import sys

from PySide6.QtCore import QPoint, QRegularExpression, Qt
from PySide6.QtGui import QFont, QIcon, QIntValidator, QRegularExpressionValidator
from PySide6.QtWidgets import (
    QApplication,
    QGridLayout,
    QGroupBox,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QPushButton,
    QSizePolicy,
    QVBoxLayout,
)

from constants import (
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0,
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1,
    CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC2,
    CONFIG_UI_TITLE,
    MAIN_UI_GROUPBOX_TITLE,
    UI_CONTENTS_MARGINS,
    UI_FONT_TYPE,
    UI_GROUPBOX_FONT_SIZE,
    UI_GROUPBOX_STYLESHEET,
    UI_ICON_PATH,
    UI_TITLE,
)
from ui.setup_ui import SetupUI


class MainUI(SetupUI):
    def __init__(self):
        super().__init__()
        # Center the window on the screen
        self.center_window()

        # Add buttons
        self.create_button()

        # Add labels
        self.MainUILabel()
        self.copyright_label()

        # Initialize variable to keep track of whether CONFIG_UI is open
        self.config_ui_open = False

        # Set the window title and size
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))
        self.setGeometry(0, 0, 400, 300)

        self.main_layout.addWidget(self.main_label)
        self.main_layout.addWidget(self.crlabel)

    def MainUILabel(self):
        self.main_label = QLabel(MAIN_UI_GROUPBOX_TITLE)
        self.main_label.setFont(QFont(UI_FONT_TYPE))
        self.main_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.main_label.setFont(
            QFont(UI_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold)
        )

    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_Escape or (
            event.key() == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            self.close()
            if self.config_ui:
                self.config_ui.close()

        else:
            super().keyPressEvent(event)

    # def moveEvent(self, event):
    #     super().moveEvent(event)
    #     offset = self.pos() - event.oldPos()
    #     new_pos = self.config_ui.pos() + offset
    #     self.config_ui.move(new_pos)

    # TODO: Fix this closing ConfigUI when moving.
    # TODO: Fix toggle_button centering the MainUI on the screen.

    def onClose(self, event):
        self.config_ui.close()
        event.accept()

    # FIXME: Fix this not closing ConfigUI when the onClose event is triggered in the MainUI.

    def create_button(self):
        # Create the button to open and close CONFIG_UI
        self.btn_toggle = QPushButton(self)
        self.btn_toggle.setIcon(QIcon.fromTheme("arrow-right"))
        self.btn_toggle.setToolTip("Open CONFIG_UI")
        self.btn_toggle.setFixedSize(20, 20)  # set a fixed size for the button
        self.btn_toggle.move(
            self.width() - self.btn_toggle.width() - 10, 10
        )  # align the button to the top right corner
        self.btn_toggle.clicked.connect(self.toggle_config_ui)

    def center_window(self):
        """
        This function centers a window on the screen.
        """
        screen_geometry = QApplication.screens()[0].geometry()
        center_point = screen_geometry.center()
        window_center = self.rect().center()
        window_top_left = QPoint(
            center_point.x() - window_center.x(), center_point.y() - window_center.y()
        )
        self.move(window_top_left)

    def show(self):
        """
        This function calls the parent class's show method and then centers the window.
        """
        super().show()
        self.center_window()

    def resizeEvent(self, event):
        super().resizeEvent(event)
        self.btn_toggle.move(
            self.width() - self.btn_toggle.width() - 10, 10
        )  # reposition the button when the window is resized

    def toggle_config_ui(self):
        if not self.config_ui_open:
            # Create and show CONFIG_UI
            self.config_ui = ConfigUI()
            self.config_ui.setGeometry(
                self.geometry().right() + 10,
                self.geometry().top(),
                self.config_ui.width(),
                self.height(),
            )
            self.config_ui.show()

            # Update variable to indicate that CONFIG_UI is open
            self.config_ui_open = True
        else:
            # Close CONFIG_UI
            self.config_ui.close()

            # Update variable to indicate that CONFIG_UI is closed
            self.config_ui_open = False

        # Center MAIN_UI on the screen
        screen_geometry = QApplication.screens()[0].geometry()
        center_point = screen_geometry.center()
        window_center = self.rect().center()
        window_top_left = QPoint(
            center_point.x() - window_center.x(), center_point.y() - window_center.y()
        )
        self.move(window_top_left)

        # If CONFIG_UI is open, attach it to MAIN_UI
        if self.config_ui_open:
            main_ui_rect = self.geometry()
            config_ui_rect = self.config_ui.geometry()
            self.config_ui.setGeometry(
                main_ui_rect.right() + 2,
                main_ui_rect.top(),
                config_ui_rect.width(),
                main_ui_rect.height(),
            )

        # Raise both windows to the top
        self.activateWindow()
        self.raise_()
        if self.config_ui_open:
            self.config_ui.activateWindow()
            self.config_ui.raise_()


class ConfigUI(SetupUI):
    def __init__(self):
        super().__init__()

        # Create some content for CONFIG_UI
        self.setWindowFlags(
            Qt.WindowType.WindowTitleHint | Qt.WindowType.CustomizeWindowHint
        )
        self.setWindowTitle(CONFIG_UI_TITLE)
        layout = QVBoxLayout(self)

        self.create_group_box()
        self.main_layout.addWidget(self.group_box)

        self.main_layout.addWidget(self.crlabel)

    def keyPressEvent(self, event):
        if event.key() == Qt.Key.Key_Escape or (
            event.key() == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            self.close()
        else:
            super().keyPressEvent(event)

    def create_group_box(self):
        """
        This function creates a group box with input fields and applies styling to it.
        """
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box.setStyleSheet(UI_GROUPBOX_STYLESHEET)
        self.group_box.setFont(
            QFont(UI_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold)
        )
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignHCenter)
        self.group_box.setFlat(True)

        self.group_box.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum
        )
        self.group_box_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        self.create_input_fields()
        self.group_box_layout.addLayout(self.input_fields_layout)

    def create_input_fields(self):
        """
        This function creates input fields with labels and placeholders in a QGridLayout.
        """
        self.labels = []
        self.inputs = []
        self.input_fields_layout = QGridLayout()

        for i, (desc0, desc1) in enumerate(
            zip(
                CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC0,
                CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC2,
            )
        ):
            label0 = QLabel(desc0, self)
            input = QLineEdit(self)
            label1 = QLabel(desc1, self)

            self.labels.extend([label0, label1])
            self.inputs.append(input)

            input_validate = QRegularExpressionValidator()
            input.setValidator(input_validate)

            self.input_fields_layout.addWidget(label0, i, 0)
            self.input_fields_layout.addWidget(input, i, 1)
            self.input_fields_layout.addWidget(label1, i, 2)

            input.setPlaceholderText(CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1[i])

            if "text" in CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1[i]:
                input_validate.setRegularExpression(QRegularExpression(".+"))
            elif "number" in CONFIG_UI_GROUPBOX_INPUT_FIELDS_DESC1[i]:
                input_validate = QIntValidator()
                input_validate.setBottom(0)
                input.setValidator(input_validate)
            else:
                input_validate.setRegularExpression(QRegularExpression(".*"))
