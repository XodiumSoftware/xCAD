import sys

from PySide6.QtCore import QObject, Signal
from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class SignalsHandler(QObject):
    _signals = {}

    def __init__(self, value_types):
        super().__init__()

        for value_type in value_types:
            self._signals[value_type] = Signal(value_type)

    def __getitem__(self, value_type):
        return self._signals[value_type]


class MainUI(QMainWindow):
    UI_TITLE = "My Application"
    SUPPORTED_TYPES = [
        int,
        str,
        bool,
        float,
        list,
        tuple,
        dict,
        set,
        frozenset,
        bytes,
        bytearray,
        memoryview,
        type(None),
    ]

    def __init__(self):
        super().__init__()
        self._signals = SignalsHandler(self.SUPPORTED_TYPES)
        self.setup_main_ui()

    def setup_main_ui(self):
        self.setCentralWidget(QWidget())
        self.setWindowTitle(self.UI_TITLE)

        layout = self.create_layout()
        button = self.create_button()

        layout.addWidget(button)

    def create_layout(self):
        return QVBoxLayout(self.centralWidget())

    def create_button(self):
        button = QPushButton("Button")
        button.clicked.connect(self.emit_signals)
        return button

    def emit_signals(self):
        values = [
            1,
            "Hello",
            True,
            3.14,
            [1, 2, 3],
            (4, 5, 6),
            {"key": "value"},
            {1, 2, 3},
            frozenset({4, 5, 6}),
            b"data",
            bytearray(b"data"),
            memoryview(b"data"),
            None,
        ]
        for value in values:
            self.emit_signal(value)

    def emit_signal(self, value):
        self._signals[type(value)].emit(value)


def run():
    app = QApplication([])
    main_ui = MainUI()
    main_ui.show()

    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
