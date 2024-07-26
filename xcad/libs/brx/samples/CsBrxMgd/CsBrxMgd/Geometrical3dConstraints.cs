using System;
using System.Collections.Specialized;
using System.Collections.Generic;
using Bricscad.ApplicationServices;
using Bricscad.EditorInput;
using Bricscad.Constraints3d;
using Teigha.DatabaseServices;
using Teigha.Runtime;
using Teigha.Geometry;

namespace CsBrxMgd
{
    //---------------------------------------------------------------------------------------
    // Assoc3dVariable class holds the constraints parameter for a single 3D constraint
    // Geometrical3dConstraint class represents a 3D constraint
    // Assoc3dConstraintGroup class represents the 3D constraints group of a block table record
    // Assoc3dNetwork class used to managed block reference constraints
    public class Bricscad3dGeoContr
    {
        //---------------------------------------------------------------------------------------
        // Select a block reference with geometrical constraints added. For this example was used
        // a block reference having Parameters H, W, D
        static public void Geometrical3dConstraintsBlockReference()
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
                    Assoc3dNetwork Assoc3dNetwork = new Assoc3dNetwork();
                    StringCollection parameterNames = Assoc3dNetwork.Get3dComponentParametersNames(per.ObjectId);
                    foreach (String value in parameterNames)
                    {
                        ed.WriteMessage("\nParamenter Name is {0}", value);
                    }
                    ComponentParameter par = Assoc3dNetwork.Get3dComponentParameter(per.ObjectId, "W");
                    resValue = par.Value;
                    expr = par.Expression;
                    par.Expression = "100";

                    Database dataB = new Database(true, true);
                    Assoc3dConstraintGroup[] a3DConstrGr = Assoc3dNetwork.GetAll3dConstraintsGroups(db);
                    foreach (Assoc3dConstraintGroup val in a3DConstrGr)
                    {
                        ed.WriteMessage("\nAssoc3dConstraintGroup ID is {0}", val.BlockId);
                    }

                    BlockTableRecord btr = (BlockTableRecord)tr.GetObject(br.BlockTableRecord, OpenMode.ForRead);

                    Assoc3dConstraintGroup Constr = Assoc3dNetwork.Get3dConstraintsGroup(btr.Id, false);
                    ObjectId oId = Constr.BlockId;
                    bool has = Constr.HasSketchPlane;
                    bool trans = Constr.Transient;
                    Plane plane = Constr.SketchPlane;
                    Geometrical3dConstraint[] ar = Constr.Constraints;
                    foreach (Geometrical3dConstraint value in ar)
                    {
                        ed.WriteMessage("\nThe name is {0}", value.Name);
                        Assoc3dVariable ass = value.Parameter;
                        ed.WriteMessage("\nAssoc3dVariable name is {0}", ass.Name);
                        ed.WriteMessage("\nAssoc3dVariable value is {0}", ass.Value);
                        Geometrical3dConstraint.ConstraintType type = value.Type;
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
        // Select a Solid3d. For this example was used Box
        static public void Geometrical3dConstraintsSolid3d()
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
                Assoc3dConstraintGroup assGr = Assoc3dNetwork.Get3dConstraintsGroup(btRecord.Id, true);

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

                Geometrical3dConstraint geoConstr = assGr.AddConstraint(Geometrical3dConstraint.ConstraintType.Distance, fsp);
                if (geoConstr == null)
                {
                    ed.WriteMessage("\nCannot create constraint, not supported types of faces");
                    return;
                }

                geoConstr.Name = "Distance_Constraint";

                Assoc3dVariable assVar = Assoc3dVariable.GetByName(btRecord.Id, "Distance_Constraint", false);
                string name = assVar.Name;

                Assoc3dVariable[] assVarAr = Assoc3dVariable.GetFromBlock(btRecord.Id);
                foreach (Assoc3dVariable var in assVarAr)
                {
                    ed.WriteMessage("\nAssoc3dVariable name is {0}", var.Name);
                    ed.WriteMessage("\nAssoc3dVariable BlockId is {0}", var.BlockId);
                    ed.WriteMessage("\nAssoc3dVariable Expression is {0}", var.Expression);
                    ed.WriteMessage("\nAssoc3dVariable Value is {0}", var.Value);
                }

                FullSubentityPath[] constrFSP = geoConstr.Arguments;
                ObjectId constrBlockId = geoConstr.BlockId;
                Geometrical3dConstraint.ConstraintType constrType = geoConstr.Type;
                Assoc3dVariable constrParameter = geoConstr.Parameter;
                bool isD = geoConstr.IsDimensional;
                string constrName = geoConstr.Name;
                Tx.Commit();
            }
        }
    };
}

