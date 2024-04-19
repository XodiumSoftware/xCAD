import logging
import unittest
from unittest.mock import MagicMock, patch

from StenLib.logger import Logger


class TestLogger(unittest.TestCase):
    """A class to test the Logger class"""

    def setUp(self) -> None:
        """Sets up the test"""
        self.name = "test_logger"
        self.level = logging.INFO
        self.format = "%(asctime)s - %(name)s - %(levelname)s - %(message)s"
        self.dateformat = "%Y-%m-%d %H:%M:%S"

    @patch("logging.getLogger")
    @patch("logging.StreamHandler")
    @patch("logging.Formatter")
    def test_logger(
        self,
        formatter_mock: MagicMock,
        handler_mock: MagicMock,
        getLogger_mock: MagicMock,
    ) -> None:
        """Tests the _logger method

        Args:
            formatter_mock (MagicMock): A mock for the Formatter class.
            handler_mock (MagicMock): A mock for the StreamHandler class.
            getLogger_mock (MagicMock): A mock for the getLogger function.
        """
        logger_mock = getLogger_mock.return_value
        handler_instance_mock = handler_mock.return_value

        logger = Logger.logger(
            self.name, self.level, self.format, self.dateformat
        )

        getLogger_mock.assert_called_once_with(name=self.name)
        logger_mock.setLevel.assert_called_once_with(level=self.level)
        handler_mock.assert_called_once_with()
        formatter_mock.assert_called_once_with(
            fmt=self.format, datefmt=self.dateformat
        )
        handler_instance_mock.setFormatter.assert_called_once_with(
            formatter_mock.return_value
        )
        logger_mock.addHandler.assert_called_once_with(
            hdlr=handler_instance_mock
        )

        self.assertIs(logger, logger_mock)
