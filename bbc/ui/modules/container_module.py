from PySide6.QtWidgets import QVBoxLayout, QWidget


class ContainerModule(QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.init_container_module()

    def init_container_module(self):
        layout = QVBoxLayout(self)
        layout.setContentsMargins(0, 0, 0, 0)
        layout.setSpacing(0)
        self.setLayout(layout)
