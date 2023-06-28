from constants import DEBUG_NAME
from handlers.visibility_handler import VisibilityHandler
from PySide6.QtWidgets import (
    QFormLayout,
    QGridLayout,
    QHBoxLayout,
    QSizePolicy,
    QSpacerItem,
    QVBoxLayout,
    QWidget,
)


class ContainerModule(QWidget):
    def __init__(self, module_index, margins=None, alignment=None, parent=None):
        """
        Initialize the ContainerModule.
        """
        super().__init__(parent)
        self.visibility_handler = VisibilityHandler()

        self.setup_module(module_index, margins, alignment)

        # self.visibility_handler.load_visibility_state(self, module_index)

    def setup_module(self, module_index, margins, alignment):
        """
        Setup the ContainerModule.
        """
        if module_index == "VBox":
            layout = QVBoxLayout(self)

        elif module_index == "HBox":
            layout = QHBoxLayout(self)

        elif module_index == "Grid":
            layout = QGridLayout(self)

        elif module_index == "Form":
            layout = QFormLayout(self)

        else:
            raise ValueError(f"Invalid layout type: {module_index}")

        if margins is not None:
            layout.setContentsMargins(*margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if alignment is not None:
            layout.setAlignment(alignment)

        self.setLayout(layout)

    def add_widget(
        self,
        widget,
        row=None,
        column=None,
        rowspan=None,
        columnspan=None,
        alignment=None,
    ):
        """
        Add a widget to the container.
        """
        layout = self.layout()
        if isinstance(layout, QGridLayout):
            if alignment is not None and (rowspan and columnspan is not None):
                layout.addWidget(widget, row, column, rowspan, columnspan, alignment)

            elif alignment is not None and (rowspan or columnspan is None):
                layout.addWidget(widget, row, column, alignment)

            elif alignment is None and (rowspan and columnspan is not None):
                layout.addWidget(widget, row, column, rowspan, columnspan)

            elif alignment is None and (rowspan or columnspan is None):
                layout.addWidget(widget, row, column)

            elif widget is None or row is None or column is None:
                raise ValueError(
                    DEBUG_NAME + "widget, row and column indices must be specified."
                )

        else:
            layout.addWidget(widget)

        if rowspan == -1:
            layout.setRowStretch(row, layout.rowCount())

        if columnspan == -1:
            layout.setColumnStretch(column, layout.columnCount())

    # FIXME: labelmodule(0) and button6 not being affected by spacer.
    def add_spacer(self, size=None):
        """
        Add a stretch to the container.
        """
        layout = self.layout()
        if isinstance(layout, (QVBoxLayout, QHBoxLayout, QFormLayout)):
            spacer_item = QSpacerItem(
                0, 0, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
            )
            if size is not None:
                spacer_item.changeSize(size, 0, QSizePolicy.Policy.Fixed)

            layout.addItem(spacer_item)

        elif isinstance(layout, QGridLayout):
            empty_spacer = QSpacerItem(
                0, 0, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
            )
            layout.addItem(empty_spacer, layout.rowCount(), 0)
            layout.setRowStretch(layout.rowCount(), 1)
            layout.setColumnStretch(layout.columnCount(), 1)

        else:
            raise TypeError(
                DEBUG_NAME
                + "Stretch can only be added to QVBoxLayout, QHBoxLayout, QFormLayout, or QGridLayout."
            )

    def toggle_module(self, module_index):
        """
        Toggle the visibility of the label.
        """
        self.visibility_handler.toggle_visibility_state(self, module_index)
