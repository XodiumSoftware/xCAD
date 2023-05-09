import sys

from ezdxf import *

try:
    # get the filepath of the existing DXF document from the command line argument
    filepath = sys.argv[1]

    # open the existing DXF document
    doc = readfile(filepath)
    msp = doc.modelspace()  # get the modelspace

    # prompt the user to enter two points
    p1 = tuple(map(float, input("Enter the first point (x, y): ").split()))
    p2 = tuple(map(float, input("Enter the second point (x, y): ").split()))

    # add a line to the modelspace using the selected points
    line = msp.add_line(p1, p2)

    # save the DXF document
    doc.save()

except Exception as e:
    print("An error occurred:", e)
