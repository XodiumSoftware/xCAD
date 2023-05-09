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
    public class TinSurfaceSample
    {
        public static void do_TINCreate()
        {
            const double INNER_SURF_POINTS_OFFSET = 10;
            const double OUTER_SURF_POINTS_OFFSET = 50;
            Point3dCollection points = new Point3dCollection();

            points.Add(new Point3d(-INNER_SURF_POINTS_OFFSET, -INNER_SURF_POINTS_OFFSET, 0));
            points.Add(new Point3d(INNER_SURF_POINTS_OFFSET, -INNER_SURF_POINTS_OFFSET, 0));
            points.Add(new Point3d(INNER_SURF_POINTS_OFFSET, INNER_SURF_POINTS_OFFSET, 0));
            points.Add(new Point3d(-INNER_SURF_POINTS_OFFSET, INNER_SURF_POINTS_OFFSET, 0));

            points.Add(new Point3d(-OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, 10));
            points.Add(new Point3d(OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, 10));
            points.Add(new Point3d(OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10));
            points.Add(new Point3d(-OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10));

            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            TinSurface tinSurface = new TinSurface(new Point3d(-OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, 0),
                                    new Point3d(OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10),
                                    100);
            tinSurface.SetDatabaseDefaults();

            try
            {
                tinSurface.AddPoints(points);
            }
            catch
            {
                editor.WriteMessage("\nAdding points to TIN Surface failed");
                return;
            }

            ObjectIdCollection ids = Utils.AddToModelSpace(tinSurface);
        }

        public static void do_TINListData()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
            peo.SetRejectMessage("Not a TIN surface!");
            peo.AddAllowedClass(typeof(TinSurface), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    TinSurface tinSurface = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForWrite) as TinSurface;
                    if (tinSurface != null)
                    {
                        string surfaceHandleString = tinSurface.Handle.ToString();
                        editor.WriteMessage("\nSurface handle: {0}\n", surfaceHandleString);
                        editor.WriteMessage("\tSurface contains {0} points\n", tinSurface.GetGeneralProperties(true).NumberOfPoints);
                        editor.WriteMessage("\tSurface contains {0} trinagles\n", tinSurface.GetTinProperties(true).NumberOfTriangles);
                        editor.WriteMessage("\tSurface 2d is: {0}\n", tinSurface.GetTerrainProperties(true).SurfaceArea2d);
                        editor.WriteMessage("\tSurface 3d is: {0}\n", tinSurface.GetTerrainProperties(true).SurfaceArea3d);

                        IEnumerable<TinSurfaceConstraint> constraints = tinSurface.Constraints;
                        int count = 0;
                        foreach (TinSurfaceConstraint constraint in constraints)
                        {
                            count++;
                            string constraintTypeName = "unknown";
                            switch (constraint.ConstraintType)
                            {
                                case TinConstraintType.Boundary:
                                    constraintTypeName = "TinBoundary";
                                    break;
                                case TinConstraintType.Breakline:
                                    constraintTypeName = "TinBreakline";
                                    break;
                                case TinConstraintType.Wall:
                                    constraintTypeName = "TinWall";
                                    break;
                            }
                            editor.WriteMessage("\t constraint: ID: {0} - type: {1} - DBR: {2}\n",
                                                    constraint.ConstraintId,
                                                    constraintTypeName,
                                                    constraint.IsDbResident ? "true" : "false");

                            //If the constraint is reported DBRO it is possible to convert it to handle
                            if (constraint.IsDbResident)
                            {
                                Handle handle = new Handle((Int64)constraint.ConstraintId);
                                ObjectId constraintId = database.GetObjectId(false, handle, 0);
                                editor.WriteMessage("\t constraint handle: {0}  id: {1}\n",
                                    handle.ToString(),
                                    constraintId.ToString());
                                if (constraintId.IsValid)
                                {
                                    //Do something
                                }
                            }
                        }
                        if (count == 0)
                        {
                            editor.WriteMessage("\nSurface does not contain any constraints.");
                        }
                    }
                    action.Commit();
                }
            }
        }

        public static void do_TINListAllHandles()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcDb.TypedValue[] dxfs = new _AcDb.TypedValue[] { new _AcDb.TypedValue((int)_AcDb.DxfCode.Start, "BSYSCVDBTINSURFACE") };
            SelectionFilter filter = new SelectionFilter(dxfs);
            _AcEd.PromptSelectionResult psr = editor.SelectAll(filter);
            if (psr.Status == _AcEd.PromptStatus.OK)
            {
                SelectionSet sset = psr.Value;
                ObjectId[] ids = sset.GetObjectIds();
                editor.WriteMessage("\nThere is {0} TIN surfaces in the drawing.", ids.GetLength(0));
                if (ids.GetLength(0) > 0)
                    editor.WriteMessage("\nTheir handles are:");
                foreach (ObjectId id in ids)
                {
                    editor.WriteMessage("\n\t{0}", id.Handle);
                }
            }
            else
            {
                editor.WriteMessage("\nCould not find any TIN surface entities!");
            }
        }

        public static void do_TINAddBreakline()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
            peo.SetRejectMessage("Not a TIN surface!");
            peo.AddAllowedClass(typeof(TinSurface), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    TinSurface tinSurface = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForWrite) as TinSurface;
                    if (tinSurface != null)
                    {
                        List<TinSurfaceConstraint> constraints = new List<TinSurfaceConstraint>();

                        //Non Database Resident Object case
                        {
                            Point3dCollection points = new Point3dCollection();
                            points.Add(new Point3d(-20, -20, 5));
                            points.Add(new Point3d(-30, 0, 0));
                            points.Add(new Point3d(-20, 20, -5));

                            TinSurfaceBreakline breakline = new TinSurfaceBreakline(TinBreaklineType.Normal);
                            /*
                                Currently Non Database Resident constraints require a unique id
                                to be added to TIN Surface (you can use non unique one, but in such
                                case it will override the previous constraint definition while leaving
                                the points that were added by the (previous) definition).
                            */
                            UInt64 breaklineId = 1007510122;
                            breakline.SetData(breaklineId, points);

                            //add constraint to the list
                            constraints.Add(breakline);
                        }

                        //Database Resident Object case
                        {
                            Polyline polyline = new Polyline();
                            polyline.AddVertexAt(0, new Point2d(20, -20), 0.5, 0.0, 0.0);
                            polyline.AddVertexAt(1, new Point2d(30, 0), 0.0, 0.0, 0.0);
                            polyline.AddVertexAt(2, new Point2d(20, 20), 0.0, 0.0, 0.0);
                            polyline.Closed = false;

                            ObjectIdCollection ids = Utils.AddToModelSpace(polyline);

                            if ((ids.Count == 0) || ids[0].IsNull)
                            {
                                editor.WriteMessage("\nPolyline Id is null");
                                return;
                            }
                            TinSurfaceBreakline breakline = new TinSurfaceBreakline(TinBreaklineType.Normal);
                            /*
                                set the data via Database Resident Object,
                                midOrdinateDist defines maximal difference between the actual curve and the tessellated one
                            */
                            breakline.SetData(ids[0], 0.1);

                            //add constraint to the array
                            constraints.Add(breakline);
                        }


                        //Add multiple constraints at once to improve the preformance
                        try
                        {
                            tinSurface.AddConstraints(constraints, true);
                        }
                        catch
                        {
                            editor.WriteMessage("\nFailed to add constraints");
                        }
                    }
                    action.Commit();
                }
            }
        }

        public static void do_TINAddBoundary()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
            peo.SetRejectMessage("Not a TIN surface!");
            peo.AddAllowedClass(typeof(TinSurface), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    TinSurface tinSurface = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForWrite) as TinSurface;
                    if (tinSurface != null)
                    {
                        const double SHOW_BOUNDARY_POINTS_OFFSET = 5;
                        const double HIDE_BOUNDARY_POINTS_OFFSET = 9;

                        TinSurfaceBoundary showBoundary = new TinSurfaceBoundary(TinBoundaryType.Show);
                        TinSurfaceBoundary hideBoundary = new TinSurfaceBoundary(TinBoundaryType.Hide);

                        //Non Database Resident Case
                        {
                            Point3dCollection showBoundaryPoints = new Point3dCollection();

                            showBoundaryPoints.Add(new Point3d(-SHOW_BOUNDARY_POINTS_OFFSET, -SHOW_BOUNDARY_POINTS_OFFSET, 0));
                            showBoundaryPoints.Add(new Point3d(SHOW_BOUNDARY_POINTS_OFFSET, -SHOW_BOUNDARY_POINTS_OFFSET, 0));
                            showBoundaryPoints.Add(new Point3d(SHOW_BOUNDARY_POINTS_OFFSET, SHOW_BOUNDARY_POINTS_OFFSET, 0));
                            showBoundaryPoints.Add(new Point3d(-SHOW_BOUNDARY_POINTS_OFFSET, SHOW_BOUNDARY_POINTS_OFFSET, 0));

                            /*
                                Currently Non Database Resident constraints require a unique id
                                to be added to TIN Surface (you can use non unique one, but in such
                                case it will override the previous constraint definition while leaving
                                the points that were added by the (previous) definition).
                            */
                            UInt64 showBoundaryId = 1054400123;
                            showBoundary.SetData(showBoundaryId, showBoundaryPoints);
                        }

                        //Database Resident Case
                        {
                            Polyline polyline = new Polyline();
                            polyline.Closed = true;
                            polyline.AddVertexAt(0, new Point2d(-HIDE_BOUNDARY_POINTS_OFFSET, -HIDE_BOUNDARY_POINTS_OFFSET), 0, 0, 0);
                            polyline.AddVertexAt(1, new Point2d(HIDE_BOUNDARY_POINTS_OFFSET, -HIDE_BOUNDARY_POINTS_OFFSET), 0.5, 0, 0);
                            polyline.AddVertexAt(2, new Point2d(HIDE_BOUNDARY_POINTS_OFFSET, HIDE_BOUNDARY_POINTS_OFFSET), 0, 0, 0);
                            polyline.AddVertexAt(3, new Point2d(-HIDE_BOUNDARY_POINTS_OFFSET, HIDE_BOUNDARY_POINTS_OFFSET), 0, 0, 0);

                            ObjectIdCollection ids = Utils.AddToModelSpace(polyline);

                            /*
                                Set the boundary data via ObjectId. The boundary data is automatically parsed
                                from the object. Currently supported entities are Polyline, Polyline2d, Polyline3d,
                                Line, 
                            */

                            hideBoundary.SetData(ids[0], 0.1);
                        }

                        /*
                                The two (or more) constraints could be added to TIN Surface
                                with single command (tinSurface.AddConstraints) as in the 
                                AddBreakline() sample, to improve the preformance.

                                When adding the boundaries the user must be careful, since
                                changing the order of adding the boundaries can lead to different
                                result. (e.g. in this case first adding showBoundary and then
                                hideBoundary will _appear_ to only add the hideBoundary)
                        */
                        try
                        {
                            tinSurface.AddConstraint(hideBoundary, true);
                        }
                        catch
                        {
                            editor.WriteMessage("\nFailed to add hideBoundaryId");
                        }

                        try
                        {
                            tinSurface.AddConstraint(showBoundary, true);
                        }
                        catch
                        {
                            editor.WriteMessage("\nFailed to add showBoundary");
                        }
                    }
                    action.Commit();
                }
            }
        }

        public static void civilAddDBROConstraints(TinConstraintType constraintType)
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
            peo.SetRejectMessage("Not a TIN surface!");
            peo.AddAllowedClass(typeof(TinSurface), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    TinSurface tinSurface = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForWrite) as TinSurface;
                    if (tinSurface != null)
                    {
                        _AcEd.PromptEntityOptions peoCurve = new _AcEd.PromptEntityOptions("Select DBR Curve to add as a surface constraint: ");
                        peoCurve.SetRejectMessage("Not a Curve!");
                        peoCurve.AddAllowedClass(typeof(Curve), false);
                        _AcEd.PromptEntityResult perCurve = editor.GetEntity(peoCurve);
                        Curve curve = action.GetObject(perCurve.ObjectId, _AcDb.OpenMode.ForRead) as Curve;
                        if (curve == null)
                        {
                            return;
                        }
                        ObjectId polylineId = curve.ObjectId;

                        TinSurfaceConstraint constraint;
                        if (constraintType == TinConstraintType.Breakline)
                            constraint = new TinSurfaceBreakline(TinBreaklineType.Normal);
                        else if (constraintType == TinConstraintType.Boundary)
                            constraint = new TinSurfaceBoundary(TinBoundaryType.Hide);
                        else
                            constraint = new TinSurfaceWall(TinWallType.Normal);

                        /*
                            set the data via Database Resident Object,
                            midOrdinateDist defines maximal difference between the actual curve and the tessellated one
                        */
                        constraint.SetData(polylineId, 0.2);

                        /*
                            add constraint
                            and add reactor to the DBRO so the TIN Surface updates
                            it's breakline when users edit the polyline. If you do
                            not wish to dynamically conect the two entites you can
                            achieve that by passing false instead to addConstraint(s)
                            function.
                        */
                        try
                        {
                            tinSurface.AddConstraint(constraint, true);
                        }
                        catch
                        {
                            editor.WriteMessage("\nFailed to add constraint");
                        }

                        /*
                            TIN Surface automatically updates when it closes;
                            if we wish to update it while it's stil open a call to
                            tinSurface.UpdateObjectData() is needed to update surface
                            with currently cached data.
                        */
                        editor.WriteMessage("\nSurface 3d area: {0}", tinSurface.GetTerrainProperties(true).SurfaceArea3d);
                        tinSurface.UpdateObjectData();
                        editor.WriteMessage("\nAfter calling updateObjectData 3d area: {0}\n", tinSurface.GetTerrainProperties(true).SurfaceArea3d);
                    }
                    action.Commit();
                }
            }
        }

        public static void do_TINAddBreaklineDBRO()
        {
            civilAddDBROConstraints(TinConstraintType.Breakline);
        }

        public static void do_TINAddBoundaryDBRO()
        {
            civilAddDBROConstraints(TinConstraintType.Boundary);
        }


        public static void civilRemoveConstraint(TinConstraintType constraintType)
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
            peo.SetRejectMessage("Not a TIN surface!");
            peo.AddAllowedClass(typeof(TinSurface), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    TinSurface tinSurface = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForWrite) as TinSurface;
                    if (tinSurface != null)
                    {
                        IEnumerable<TinSurfaceConstraint> constraints = tinSurface.Constraints;

                        bool removedConstraint = false;
                        foreach (TinSurfaceConstraint constraint in constraints)
                        {
                            if (constraint.ConstraintType == constraintType)
                            {
                                try
                                {
                                    tinSurface.EraseConstraint(constraint.ConstraintId, true);
                                    editor.WriteMessage("\nSuccessfully removed constraint with ID: %d", constraint.ConstraintId);
                                    removedConstraint = true;
                                    break;

                                }
                                catch
                                {

                                }
                            }
                        }
                        if (!removedConstraint)
                        {
                            editor.WriteMessage("\nCould not find any matching constraints for removal.");
                        }
                    }
                    action.Commit();
                }
            }
        }

        public static void do_TINRemoveBreakline()
        {
            civilRemoveConstraint(TinConstraintType.Breakline);
        }

        public static void do_TINRemoveBoundary()
        {
            civilRemoveConstraint(TinConstraintType.Boundary);
        }

        public static void do_TINChangeStyle()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
            peo.SetRejectMessage("Not a TIN surface!");
            peo.AddAllowedClass(typeof(TinSurface), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    TinSurface tinSurface = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForWrite) as TinSurface;
                    if (tinSurface != null)
                    {
                        //Check existing style
                        {
                            TinSurfaceStyle style = tinSurface.Style;
                            editor.WriteMessage("Currently active TIN Surface styles: ");
                            if (style == TinSurfaceStyle.None)
                                editor.WriteMessage("none ");
                            if ((style & TinSurfaceStyle.BoundaryLine) != 0)
                                editor.WriteMessage("TinStyleBoundaryLine ");
                            if ((style & TinSurfaceStyle.Points) != 0)
                                editor.WriteMessage("TinStylePoints ");
                            if ((style & TinSurfaceStyle.Triangles) != 0)
                                editor.WriteMessage("TinStyleTriangles");
                            if ((style & TinSurfaceStyle.Contours) != 0)
                                editor.WriteMessage("TinStyleContours");
                            if ((style & TinSurfaceStyle.ElevationTooltip) != 0)
                                editor.WriteMessage("TinStyleElevationTooltip");
                            editor.WriteMessage("\n");
                        }

                        _AcEd.PromptIntegerOptions pio = new _AcEd.PromptIntegerOptions("Set style(0 - off, 1 - triangles, 2 - contours and points) :");
                        pio.LowerLimit = 0;
                        pio.UpperLimit = 3;
                        _AcEd.PromptIntegerResult pir = editor.GetInteger(pio);
                        if (pir.Status == _AcEd.PromptStatus.OK)
                        {
                            int userSelectedStyle = pir.Value;

                            //Update TIN Surface style
                            if (userSelectedStyle == 0)
                            {
                                editor.WriteMessage("\nSwitching off all styles.");
                                /*
                                    When all styles are switched off TIN Surface displays
                                    a bounding box (so that the user is still able to select
                                    the entity).
                                */
                                tinSurface.Style = TinSurfaceStyle.None;
                            }
                            else if (userSelectedStyle == 1)
                            {
                                editor.WriteMessage("\nSwitching style to triangles.");
                                tinSurface.Style = TinSurfaceStyle.Triangles;
                            }
                            else if (userSelectedStyle == 2)
                            {
                                editor.WriteMessage("\nSwitching style to contours and points.\n");
                                /*
                                    You can combine multiple TinSurfaceStyle to draw multiple
                                    different styles at once.
                                */
                                tinSurface.Style = (TinSurfaceStyle.Contours | TinSurfaceStyle.Points);
                            }
                            else
                            {
                                editor.WriteMessage("\nError selecting style.");
                                return;
                            }


                            //Set contour interval
                            {
                                _AcEd.PromptDoubleOptions promptMinorCI = new _AcEd.PromptDoubleOptions("Enter minor contour interval:");
                                _AcEd.PromptDoubleOptions promptMajorCI = new _AcEd.PromptDoubleOptions("Enter major contour interval:");
                                promptMinorCI.AllowNegative = false;
                                promptMajorCI.AllowNegative = false;

                                double majorContoursInterval = 5, minorContoursInterval = 1;

                                _AcEd.PromptDoubleResult resultMinorCI = editor.GetDouble(promptMinorCI);
                                if (resultMinorCI.Status == _AcEd.PromptStatus.OK)
                                    minorContoursInterval = resultMinorCI.Value;

                                _AcEd.PromptDoubleResult resultMajorCI = editor.GetDouble(promptMajorCI);
                                if (resultMajorCI.Status == _AcEd.PromptStatus.OK)
                                    majorContoursInterval = resultMajorCI.Value;

                                if (majorContoursInterval > (minorContoursInterval + Tolerance.Global.EqualPoint))
                                {
                                    tinSurface.MinorContoursInterval = minorContoursInterval;
                                    tinSurface.MajorContoursInterval = majorContoursInterval;
                                }
                                else
                                {
                                    editor.WriteMessage("\nSpecified minor contour interval is greater than major interval");
                                }
                            }

                            //Set contour colors
                            {
                                _AcEd.PromptIntegerOptions promptMinorCC = new _AcEd.PromptIntegerOptions("Enter minor contour color:");
                                _AcEd.PromptIntegerOptions promptMajorCC = new _AcEd.PromptIntegerOptions("Enter major contour color:");
                                promptMinorCC.LowerLimit = 0;
                                promptMinorCC.UpperLimit = 255;
                                promptMajorCC.LowerLimit = 0;
                                promptMajorCC.UpperLimit = 255;

                                UInt16 majorContoursColor = 1, minorContoursColor = 2;

                                _AcEd.PromptIntegerResult resultMinorCC = editor.GetInteger(promptMinorCC);
                                if (resultMinorCC.Status == _AcEd.PromptStatus.OK)
                                    minorContoursColor = Convert.ToUInt16(resultMinorCC.Value);

                                _AcEd.PromptIntegerResult resultMajorCC = editor.GetInteger(promptMajorCC);
                                if (resultMajorCC.Status == _AcEd.PromptStatus.OK)
                                    majorContoursColor = Convert.ToUInt16(resultMajorCC.Value);

                                UInt16 prevMajorContoursColor, prevMinorContoursColor;

                                prevMinorContoursColor = tinSurface.MinorContoursColor;
                                prevMajorContoursColor = tinSurface.MajorContoursColor;

                                editor.WriteMessage("\nSwitching (minor, major) contour colors from: {0} and {1} to {2} and {3}",
                                            prevMinorContoursColor,
                                            prevMajorContoursColor,
                                            minorContoursColor,
                                            majorContoursColor);

                                tinSurface.MinorContoursColor = minorContoursColor;
                                tinSurface.MajorContoursColor = majorContoursColor;
                            }
                        }
                    }
                    action.Commit();
                }
            }
        }

        public static void do_TINMerge()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
            _AcDb.TransactionManager manager = database.TransactionManager;
            using (_AcDb.Transaction action = manager.StartTransaction())
            {
                TinSurface tinSurface = null;
                TinSurface mergeTinSurface = null;
                _AcEd.PromptEntityOptions peo1 = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
                peo1.SetRejectMessage("Not a TIN surface!");
                peo1.AddAllowedClass(typeof(TinSurface), true);
                _AcEd.PromptEntityResult per1 = editor.GetEntity(peo1);
                if (per1.Status == _AcEd.PromptStatus.OK)
                {
                    tinSurface = action.GetObject(per1.ObjectId, _AcDb.OpenMode.ForRead) as TinSurface;
                    if (tinSurface == null)
                        return;
                }

                _AcEd.PromptEntityOptions peo2 = new _AcEd.PromptEntityOptions("Select second TIN Surface: ");
                peo2.SetRejectMessage("Not a TIN surface!");
                peo2.AddAllowedClass(typeof(TinSurface), true);
                _AcEd.PromptEntityResult per2 = editor.GetEntity(peo2);
                if (per2.Status == _AcEd.PromptStatus.OK)
                {
                    mergeTinSurface = action.GetObject(per2.ObjectId, _AcDb.OpenMode.ForRead) as TinSurface;
                    if (mergeTinSurface == null)
                        return;
                }

                int userMergeOption = 1;
                _AcEd.PromptIntegerOptions promptMergeOptions = new _AcEd.PromptIntegerOptions("0 - merge to existing, 1 - create new surface");
                promptMergeOptions.LowerLimit = 0;
                promptMergeOptions.UpperLimit = 1;
                _AcEd.PromptIntegerResult resultMergeOptions = editor.GetInteger(promptMergeOptions);
                if (resultMergeOptions.Status == _AcEd.PromptStatus.OK)
                    userMergeOption = resultMergeOptions.Value;

                if (userMergeOption == 1)
                {
                    TinSurface newTinSurface = TinSurface.Merge(tinSurface, mergeTinSurface);

                    if (newTinSurface == null)
                    {
                        editor.WriteMessage("\nMerge failed.");
                    }
                    else
                    {

                        //Point3dCollection points = new Point3dCollection();
                        //points.Add(new Point3d(10, 10, 13));
                        //points.Add(new Point3d(12, 12, 13));


                        //Polyline poly = new Polyline();
                        //poly.ColorIndex = 1;
                        //for (int i = 0; i < points.Count; i++)
                        //{
                        //    poly.AddVertexAt(i, new Point2d(points[i].X, points[i].Y), 0, 0, 0);
                        //}
                        //ObjectIdCollection ids = TinSurfaceSample.AddToModelSpace(poly);

                        editor.WriteMessage("\nNumber of points in merged surface: {0}", newTinSurface.GetGeneralProperties(true).NumberOfPoints);
                        ObjectIdCollection ids = Utils.AddToModelSpace(newTinSurface);
                        if ((ids.Count == 0) || (ids[0].IsNull))
                            editor.WriteMessage("\nFailed adding new surface to model space.");
                    }
                }
                else
                {
                    if (tinSurface.IsWriteEnabled == false)
                    {
                        tinSurface.UpgradeOpen();
                    }

                    try
                    {
                        tinSurface.Merge(mergeTinSurface);
                    }
                    catch
                    {
                        editor.WriteMessage("\nMerging pMergeSurface in to pSurface failed.");
                    }
                }

                action.Commit();
            }
        }

        public static void do_TINMesh()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
            peo.SetRejectMessage("Not a TIN surface!");
            peo.AddAllowedClass(typeof(TinSurface), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    TinSurface tinSurface = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForRead) as TinSurface;
                    if (tinSurface != null)
                    {
                        double maxElevation = tinSurface.GetGeneralProperties(true).MaxElevation;
                        double minElevation = tinSurface.GetGeneralProperties(true).MinElevation;

                        //TinSurfaceMeshType.TinSurfaceMeshDepth
                        {
                            /*
                                TinSurfaceMeshDepth creates mesh by duplicating the surface vertices (points)
                                and adding the 'thickness' parameter to the Z-coordinate of duplicated points.
                                Points are then 'stiched' together to create a closed mesh. 
                            */
                            SubDMesh meshAbove = tinSurface.GetMesh(TinSurfaceExtractType.Depth, 1.0);
                            SubDMesh meshBelow = tinSurface.GetMesh(TinSurfaceExtractType.Depth, -1.0);
                            if ((meshAbove != null) && (meshBelow != null))
                            {
                                meshAbove.ColorIndex = 1;
                                meshBelow.ColorIndex = 2;
                                ObjectIdCollection ids = Utils.AddToModelSpace(meshAbove, meshBelow);
                            }
                        }

                        //TinSurfaceMeshType.TinSurfaceMeshElevation
                        {
                            /*
                                TinSurfaceMeshElevation creates mesh by duplicating the surface vertices (points)
                                and setting the Z-coordinate of the duplicated points to given parameter.
                                Points are then 'stiched' together to create a closed mesh. 
                            */
                            SubDMesh meshAbove = tinSurface.GetMesh(TinSurfaceExtractType.Elevation, maxElevation + 5.0);
                            SubDMesh meshBetween = tinSurface.GetMesh(TinSurfaceExtractType.Elevation, (maxElevation + minElevation) / 2.0);
                            SubDMesh meshBelow = tinSurface.GetMesh(TinSurfaceExtractType.Elevation, minElevation - 5.0);
                            if ((meshAbove != null) && (meshBetween != null) && (meshBelow != null))
                            {
                                meshAbove.ColorIndex = 3;
                                meshBetween.ColorIndex = 4;
                                meshBelow.ColorIndex = 5;
                                ObjectIdCollection ids = Utils.AddToModelSpace(meshAbove, meshBetween, meshBelow);
                            }
                        }
                    }
                    action.Commit();
                }
            }
        }


        public static void do_TINDrape()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
            peo.SetRejectMessage("Not a TIN surface!");
            peo.AddAllowedClass(typeof(TinSurface), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    TinSurface tinSurface = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForRead) as TinSurface;
                    if (tinSurface != null)
                    {
                        Extents2d boundingBox = tinSurface.BoundingBox;
                        double maxElevation = tinSurface.GetGeneralProperties(false).MaxElevation;

                        Point3dCollection points = new Point3dCollection();
                        points.Add(new Point3d(boundingBox.MaxPoint.X, boundingBox.MaxPoint.Y, maxElevation));
                        points.Add(new Point3d(boundingBox.MinPoint.X, boundingBox.MinPoint.Y, maxElevation));

                        points.Add(new Point3d(boundingBox.MinPoint.X + 10, boundingBox.MinPoint.Y + 10, maxElevation));
                        points.Add(new Point3d(boundingBox.MinPoint.X + 10, (boundingBox.MinPoint.Y + boundingBox.MaxPoint.Y) / 2, maxElevation));
                        points.Add(new Point3d(boundingBox.MaxPoint.X, (boundingBox.MinPoint.Y + boundingBox.MaxPoint.Y) / 2, maxElevation));

                        Polyline poly = new Polyline();
                        poly.ColorIndex = 1;
                        for (int i = 0; i < points.Count; i++)
                        {
                            poly.AddVertexAt(i, new Point2d(points[i].X, points[i].Y), 0, 0, 0);
                        }
                        ObjectIdCollection ids = Utils.AddToModelSpace(poly);

                        /*
                        The drape function projects a 3d polyline onto the given TIN Surface.
                        The result can be:
                            - empty (given points (polyline vertices) and the surface do not intersect,
                            if both would be projected onto XY plane)
                            - one Point3dCollection (all the polyline vertices can be projected without
                            any discontinuites)
                            - multiple resulting Point3dCollections (some parts of the polyline
                            can be projected on the surface, while others "fall" of the surface
                            or are inside the hide boundaries)
                        */

                        IEnumerable<Point3dCollection> drapedPointGroups = tinSurface.Drape(points);
                        foreach (Point3dCollection drapedPoints in drapedPointGroups)
                        {
                            Polyline3d polyline = new Polyline3d(Poly3dType.SimplePoly, drapedPoints, false);
                            polyline.ColorIndex = 3;
                            Utils.AddToModelSpace(polyline);
                        }
                    }
                    action.Commit();
                }
            }
        }



        //////////////////////////////////////////////////////////////////////////////
        // Volume surface examples
        //////////////////////////////////////////////////////////////////////////////

        /*
        CASES:
        // initializes the TinVolumeSurface based on 2 surfaces, and a bounding contour
        public virtual bool Initialize( CivilTinSurface baseSurface, 
                                        CivilTinSurface compSurface, 
                                        Point3dCollection boundingPolygon);
        
        // initializes the TinVolumeSurface based on 2 surfaces, and a bounding contour
        // taken from specified contour entity (using midOrdinateDist to determine the smoothness)
        public virtual bool Initialize( CivilTinSurface baseSurface, 
                                        CivilTinSurface compSurface, 
                                        ObjectId objId, 
                                        double midOrdinateDist);
        */

        public static void do_TINVolumeSurfaceCreate()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
            peo.SetRejectMessage("Not a TIN surface!");
            peo.AddAllowedClass(typeof(TinSurface), false);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    TinSurface tinSurface = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForRead) as TinSurface;
                    if (tinSurface != null)
                    {
                        //Create a clone of the selected surface
                        TinSurface clonedSurface = (TinSurface)tinSurface.Clone();
                        if (clonedSurface == null)
                        {
                            return;
                        }

                        const double CLONED_SURFACE_OFFSET = 10;
                        clonedSurface.RaiseSurface(CLONED_SURFACE_OFFSET);

                        TinVolumeSurface tinVolumeSurface = new TinVolumeSurface(tinSurface, clonedSurface, new Point3dCollection());
                        double area2d = tinSurface.GetTerrainProperties(true).SurfaceArea2d;
                        if (tinVolumeSurface.VolumeProperties.FillVolume.Equals(area2d * CLONED_SURFACE_OFFSET))
                        {
                            editor.WriteMessage("\nVolume between the surfaces: {0}", tinVolumeSurface.VolumeProperties.FillVolume);
                        }
                        else
                        {
                            editor.WriteMessage("\nVolume was wrongly calculated!");
                        }

                        Utils.AddToModelSpace(clonedSurface);
                        Utils.AddToModelSpace(tinVolumeSurface);
                    }
                    action.Commit();
                }
            }
        }


        public static void do_TINVolumeSurfaceElevationCreate()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select TIN Surface: ");
            peo.SetRejectMessage("Not a TIN surface!");
            peo.AddAllowedClass(typeof(TinSurface), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    TinSurface tinSurface = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForRead) as TinSurface;
                    if (tinSurface != null)
                    {
                        _AcEd.PromptDoubleOptions promptElevation = new _AcEd.PromptDoubleOptions("\nEnter the reference elevation:");
                        promptElevation.AllowNegative = true;

                        double elevation = 0.0;

                        _AcEd.PromptDoubleResult resultElevation = editor.GetDouble(promptElevation);
                        if (resultElevation.Status == _AcEd.PromptStatus.OK)
                            elevation = resultElevation.Value;

                        /*
                            TinVolumeSurfaceType.TinVolumeToElevation - calculates the volume between the XY plane
                            with specified reference elevation and the provided CivilTinSurface (or any derived type)
                        */
                        TinVolumeSurface volumeSurface1 = new TinVolumeSurface(tinSurface, elevation, TinVolumeSurfaceType.ToElevation, new Point3dCollection());

                        /*
                            TinVolumeSurfaceType.TinVolumeToDepth - calculates the volume of surface raised / lowered by the
                            specified elevation(exactly the same as done in the example cmdCivilVolumeSurfaceCreate).
                        */
                        TinVolumeSurface volumeSurface2 = new TinVolumeSurface(tinSurface, elevation, TinVolumeSurfaceType.ToElevation, new Point3dCollection());

                        /*
                                There is no need to add the CivilTinVolumeSurface entities to the Database,
                                (since we are only interested in the cut/fill volumes).
                        */
                        editor.WriteMessage("\nTinVolumeToElevation : Fill volume: {0}  Cut volume: {1}",
                                    volumeSurface1.VolumeProperties.FillVolume,
                                    volumeSurface1.VolumeProperties.CutVolume);
                        editor.WriteMessage("\nTinVolumeToDepth : Fill volume: {0}  Cut volume: {1}",
                                    volumeSurface2.VolumeProperties.FillVolume,
                                    volumeSurface2.VolumeProperties.CutVolume);
                    }
                    action.Commit();
                }
            }
        }


        public static void do_TINVolumeSurfaceBounded()
        {
            const double SURFACE_SIZE = 10;
            Point3dCollection roofShapedPoints = new Point3dCollection();
            roofShapedPoints.Add(new Point3d(-SURFACE_SIZE, -SURFACE_SIZE, 0));
            roofShapedPoints.Add(new Point3d(0, -SURFACE_SIZE, SURFACE_SIZE));
            roofShapedPoints.Add(new Point3d(SURFACE_SIZE, -SURFACE_SIZE, 0));
            roofShapedPoints.Add(new Point3d(SURFACE_SIZE, SURFACE_SIZE, 0));
            roofShapedPoints.Add(new Point3d(0, SURFACE_SIZE, SURFACE_SIZE));
            roofShapedPoints.Add(new Point3d(-SURFACE_SIZE, SURFACE_SIZE, 0));

            Point3dCollection flatPoints = new Point3dCollection();
            flatPoints.Add(new Point3d(-SURFACE_SIZE, -SURFACE_SIZE, SURFACE_SIZE / 2));
            flatPoints.Add(new Point3d(0, -SURFACE_SIZE, SURFACE_SIZE / 2));
            flatPoints.Add(new Point3d(SURFACE_SIZE, -SURFACE_SIZE, SURFACE_SIZE / 2));
            flatPoints.Add(new Point3d(SURFACE_SIZE, SURFACE_SIZE, SURFACE_SIZE / 2));
            flatPoints.Add(new Point3d(0, SURFACE_SIZE, SURFACE_SIZE / 2));
            flatPoints.Add(new Point3d(-SURFACE_SIZE, SURFACE_SIZE, SURFACE_SIZE / 2));

            TinSurface tinSurface = new TinSurface(new Point3d(-SURFACE_SIZE, -SURFACE_SIZE, 0),
                                    new Point3d(SURFACE_SIZE, SURFACE_SIZE, 0),
                                    (ulong)roofShapedPoints.Count);
            tinSurface.AddPoints(roofShapedPoints);

            TinSurface tinSurfaceFlat = new TinSurface(new Point3d(-SURFACE_SIZE, -SURFACE_SIZE, 0),
                                        new Point3d(SURFACE_SIZE, SURFACE_SIZE, 0),
                                        (ulong)flatPoints.Count);
            tinSurface.AddPoints(flatPoints);

            Utils.AddToModelSpace(tinSurface, tinSurfaceFlat);

            TinVolumeSurface volumeSurface1;
            TinVolumeSurface volumeSurface2;

            //Bound the volume calculation to the upper left quarter of the created surface
            {
                Point3dCollection boundaryNDBR = new Point3dCollection();
                boundaryNDBR.Add(new Point3d(-SURFACE_SIZE, 0, 0));
                boundaryNDBR.Add(new Point3d(0, 0, 0));
                boundaryNDBR.Add(new Point3d(0, SURFACE_SIZE, 0));
                boundaryNDBR.Add(new Point3d(-SURFACE_SIZE, SURFACE_SIZE, 0));

                /*
                    Calculates the volume between the tinSurface and the flatSurface bounded by the
                    points passed in (visually only the upper left quarter of the tinSurface).
                */
                volumeSurface1 = new TinVolumeSurface(tinSurface, tinSurfaceFlat, boundaryNDBR);
            }

            //Bound the volume calculation to the right half of the created surface
            {
                Polyline polyline = new Polyline();
                polyline.AddVertexAt(0, new Point2d(0, -SURFACE_SIZE), 0, 0, 0);
                polyline.AddVertexAt(1, new Point2d(SURFACE_SIZE, -SURFACE_SIZE), 0, 0, 0);
                polyline.AddVertexAt(2, new Point2d(SURFACE_SIZE, SURFACE_SIZE), 0, 0, 0);
                polyline.AddVertexAt(3, new Point2d(0, SURFACE_SIZE), 0, 0, 0);
                polyline.Closed = true;

                ObjectId polylineId = Utils.AddToModelSpace(polyline)[0];

                /*
                    Calculates the volume between the tinSurface and the XY plane with elevation 0 bounded by the 
                    polylineId (visually only the right half of the tinSurface).
                */
                volumeSurface2 = new TinVolumeSurface(tinSurface, 0.0, TinVolumeSurfaceType.ToElevation, polylineId, 0.1);
            }

            double fillVolume1 = volumeSurface1.VolumeProperties.FillVolume;
            double cutVolume1 = volumeSurface1.VolumeProperties.CutVolume;
            double fillVolume2 = volumeSurface2.VolumeProperties.FillVolume;
            double cutVolume2 = volumeSurface2.VolumeProperties.CutVolume;

            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            editor.WriteMessage("\nFill/cut of pVolumeSurface1: {0}, {1}.", fillVolume1, cutVolume1);
            editor.WriteMessage("\nFill/cut of pVolumeSurface2: {0}, {1}.", fillVolume2, cutVolume2);
        }

        private enum ETypeOfScheme { eSchemeRed, eSchemeGreen, eSchemeBlue }
        private enum ETypeOfEntity { eTypeMesh, eTypeFace }

        private static Teigha.Colors.Color generateColorSheme(ETypeOfScheme typeOfSheme, int colorIndex)
        {
            if (colorIndex > 255)
                colorIndex = 255;
            Teigha.Colors.Color color = null;
            if (typeOfSheme == ETypeOfScheme.eSchemeRed)
                color = Teigha.Colors.Color.FromRgb(Convert.ToByte(colorIndex), 0, 0);
            else if (typeOfSheme == ETypeOfScheme.eSchemeGreen)
                color = Teigha.Colors.Color.FromRgb(0, Convert.ToByte(colorIndex), 0);
            else
                color = Teigha.Colors.Color.FromRgb(0, 0, Convert.ToByte(colorIndex));
            return color;
        }

        private static List<_AcDb.Entity> generateMeshes(List<List<TinSurfaceTriangle>> tinTrianglesRanges,
            int numOfRanges, ETypeOfScheme typeOfScheme)
        {
            int rangeIndex = 0;
            int colorRange = 255 / (numOfRanges - 1);
            var entities = new List<_AcDb.Entity>();
            foreach (var tinTriangleRange in tinTrianglesRanges)
            {
                if (tinTriangleRange.Count == 0)
                {
                    ++rangeIndex;
                    continue;
                }
                var uniqueVertices = new Dictionary<TinSurfaceVertex, Int32>(tinTriangleRange.Count);
                //unique points from triangles
                var point3DCollection = new Point3dCollection();
                foreach (var tinTriangle in tinTriangleRange)
                {
                    if (!uniqueVertices.ContainsKey(tinTriangle.Vertex1))
                    {
                        point3DCollection.Add(tinTriangle.Vertex1.Location);
                        uniqueVertices[tinTriangle.Vertex1] = point3DCollection.Count - 1;
                    }
                    if (!uniqueVertices.ContainsKey(tinTriangle.Vertex2))
                    {
                        point3DCollection.Add(tinTriangle.Vertex2.Location);
                        uniqueVertices[tinTriangle.Vertex2] = point3DCollection.Count - 1;
                    }
                    if (!uniqueVertices.ContainsKey(tinTriangle.Vertex3))
                    {
                        point3DCollection.Add(tinTriangle.Vertex3.Location);
                        uniqueVertices[tinTriangle.Vertex3] = point3DCollection.Count - 1;
                    }
                }
                //make faces indices for meshes
                var trianglesIndices = new Int32Collection();
                foreach (var tinTriangle in tinTriangleRange)
                {
                    trianglesIndices.Add(3);
                    trianglesIndices.Add(uniqueVertices[tinTriangle.Vertex1]);
                    trianglesIndices.Add(uniqueVertices[tinTriangle.Vertex2]);
                    trianglesIndices.Add(uniqueVertices[tinTriangle.Vertex3]);
                }
                //create subDMesh-es
                var subDMesh = new SubDMesh();
                subDMesh.SetDatabaseDefaults();
                subDMesh.SetSubDMesh(point3DCollection, trianglesIndices, 0);
                int colorIndex = rangeIndex * colorRange;
                if (colorIndex > colorRange * (numOfRanges - 1))
                    colorIndex = 255;
                var color = generateColorSheme(typeOfScheme, colorIndex);
                subDMesh.Color = color;
                entities.Add(subDMesh);
                ++rangeIndex;
            }
            return entities;
        }

        private static List<_AcDb.Entity> generateFaces(List<List<TinSurfaceTriangle>> tinTrianglesRanges,
            int numOfRanges, ETypeOfScheme typeOfScheme)
        {
            int rangeIndex = 0;
            int colorRange = 255 / (numOfRanges - 1);
            var entities = new List<_AcDb.Entity>();
            foreach (var tinTriangleRange in tinTrianglesRanges)
            {
                if (tinTriangleRange.Count == 0)
                {
                    ++rangeIndex;
                    continue;
                }
                int colorIndex = rangeIndex * colorRange;
                if (colorIndex > colorRange * (numOfRanges - 1))
                    colorIndex = 255;
                var color = generateColorSheme(typeOfScheme, colorIndex);
                foreach (var tinTriangle in tinTriangleRange)
                {
                    var dbFace = new Face(tinTriangle.Vertex1.Location,
                            tinTriangle.Vertex2.Location,
                            tinTriangle.Vertex3.Location,
                            tinTriangle.Vertex1.Location,
                            true, true, true, true);
                    dbFace.SetDatabaseDefaults();
                    dbFace.Color = color;
                    entities.Add(dbFace);
                }
                ++rangeIndex;
            }
            return entities;
        }

        public static void do_colorSchemesByElevation()
        {
            Editor editor = Application.DocumentManager.MdiActiveDocument.Editor;
            var promptEntityOptions = new PromptEntityOptions("Select TIN Surface: ");
            promptEntityOptions.SetRejectMessage("Not a TIN surface!");
            promptEntityOptions.AddAllowedClass(typeof(TinSurface), true);
            var promptEntityResult = editor.GetEntity(promptEntityOptions);
            if (promptEntityResult.Status != PromptStatus.OK)
                return;
            var selectedEntityId = promptEntityResult.ObjectId;

            var promptIntegerOptions = new PromptIntegerOptions("Enter number of ranges:");
            promptIntegerOptions.AllowZero = false;
            promptIntegerOptions.AllowNegative = false;
            promptIntegerOptions.DefaultValue = 10;
            var promptIntegerResult = editor.GetInteger(promptIntegerOptions);
            if (promptIntegerResult.Status != PromptStatus.OK)
                return;
            var numOfRanges = promptIntegerResult.Value;

            var promptKeywordOptions = new PromptKeywordOptions("Enter color scheme");
            promptKeywordOptions.Keywords.Add("Red");
            promptKeywordOptions.Keywords.Add("Green");
            promptKeywordOptions.Keywords.Add("Blue");
            promptKeywordOptions.Keywords.Default = "Red";
            promptKeywordOptions.AppendKeywordsToMessage = true;
            var promptKeywordResult = editor.GetKeywords(promptKeywordOptions);
            if (promptKeywordResult.Status != PromptStatus.OK)
                return;
            ETypeOfScheme typeOfScheme = ETypeOfScheme.eSchemeRed;
            if (promptKeywordResult.StringResult == "Green")
                typeOfScheme = ETypeOfScheme.eSchemeGreen;
            else if (promptKeywordResult.StringResult == "Blue")
                typeOfScheme = ETypeOfScheme.eSchemeBlue;

            promptKeywordOptions = new PromptKeywordOptions("Enter entity type");
            promptKeywordOptions.Keywords.Add("Meshes");
            promptKeywordOptions.Keywords.Add("Faces");
            promptKeywordOptions.Keywords.Default = "Meshes";
            promptKeywordOptions.AppendKeywordsToMessage = true;
            promptKeywordResult = editor.GetKeywords(promptKeywordOptions);
            if (promptKeywordResult.Status != PromptStatus.OK)
                return;
            ETypeOfEntity typeOfEntity;
            if (promptKeywordResult.StringResult == "Faces")
                typeOfEntity = ETypeOfEntity.eTypeFace;
            else
                typeOfEntity = ETypeOfEntity.eTypeMesh;

            var database = HostApplicationServices.WorkingDatabase;
            List<_AcDb.Entity> modelEntities = null;
            using (var action = database.TransactionManager.StartTransaction())
            {
                var tinSurface = action.GetObject(selectedEntityId, OpenMode.ForRead) as TinSurface;
                if (tinSurface != null)
                {
                    //clone existing to prevent changing of original entity
                    var tinSurfaceClone = tinSurface.Clone() as TinSurface;
                    var triangles = tinSurfaceClone.Triangles;
                    //find min/max surface elevation
                    double minElevation = tinSurface.GeneralProperties.MinElevation;
                    double maxElevation = tinSurface.GeneralProperties.MaxElevation;
                    double elevFactor = (maxElevation - minElevation) / numOfRanges;
                    double currentElevation = minElevation;
                    var listOfBreaklines = new List<TinSurfaceConstraint>();
                    ulong breaklineId = 1;
                    //create non-destructive breaklines on elevations
                    for (int i = 0; i < numOfRanges; ++i)
                    {
                        IEnumerable<Point3dCollection> contoursAtElev = null;
                        currentElevation += elevFactor;
                        try
                        {
                            contoursAtElev = tinSurfaceClone.GetContoursAt(currentElevation);
                        }
                        catch { }
                        if (contoursAtElev == null)
                            continue;
                        foreach (var contourAtElev in contoursAtElev)
                        {
                            var tinSurfaceBreakline = new TinSurfaceBreakline(TinBreaklineType.NonDestructive);
                            tinSurfaceBreakline.SetData(breaklineId++, contourAtElev);
                            listOfBreaklines.Add(tinSurfaceBreakline);
                        }
                    }
                    tinSurfaceClone.AddConstraints(listOfBreaklines, false);
                    //only memory object - UpdateObjectData must be called
                    tinSurfaceClone.UpdateObjectData();

                    var tinTrianglesRanges = new List<List<TinSurfaceTriangle>>();
                    for (int i = 0; i < numOfRanges; ++i)
                    {
                        tinTrianglesRanges.Add(new List<TinSurfaceTriangle>());
                    }

                    triangles = tinSurfaceClone.Triangles;
                    foreach (var triangle in triangles)
                    {
                        //check elevation of center
                        double midElevation = (
                            triangle.Vertex1.Location.Z +
                            triangle.Vertex2.Location.Z +
                            triangle.Vertex3.Location.Z) / 3;
                        //create index from elevation
                        int index = (int)((midElevation - minElevation) / elevFactor);
                        if (index < 0)
                            index = 0;
                        else if (index > numOfRanges - 1)
                            index = numOfRanges - 1;
                        tinTrianglesRanges[index].Add(triangle);
                    }
                    //meshes
                    if (typeOfEntity == ETypeOfEntity.eTypeMesh)
                        modelEntities = generateMeshes(tinTrianglesRanges,
                        numOfRanges, typeOfScheme);
                    //faces
                    else
                        modelEntities = generateFaces(tinTrianglesRanges,
                            numOfRanges, typeOfScheme);
                }
                action.Commit();
            }
            if (modelEntities != null && modelEntities.Count > 0)
                Utils.AddToModelSpace(modelEntities.ToArray());
        }

        public static void do_colorSchemesBySlope()
        {
            Editor editor = Application.DocumentManager.MdiActiveDocument.Editor;
            var promptEntityOptions = new PromptEntityOptions("Select TIN Surface: ");
            promptEntityOptions.SetRejectMessage("Not a TIN surface!");
            promptEntityOptions.AddAllowedClass(typeof(TinSurface), true);
            var promptEntityResult = editor.GetEntity(promptEntityOptions);
            if (promptEntityResult.Status != PromptStatus.OK)
                return;
            var selectedEntityId = promptEntityResult.ObjectId;

            var promptIntegerOptions = new PromptIntegerOptions("Enter number of ranges:");
            promptIntegerOptions.AllowZero = false;
            promptIntegerOptions.AllowNegative = false;
            promptIntegerOptions.DefaultValue = 10;
            var promptIntegerResult = editor.GetInteger(promptIntegerOptions);
            if (promptIntegerResult.Status != PromptStatus.OK)
                return;
            var numOfRanges = promptIntegerResult.Value;

            var promptKeywordOptions = new PromptKeywordOptions("Enter color scheme");
            promptKeywordOptions.Keywords.Add("Red");
            promptKeywordOptions.Keywords.Add("Green");
            promptKeywordOptions.Keywords.Add("Blue");
            promptKeywordOptions.Keywords.Default = "Red";
            promptKeywordOptions.AppendKeywordsToMessage = true;
            var promptKeywordResult = editor.GetKeywords(promptKeywordOptions);
            if (promptKeywordResult.Status != PromptStatus.OK)
                return;
            ETypeOfScheme typeOfScheme = ETypeOfScheme.eSchemeRed;
            if (promptKeywordResult.StringResult == "Green")
                typeOfScheme = ETypeOfScheme.eSchemeGreen;
            else if (promptKeywordResult.StringResult == "Blue")
                typeOfScheme = ETypeOfScheme.eSchemeBlue;

            promptKeywordOptions = new PromptKeywordOptions("Enter entity type");
            promptKeywordOptions.Keywords.Add("Meshes");
            promptKeywordOptions.Keywords.Add("Faces");
            promptKeywordOptions.Keywords.Default = "Meshes";
            promptKeywordOptions.AppendKeywordsToMessage = true;
            promptKeywordResult = editor.GetKeywords(promptKeywordOptions);
            if (promptKeywordResult.Status != PromptStatus.OK)
                return;
            ETypeOfEntity typeOfEntity;
            if (promptKeywordResult.StringResult == "Faces")
                typeOfEntity = ETypeOfEntity.eTypeFace;
            else
                typeOfEntity = ETypeOfEntity.eTypeMesh;

            var database = HostApplicationServices.WorkingDatabase;
            List<_AcDb.Entity> modelEntities = null;
            using (var action = database.TransactionManager.StartTransaction())
            {
                var tinSurface = action.GetObject(selectedEntityId, OpenMode.ForRead) as TinSurface;
                if (tinSurface != null)
                {
                    //clone existing to prevent changing of original entity
                    var triangles = tinSurface.Triangles;
                    var angleFactor = (Math.PI * 0.5) / numOfRanges;

                    var tinTrianglesRanges = new List<List<TinSurfaceTriangle>>();
                    for (int i = 0; i < numOfRanges; ++i)
                    {
                        tinTrianglesRanges.Add(new List<TinSurfaceTriangle>());
                    }

                    foreach (var triangle in triangles)
                    {
                        List<Point3d> point3Ds = new List<Point3d>();
                        point3Ds.Add(triangle.Vertex1.Location);
                        point3Ds.Add(triangle.Vertex2.Location);
                        point3Ds.Add(triangle.Vertex3.Location);
                        point3Ds.Sort((a, b) => (a.Z.CompareTo(b.Z)));

                        Vector3d vec = (point3Ds[2] - point3Ds[0]);
                        double angleToPlane = vec.GetAngleTo(Vector3d.ZAxis);

                        int index = (int)(angleToPlane / angleFactor);
                        if (index < 0)
                            index = 0;
                        else if (index > numOfRanges - 1)
                            index = numOfRanges - 1;
                        tinTrianglesRanges[index].Add(triangle);
                    }
                    //meshes
                    if (typeOfEntity == ETypeOfEntity.eTypeMesh)
                        modelEntities = generateMeshes(tinTrianglesRanges,
                        numOfRanges, typeOfScheme);
                    //faces
                    else
                        modelEntities = generateFaces(tinTrianglesRanges,
                            numOfRanges, typeOfScheme);
                }
                action.Commit();
            }
            if (modelEntities != null && modelEntities.Count > 0)
                Utils.AddToModelSpace(modelEntities.ToArray());
        }


        //////////////////////////////////////////////////////////////////////////////
        // JIG surface example
        //////////////////////////////////////////////////////////////////////////////


        public class MySurfaceJig : EntityJig, IDisposable
        {
            private Point3d currentCursorPosition;
            private bool disposed;
            private Editor editor;
            private Point3d previousCursorPosition;
            private Point3dCollection outerPolygon;
            private Point3dCollection innerPolygon;
            private TinSurface tinSurfaceBase;
            private Point3dCollection insidePoints;
            private Point3dCollection outerPoints;
            private double newElevation;

            public MySurfaceJig(TinSurface baseSurface, Point3dCollection oPolygon, Point3dCollection iPolygon)
                : base(InitEntity())
            {
                this.editor = Application.DocumentManager.MdiActiveDocument.Editor;
                this.previousCursorPosition = Point3d.Origin;
                outerPolygon = oPolygon;
                innerPolygon = iPolygon;
                tinSurfaceBase = baseSurface;
                newElevation = outerPolygon[0].Z;

                TinSurface tinSurface = base.Entity as TinSurface;
                insidePoints = baseSurface.GetPointsInsidePolygon(innerPolygon, true);

                IEnumerable<Point3dCollection> drapedPointGroups = baseSurface.Drape(outerPolygon);
                outerPoints = new Point3dCollection();
                foreach (Point3dCollection drapedPoints in drapedPointGroups)
                {
                    foreach (Point3d point in drapedPoints)
                    {
                        outerPoints.Add(point);
                    }
                }

                drapedPointGroups = baseSurface.Drape(innerPolygon);
                //Point3dCollection innerPoints = new Point3dCollection();
                foreach (Point3dCollection drapedPoints in drapedPointGroups)
                {
                    foreach (Point3d point in drapedPoints)
                    {
                        insidePoints.Add(point);
                    }
                }

                tinSurface.AddPoints(insidePoints);
                tinSurface.AddPoints(outerPoints);
                tinSurface.Style = TinSurfaceStyle.Triangles;
                tinSurface.ColorIndex = 1;

                TinSurfaceConstraint constraint = new TinSurfaceBoundary(TinBoundaryType.Hide);
                constraint.SetData(465869, outerPoints);
                tinSurfaceBase.UpgradeOpen();
                tinSurfaceBase.AddConstraint(constraint, false);
                tinSurfaceBase.DowngradeOpen();
            }

            public TinSurface TinSurface
            {
                get
                {
                    return base.Entity as TinSurface;
                }
            }

            static internal _AcDb.Entity InitEntity()
            {
                TinSurface tinSurface = new TinSurface();
                return tinSurface;
            }

            private bool CursorHasMoved()
            {
                return !(this.currentCursorPosition == this.previousCursorPosition);
            }

            public void Dispose()
            {
                this.Dispose(true);
                GC.SuppressFinalize(this);
            }

            private void Dispose(bool disposing)
            {
                if (!this.disposed)
                {
                    if (disposing)
                    {
                        this.Entity.Dispose();
                    }
                    this.disposed = true;
                }
            }

            protected override bool Update()
            {
                // Update jigging TIN surface with new elevations
                TinSurface tinSurface = base.Entity as TinSurface;
                List<double> newZValues = new List<double>();
                foreach (Point3d point in insidePoints)
                    newZValues.Add(newElevation);
                tinSurface.ChangePointsElevations(insidePoints, newZValues);
                tinSurface.UpdateObjectData();

                return true;
            }

            protected override SamplerStatus Sampler(JigPrompts prompts)
            {
                ViewTableRecord view = editor.GetCurrentView();
                Matrix3d worldToEye = Utils.worldToEye(view);

                PromptPointResult userFeedback = prompts.AcquirePoint("\nMove mouse to change elevation:");
                this.currentCursorPosition = userFeedback.Value;

                if (this.CursorHasMoved())
                {
                    TinSurface tinSurface = base.Entity as TinSurface;

                    //Update elevation based on change of mouse cursor
                    if (previousCursorPosition != Point3d.Origin)
                    {
                        Vector3d v = currentCursorPosition - previousCursorPosition;
                        v = v.TransformBy(worldToEye);
                        newElevation += v.Y;
                    }

                    this.previousCursorPosition = this.currentCursorPosition;
                    return SamplerStatus.OK;
                }
                return SamplerStatus.NoChange;
            }

            public Point3d StartJig()
            {
                if (this.editor.Drag(this).Status != PromptStatus.OK)
                {
                    throw new System.Exception();
                }
                return this.currentCursorPosition;
            }
        }

        public static void do_TINJig()
        {
            const double SURFACE_SIZE = 200;
            const UInt32 NUMBER_OF_POINTS = 1000;
            const double SURFACE_ELEVATION = 300;
            const double ELEVATION_VAR = 3;

            //Create TIN surface
            TinSurface tinSurfaceBase = new TinSurface(new Point3d(-SURFACE_SIZE, -SURFACE_SIZE, 0), new Point3d(SURFACE_SIZE, SURFACE_SIZE, 0), NUMBER_OF_POINTS);
            Point3dCollection points = new Point3dCollection();
            Random random = new Random();
            for (int i = 0; i < NUMBER_OF_POINTS; i++)
            {
                points.Add(new Point3d(random.NextDouble() * SURFACE_SIZE * 2 - SURFACE_SIZE,
                                        random.NextDouble() * SURFACE_SIZE * 2 - SURFACE_SIZE,
                                        random.NextDouble() * ELEVATION_VAR + SURFACE_ELEVATION));
            }
            tinSurfaceBase.AddPoints(points);

            ObjectId surfaceId = Utils.AddToModelSpace(tinSurfaceBase)[0];

            //Create outer polygon
            const double OUTER_POLY_SIZE = 50.0;
            const double POLY_HEIGHT = 330;
            Point3dCollection outerVertices = new Point3dCollection();
            outerVertices.Add(new Point3d(-OUTER_POLY_SIZE, -OUTER_POLY_SIZE, POLY_HEIGHT));
            outerVertices.Add(new Point3d(OUTER_POLY_SIZE, -OUTER_POLY_SIZE, POLY_HEIGHT));
            outerVertices.Add(new Point3d(OUTER_POLY_SIZE, OUTER_POLY_SIZE, POLY_HEIGHT));
            outerVertices.Add(new Point3d(-OUTER_POLY_SIZE, OUTER_POLY_SIZE, POLY_HEIGHT));
            outerVertices.Add(new Point3d(-OUTER_POLY_SIZE, -OUTER_POLY_SIZE, POLY_HEIGHT));

            //Create inner polygon
            const double INNER_POLY_SIZE = 40.0;
            Point3dCollection innerVertices = new Point3dCollection();
            innerVertices.Add(new Point3d(-INNER_POLY_SIZE, -INNER_POLY_SIZE, POLY_HEIGHT));
            innerVertices.Add(new Point3d(INNER_POLY_SIZE, -INNER_POLY_SIZE, POLY_HEIGHT));
            innerVertices.Add(new Point3d(INNER_POLY_SIZE, INNER_POLY_SIZE, POLY_HEIGHT));
            innerVertices.Add(new Point3d(-INNER_POLY_SIZE, INNER_POLY_SIZE, POLY_HEIGHT));
            innerVertices.Add(new Point3d(-INNER_POLY_SIZE, -INNER_POLY_SIZE, POLY_HEIGHT));

            // get current view
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            ViewTableRecord view = editor.GetCurrentView();

            // set different view direction in order to get better view of the jigging surface
            view.ViewDirection = new Vector3d(0.6, -0.6, 0.3);
            editor.SetCurrentView(view);

            //calculate world to eye matrix
            Matrix3d worldToEye = Utils.worldToEye(view);

            // perform zoom extents to get focus on the created surface
            Database db = editor.Document.Database;
            db.UpdateExt(false);
            Extents3d ext = (short)Application.GetSystemVariable("cvport") == 1 ?
                new Extents3d(db.Pextmin, db.Pextmax) :
                new Extents3d(db.Extmin, db.Extmax);

            ext.TransformBy(worldToEye);

            view.Width = ext.MaxPoint.X - ext.MinPoint.X;
            view.Height = ext.MaxPoint.Y - ext.MinPoint.Y;
            view.CenterPoint = new Point2d(
                (ext.MaxPoint.X + ext.MinPoint.X) / 2.0,
                (ext.MaxPoint.Y + ext.MinPoint.Y) / 2.0);

            editor.SetCurrentView(view);

            // create and start JIG
            _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
            _AcDb.TransactionManager manager = database.TransactionManager;
            using (_AcDb.Transaction action = manager.StartTransaction())
            {
                TinSurface baseTinSurface = action.GetObject(surfaceId, _AcDb.OpenMode.ForRead) as TinSurface;
                if (baseTinSurface != null)
                {
                    using (MySurfaceJig jig = new MySurfaceJig(baseTinSurface, outerVertices, innerVertices))
                    {
                        jig.StartJig();

                        // Merge jigged surface into the base surface
                        TinSurface jigSurface = jig.TinSurface;
                        baseTinSurface.UpgradeOpen();
                        baseTinSurface.Merge(jigSurface);
                    }
                }
                action.Commit();
            }
        }
    }
}
