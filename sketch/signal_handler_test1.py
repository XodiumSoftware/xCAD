import sys
from collections import defaultdict
from functools import partial

from PySide6.QtCore import Signal, Slot
from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)

UI_TITLE = "My Application"


class MainUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.init_signals()
        self.init_values()
        self.setup_main_ui()
        self.setup_signals()

    def init_signals(self):
        def create_signal():
            return Signal(object)

        self._signals = defaultdict(
            create_signal,
            {
                int: Signal(int),
                str: Signal(str),
                bool: Signal(bool),
                float: Signal(float),
                list: Signal(list),
                tuple: Signal(tuple),
                dict: Signal(dict),
                set: Signal(set),
                frozenset: Signal(frozenset),
                bytes: Signal(bytes),
                bytearray: Signal(bytearray),
                type(None): Signal(type(None)),
            },
        )

    def init_values(self):
        self._values = [
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
            None,
        ]

    def setup_main_ui(self):
        self.setCentralWidget(QWidget())
        self.setWindowTitle(UI_TITLE)

        layout = QVBoxLayout(self.centralWidget())
        emitButton = QPushButton("Emit Signals")
        emitButton.clicked.connect(self.emit_signals)

        layout.addWidget(emitButton)

    def setup_signals(self):
        for value_type, signal in self._signals.items():
            signal.connect(partial(self.print_received_signal, value_type))

    def emit_signals(self):
        for value in self._values:
            self.emit_signal(value)

    @Slot(type)
    def print_received_signal(self, value_type):
        print(f"Received signal for type: {value_type}")

    def emit_signal(self, value):
        signal = self._signals[type(value)]
        signal.emit(value)


def run():
    app = QApplication([])
    main_ui = MainUI()
    main_ui.show()

    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
