// system 
using System;
using System.Text;
using System.Diagnostics;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.IO;


// ODA
using Teigha.Runtime;
using Teigha.DatabaseServices;
using Teigha.Geometry;

// Bricsys
using Bricscad.ApplicationServices;
using Bricscad.Runtime;
using Bricscad.EditorInput;
using Bricscad.Civil;

// alias
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;

namespace CsBrxMgdCivil
{
    class Utils
    {
        //helper Function to add items to ModelSpace;
        public static ObjectIdCollection AddToModelSpace(params _AcDb.Entity[] list)
        {
            ObjectIdCollection ids = new ObjectIdCollection();
            Database database = HostApplicationServices.WorkingDatabase;
            _AcDb.TransactionManager manager = database.TransactionManager;
            using (Transaction action = manager.StartTransaction())
            {
                BlockTable blockTable =
                    action.GetObject(database.BlockTableId, OpenMode.ForRead) as BlockTable;
                if (blockTable == null)
                    throw new System.NullReferenceException("blockTable == null");

                BlockTableRecord blockTableRecord =
                    action.GetObject(blockTable[BlockTableRecord.ModelSpace], OpenMode.ForWrite) as BlockTableRecord;
                if (blockTableRecord == null)
                    throw new System.NullReferenceException("blockTableRecord == null");

                foreach (_AcDb.Entity ent in list)
                {
                    if (ent != null)
                    {
                        ids.Add(blockTableRecord.AppendEntity(ent));
                        action.AddNewlyCreatedDBObject(ent, true);
                    }
                }
                action.Commit();
            }
            return ids;
        }

        public static Matrix3d worldToEye(ViewTableRecord view)
        {
            return Matrix3d.WorldToPlane(view.ViewDirection) *
                    Matrix3d.Displacement(Point3d.Origin - view.Target) *
                    Matrix3d.Rotation(view.ViewTwist, view.ViewDirection, view.Target);
        }

        public static double degToRad(double deg)
        {
            return deg * Math.PI / 180.0;
        }

        public static TinSurface createSampleTinSurface()
        {
            const double INNER_SURF_POINTS_OFFSET = 10;
            const double OUTER_SURF_POINTS_OFFSET = 50;
            Point3dCollection points = new Point3dCollection();

            points.Add(new Point3d(-INNER_SURF_POINTS_OFFSET, -INNER_SURF_POINTS_OFFSET, 0));
            points.Add(new Point3d(INNER_SURF_POINTS_OFFSET, -INNER_SURF_POINTS_OFFSET, 0));
            points.Add(new Point3d(INNER_SURF_POINTS_OFFSET, INNER_SURF_POINTS_OFFSET, 0));
            points.Add(new Point3d(-INNER_SURF_POINTS_OFFSET, INNER_SURF_POINTS_OFFSET, 0));

            points.Add(new Point3d(-OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, -10));
            points.Add(new Point3d(OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, -10));
            points.Add(new Point3d(OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10));
            points.Add(new Point3d(-OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10));

            TinSurface tinSurface = new TinSurface(new Point3d(-OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, 0),
                                    new Point3d(OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10),

                                    100);
            tinSurface.SetDatabaseDefaults();
            try
            {
                tinSurface.AddPoints(points);
                tinSurface.UpdateObjectData();
            }
            catch
            {
                return null;
            }

            return tinSurface;
        }
    }
}
