import pyautocad
from constants import LAYER_PROPERTIES, OBJECT_PROPERTIES


class AFCCMD:
    def __init__(self):
        """Initialize the AutoCAD application and open the drawing."""
        super().__init__()
        self.setup_afc_cmd()

    def setup_afc_cmd(self):
        """Setup the AFC command."""
        # FIXME: "Acad" is not a known member of module "pyautocad"
        self.cad = pyautocad.Acad()  # type: ignore
        self.doc = self.cad.doc
        self.setup_layers()

    def setup_layers(self):
        """Setup the layers in the drawing."""
        for layer_name, layer_properties in LAYER_PROPERTIES.items():
            if not self.doc.Layers.Exists(layer_name):
                layer = self.doc.Layers.Add(layer_name)
                for prop, value in layer_properties.items():
                    setattr(layer, prop, value)

    def draw_rectangle(self, corner1, corner2, output_path):
        """Draw a rectangle in an AutoCAD drawing."""
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
