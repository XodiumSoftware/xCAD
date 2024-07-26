// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

using Bricscad.Ifc;
using _AcDb = Teigha.DatabaseServices;
using _AcAp = Bricscad.ApplicationServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;
using System.Collections.Generic;
using System;

namespace CsBrxMgd
{
    class IfcImportReactor : IFCImportReactor
    {
        private static IfcImportReactor _instance;
        private int _numberOfWalls = 0;
        private List<IfcEntity> _ifcWalls = new List<IfcEntity>();
        const string AppName = "CsBrxMgd";
        public IfcImportReactor() : base("FB5D55DD-C187-4DA7-B70F-D8EAF2E02650", AppName)
        {
        }
        public override bool OnIfcProduct(ImportContext context, IfcEntity product, bool isParent, IfcEntity parentProduct)
        {
            if (product.IsKindOf(IfcEntityDesc.IfcWall))
            {
                ++_numberOfWalls;
                _ifcWalls.Add(product);
            }
            return false; //use default import
        }
        public override void OnStart(ImportContext context, IfcEntity project, ImportInfo info)
        {
            CreateRegApp(context);
            object projName;
            project.GetAttribute(IfcAttribute.Name, out projName);
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            editor.WriteMessage($"\nImport of the project \"{(projName as IfcString).GetString()}\" is started");
        }
        public override void BeforeCompletion(ImportContext context, bool success)
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            editor.WriteMessage($"\nNumber of imported walls: {_numberOfWalls}");
            //Write IfcWall.Tag into XData
            foreach (var ifcWall in _ifcWalls)
            {
                _AcDb.Entity ent;
                if (context.GetEntity(out ent, ifcWall))
                {
                    object tag;
                    if (IfcResult.Ok == ifcWall.GetAttribute(IfcAttribute.Tag, out tag))
                    {
                        var tagVal = (tag as IfcString).GetString();
                        _AcDb.ResultBuffer rb =
                          new _AcDb.ResultBuffer(
                            new _AcDb.TypedValue(Convert.ToInt32(_AcDb.DxfCode.ExtendedDataRegAppName), AppName),
                            new _AcDb.TypedValue(Convert.ToInt32(_AcDb.DxfCode.ExtendedDataAsciiString), tagVal)
                          );
                        ent.XData = rb;
                        rb.Dispose();
                        ent.Dispose();
                    }
                }
            }
        }
        private void CreateRegApp(ImportContext context)
        {
            //var db = CurrentContext -> GetDatabase();
            var db = context.GetDatabase();
            using (var tr = db.TransactionManager.StartTransaction())
            {
                var regTable = tr.GetObject(db.RegAppTableId, _AcDb.OpenMode.ForRead) as _AcDb.RegAppTable;
                if (!regTable.Has(AppName))
                {
                    regTable.UpgradeOpen();
                    using (var app = new _AcDb.RegAppTableRecord { Name = AppName })
                    {
                        regTable.Add(app);
                        tr.AddNewlyCreatedDBObject(app, true);
                    }
                }
            }
        }
        public static void Register()
        {
            if (_instance != null)
                _instance.DetachReactor();
            _instance = new IfcImportReactor { Ifc2x3Enabled = true }; // only for Ifc2x3
            if (_instance.AttachReactor())
            {
                _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
                editor.WriteMessage("IfcImportReactor attached\n");
            }
        }
        public static void Unregister()
        {
            if (_instance != null && _instance.DetachReactor())
            {
                _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
                editor.WriteMessage("IfcImportReactor detached\n");
            }
            _instance = null;
        }
    }
}
