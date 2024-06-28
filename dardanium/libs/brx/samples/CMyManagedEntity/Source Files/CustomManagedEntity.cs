// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

//The entity represents a circle that is controlled by 3 points

// system 
using System;

#if _BCAD
// ODA
using Teigha.Runtime;
using Teigha.DatabaseServices;
using Teigha.Geometry;


// Bricsys
using Bricscad.ApplicationServices;
using Bricscad.EditorInput;

// alias
using AcRx = Teigha.Runtime;
using AcAp = Bricscad.ApplicationServices;
using AcDb = Teigha.DatabaseServices;
using AcGe = Teigha.Geometry;
using AcEd = Bricscad.EditorInput;

#else
using Autodesk.AutoCAD.Runtime;
using Autodesk.AutoCAD.DatabaseServices;
using Autodesk.AutoCAD.Geometry;
using Autodesk.AutoCAD.ApplicationServices;
using Autodesk.AutoCAD.EditorInput;

// alias
using AcRx = Autodesk.AutoCAD.Runtime;
using AcAp = Autodesk.AutoCAD.ApplicationServices;
using AcDb = Autodesk.AutoCAD.DatabaseServices;
using AcGe = Autodesk.AutoCAD.Geometry;
using AcEd = Autodesk.AutoCAD.EditorInput;
#endif


namespace Test
{
    public class Commands
    {
        static ObjectId mgdCustEntId = ObjectId.Null;

        [CommandMethod("CustMgdEnt")]
        static public void CustMgdEnt()
        {
            double r = 1.0;
            Document doc = AcAp.Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;

            PromptPointOptions pointOptions = new PromptPointOptions("Insertion point:");
            pointOptions.AllowNone = false;
            pointOptions.AllowArbitraryInput = false;
            PromptPointResult pointResult = ed.GetPoint(pointOptions);
            Point3d pointResultVal = pointResult.Value;
            Point3d pnt1 = new Point3d(pointResultVal.X - r, pointResultVal.Y, pointResultVal.Z);
            Point3d pnt2 = new Point3d(pointResultVal.X, pointResultVal.Y + r, pointResultVal.Z);
            Point3d pnt3 = new Point3d(pointResultVal.X + r, pointResultVal.Y, pointResultVal.Z);

            using (Transaction Tx = db.TransactionManager.StartTransaction())
            {
                using (CustomManagedEntity.CMyManagedEntity mgdCustEnt = new CustomManagedEntity.CMyManagedEntity())
                {
                    mgdCustEnt.Point1 = pnt1;
                    mgdCustEnt.Point2 = pnt2;
                    mgdCustEnt.Point3 = pnt3;

                    ObjectId ModelSpaceId = SymbolUtilityServices.GetBlockModelSpaceId(db);
                    mgdCustEnt.SetDatabaseDefaults(db);
                    BlockTableRecord btr = Tx.GetObject(ModelSpaceId, OpenMode.ForWrite) as BlockTableRecord;
                    mgdCustEntId = btr.AppendEntity(mgdCustEnt);

                    Tx.AddNewlyCreatedDBObject(mgdCustEnt, true);
                }
                Tx.Commit();
            }
        }

        [CommandMethod("CustMgdEntDerived")]
        static public void CustMgdEntDerived()
        {
            double r = 1.0;
            Document doc = AcAp.Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;

            PromptPointOptions pointOptions = new PromptPointOptions("Insertion point:");
            pointOptions.AllowNone = false;
            pointOptions.AllowArbitraryInput = false;
            PromptPointResult pointResult = ed.GetPoint(pointOptions);
            Point3d pointResultVal = pointResult.Value;
            Point3d pnt1 = new Point3d(pointResultVal.X - r, pointResultVal.Y, pointResultVal.Z);
            Point3d pnt2 = new Point3d(pointResultVal.X, pointResultVal.Y + r, pointResultVal.Z);
            Point3d pnt3 = new Point3d(pointResultVal.X + r, pointResultVal.Y, pointResultVal.Z);

            using (Transaction Tx = db.TransactionManager.StartTransaction())
            {
                using (CustomManagedEntity.CMyManagedEntityDerived mgdCustEnt =
                    new CustomManagedEntity.CMyManagedEntityDerived())
                {
                    mgdCustEnt.Point1 = pnt1;
                    mgdCustEnt.Point2 = pnt2;
                    mgdCustEnt.Point3 = pnt3;

                    ObjectId ModelSpaceId = SymbolUtilityServices.GetBlockModelSpaceId(db);
                    mgdCustEnt.SetDatabaseDefaults(db);
                    BlockTableRecord btr = Tx.GetObject(ModelSpaceId, OpenMode.ForWrite) as BlockTableRecord;
                    mgdCustEntId = btr.AppendEntity(mgdCustEnt);

                    Tx.AddNewlyCreatedDBObject(mgdCustEnt, true);
                }
                Tx.Commit();
            }
        }

        [CommandMethod("GetCustomEnt")]
        static public void GetCustomEnt()
        {
            Document doc = AcAp.Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;
            PromptEntityResult pointResult = ed.GetEntity("Select CMyManagedEntity");
            using (Transaction Tx = db.TransactionManager.StartTransaction())
            {
                CustomManagedEntity.CMyManagedEntity mgdCustEnt =
                    Tx.GetObject(pointResult.ObjectId, OpenMode.ForWrite) as CustomManagedEntity.CMyManagedEntity;

                if (mgdCustEnt != null)
                {
                    ed.WriteMessage("\n{0}", mgdCustEnt.GetRXClass().DxfName);
                }
                else
                {
                    ed.WriteMessage("\n{0}", "CMyManagedEntity or CMyManagedEntityDerived not found");
                }
                Tx.Commit();
            }
        }
    }
}
