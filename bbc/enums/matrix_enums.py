from enum import Enum

from enums.module_enums import GraphicsViews, Labels, PushButtons
from enums.q_enums import AlignmentType, LayoutType, SizePolicyType


# ModuleHandler:
# ====================================================================================================
# Define the matrix data with support for nested containers
# NOTE: Nested containers are not supported yet.
# Each element in module_matrix_pos can contain either a list of widgets
# or another set of "module_args" representing a nested container.
# For nested containers, specify the nested layout as a string.
# ====================================================================================================
class Matrices(Enum):
    """A class to store the matrices."""

    MainMatrix0 = [
        [
            [
                LayoutType.VBox,
                PushButtons.AutoFrameCAD,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Expanding, SizePolicyType.Expanding),
            ],
        ],
        [
            [
                LayoutType.VBox,
                Labels.Copyright,
                (0, 0, 0, 0),
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
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Expanding, SizePolicyType.Expanding),
            ],
        ],
        [
            [
                LayoutType.VBox,
                PushButtons.Save,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                LayoutType.VBox,
                PushButtons.Discard,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                LayoutType.VBox,
                PushButtons.Reset,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
        [
            [
                LayoutType.VBox,
                PushButtons.StartupPage,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
        [
            [
                LayoutType.VBox,
                Labels.Copyright,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
    ]
