from pyautocad import Autocad


def draw_pline():
    """
    Draws a polyline by user-specified inputs
    """
    acad = Autocad()

    # prompt user for points using list comprehension
    points = [
        (float(x), float(y))
        for x, y in (
            input("Enter a point as x,y (leave blank when done): ").split(",")
            for _ in range(100)
        )
        if x and y
    ]

    # add polyline to AutoCAD drawing
    acad.model.AddPolyline(points)
