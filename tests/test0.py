import sys
import weakref
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

    def add_ui(self, ui):
        if isinstance(ui, QMainWindow):
            self._uis.append(weakref.ref(ui))

    def handle_close_event(self, handler):
        """
        Handle close event of all UIs
        """
        self._uis = [ui for ui in self._uis if ui() is not None]
        for ui in self._uis:
            ui_instance = ui()
            if ui_instance is not None:
                ui_instance.closeEvent = partial(handler, ui_instance)

        all_visible = all(ui().isVisible() for ui in self._uis if ui() is not None)
        self.visibilityChanged.emit(all_visible)

    def toggle_visibility(self, current_ui, target_ui_type):
        for ui_ref in self._uis:
            ui_instance = ui_ref()
            if ui_instance is not None:
                if isinstance(ui_instance, target_ui_type):
                    ui_instance.setVisible(True)
                elif ui_instance == current_ui:
                    ui_instance.setVisible(False)


class MainUI(QMainWindow):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.setWindowTitle("MainUI")
        self.handler = VisibilityHandler(self)
        self.viewerUI = ViewerUI(self.handler)
        self.configUI = ConfigUI(self.handler)

        self.handler.handle_close_event(super().closeEvent)

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


def run():
    app = QApplication([])
    main_ui = MainUI()
    main_ui.show()

    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
