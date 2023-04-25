import os
from typing import *

from PySide6.QtWidgets import *

from constants import *


class DataHandler:
    def input_signal_handler(self):
        """
        Connects the `textChanged` and `valueChanged` signals of several input
        widgets to the `save_configurator_inputs` method of the current object.
        """
        inputs = [
            self.frame_material_input,
            self.frame_length_input,
            self.frame_height_input,
            self.profile_type_input,
            self.profile_length_input,
            self.profile_width_input,
            self.plate_material_input,
            self.plate_thickness_input,
        ]
        for input in inputs:
            input.textChanged.connect(self.save_configurator_inputs)
            input.valueChanged.connect(self.save_configurator_inputs)

    def configurator_data_handler(self):
        """
        Handles data for the configurator.
        """
        inputs = [
            ("Frame Material", self.frame_material_input.text()),
            ("Frame Length", self.frame_length_input.value()),
            ("Frame Height", self.frame_height_input.value()),
            ("Profile Type", self.profile_type_input.text()),
            ("Profile Length", self.profile_length_input.value()),
            ("Profile Width", self.profile_width_input.value()),
            ("Plate Material", self.plate_material_input.text()),
            ("Plate Thickness", self.plate_thickness_input.value()),
        ]
        with open(DATA_DIR_FOLDER + DATA_DIR_FILE, "w") as f:
            for name, value in inputs:
                f.write("{}: {}\n".format(name, value))

        print(DEBUG_SAVE_INPUT_PRINT)
        for name, value in inputs:
            print("{}: {}".format(name, value))

    def dir_and_file_handler(self) -> Dict[str, Union[str, bool]]:
        """
        Initializes a dictionary to hold data folder and file information.
        Creates data and theme directories and files if they don't exist.
        """
        # Initialize dictionary to hold data folder and file information
        data_info = {
            "data_dir": DATA_DIR_FOLDER,
            "theme_dir": THEME_DIR_FOLDER,
            "data_file": DATA_DIR_FILE,
            "theme_file": THEME_DIR_FILE,
            "data_dir_created": False,
            "theme_dir_created": False,
            "data_file_created": False,
            "theme_file_created": False,
        }

        # Create data directory and file if they don't exist
        os.makedirs(DATA_DIR_FOLDER, exist_ok=True)
        data_file_path = os.path.join(DATA_DIR_FOLDER, DATA_DIR_FILE)
        if not os.path.exists(data_file_path):
            open(data_file_path, "a").close()
            data_info["data_file_created"] = True
        data_info["data_dir_created"] = True

        # Create theme directory and file if they don't exist
        os.makedirs(THEME_DIR_FOLDER, exist_ok=True)
        theme_file_path = os.path.join(THEME_DIR_FOLDER, THEME_DIR_FILE)
        if not os.path.exists(theme_file_path):
            open(theme_file_path, "a").close()
            data_info["theme_file_created"] = True
        data_info["theme_dir_created"] = True

        # Print debug information
        if DEBUG_SAVE_INPUT_PRINT:
            print(
                f"Data directory: {data_info['data_dir']}, file: {data_info['data_file']}"
            )
            print(
                f"Theme directory: {data_info['theme_dir']}, file: {data_info['theme_file']}"
            )
            print(f"Data directory created: {data_info['data_dir_created']}")
            print(f"Theme directory created: {data_info['theme_dir_created']}")
            print(f"Data file created: {data_info['data_file_created']}")
            print(f"Theme file created: {data_info['theme_file_created']}")

        return data_info
