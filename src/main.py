import sys

import qdarktheme
from PySide6.QtWidgets import QApplication

from helpers.settings_manager import SettingsManager
from ui import UI


class MyClass:
    OPTION_1: int = 0
    OPTION_2: tuple = (2, 3, 4)
    OPTION_3: str = "Hello"
    OPTION_4: dict = {
        "key1": "value1",
        "key2": "value2",
    }
    OPTION_5: list = ["a", "b", "c"]
    OPTION_6: bool = True


def test():
    _settings_manager = SettingsManager()
    _settings_manager.load(MyClass)
    MyClass.OPTION_1 = 38
    _settings_manager.save(MyClass)


def run():
    """Run the application."""
    qdarktheme.enable_hi_dpi()
    app = QApplication([])
    test()
    _ = UI()

    return app.exec()


if __name__ == "__main__":
    sys.exit(run())
