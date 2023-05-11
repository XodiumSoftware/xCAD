import os
from typing import *

from PySide6.QtWidgets import *

from constants import *

# FIXME: Configurator inputs not being saved.


class DataHandler:
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
            with open(theme_file_path, "w") as f:
                f.write("LIGHT")
            data_info["theme_file_created"] = True
        data_info["theme_dir_created"] = True

        # Print debug information
        if DEBUG_SAVE_INPUT_PRINT:
            print(
                f"[DEBUG] Data directory: {data_info['data_dir']}, file: {data_info['data_file']}"
            )
            print(
                f"[DEBUG] Theme directory: {data_info['theme_dir']}, file: {data_info['theme_file']}"
            )
            print(f"[DEBUG] Data directory created: {data_info['data_dir_created']}")
            print(f"[DEBUG] Theme directory created: {data_info['theme_dir_created']}")
            print(f"[DEBUG] Data file created: {data_info['data_file_created']}")
            print(f"[DEBUG] Theme file created: {data_info['theme_file_created']}")

        return data_info
