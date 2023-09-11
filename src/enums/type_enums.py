from enum import Enum


class LumberTypes(Enum):
    """A class to represent different types of lumber.

    This class defines two categories of lumber types: SLS (Scandinavian Lumber Standard)
    and CLS (Canadian Lumber Standard).

    Attributes:
        SLS (list): List of tuples representing dimensions of Scandinavian Lumber Standard.
        CLS (list): List of tuples representing dimensions of Canadian Lumber Standard.

    Methods:
        get_all_content():
            Returns a list of tuples containing formatted names and dimensions of all lumber types.

    Example:
        >>> lumber_list = LumberTypes.get_all_content()
        >>> print(lumber_list)
        [('SLS 38x89', (38, 89)), ('SLS 38x120', (38, 120)), ...]

    """

    SLS = [
        (38, 89),
        (38, 120),
        (38, 140),
        (38, 170),
        (38, 184),
        (38, 235),
        (38, 285),
    ]

    CLS = [
        (50, 75),
        (50, 100),
        (50, 125),
        (50, 150),
        (50, 175),
    ]

    @classmethod
    def get_all_content(cls):
        """Get all content from the lumber types.

        Returns:
            list: A list of tuples containing formatted names and dimensions of all lumber types.

        Example:
            >>> lumber_list = LumberTypes.get_all_content()
            >>> print(lumber_list)
            [('SLS 38x89', (38, 89)), ('SLS 38x120', (38, 120)), ...]

        """
        return [
            (f"{name} {x}x{y}", (x, y))
            for name, values in cls.__members__.items()
            for x, y in values.value
        ]
