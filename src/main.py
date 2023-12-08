import sys
from interfaces.configs.ui_configs import MainUIConfig
from interfaces.modules.ui_module import MainUIModule


def run() -> None:
    """Runs the application."""
    app = MainUIModule(MainUIConfig())
    return app.mainloop()


if __name__ == "__main__":
    sys.exit(run())
