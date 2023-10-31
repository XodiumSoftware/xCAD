from dataclasses import dataclass

from StenLib.StenUtils import Utils

from data.types_data import LumberTypes


@dataclass
class ObjInitData:
    """A class to represent different types of lumber."""

    Object_ID: str = Utils.alphanumeric_id_generator()
    Type: str = f"{LumberTypes.SLS} {LumberTypes.SLS[0][0]}x{LumberTypes.SLS[0][1]}"
    DrawOrder: int = 0

    PosX: int = 0
    PosY: int = 0
    DimX: int = LumberTypes.SLS[0][0]
    DimY: int = LumberTypes.SLS[0][1]
    Rad: int = 0

    PenStyle: str = "SolidLine"
    PenColor: str = "#ffffff"
    PenThickness: int = 2

    Fill: bool = True
    FillPattern: str = "SolidPattern"
    FillColor: str = "#ebd3b0"
    FillOpacity: int = 100

    # TODO: add this to StenLib. remove it everywhere else.
    @classmethod
    def get_all_content(cls) -> list[tuple[str, tuple[int, int]]]:
        """Get all content from the lumber types."""
        return [
            (f"{name} {x}x{y}", (x, y))
            for name, values in cls.__dict__.items()
            if isinstance(values, list)
            for x, y in values
        ]
