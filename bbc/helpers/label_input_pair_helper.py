from constants import INPUT_BAR_WIDTH
from PySide6.QtWidgets import QGridLayout, QLabel, QWidget


def label_input_pair_helper(
    self,
    label_text: str,
    input_object: QWidget,
    row: int,
    layout: QGridLayout,
    suffix_text: str = "",
):
    """
    Helper function to create a label-input field pair and add it to a given grid layout.
    """
    prefix_label = QLabel(label_text)
    input_object.setFixedWidth(INPUT_BAR_WIDTH)

    if suffix_text:
        suffix_label = QLabel(suffix_text)
        layout.addWidget(suffix_label, row, 2)

    layout.addWidget(prefix_label, row, 0)
    layout.addWidget(input_object, row, 1)
