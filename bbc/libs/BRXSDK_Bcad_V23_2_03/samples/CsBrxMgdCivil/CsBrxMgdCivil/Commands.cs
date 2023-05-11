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

// alias
using _AcRx = Teigha.Runtime;
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;
using _AcGi = Teigha.GraphicsInterface;
using _AcClr = Teigha.Colors;
using _AcWnd = Bricscad.Windows;



// this attribute marks this class, as a class that contains commands or lisp callable functions 
[assembly: CommandClass(typeof(CsBrxMgdCivil.Commands))]


// this attribute marks this class, as a class having ExtensionApplication methods
// Initialize and Terminate that are called on loading and unloading of this assembly 
[assembly: ExtensionApplication(typeof(CsBrxMgdCivil.Commands))]

namespace CsBrxMgdCivil
{
    //command classes need to be public, but can be either static or instance
    public class Commands : IExtensionApplication
    {
        public Commands()
        {
            // ctor
        }

        // this is initialized when the application is loaded
        public void Initialize()
        {
            //Application.ShowAlertDialog("The commands class is Initialized");
        }

        // this is initialized when the application is terminated
        public void Terminate()
        {
            //Application.ShowAlertDialog("The commands class is Terminated");
        }

        // Create new TIN surface from point collection
        [CommandMethod("samp_TinCreate")]
        static public void sampTinCreate()
        {
            TinSurfaceSample.do_TINCreate();
        }

        // Read and display data of selected TIN Surface
        [CommandMethod("samp_TinCreateList")]
        static public void sampTinListData()
        {
            TinSurfaceSample.do_TINListData();
        }

        // Get all TIN surfaces in the drawing and list their handles
        [CommandMethod("samp_TinListAll")]
        static public void sampTinListAllHandles()
        {
            TinSurfaceSample.do_TINListAllHandles();
        }

        // Add breakline to selected TIN surface
        [CommandMethod("samp_TinAddBreakline")]
        static public void sampTinAddBreakline()
        {
            TinSurfaceSample.do_TINAddBreakline();
        }

        // Add boundary to selected TIN surface
        [CommandMethod("samp_TinAddBoundary")]
        static public void sampTinAddBoundary()
        {
            TinSurfaceSample.do_TINAddBoundary();
        }

        // Add breakline to selected TIN surface (DBR curve entity as input data)
        [CommandMethod("samp_TinAddBreaklineDBRO")]
        static public void sampTinAddBreaklineDBRO()
        {
            TinSurfaceSample.do_TINAddBreaklineDBRO();
        }

        // Add boundary to selected TIN surface (DBR curve entity as input data)
        [CommandMethod("samp_TinAddBoundaryDBRO")]
        static public void sampTinAddBoundaryDBRO()
        {
            TinSurfaceSample.do_TINAddBoundaryDBRO();
        }

        // Remove breakline from selected TIN surface
        [CommandMethod("samp_TinRemoveBreakline")]
        static public void sampTinRemoveBreakline()
        {
            TinSurfaceSample.do_TINRemoveBreakline();
        }

        // Remove boundary from selected TIN surface
        [CommandMethod("samp_TinRemoveBoundary")]
        static public void sampTinRemoveBoundary()
        {
            TinSurfaceSample.do_TINRemoveBoundary();
        }

        // Change style of selected TIN surface 
        [CommandMethod("samp_TinChangeStyle")]
        static public void sampTinChangeStyle()
        {
            TinSurfaceSample.do_TINChangeStyle();
        }

        // Merge two TIN surfaces 
        [CommandMethod("samp_TinMerge")]
        static public void sampTinMerge()
        {
            TinSurfaceSample.do_TINMerge();
        }

        // Create Mesh from TIN surface
        [CommandMethod("samp_TinMesh")]
        static public void sampTinMesh()
        {
            TinSurfaceSample.do_TINMesh();
        }

        // Drape polyline to selected TIN surface
        [CommandMethod("samp_TinDrape")]
        static public void sampTinDrape()
        {
            TinSurfaceSample.do_TINDrape();
        }

        // Create Volume TIN surface 
        [CommandMethod("samp_TinVolumeSurface")]
        static public void sampTinVolumeSurface()
        {
            TinSurfaceSample.do_TINVolumeSurfaceCreate();
        }

        // Create Volume TIN surface to elevation 
        [CommandMethod("samp_TinVolumeSurfaceElevation")]
        static public void sampTinVolumeSurfaceElevation()
        {
            TinSurfaceSample.do_TINVolumeSurfaceElevationCreate();
        }

        // Create Volume TIN surface bounded 
        [CommandMethod("samp_TinVolumeSurfaceBounded")]
        static public void sampTinVolumeSurfaceBounded()
        {
            TinSurfaceSample.do_TINVolumeSurfaceBounded();
        }

        [CommandMethod("samp_TinToColorElevation")]
        static public void sampTinToColorElevation()
        {
            TinSurfaceSample.do_colorSchemesByElevation();
        }

        [CommandMethod("samp_TinToColorSlope")]
        static public void sampTinToColorSlope()
        {
            TinSurfaceSample.do_colorSchemesBySlope();
        }

        // TIN surface jig 
        [CommandMethod("samp_TinJig")]
        static public void sampTinJig()
        {
            TinSurfaceSample.do_TINJig();
        }

        // Create grading slope offset 
        [CommandMethod("samp_GradingSlopeOffset")]
        static public void sampGradingSlopeOffset()
        {
            GradingSample.do_GradingSlopeOffsetCreate();
        }

        // Create grading slope to surface 
        [CommandMethod("samp_GradingSlopeSurface")]
        static public void sampGradingSlopeSurface()
        {
            GradingSample.do_GradingSlopeSurfaceCreate();
        }

        // Grading parameters
        [CommandMethod("samp_GradingParameters")]
        static public void sampGradingParameters()
        {
            GradingSample.do_GradingParams();
        }

        // Grading set region
        [CommandMethod("samp_GradingSetRegion")]
        static public void sampGradingSetRegion()
        {
            GradingSample.do_GradingSetRegion();
        }

        // Alignment report
        [CommandMethod("samp_AlignmentReport")]
        static public void sampAlignmentReport()
        {
            AlignmentSample.do_AlignmentReport();
        }

        // Create alignment
        [CommandMethod("samp_AlignmentCreate")]
        static public void sampAlignmentCreate()
        {
            AlignmentSample.do_CreateAlignment();
        }

        // Create alignment from polyline
        [CommandMethod("samp_AlignmentCreateFromPolyline")]
        static public void sampAlignmentCreateFromPolyline()
        {
            AlignmentSample.do_CreateAlignmentFromPolyline();
        }

        // Replace alignment element
        [CommandMethod("samp_AlignmentReplaceElement")]
        static public void sampAlignmentReplaceElement()
        {
            AlignmentSample.do_ReplaceAlignmentElement();
        }

        // Stations and "param" relations
        [CommandMethod("samp_AlignmentStationsAndParamRelations")]
        static public void sampAlignmentStationsAndParamRelations()
        {
            AlignmentSample.do_StationsAndParamRelations();
        }

        // Station equations
        [CommandMethod("samp_AlignmentStationEquations")]
        static public void sampAlignmentStationEquations()
        {
            AlignmentSample.do_StationEquations();
        }

        // Alignment jig
        [CommandMethod("samp_AlignmentJig")]
        static public void sampAlignmentJig()
        {
            AlignmentSample.do_AlignmentJig();
        }


        //convert all Civil3D entities to BricsCAD Civil entities
        [CommandMethod("samp_Civil3DConvertAll")]
        static public void sampCivil3DConvertAll()
        {
            Civil3DConverterSample.do_civil3DConvertAll();
        }
    }
}
