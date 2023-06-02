import sys

from PySide6.QtCore import QObject, Signal
from PySide6.QtWidgets import QApplication, QMainWindow, QPushButton


class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Signal-Slot Example")

        self.button = MyButton()
        self.setCentralWidget(self.button)


class MyButton(QPushButton):
    def __init__(self):
        super().__init__("Click me")
        self.clicked.connect(self.button_clicked)

    def button_clicked(self):
        signal = MySignal()
        signal.emit_signal()
        print("Button clicked")


class MySignal(QObject):
    my_signal = Signal()

    def emit_signal(self):
        self.my_signal.emit()
        print("Signal emitted")


if __name__ == "__main__":
    app = QApplication(sys.argv)

    window = MyWindow()
    window.show()

    sys.exit(app.exec())
