from BricscadApp import *
from Teigha.DatabaseServices import *
from Teigha.Geometry import *


@CommandMethod("MYCOMMAND")
def my_command():
    ed = Application.DocumentManager.MdiActiveDocument.Editor
    p1 = ed.GetPoint("Select the first point:")
    p2 = ed.GetPoint("Select the second point:", p1.Value)
    with HostApplicationServices.WorkingDatabase.TransactionManager.StartTransaction() as tr:
        line = Line(p1.Value, p2.Value)
        tr.AddNewlyCreatedDBObject(line, True)
        space = tr.GetObject(
            DocumentManager.MdiActiveDocument.Database.CurrentSpaceId, OpenMode.ForWrite
        )
        space.AppendEntity(line)
        tr.Commit()
