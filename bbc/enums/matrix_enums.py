from enum import Enum

from enums.module_enums import Buttons, Labels
from enums.q_enums import AlignmentType, LayoutType, ModuleType, SizePolicyType


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

    Matrix0 = [
        [
            [
                LayoutType.VBox,
                ModuleType.PushButton,
                Buttons.AutoFrameCAD,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Expanding, SizePolicyType.Expanding),
            ],
        ],
        [
            [
                LayoutType.VBox,
                ModuleType.Label,
                Labels.Copyright,
                (0, 0, 0, 0),
                AlignmentType.AlignBottom,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
    ]
    Matrix1 = [
        [
            [
                LayoutType.VBox,
                ModuleType.PushButton,
                Buttons.Save,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                LayoutType.VBox,
                ModuleType.PushButton,
                Buttons.Discard,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                LayoutType.VBox,
                ModuleType.PushButton,
                Buttons.Reset,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
        [
            [
                LayoutType.VBox,
                ModuleType.PushButton,
                Buttons.StartupPage,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                LayoutType.VBox,
                ModuleType.PushButton,
                Buttons.ViewerButton,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
        [
            [
                LayoutType.VBox,
                ModuleType.Label,
                Labels.Copyright,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
    ]
    Matrix2 = [
        [
            [
                LayoutType.VBox,
                ModuleType.PushButton,
                Buttons.Save,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                LayoutType.VBox,
                ModuleType.PushButton,
                Buttons.Discard,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
            [
                LayoutType.VBox,
                ModuleType.PushButton,
                Buttons.Reset,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
        [
            [
                LayoutType.VBox,
                ModuleType.PushButton,
                Buttons.StartupPage,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
        [
            [
                LayoutType.VBox,
                ModuleType.Label,
                Labels.Copyright,
                (0, 0, 0, 0),
                AlignmentType.AlignCenter,
                (SizePolicyType.Minimum, SizePolicyType.Minimum),
            ],
        ],
    ]
