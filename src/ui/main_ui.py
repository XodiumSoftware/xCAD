from PySide6.QtCore import QPoint, QSize, Qt
from PySide6.QtGui import QFont, QIcon
from PySide6.QtWidgets import (
    QApplication,
    QFormLayout,
    QGroupBox,
    QHBoxLayout,
    QLabel,
    QPushButton,
    QSizePolicy,
    QSpacerItem,
    QVBoxLayout,
    QWidget,
)

from constants import (
    BUTTON_ICON_PATH,
    CONFIG_UI_TITLE,
    MAIN_UI_BUTTON_HEIGHT,
    MAIN_UI_GROUPBOX_TITLE,
    UI_CONTENTS_MARGINS,
    UI_FONT_TYPE,
    UI_GROUPBOX_FONT_SIZE,
    UI_GROUPBOX_STYLESHEET,
    UI_ICON_PATH,
    UI_TITLE,
)
from ui.config_ui import ConfigUI
from ui.setup_ui import SetupUI


class MainUI(SetupUI):
    def __init__(self):
        super().__init__()

        self.config_ui_instance = ConfigUI()
        self.form_layout = QFormLayout(self)
        self.form_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.center_window()
        self.create_main_ui_label()
        self.create_group_box()
        self.create_button()

        self.config_ui_open = False

        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))
        self.setGeometry(0, 0, 500, 300)
        self.setMinimumSize(500, 300)

        self.config_ui_instance.setParent(self)
        self.config_ui_instance.move(
            self.geometry().right() + 10, self.geometry().top()
        )
        self.config_ui_instance.hide()

    def create_main_ui_label(self):
        self.main_label = QLabel(MAIN_UI_GROUPBOX_TITLE)
        self.main_label.setAlignment(Qt.AlignmentFlag.AlignCenter)
        self.main_label.setFont(
            QFont(UI_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold)
        )
        self.form_layout.addRow(self.main_label)

    def create_group_box(self):
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout()
        self.group_box_layout.setContentsMargins(*UI_CONTENTS_MARGINS)
        self.group_box_layout.setAlignment(Qt.AlignmentFlag.AlignHCenter)
        self.group_box.setFlat(True)
        self.group_box.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum
        )
        self.group_box.setStyleSheet(UI_GROUPBOX_STYLESHEET)
        self.group_box.setFont(
            QFont(UI_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold)
        )
        self.form_layout.addRow(self.group_box)

        spacer_widget = QWidget()
        spacer_layout = QVBoxLayout()
        spacer_layout.addItem(self.create_space())
        spacer_widget.setLayout(spacer_layout)
        self.form_layout.addRow(spacer_widget)

        self.form_layout.addRow(self.create_crlabel())

    def keyPressEvent(self, event):
        # TODO: Combine keyPressEvent with the similar on in config_ui and move them to setup_ui.py.
        """
        This function is called when certain keys are pressed.
        """
        if event.key() == Qt.Key.Key_Escape or (
            event.key() == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            self.close()
            if self.config_ui_instance:
                self.config_ui_instance.close()

        else:
            super().keyPressEvent(event)

    def closeEvent(self, event):
        """
        This function closes CONFIG_UI when triggered in the MainUI.
        """
        self.config_ui_instance.close()
        event.accept()

    def create_space(self):
        spacer = QSpacerItem(
            20, 40, QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Expanding
        )
        return spacer

    def create_button(self):
        self.config_button = QPushButton(self)
        self.config_button.setIcon(QIcon(BUTTON_ICON_PATH))
        self.config_button.setToolTip("Toggle " + CONFIG_UI_TITLE)
        self.config_button.setFixedSize(MAIN_UI_BUTTON_HEIGHT, MAIN_UI_BUTTON_HEIGHT)
        self.config_button.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum
        )
        self.config_button.clicked.connect(self.toggle_config_ui)
        self.config_button.setIconSize(self.config_button.size() - QSize(10, 10))
        self.config_button.move(self.width() - self.config_button.width() - 10, 10)

    def center_window(self):
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
        self.config_ui_instance.resize(self.size())
        self.config_button.move(self.width() - self.config_button.width() - 10, 10)

    def toggle_config_ui(self):
        if not self.config_ui_open:
            self.config_ui_instance.show()
            self.config_ui_instance.move(
                self.geometry().right() + 2, self.geometry().top()
            )
        else:
            self.config_ui_instance.hide()

        self.config_ui_open = not self.config_ui_open
