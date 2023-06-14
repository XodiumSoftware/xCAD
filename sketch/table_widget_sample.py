from PySide6.QtWidgets import (
    QApplication,
    QGroupBox,
    QMainWindow,
    QTableWidget,
    QTableWidgetItem,
    QVBoxLayout,
    QWidget,
)

TABLES = [
    {
        "index": 0,
        "column_headers": ["Parameters", "Values"],
        "column_headers_stylesheet": "QHeaderView::section { font-size: 12px; }",
        "containers": [
            {
                "container_title": "General",
                "container_title_stylesheet": "QGroupBox::title { font-size: 12px; }",
                "container_data": [
                    ["Name", "John Doe"],
                    ["Age", "30"],
                    ["Country", "USA"],
                ],
                "container_data_stylesheet": "QTableWidget { font-size: 12px; }",
            },
            {
                "container_title": "Dimensions",
                "container_title_stylesheet": "QGroupBox::title { font-size: 12px; }",
                "container_data": [
                    ["Length", "6000"],
                    ["Height", "3000"],
                    ["Thickness", "170"],
                ],
                "container_data_stylesheet": "QTableWidget { font-size: 12px; }",
            },
        ],
    },
]

app = QApplication([])
window = QMainWindow()

# Create a central widget for the main window
central_widget = QWidget()
window.setCentralWidget(central_widget)

# Create a vertical layout for the central widget
layout = QVBoxLayout(central_widget)

# Iterate over the tables
for table in TABLES:
    # Create a group box for each table
    group_box = QGroupBox()
    group_box.setTitle(table["column_headers"][0])

    # Apply the stylesheet for the group box title
    group_box.setStyleSheet(table["container_title_stylesheet"])

    # Create a table widget for each container
    table_widget = QTableWidget(
        len(table["containers"][0]["container_data"]), len(table["column_headers"])
    )
    table_widget.setHorizontalHeaderLabels(table["column_headers"])
    table_widget.horizontalHeader().setStyleSheet(table["column_headers_stylesheet"])

    # Apply the stylesheet for the table widget
    table_widget.setStyleSheet(table["container_data_stylesheet"])

    # Iterate over the container data and populate the table widget
    for row, data in enumerate(table["containers"][0]["container_data"]):
        for column, item in enumerate(data):
            table_widget.setItem(row, column, QTableWidgetItem(item))

    # Add the table widget to the group box
    group_box_layout = QVBoxLayout()
    group_box_layout.addWidget(table_widget)
    group_box.setLayout(group_box_layout)

    # Add the group box to the main layout
    layout.addWidget(group_box)

window.show()
app.exec()
