import ast

import bricscad
import comtypes.client

# connect to BricsCAD
bricscad = comtypes.client.GetActiveObject("BricscadApp.AcadApplication")


def get_valid_input(prompt):
    """
    Get a valid input from the user.
    """
    while True:
        try:
            value = ast.literal_eval(input(prompt))
            if not isinstance(value, tuple) or len(value) != 2:
                raise ValueError
            return value
        except ValueError:
            print("Invalid input. Please enter two points in the form (x, y).")


def my_command():
    """
    ***
    """
    # prompt the user to enter two points
    p1 = get_valid_input("Enter the first point (x, y): ")
    p2 = get_valid_input("Enter the second point (x, y): ")

    # add a line to the modelspace using the selected points
    doc = bricscad.doc
    msp = doc.modelspace()  # get the modelspace
    msp.add_line(p1, p2)


bricscad.defun("MYCOMMAND", my_command)
