using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcTrx = Teigha.Runtime;
using _AcEd = Bricscad.EditorInput;
using _AcHlr = Bricscad.Hlr;

namespace CsBrxMgd
{
    class HlrSample
    {
        public static _AcDb.ObjectId makePolyFaceMesh(_AcGe.Point3d position, _AcGe.Vector3d axis, double radius, short sides)
        {
            _AcAp.Document doc = _AcAp.Application.DocumentManager.MdiActiveDocument;
            _AcDb.Database db = doc.Database;

            _AcGe.Point3d startPoint = position;
            _AcGe.Point3d endPoint = position + axis;
            double rang = 2 * Math.PI / sides;
            _AcGe.Vector3d perpDirection = radius * axis.GetPerpendicularVector().GetNormal();

            _AcGe.Point3dCollection pntCollection = new _AcGe.Point3dCollection();
            for (short index = 0; index < sides; ++index)
            {
                _AcGe.Vector3d tVec = perpDirection;
                _AcGe.Vector3d rotateVec = tVec.RotateBy(index * rang, axis);
                pntCollection.Add(startPoint + rotateVec);
                pntCollection.Add(endPoint + rotateVec);
            }

            _AcDb.ObjectId resultId;
            using (_AcDb.Transaction tr = db.TransactionManager.StartTransaction())
            {
                _AcDb.BlockTableRecord currentSpace = tr.GetObject(db.CurrentSpaceId, _AcDb.OpenMode.ForWrite) as _AcDb.BlockTableRecord;
                using (_AcDb.PolyFaceMesh polyFace = new _AcDb.PolyFaceMesh())
                {
                    polyFace.SetDatabaseDefaults(db);
                    resultId = currentSpace.AppendEntity(polyFace);
                    tr.AddNewlyCreatedDBObject(polyFace, true);

                    foreach (_AcGe.Point3d pnt in pntCollection)
                    {
                        _AcDb.PolyFaceMeshVertex faceVertex = new _AcDb.PolyFaceMeshVertex(pnt);
                        polyFace.AppendVertex(faceVertex);
                        tr.AddNewlyCreatedDBObject(faceVertex, true);
                    }

                    for (short index = 1; index <= sides; ++index)
                    {
                        short firstVert = (short)(2 * (index - 1) + 1);
                        short v0 = (short)(firstVert + 0);
                        short v1 = (short)(firstVert + 1);
                        short v2 = (short)((index < sides) ? firstVert + 3 : 2);
                        short v3 = (short)((index < sides) ? firstVert + 2 : 1);

                        using (_AcDb.FaceRecord faceRecord = new _AcDb.FaceRecord(v0, v1, v2, v3))
                        {
                            polyFace.AppendFaceRecord(faceRecord);
                            tr.AddNewlyCreatedDBObject(faceRecord, true);
                        }
                    }
                }

                tr.Commit();
            }
            return resultId;
        }

        // Generates 8-sided 'cylinder' and runs HLR
        public static void GenerateHlrLines()
        {
            _AcAp.Document doc = _AcAp.Application.DocumentManager.MdiActiveDocument;
            _AcEd.Editor ed = doc.Editor;
            _AcDb.ObjectId polyFaceMeshId = makePolyFaceMesh(_AcGe.Point3d.Origin, _AcGe.Vector3d.XAxis * 100, 60, 8);
            ed.Command("_VPOINT", "-1.0, -1.0, 2.0");

            using (_AcHlr.HlrCollector hlrCollector = new _AcHlr.HlrCollector() { DeleteState = true })
            {
                hlrCollector.AddEntity(polyFaceMeshId);

                _AcGe.Point3d pointViewDirection = (_AcGe.Point3d)_AcAp.Application.GetSystemVariable("VIEWDIR");
                _AcGe.Vector3d currentUcsDir = pointViewDirection.TransformBy(ed.CurrentUserCoordinateSystem).GetAsVector();
                _AcGe.Point3d targetVar = (_AcGe.Point3d)_AcAp.Application.GetSystemVariable("TARGET");
                targetVar = targetVar.TransformBy(ed.CurrentUserCoordinateSystem);

                using (_AcHlr.HlrEngine hlrEngine = new _AcHlr.HlrEngine(targetVar, currentUcsDir, _AcHlr.HlrControl.Entity | _AcHlr.HlrControl.Block | _AcHlr.HlrControl.Subentity |
                    _AcHlr.HlrControl.ShowAll | _AcHlr.HlrControl.MeshSilhouettes | _AcHlr.HlrControl.Progress))
                {
                    _AcTrx.ErrorStatus resultStatus = hlrEngine.Run(hlrCollector);
                    if (resultStatus != _AcTrx.ErrorStatus.OK)
                        return;
                    _AcDb.Database db = doc.Database;
                    using (_AcDb.Transaction tr = db.TransactionManager.StartTransaction())
                    {
                        _AcDb.BlockTableRecord currentSpace = tr.GetObject(db.CurrentSpaceId, _AcDb::OpenMode.ForWrite) as _AcDb.BlockTableRecord;
                        int collectorLength = hlrCollector.OutputDataLength;
                        for (int idx = 0; idx < collectorLength; idx++)
                        {
                            using (_AcHlr.HlrData hlrData = hlrCollector.OutputData(idx))
                            {
                                _AcDb.Entity resultEntity = hlrData.ResultEntity;
                                _AcHlr.Visibility entityVisibility = hlrData.EntityVisibility;
                                if (entityVisibility == _AcHlr.Visibility.Visible)
                                    resultEntity.ColorIndex = 4;
                                else if (entityVisibility == _AcHlr.Visibility.InternallyHidden)
                                {
                                    if (hlrData.HlrVisibility == _AcHlr.Visibility.Visible)
                                        resultEntity.ColorIndex = 6;
                                    else
                                        resultEntity.ColorIndex = 52;
                                }
                                else
                                    resultEntity.ColorIndex = 11;

                                currentSpace.AppendEntity(resultEntity);
                                tr.AddNewlyCreatedDBObject(resultEntity, true);
                            }
                        }
                        tr.Commit();
                    }
                }
            }
        }
    }
}
