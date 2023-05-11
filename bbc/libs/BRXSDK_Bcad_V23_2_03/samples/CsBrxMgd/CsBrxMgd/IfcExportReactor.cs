using Bricscad.Ifc;
using _AcDb = Teigha.DatabaseServices;
using _AcAp = Bricscad.ApplicationServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;

namespace CsBrxMgd
{
    class IfcExportReactor : IFCExportReactor
    {
        private static IfcExportReactor _instance = new IfcExportReactor();
        public IfcExportReactor() : base("86EF4C9E-7E20-48D1-AC34-ABC8BEF6CB8E", "CsBrxMgd")
        { }

        public override void OnBeginIfcModelSetup(ExportContext context)
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            editor.WriteMessage("OnBeginIfcModelSetup called\n");
        }

        public override void OnEndIfcModelSetup(ExportContext context)
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            editor.WriteMessage("OnEndIfcModelSetup called\n");
        }

        public override IfcEntity OnEntity(ExportContext context, _AcDb.Entity entity)
        {
            if (entity.Color.ColorIndex != 51)
                return null; // default export

            var ifcModel = context.GetIfcModel();
            var furnishing = IfcEntity.Create(ifcModel, IfcEntityDesc.IfcFurnishingElement);
            context.SetIfcRootData(furnishing, "Special Chair", "custom made", "{3F2504E0-4F89-41D3-9A0C-0305E82C3301}", null);
            context.SetRepresentationAsBrep(furnishing, entity);
            context.SetLocationRelToAssignedSpatialLocation(furnishing, entity, _AcGe.Matrix3d.Identity);
            context.SetMaterialToAssignedComposition(furnishing, entity, 0);
            return furnishing;
        }

        public static void Register()
        {
            if (_instance.AttachReactor())
            {
                _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
                editor.WriteMessage("IfcExportReactor attached\n");
            }
        }

        public static void Unregister()
        {
            if (_instance.DetachReactor())
            {
                _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
                editor.WriteMessage("IfcExportReactor detached\n");
            }
        }
    }
}
