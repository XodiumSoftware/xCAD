import os

from constants import DATA_DIR_FILE, DATA_DIR_FOLDER

# FIXME: circular import
from ui.tfcc_ui import TFCCUI


class inputHandler:
    def save_inputs(self):
        """
        This function saves input values from input widgets to a text file.
        """
        input_values = {}
        for i, input_widget in enumerate(TFCCUI.create_input_fields.inputs):
            input_text = input_widget.text()
            input_values[i] = input_text

        data_dir = DATA_DIR_FOLDER

        if not os.path.exists(data_dir):
            os.makedirs(data_dir)

        file_path = os.path.join(data_dir, DATA_DIR_FILE)

        with open(file_path, "w") as f:
            for key, value in input_values.items():
                f.write(f"{key}: {value}\n")

        from handlers.press_handler import saveButtonHandler

        save_button_handler_instance = saveButtonHandler()
        save_button_handler_instance.save_button_handler()
