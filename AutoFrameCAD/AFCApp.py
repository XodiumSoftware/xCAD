import sys

from AFCDataclasses import MainUIDataclass
from AFCUIModules import MainUIModule


def run() -> None:
    """Runs the application."""
    app = MainUIModule(MainUIDataclass())
    return app.mainloop()


if __name__ == '__main__':
    sys.exit(run())
