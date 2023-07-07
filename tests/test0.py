from PySide6.QtWidgets import QApplication, QHBoxLayout, QPushButton, QWidget

app = QApplication()

window = QWidget()
layout = QHBoxLayout(window)

button1 = QPushButton("Button 1")
layout.addWidget(button1)

layout.addStretch()

button2 = QPushButton("Button 2")
layout.addWidget(button2)

window.show()

app.exec()
