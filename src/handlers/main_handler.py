import os
from typing import Dict, Union

from PySide6.QtWidgets import QGridLayout, QLineEdit, QWidget

from constants import DATA_DIR_FILE, DATA_DIR_FOLDER, DEBUG_SAVE_INPUT_PRINT


class MainHandler(QWidget):
    def __init__(self):
        super().__init__()
        self.labels = []
        self.inputs = []
        self.input_fields_layout = QGridLayout()
        self.line_validator = QLineEdit()

        self.data_dir_folder = DATA_DIR_FOLDER
        self.data_dir_file = DATA_DIR_FILE

        self.file_path = os.path.join(self.data_dir_folder, self.data_dir_file)

    # def input_signal(self):
    #     """Connect a slot to input textChanged signal."""
    #     for input_widget in self.inputs:
    #         input_widget.textChanged.connect(self.write_inputs_to_file)

    def write_inputs_to_file(self, inputs: Dict[str, Union[str, float]]):
        """
        Write the inputs to a file at a given path. If the file already exists,
        overwrite it; otherwise, create a new file.
        """
        if not os.path.exists(self.data_dir_folder):
            os.makedirs(self.data_dir_folder)

        inputs_filepath = os.path.join(self.data_dir_folder, self.data_dir_file)

        with open(inputs_filepath, "w") as f:
            input_str = "\n".join([f"{key}: {value}" for key, value in inputs.items()])
            f.write(input_str + "\n")

        print(DEBUG_SAVE_INPUT_PRINT, inputs)
