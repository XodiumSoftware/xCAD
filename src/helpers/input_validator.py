from PySide6.QtGui import QValidator


def input_validator(self, input_text, pos):
    """
    This function validates user input by checking if it is empty or a non-negative integer, and
    returns a state indicating whether the input is acceptable, invalid, or intermediate.

    :param input_text: The text input that needs to be validated
    :param pos: pos refers to the position of the cursor in the input field. It is used in the
    function to return the updated position of the cursor after validating the input
    :return: A tuple containing the validation state (either Intermediate, Acceptable, or Invalid),
    the input text, and the position of the cursor.
    """
    if input_text.isEmpty():
        return (QValidator.State.Intermediate, input_text, pos)
    elif self.inputs.index(self.sender()) in [0, 1, 3, 4, 6]:
        if input_text.isdigit() and int(input_text) >= 0:
            return (QValidator.State.Acceptable, input_text, pos)
        else:
            return (QValidator.State.Invalid, input_text, pos)
    else:
        return (QValidator.State.Acceptable, input_text, pos)
