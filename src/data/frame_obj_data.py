from dataclasses import dataclass


@dataclass
class FrameObjInitData:
    """A class to represent frame settings."""

    FrameX: int = 4000
    FrameY: int = 2500

    StudSpacingX: int = 600
    StudSpacingY: int = 2400
