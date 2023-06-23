import win32com.client
from PySide6.QtCore import Slot
from PySide6.QtWidgets import QApplication, QMainWindow, QPushButton


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        button = QPushButton("Execute LISP Routine", self)
        button.clicked.connect(self.execute_lisp_routine)

    @Slot()
    def execute_lisp_routine(self):
        try:
            bricscad = win32com.client.Dispatch("BricscadApp.AcadApplication")
            doc = bricscad.ActiveDocument
            model_space = doc.ModelSpace
            model_space.InsertBlock((0, 0), "YourBlockName", 1, 1, 1, 0)
        except Exception as e:
            print("Error executing LISP routine:", str(e))


if __name__ == "__main__":
    app = QApplication([])
    window = MainWindow()
    window.show()
    app.exec()
