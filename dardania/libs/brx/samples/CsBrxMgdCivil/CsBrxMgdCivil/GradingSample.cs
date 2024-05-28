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
using Bricscad.Civil;

// alias
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;

namespace CsBrxMgdCivil
{
    class GradingSample
    {
        public static void do_GradingSlopeOffsetCreate()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;

            Polyline3d inputCurve = new Polyline3d();
            inputCurve.AppendVertex(new PolylineVertex3d(new Point3d(-5, -20, 1)));
            inputCurve.AppendVertex(new PolylineVertex3d(new Point3d(5, -20, 1)));
            inputCurve.AppendVertex(new PolylineVertex3d(new Point3d(5, 20, 1)));
            inputCurve.AppendVertex(new PolylineVertex3d(new Point3d(-5, 20, 1)));
            ObjectId inputCurveId = Utils.AddToModelSpace(inputCurve)[0];

            Grading grading = new Grading();

            // Set the (input) grading curve from which the rays are calculated based on 
            // grading type, slope angles and other grading parameters.
            GradingStatus status = grading.SetInputData(inputCurveId);

            if ((status & GradingStatus.Ok) != GradingStatus.Ok)
                editor.WriteMessage("\nSet grading curve is invalid.");


            // Create a TinSlopeOffsetRule which is defined by an angle/slope (at which
            // the rays are fired) and the offset from the grading curve.
            //    
            // Default slope format is in radians. Positive angle values specify positive
            // change in Z direction (meaning rays are fired upwards from given grading
            // curve) and opposite for negative values.
            //
            // Valid range for slope in TinSlopeOffsetRule is (-Pi/2, 0] and [0, Pi/2).
            // The offset must be  greater than 0. 
            GradingOffsetRule rule = new GradingOffsetRule(Utils.degToRad(45.0), 1);


            // The setSide function specifies on which side of the grading
            // curve, the rays should be projected. Reversing the direction of the curve
            // changes (visually) the side of the grading.
            rule.Side = GradingSide.Right;

            //Apply the created rule to the grading entity.
            grading.Rule = rule;

            ObjectId gradingId = Utils.AddToModelSpace(grading)[0];
        }


        public static void do_GradingSlopeSurfaceCreate()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;

            TinSurface tinSurface = Utils.createSampleTinSurface();
            ObjectId surfaceId = Utils.AddToModelSpace(tinSurface)[0];

            Polyline3d inputCurve = new Polyline3d();
            inputCurve.AppendVertex(new PolylineVertex3d(new Point3d(-5, -20, 1)));
            inputCurve.AppendVertex(new PolylineVertex3d(new Point3d(5, -20, 1)));
            inputCurve.AppendVertex(new PolylineVertex3d(new Point3d(5, 20, 1)));
            inputCurve.AppendVertex(new PolylineVertex3d(new Point3d(-5, 20, 1)));
            ObjectId inputCurveId = Utils.AddToModelSpace(inputCurve)[0];

            Grading grading = new Grading();

            // Set the (input) grading curve from which the rays are calculated based on 
            // grading type, slope angles and other grading parameters.
            GradingStatus status = grading.SetInputData(inputCurveId);

            if ((status & GradingStatus.Ok) != GradingStatus.Ok)
                editor.WriteMessage("\nSet grading curve is invalid.");


            // Create a TinSlopeSurfaceRule which is defined by a given target
            // surface (on which the rays are projected), cutSlope (used when
            // the given grading curve is below the target surface) and fillSlope
            // (used when the given grading curve is above the target surface).
            //
            // Given ObjectId can be any (isKindOf) CivilTinSurface or derived object
            // (that includes CivilTinGrading).
            // Default slope format is in radians.
            // Valid range for both slopes is [0, Pi/2).

            double cutSlope = Utils.degToRad(77.0);
            double fillSlope = Utils.degToRad(33.0);
            GradingSurfaceRule rule = new GradingSurfaceRule(surfaceId, cutSlope, fillSlope);
            rule.Side = GradingSide.Right;
            grading.Rule = rule;

            status = grading.Update(false);
            if ((status & GradingStatus.Ok) != GradingStatus.Ok)
                editor.WriteMessage("\nGrading calculation failed.");

            ObjectId gradingId = Utils.AddToModelSpace(grading)[0];
        }



        static void initEntitiesGradingParams(ref ObjectId straightLineId,
                                                ref ObjectId rightAngleLineId,
                                                ref ObjectId lineWithArc,
                                                ref ObjectId surfaceId)
        {
            //straightLineId
            {
                Polyline polyline = new Polyline();
                polyline.AddVertexAt(0, new Point2d(0, 0), 0, 0, 0);
                polyline.AddVertexAt(1, new Point2d(0, 10), 0, 0, 0);
                polyline.Elevation = 1.0;
                straightLineId = Utils.AddToModelSpace(polyline)[0];
            }
            //rightAngleLineId
            {
                Polyline polyline = new Polyline();
                polyline.AddVertexAt(0, new Point2d(0, 0), 0, 0, 0);
                polyline.AddVertexAt(1, new Point2d(5, 0), 0, 0, 0);
                polyline.AddVertexAt(2, new Point2d(5, 10), 0, 0, 0);
                polyline.Elevation = 1.0;
                rightAngleLineId = Utils.AddToModelSpace(polyline)[0];
            }
            //lineWithArc
            {
                Polyline polyline = new Polyline();
                polyline.AddVertexAt(0, new Point2d(0, 0), 0, 0, 0);
                polyline.AddVertexAt(1, new Point2d(0, 5), 1, 0, 0);
                polyline.AddVertexAt(2, new Point2d(0, 10), -1, 0, 0);
                polyline.AddVertexAt(3, new Point2d(0, 15), 0, 0, 0);
                polyline.Elevation = 1.0;
                lineWithArc = Utils.AddToModelSpace(polyline)[0];
            }
            //surfaceId
            {
                TinSurface tinSurface = Utils.createSampleTinSurface();
                surfaceId = Utils.AddToModelSpace(tinSurface)[0];
            }
        }

        public static void do_GradingParams()
        {
            ObjectId straightLineId = new ObjectId();
            ObjectId rightAngleLineId = new ObjectId();
            ObjectId lineWithArc = new ObjectId();
            ObjectId surfaceId = new ObjectId();
            initEntitiesGradingParams(ref straightLineId, ref rightAngleLineId, ref lineWithArc, ref surfaceId);

            Grading grading1 = new Grading();
            Grading grading2 = new Grading();
            Grading grading3 = new Grading();

            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            double segMaxLen = 2;
            _AcEd.PromptDoubleOptions promptSegMaxLen = new _AcEd.PromptDoubleOptions("Enter segMaxLen distance: ");
            _AcEd.PromptDoubleResult resultSegMaxLen = editor.GetDouble(promptSegMaxLen);
            if (resultSegMaxLen.Status == _AcEd.PromptStatus.OK)
                segMaxLen = resultSegMaxLen.Value;

            // Straight segments are split into multiple pieces to create
            // smoother surfaces. The following parameter sets the maximal
            // length of each piece (a ray is projected at each piece).
            grading1.SegmentMaxLength = segMaxLen;


            double segMaxAngle = 30.0;
            _AcEd.PromptDoubleOptions promptSegMaxAngle = new _AcEd.PromptDoubleOptions("Enter segMaxAngle (degrees): ");
            _AcEd.PromptDoubleResult resultSegMaxAngle = editor.GetDouble(promptSegMaxAngle);
            if (resultSegMaxAngle.Status == _AcEd.PromptStatus.OK)
                segMaxAngle = resultSegMaxAngle.Value;

            // When grading to the surface at an obtuse-angled vertex (e.g.
            // if you have a triangle shaped polyline and the grading is calculated
            // on the outside of the triangle, all the vertices used are
            // obtuse-angled) multiple rays are projected from the same vertex
            // at different angled to improve the surface smoothnes. 

            // SegmentMaxAngle property controls the max angle between each
            // projected ray at such vertices.
            grading2.SegmentMaxAngle = segMaxAngle;


            double midOrdinateDist = 10.0;
            _AcEd.PromptDoubleOptions promptMidOrdinateDist = new _AcEd.PromptDoubleOptions("Enter midOrdinateDist: ");
            _AcEd.PromptDoubleResult resultMidOrdinateDist = editor.GetDouble(promptMidOrdinateDist);
            if (resultMidOrdinateDist.Status == _AcEd.PromptStatus.OK)
                midOrdinateDist = resultMidOrdinateDist.Value;

            // If the entity/curve used to create the grading contains arcs,
            // then MidOrdinateDist property controls the maximal distance between the
            // actual arc and the tessellated one (used by grading entity).
            grading3.MidOrdinateDist = midOrdinateDist;


            grading1.SetInputData(straightLineId);
            grading2.SetInputData(rightAngleLineId);
            grading3.SetInputData(lineWithArc);

            double cutSlope = Math.PI / 4;
            double fillSlope = Math.PI / 4;

            GradingSurfaceRule rule = new GradingSurfaceRule(surfaceId, cutSlope, fillSlope);
            rule.Side = GradingSide.Left;
            grading1.Rule = rule;
            grading2.Rule = rule;
            grading3.Rule = rule;

            Utils.AddToModelSpace(grading1, grading2, grading3);
        }

        public static void do_GradingSetRegion()
        {
            Polyline polyline = new Polyline();
            polyline.AddVertexAt(0, new Point2d(0, 0), 0, 0, 0);
            polyline.AddVertexAt(1, new Point2d(0, 5), 1, 0, 0);
            polyline.AddVertexAt(2, new Point2d(0, 10), -1, 0, 0);
            polyline.AddVertexAt(3, new Point2d(0, 15), 0, 0, 0);
            polyline.Elevation = 1.0;
            ObjectId lineWithArcId = Utils.AddToModelSpace(polyline)[0];

            Grading grading = new Grading();

            const double slope = Math.PI / 4;
            const double offset = 1.0;
            GradingOffsetRule rule = new GradingOffsetRule(slope, offset);
            rule.Side = GradingSide.Left;
            grading.Rule = rule;

            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;

            _AcDb.Database database = _AcDb.HostApplicationServices.WorkingDatabase;
            _AcDb.TransactionManager manager = database.TransactionManager;
            using (_AcDb.Transaction action = manager.StartTransaction())
            {
                polyline = action.GetObject(lineWithArcId, _AcDb.OpenMode.ForRead) as Polyline;
                if (polyline != null)
                {
                    grading.SetInputData(polyline);

                    double startRegionParam = polyline.StartParam + (polyline.StartParam + polyline.EndParam) / 2;
                    _AcEd.PromptDoubleOptions promptStartRegion = new _AcEd.PromptDoubleOptions(String.Format("Enter startRegionParam (max: {0}): ",
                                                                                                               polyline.EndParam));
                    _AcEd.PromptDoubleResult resultStartRegion = editor.GetDouble(promptStartRegion);
                    if (resultStartRegion.Status == _AcEd.PromptStatus.OK)
                        startRegionParam = resultStartRegion.Value;

                    double endRegionParam = -1;
                    _AcEd.PromptDoubleOptions promptEndRegion = new _AcEd.PromptDoubleOptions(String.Format("Enter endRegionParam (min: {0} max: {1}): ",
                                                                                                             startRegionParam, polyline.EndParam));
                    _AcEd.PromptDoubleResult resultEndRegion = editor.GetDouble(promptEndRegion);
                    if (resultEndRegion.Status == _AcEd.PromptStatus.OK)
                        endRegionParam = resultEndRegion.Value;

                    grading.RegionStart = startRegionParam;
                    grading.RegionEnd = endRegionParam;

                    Utils.AddToModelSpace(grading);
                }
                action.Commit();
            }
        }
    }
}
