from AFCDataclasses import MainUIDataclass as AFCMainUIDataclass
from sv_ttk import set_theme as sv_ttkSetTheme


class ThemeHandler:
    """A class used to represent a theme handler."""

    @staticmethod
    def set_theme(configs: AFCMainUIDataclass) -> None:
        """Set the theme.

        Args:
            theme (AFCMainUIDataclass): The theme to set.
        """
        sv_ttkSetTheme(configs.THEME)
