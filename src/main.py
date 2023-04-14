import os
import sys

from PySide6.QtCore import QMargins, QPoint, QRegularExpression, Qt, Signal
from PySide6.QtGui import (
    QFont,
    QIcon,
    QIntValidator,
    QRegularExpressionValidator,
    QValidator,
)
from PySide6.QtWidgets import (
    QApplication,
    QGridLayout,
    QGroupBox,
    QHBoxLayout,
    QLabel,
    QLineEdit,
    QMainWindow,
    QMessageBox,
    QPushButton,
    QSizePolicy,
    QStyleFactory,
    QVBoxLayout,
    QWidget,
)

from constants import (
    COPYRIGHT_LABEL,
    COPYRIGHT_LABEL_SIZE,
    COPYRIGHT_LABEL_STYLE,
    DATA_DIR_FILE,
    DATA_DIR_FOLDER,
    MAIN_UI_GROUPBOX_INPUT_FIELDS_DESC0,
    MAIN_UI_GROUPBOX_INPUT_FIELDS_DESC1,
    MAIN_UI_GROUPBOX_INPUT_FIELDS_DESC2,
    MAIN_UI_GROUPBOX_TITLE,
    ON_BACK_BUTTON_PRESSED_DESC,
    SAVE_UI_TEXT,
    UI_CONTENTS_MARGINS,
    UI_GROUPBOX_FONT_SIZE,
    UI_GROUPBOX_FONT_TYPE,
    UI_GROUPBOX_STYLESHEET,
    UI_ICON_PATH,
    UI_STYLE,
    UI_TITLE,
)


class MainUI(QMainWindow, QWidget):
    def __init__(self):
        super().__init__()
        self.main_layout = QVBoxLayout(self)
        self.main_layout.setAlignment(Qt.AlignmentFlag.AlignCenter)

        self.setup_ui()
        self.create_group_box()
        self.copyright_label()

        self.main_layout.addWidget(self.crlabel)
        self.main_layout.addWidget(self.group_box)

    def setup_ui(self):
        self.setWindowTitle(UI_TITLE)
        self.setWindowIcon(QIcon(UI_ICON_PATH))
        self.margins = QMargins(*UI_CONTENTS_MARGINS)
        self.setContentsMargins(self.margins)
        self.setStyle(QStyleFactory.create(UI_STYLE))

        self.adjustSize()

    def copyright_label(self):
        self.crlabel = QLabel(COPYRIGHT_LABEL)
        self.crlabel.setFont(QFont(UI_GROUPBOX_FONT_TYPE, COPYRIGHT_LABEL_SIZE))
        self.crlabel.setStyleSheet(COPYRIGHT_LABEL_STYLE)
        self.crlabel.setAlignment(
            Qt.AlignmentFlag.AlignLeft | Qt.AlignmentFlag.AlignBottom
        )

    def center_window(self):
        screen_geometry = QApplication.screens()[0].geometry()
        center_point = screen_geometry.center()
        window_center = self.rect().center()
        window_top_left = QPoint(
            center_point.x() - window_center.x(), center_point.y() - window_center.y()
        )
        self.move(window_top_left)

    def create_group_box(self):
        """
        This function creates a group box with input fields and applies styling to it.
        """
        self.group_box = QGroupBox(self)
        self.group_box_layout = QHBoxLayout(self.group_box)
        self.group_box.setStyleSheet(UI_GROUPBOX_STYLESHEET)
        self.group_box.setTitle(MAIN_UI_GROUPBOX_TITLE)
        self.group_box.setFont(
            QFont(UI_GROUPBOX_FONT_TYPE, UI_GROUPBOX_FONT_SIZE, QFont.Weight.Bold)
        )
        self.group_box.setAlignment(Qt.AlignmentFlag.AlignHCenter)
        self.group_box.setFlat(True)

        self.group_box.setSizePolicy(
            QSizePolicy.Policy.Maximum, QSizePolicy.Policy.Maximum
        )
        self.group_box_layout.setContentsMargins(*UI_CONTENTS_MARGINS)

        self.create_input_fields()
        self.group_box_layout.addLayout(self.input_fields_layout)

    def onClose(self):
        """
        This function handles the action of pressing the close button on the window
        and prompts the user to save changes before returning to the main UI.
        """
        self.save_ui_handler()

    def show(self):
        """
        This function calls the parent class's show method and then centers the window.
        """
        super().show()
        self.center_window()

    def save_ui_handler(self):
        """
        This function handles the action of pressing the back button in a UI and prompts the user to
        save changes before returning to the main UI.
        """
        reply = QMessageBox.question(
            self,
            *ON_BACK_BUTTON_PRESSED_DESC,
            QMessageBox.StandardButton.Yes
            | QMessageBox.StandardButton.No
            | QMessageBox.StandardButton.Cancel,
        )
        if reply == QMessageBox.StandardButton.Yes:
            self.save_inputs()
            self.close()

        elif reply == QMessageBox.StandardButton.No:
            self.close()

    def saved_successful_ui_handler(self):
        """
        This function handles the action of pressing the save button in a UI and prompts a message before returning.
        """
        QMessageBox.information(
            self, UI_TITLE, SAVE_UI_TEXT, QMessageBox.StandardButton.Ok
        )

    key_pressed = Signal(int)

    def keyPressEvent(self, event):
        """
        This function handles key press events and closes the main UI or goes back to the previous
        screen depending on the key pressed.
        """
        # tfccui_instance = TFCCUI()
        key = event.key()
        self.key_pressed.emit(key)
        super().keyPressEvent(event)
        if key == Qt.Key.Key_Escape or (
            key == Qt.Key.Key_Q
            and event.modifiers() == Qt.KeyboardModifier.ControlModifier
        ):
            # if tfccui_instance.isVisible():
            #     self.tfcui_instance.close()

            self.close()

    def save_inputs(self):
        """
        This function saves input values from input widgets to a text file.
        """
        input_values = {}
        for i, input_widget in enumerate(self.create_input_fields.inputs):
            input_text = input_widget.text()
            input_values[i] = input_text

        data_dir = DATA_DIR_FOLDER

        if not os.path.exists(data_dir):
            os.makedirs(data_dir)

        file_path = os.path.join(data_dir, DATA_DIR_FILE)

        with open(file_path, "w") as f:
            for key, value in input_values.items():
                f.write(f"{key}: {value}\n")

        self.saved_successful_ui_handler()

    def create_input_fields(self):
        """
        This function creates input fields with labels and placeholders in a QGridLayout.
        """
        self.labels = []
        self.inputs = []
        self.input_fields_layout = QGridLayout()

        for i, (desc0, desc1) in enumerate(
            zip(
                MAIN_UI_GROUPBOX_INPUT_FIELDS_DESC0, MAIN_UI_GROUPBOX_INPUT_FIELDS_DESC2
            )
        ):
            label0 = QLabel(desc0)
            input = QLineEdit()
            label1 = QLabel(desc1)

            self.labels.extend([label0, label1])
            self.inputs.append(input)

            input_validate = QRegularExpressionValidator()
            input.setValidator(input_validate)

            self.input_fields_layout.addWidget(label0, i, 0)
            self.input_fields_layout.addWidget(input, i, 1)
            self.input_fields_layout.addWidget(label1, i, 2)

            input.setPlaceholderText(MAIN_UI_GROUPBOX_INPUT_FIELDS_DESC1[i])

            if "text" in MAIN_UI_GROUPBOX_INPUT_FIELDS_DESC1[i]:
                input_validate.setRegularExpression(QRegularExpression(".+"))
            elif "number" in MAIN_UI_GROUPBOX_INPUT_FIELDS_DESC1[i]:
                input_validate = QIntValidator()
                input_validate.setBottom(0)
                input.setValidator(input_validate)
            else:
                input_validate.setRegularExpression(QRegularExpression(".*"))

    def input_validator(
        self, text_input: str, pos: int, obj_num: int
    ) -> tuple[QValidator.State, str, int]:
        placeholder = self.inputs[obj_num].placeholderText()
        if "text" in placeholder:
            if text_input == "":
                return QValidator.State.Intermediate, text_input, pos
            elif text_input.isalpha():
                return QValidator.State.Acceptable, text_input, pos
            else:
                return QValidator.State.Invalid, text_input, pos
        elif "number" in placeholder:
            if text_input == "":
                return QValidator.State.Intermediate, text_input, pos
            elif text_input.isnumeric() and int(text_input) >= 0:
                return QValidator.State.Acceptable, text_input, pos
            else:
                return QValidator.State.Invalid, text_input, pos
        else:
            return QValidator.State.Acceptable, text_input, pos


def run():
    """
    Initializes QApplication and MainUi object,
    then runs the application event loop until the application is exited.
    """
    app = QApplication(sys.argv)
    main_ui = MainUI()
    main_ui.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    run()
