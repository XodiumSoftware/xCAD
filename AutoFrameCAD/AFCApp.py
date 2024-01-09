import sys

from AFCDataclasses import MainUIDataclass
from AFCUIModules import MainUIModule


def run() -> None:
    """Runs the application."""
    return MainUIModule(MainUIDataclass()).mainloop()


if __name__ == '__main__':
    sys.exit(run())
