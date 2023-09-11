from contextlib import contextmanager
from typing import Any, Optional

from PySide6.QtCore import QSettings


class SettingsManager(QSettings):
    """A class to manage settings in a class variable"""

    @contextmanager
    def group(self, group: Optional[str] = None) -> Any:
        """Context manager for a settings group"""
        if group:
            self.beginGroup(group)
        try:
            yield
        finally:
            if group:
                self.endGroup()

    def value(
        self, key: str, value: Optional[Any] = None, group: Optional[str] = None
    ) -> Any:
        """Get or set a setting in the class variable"""
        with self.group(group):
            if value is None:
                return str(super().value(key))
            else:
                super().setValue(key, value)

    def remove(self, key: str, group: Optional[str] = None) -> None:
        """Remove a setting from the class variable"""
        with self.group(group):
            super().remove(key)
