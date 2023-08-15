import sys
from typing import Optional

from PySide6.QtCore import Qt
from PySide6.QtWidgets import (
    QApplication,
    QFrame,
    QLabel,
    QMainWindow,
    QPushButton,
    QVBoxLayout,
)


class FrameDelegate(QFrame):
    """A class that creates a frame with a title and a content widget that can be folded and unfolded."""

    def __init__(
        self, title: str, content_widget: QFrame, parent: Optional[QFrame] = None
    ):
        """Initialize the frame with a title and a content widget."""
        super().__init__(parent)

        self.setFrameStyle(QFrame.Shape.Panel | QFrame.Shadow.Raised)

        self.frame_layout = QVBoxLayout()
        self.setLayout(self.frame_layout)

        self.title_button = QPushButton(title)
        self.title_button.setCheckable(True)
        self.title_button.clicked.connect(self.toggle_content)
        self.frame_layout.addWidget(
            self.title_button, alignment=Qt.AlignmentFlag.AlignLeft
        )

        self.content_widget = content_widget
        self.content_widget.hide()
        self.frame_layout.addWidget(self.content_widget)

    def toggle_content(self):
        """Show or hide the content widget."""
        self.content_widget.setVisible(self.title_button.isChecked())


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.setWindowTitle("Foldable Example")

        main_widget = FrameDelegate("Foldable Section", QLabel("Content goes here"))
        self.setCentralWidget(main_widget)


def main():
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec())


if __name__ == "__main__":
    main()
