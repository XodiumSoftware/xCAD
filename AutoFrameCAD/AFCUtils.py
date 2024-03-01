import re


class Utils:
    """A class that contains utility functions."""

    @staticmethod
    def sanitize_str(value: str) -> str:
        """Sanitizes a string.

        Args:
            value (str): The string to be sanitized.
        """
        return (re.sub(r'\W+', '_', value)).lower()
