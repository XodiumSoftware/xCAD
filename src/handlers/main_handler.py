# type: ignore
import os
from typing import *

from PySide6.QtWidgets import *

from constants import *


class MainHandler(QWidget):
    def __init__(self):
        super().__init__()
        self.data_folder_and_file_handler()

    def data_folder_and_file_handler(self) -> Dict[str, Union[str, bool]]:
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
