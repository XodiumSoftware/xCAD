from pyautocad import APoint, Autocad

acad = Autocad(create_if_not_exists=True)
acad.prompt("Hello, Autocad from Python\n")

print("Using file " + acad.doc.Name)

dim1 = acad.model.AddDimAligned(p1, p2, APoint(width / 2, -0.5))
