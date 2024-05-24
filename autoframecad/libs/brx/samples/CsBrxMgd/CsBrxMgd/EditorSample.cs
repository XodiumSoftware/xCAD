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

// alias
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;

namespace CsBrxMgd
{
    class EditorSample
    {
        //samp25
        public static void do_getSelectionSet()
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcDb.TypedValue[] dxfs = new _AcDb.TypedValue[] { new _AcDb.TypedValue((int)_AcDb.DxfCode.Start, "POINT") };
            _AcEd.SelectionFilter sfilter = new _AcEd.SelectionFilter(dxfs);

            _AcEd.PromptSelectionOptions pso = new _AcEd.PromptSelectionOptions();
            pso.MessageForAdding = "Select Points";
            pso.MessageForRemoval = "Remove Points";
            pso.AllowDuplicates = false;

            _AcEd.PromptSelectionResult res = editor.GetSelection(pso, sfilter);
            if (res.Status == _AcEd.PromptStatus.OK)
            {
                _AcEd.SelectionSet sset = res.Value;

                editor.WriteMessage("\nFound {0} points", sset.Count);
                editor.WriteMessage("\n{0}", getPointLocations(sset.GetObjectIds()).Count);
            }
        }

        public static _AcGe.Point3dCollection getPointLocations(_AcDb.ObjectId[] ids)
        {
            _AcGe.Point3dCollection locations = new _AcGe.Point3dCollection();
            _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
            _AcDb.TransactionManager manager = database.TransactionManager;
            using (_AcDb.Transaction action = manager.StartTransaction())
            {
                foreach (_AcDb.ObjectId id in ids)
                {
                    _AcDb.DBPoint point = action.GetObject(id, _AcDb.OpenMode.ForRead) as _AcDb.DBPoint;
                    if (point != null)
                        locations.Add(point.Position);
                }
                action.Commit();
            }
            return locations;
        }

        //samp18
        public static void do_getString()
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptStringOptions pop = new _AcEd.PromptStringOptions("this is a test");
            _AcEd.PromptResult res = editor.GetString(pop);
            _AcAp.Application.ShowAlertDialog(res.ToString());
        }

        public static void do_getKeyWords()
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptKeywordOptions pop = new _AcEd.PromptKeywordOptions("this is a test");
            pop.AppendKeywordsToMessage = true;
            pop.AllowNone = false;
            pop.Keywords.Add("A_Kwd");
            pop.Keywords.Add("B_Kwd");
            pop.Keywords.Add("C_Kwd");
            _AcEd.PromptResult res = editor.GetKeywords(pop);
            _AcAp.Application.ShowAlertDialog(res.ToString());
        }

        public static void do_getPoint()
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptPointOptions pop = new _AcEd.PromptPointOptions("Select Point");
            _AcEd.PromptPointResult res = editor.GetPoint(pop);
            _AcAp.Application.ShowAlertDialog(res.ToString());
        }

        public static void do_getDistance()
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptPointOptions ppo = new _AcEd.PromptPointOptions("Select Point");
            _AcEd.PromptPointResult ppr = editor.GetPoint(ppo);

            if (ppr.Status != _AcEd.PromptStatus.OK)
                throw new System.Exception("GetPoint failed");

            _AcEd.PromptDistanceOptions pdo = new _AcEd.PromptDistanceOptions("Select next Point");

            pdo.AllowNone = true;
            pdo.UseBasePoint = true;
            pdo.BasePoint = ppr.Value;
            pdo.UseDashedLine = true;

            _AcEd.PromptDoubleResult pdr = editor.GetDistance(pdo);

            if (pdr.Status != _AcEd.PromptStatus.OK)
                throw new System.Exception("GetDistance failed");
            _AcAp.Application.ShowAlertDialog(pdr.ToString());
        }

        // command samp22
        public static void do_getEntity()
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select a Hatch");
            peo.SetRejectMessage("Not a Hatch!");
            peo.AddAllowedClass(typeof(_AcDb.Hatch), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    _AcDb.Hatch hatch = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForWrite) as _AcDb.Hatch;
                    if (hatch != null)
                        _AcAp.Application.ShowAlertDialog("Area is " + hatch.Area.ToString());
                    action.Commit();
                }
            }
        }

        // command samp23
        public static void do_getEntity2()
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select a Line");
            peo.SetRejectMessage("Not a Line!");
            peo.AddAllowedClass(typeof(_AcDb.Line), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    _AcDb.Line line = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForWrite) as _AcDb.Line;
                    if (line != null)
                        _AcAp.Application.ShowAlertDialog("Length is " + line.Length.ToString());
                    action.Commit();
                }
            }
        }

        public static void do_MainWindow()
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            //AcAp.Application.MainWindow gives us access to the main window
            //so we can access/change its properties
            Bricscad.Windows.Window w = _AcAp.Application.MainWindow;
            w.Text = "*!*BricsCAD Rocks*!*";

            w.WindowState = System.Windows.Forms.FormWindowState.Minimized;
            if (w.WindowState == System.Windows.Forms.FormWindowState.Minimized)
                editor.WriteMessage("Minimized");

            w.WindowState = System.Windows.Forms.FormWindowState.Normal;
            if (w.WindowState == System.Windows.Forms.FormWindowState.Normal)
                editor.WriteMessage("Normal");

            w.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            if (w.WindowState == System.Windows.Forms.FormWindowState.Maximized)
                editor.WriteMessage("Maximized");
        }

        public static int sortByIds(_AcDb.FullSubentityPath a, _AcDb.FullSubentityPath b)
        {
            return a.SubentId.IndexPtr.ToInt32().CompareTo(b.SubentId.IndexPtr.ToInt32());
        }

        public static void OnPointMonitor(object sender, _AcEd.PointMonitorEventArgs eventArgs)
        {
            _AcDb.ObjectId id = _AcDb.ObjectId.Null;
            _AcEd.Editor editor = (_AcEd.Editor)sender;
            _AcAp.Document document = editor.Document;
            if (!editor.IsQuiescent)
                return;
            _AcEd.InputPointContext context = eventArgs.Context;
            Teigha.GraphicsInterface.ViewportDraw draw = context.DrawContext;
            draw.Geometry.Circle(context.RawPoint, 10, _AcGe.Vector3d.ZAxis);
            string names = null;
            _AcDb.FullSubentityPath[] paths = eventArgs.Context.GetPickedEntities();
            using (_AcDb.Transaction transaction = document.TransactionManager.StartTransaction())
            {
                Array.Sort(paths, sortByIds);
                foreach (_AcDb.FullSubentityPath path in paths)
                {
                    _AcDb.ObjectId[] ids = path.GetObjectIds();
                    if (ids.Length > 0)
                    {
                        _AcDb.BlockReference bref = transaction.GetObject(
                            ids[ids.GetLowerBound(0)], _AcDb.OpenMode.ForRead) as _AcDb.BlockReference;
                        if (bref != null)
                        {
                            names += string.Format("\nBlock Name= {0} {1}", bref.Name, path.SubentId.IndexPtr);
                            break;
                        }
                    }
                }
                transaction.Commit();
            }
            eventArgs.AppendToolTipText(names);
        }

    }
}
