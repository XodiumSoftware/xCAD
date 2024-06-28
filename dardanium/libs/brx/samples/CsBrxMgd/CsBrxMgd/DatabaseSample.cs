// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

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

// com
using BricscadDb;
using BricscadApp;

// alias
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;

namespace CsBrxMgd
{
    public class DatabaseSample
    {
        public static void do_addLine()
        {
            Point3d startPoint = new Point3d(0, 0, 0);
            Point3d endPoint = new Point3d(100, 100, 0);
            using (Line line = new Line(startPoint, endPoint))
            {
                DatabaseSample.AddToModelSpace(line);
            }
        }

        public static void do_addPolyLine()
        {
            using (Polyline pline1 = new Polyline(4))
            {
                pline1.AddVertexAt(0, new Point2d(0.0, 0.0), 0.1, 0, 0);
                pline1.AddVertexAt(1, new Point2d(0.0, 100.0), 0.1, 0, 0);
                pline1.AddVertexAt(2, new Point2d(100.0, 100.0), 0.1, 0, 0);
                pline1.AddVertexAt(3, new Point2d(100.0, 0.0), 0.1, 0, 0);
                pline1.Closed = true;

                using (Polyline pline2 = pline1.Clone() as Polyline)
                using (Polyline pline3 = pline1.Clone() as Polyline)
                {
                    pline2.TransformBy(Matrix3d.Rotation(0.261799388, Vector3d.ZAxis, new Point3d(50, 50, 0)));
                    pline3.TransformBy(Matrix3d.Rotation(0.523598776, Vector3d.ZAxis, new Point3d(50, 50, 0)));

                    DatabaseSample.AddToModelSpace(pline1, pline2, pline3);
                }
            }
        }

        public static void do_addLayer()
        {
            // get the database and start a new transaction
            Database database = HostApplicationServices.WorkingDatabase;
            _AcDb.TransactionManager manager = database.TransactionManager;

            using (Transaction action = manager.StartTransaction())
            {
                LayerTable layerTable =
                    action.GetObject(database.LayerTableId, OpenMode.ForWrite) as LayerTable;

                if (layerTable == null)
                    throw new System.NullReferenceException("LayerTable == null");

                if (!layerTable.Has("CoolLayer"))
                {
                    // create a new layer
                    using (LayerTableRecord myLayer = new LayerTableRecord())
                    {
                        myLayer.Name = "CoolLayer";
                        myLayer.Color = Teigha.Colors.Color.FromRgb(255, 0, 255);

                        layerTable.Add(myLayer);
                        action.AddNewlyCreatedDBObject(myLayer, true);
                    }
                }

                action.Commit();
            }
        }

        public static void do_addCircle()
        {
            using (Circle circle = new Circle(new Point3d(0, 0, 0), Vector3d.ZAxis, 3))
            using (Ellipse ellipse = new Ellipse(new Point3d(0, 0, 0),
                    Vector3d.ZAxis, Vector3d.YAxis, 0.6, 0.0, 2 * Math.PI))
            {
                DatabaseSample.AddToModelSpace(circle, ellipse);
            }
        }

        public static void do_performanceTest()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            Database database = HostApplicationServices.WorkingDatabase;
            if (database == null)
                throw new NullReferenceException("database is null");

            _AcDb.TransactionManager manager = database.TransactionManager;

            if (manager == null)
                throw new NullReferenceException("manager is null");

            using (Transaction action = manager.StartTransaction())
            {
                int countEnts = 0;
                Stopwatch sw = Stopwatch.StartNew();
                BlockTableRecord blockTableRecord = action.GetObject
                    (database.CurrentSpaceId, OpenMode.ForRead, false) as BlockTableRecord;

                if (blockTableRecord == null)
                    throw new NullReferenceException("blockTableRecord is null");

                foreach (ObjectId entityId in blockTableRecord)
                {
                    Entity entity = action.GetObject(entityId, OpenMode.ForRead, false) as Entity;
                    if (entity == null)
                        throw new NullReferenceException("entity is null");

                    countEnts++;
                }
                editor.WriteMessage("\n{0} Entities found in {1} Milliseconds", countEnts, sw.ElapsedMilliseconds);
                action.Commit();
            }
        }

        public static void do_readDwgFile()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            using (Database db = new Database(false, true))
            {
                db.ReadDwgFile(SelectDrawingFile("c:\\"), FileShare.Read, true, null);
                editor.WriteMessage("\nApproxNumObjects = {0}", db.ApproxNumObjects);
            }
        }

        public static void do_createTable()
        {
            Database database = HostApplicationServices.WorkingDatabase;

            using (Table table = new Table())
            {
                table.SetDatabaseDefaults(database);

                table.Position = Point3d.Origin;

                table.SetSize(6, 3);
                table.GenerateLayout();
                table.RecomputeTableBlock(true);

                for (int row = 0; row < table.Rows.Count; row++)
                {
                    for (int col = 0; col < table.Columns.Count; col++)
                    {
                        table.SetTextString(row, col, "BricsCAD");
                    }
                }

                table.RecomputeTableBlock(true);
                DatabaseSample.AddToModelSpace(table);
            }
        }

        public static void do_getBlockPreviewIcon()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            int nHasIcon = 0, nBlocks = 0;

            Database database = HostApplicationServices.WorkingDatabase;

            string path = Path.GetDirectoryName(database.Filename),
                    name = Path.GetFileName(database.Filename),
                    iconPath = path + "\\" + name + "-icons";

            _AcDb.TransactionManager tr = database.TransactionManager;
            using (Transaction action = tr.StartTransaction())
            {
                BlockTable bt = tr.GetObject(database.BlockTableId, OpenMode.ForRead) as BlockTable;
                foreach (ObjectId btrId in bt)
                {
                    BlockTableRecord btr = tr.GetObject(btrId, OpenMode.ForRead) as BlockTableRecord;
                    if (btr.IsLayout || btr.IsAnonymous)
                        continue;

                    nBlocks++;
                    if (btr.HasPreviewIcon)
                    {
                        nHasIcon++;

                        if (path.Length > 0)
                        {
                            if (!Directory.Exists(iconPath))
                                Directory.CreateDirectory(iconPath);

                            string blockName = btr.Name.Replace("|", "_"); // when btr.IsFromExternalReference || btr.IsFromOverlayReference;
                            string fname = iconPath + "\\" + blockName + ".bmp";
                            btr.PreviewIcon.Save(fname);
                        }
                        editor.WriteMessage("\nBlock '{0}' has preview icon", btr.Name);
                    }
                    else
                        editor.WriteMessage("\nBlock '{0}' has not preview icon", btr.Name);
                }
            }
            editor.WriteMessage("\n{0} blocks from {1} have preview icons", nHasIcon, nBlocks);
            if (nHasIcon > 0)
                editor.WriteMessage("\nbitmaps were created in folder: '{0}'", iconPath);
        }

        //helper Function to add items to ModelSpace;
        public static ObjectIdCollection AddToModelSpace(params Entity[] list)
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

                foreach (Entity ent in list)
                {
                    ids.Add(blockTableRecord.AppendEntity(ent));
                    action.AddNewlyCreatedDBObject(ent, true);
                }
                action.Commit();
            }
            return ids;
        }

        //helper Function
        private static string SelectDrawingFile(string initialDirectory)
        {
            System.Windows.Forms.OpenFileDialog dialog =
                new System.Windows.Forms.OpenFileDialog();
            dialog.Filter = "dwg files (*.dwg)|*.dwg";
            dialog.InitialDirectory = initialDirectory;
            dialog.Title = "Select a Drawing file";
            return (dialog.ShowDialog() == System.Windows.Forms.DialogResult.OK) ? dialog.FileName : null;
        }
    }
}
