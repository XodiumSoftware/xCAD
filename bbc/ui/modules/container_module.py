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
    def __init__(self, layout_type, margins=None, widget_alignment=None, parent=None):
        """
        Initialize the ContainerModule.
        """
        super().__init__(parent)
        self.visibility_handler = VisibilityHandler()

        self.setup_module(layout_type, margins, widget_alignment)

    def setup_module(self, layout_type, margins, widget_alignment):
        """
        Setup the ContainerModule.
        """
        layout = self._get_layout(layout_type)
        if margins is not None:
            layout.setContentsMargins(*margins)

        else:
            layout.setContentsMargins(0, 0, 0, 0)

        if widget_alignment is not None:
            layout.setAlignment(widget_alignment)
        self.setLayout(layout)

    def _get_layout(self, layout_type):
        """
        Get the appropriate layout based on the layout_type.
        """
        if layout_type == "VBox":
            return QVBoxLayout(self)

        elif layout_type == "HBox":
            return QHBoxLayout(self)

        elif layout_type == "Grid":
            return QGridLayout(self)

        elif layout_type == "Form":
            return QFormLayout(self)

        else:
            raise ValueError(f"Invalid layout type: {layout_type}")

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
            self._add_widget_to_grid_layout(
                layout, widget, row, column, rowspan, columnspan, alignment
            )

        else:
            layout.addWidget(widget)

    def _add_widget_to_grid_layout(
        self, layout, widget, row, column, rowspan, columnspan, alignment
    ):
        """
        Add a widget to a QGridLayout.
        """
        if widget is None or row is None or column is None:
            raise ValueError(
                f"{DEBUG_NAME} Widget, row, and column indices must be specified."
            )
        if alignment is not None and (rowspan is not None and columnspan is not None):
            layout.addWidget(widget, row, column, rowspan, columnspan, alignment)

        elif alignment is not None and (rowspan is not None or columnspan is None):
            layout.addWidget(widget, row, column, alignment)

        elif alignment is None and (rowspan is not None and columnspan is not None):
            layout.addWidget(widget, row, column, rowspan, columnspan)

        else:
            layout.addWidget(widget, row, column)

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
                f"{DEBUG_NAME} Stretch can only be added to QVBoxLayout, QHBoxLayout, QFormLayout, or QGridLayout."
            )

    # def toggle_module(self, layout_type=None):
    #     """
    #     Toggle the visibility of the label.
    #     """
    #     self.visibility_handler.toggle_visibility_state(self, layout_type)
