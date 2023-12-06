from PySide6.QtWidgets import QLayout, QWidget


class ContainerHandler:
    """A class used to represent a container handler."""

    def __init__(self, layout: QLayout, modules: list[QWidget]) -> None:
        """Initialize the class.

        Args:
            layout (QLayout): A layout.
            modules (list[QWidget]): A list of modules.
        """
        for module in modules:
            layout.addWidget(module)
