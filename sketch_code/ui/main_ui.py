from handlers.theme_handler import ThemeHandler
from PySide6.QtWidgets import QMainWindow, QPushButton, QVBoxLayout


class MainUI(QMainWindow, ThemeHandler):
    def __init__(self):
        super().__init__()
        self.init_ui()

    def init_ui(self):
        layout = QVBoxLayout()
        self.setLayout(layout)

        layout.addWidget(self.theme_label)

        self.toggle_button = QPushButton(
            "Toggle Theme"
        )  # TODO: Replace text with icon.
        self.toggle_button.clicked.connect(self.toggle_theme)
        layout.addWidget(self.toggle_button)

        self.load_theme_stylesheet()
