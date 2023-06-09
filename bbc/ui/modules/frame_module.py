from constants import FRAMES
from PySide6.QtWidgets import QFrame, QVBoxLayout, QWidget


class FrameModule(QWidget):
    def __init__(self, frame_index, parent=None):
        """
        Initialize the FrameModule.
        """
        super().__init__(parent)
        self.setup_frame_module(frame_index)

    def setup_frame_module(self, frame_index):
        """
        Setup the FrameModule.
        """
        layout = QVBoxLayout(self)

        frame_data = next(
            (frame for frame in FRAMES if frame["index"] == frame_index),
            None,
        )

        if frame_data:
            frame = self.create_frame_module(frame_data)
            layout.addWidget(frame)

        layout.setContentsMargins(0, 0, 0, 0)

        self.setLayout(layout)

    def create_frame_module(self, frame_data):
        """
        Create a frame module.
        """
        frame = QFrame()
        if frame_data["title"] is not None:
            frame.setWindowTitle(frame_data["title"])
        if frame_data["size"] is not None:
            frame.setFixedSize(*frame_data["size"])
        if frame_data["stylesheet"] is not None:
            frame.setStyleSheet(frame_data["stylesheet"])

        return frame
