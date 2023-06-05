from constants import SPINBOXES
from PySide6.QtWidgets import QSpinBox, QVBoxLayout, QWidget


class SpinBoxModule(QWidget):
    def __init__(self, spinbox_index, parent=None):
        """
        Initialize the SpinBoxModule.
        """
        super().__init__(parent)
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
        spinbox.setSizePolicy(*spinbox_data["size_policy"])
        return spinbox
