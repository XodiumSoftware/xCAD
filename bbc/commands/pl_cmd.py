from functools import lru_cache

import comtypes.client
from pyautocad import APoint, Autocad


# Get the active AutoCAD application and document
@lru_cache(maxsize=None)
def get_autocad_app():
    return comtypes.client.GetActiveObject("AutoCAD.Application")


acad = get_autocad_app()
doc = acad.DocumentManager.MdiActiveDocument
model_space = doc.ModelSpace


class AutocadEventHandler:
    def __init__(self, acad):
        self.acad = acad

    # Define a function to create a polyline between two points
    @staticmethod
    def create_polyline(start_point, end_point):
        return model_space.AddLine(start_point, end_point)

    # Define a function to handle the command line input
    def on_command_entered(self, sender, args):
        # Check if the entered command is "pline2"
        if args.commandName.lower() == "pline2":
            # Prompt the user to enter the start and end points
            start_point, end_point = APoint(self.acad.GetPoint()), APoint(
                self.acad.GetPoint()
            )
            # Create the polyline between the two points
            self.create_polyline(start_point, end_point)


# Use the with_events decorator to register the command entered event handler
handler = AutocadEventHandler(acad)
acad = Autocad(create_if_not_exists=True)
acad.doc.CommandEnded.add(handler.on_command_entered)

# Run the AutoCAD event loop
acad.doc.SendCommand("_pline2\n")
