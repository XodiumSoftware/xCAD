import os

from constants import DATA_DIR


def save_input_values(self):
    """
    This function saves input values from input widgets to a text file.
    """
    input_values = {}
    for i, input_widget in enumerate(self.inputs):
        input_text = input_widget.text()
        input_values[i] = input_text

    data_dir = DATA_DIR
    if not os.path.exists(data_dir):
        os.makedirs(data_dir)
    file_path = os.path.join(data_dir, "input_values.txt")

    with open(file_path, "w") as f:
        for key, value in input_values.items():
            f.write(f"{key}: {value}\n")
