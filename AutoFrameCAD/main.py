import sys

from AFCDataclasses import UIDataclass
from AFCUIModules import MainUIModule


def run() -> None:
    """Runs the application."""
    app = MainUIModule(UIDataclass())
    return app.mainloop()


if __name__ == '__main__':
    sys.exit(run())
