// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

using System;
using System.Text;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;

using Bricscad.Runtime;
using Teigha.DatabaseServices;
using Teigha.Geometry;
using Teigha.Runtime;
using Bricscad.ApplicationServices;
using Bricscad.EditorInput;
using Teigha.Colors;
using Teigha.GraphicsInterface;

//alias
using _AcRx = Teigha.Runtime;
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;
using _AcGi = Teigha.GraphicsInterface;
using _AcClr = Teigha.Colors;
using _AcWnd = Bricscad.Windows;


namespace CsBrxMgd
{
    public class MyDrawJig : DrawJig, IDisposable
    {
        // Fields
        private Point3d currentCursorPosition;
        private bool disposed;
        private Editor editor;
        private List<Entity> EntsToDrag;
        private Point3d previousCursorPosition;

        // Constructors
        public MyDrawJig()
        {
            this.editor = Application.DocumentManager.MdiActiveDocument.Editor;
            this.previousCursorPosition = new Point3d(0.0, 0.0, 0.0);
            this.EntsToDrag = InitEntity();
        }

        private List<Entity> InitEntity()
        {
            List<Entity> ents = new List<Entity>();
            _AcDb.Polyline pline = new _AcDb.Polyline(4);
            pline.SetDatabaseDefaults(editor.Document.Database);
            pline.AddVertexAt(0, new Point2d(0, 0), 0, 0, 0);
            pline.AddVertexAt(1, new Point2d(0, 10), 0, 0, 0);
            pline.AddVertexAt(2, new Point2d(10, 10), 0, 0, 0);
            pline.AddVertexAt(3, new Point2d(10, 0), 0, 0, 0);
            pline.Closed = true;
            pline.Color = Color.FromColorIndex(ColorMethod.ByAci, 10);
            ents.Add(pline);
            ents.Add(new Circle(new Point3d(0, 0, 0), Vector3d.ZAxis, 2));
            ents.Add(new Circle(new Point3d(0, 10, 0), Vector3d.ZAxis, 2));
            ents.Add(new Circle(new Point3d(10, 10, 0), Vector3d.ZAxis, 2));
            ents.Add(new Circle(new Point3d(10, 0, 0), Vector3d.ZAxis, 2));
            return ents;
        }

        // Methods
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
                    foreach (Entity item in EntsToDrag)
                    {
                        item.Dispose();
                    }
                }
                this.disposed = true;
            }
        }

        protected override void OnDimensionValueChanged(DynamicDimensionChangedEventArgs e)
        {
        }

        protected override SamplerStatus Sampler(JigPrompts prompts)
        {
            PromptPointResult userFeedback = prompts.AcquirePoint("\nSpecify insertion point:");
            this.currentCursorPosition = userFeedback.Value;
            if (this.CursorHasMoved())
            {
                foreach (Entity item in EntsToDrag)
                {
                    item.TransformBy(Matrix3d.Displacement(
                        this.currentCursorPosition - this.previousCursorPosition));
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

        protected override bool WorldDraw(WorldDraw draw)
        {
            foreach (Entity item in EntsToDrag)
            {
                draw.Geometry.Draw(item);
            }
            return true;
        }
    }

    //
    public class MyEntityJig : EntityJig, IDisposable
    {
        private Point3d currentCursorPosition;
        private bool disposed;
        private Editor editor;
        private Point3d previousCursorPosition;
        private DynamicDimensionDataCollection ddims;

        public MyEntityJig()
            : base(InitEntity())
        {
            this.editor = Application.DocumentManager.MdiActiveDocument.Editor;
            this.previousCursorPosition = new Point3d(0.0, 0.0, 0.0);
            ddims = new DynamicDimensionDataCollection();
            Dimension ddim = new AlignedDimension();
            ddim.SetDatabaseDefaults(HostApplicationServices.WorkingDatabase);
            ddims.Add(new DynamicDimensionData(ddim, true, false));
        }

        static internal Entity InitEntity()
        {
            Editor editor = Application.DocumentManager.MdiActiveDocument.Editor;
            PromptPointResult ppr = editor.GetPoint("Pick first point");
            Line line = new Line(ppr.Value, ppr.Value);
            return line;
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
            AlignedDimension dim = (AlignedDimension)ddims[0].Dimension;
            Line line = base.Entity as Line;
            dim.XLine1Point = line.StartPoint;
            dim.XLine2Point = line.EndPoint;
            dim.DimLinePoint = line.StartPoint + ((line.EndPoint - line.StartPoint) * 0.5);
            dim.TextPosition = line.StartPoint + ((line.EndPoint - line.StartPoint) * 0.5);
            return true;
        }

        protected override DynamicDimensionDataCollection GetDynamicDimensionData(double dimScale)
        {
            return ddims;
        }

        protected override void OnDimensionValueChanged(DynamicDimensionChangedEventArgs e)
        {
            this.editor.WriteMessage("OnDimensionValueChanged {0} {1}", e.Index, e.Value);
        }

        protected override SamplerStatus Sampler(JigPrompts prompts)
        {
            PromptPointResult userFeedback = prompts.AcquirePoint("\nSpecify insertion point:");
            this.currentCursorPosition = userFeedback.Value;
            if (this.CursorHasMoved())
            {
                Line line = base.Entity as Line;
                line.EndPoint = this.currentCursorPosition;
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
}
