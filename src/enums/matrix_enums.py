from enum import Enum

from enums.module_enums import GraphicsViews, Labels, PushButtons
from enums.q_enums import AlignmentType, LayoutType, SizePolicyType


class Matrices(Enum):
    """A class to store the matrices."""

    MainMatrix0 = [
        [
            [
                LayoutType.VBox,
                PushButtons.AutoFrameCAD,
                None,
                AlignmentType.AlignCenter,
                (SizePolicyType.Expanding, SizePolicyType.Expanding),
            ],
        ],
        [
            [
                LayoutType.VBox,
                Labels.Copyright,
                None,
                AlignmentType.AlignBottom,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
    ]
    MainMatrix1 = [
        [
            [
                LayoutType.VBox,
                GraphicsViews.StructureView,
                None,
                AlignmentType.AlignCenter,
                (SizePolicyType.Expanding, SizePolicyType.Expanding),
            ],
        ],
        [
            [
                LayoutType.VBox,
                PushButtons.Save,
                None,
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                LayoutType.VBox,
                PushButtons.Discard,
                None,
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                LayoutType.VBox,
                PushButtons.Reset,
                None,
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
        [
            [
                LayoutType.VBox,
                PushButtons.StartupPage,
                None,
                AlignmentType.AlignLeft,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
        [
            [
                LayoutType.VBox,
                Labels.Copyright,
                None,
                AlignmentType.AlignLeft,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
    ]
