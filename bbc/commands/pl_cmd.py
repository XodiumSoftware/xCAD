from functools import lru_cache

import comtypes.client
from pyautocad import APoint, Autocad


class AutoCAD:
    def __init__(self):
        self.acad = self.get_active_acad_app()
        self.autocad = Autocad(create_if_not_exists=True)
        self.doc = self.autocad.doc
        self.model_space = self.doc.ModelSpace
        self.handler = AutocadEventHandler(self.autocad, self.model_space)

    @staticmethod
    @lru_cache(maxsize=None)
    def get_active_acad_app():
        return comtypes.client.GetActiveObject("AutoCAD.Application")

    def run(self):
        self.doc.CommandEnded.add(self.handler.on_command_entered)
        self.doc.SendCommand("_pline2\n")


class AutocadEventHandler:
    def __init__(self, autocad, model_space):
        self.autocad = autocad
        self.model_space = model_space

    def create_polyline(self, start_point, end_point):
        return self.model_space.AddLine(start_point, end_point)

    def on_command_entered(self, sender, args):
        if args.commandName.lower() == "pline2":
            start_point, end_point = APoint(self.autocad.GetPoint()), APoint(
                self.autocad.GetPoint()
            )
            self.create_polyline(start_point, end_point)


if __name__ == "__main__":
    autocad = AutoCAD()
    autocad.run()
