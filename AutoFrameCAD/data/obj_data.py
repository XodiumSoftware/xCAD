from dataclasses import dataclass

from data.types_data import LumberTypesData
from StenLib.StenUtils import Utils


@dataclass
class ObjInitData:
    """A class to represent different types of lumber."""

    Object_ID: str = Utils.alphanumeric_id_generator()
    Type: str = (
        f"{LumberTypesData.SLS} {LumberTypesData.SLS[0][0]}x{LumberTypesData.SLS[0][1]}"
    )
    DrawOrder: int = 0

    PosX: int = 0
    PosY: int = 0
    DimX: int = LumberTypesData.SLS[0][0]
    DimY: int = LumberTypesData.SLS[0][1]
    Rad: int = 0

    PenStyle: str = "SolidLine"
    PenColor: str = "#ffffff"
    PenThickness: int = 2

    Fill: bool = True
    FillPattern: str = "SolidPattern"
    FillColor: str = "#ebd3b0"
    FillOpacity: int = 100
