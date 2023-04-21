# type: ignore
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

    def data_folder_and_file_handler(self) -> Dict[str, Union[str, bool]]:
        """
        Initializes a dictionary to hold data folder and file information.
        Checks if data directory and file exist, and creates them if they don't.
        """
        # Initialize dictionary to hold data folder and file information
        data_info = {
            "data_dir": DATA_DIR_FOLDER,
            "data_file": DATA_DIR_FILE,
            "data_dir_created": False,
            "data_file_created": False,
        }

        # Check if data directory and file exist
        if not os.path.exists(DATA_DIR_FOLDER + "/" + DATA_DIR_FILE):
            # Create data directory and file if they don't exist
            os.makedirs(DATA_DIR_FOLDER, exist_ok=True)
            with open(DATA_DIR_FOLDER + "/" + DATA_DIR_FILE, "w") as f:
                pass
            data_info["data_dir_created"] = True
            data_info["data_file_created"] = True

        # Print debug information
        if DEBUG_SAVE_INPUT_PRINT:
            print(
                f"Data directory: {data_info['data_dir']}, file: {data_info['data_file']}"
            )
            print(f"Data directory created: {data_info['data_dir_created']}")
            print(f"Data file created: {data_info['data_file_created']}")

        return data_info
