// system 
using System;

// alias
using _AcAp = Bricscad.ApplicationServices;
using _AcRx = Teigha.Runtime;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;
using _AcGi = Teigha.GraphicsInterface;
using Teigha.GraphicsInterface;
using Teigha.Runtime;

namespace CsBrxMgd
{
    public class PointPositionDrawOverrule : _AcGi.DrawableOverrule
    {
        public override bool WorldDraw(_AcGi.Drawable drawable, _AcGi.WorldDraw wd)
        {
            _AcDb.DBPoint point = drawable as _AcDb.DBPoint;
            _AcGe.Point3d pos = point.Position;
            string text = string.Format("x={0}, y={1}, z={2}",
                pos.X.ToString("F"), pos.Y.ToString("F"), pos.Z.ToString("F"));
            double texthight = point.Database.Textsize;
            wd.Geometry.Text(point.Position, point.Normal, point.Normal.GetPerpendicularVector(),
              texthight, (texthight * text.Length) * 0.4, 0.0, text);
            return base.WorldDraw(drawable, wd);
        }
    }
    public class PointReadableElevDrawOverrule : _AcGi.DrawableOverrule
    {
        // LabelTemplateBlock is the name of a block definition to be used as a template when
        // drawing the point entity graphics. The default name is "LABEL". If the template
        // block has an attribute definition with tag ELEV, this attribute will be replaced
        // with the value of the point's Z coordinate.
        public string LabelTemplateBlock { get; set; }
        public override bool IsApplicable(RXObject overruledSubject)
        {
            _AcDb.DBPoint pointEnt = overruledSubject as _AcDb.DBPoint;
            if (pointEnt != null && pointEnt.OwnerId.IsNull)
            {
                bool isLayout = false;
                using (_AcDb.Transaction trans = pointEnt.OwnerId.Database.TransactionManager.StartOpenCloseTransaction())
                {
                    using (_AcDb.BlockTableRecord btr = trans.GetObject(pointEnt.OwnerId, _AcDb.OpenMode.ForRead) as _AcDb.BlockTableRecord)
                    {
                        isLayout = btr.IsLayout;
                    }
                    trans.Commit();
                }
                return isLayout;
            }
            return false;
        }
        public override int SetAttributes(Drawable drawable, DrawableTraits traits)
        {
            return base.SetAttributes(drawable, traits) | (int)(_AcGi.AttributesFlags.DrawableUsesNesting);
        }
        public override void ViewportDraw(Drawable drawable, ViewportDraw vd)
        {
            base.ViewportDraw(drawable, vd); //draw the point entity in the ordinary way
            if (vd.Context.IsNesting)
                return; //only overruling top level point entities
            _AcDb.DBPoint pointEnt = drawable as _AcDb.DBPoint;
            _AcDb.ObjectId templateId = new _AcDb.ObjectId();
            _AcDb.Database db = vd.Context.Database;
            using (_AcDb.Transaction trans = db.TransactionManager.StartOpenCloseTransaction())
            {
                using (_AcDb.BlockTable bt = trans.GetObject(db.BlockTableId, _AcDb.OpenMode.ForRead) as _AcDb.BlockTable)
                {
                    string blockName = LabelTemplateBlock;
                    if (string.IsNullOrEmpty(blockName))
                        blockName = "LABEL";
                    templateId = bt[blockName];
                }
                trans.Commit();
            }
            _AcGe.Point3d position = pointEnt.Position;
            double rotation = vd.Viewport.CameraUpVector.GetAngleTo(_AcGe.Vector3d.YAxis);
            double scaling = vd.Viewport.LinetypeScaleMultiplier;
            _AcGe.Matrix3d viewOrient = _AcGe.Matrix3d.Displacement(position.GetAsVector()) *
                _AcGe.Matrix3d.Rotation(rotation, _AcGe.Vector3d.ZAxis, _AcGe.Point3d.Origin) *
                _AcGe.Matrix3d.Scaling(scaling, _AcGe.Point3d.Origin);
            vd.Geometry.PushModelTransform(viewOrient);
            try
            {
                DrawElevLabel(vd.Geometry, templateId, position.Z);
            }
            finally
            {
                vd.Geometry.PopModelTransform();
            }
        }
        public override bool WorldDraw(_AcGi.Drawable drawable, _AcGi.WorldDraw wd)
        {
            return false;
        }
        private void DrawElevLabel(Geometry drawGeom, _AcDb.ObjectId templateId, double elevation)
        {
            if (templateId.IsNull)
                return;
            _AcDb.Database db = templateId.Database;
            using (_AcDb.Transaction trans = db.TransactionManager.StartOpenCloseTransaction())
            {
                using (_AcDb.BlockTableRecord template = trans.GetObject(templateId, _AcDb.OpenMode.ForRead) as _AcDb.BlockTableRecord)
                {
                    foreach (_AcDb.ObjectId entId in template)
                    {
                        using (_AcDb.Entity ent = trans.GetObject(entId, _AcDb.OpenMode.ForRead) as _AcDb.Entity)
                        {
                            if (!ent.Visible)
                                continue;
                            _AcDb.AttributeDefinition attDef = ent as _AcDb.AttributeDefinition;
                            if (attDef != null)
                            {
                                if (attDef.Tag == "ELEV")
                                {
                                    using (_AcDb.AttributeReference attrib = new _AcDb.AttributeReference())
                                    {
                                        attrib.SetDatabaseDefaults(db);
                                        attrib.SetAttributeFromBlock(attDef, _AcGe.Matrix3d.Identity);
                                        attrib.TextString = elevation.ToString("F");
                                        drawGeom.Draw(attrib);
                                    }
                                }
                            }
                            else
                            {
                                drawGeom.Draw(ent);
                            }
                        }
                    }
                }
                trans.Commit();
            }
        }
    }

    public class MultiModePointGripData : _AcDb.GripData
    {
        public MultiModePointGripData(_AcGe.Point3d gripPoint)
        {
            this.GripPoint = gripPoint;
        }
        public override ReturnValue OnHover(_AcDb.ObjectId entityId, Context contextFlags)
        {
            // create a context menu
            System.Windows.Forms.ContextMenuStrip multiModeMenu = new System.Windows.Forms.ContextMenuStrip();
            System.Windows.Forms.ToolStripItem donutize = multiModeMenu.Items.Add("Donutize", null, onDonutize);
            donutize.ToolTipText = "Convert to donut";
            System.Windows.Forms.ToolStripItem circlize = multiModeMenu.Items.Add("Circlize", null, onCirclize);
            circlize.ToolTipText = "Convert to circle";
            multiModeMenu.AutoClose = true;

            // create a completely transparent form for hosting the context menu
            System.Windows.Forms.Form backingForm = new System.Windows.Forms.Form();
            backingForm.Location = _AcAp.Application.DocumentManager.MdiActiveDocument.Window.GetLocation();
            backingForm.Size = _AcAp.Application.DocumentManager.MdiActiveDocument.Window.GetSize();
            backingForm.Opacity = 0;
            backingForm.Show(_AcAp.Application.DocumentManager.MdiActiveDocument.Window);

            // make sure the form is closed when the menu closes
            multiModeMenu.Closed += delegate (object s, System.Windows.Forms.ToolStripDropDownClosedEventArgs e)
            {
                backingForm.Close();
            };
            multiModeMenu.Show(backingForm, backingForm.PointToClient(System.Windows.Forms.Control.MousePosition));
            return ReturnValue.Ok;
        }
        private void onDonutize(object s, EventArgs e)
        {
            _AcAp.Application.DocumentManager.MdiActiveDocument.SendStringToExecute("_DONUTIZE\n", true, false, true);
        }
        private void onCirclize(object s, EventArgs e)
        {
            _AcAp.Application.DocumentManager.MdiActiveDocument.SendStringToExecute("_CIRCLIZE\n", true, false, true);
        }
    }

    public class PointGripOverrule : _AcDb.GripOverrule
    {
        private System.Collections.Generic.Dictionary<_AcDb.Entity, _AcDb.GripDataCollection> _gripDataCache;
        private void clearGripData(_AcDb.Entity ent)
        {
            if (_gripDataCache == null)
                return;
            _AcDb.GripDataCollection collection;
            if (_gripDataCache.TryGetValue(ent, out collection))
            {
                _gripDataCache.Remove(ent);
                collection.Dispose();
            }
        }
        private void addGripData(_AcDb.Entity ent, MultiModePointGripData data)
        {
            if (_gripDataCache == null)
                _gripDataCache = new System.Collections.Generic.Dictionary<_AcDb.Entity, _AcDb.GripDataCollection>(1);
            _AcDb.GripDataCollection collection;
            if (!_gripDataCache.TryGetValue(ent, out collection))
            {
                collection = new _AcDb.GripDataCollection();
                _gripDataCache.Add(ent, collection);
            }
            collection.Add(data);
        }

        public override bool IsApplicable(RXObject overruledSubject)
        {
            return true;
        }
        public override void GetGripPoints(_AcDb.Entity entity, _AcDb.GripDataCollection grips, double curViewUnitSize, int gripSize, _AcGe.Vector3d curViewDir, _AcDb.GetGripPointsFlags bitFlags)
        {
            _AcDb.DBPoint point = entity as _AcDb.DBPoint;
            MultiModePointGripData data = new MultiModePointGripData(point.Position);
            addGripData(entity, data);
            grips.Add(data);
        }
        public override void MoveGripPointsAt(_AcDb.Entity entity, _AcDb.GripDataCollection grips, _AcGe.Vector3d offset, _AcDb.MoveGripPointsFlags bitFlags)
        {
            entity.TransformBy(_AcGe.Matrix3d.Displacement(offset));
        }
        public override void OnGripStatusChanged(_AcDb.Entity entity, _AcDb.GripStatus status)
        {
            if (status == _AcDb.GripStatus.GripsToBeDeleted)
                clearGripData(entity);
            base.OnGripStatusChanged(entity, status);
        }
    }

    public class ThreadIdColorDrawOverrule : _AcGi::DrawableOverrule
    {
        public override bool WorldDraw(Drawable drawable, WorldDraw wd)
        {
            wd.SubEntityTraits.Color = (short)System.Threading.Thread.CurrentThread.ManagedThreadId;
            return base.WorldDraw(drawable, wd);
        }
    }

    public class ForceSingleThreadedDrawOverrule : _AcGi::DrawableOverrule
    {
        public override AdvancedSupportFlags RegenSupportFlags(_AcGi.Drawable drawable)
        {
            return AdvancedSupportFlags.None; //disable all multi-threaded rendering support
        }
    }
}
