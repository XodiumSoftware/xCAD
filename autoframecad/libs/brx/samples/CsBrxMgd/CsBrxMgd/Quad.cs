// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

using System;
using System.Collections.Specialized;
using System.Collections.Generic;

using Bricscad.ApplicationServices;
using Bricscad.EditorInput;
using Bricscad.Quad;
using Bricscad.Windows;

using Teigha.DatabaseServices;
using Teigha.Runtime;
using Teigha.Geometry;
//---------------------------------------------------------------------------------------
/*
Specifying icons :
==================
"iconId"                        : one of the builtin icon IDs (visible in the Customize dialog)
"icon16id|icon32id"             : a different ID for small and large icon (separated with '|' char)
"iconfile.png"                  : a bitmap file name (with or without path)
"icon16file.png|icon32file.png" : two bitmap file names, small and large (with or without path)
"resName[iconid]"               : resName is the name of a resource DLL in which the icon can be found
"resName[icon16id|icon32id]"    : resName is the name of a resource DLL in which both icons can be found
                                  (resName is usually the same as the CUI menugroup name)
"(abbreviation)"                : abbreviation is a short text (1 to 3 chars) that will be drawn in a circle


Specifying command strings and passing selection sets :
=======================================================

* command is usually specified as ^C^CCOMMANDNAME followed by additional parameters if any.
  The syntax is the same as that used when menu macros are specified. In addition,

* If the command string does not contain a ^S, the pickfirst set (pre-selected/grip set), if any,
  is fed to the command.
  If the cursor is hovering on a selection thats not in the pickfirst set, that will also get appended
  to the pickfirst set, and the combined set fed to the command.
  Note : this works only for commands which accept pickfirst sets.

* Commands that dont accept pickfirst sets can still use pickfirst/hovered sets by specifying a ^S in
  the command string, and keeping selection sets NULL in AcEdQuadItems::append() for that particular
  command.
  Then, the combined set consisting of hovered and picked first set (if any) will be fed to the command.
  For example, "^c^c_offset;^S;".
  Note : however this is the users responsibility to select the correct selection set while executing this
  macro from the Quad, else the command may give unexpected results.

* If finer control is desired, ppSSet1, ppSSet2 and ppSSet3 can be populated and passed.
  However, one selection set per ^S is expected in this case.
  Example, "^c^c_GCFIX;_E;^S" with ppSSet1 non-NULL, ppSSet2 and ppSSet3 NULL, or
           "^c^c_GCSYMMETRIC;^S;^S;^S" with all three non-NULL.
  Note : currently, a maximum of 3 selection sets can be passed.
*/

namespace CsBrxMgd
{
    //---------------------------------------------------------------------------------------
    // This is the main Quad-related class : a client module will need to derive from AcEdQuadReactor,
    // and register the reactor instance via acedQuadReactorManager()->addQuadReactor();
    // communication between Quad management and client application (incl. extension of the Quad cursor/menu)
    // is processed via reactor callbacks.
    // During 'registerQuadItems()' callback, the client application should declare all its available, and
    // potentially used, Quad items.
    // Whenever the Quad menu/cursor is about to be displayed, the client reactor is asked for items, which
    // shall be shown : 'appendQuadItems()' is then called, providing informations about actually selected
    // and/or hovered entities, subentities and boundaries, and client application can add items to be shown.
    public class MyQuad : QuadReactor
    {
        public MyQuad() { }

        // The display name will be shown to users in the UI for identifying/enabling/disabling/
        // prioritising your reactor.
        public override string displayName()
        {
            return "MyQuad";
        }

        // The GUID has to be a globally unique identifier (use VS201x->Tools->CreateGUID, "guidgen.exe")
        // and will be used to internally identify the reactor across sessions, releases and
        // different third party applications, so it should always be the same for this reactor. 
        // Therefore, once a reactor is published by a developer, its GUID should NEVER be changed.
        // Note : any string format from "CreateGUID" / "guidgen.exe" is accepted, suggested format
        //        is like "C2160591-FC06-4A74-A9B8-2E28635279BA" (not brackets)
        public override string GUID()
        {
            return "406F88BD-E123-4296-9CAA-EF2EAEC88012";
        }

        // This function is called when the no-selection Quad is to be shown.
        // Add selection-independent items in this function.
        public override bool appendQuadItems(QuadItems quadItems)
        {
            bool bs = quadItems.append("id_5", null, null, null);
            return bs;
        }

        bool collectEntities(out List<FullSubentityPath> arrEnts, QuadSelectionData data, RXClass entClass, QuadSelectionData.SelectedType etype, bool allowDerived)
        {
            Document doc = Application.DocumentManager.MdiActiveDocument;
            Database db = doc.Database;
            arrEnts = new List<FullSubentityPath>();

            if (!data.isValid())
                return false;
            if (data.hasTypes() == 0 & etype == 0)
                return false;

            bool validType = false;
            DBObject pObject = null;
            ObjectIdCollection id = new ObjectIdCollection();
            List<ObjectId> objIds = new List<ObjectId>();
            FullSubentityPath path = new FullSubentityPath();
            SubentityId emptySubentId = new SubentityId(SubentityType.Null, System.IntPtr.Zero);

            uint numEntries = data.length();
            for (uint i = 0; i < numEntries; ++i)
            {
                QuadSelectionData.SelectedType selType = data.typeAt(i);
                if (selType != etype)
                    continue;
                switch (selType)
                {
                    case QuadSelectionData.SelectedType.Entity:
                        objIds.Add((ObjectId)data.entityAt(i));
                        path = new FullSubentityPath(objIds.ToArray(), emptySubentId);
                        break;

                    case QuadSelectionData.SelectedType.Subent:
                        path = data.subentAt(i);
                        objIds.Add((ObjectId)path.GetObjectIds().GetValue(0));
                        break;

                }

                ObjectId[] checkId = objIds.ToArray();
                if (objIds != null)
                    pObject = checkId[0].GetObject(OpenMode.ForRead);

                if (pObject == null)
                    path = FullSubentityPath.Null;

                validType = (pObject.ObjectId.ObjectClass.GetRXClass() == entClass) || (allowDerived && pObject.ObjectId.ObjectClass.IsDerivedFrom(entClass));
                if (validType)
                    arrEnts.Add(path);
            }

            if (arrEnts.Capacity > 0)
                return true;
            else
                return false;
        }

        // This function is called whenever BricsCAD needs to know ALL the commands supported by
        // your reactor during, but not limited to loading of your module, adding your reactor
        // to the AcEdQuadReactorManager, displaying the CUI dialog. Your implementation of this
        // interface is expected to call AcEdQuadItemRegistry::append() for each QuadItem your
        // reactor supports / requires. 
        // If a QuadItem has not been registered, AcEdQuadItems::append will not append that
        // QuadItem to the Quad when its shown.
        public override bool registerQuadItems(QuadItemRegistry quadItemRegistry)
        {
            bool bs = false;
            string png1 = "custom_1.png";
            string png2 = "custom_2.png";
            string png3 = "download_16.png|download_32.png";
            string png4 = "downloading_16.png";

            // for ALL
            bs = quadItemRegistry.append("id_1", "Custom 'id_2'", png1, "_regen", "'Regen' command");
            // for LINE
            bs = quadItemRegistry.append("id_2", "Custom 'id_1'", png2, "_chprop;^S;", "'ChProp' for LINE");
            // for CIRCLE
            bs = quadItemRegistry.append("id_3", "Custom 'id_3'", png3, "_move;^S;", "'Move' for CIRCLE");
            // for 3DSOLID subentity
            bs = quadItemRegistry.append("id_4", "Custom 'id_4'", png4, "_offset;_s;", "'Offset' for 3DSOLID edge + face");
            // for NoSelection
            bs = quadItemRegistry.append("id_5", "Custom 'id_5'", "(H)", "_help", "'Help' command");

            return bs;
        }

        // Implement appendQuadItems to append QuadItems to the Quad. This function will be called
        // when the Quad is about to be shown.
        // Only those QuadItems that have been registered will be successfully appended.
        // Several reactors may be registered, but only those which are active (as per settings)
        // will append their items to the Quad.
        // *
        // This function is called when a Quad is to be shown for a selection.
        // AcEdQuadSelection can be queried further for hovered and pickfirst selection data,
        // to make intelligent decisions of relevant QuadItems to be added to the Quad.
        public override bool appendQuadItems(QuadSelection quadSelection, QuadItems quadItems)
        {
            bool bs = false;

            bool selectionValid = quadSelection.isValid();

            bool hasHover = quadSelection.hasHoveredData();
            QuadSelectionData hoverData = quadSelection.hoveredData();
            bool hoverValid = hoverData.isValid();

            bool hasPicked = quadSelection.hasPickFirstData();
            QuadSelectionData pickData = quadSelection.pickFirstData();
            bool pickedValid = pickData.isValid();

            QuadSelectionData allData = quadSelection.fullData();
            bool hasValidData = allData.isValid();

            List<FullSubentityPath> arrLines = null;
            List<FullSubentityPath> arrCircles = null;
            List<FullSubentityPath> arr3dSolids = null;

            bool hasLines = collectEntities(out arrLines, allData, RXClass.GetClass(typeof(Line)), QuadSelectionData.SelectedType.Entity, true);
            bool hasCircles = collectEntities(out arrCircles, allData, RXClass.GetClass(typeof(Circle)), QuadSelectionData.SelectedType.Entity, true);
            bool has3dSolids = collectEntities(out arr3dSolids, allData, RXClass.GetClass(typeof(Solid3d)), QuadSelectionData.SelectedType.Subent, true);

            if (hasValidData)
                bs = quadItems.append("id_1", null, null, null); // all

            if (hasLines)
                bs = quadItems.append("id_2", arrLines, null, null);    // for LINE entities

            if (hasCircles)
                bs = quadItems.append("id_3", arrCircles, null, null);  // for CIRCLE entities

            if (has3dSolids)
                bs = quadItems.append("id_4", null, null, null); // for 3DSOLID (edge+face) entities, uses hovered + selected automatically

            return bs;
        }
    }

    public class QuadCommands
    {
        MyQuad myQuadReactor = new MyQuad();
        public void AddMyQuadReactor()
        {
            QuadReactor.registerQuadReactor(myQuadReactor);
        }

        public void RemoveMyQuadReactor()
        {
            QuadReactor.unregisterQuadReactor(myQuadReactor);
        }
    }
}
