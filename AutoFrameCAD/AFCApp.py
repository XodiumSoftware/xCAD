import sys

from AFCUIModules import PrimaryUIModule as AFCPrimaryUIModule


def run() -> None:
    """Runs the application."""
    return AFCPrimaryUIModule().mainloop()


if __name__ == '__main__':
    sys.exit(run())
