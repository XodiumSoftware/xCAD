"""This module contains unit tests for the Forger class."""

import unittest
from pathlib import Path
from unittest.mock import MagicMock

from stenlib.forger import Forger


class TestForger(unittest.TestCase):
    """A class to test the Forger class."""

    def setUp(self: "TestForger") -> None:
        """Sets up the test."""
        self.path = MagicMock(spec=Path)

    def test_forge_dir(self: "TestForger") -> None:
        """Tests the dir method."""
        Forger.dir(self.path)

        self.path.mkdir.assert_called_once_with(
            mode=511,
            parents=True,
            exist_ok=True,
        )

    def test_forge_file(self: "TestForger") -> None:
        """Tests the file method."""
        Forger.file(self.path)

        self.path.touch.assert_called_once_with(mode=438, exist_ok=True)
