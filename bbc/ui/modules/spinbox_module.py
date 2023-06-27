from constants import DEBUG_NAME, SPINBOXES
from PySide6.QtWidgets import QSpinBox, QVBoxLayout, QWidget


class SpinBoxModule(QWidget):
    def __init__(self, spinbox_index, margins=None, alignment=None, parent=None):
        """
        Initialize the SpinBoxModule.
        """
        super().__init__(parent)
        self.margins = margins
        self.alignment = alignment
        self.setup_spinbox_module(spinbox_index)

    def setup_spinbox_module(self, spinbox_index):
        """
        Setup the SpinBoxModule.
        """
        layout = QVBoxLayout(self)

        spinbox_data = next(
            (spinbox for spinbox in SPINBOXES if spinbox["index"] == spinbox_index),
            None,
        )

        if spinbox_data:
            spinbox = self.create_spinbox_module(spinbox_data)
            layout.addWidget(spinbox)

        else:
            print(DEBUG_NAME + f'"index" {spinbox_index} not found in SPINBOXES')

        if self.margins is not None:
            layout.setContentsMargins(*self.margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if self.alignment is not None:
            layout.setAlignment(*self.alignment)

        self.setLayout(layout)

    def create_spinbox_module(self, spinbox_data):
        """
        Create a spinbox module.
        """
        spinbox = QSpinBox()
        spinbox.setMinimum(spinbox_data["minimum"])
        spinbox.setMaximum(spinbox_data["maximum"])
        spinbox.setValue(spinbox_data["default"])
        spinbox.setSingleStep(spinbox_data["step"])
        spinbox.setStyleSheet(spinbox_data["stylesheet"])

        return spinbox
