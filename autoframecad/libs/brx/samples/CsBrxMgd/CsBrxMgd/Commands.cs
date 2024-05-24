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
using Bricscad.Ribbon;
using Bricscad.Parametric;

// com
using BricscadDb;
using BricscadApp;

// alias
using _AcRx = Teigha.Runtime;
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;
using _AcGi = Teigha.GraphicsInterface;
using _AcClr = Teigha.Colors;
using _AcWnd = Bricscad.Windows;
using _AcDm = Bricscad.DirectModeling;



// this attribute marks this class, as a class that contains commands or lisp callable functions 
[assembly: CommandClass(typeof(CsBrxMgd.Commands))]


// this attribute marks this class, as a class having ExtensionApplication methods
// Initialize and Terminate that are called on loading and unloading of this assembly 
[assembly: ExtensionApplication(typeof(CsBrxMgd.Commands))]

namespace CsBrxMgd
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
            //Application.ShowAlertDialog("The commands class is Initializing");
            try
            {
                if (RibbonServices.RibbonPaletteSet == null)
                    RibbonServices.CreateRibbonPaletteSet(); //needed for ribbon samples

                //Create and display a native dockable panel (Bricscad.Windows.Panel)
                _AcWnd.DockingTemplate dockTemplate = new _AcWnd.DockingTemplate();
                dockTemplate.DefaultStackId = "RDOCK"; //default stack is RDOCK panelset
                dockTemplate.DefaultStackZ = 20; //default to position 20 (bottom of the stack)
                dockTemplate.DefaultDock = _AcWnd.DockSides.Right; //dock alone at right in case RDOCK panelset isn't available
                _AcWnd.Panel panel = new _AcWnd.Panel("CSharpSamples", dockTemplate, new CsMgdSamples());
                panel.Title = "C# Samples";
                panel.Icon = ImageSourceFromEmbeddedResourceStream(@"CsBrxMgd.CSharp.ico");
                panel.Visible = true;
            }
            catch (System.Exception e)
            {
                Application.ShowAlertDialog(" An exception occurred in Initialize():\n" + e.ToString());
            }
        }

        // this is initialized when the application is terminated
        public void Terminate()
        {
            //Application.ShowAlertDialog("The commands class is Terminating");
        }

        [DllImport("brx24.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Unicode)]
        private extern static IntPtr acutPrintf(string str);

        static private System.Windows.Media.ImageSource ImageSourceFromEmbeddedResourceStream(string resName)
        {
            System.Reflection.Assembly assy = System.Reflection.Assembly.GetExecutingAssembly();
            System.IO.Stream stream = assy.GetManifestResourceStream(resName);
            if (stream == null)
                return null;
            System.Windows.Media.Imaging.BitmapImage img = new System.Windows.Media.Imaging.BitmapImage();
            img.BeginInit();
            img.StreamSource = stream;
            img.EndInit();
            return img;
        }

        // This attribute marks this function as being command line callable 
        [CommandMethod("samp01")]
        static public void samp01()
        {
            DatabaseSample.do_addLine();
        }

        // non static method, static will always be faster;
        [CommandMethod("samp02")]
        public void samp02()
        {
            DatabaseSample.do_addLine();
        }

        // Create new layer sample 
        [CommandMethod("samp03")]
        static public void samp03()
        {
            DatabaseSample.do_addLayer();
        }


        //using COM selection set
        [CommandMethod("samp04")]
        static public void samp04()
        {
            ComSamples.do_comSSet();
        }

        //sample form
        [CommandMethod("samp05")]
        static public void samp05()
        {
            AcadApplication application = Application.AcadApplication as AcadApplication;
            if (application == null)
                throw new System.Exception("Could Not Get Application");

            AcadDocument document = application.ActiveDocument;
            BrxMgdForm form = new BrxMgdForm(document);
            Application.ShowModalDialog(Application.MainWindow, form);
        }

        // PInvoke BRX sample
        [CommandMethod("samp06")]
        static public void samp06()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            acutPrintf("\nPInvoke Worked, This was a managed string but now its native: ");
        }

        // Set system variable sample
        [CommandMethod("samp07")]
        static public void samp07()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcAp.Application.SetSystemVariable("OSMODE", 191);
            object osmode = _AcAp.Application.GetSystemVariable("OSMODE");
            editor.WriteMessage("{0}", osmode);
        }

        // sample to create a polyline
        [CommandMethod("samp08")]
        static public void samp08()
        {
            DatabaseSample.do_addPolyLine();
        }


        // sample to create a circle
        [CommandMethod("samp09")]
        static public void samp09()
        {
            DatabaseSample.do_addCircle();
        }


        // sample to get the current Document, Textsize and UCS
        [CommandMethod("samp10")]
        static public void samp10()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            foreach (Document doc in Application.DocumentManager)
            {
                ed.WriteMessage("\nDocument {0}, Textsize={1}, UCS={2}:",
                    doc.Name, doc.Database.Textsize, doc.Editor.CurrentUserCoordinateSystem);
            }

            ed.WriteMessage("\nMdiActiveDocument {0}:", Application.DocumentManager.MdiActiveDocument.Name);
        }

        //performance test
        [CommandMethod("samp11")]
        public static void samp11()
        {
            DatabaseSample.do_performanceTest();
        }

        //com performance test
        [CommandMethod("samp12")]
        public static void samp12()
        {
            ComSamples.do_performanceTest();
        }


        // read in a database from a .dwg
        [CommandMethod("samp13")]
        public static void samp13()
        {
            DatabaseSample.do_readDwgFile();
        }

        // get/set properties to the main BricsCAD Window
        [CommandMethod("samp14")]
        public static void samp14()
        {
            EditorSample.do_MainWindow();
        }

        //start point monitor sample
        [CommandMethod("samp15")]
        public static void samp15()
        {
            Application.ShowAlertDialog("Hover the cursor over Block References");
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            ed.PointMonitor += new PointMonitorEventHandler(EditorSample.OnPointMonitor);
        }

        //end pointmonitor sample
        [CommandMethod("samp16")]
        public static void samp16()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            ed.PointMonitor -= new PointMonitorEventHandler(EditorSample.OnPointMonitor);
        }

        // sample to create a table
        [CommandMethod("samp17")]
        public static void samp17()
        {
            DatabaseSample.do_createTable();
        }

        //Editor Sample
        [CommandMethod("samp18")]
        public static void samp18()
        {
            EditorSample.do_getString();
        }

        //Editor Sample
        [CommandMethod("samp19")]
        public static void samp19()
        {
            EditorSample.do_getKeyWords();
        }

        //Editor Sample
        [CommandMethod("samp20")]
        public static void samp20()
        {
            EditorSample.do_getPoint();
        }

        //Editor Sample
        [CommandMethod("samp21")]
        public static void samp21()
        {
            EditorSample.do_getDistance();
        }

        //Editor Sample
        [CommandMethod("samp22")]
        public static void samp22()
        {
            EditorSample.do_getEntity();
        }

        //Editor Sample
        [CommandMethod("samp23")]
        public static void samp23()
        {
            EditorSample.do_getEntity2();
        }
		
        //Overrule Sample
        internal static PointPositionDrawOverrule m_PointPosDrawOverrule = null;

        [CommandMethod("samp24")]
        public static void samp24()
        {
            _AcAp.Application.ShowAlertDialog("Draw a few points \nre-run the command to toggle visuals");
            if (m_PointPosDrawOverrule == null)
            {
                m_PointPosDrawOverrule = new PointPositionDrawOverrule();
                Overrule.AddOverrule(RXObject.GetClass(typeof(DBPoint)), m_PointPosDrawOverrule, false);
                Overrule.Overruling = true;
            }
            else
            {
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(DBPoint)), m_PointPosDrawOverrule);
                m_PointPosDrawOverrule = null;
            }
            _AcAp.Application.DocumentManager.MdiActiveDocument.Editor.Regen();
        }

        //Editor Sample
        [CommandMethod("samp25")]
        public static void samp25()
        {
            EditorSample.do_getSelectionSet();
        }

        //Editor.Snap
        [CommandMethod("samp26")]
        public static void samp26()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptPointResult PPR1 = ed.GetPoint("Pick Point near object");
            if (PPR1.Status == _AcEd.PromptStatus.OK)
            {
                _AcGe.Point3d snap = ed.Snap("nearest", PPR1.Value);
                ed.WriteMessage("\n{0} {1}", PPR1.Value, snap);
            }
        }

        //Editor.SelectPrevious
        [CommandMethod("samp27")]
        public static void samp27()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptSelectionResult res = ed.SelectPrevious();
            ed.WriteMessage("\n{0} {1}", res, res.Value.Count);
        }

        //Editor.SelectFence
        [CommandMethod("samp28")]
        public static void samp28()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcGe.Point3dCollection col = new _AcGe.Point3dCollection();

            _AcEd.PromptPointResult PPR1 = ed.GetPoint("Get Point");
            if (PPR1.Status == _AcEd.PromptStatus.OK)
                col.Add(PPR1.Value);

            PromptPointOptions ppo = new PromptPointOptions("Get next Point");
            ppo.UseBasePoint = true;
            ppo.BasePoint = PPR1.Value;

            _AcEd.PromptPointResult PPR2 = ed.GetPoint(ppo);
            if (PPR2.Status == _AcEd.PromptStatus.OK)
                col.Add(PPR2.Value);

            _AcEd.PromptSelectionResult res = ed.SelectFence(col);
            ed.WriteMessage("\n{0} {1}", res, res.Value.Count);
        }

        //Editor.SelectWindow
        [CommandMethod("samp29")]
        public static void samp29()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcEd.PromptPointResult PPR1 = ed.GetPoint("Get Point");
            if (PPR1.Status != _AcEd.PromptStatus.OK)
                return;
            _AcEd.PromptPointResult PPR2 = ed.GetCorner("Get Corner", PPR1.Value);
            if (PPR2.Status != _AcEd.PromptStatus.OK)
                return;

            _AcEd.PromptSelectionResult res = ed.SelectWindow(PPR1.Value, PPR2.Value);
            ed.WriteMessage("\n{0} {1}", res, res.Value.Count);
        }


        //Color Dialog
        [CommandMethod("samp30")]
        public static void samp30()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcWnd.ColorDialog dlg = new _AcWnd.ColorDialog();
            if (dlg.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                ed.WriteMessage("\nColor = {0}", dlg.Color);
            }
        }

        //LineType Dialog
        [CommandMethod("samp31")]
        public static void samp31()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcWnd.LinetypeDialog dlg = new _AcWnd.LinetypeDialog();
            dlg.Linetype = _AcDb.HostApplicationServices.WorkingDatabase.Celtype;
            if (dlg.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                ed.WriteMessage("\nLineType ObjectId = {0}", dlg.Linetype);
            }
        }

        //OpenFileDialog
        [CommandMethod("samp32")]
        public static void samp32()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcWnd.OpenFileDialog dlg =
                new _AcWnd.OpenFileDialog("Test", "Drawing", "dwg", "BricsCAD File Nav",
                _AcWnd.OpenFileDialog.OpenFileDialogFlags.AllowAnyExtension |
                _AcWnd.OpenFileDialog.OpenFileDialogFlags.AllowMultiple);

            if (dlg.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                foreach (String file in dlg.GetFilenames())
                    ed.WriteMessage(file);
            }
        }

        //SaveFileDialog
        [CommandMethod("samp33")]
        public static void samp33()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            _AcWnd.SaveFileDialog dlg =
                new _AcWnd.SaveFileDialog("Test", "Drawing", "dwg", "BricsCAD File Nav",
                _AcWnd.SaveFileDialog.SaveFileDialogFlags.AllowAnyExtension);

            if (dlg.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                ed.WriteMessage(dlg.Filename);
            }
        }


        //Conversions 
        [CommandMethod("samp34")]
        public static void samp34()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            string a = _AcRx.Converter.AngleToString(System.Math.PI);
            string b = _AcRx.Converter.AngleToString(121.135, _AcRx.AngularUnitFormat.DegreesMinutesSeconds, 5);
            string c = _AcRx.Converter.DistanceToString(System.Math.PI);
            string d = _AcRx.Converter.DistanceToString(System.Math.PI, _AcRx.DistanceUnitFormat.Architectural, -1);

            ed.WriteMessage("\nAngleToString {0}", a);
            ed.WriteMessage("\nAngleToString {0}", b);
            ed.WriteMessage("\nDistanceToString {0}", c);
            ed.WriteMessage("\nDistanceToString {0}", d);

            ed.WriteMessage("\nStringToAngle {0}", _AcRx.Converter.StringToAngle(a));
            ed.WriteMessage("\nStringToAngle {0}", _AcRx.Converter.StringToAngle(b, _AcRx.AngularUnitFormat.DegreesMinutesSeconds));
            ed.WriteMessage("\nStringToDistance {0}", _AcRx.Converter.StringToDistance(c));
            ed.WriteMessage("\nStringToDistance {0}", _AcRx.Converter.StringToDistance(d, _AcRx.DistanceUnitFormat.Architectural));
        }

        // Entity Jig 
        [CommandMethod("samp35")]
        public static void samp35()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            using (MyEntityJig jig = new MyEntityJig())
            {
                jig.StartJig();
            }
        }

        // Draw Jig 
        [CommandMethod("samp36")]
        public static void samp36()
        {
            _AcEd.Editor ed = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            using (MyDrawJig jig = new MyDrawJig())
            {
                jig.StartJig();
            }
        }

        // AddRibbon
        [CommandMethod("samp37")]
        public static void samp37()
        {
            Ribbon.AddButtons();
        }

        // Ribbon RemoveTab
        [CommandMethod("samp38")]
        public static void samp38()
        {
            Ribbon.removeTab();
        }

        // Ribbon RemovePanel
        [CommandMethod("samp39")]
        public static void samp39()
        {
            Ribbon.FindRemoveRibbonButton();
        }

        // Ribbon RemoveButton
        [CommandMethod("samp40")]
        public static void samp40()
        {
            Ribbon.RibbonToggle();
        }

        [CommandMethod("samp41")]
        public static void samp41()
        {
            Ribbon.SplitButton();
        }

        [CommandMethod("samp42")]
        public static void samp42()
        {
            Ribbon.RowPanelRowBreakSeparator();
        }

        [CommandMethod("samp43")]
        public static void samp43()
        {
            Ribbon.FindRemoveRibbonPanel();
        }

        [CommandMethod("samp44")]
        public static void samp44()
        {
            Ribbon.AddClonedObjects();
        }

        [CommandMethod("samp45")]
        public static void samp45()
        {
            Ribbon.AddRibbonComboRibbonTextBox();
        }

        [CommandMethod("samp46")]
        public static void samp46()
        {
            QuadCommands quadCommands = new QuadCommands();
            quadCommands.AddMyQuadReactor();
        }

        [CommandMethod("samp47")]
        public static void samp47()
        {
            QuadCommands quadCommands = new QuadCommands();
            quadCommands.RemoveMyQuadReactor();
        }

        [CommandMethod("samp48")]
        public static void samp48()
        {
            Ribbon.addWPFControls();
        }

        [CommandMethod("samp49")]
        public static void samp49()
        {
            Constraints3dSample.Constraints3dBlockReference();
        }

        [CommandMethod("samp50")]
        public static void samp50()
        {
            Constraints3dSample.Constraints3dDistanceBetweenFaces();
        }

        [CommandMethod("samp50_CS")]
        public static void samp50_CS()
        {
            Constraints3dSample.Constraints3dDistanceToCoordinateSystemObject();
        }

        [CommandMethod("samp50_MeasurementMode")]
        public static void samp50_MeasurementMode()
        {
            Constraints3dSample.Constraints3dDistanceToFaceBoundary();
        }

        [CommandMethod("samp51")]
        public static void samp51()
        {
            Ribbon.addRibbonPanelBreak();
        }

        [CommandMethod("samp52")]
        public static void samp52()
        {
            IfcExportReactor.Register();
        }

        [CommandMethod("samp53")]
        public static void samp53()
        {
            IfcExportReactor.Unregister();
        }

        [CommandMethod("samp54")]
        public static void samp54()
        {
            IfcImportReactor.Register();
        }

        [CommandMethod("samp55")]
        public static void samp55()
        {
            IfcImportReactor.Unregister();
        }

        [CommandMethod("samp56")]
        public static void samp56()
        {
            DatabaseSample.do_getBlockPreviewIcon();
        }

        //sample palette (themed + unthemed)
        [CommandMethod("samp57")]
        static public void samp57()
        {
            if (_paletteset == null)
            {
                // Create the custom WinForms forms. The first form will be
                // automatically themed; the second will not be themed.
                MyUserControl page1 = new MyUserControl("Control1", true);
                MyUserControl page2 = new MyUserControl("Control2", false);

                // Create the palette set
                _paletteset = new _AcWnd.PaletteSet("Sample PaletteSet");
                _paletteset.Size = new System.Drawing.Size(400, 600);
                _paletteset.DockEnabled = (_AcWnd::DockSides)((int)_AcWnd::DockSides.Left + (int)_AcWnd::DockSides.Right);
                _paletteset.Dock = _AcWnd.DockSides.Left;

                // Add the custom forms
                _paletteset.Add("Themed WinForm", page1);
                _paletteset.Add("Unthemed WinForm", page2);
            }
            _paletteset.KeepFocus = true;
            _paletteset.Visible = true;
        }
        static _AcWnd.PaletteSet _paletteset;
        public class MyUserControl : System.Windows.Forms.UserControl
        {
            private System.ComponentModel.IContainer components = null;
            public MyUserControl(string name, bool autoThemed)
            {
                InitializeComponent(name);
                // The control style SupportsTransparentBackColor flag is used by the
                // PaletteSet framework to enable or disable automatic theming. When
                // the flag is not set, ForeColor and BackColor properties of the form
                // will be synchronized to the current theme colors. The flag is set
                // by default in UserControl, so the default behavior is un-themed.
                if (autoThemed)
                    SetStyle(System.Windows.Forms.ControlStyles.SupportsTransparentBackColor, false);
            }
            protected override void Dispose(bool disposing)
            {
                if (disposing && (components != null))
                {
                    components.Dispose();
                }
                base.Dispose(disposing);
            }
            private void InitializeComponent(string name)
            {
                this.button1 = new System.Windows.Forms.Button();
                this.SuspendLayout();

                this.button1.Location = new System.Drawing.Point(16, 16);
                this.button1.Name = "button1";
                this.button1.Size = new System.Drawing.Size(150, 50);
                this.button1.TabIndex = 0;
                this.button1.Text = "Test";

                this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
                this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
                this.Controls.Add(this.button1);
                this.Name = name;
                this.ResumeLayout(false);
                this.PerformLayout();
            }
            public System.Windows.Forms.Button button1;
        }

        [CommandMethod("samp58")]
        public void samp58()
        {
            MechanicalComponents.RetrieveComponentName();
        }

        // This sample demonstrates using an overrule to draw point elevation labels always
        // scaled based on the viewport scale and oriented horizontally on the display.
        // The sample uses a block named LABEL, and containing an ELEV attribute, as a template.
        internal static PointReadableElevDrawOverrule m_pointElevDrawOverrule = null;
        [CommandMethod("samp59")]
        public static void samp59()
        {
            _AcAp.Application.ShowAlertDialog("Draw point entities in modelspace and view them in paperspace at various view orientations. Define a template block LABEL including an attribute definition with tag ELEV to display the point's Z coordinate.\nRun the command again to toggle the behavior off and on.");
            if (m_pointElevDrawOverrule == null)
            {
                m_pointElevDrawOverrule = new PointReadableElevDrawOverrule();
                Overrule.AddOverrule(RXObject.GetClass(typeof(DBPoint)), m_pointElevDrawOverrule, false);
                Overrule.Overruling = true;
            }
            else
            {
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(DBPoint)), m_pointElevDrawOverrule);
                m_pointElevDrawOverrule = null;
            }
            _AcAp.Application.DocumentManager.MdiActiveDocument.Editor.Regen();
        }

        // This sample demonstrates using an overrule to simulate a multi-mode grip. The sample replaces
        // the single grip of a point entity with a custom "multi-mode" grip that displays a context
        // menu when hovered. The context menu runs DONUTIZE or CIRCLIZE commands to convert the point
        // into a donut or circle. Those commands are also defined below.
        internal static PointGripOverrule m_pointGripOverrule = null;
        [CommandMethod("samp60")]
        public static void samp60()
        {
            if (m_pointGripOverrule == null)
            {
                m_pointGripOverrule = new PointGripOverrule();
                Overrule.AddOverrule(RXObject.GetClass(typeof(DBPoint)), m_pointGripOverrule, false);
                Overrule.Overruling = true;
            }
            else
            {
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(DBPoint)), m_pointGripOverrule);
                m_pointGripOverrule = null;
            }
        }
        internal static _AcDb.ObjectId SelectPointEntity(_AcEd.Editor ed)
        {
            // If the pickfirst set consists of a single point entity, use that without prompting
            _AcEd.PromptSelectionResult pickfirst = ed.SelectImplied();
            if (pickfirst.Status == _AcEd.PromptStatus.OK && pickfirst.Value.Count == 1)
            {
                _AcDb.ObjectId id = pickfirst.Value[0].ObjectId;
                if (id.ObjectClass == RXClass.GetClass(typeof(_AcDb.DBPoint)))
                    return id;
            }
            // Otherwise prompt to select a point entity
            _AcEd.PromptEntityOptions peo = new _AcEd.PromptEntityOptions("Select a Point entity: ");
            peo.SetRejectMessage("Not a Point entity!");
            peo.AddAllowedClass(typeof(_AcDb.DBPoint), true);
            _AcEd.PromptEntityResult per = ed.GetEntity(peo);
            return per.ObjectId;
        }
        [CommandMethod("DONUTIZE", CommandFlags.UsePickSet)]
        public static void DONUTIZE()
        {
            _AcAp.Document doc = _AcAp.Application.DocumentManager.MdiActiveDocument;
            _AcEd.Editor ed = doc.Editor;
            _AcDb.ObjectId pointId = SelectPointEntity(ed);
            if (!pointId.IsNull)
            {
                using (_AcDb.Transaction tx = doc.TransactionManager.StartTransaction())
                {
                    _AcDb.DBPoint point = tx.GetObject(pointId, _AcDb.OpenMode.ForWrite) as _AcDb.DBPoint;
                    using (_AcDb.Polyline donut = new _AcDb.Polyline(2))
                    {
                        donut.SetDatabaseDefaults(point.Database);
                        donut.SetPropertiesFrom(point);
                        donut.Elevation = point.Position.Z;
                        donut.Normal = point.Normal;
                        donut.AddVertexAt(0, new _AcGe.Point2d(point.Position.X, point.Position.Y + 0.5), 1.0, 1.0, 1.0);
                        donut.AddVertexAt(1, new _AcGe.Point2d(point.Position.X, point.Position.Y - 0.5), 1.0, 1.0, 1.0);
                        donut.Closed = true;
                        _AcDb.BlockTableRecord owner = tx.GetObject(point.OwnerId, _AcDb.OpenMode.ForWrite) as _AcDb.BlockTableRecord;
                        owner.AppendEntity(donut);
                        tx.AddNewlyCreatedDBObject(donut, true);
                        point.Erase();
                    }
                    tx.Commit();
                }
            }
        }
        [CommandMethod("CIRCLIZE", CommandFlags.UsePickSet)]
        public static void CIRCLIZE()
        {
            _AcAp.Document doc = _AcAp.Application.DocumentManager.MdiActiveDocument;
            _AcEd.Editor ed = doc.Editor;
            _AcDb.ObjectId pointId = SelectPointEntity(ed);
            if (!pointId.IsNull)
            {
                using (_AcDb.Transaction tx = doc.TransactionManager.StartTransaction())
                {
                    _AcDb.DBPoint point = tx.GetObject(pointId, _AcDb.OpenMode.ForWrite) as _AcDb.DBPoint;
                    using (_AcDb.Circle circle = new _AcDb.Circle(point.Position, point.Normal, 1.0))
                    {
                        circle.SetDatabaseDefaults(point.Database);
                        circle.SetPropertiesFrom(point);
                        _AcDb.BlockTableRecord owner = tx.GetObject(point.OwnerId, _AcDb.OpenMode.ForWrite) as _AcDb.BlockTableRecord;
                        owner.AppendEntity(circle);
                        tx.AddNewlyCreatedDBObject(circle, true);
                        point.Erase();
                    }
                    tx.Commit();
                }
            }
        }

        // This overrule changes the entity draw color depending on the current thread
        // as a way to visualize multi-threaded display graphics rendering.
        internal static ThreadIdColorDrawOverrule m_colorByThreadOverrule = null;
        [CommandMethod("samp61")]
        public static void samp61()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            if (m_colorByThreadOverrule == null)
            {
                m_colorByThreadOverrule = new ThreadIdColorDrawOverrule();
                Overrule.AddOverrule(RXObject.GetClass(typeof(Entity)), m_colorByThreadOverrule, false);
                Overrule.Overruling = true;
                ed.WriteMessage("\nDraw color depending on current thread is ENABLED\n");
            }
            else
            {
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(Entity)), m_colorByThreadOverrule);
                m_colorByThreadOverrule = null;
                ed.WriteMessage("\nDraw color depending on current thread is DISABLED\n");
            }
        }

        // This overrule disables multi-threaded display graphics rendering of all entities.
        internal static ForceSingleThreadedDrawOverrule m_forceSingleThreadOverrule = null;
        [CommandMethod("samp62")]
        public static void samp62()
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            if (m_forceSingleThreadOverrule == null)
            {
                m_forceSingleThreadOverrule = new ForceSingleThreadedDrawOverrule();
                Overrule.AddOverrule(RXObject.GetClass(typeof(Entity)), m_forceSingleThreadOverrule, false);
                Overrule.Overruling = true;
                ed.WriteMessage("\nForced single-threaded display graphics rendering is ENABLED\n");
            }
            else
            {
                Overrule.RemoveOverrule(RXObject.GetClass(typeof(Entity)), m_forceSingleThreadOverrule);
                m_forceSingleThreadOverrule = null;
                ed.WriteMessage("\nForced single-threaded display graphics rendering is DISABLED\n");
            }
        }

        // Use ModelerThreadLock within a thread function to create some NDBRO cubes in parallel.
        [CommandMethod("samp63")]
        public static void samp63()
        {
            int[] dims = new int[] { 1, 2, 3, 4, 5, 6, 7 };
            System.Collections.Concurrent.ConcurrentBag<int> volumes = new System.Collections.Concurrent.ConcurrentBag<int>();
            System.Threading.Tasks.ParallelLoopResult plr = System.Threading.Tasks.Parallel.ForEach<int>(dims, dim =>
            {
                using (_AcDm.ModelerThreadLock modelerThreadLock = new _AcDm.ModelerThreadLock())
                {
                    using (_AcDb.Solid3d solid = new _AcDb.Solid3d())
                    {
                        solid.CreateBox(dim, dim, 1);
                        volumes.Add((int)solid.MassProperties.Volume);
                    }
                }
            });

            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            if (!plr.IsCompleted)
            {
                ed.WriteMessage("\nParallel multithreaded loop was not completed!\n");
                return;
            }
            int totalVolume = 0;
            foreach (int volume in volumes)
                totalVolume += volume;
            ed.WriteMessage(string.Format("\nCalculated total volume: {0}\n", totalVolume.ToString()));
        }

        [CommandMethod("samp64")]
        public static void samp64()
        {
            HlrSample.GenerateHlrLines();
        }

        [CommandMethod("samp65")]
        public static void samp65()
        {
            BimSample.CreateBimColumn();
        }

        [CommandMethod("samp66")]
        public static void samp66()
        {
            BimSample.GetSetBIMProperties();
        }

        [CommandMethod("samp67")]
        public static void samp67()
        {
            BimSample.GetBIMProfileProperties();
        }

        // this attribute marks this function as being lisp callable 
        [LispFunction("lisp01")]
        // Note: you can return types bool, int, double, Point2d, Point3d, ObjectID, TypedValue,
        // ResultBuffer or null to lisp
        static public ResultBuffer lisp01(ResultBuffer pArgs)
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            if (pArgs != null)
            {
                List<TypedValue> inArray = new List<TypedValue>(pArgs.AsArray());
                return new ResultBuffer(inArray.ToArray());
            }
            return null;
        }

        // one thing to keep in mind when passing arguments from lisp, 
        // the lisp interpret will sometimes evaluate certain patterns. 
        // I.e a list of three numbers will evaluate as a point3.
        //(lisp02 1 2 "3" 1.2 '(1 2 3) '(1 2))
        [LispFunction("lisp02")]
        static public string lisp02(ResultBuffer pArgs)
        {
            Editor ed = Application.DocumentManager.MdiActiveDocument.Editor;
            String result = string.Empty;
            if (pArgs != null)
            {
                foreach (TypedValue typedValue in pArgs)
                {
                    switch ((LispDataType)typedValue.TypeCode)
                    {
                        case LispDataType.ListBegin:
                            result += "(";
                            break;
                        case LispDataType.ListEnd:
                            result += ")";
                            break;
                        case LispDataType.Double:
                            result += " real ";
                            break;
                        case LispDataType.Int16:
                            result += " int16 ";
                            break;
                        case LispDataType.Int32:
                            result += " int32 ";
                            break;
                        case LispDataType.Point3d:
                            result += " Point3d ";
                            break;
                        case LispDataType.Point2d:
                            result += " Point2d ";
                            break;
                        case LispDataType.ObjectId:
                            result += " ObjectId ";
                            break;
                        case LispDataType.T_atom:
                            result += " T ";
                            break;
                        case LispDataType.Nil:
                            result += " NIL ";
                            break;
                        case LispDataType.Text:
                            result += " Text ";
                            break;
                    }
                }
            }
            return result;
        }
    }
}
