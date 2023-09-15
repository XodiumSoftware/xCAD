from enum import Enum

from enums.module_enums import GraphicsViews, Labels, PushButtons
from enums.q_enums import AlignmentType, LayoutType, SizePolicyType


class Matrices(Enum):
    """A class to store the matrices."""

    StartupPageMatrix = [
        [
            [
                PushButtons.AutoFrameCAD,
                LayoutType.VBox,
                None,
                AlignmentType.AlignCenter,
                (SizePolicyType.Expanding, SizePolicyType.Expanding),
            ],
        ],
        [
            [
                Labels.Copyright,
                LayoutType.VBox,
                None,
                AlignmentType.AlignBottom,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
    ]
    FooterMatrix = [
        [
            [
                PushButtons.StartupPage,
                LayoutType.VBox,
                None,
                AlignmentType.AlignLeft,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                Labels.Copyright,
                LayoutType.VBox,
                None,
                AlignmentType.AlignLeft,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
    ]
    StructureViewMatrix = [
        [
            [
                GraphicsViews.StructureView,
                LayoutType.VBox,
                None,
                AlignmentType.AlignCenter,
                (SizePolicyType.Expanding, SizePolicyType.Expanding),
            ],
        ],
    ]
    SaveDiscardMatrix = [
        [
            [
                PushButtons.Save,
                LayoutType.VBox,
                None,
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                PushButtons.Discard,
                LayoutType.VBox,
                None,
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
    ]
