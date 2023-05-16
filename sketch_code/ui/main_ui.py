# from constants import *
# from handlers.theme_handler import ThemeHandler
# from PySide6.QtWidgets import QLabel, QMainWindow, QPushButton, QVBoxLayout, QWidget


# class MainUI(QMainWindow):
#     def __init__(
#         self, theme=THEME_LIGHT, preferences_file=Path.cwd() / PREFERENCES_FILE
#     ):
#         super().__init__()

#         # Create an instance of the ThemeHandler class with the required constructor arguments.
#         self.theme_label = QLabel("Theme: ")
#         self.theme_handler = ThemeHandler(theme, preferences_file, self.theme_label)

#         self.init_ui(theme)

#     def init_ui(self, theme):
#         layout = QVBoxLayout()
#         central_widget = QWidget()  # Create a central widget to hold the layout
#         central_widget.setLayout(layout)
#         self.setCentralWidget(
#             central_widget
#         )  # Set the central widget for the QMainWindow

#         layout.addWidget(self.theme_label)

#         self.toggle_button = QPushButton(
#             "Toggle Theme"
#         )  # TODO: Replace text with icon.
#         self.toggle_button.clicked.connect(self.theme_handler.toggle_theme)
#         layout.addWidget(self.toggle_button)

#         self.theme_handler.load_theme_stylesheet(theme)
