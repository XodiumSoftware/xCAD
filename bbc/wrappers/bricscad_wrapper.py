import ctypes
import os

# FIXME: bricscadapi = wrong lib?
bricscadapi_path = os.path.join(
    "bbc", "libs", "BRXSDK_Bcad_V23_2_03", "lib64", "brx23.lib"
)
bricscadapi = ctypes.cdll.LoadLibrary(bricscadapi_path)

# Line argument types are (x1, y1, x2, y2) aka point1 and point2.
bricscadapi.Line.argtypes = [
    ctypes.c_double,
    ctypes.c_double,
    ctypes.c_double,
    ctypes.c_double,
]


def add_line(start_point, end_point):
    """
    Create a new line entity
    """
    bricscadapi.Line(start_point[0], start_point[1], end_point[0], end_point[1])


def redraw():
    """
    Refresh the display
    """
    bricscadapi.redraw()
