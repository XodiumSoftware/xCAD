# importing pyautocad
import pyautocad

# creating AutoCAD instance
acad = pyautocad.Autocad()

# print name of document currently recognized as being active in AutoCAD
print(acad.doc.Name)
