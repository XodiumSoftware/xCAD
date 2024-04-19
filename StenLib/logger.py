import logging


class Logger:
    """A class that contains logger functions."""

    @staticmethod
    def _logger(
        name: str,
        level: int = logging.INFO,
        format: str = "%(asctime)s - %(name)s - %(levelname)s - %(message)s",
        dateformat: str = "%Y-%m-%d %H:%M:%S",
    ) -> logging.Logger:
        """Set up a logger.

        Args:
            name (str): The name of the logger.
            level (int): The logging level.
            format (str): The format of the log message.
            dateformat (str): The format of the date.

        Returns:
            logging.Logger: The logger.
        """
        logger = logging.getLogger(name=name)
        logger.setLevel(level=level)
        handler = logging.StreamHandler()
        handler.setFormatter(logging.Formatter(fmt=format, datefmt=dateformat))
        logger.addHandler(hdlr=handler)
        return logger

    logger = _logger
