from interfaces.configs.label_configs import CopyrightLabelConfig
from interfaces.modules.label_module import LabelModule


class MainUIMatrixConfig:
    """A class used to represent the main UI matrix config"""

    Matrix = (
        [
            [
                [
                    LabelModule(CopyrightLabelConfig()),
                ],
            ],
        ],
    )
