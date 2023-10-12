from typing import Any, Dict

from PySide6.QtCore import Qt, Signal
from PySide6.QtGui import QIcon
from PySide6.QtWidgets import (
    QCheckBox,
    QDoubleSpinBox,
    QLabel,
    QLayout,
    QLineEdit,
    QPushButton,
    QSizePolicy,
    QWidget,
)


class CoreModule(QWidget):
    """Base class for all modules."""

    button_clicked = Signal()
    checkbox_toggle = Signal(bool)

    def __init__(self, module_data: Dict[str, Any], **kwargs) -> None:
        """
        Initialize the module.

        Args:
            module_data (dict): A dictionary containing properties for the module.
            **kwargs: Additional properties for the module.
        """
        super.__init__(**kwargs)

        for key, value in kwargs.items():
            setattr(self, key, value)

        self.setStyleSheet(module_data.get("stylesheet", ""))

        if isinstance(self, QDoubleSpinBox):
            self.setRange(
                module_data.get("min_value", 0), module_data.get("max_value", 100)
            )
            self.setValue(module_data.get("default_value", 0))
            self.setSingleStep(module_data.get("step", 1))
            self.setSuffix(module_data.get("suffix", ""))

        elif isinstance(self, (QCheckBox, QLabel)):
            self.setText(module_data.get("title", ""))

            if isinstance(self, QPushButton):
                self.clicked.connect(self.button_clicked)

                if module_data["icon_path"]:
                    icon = QIcon(module_data["icon_path"])
                    self.setIcon(icon)
                    self.setStyleSheet(module_data["stylesheet"])

                elif isinstance(
                    module_data["title"] and module_data["stylesheet"], tuple
                ):
                    layout = QLayout()
                    layout.setAlignment(Qt.AlignmentFlag.AlignCenter)
                    for title, stylesheet in zip(
                        module_data["title"], module_data["stylesheet"]
                    ):
                        label = QLabel(title)
                        label.setStyleSheet(stylesheet)
                        label.setAlignment(Qt.AlignmentFlag.AlignCenter)
                        layout.addWidget(label)
                    self.setLayout(layout)

                else:
                    self.setText(module_data["title"])
                    self.setStyleSheet(module_data["stylesheet"])

                if module_data["size"] is not None:
                    self.setFixedSize(*module_data["size"])

                else:
                    self.setSizePolicy(
                        QSizePolicy.Policy.Minimum, QSizePolicy.Policy.Minimum
                    )

            elif isinstance(self, QCheckBox):
                self.setChecked(module_data.get("checked", False))
                self.stateChanged.connect(self.checkbox_toggle)

        elif isinstance(self, QLineEdit):
            self.setPlaceholderText(module_data.get("placeholder", ""))
