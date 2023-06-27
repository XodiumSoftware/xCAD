from constants import DEBUG_NAME
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
    def __init__(self, layout_type, margins=None, alignment=None, parent=None):
        """
        Initialize the ContainerModule.
        """
        super().__init__(parent)
        self.margins = margins
        self.alignment = alignment
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

        if self.margins is not None:
            layout.setContentsMargins(*self.margins)
        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if self.alignment is not None:
            layout.setAlignment(*self.alignment)

        self.setLayout(layout)

    def set_container_margins(self, margins):
        """
        Set the margins of the container.
        """
        if len(margins) != 4:
            raise ValueError(
                DEBUG_NAME + "Margins should be a tuple or list of four integers."
            )
        if self.layout() is not None:
            self.layout().setContentsMargins(*margins)

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
