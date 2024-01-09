import sys

from AFCDataclasses import EventsDataclass as AFCEventsDataclass
from AFCDataclasses import UIDataclass as AFCUIDataclass
from AFCUIModules import MainUIModule as AFCMainUIModule


def run() -> None:
    """Runs the application."""
    return AFCMainUIModule(
        AFCUIDataclass(),
        AFCEventsDataclass(),
    ).mainloop()


if __name__ == '__main__':
    sys.exit(run())
