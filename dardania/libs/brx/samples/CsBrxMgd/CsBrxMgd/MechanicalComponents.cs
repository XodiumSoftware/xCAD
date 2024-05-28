// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Bricscad.ApplicationServices;
using Teigha.DatabaseServices;
using Bricscad.EditorInput;
using Bricscad.MechanicalComponents;


namespace CsBrxMgd
{
    class MechanicalComponents
    {
        //---------------------------------------------------------------------------------------
        // Select a block reference with mechanical commponent added. For this example was used
        // a block reference having Component Insert: Name, Component Name, Description, BOM Status.

        static public void RetrieveComponentName()
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            Editor ed = doc.Editor;
            Transaction tr = db.TransactionManager.StartTransaction();

            using (tr)
            {
                PromptEntityOptions peo = new PromptEntityOptions("\nSelect a block reference:");
                peo.SetRejectMessage("\nEntity is not a block.");
                peo.AddAllowedClass(typeof(BlockReference), false);
                PromptEntityResult per = ed.GetEntity(peo);

                if (per.Status != PromptStatus.OK)
                    return;

                BlockReference br = null;
                br = tr.GetObject(per.ObjectId, OpenMode.ForRead) as BlockReference;
                ObjectId id = br.ObjectId;

                using (ComponentInstance componentInstance = ComponentInstance.GetComponentInstance(id))
                {
                    if (componentInstance == null)
                    {
                        ed.WriteMessage("\nThe selected block doesn't contain MechanicalComponents");
                        return;
                    }

                    using (ComponentDefinition componentDefinition = ComponentDefinition.GetComponentDefinition(componentInstance.InstanceBlockId, false))
                    {
                        string compName = componentInstance.Name;
                        string compDefName = componentDefinition.Name;
                        string compStatus = componentDefinition.BomStatus.ToString();
                        string compDescription = componentDefinition.Description;

                        ed.WriteMessage("\nThe component name of the block reference with id={0} is {1}; " +
                                        "\ncomponentDefinitionName: {2};" +
                                        "\ncomponent type: {3};" +
                                        "\ncomponent status: {4};" +
                                        "\ncomponent description: {5};" +
                                        "\ncomponent file status: {6}",
                                        id, compName,
                                        compDefName,
                                        componentDefinition.ComponentType,
                                        compStatus,
                                        compDescription,
                                        componentDefinition.FileStatus);
                    }
                }

                tr.Commit();

            }

        }

    }
}
