from PySide6.QtWidgets import QApplication, QMainWindow, QPushButton


class Window(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Window 1")
        self.button = QPushButton("Open Window 2", self)
        self.button.clicked.connect(self.open_window2)

    def open_window2(self):
        self.window2 = Window2(self)
        self.window2.show()


class Window2(QMainWindow):
    def __init__(self, window1):
        super().__init__()
        self.setWindowTitle("Window 2")
        self.window1 = window1
        self.window1.resizeEvent = self.adjust_windows

    def adjust_windows(self, event):
        self.resize(event.size())
        self.window1.resize(event.size())


if __name__ == "__main__":
    app = QApplication()
    window = Window()
    window.show()
    app.exec()
