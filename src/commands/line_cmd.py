from pyautocad import *

acad = Autocad()
print(acad.doc.Name)

p1 = APoint(100.0, 100.0)
cir1 = acad.model.AddCircle(p1, 100)

cir1.Color = 10  # = red in HEX
