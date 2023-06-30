from PySide6.QtCore import QSize, Qt, Signal
from PySide6.QtGui import QIcon, QPainter
from PySide6.QtWidgets import QPushButton


class ButtonDelegate(QPushButton):
    clickedCustom = Signal()

    def __init__(self, module_data, parent=None):
        super().__init__(parent)
        self.button_data = module_data
        self.setStyleSheet(self.generateStylesheet())

    def paintEvent(self, event):
        painter = QPainter(self)
        if painter.isActive():
            painter.setRenderHints(
                QPainter.RenderHint.Antialiasing | QPainter.RenderHint.TextAntialiasing
            )

            icon_path = self.button_data.get("icon_path")
            if icon_path is not None:
                icon = QIcon(icon_path)
                icon_size = self.sizeHint().height()

                rect = self.rect()
                rect.setHeight(icon_size)
                icon.paint(painter, rect, Qt.AlignmentFlag.AlignCenter)

            for i, title in enumerate(self.button_data.get("button_titles", [])):
                painter.drawText(self.rect(), Qt.AlignmentFlag.AlignCenter, title)

    def sizeHint(self):
        content_width = 0
        content_height = 0

        icon_path = self.button_data.get("icon_path")
        if icon_path is not None:
            icon_size = self.height()
            content_width = max(content_width, icon_size)
            content_height += icon_size

        font_metrics = self.fontMetrics()
        for title in self.button_data.get("button_titles", []):
            text_width = font_metrics.horizontalAdvance(title)
            content_width = max(content_width, text_width)

        if self.button_data.get("button_size") == [None, None]:
            size_hint = super().sizeHint()
            size_hint.setWidth(content_width)
            size_hint.setHeight(content_height)
            return size_hint
        else:
            return QSize(*self.button_data.get("button_size"))

    def generateStylesheet(self):
        stylesheet = ""

        # Button size
        button_size = self.button_data.get("button_size", [None, None])
        if button_size[0] is not None:
            stylesheet += f"width: {button_size[0]}px;"
        if button_size[1] is not None:
            stylesheet += f"height: {button_size[1]}px;"

        # Button titles
        button_titles = self.button_data.get("button_titles", [])
        if button_titles:
            stylesheet += "QAbstractButton {"

            # Font properties
            stylesheets = self.button_data.get("stylesheets")
            if stylesheets is not None:
                for key, value in stylesheets.items():
                    stylesheet += f"{key}: {value};"

            stylesheet += "}"

        return stylesheet

    def mousePressEvent(self, event):
        super().mousePressEvent(event)
        self.clickedCustom.emit()


# Example usage
module_data = [
    {
        "index": 0,
        "icon_path": None,
        "button_size": [None, None],
        "button_titles": ["AutoFrameCAD", "Click me!"],
        "stylesheets": {
            "line1": "font-size: 20px; font-weight: bold; color: #000000;",
            "line2": "font-size: 15px; font-weight: normal; color: #000000;",
        },
    },
]
