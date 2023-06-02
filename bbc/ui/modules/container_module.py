from PySide6.QtWidgets import (
    QBoxLayout,
    QFormLayout,
    QGridLayout,
    QHBoxLayout,
    QStackedLayout,
    QVBoxLayout,
    QWidget,
)


class ContainerModule(QWidget):
    def __init__(self, layout_type, parent=None):
        super().__init__(parent)
        self.init_container_module(layout_type)

    def init_container_module(self, layout_type):
        if layout_type == "VBox":
            layout = QVBoxLayout(self)
            layout.setSpacing(0)
        elif layout_type == "HBox":
            layout = QHBoxLayout(self)
            layout.setSpacing(0)
        elif layout_type == "Grid":
            layout = QGridLayout(self)
        elif layout_type == "Form":
            layout = QFormLayout(self)
        elif layout_type == "Box":
            layout = QBoxLayout(
                QBoxLayout.Direction.LeftToRight
                if layout_type == "Horizontal"
                else QBoxLayout.Direction.TopToBottom,
                self,
            )
            layout.setSpacing(0)
        elif layout_type == "Stacked":
            layout = QStackedLayout(self)
        else:
            raise ValueError(f"Invalid layout type: {layout_type}")

        layout.setContentsMargins(0, 0, 0, 0)

        self.setLayout(layout)

    def add_widget(self, widget):
        self.layout().addWidget(widget)
