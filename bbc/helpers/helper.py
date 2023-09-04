import random
import string
from typing import Optional

from PySide6.QtCore import QSettings


class Helper:
    """Helper class for common functions"""

    @staticmethod
    def generate_complex_id(char_len: int = 6) -> str:
        """Generate a complex ID."""
        chars = string.ascii_letters + string.digits
        return "".join(random.choice(chars) for _ in range(char_len))

    @staticmethod
    def settings_manager(
        key: str, value: str, group: Optional[str] = None
    ) -> Optional[str]:
        """Manage the settings."""
        settings = QSettings()
        if group:
            settings.beginGroup(group)

        settings.setValue(key, value)
        settings.sync()

        if group:
            settings.endGroup()

        return str(settings.value(key))
