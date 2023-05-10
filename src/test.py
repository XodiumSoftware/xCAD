import ast
import os
import sys

import libs.bricscad
import matplotlib.pyplot as plt
import pandas as pd
from libs.bricscad import current_model as bim_model

plt.close("all")

# FIXME: bricscad lib import


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
    This function gets executed when the user types "my_command".
    It then makes the user select two points which after the selection adds a line in between the points to the modelspace.
    """
    # prompt the user to enter two points
    p1 = get_valid_input("Enter the first point (x, y): ")
    p2 = get_valid_input("Enter the second point (x, y): ")

    # add a line to the modelspace using the selected points
    doc = bricscad.doc
    msp = doc.modelspace()  # get the modelspace
    msp.add_line(p1, p2)


bricscad.defun("MYCOMMAND", my_command)
