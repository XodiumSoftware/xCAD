using System;
using System.Collections.Specialized;
using System.Collections.Generic;
using Bricscad.ApplicationServices;
using Bricscad.EditorInput;
using Bricscad.Parametric;
using Teigha.DatabaseServices;
using Teigha.Runtime;
using Teigha.Geometry;

namespace CsBrxMgd
{
    //---------------------------------------------------------------------------------------
    // Utility class used to managed block reference constraints
    // ConstraintsGroup3d class represents a group of 3D constraints for a given block table record
    // Constraint3d class represents a 3D constraint
    // Parameter class holds the constraints parameter for a single 3D constraint
    public class Constraints3dSample
    {
        //---------------------------------------------------------------------------------------
        // Select a block reference with geometrical constraints added. For this example was used
        // a block reference having Parameters H, W, D
        static public void Constraints3dBlockReference()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;

            PromptStringOptions pso = new PromptStringOptions("\nEnter block name or press enter to select: ");
            pso.AllowSpaces = true;
            PromptResult pr = ed.GetString(pso);

            if (pr.Status != PromptStatus.OK)
                return;

            Transaction tr = db.TransactionManager.StartTransaction();
            using (tr)
            {
                BlockReference br = null;

                if (pr.StringResult == "")
                {
                    PromptEntityOptions peo = new PromptEntityOptions("\nSelect a block reference: ");
                    peo.SetRejectMessage("\nEntity is not a block.");
                    peo.AddAllowedClass(typeof(BlockReference), false);
                    PromptEntityResult per = ed.GetEntity(peo);

                    if (per.Status != PromptStatus.OK)
                        return;

                    br = tr.GetObject(per.ObjectId, OpenMode.ForRead) as BlockReference;

                    double resValue;
                    String expr;
                    StringCollection parameterNames = Utility.GetBlockParameterNames(per.ObjectId);
                    foreach (String value in parameterNames)
                    {
                        ed.WriteMessage("\nParamenter Name is {0}", value);
                    }
                    BlockParameter par = Utility.GetBlockParameter(per.ObjectId, "W");
                    resValue = par.Value;
                    expr = par.Expression;
                    par.Expression = "100";

                    Database dataB = new Database(true, true);
                    ConstraintsGroup3d[] groupArr = Utility.GetAllConstraintsGroups3d(db);
                    foreach (ConstraintsGroup3d gr in groupArr)
                    {
                        ed.WriteMessage("\nConstraint3dGroup ID is {0}", gr.BlockId);
                    }

                    BlockTableRecord btr = (BlockTableRecord)tr.GetObject(br.BlockTableRecord, OpenMode.ForRead);

                    ConstraintsGroup3d constraintGr = Utility.Get3dConstraintsGroup(btr.Id, false);
                    ObjectId oId = constraintGr.BlockId;
                    bool has = constraintGr.HasSketchPlane;
                    bool trans = constraintGr.Transient;
                    Plane plane = constraintGr.SketchPlane;
                    Constraint3d[] ar = constraintGr.Constraints;
                    foreach (Constraint3d value in ar)
                    {
                        ed.WriteMessage("\nThe name is {0}", value.Name);
                        Parameter parameter = value.Parameter;
                        ed.WriteMessage("\nAssoc3dVariable name is {0}", parameter.Name);
                        ed.WriteMessage("\nAssoc3dVariable value is {0}", parameter.Value);
                        ConstraintType type = value.Type;
                        FullSubentityPath[] arguments = value.Arguments;
                        foreach (FullSubentityPath val in arguments)
                        {
                            ObjectId[] ids = val.GetObjectIds();
                            foreach (ObjectId valId in ids)
                            {
                                ed.WriteMessage("\nThe Ids {0}", valId.ToString());
                            }
                        }
                        ed.WriteMessage("\nThe value type is {0}", type);
                        uint nodeId = value.NodeId;
                    }
                }
                tr.Commit();
            }
        }

        //---------------------------------------------------------------------------------------
        // Select a pair of faces and create the Distance constraint between them
        static public void Constraints3dDistanceBetweenFaces()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;

            PromptSelectionOptions pso = new PromptSelectionOptions();
            pso.MessageForAdding = "\nSelect two faces to create distance constraint: ";
            pso.AllowSubSelections = true;
            PromptSelectionResult psr = ed.GetSelection(pso);

            if (psr.Status != PromptStatus.OK)
            {
                ed.WriteMessage("\nInvalid input");
                return;
            }

            using (Transaction Tx = db.TransactionManager.StartTransaction())
            {
                BlockTableRecord btRecord = (BlockTableRecord)Tx.GetObject(SymbolUtilityServices.GetBlockModelSpaceId(db), OpenMode.ForRead);
                ConstraintsGroup3d constraintGr = Utility.Get3dConstraintsGroup(btRecord.Id, true);

                FullSubentityPath[] fsp = new FullSubentityPath[2];
                int index = 0;
                foreach (SelectedObject obj in psr.Value)
                {
                    var subents = obj.GetSubentities();
                    if (subents.Length == 0)
                    {
                        ed.WriteMessage("\nInvalid input, faces should be selected");
                        return;
                    }

                    foreach (SelectedSubObject subobj in obj.GetSubentities())
                    {
                        if (index >= 2)
                        {
                            ed.WriteMessage("\nInvalid input, more than two faces were selected");
                            return;
                        }

                        if (subobj.FullSubentityPath.SubentId.Type != SubentityType.Face)
                        {
                            ed.WriteMessage("\nInvalid input, faces should be selected");
                            return;
                        }

                        fsp[index++] = subobj.FullSubentityPath;
                    }
                }

                if (index != 2)
                {
                    ed.WriteMessage("\nInvalid input, less than two faces were selected");
                    return;
                }

                Constraint3d geoConstr = constraintGr.AddConstraint(ConstraintType.Distance, fsp);
                if (geoConstr == null)
                {
                    ed.WriteMessage("\nCannot create constraint, not supported types of faces");
                    return;
                }

                geoConstr.Name = "Distance_Constraint";

                Parameter distanceParameter = Parameter.GetByName(btRecord.Id, "Distance_Constraint", false);
                string name = distanceParameter.Name;

                Parameter[] parameters = Parameter.GetFromBlock(btRecord.Id);
                foreach (Parameter p in parameters)
                {
                    ed.WriteMessage("\nAssoc3dVariable name is {0}", p.Name);
                    ed.WriteMessage("\nAssoc3dVariable BlockId is {0}", p.BlockId);
                    ed.WriteMessage("\nAssoc3dVariable Expression is {0}", p.Expression);
                    ed.WriteMessage("\nAssoc3dVariable Value is {0}", p.Value);
                }

                FullSubentityPath[] constrFSP = geoConstr.Arguments;
                ObjectId constrBlockId = geoConstr.BlockId;
                ConstraintType constrType = geoConstr.Type;
                Parameter pr = geoConstr.Parameter;

                // testing bounds
                ed.WriteMessage("\nTesting the bounds");
                ed.WriteMessage("\nby default the parameter should not have bounds ... ");

                if (pr.HasLowerBound || pr.HasUpperBound)
                {
                  ed.WriteMessage("error!");
                }
                else
                {
                    ed.WriteMessage("OK");
                    ed.WriteMessage("\nsetting the lower bound ... ");
                    pr.LowerBound = pr.Value * 0.9;
                    if (!pr.HasLowerBound)
                    {
                        ed.WriteMessage("error!");
                    }
                    else
                    {
                        ed.WriteMessage("set to {0}", pr.Value * 0.9);
                        ed.WriteMessage("\nsetting the upper bound ... ");
                        pr.UpperBound = pr.Value * 1.2;
                        if (!pr.HasUpperBound)
                        {
                            ed.WriteMessage("error!");
                        }
                        else
                        {
                            ed.WriteMessage("set to {0}", pr.Value * 1.2);
                            ed.WriteMessage("\ntrying to unset the lower bound ... ");
                            pr.UnsetLowerBound();
                            if (pr.HasLowerBound)
                            {
                                ed.WriteMessage("error!");
                            }
                            else
                            {
                                ed.WriteMessage("OK");
                            }
                        }
                    }
                }

                Tx.Commit();
            }
        }

        //---------------------------------------------------------------------------------------
        // create the distance constraint between World Coordinate System object (Y axis) and some selected object
        static public void Constraints3dDistanceToCoordinateSystemObject()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;

            // prompt a user to select the first argument
            FullSubentityPath firstArgument = new FullSubentityPath();
            {
                bool isFirstArgumentSelected = false;
                PromptSelectionOptions pso = new PromptSelectionOptions();
                pso.MessageForAdding =
                    "\nSelect the first argument of the distance constraint: face, edge, or vertex: ";
                pso.SingleOnly = true;
                pso.AllowSubSelections = true;
                PromptSelectionResult psr = ed.GetSelection(pso);

                if (psr.Status == PromptStatus.OK && psr.Value.Count > 0)
                {
                    SelectedObject selObj = psr.Value[0];
                    if (selObj.GetSubentities() != null)
                    {
                        firstArgument = selObj.GetSubentities()[0].FullSubentityPath;
                    }
                    else
                    {
                        // some teigha object selected, e.g. POINT, LINE,  ARC, etc.
                        ObjectId[] objIDs = new ObjectId[] { psr.Value[0].ObjectId };
                        firstArgument = new FullSubentityPath(objIDs, SubentityId.Null);
                    }

                    isFirstArgumentSelected = true;
                }

                if (!isFirstArgumentSelected)
                {
                    ed.WriteMessage("\nInvalid input");
                    return;
                }
            }

            using (Transaction Tx = db.TransactionManager.StartTransaction())
            {
                ConstraintArgument[] arguments =
                    new ConstraintArgument[] { new ConstraintArgument(firstArgument),
                                               new ConstraintArgument(CoordinateSystemObject.Y) };

                ed.WriteMessage("\nUsing {0} as the second constraint argument", arguments[1].CoordinateSystemObject);
                

                BlockTableRecord btRecord =
                    (BlockTableRecord)Tx.GetObject(SymbolUtilityServices.GetBlockModelSpaceId(db), OpenMode.ForRead);
                ConstraintsGroup3d constraintGr = Utility.Get3dConstraintsGroup(btRecord.Id, true);

                Constraint3d constraint = constraintGr.AddConstraint(ConstraintType.Distance, arguments);
                if (constraint == null)
                {
                    ed.WriteMessage("\nFailed to create the distance constraint");
                    return;
                }

                ed.WriteMessage("\nThe distance name is {0}", constraint.Name);
                ed.WriteMessage("\nThe distance node ID is {0}", constraint.NodeId);
                ed.WriteMessage("\nThe distance value is {0}", constraint.Parameter.Value);
                Tx.Commit();
            }
        }

        //---------------------------------------------------------------------------------------
        // create the distance constraint from World Origin to the boundary of the selected face
        static public void Constraints3dDistanceToFaceBoundary()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;

            // prompt a user to select face
            FullSubentityPath faceArgument = new FullSubentityPath();
            {
                bool isFaceSelected = false;
                PromptSelectionOptions pso = new PromptSelectionOptions();
                pso.MessageForAdding = "\nSelect the cylindrical, toroidal, conical, or spherical face:";
                pso.SingleOnly = true;
                pso.AllowSubSelections = true;
                PromptSelectionResult psr = ed.GetSelection(pso);

                if (psr.Status == PromptStatus.OK && psr.Value.Count > 0)
                {
                    SelectedObject selObj = psr.Value[0];
                    if (selObj.GetSubentities() != null)
                    {
                        SelectedSubObject subObj = selObj.GetSubentities()[0];
                        faceArgument = subObj.FullSubentityPath;
                        if (faceArgument.SubentId.Type == SubentityType.Face)
                            isFaceSelected = true;
                    }
                }

                if (!isFaceSelected)
                {
                    ed.WriteMessage("\nInvalid input");
                    return;
                }
            }

            using (Transaction Tx = db.TransactionManager.StartTransaction())
            {
                ConstraintArgument[] arguments =
                    new ConstraintArgument[] { new ConstraintArgument(CoordinateSystemObject.Origin),
                                               new ConstraintArgument(faceArgument) };

                ed.WriteMessage("\nUsing {0} as another constraint argument", arguments[0].CoordinateSystemObject);

                BlockTableRecord btRecord =
                    (BlockTableRecord)Tx.GetObject(SymbolUtilityServices.GetBlockModelSpaceId(db), OpenMode.ForRead);
                ConstraintsGroup3d constraintGr = Utility.Get3dConstraintsGroup(btRecord.Id, true);

                Constraint3d constraint = constraintGr.AddConstraint(ConstraintType.Distance, arguments);
                if (constraint == null)
                {
                    ed.WriteMessage("\nFailed to create the distance constraint");
                    return;
                }

                ed.WriteMessage("\nThe distance name is {0}", constraint.Name);
                ed.WriteMessage("\nThe distance node ID is {0}", constraint.NodeId);
                ed.WriteMessage("\nThe distance value is {0}", constraint.Parameter.Value);

                const uint faceArgId = 1;

                ed.WriteMessage("\nBy default the measurement mode of the face argument is {0}",
                                constraint.get_Measurement(faceArgId));

                constraint.set_Measurement(faceArgId, MeasurementMode.Boundary);
                ed.WriteMessage("\nChanged the measurement mode to {0}", constraint.get_Measurement(faceArgId));
                ed.WriteMessage("\nThe new distance value is {0}", constraint.Parameter.Value);

                Tx.Commit();
            }
        }
    };
}

