from PySide6.QtWidgets import (
    QFormLayout,
    QGridLayout,
    QHBoxLayout,
    QSizePolicy,
    QVBoxLayout,
    QWidget,
)


class ContainerModule(QWidget):
    def __init__(self, layout_type, parent=None):
        """
        Initialize the ContainerModule.
        """
        super().__init__(parent)
        self.setup_container_module(layout_type)

    def setup_container_module(self, layout_type):
        """
        Setup the ContainerModule.
        """
        if layout_type == "VBox":
            layout = QVBoxLayout(self)
        elif layout_type == "HBox":
            layout = QHBoxLayout(self)
        elif layout_type == "Grid":
            layout = QGridLayout(self)
        elif layout_type == "Form":
            layout = QFormLayout(self)
        else:
            raise ValueError(f"Invalid layout type: {layout_type}")

        self.setLayout(layout)

    def add_widget(self, widget):
        """
        Add a widget to the container.
        """
        self.layout().addWidget(widget)

    def add_stretch(self):
        """
        Add a stretch to the container.
        """
        layout = self.layout()
        if isinstance(layout, (QVBoxLayout, QHBoxLayout, QFormLayout)):
            spacer_item = QWidget()
            spacer_item.setSizePolicy(
                QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
            )

            layout.addWidget(spacer_item)
        elif isinstance(layout, QGridLayout):
            empty_widget = QWidget()
            layout.addWidget(empty_widget)
            layout.setRowStretch(layout.rowCount(), 1)
            layout.setColumnStretch(layout.columnCount(), 1)
        else:
            raise TypeError(
                "Stretch can only be added to QVBoxLayout, QHBoxLayout, QFormLayout, or QGridLayout."
            )
