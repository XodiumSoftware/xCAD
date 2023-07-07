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
        super().__init__(parent)
        self.setup_module(layout_type, margins, alignment)

    def setup_module(self, layout_type, margins, alignment):
        layout = self._get_layout(layout_type)
        layout.setContentsMargins(*margins) if margins else layout.setContentsMargins(
            0, 0, 0, 0
        )
        layout.setAlignment(alignment) if alignment else None
        self.setLayout(layout)

    def _get_layout(self, layout_type):
        layouts = {
            "VBox": QVBoxLayout(),
            "HBox": QHBoxLayout(),
            "Grid": QGridLayout(),
        }
        layout = layouts.get(layout_type)
        if layout is None:
            raise ValueError(f"Invalid layout type: {layout_type}")
        return layout

    def add_spacer(self, size=None):
        layout = self.layout()
        if isinstance(layout, (QVBoxLayout, QHBoxLayout, QFormLayout)):
            spacer_item = QSpacerItem(
                0, 0, QSizePolicy.Policy.Expanding, QSizePolicy.Policy.Expanding
            )
            if size is not None:
                spacer_item.changeSize(
                    size, size, QSizePolicy.Policy.Fixed, QSizePolicy.Policy.Fixed
                )
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
                "Stretch can only be added to QVBoxLayout, QHBoxLayout, QFormLayout, or QGridLayout."
            )

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
            raise ValueError("Widget, row, and column indices must be specified.")

        if rowspan == "auto":
            rowspan = layout.rowCount()

        if columnspan == "auto":
            columnspan = layout.columnCount()

        if alignment is not None:
            if rowspan is not None and columnspan is not None:
                layout.addWidget(widget, row, column, rowspan, columnspan, alignment)
            else:
                layout.addWidget(widget, row, column, alignment)
        else:
            if rowspan is not None and columnspan is not None:
                layout.addWidget(widget, row, column, rowspan, columnspan)
            else:
                layout.addWidget(widget, row, column)
