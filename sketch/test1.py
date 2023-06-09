import sqlite3
import sys

from PySide6.QtWidgets import (
    QApplication,
    QLabel,
    QPushButton,
    QStackedWidget,
    QVBoxLayout,
    QWidget,
)


class SettingsManager:
    def __init__(self, db_file):
        self.db_file = db_file
        self.create_database()
        self.set_default_settings()

    def create_database(self):
        conn = sqlite3.connect(self.db_file)
        c = conn.cursor()
        c.execute(
            """
            CREATE TABLE IF NOT EXISTS settings (
                key TEXT PRIMARY KEY,
                value TEXT
            )
            """
        )
        conn.commit()
        conn.close()

    def set_default_settings(self):
        settings = [
            ("layout_visibility", "0"),
        ]
        conn = sqlite3.connect(self.db_file)
        c = conn.cursor()
        c.executemany(
            "INSERT OR IGNORE INTO settings (key, value) VALUES (?, ?)", settings
        )
        conn.commit()
        conn.close()

    def get_setting(self, key):
        conn = sqlite3.connect(self.db_file)
        c = conn.cursor()
        c.execute("SELECT value FROM settings WHERE key=?", (key,))
        result = c.fetchone()
        conn.close()
        if result is not None:
            return result[0]
        return None

    def set_setting(self, key, value):
        conn = sqlite3.connect(self.db_file)
        c = conn.cursor()
        c.execute(
            "INSERT OR REPLACE INTO settings (key, value) VALUES (?, ?)", (key, value)
        )
        conn.commit()
        conn.close()


class MyWidget(QWidget):
    def __init__(self):
        super().__init__()

        self.resize(600, 400)

        db_file = "settings.db"
        self.settings_manager = SettingsManager(db_file)
        layout_visible = self.settings_manager.get_setting("layout_visibility")
        print(layout_visible)

        self.stacked_widget = QStackedWidget()

        self.containers = [
            ("Container 0", QPushButton("Toggle Page")),
            ("Container 1", QPushButton("Toggle Page")),
            ("Container 2", QPushButton("Toggle Page")),
        ]

        self.container_buttons = {}
        for container_title, container_button in self.containers:
            container_widget = QWidget()
            container_layout = QVBoxLayout(container_widget)
            container_label = QLabel(container_title)
            container_button.clicked.connect(
                lambda checked, button=container_button: self.toggleContainerVisibility(
                    button
                )
            )
            container_layout.addWidget(container_label)
            container_layout.addWidget(container_button)
            self.stacked_widget.addWidget(container_widget)

            self.container_buttons[container_button] = len(self.container_buttons)

        self.stacked_widget.setCurrentIndex(int(layout_visible))

        main_layout = QVBoxLayout(self)
        main_layout.addWidget(self.stacked_widget)

    def toggleContainerVisibility(self, button):
        container_index = self.container_buttons[button]
        self.stacked_widget.setCurrentIndex(container_index)
        print(container_index)
        self.settings_manager.set_setting("layout_visibility", str(container_index))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    widget = MyWidget()
    widget.show()
    sys.exit(app.exec())
