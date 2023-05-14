import pythoncom
import win32com.client

acad = win32com.client.Dispatch("AutoCAD.Application")
doc = acad.ActiveDocument
acadModel = doc.ModelSpace


def APoint(x, y, z=0):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, (x, y, z))


def aDouble(xyz):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, (xyz))


def aVariant(vObject):
    return win32com.client.VARIANT(
        pythoncom.VT_ARRAY | pythoncom.VT_DISPATCH, (vObject)
    )
