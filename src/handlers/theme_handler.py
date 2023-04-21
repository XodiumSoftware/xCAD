import winreg

from constants import DARK_THEME_DIR_PATH


class ThemeHandler:
    def __init__(self):
        super().__init__()
        self.current_theme = None
        self.detect_theme_in_microsoft_handler()

    @staticmethod
    def set_application_theme_handler(app, button):
        """
        Sets the application style by reading the style file and
        setting it as the style sheet of the given QApplication object.
        """
        with open(DARK_THEME_DIR_PATH, "r") as f:
            style = f.read()
            app.setStyleSheet(style)
        button.update()
        app.activeWindow().update()

    def toggle_theme_handler(self, app, button):
        """
        Toggles the application theme between light and dark.
        """
        if self.current_theme is None:
            self.current_theme = DARK_THEME_DIR_PATH
        elif self.current_theme is DARK_THEME_DIR_PATH:
            self.current_theme = None
        self.set_application_theme_handler(app, self.current_theme)
        button.update()

    def detect_theme_in_microsoft_handler(self):
        """
        This function detects if the Windows color mode is set to dark or light.
        :return: a boolean value indicating whether the color mode in Windows is set to dark mode or not. It
        returns True if the color mode is set to dark mode, and False otherwise.
        """
        registry = winreg.ConnectRegistry(None, winreg.HKEY_CURRENT_USER)
        reg_keypath = (
            r"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize"
        )
        try:
            reg_key = winreg.OpenKey(registry, reg_keypath)
        except FileNotFoundError:
            return False
        for i in range(1024):
            try:
                value_name, value, _ = winreg.EnumValue(reg_key, i)
                if value_name == "AppsUseLightTheme":
                    return value == 0
            except OSError:
                break
        return False
