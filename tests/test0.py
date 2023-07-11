import sys
from functools import partial

from PySide6.QtCore import QObject, Signal
from PySide6.QtWidgets import (
    QApplication,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
    QWidget,
)


class VisibilityHandler(QObject):
    visibilityChanged = Signal(bool)

    def __init__(self, parent=None):
        super().__init__(parent)
        self._uis = []
        self.add_ui(parent)

    def add_ui(self, ui):
        if isinstance(ui, QMainWindow):
            self._uis.append(ui)
            for attr_value in vars(ui).items():
                self.add_ui(attr_value)

    def handle_close_event(self):
        all_visible = all(ui.isVisible() for ui in self._uis)
        self.visibilityChanged.emit(all_visible)

    def toggle_visibility(self, current_ui, target_ui_type):
        for ui in self._uis:
            if isinstance(ui, target_ui_type):
                ui.setVisible(True)
            elif ui == current_ui:
                ui.setVisible(False)


class MainUI(QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("MainUI")
        self.handler = VisibilityHandler(self)
        self.viewerUI = ViewerUI(self.handler)
        self.configUI = ConfigUI(self.handler)

        self.handler.add_ui(self.viewerUI)
        self.handler.add_ui(self.configUI)

        central_widget = QWidget()
        layout = QVBoxLayout()

        toggle_button_0 = QPushButton("Show ViewerUI")
        toggle_button_0.clicked.connect(
            partial(self.handler.toggle_visibility, self, ViewerUI)
        )

        toggle_button_1 = QPushButton("Show ConfigUI")
        toggle_button_1.clicked.connect(
            partial(self.handler.toggle_visibility, self, ConfigUI)
        )

        layout.addWidget(toggle_button_0)
        layout.addWidget(toggle_button_1)

        central_widget.setLayout(layout)
        self.setCentralWidget(central_widget)

    def closeEvent(self, event):
        super().closeEvent(event)
        if self.handler:
            self.handler.handle_close_event()


class ViewerUI(QMainWindow):
    def __init__(self, handler: VisibilityHandler, parent=None):
        super().__init__(parent)
        self.setWindowTitle("ViewerUI")
        self.handler = handler

        central_widget = QWidget()
        layout = QVBoxLayout()

        toggle_button = QPushButton("Show MainUI")
        toggle_button.clicked.connect(
            partial(self.handler.toggle_visibility, self, MainUI)
        )
        layout.addWidget(toggle_button)

        central_widget.setLayout(layout)
        self.setCentralWidget(central_widget)

    def closeEvent(self, event):
        super().closeEvent(event)
        if self.handler:
            self.handler.handle_close_event()


class ConfigUI(QMainWindow):
    def __init__(self, handler: VisibilityHandler, parent=None):
        super().__init__(parent)
        self.setWindowTitle("ConfigUI")
        self.handler = handler

        central_widget = QWidget()
        layout = QVBoxLayout()

        toggle_button = QPushButton("Show MainUI")
        toggle_button.clicked.connect(
            partial(self.handler.toggle_visibility, self, MainUI)
        )
        layout.addWidget(toggle_button)

        central_widget.setLayout(layout)
        self.setCentralWidget(central_widget)

    def closeEvent(self, event):
        super().closeEvent(event)
        if self.handler:
            self.handler.handle_close_event()


def run():
    app = QApplication([])
    main_ui = MainUI()
    main_ui.show()

    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
