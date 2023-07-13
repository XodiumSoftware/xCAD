from PySide6.QtWidgets import QApplication, QLabel

app = QApplication([])

text = "<font color='red'>This is line one</font><br><font color='blue'>This is line two</font>"
label = QLabel(text)
label.show()

app.exec_()
