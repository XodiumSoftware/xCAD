from PySide6.QtCharts import QChart, QChartView, QLineSeries, QValueAxis
from PySide6.QtCore import Qt
from PySide6.QtGui import QFont, QPainter, QPen
from PySide6.QtWidgets import QApplication, QMainWindow


class LineChartApp(QApplication):
    def __init__(self):
        super().__init__([])
        self.initUI()

    def initUI(self) -> None:
        series = self.createSeries()
        chart = self.createChart(series)
        axisX, axisY = self.createAxes()
        self.configureChart(chart, series, axisX, axisY)
        chartView = QChartView(chart)
        self.showChartView(chartView)

    def createSeries(self) -> QLineSeries:
        series = QLineSeries()
        series.append(0, 6)
        series.append(2, 4)
        series.append(3, 8)
        series.append(7, 4)
        series.append(10, 5)
        return series

    def createChart(self, series: QLineSeries) -> QChart:
        chart = QChart()
        chart.addSeries(series)
        chart.setTitleFont(QFont("Arial", 18, QFont.Weight.Bold))
        chart.setTitle("Timber Frame Wall")
        chart.setAnimationOptions(QChart.AnimationOption.SeriesAnimations)
        chart.legend().setVisible(False)
        return chart

    def createAxes(self) -> tuple[QValueAxis, QValueAxis]:
        axisX = QValueAxis()
        axisX.setRange(0, 10)
        axisX.setLabelFormat("%d")
        axisX.setTitleFont(QFont("Arial", 12, QFont.Weight.Bold))
        axisX.setTitleText("Length (mm)")

        axisY = QValueAxis()
        axisY.setRange(0, 10)
        axisY.setLabelFormat("%d")
        axisY.setTitleFont(QFont("Arial", 12, QFont.Weight.Bold))
        axisY.setTitleText("Height (mm)")

        axes_color = "#000000"
        axisX.setLinePen(QPen(axes_color))
        axisY.setLinePen(QPen(axes_color))

        return axisX, axisY

    def configureChart(
        self, chart: QChart, series: QLineSeries, axisX: QValueAxis, axisY: QValueAxis
    ) -> None:
        chart.addAxis(axisX, Qt.AlignmentFlag.AlignBottom)
        chart.addAxis(axisY, Qt.AlignmentFlag.AlignLeft)
        series.attachAxis(axisX)
        series.attachAxis(axisY)

    def showChartView(self, chartView: QChartView) -> None:
        chartView.setRenderHint(QPainter.RenderHint.Antialiasing)
        window = QMainWindow()
        window.setCentralWidget(chartView)
        window.setFixedSize(800, 400)
        window.show()
        self.exec()


if __name__ == "__main__":
    app = LineChartApp()
