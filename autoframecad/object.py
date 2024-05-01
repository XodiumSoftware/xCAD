"""This module contains the object functionality."""


class BIMObject:
    """A class that contains object functions."""

    def __init__(
        self: "BIMObject",
        name: str,
        material: str,
        dimensions: tuple[float, float, float],
    ) -> None:
        """Initialize the object.

        Args:
            name: The name of the object.
            material: The material of the object.
            dimensions: The dimensions of the object in (x, y, z).
        """
        self.name = name
        self.material = material
        self.dimensions = dimensions

    def __str__(self: "BIMObject") -> str:
        """Return the object as a string.

        Returns:
            The object as a string.
        """
        formatted_dimensions = ", ".join(
            f"{axis}: {value}"
            for axis, value in zip(
                ["x", "y", "z"],
                self.dimensions,
                strict=False,
            )
        )
        return (
            f"BIM Object: {self.name}\n"
            f"Material: {self.material}\n"
            f"Dimensions: ({formatted_dimensions})\n"
        )
