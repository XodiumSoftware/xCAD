from pyautocad import APoint, Autocad


def draw_polyline():
    acad = Autocad()
    points = []
    for i in range(2):
        point = acad.GetPoint(prompt=f"Select point {i+1}: ")
        if point is None:  # User pressed ESC
            return
        points.append(APoint(point))
    acad.model.AddPolyline(points)


# Register the function as a command in AutoCAD
acad = Autocad()
acad.RegisterApplication("MyApp", "MyCommand", "MyCommand", 1)
acad.AddCommand("MyApp", "MyCommand", "MyCommand", "N", draw_polyline)
