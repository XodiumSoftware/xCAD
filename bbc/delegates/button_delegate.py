from PySide6.QtCore import QSize, Qt, Signal
from PySide6.QtGui import QColor, QFont, QFontMetrics, QIcon, QPainter, QPen
from PySide6.QtWidgets import QPushButton


class ButtonDelegate(QPushButton):
    clickedCustom = Signal()

    def __init__(self, button_data, parent=None):
        super().__init__(parent)
        self.button_data = button_data
        self.fonts = []
        self.colors = []

    def paintEvent(self, event):
        painter = QPainter(self)
        painter.setRenderHints(
            QPainter.RenderHint.Antialiasing | QPainter.RenderHint.TextAntialiasing
        )

        metrics = QFontMetrics(self.font())

        total_height = 0
        line_spacing = self.calculateLineSpacing(metrics)

        icon_path = self.button_data["icon_path"]
        if icon_path is not None:
            icon = QIcon(icon_path)
            icon_size = self.sizeHint().height() - line_spacing

            rect = self.rect()
            rect.setHeight(icon_size)
            rect.moveTop(total_height)
            icon.paint(painter, rect, Qt.AlignmentFlag.AlignCenter)

            total_height += icon_size + line_spacing

        for i, title in enumerate(self.button_data["titles"]):
            font = self.getFont(i)
            color = self.getColor(i)

            painter.setFont(font)
            painter.setPen(QPen(QColor(*color)))

            line_height = metrics.height()
            total_height += line_height + line_spacing

            rect = self.rect()
            rect.setTop(total_height - line_height)
            painter.drawText(rect, Qt.AlignmentFlag.AlignCenter, title)

        return event

    def getFont(self, index):
        if len(self.fonts) > index:
            return self.fonts[index]

        font = self.font()
        font = QFont(
            font.family(),
            self.button_data["font_size"][index],
        )
        font.setBold(self.button_data["bold"][index])
        font.setItalic(self.button_data["italic"][index])
        font.setUnderline(self.button_data["underline"][index])
        font.setStrikeOut(self.button_data["strikeout"][index])

        self.fonts.append(font)
        return font

    def getColor(self, index):
        if len(self.colors) > index:
            return self.colors[index]

        color = self.button_data["font_color"][index]
        self.colors.append(color)
        return color

    def sizeHint(self):
        metrics = QFontMetrics(self.font())

        total_height = 0
        line_spacing = self.calculateLineSpacing(metrics)

        for text in self.button_data["titles"]:
            line_height = metrics.height()
            total_height += line_height + line_spacing

        width = (
            self.fontMetrics()
            .boundingRect("\n".join(self.button_data["titles"]))
            .width()
            + 10
        )
        height = (
            total_height + (line_spacing * (len(self.button_data["titles"]) - 1)) + 10
        )

        return QSize(width, height)

    def calculateLineSpacing(self, metrics):
        line_spacing = 6
        if self.button_data["titles"]:
            max_font_height = max(self.button_data["font_size"])
            line_spacing = max(6, max_font_height)
        return line_spacing

    def mousePressEvent(self, event):
        super().mousePressEvent(event)
        self.clickedCustom.emit()
