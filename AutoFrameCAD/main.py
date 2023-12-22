import sys

from interfaces.configs.ui_configs import UIConfig

from AutoFrameCAD.interfaces.modules.ui_modules import MainUIModule


def run() -> None:
    """Runs the application."""
    app = MainUIModule(UIConfig())
    return app.mainloop()


if __name__ == '__main__':
    sys.exit(run())
