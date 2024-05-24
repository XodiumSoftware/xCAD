using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

// Alias
using _AcAp = Bricscad.ApplicationServices;
using _AcBim = Bricscad.Bim;
using _AcDb = Teigha.DatabaseServices;
using _AcEd = Bricscad.EditorInput;
using _AcGe = Teigha.Geometry;

namespace CsBrxMgd
{
    public class BimSample
    {
        public static void GetSetBIMProperties()
        {
            _AcDb.ObjectId id;
            using (_AcDb.Database db = _AcDb.HostApplicationServices.WorkingDatabase)
            using (_AcDb.Transaction tr = db.TransactionManager.StartTransaction())
            {
                _AcDb.Solid3d solid = new _AcDb.Solid3d();
                solid.CreateBox(50, 40, 30);

                _AcDb.BlockTableRecord space = tr.GetObject(db.CurrentSpaceId, _AcDb.OpenMode.ForWrite) as _AcDb.BlockTableRecord; 
                if (space == null)
                    throw new System.NullReferenceException("space == null");

                id = space.AppendEntity(solid);
                tr.AddNewlyCreatedDBObject(solid, true);
                tr.Commit();
            }

            _AcBim.BimResStatus res = _AcBim.BIMClassification.ClassifyAs(id, _AcBim.BimTypeElement.BimWall);
            _AcBim.BIMClassification.SetName(id, "Outer Wall");
            _AcBim.BIMClassification.SetDescription(id, "South-East facing external wall");

            string bimName = _AcBim.BIMClassification.GetName(id);
            string bimDesc = _AcBim.BIMClassification.GetDescription(id);
            _AcBim.BimTypeElement bimType = _AcBim.BIMClassification.GetClassification(id);

            _AcAp.Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage($"\nName: {bimName}, Description: {bimDesc}, Type: {bimType} ");
        }

        public static void CreateBimColumn()
        {
            using (_AcDb.Database db = _AcDb.HostApplicationServices.WorkingDatabase)
            {
                // Create a cylinder to represent our Bim Column
                _AcDb.ObjectId id;
                using (_AcDb.Transaction tr = db.TransactionManager.StartTransaction())
                {
                    _AcDb.Solid3d cylinder = new _AcDb.Solid3d();
                    cylinder.CreateFrustum(100.0, 10.0, 10.0, 10.0);
                    cylinder.TransformBy(_AcGe.Matrix3d.Displacement(new _AcGe.Vector3d(0.0, 0.0, 50.0)));

                    _AcDb.BlockTableRecord space = tr.GetObject(db.CurrentSpaceId, _AcDb.OpenMode.ForWrite) as _AcDb.BlockTableRecord;
                    if (space == null)
                        throw new System.NullReferenceException("space == null");

                    id = space.AppendEntity(cylinder);
                    tr.AddNewlyCreatedDBObject(cylinder, true);
                    tr.Commit();
                }

                // Classify column as a Bim Column
                _AcBim.BimResStatus res = _AcBim.BIMClassification.ClassifyAs(id, _AcBim.BimTypeElement.BimColumn);

                // Name it & describe it
                _AcBim.BIMClassification.SetName(id, "Column 1");
                _AcBim.BIMClassification.SetDescription(id, "Supporting column number 1.");

                // Create a visible per-instance Property Set in the User Namespace
                res = _AcBim.BIMPropertySet.CreatePropertySet("ColumnPropSet", "My Column Properties", null, true, true, db);

                // Add two visible properties to the Property Set
                res = _AcBim.BIMPropertySet.CreateProperty("ColumnPropSet", "CapitalType", "Column Capital Type", "The type of capital used by the column", true, db);
                res = _AcBim.BIMPropertySet.CreateProperty("ColumnPropSet", "LoadBearing", "Load Bearing", "Is the column load bearing?", true, db);

                // Add the BimDbColumn Bim type to the Property Set
                res = _AcBim.BIMPropertySet.AddBimType("ColumnPropSet", "BimDbColumn");

                // Set the Property values for our column
                res = _AcBim.BIMPropertySet.SetProperty(id, "ColumnPropSet", "CapitalType", "Corinthian", false);
                res = _AcBim.BIMPropertySet.SetProperty(id, "ColumnPropSet", "LoadBearing", "<bool::true>", false);
            }
        }

        public static void GetBIMProfileProperties()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            try
            {
                _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select a BIM profile");
                peo.SetRejectMessage("\nThe selected object is not a BIM profile.");
                peo.AddAllowedClass(typeof(_AcDb.Solid3d), true);
                peo.AddAllowedClass(typeof(_AcDb.BlockReference), true);
                _AcEd.PromptEntityResult per = ed.GetEntity(peo);
                if (per.Status == _AcEd.PromptStatus.OK)
                {
                    using (_AcDb.Database db = _AcDb.HostApplicationServices.WorkingDatabase)
                    using (_AcDb.Transaction tr = db.TransactionManager.StartTransaction())
                    {
                        _AcDb.ObjectId id = per.ObjectId;
                        _AcDb.Entity ent = tr.GetObject(id, _AcDb.OpenMode.ForWrite) as _AcDb.Entity;
                        if (ent == null)
                            throw new System.NullReferenceException("_AcDb.Entity is null");

                        _AcBim.BimTypeElement bimType = _AcBim.BIMClassification.GetClassification(id);
                        ed.WriteMessage($"\n\nThe selected BIM Profile is classified as {bimType}");

                        _AcBim.BIMLibraryInfo bimInfo = _AcBim.BimUtilityFunctions.GetLibraryInfo(db, true);
                        ed.WriteMessage("\nWith units: " + (bimInfo.m_Unit == _AcBim.LibraryUnit.UnitInch ? "Inches" : "Millimeters"));

                        _AcBim.BIMLinearGeometry bimLinearGeo = new _AcBim.BIMLinearGeometry(id);
                        if (bimLinearGeo == null)
                            throw new System.NullReferenceException("_AcBim.BIMLinearGeometry is null");

                        _AcBim.BIMProfile profile = bimLinearGeo.Profile;
                        if (profile == null)
                            ed.WriteMessage("\n_AcBim.BIMProfile is null.");
                        else
                            ed.WriteMessage("\nAnd the following properties: " +
                                "\n  Standard = {0}" + 
                                "\n  Name = {1}" +
                                "\n  Shape = {2}" +
                                "\n  Description = {3}",
                                string.IsNullOrEmpty(profile.Standard) ? "(None)" : profile.Standard,
                                string.IsNullOrEmpty(profile.Name) ? "(None)" : profile.Name,
                                string.IsNullOrEmpty(profile.Shape) ? "(None)" : profile.Shape,
                                string.IsNullOrEmpty(profile.Description) ? "(None)" : profile.Description);

                        tr.Commit();
                        _AcAp.Application.DisplayTextScreen = true;
                    }
                }
            }
            catch (System.Exception ex)
            {
                _AcAp.Application.ShowAlertDialog(string.Format("\nError: {0}\nStackTrace: {1}", ex.Message, ex.StackTrace));
            }
        }
    }
}
