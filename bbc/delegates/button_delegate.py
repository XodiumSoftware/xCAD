from PySide6.QtCore import QSize, Qt, Signal
from PySide6.QtGui import QIcon, QPainter
from PySide6.QtWidgets import QPushButton


class ButtonDelegate(QPushButton):
    clickedCustom = Signal()

    def __init__(self, button_data, parent=None):
        """
        Initialize the ButtonDelegate.
        """
        super().__init__(parent)
        self.button_data = button_data
        self.setStyleSheet(self.generateStylesheet())

    def paintEvent(self, event):
        """
        Handle the paint event for the button.
        """
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

            font = self.font()
            font_metrics = self.fontMetrics()
            line_spacing = self.button_data.get("stylesheets", {}).get(
                "line-spacing", 0
            )

            for i, title in enumerate(self.button_data.get("title", [])):
                painter.setFont(font)
                painter.drawText(self.rect(), Qt.AlignmentFlag.AlignCenter, title)
                font.setPointSize(font.pointSize() + line_spacing)

    def sizeHint(self):
        """
        Return the recommended size for the button.
        """
        content_width = 0
        content_height = 0

        icon_path = self.button_data.get("icon_path")
        if icon_path is not None:
            icon_size = self.height()
            content_width = max(content_width, icon_size)
            content_height += icon_size

        font_metrics = self.fontMetrics()
        for title in self.button_data.get("title", []):
            text_width = font_metrics.horizontalAdvance(title)
            content_width = max(content_width, text_width)

        if self.button_data.get("size") == [None, None]:
            size_hint = super().sizeHint()
            size_hint.setWidth(content_width)
            size_hint.setHeight(content_height)
            return size_hint
        else:
            return QSize(*self.button_data.get("size"))

    def generateStylesheet(self):
        """
        Generate the stylesheet for the button.
        """
        stylesheet = ""

        size = self.button_data.get("size", [None, None])
        if size[0] is not None:
            stylesheet += f"width: {size[0]}px;"
        if size[1] is not None:
            stylesheet += f"height: {size[1]}px;"

        title = self.button_data.get("title", [])
        if title:
            stylesheet += "QAbstractButton {"

            stylesheets = self.button_data.get("stylesheets", [])
            if stylesheets:
                for style in stylesheets:
                    for key, value in style.items():
                        if key != "line-spacing":
                            stylesheet += f"{key}: {value};"

            stylesheet += "}"

        return stylesheet

    def mousePressEvent(self, event):
        """
        Handle the mouse press event for the button.
        """
        super().mousePressEvent(event)
        self.clickedCustom.emit()
