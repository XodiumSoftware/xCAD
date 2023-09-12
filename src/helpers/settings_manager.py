import os
from contextlib import contextmanager
from typing import Iterator

from PySide6.QtCore import QSettings

from constants import DATABASE_PATH


class SettingsManager(QSettings):
    """A class to manage settings in a class variable"""

    @property
    def data_path(self) -> str:
        """The path to the settings file"""
        return os.path.abspath((DATABASE_PATH))

    def __init__(self) -> None:
        super().__init__()
        os.makedirs(os.path.dirname(self.data_path), exist_ok=True)
        self.setPath(
            QSettings.Format.IniFormat,
            QSettings.Scope.UserScope,
            self.data_path,
        )

    @contextmanager
    def group(self, name: str) -> Iterator[str]:
        """A context manager to create a group"""
        self.beginGroup(name)
        try:
            yield name
        finally:
            self.endGroup()

    def load(self, obj: type) -> None:
        """Load the settings from the object"""
        if not isinstance(obj, type):
            raise ValueError("obj must be a class")
        with self.group(obj.__name__) as group:
            for key in (k for k in dir(obj) if not k.startswith("_")):
                if self.contains(key):
                    value = self.value(key)
                    print(f"Loading from group {group}.{key} = {value}")
                    setattr(obj, key, value)

    def save(self, obj: type) -> None:
        """Save the settings to the object"""
        if not isinstance(obj, type):
            raise ValueError("obj must be a class")
        with self.group(obj.__name__) as group:
            for key in (k for k in dir(obj) if not k.startswith("_")):
                new_value = getattr(obj, key)
                old_value = self.value(key) if self.contains(key) else None
                if new_value != old_value:
                    print(f"Saving to group {group}.{key} = {new_value}")
                    self.setValue(key, new_value)
