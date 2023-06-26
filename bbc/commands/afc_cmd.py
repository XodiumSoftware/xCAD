import argparse
import sys

import pyautocad

# TODO: move the constants to constants.py
LAYER_PROPERTIES = {
    "KBG_SLS": {
        "Color": 1,
        "Linetype": "Continuous",
        "LinetypeScale": 1,
        "Lineweight": -1,
    }
}

OBJECT_PROPERTIES = {
    "rectangle": {
        "TrueColor": None,
        "Layer": "KBG_SLS",
        "Linetype": "ByLayer",
        "LinetypeScale": 1,
        "Lineweight": -1,
        "Transparency": -1,
        "Hyperlinks": None,
        "RecordGraphicsModified": True,
        "Thickness": 0,
        "Material": "ByLayer",
    },
}


class AFCCMD:
    def __init__(self):
        """
        Initialize the AutoCAD application and open the drawing.
        """
        super().__init__()
        self.setup_afc_cmd()

    def setup_afc_cmd(self):
        """
        Setup the AFC command.
        """
        self.cad = pyautocad.Acad()
        self.doc = self.cad.doc
        self.setup_layers()

    def setup_layers(self):
        """
        Setup the layers in the drawing.
        """
        for layer_name, layer_properties in LAYER_PROPERTIES.items():
            if not self.doc.Layers.Exists(layer_name):
                layer = self.doc.Layers.Add(layer_name)
                for prop, value in layer_properties.items():
                    setattr(layer, prop, value)

    def draw_rectangle(self, corner1, corner2, output_path):
        """
        Draw a rectangle in an AutoCAD drawing.
        """
        # Get the model space object
        model_space = self.doc.ModelSpace

        # Add the rectangle entity to the model space
        rectangle = model_space.AddRectangle(corner1, corner2)

        # Set the properties of the rectangle
        for prop, value in OBJECT_PROPERTIES["rectangle"].items():
            if prop == "Hyperlinks" and value is None:
                rectangle.Hyperlinks.DeleteAll()
            elif prop == "RecordGraphicsModified":
                rectangle.RecordGraphicsModified(value)
            else:
                setattr(rectangle, prop, value)

        # Save and display the drawing
        self.doc.SaveAs(output_path)
        self.cad.app.WindowState = self.cad.constants.acWindowStateMax


# TODO: merge this with main.py
def run():
    """
    Run the AFC command.
    """
    afc_cmd = AFCCMD()
    afc_cmd.draw_rectangle((0, 0), (10, 10), "C:\\Users\\User\\Desktop\\test.dwg")
    afc_cmd.quit()

    parser = argparse.ArgumentParser(
        description="Draw a rectangle in an AutoCAD drawing."
    )
    parser.add_argument("x1", type=float, help="X coordinate of the first corner point")
    parser.add_argument("y1", type=float, help="Y coordinate of the first corner point")
    parser.add_argument(
        "x2", type=float, help="X coordinate of the second corner point"
    )
    parser.add_argument


if __name__ == "__main__":
    sys.exit(run())
