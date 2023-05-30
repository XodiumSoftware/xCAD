from PySide6 import QtCore
import random

class Slots(QtCore.QObject):
    def __init__(self):
        super().__init__()

    @QtCore.Slot()
    def magic(self):
        self.text.setText(random.choice(self.hello)