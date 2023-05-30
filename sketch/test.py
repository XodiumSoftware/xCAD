import sys

from PySide6.QtWidgets import QApplication, QMainWindow, QPushButton


class MyWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Signal-Slot Example")

        self.button = QPushButton("Click me", self)
        self.button.clicked.connect(self.button_clicked)

    def button_clicked(self):
        print("Button clicked!")


if __name__ == "__main__":
    app = QApplication(sys.argv)

    window = MyWindow()
    window.show()

    sys.exit(app.exec())
