import random
import string


class Helper:
    """Helper class for common functions"""

    @staticmethod
    def generate_complex_id(char_len=6) -> str:
        """Generate a complex ID."""
        chars = string.ascii_letters + string.digits
        return "".join(random.choice(chars) for _ in range(char_len))

    @staticmethod
    def get_data_from_app(app, key) -> str:
        """Get data from the application."""
        return app.data[key]
