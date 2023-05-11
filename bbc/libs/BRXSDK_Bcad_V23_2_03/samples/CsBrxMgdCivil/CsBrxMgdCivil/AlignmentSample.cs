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
using Teigha.Colors;

// Bricsys
using Bricscad.ApplicationServices;
using Bricscad.Runtime;
using Bricscad.EditorInput;
using Bricscad.Civil;

// alias
using _AcRx = Teigha.Runtime;
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;

namespace CsBrxMgdCivil
{
    public class AlignmentSample
    {
        public static void do_AlignmentReport()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select Horizontal Alignment: ");
            peo.SetRejectMessage("Not a Horizontal Alignment!");
            peo.AddAllowedClass(typeof(AlignmentHorizontal), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    AlignmentHorizontal alignment = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForRead) as AlignmentHorizontal;
                    if (alignment != null)
                    {
                        // Create and set up alignment table
                        Table elementsTable = new Table();
                        elementsTable.SetDatabaseDefaults(database);

                        UnitsValue units = database.Insunits;
                        double scale = UnitsConverter.GetConversionFactor(UnitsValue.Meters, units);

                        double titleTextHeight = 1 * scale;
                        double headerTextHeight = 0.8 * scale;
                        double dataRowHeight = 2 * scale;
                        double dataTextHeight = 0.6 * scale;
                        double columnWidth = 10 * scale;

                        elementsTable.SetSize(3, 7);
                        elementsTable.SetRowHeight(2.5 * scale);
                        elementsTable.SetColumnWidth(columnWidth);
                        elementsTable.Columns[5].Width = columnWidth * 2;
                        elementsTable.Columns[6].Width = columnWidth * 2;

                        elementsTable.Rows[0].BackgroundColor = Teigha.Colors.Color.FromRgb(0, 115, 0);
                        elementsTable.Rows[0].ContentColor = Teigha.Colors.Color.FromRgb(222, 222, 0);
                        elementsTable.Rows[0].TextHeight = titleTextHeight;

                        elementsTable.Rows[1].BackgroundColor = Teigha.Colors.Color.FromRgb(0, 115, 0);
                        elementsTable.Rows[1].ContentColor = Teigha.Colors.Color.FromRgb(222, 222, 0);
                        elementsTable.Rows[1].TextHeight = titleTextHeight;

                        string alignmentName = alignment.Name;
                        if (alignmentName == null)
                            alignmentName = "Unnamed";
                        elementsTable.SetTextString(0, 0, "Alignment: " + alignmentName);
                        CellRange range = CellRange.Create(elementsTable, 0, 0, 0, 6);
                        elementsTable.MergeCells(range);

                        //Get alignment starting station
                        double StartStation = alignment.StationEquations.StartingStation;

                        //Get alignment end station
                        double RawEndStation = alignment.StationEquations.GetRawStationAtLength(alignment.Length);
                        double EndStation = alignment.StationEquations.GetStationAt(RawEndStation);
                        
                        elementsTable.SetTextString(1, 0, String.Format("Starting station: {0:0.000}, End station: {1:0.000}", StartStation, EndStation));
                        range = CellRange.Create(elementsTable, 1, 0, 1, 6);
                        elementsTable.MergeCells(range);

                        elementsTable.Rows[2].BackgroundColor = Teigha.Colors.Color.FromRgb(100, 0, 0);
                        elementsTable.Rows[2].ContentColor = Teigha.Colors.Color.FromRgb(222, 222, 0);
                        elementsTable.Rows[2].Alignment = CellAlignment.MiddleCenter;
                        elementsTable.Rows[2].TextHeight = headerTextHeight;

                        elementsTable.SetTextString(2, 0, "Element");
                        elementsTable.SetTextString(2, 1, "Length");
                        elementsTable.SetTextString(2, 2, "Radius");
                        elementsTable.SetTextString(2, 3, "A Value");
                        elementsTable.SetTextString(2, 4, "Direction");
                        elementsTable.SetTextString(2, 5, "Start Point");
                        elementsTable.SetTextString(2, 6, "End Point");

                        Int32 nLines = 0;
                        Int32 nArcs = 0;
                        Int32 nSpirals = 0;

                        // Fill table with alignment elements data
                        AlignmentHorizontalElement element = alignment.get_HAElement(alignment.FirstHAElementId);
                        while (element != null)
                        {
                            if (element.ElementType == HAElementType.Line)
                            {
                                nLines++;
                                AlignmentHorizontalLine lineElement = element as AlignmentHorizontalLine;
                                elementsTable.InsertRows(elementsTable.Rows.Count, dataRowHeight, 1);
                                elementsTable.Rows[elementsTable.Rows.Count - 1].Alignment = CellAlignment.MiddleCenter;
                                elementsTable.Rows[elementsTable.Rows.Count - 1].TextHeight = dataTextHeight;
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 0, String.Format("L{0}", nLines));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 1, _AcRx.Converter.DistanceToString(lineElement.Length));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 4, _AcRx.Converter.AngleToString((lineElement.EndPoint - lineElement.StartPoint).Angle, _AcRx.AngularUnitFormat.Surveyor, 2));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 5, String.Format("({0:0.000},{1: 0.000})", lineElement.StartPoint.X, lineElement.StartPoint.Y));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 6, String.Format("({0:0.000},{1: 0.000})", lineElement.EndPoint.X, lineElement.EndPoint.Y));

                            }
                            else if (element.ElementType == HAElementType.Arc)
                            {
                                nArcs++;
                                AlignmentHorizontalArc arcElement = element as AlignmentHorizontalArc;
                                elementsTable.InsertRows(elementsTable.Rows.Count, dataRowHeight, 1);
                                elementsTable.Rows[elementsTable.Rows.Count - 1].Alignment = CellAlignment.MiddleCenter;
                                elementsTable.Rows[elementsTable.Rows.Count - 1].TextHeight = dataTextHeight;
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 0, String.Format("C{0}", nArcs));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 1, _AcRx.Converter.DistanceToString(arcElement.Length));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 2, _AcRx.Converter.DistanceToString(arcElement.Radius));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 4, _AcRx.Converter.AngleToString((arcElement.EndPoint - arcElement.StartPoint).Angle, _AcRx.AngularUnitFormat.Surveyor, 2));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 5, String.Format("({0:0.000},{1: 0.000})", arcElement.StartPoint.X, arcElement.StartPoint.Y));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 6, String.Format("({0:0.000},{1: 0.000})", arcElement.EndPoint.X, arcElement.EndPoint.Y));
                            }
                            else if (element.ElementType == HAElementType.SpiralCurveSpiral)
                            {
                                AlignmentHorizontalSCS scsElement = element as AlignmentHorizontalSCS;
                                elementsTable.InsertRows(elementsTable.Rows.Count, dataRowHeight, 3);

                                nSpirals++;
                                elementsTable.Rows[elementsTable.Rows.Count - 3].Alignment = CellAlignment.MiddleCenter;
                                elementsTable.Rows[elementsTable.Rows.Count - 3].TextHeight = dataTextHeight;
                                elementsTable.SetTextString(elementsTable.Rows.Count - 3, 0, String.Format("S{0}", nSpirals));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 3, 1, _AcRx.Converter.DistanceToString(scsElement.SpiralIn.Length));
                                string radiusStr = Math.Abs(scsElement.SpiralIn.RadiusIn) > 0 ? _AcRx.Converter.DistanceToString(Math.Abs(scsElement.SpiralIn.RadiusIn)) : "Infinity";
                                elementsTable.SetTextString(elementsTable.Rows.Count - 3, 2, radiusStr);
                                elementsTable.SetTextString(elementsTable.Rows.Count - 3, 3, String.Format("{0:0.00}", scsElement.SpiralIn.ParameterA));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 3, 4, _AcRx.Converter.AngleToString(scsElement.SpiralIn.StartDirection, _AcRx.AngularUnitFormat.Surveyor, 2));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 3, 5, String.Format("({0:0.000},{1: 0.000})", scsElement.SpiralIn.StartPoint.X, scsElement.SpiralIn.StartPoint.Y));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 3, 6, String.Format("({0:0.000},{1: 0.000})", scsElement.SpiralIn.EndPoint.X, scsElement.SpiralIn.EndPoint.Y));

                                nArcs++;
                                elementsTable.Rows[elementsTable.Rows.Count - 2].Alignment = CellAlignment.MiddleCenter;
                                elementsTable.Rows[elementsTable.Rows.Count - 2].TextHeight = dataTextHeight;
                                elementsTable.SetTextString(elementsTable.Rows.Count - 2, 0, String.Format("C{0}", nArcs));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 2, 1, _AcRx.Converter.DistanceToString(scsElement.Arc.Length));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 2, 2, _AcRx.Converter.DistanceToString(scsElement.Arc.Radius));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 2, 4, _AcRx.Converter.AngleToString((scsElement.Arc.EndPoint - scsElement.Arc.StartPoint).Angle, _AcRx.AngularUnitFormat.Surveyor, 2));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 2, 5, String.Format("({0:0.000},{1: 0.000})", scsElement.Arc.StartPoint.X, scsElement.Arc.StartPoint.Y));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 2, 6, String.Format("({0:0.000},{1: 0.000})", scsElement.Arc.EndPoint.X, scsElement.Arc.EndPoint.Y));

                                nSpirals++;
                                elementsTable.Rows[elementsTable.Rows.Count - 1].Alignment = CellAlignment.MiddleCenter;
                                elementsTable.Rows[elementsTable.Rows.Count - 1].TextHeight = dataTextHeight;
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 0, String.Format("S{0}", nSpirals));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 1, _AcRx.Converter.DistanceToString(scsElement.SpiralOut.Length));
                                radiusStr = Math.Abs(scsElement.SpiralOut.RadiusIn) > 0 ? _AcRx.Converter.DistanceToString(Math.Abs(scsElement.SpiralOut.RadiusIn)) : "Infinity";
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 2, radiusStr);
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 3, String.Format("{0:0.00}", scsElement.SpiralOut.ParameterA));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 4, _AcRx.Converter.AngleToString(scsElement.SpiralOut.StartDirection, _AcRx.AngularUnitFormat.Surveyor, 2));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 5, String.Format("({0:0.000},{1: 0.000})", scsElement.SpiralOut.StartPoint.X, scsElement.SpiralOut.StartPoint.Y));
                                elementsTable.SetTextString(elementsTable.Rows.Count - 1, 6, String.Format("({0:0.000},{1: 0.000})", scsElement.SpiralOut.EndPoint.X, scsElement.SpiralOut.EndPoint.Y));

                            }
                            element = alignment.get_HAElement(element.NextElementId);
                        }

                        for (int i = 0; i < elementsTable.Rows.Count; i++)
                        {
                            for (int j = 0; j < elementsTable.Columns.Count; j++)
                            {
                                elementsTable.SetMargin(i, j, CellMargins.Top, dataRowHeight / 5.0);
                                elementsTable.SetMargin(i, j, CellMargins.Bottom, dataRowHeight / 5.0);
                                elementsTable.SetMargin(i, j, CellMargins.Left, columnWidth / 5.0);
                                elementsTable.SetMargin(i, j, CellMargins.Right, columnWidth / 5.0);
                            }
                        }

                        elementsTable.GenerateLayout();

                        _AcEd.PromptPointOptions ppo = new _AcEd.PromptPointOptions("Pick insertion point:");
                        PromptPointResult ppr = editor.GetPoint(ppo);
                        if (ppr.Status == _AcEd.PromptStatus.OK)
                        {
                            Point3d insertionPoint = ppr.Value;
                            elementsTable.Position = insertionPoint;
                            ObjectIdCollection ids = Utils.AddToModelSpace(elementsTable);
                        }
                    }

                    action.Commit();
                }
            }
        }

        public static void do_CreateAlignment()
        {
            //First create horizontal alignment
            AlignmentHorizontal HAlignment = new AlignmentHorizontal();
            HAlignment.SetDatabaseDefaults();

            ulong lineId1 = HAlignment.AddLineFixed(new Point2d(0.0, 0.0), new Point2d(5.0, 0.0));
            ulong lineId2 = HAlignment.AddLineFixed(new Point2d(10.0, 10.0), new Point2d(10.0, 15.0));
            ulong autoSCSId = HAlignment.AddSCSAuto(lineId1, lineId2);

            ObjectId HAlignmentId = Utils.AddToModelSpace(HAlignment)[0];

            //Now we can create vertical alignment that uses previously created hAlignment
            AlignmentVertical VAlignment = new AlignmentVertical();
            VAlignment.SetDatabaseDefaults();
            ulong tangentId1 = VAlignment.AddTangentFixed(new Point2d(0.0, 0.0), new Point2d(4.0, 4.0));
            ulong tangentId2 = VAlignment.AddTangentFixed(new Point2d(10.0, 8.0), new Point2d(50.0, 4.0));
            ulong autoParabola1 = VAlignment.AddParabolaAuto(tangentId1, tangentId2);
            VAlignment.BaseHorizontalAlignment = HAlignmentId;
            ObjectId VAlignmentId = Utils.AddToModelSpace(VAlignment)[0];

            //Create vertical alignment view so we can display the vAlignment
            AlignmentViewVertical VAlignmentView = new AlignmentViewVertical();
            VAlignmentView.SetDatabaseDefaults();
            VAlignmentView.BaseHorizontalAlignment = HAlignmentId;
            VAlignmentView.Origin = new Point2d(0.0, -15.0);
            ObjectId VAlignmentViewId = Utils.AddToModelSpace(VAlignmentView)[0];

            //Create 3d alignment from horizonal and vertical alignment
            Alignment3d A3D = new Alignment3d();
            A3D.SetDatabaseDefaults();
            A3D.BaseHorizontalAlignment = HAlignmentId;
            A3D.VerticalAlignment = VAlignmentId;
            ObjectId A3DId = Utils.AddToModelSpace(A3D)[0];

            //Change some alignment visuals
            HAlignment.LineElementColor = new EntityColor(ColorMethod.ByAci,256);
            HAlignment.CurveElementColor = new EntityColor(ColorMethod.ByAci, 2);
            HAlignment.SpiralElementColor = new EntityColor(ColorMethod.ByAci, 3);
            HAlignment.TangentExtensionColor = new EntityColor(ColorMethod.ByAci, 4);
            HAlignment.Style = HAVisualStyle.Elements | HAVisualStyle.Tangents | HAVisualStyle.Extensions;

            VAlignment.LineElementColor = new EntityColor(ColorMethod.ByAci, 256);
            VAlignment.CurveElementColor = new EntityColor(ColorMethod.ByAci, 5);
            VAlignment.TangentExtensionColor = new EntityColor(ColorMethod.ByAci, 6);
            VAlignment.Style = VAVisualStyle.Elements | VAVisualStyle.Tangents;

            //Add another vertical alignment to the same horizontal alignment and the same view.
            AlignmentVertical VAlignment2 = new AlignmentVertical();
            VAlignment2.BaseHorizontalAlignment = HAlignmentId;

            ulong TangentId1 = VAlignment2.AddTangentFixed(new Point2d(5.0, 5.0), new Point2d(9.0, 6.0));
            ulong TangentId2 = VAlignment2.AddTangentFixed(new Point2d(9.0, 6.0), new Point2d( 15.0, 5.0 ));
            ObjectId VAlignmentID2 = Utils.AddToModelSpace(VAlignment2)[0];
            VAlignmentView.AddGraph(VAlignmentID2);

            //Set name and description for horizontal alignment
            HAlignment.Name = "Sample name";
            HAlignment.Description = "This is sample description";

            //Set starting station for horizontal alignment
            StationEquationCollection stationEquations = HAlignment.StationEquations;
            double RefStartLength = stationEquations.RefStartingLength;
            double NewStartingStation = 10.5;
            stationEquations.RefRawStartingStation = NewStartingStation + RefStartLength;
            HAlignment.StationEquations = stationEquations;
        }

        public static void do_CreateAlignmentFromPolyline()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select polyline: ");
            peo.SetRejectMessage("Not a polyline!");
            peo.AddAllowedClass(typeof(Polyline), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    Polyline Poly = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForRead) as Polyline;
                    if (Poly != null)
                    {
                        AlignmentHorizontal HAlignment = new AlignmentHorizontal();
                        HAlignment.SetDatabaseDefaults();
                        if (Poly.NumberOfVertices < 2)
                            return;

                        for (int i = 0; i < Poly.NumberOfVertices - 1; i++)
                        {
                            double bulge = Poly.GetBulgeAt(i);
                            if (bulge.Equals(0.0))
                            {
                                LineSegment2d LineSeg = Poly.GetLineSegment2dAt(i);
                                ulong ElementId = HAlignment.AddLineFixed(LineSeg.StartPoint, LineSeg.EndPoint);
                            }
                            else
                            {
                                CircularArc2d ArcSeg = Poly.GetArcSegment2dAt(i);
                                Point2d startPt = ArcSeg.StartPoint;
                                Point2d endPt = ArcSeg.EndPoint;
                                double startParam = ArcSeg.GetParameterOf(startPt);
                                double endParam = ArcSeg.GetParameterOf(endPt);
                                Point2d midPt = ArcSeg.EvaluatePoint((startParam + endParam) / 2.0);
                                ulong ElementId = HAlignment.AddArcFixed(startPt, midPt, endPt);
                            }
                        }
                        action.Commit();

                        if (HAlignment.HAElementCount == 0)
                            return;
                        else
                        {
                            ObjectId HAlignmentId = Utils.AddToModelSpace(HAlignment)[0];
                        }
                    }
                }
            }
        }

        public static void do_ReplaceAlignmentElement()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptSelectionOptions pso = new _AcEd.PromptSelectionOptions();
            pso.MessageForAdding = "Select horizontal alignment:";
            pso.SingleOnly = true;
            pso.ForceSubSelections = true;
            _AcEd.PromptSelectionResult psr = editor.GetSelection(pso);
            if (psr.Status == _AcEd.PromptStatus.OK)
            {
                SelectionSet sset = psr.Value;
                SelectedObject selected = sset[0];

                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    AlignmentHorizontal alignment = action.GetObject(selected.ObjectId, _AcDb.OpenMode.ForWrite) as AlignmentHorizontal;
                    if (alignment != null)
                    {
                        
                        SelectedSubObject[] selectedSubs = selected.GetSubentities();
                        IntPtr gsMarker = selectedSubs[0].GraphicsSystemMarkerPtr;
                        ulong elementId = alignment.GetElementId(gsMarker);
                        AlignmentHorizontalElement element = alignment.get_HAElement(elementId);
                        if ((element == null) || (element.ElementType != HAElementType.SpiralCurveSpiral))
                            return;

                        AlignmentHorizontalSCS scs = (AlignmentHorizontalSCS)element;
                        if (scs.TangencyConstraint == HATangencyConstraint.Fixed)
                            return;

                        ulong prevId = scs.PreviousElementId;
                        ulong nextId = scs.NextElementId;
                        if (prevId > 0 && nextId > 0)
                        {
                            alignment.DeleteHAElement(elementId);
                            //Element must be added after previous was removed
                            alignment.AddArcAuto(prevId, nextId);
                        }
                    }
                    action.Commit();
                }
            }
        }

        public static void CreateXMarkAtHorizontalAlignment(ref AlignmentHorizontal alignment, double station)
        {
            Point2d point = alignment.GetPointAtStation(station);
            if (point == null)
                return;

            DBPoint dbPoint = new DBPoint();
            dbPoint.SetDatabaseDefaults();
            dbPoint.Position = new Point3d(point.X, point.Y, 0.0);
            ObjectId pointId = Utils.AddToModelSpace(dbPoint)[0];
        }

        public static void CreateXMarkAtAlignmentViews(ref AlignmentHorizontal alignment, Point2d VAlignmentPoint)
        {
            for (uint i = 0; i < alignment.VerticalAlignmentViewCount; i++)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    AlignmentViewVertical vaView = action.GetObject(alignment.get_VerticalAlignmentView(i), _AcDb.OpenMode.ForRead) as AlignmentViewVertical;
                    if (vaView != null)
                    {
                        Point2d wcPoint = vaView.ConvertViewToWCS(VAlignmentPoint);
                        action.Commit();
                        DBPoint dbPoint = new DBPoint();
                        dbPoint.SetDatabaseDefaults();
                        dbPoint.Position = new Point3d(wcPoint.X, wcPoint.Y, 0.0);
                        ObjectId pointId = Utils.AddToModelSpace(dbPoint)[0];
                    }
                }
            }
        }

        public static void CreateXMarkAt3dAlignments(ref AlignmentHorizontal alignment, double station)
        {
            for (uint i = 0; i < alignment.Alignment3dCount; i++)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    Alignment3d a3d = action.GetObject(alignment.get_Alignment3d(i), _AcDb.OpenMode.ForRead) as Alignment3d;
                    if (a3d != null)
                    {
                        Point3d point = a3d.GetPointAtParameter(station);
                        action.Commit();
                        DBPoint dbPoint = new DBPoint();
                        dbPoint.SetDatabaseDefaults();
                        dbPoint.Position = point;
                        ObjectId pointId = Utils.AddToModelSpace(dbPoint)[0];
                    }
                }
            }
        }

        public static void do_StationsAndParamRelations()
        {
            const int SPLIT_COUNT = 4;
            
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select vertical alignment: ");
            peo.SetRejectMessage("Not a vertical alignment!");
            peo.AddAllowedClass(typeof(AlignmentVertical), true);
            _AcEd.PromptEntityResult per = editor.GetEntity(peo);
            if (per.Status == _AcEd.PromptStatus.OK)
            {
                _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
                _AcDb.TransactionManager manager = database.TransactionManager;
                using (_AcDb.Transaction action = manager.StartTransaction())
                {
                    AlignmentVertical verticalAlignment = action.GetObject(per.ObjectId, _AcDb.OpenMode.ForRead) as AlignmentVertical;
                    if (verticalAlignment == null)
                        return;

                    AlignmentHorizontal horizontalAlignment = action.GetObject(verticalAlignment.BaseHorizontalAlignment, _AcDb.OpenMode.ForRead) as AlignmentHorizontal;
                    if (horizontalAlignment == null)
                        return;

                    //Make points more visible for this sample
                    verticalAlignment.Database.Pdmode = 3;

                    double verticalStartStation = verticalAlignment.StartParam;
                    double verticalEndStation = verticalAlignment.EndParam;
                    double startStation = Math.Max(0.0, verticalStartStation);
                    double endStation = Math.Min(horizontalAlignment.Length, verticalEndStation);
                    double markCreationDistance = (endStation - startStation) / SPLIT_COUNT;
                    for (int i = 0; i <= SPLIT_COUNT; i++)
                    {
                        double currentStation = startStation + i * markCreationDistance;
                        double distance3d = verticalAlignment.GetDistanceAtParameter(currentStation);
                        Point3d point = verticalAlignment.GetPointAtDist(distance3d);
                        CreateXMarkAtAlignmentViews(ref horizontalAlignment, new Point2d(point.X, point.Y));
                        CreateXMarkAtHorizontalAlignment(ref horizontalAlignment, currentStation);
                        CreateXMarkAt3dAlignments(ref horizontalAlignment, currentStation);
                    }
                    action.Commit();
                }
            }
        }

        public static void CreateSimpleHAlignment(ref ObjectId alignmentId)
        {
            AlignmentHorizontal HAlignment = new AlignmentHorizontal();
            HAlignment.SetDatabaseDefaults();

            ulong lineId1 = HAlignment.AddLineFixed(new Point2d(0.0, 0.0), new Point2d(5.0, 0.0));
            ulong lineId2 = HAlignment.AddLineFixed(new Point2d(10.0, 10.0), new Point2d(10.0, 15.0));
            ulong autoSCSId = HAlignment.AddSCSAuto(lineId1, lineId2);

            alignmentId = Utils.AddToModelSpace(HAlignment)[0];
        }

        public static void do_StationEquations()
        {
            ObjectId alignmentId = new ObjectId();
            CreateSimpleHAlignment(ref alignmentId);

            _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
            _AcDb.TransactionManager manager = database.TransactionManager;
            
            using (_AcDb.Transaction action = manager.StartTransaction())
            {
                AlignmentHorizontal alignment = action.GetObject(alignmentId, _AcDb.OpenMode.ForWrite) as AlignmentHorizontal;
                if (alignment != null)
                {
                    StationEquationCollection stationEquations = new StationEquationCollection();
                    StationEquation stationEquation = new StationEquation();

                    stationEquation.RawStation = 25;
                    stationEquation.StationForward = 15;

                    //new station equation is added at raw station 25
                    stationEquations.AddEquation(stationEquation);

                    alignment.StationEquations = stationEquations;
                }
                action.Commit();
            }
            using (_AcDb.Transaction action = manager.StartTransaction())
            {
                AlignmentHorizontal alignment = action.GetObject(alignmentId, _AcDb.OpenMode.ForWrite) as AlignmentHorizontal;
                if (alignment != null)
                {
                    StationEquationCollection stationEquations = alignment.StationEquations;
                    StationEquation stationEquation = new StationEquation();

                    stationEquation.RawStation = 25;
                    stationEquation.StationForward = 20;

                    //because there is already station equation with raw station 25,
                    //it will get replaced with this new one
                    stationEquations.AddEquation(stationEquation);

                    alignment.StationEquations = stationEquations;
                }
                action.Commit();
            }
            using (_AcDb.Transaction action = manager.StartTransaction())
            {
                AlignmentHorizontal alignment = action.GetObject(alignmentId, _AcDb.OpenMode.ForWrite) as AlignmentHorizontal;
                if (alignment != null)
                {
                    StationEquationCollection stationEquations = alignment.StationEquations;
                    StationEquation stationEquation = new StationEquation();

                    stationEquation.RawStation = 35;
                    stationEquation.StationForward = 25;

                    //new station equation is added at raw station 35
                    stationEquations.AddEquation(stationEquation);

                    alignment.StationEquations = stationEquations;
                }
                action.Commit();
            }
            using (_AcDb.Transaction action = manager.StartTransaction())
            {
                Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
                AlignmentHorizontal alignment = action.GetObject(alignmentId, _AcDb.OpenMode.ForRead) as AlignmentHorizontal;
                if (alignment != null)
                {
                    StationEquationCollection stationEquations = alignment.StationEquations;
                    for (ulong i = 0; i < stationEquations.Count; i++) 
                    { 
                        StationEquation se = stationEquations.get_Equation(i);
                        editor.WriteMessage("\n" + se.RawStation.ToString() + "\n" + se.StationForward.ToString() + "\n" + se.EquationType.ToString()); 
                    }
                }
                action.Commit();
            }
        }

        public class MyAlignmentJig : EntityJig, IDisposable
        {
            private Point2d currentCursorPosition;
            private bool disposed;
            private Editor editor;
            private Point2d previousCursorPosition;
            private ulong lineId1;
            private ulong lineId2;

            public MyAlignmentJig(ObjectId surfaceId)
                : base(InitEntity())
            {
                this.editor = Application.DocumentManager.MdiActiveDocument.Editor;
                this.previousCursorPosition = Point2d.Origin;
                lineId1 = AlignmentHorizontal.AddLineFixed(new Point2d(-8.0, -8.0), currentCursorPosition);
                lineId2 = AlignmentHorizontal.AddLineFixed(currentCursorPosition, new Point2d(0.0, 8.0));
                ulong scsId = AlignmentHorizontal.AddSCSAuto(lineId1, lineId2);
                //Create vertical alignment that is 'draped' to the given surface.
                AlignmentVertical verticalAlignment = new AlignmentVertical();
                ObjectId hAlignmentId = Utils.AddToModelSpace(AlignmentHorizontal)[0];
                ObjectId vAlignmentId = Utils.AddToModelSpace(verticalAlignment)[0];
                verticalAlignment.BaseHorizontalAlignment = hAlignmentId;
                verticalAlignment.BaseSurface = surfaceId;
                Alignment3d a3d = new Alignment3d();
                ObjectId a3dId = Utils.AddToModelSpace(a3d)[0];
                a3d.BaseHorizontalAlignment = hAlignmentId;
                a3d.VerticalAlignment = vAlignmentId;
            }

            public AlignmentHorizontal AlignmentHorizontal
            {
                get
                {
                    return base.Entity as AlignmentHorizontal;
                }
            }

            static internal _AcDb.Entity InitEntity()
            {
                AlignmentHorizontal horizontalAlignment = new AlignmentHorizontal();
                return horizontalAlignment;
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
                AlignmentHorizontalElement element1 = AlignmentHorizontal.get_HAElement(lineId1);
                AlignmentHorizontalElement element2 = AlignmentHorizontal.get_HAElement(lineId2);
                AlignmentHorizontalLine line1 = (AlignmentHorizontalLine)element1;
                AlignmentHorizontalLine line2 = (AlignmentHorizontalLine)element2;
                if ((line1 != null) && (line2 != null))
                {
                    line1.ThroughPoint2 = currentCursorPosition;
                    line2.ThroughPoint1 = currentCursorPosition;
                    try
                    {
                        AlignmentHorizontal.Update(true);
                    }
                    catch
                    {
                    }
                    return true;
                }
                return false;
            }

            protected override SamplerStatus Sampler(JigPrompts prompts)
            {
                PromptPointResult userFeedback = prompts.AcquirePoint("\nMove mouse to change alignment:");
                this.currentCursorPosition = new Point2d(userFeedback.Value.X, userFeedback.Value.Y);
                
                if (this.CursorHasMoved())
                {
                    this.previousCursorPosition = this.currentCursorPosition;
                    return SamplerStatus.OK;
                }
                return SamplerStatus.NoChange;
            }

            public Point2d StartJig()
            {
                if (this.editor.Drag(this).Status != PromptStatus.OK)
                {
                    throw new System.Exception();
                }
                return this.currentCursorPosition;
            }
        }

        private static void SetupForAlignmentJig(ref ObjectId surfaceId)
        {
            Point3dCollection points = new Point3dCollection();

            points.Add(new Point3d(-10, -10, 0));
            points.Add(new Point3d(10, -10, 0));
            points.Add(new Point3d(10, 10, 0));
            points.Add(new Point3d(-10, 10, 0));

            points.Add(new Point3d(-7, -7, 0.5));
            points.Add(new Point3d(7, -7, 0.5));
            points.Add(new Point3d(7, 7, 0.5));
            points.Add(new Point3d(-7, 7, 0.5));

            points.Add(new Point3d(-5, -5, 0.5));
            points.Add(new Point3d(5, -5, 0.5));
            points.Add(new Point3d(5, 5, 0.5));
            points.Add(new Point3d(-5, 5, 0.5));

            points.Add(new Point3d(-2, -2, -0.5));
            points.Add(new Point3d(2, -2, -0.5));
            points.Add(new Point3d(2, 2, -0.5));
            points.Add(new Point3d(-2, 2, -0.5));
            points.Add(new Point3d(0, 0, -0.5));

            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            TinSurface tinSurface = new TinSurface(new Point3d(-15, -15, -10),
                                    new Point3d(15, 15, 10),
                                    20);
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
            surfaceId = ids[0];
        }

        public static void do_AlignmentJig()
        {
            ObjectId surfaceId = new ObjectId();
            SetupForAlignmentJig(ref surfaceId);
            using (MyAlignmentJig jig = new MyAlignmentJig(surfaceId))
            {
                jig.StartJig();
                jig.AlignmentHorizontal.UpgradeOpen();
                jig.AlignmentHorizontal.RecordGraphicsModified(true);
            }
        }
    }
}
