// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BricsCAD API for the Quad cursor/menu

#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"

#include "AcDb/AcDbObjectId.h"  // AcDbObjectIdArray
#include "AcDb/AcDbFullSubentPath.h"

class AcGePlane;
class AcDbCurve;
class AcDbRegion;

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

/*
V18.2 : chnaged logic for showing Quad tabs and items
=====================================================

With V18.2. a significant change in the logic of handling Quad tabs + items has been
introduced, to allow users to define which of those application-provided tabs + items
shall be shown.

Solution 1 :
------------
Type the CUI command and in the dialog, go to Quad. In the right pane, under
Available tools, Built-in, you should be able to see your BRX Quad application.
In the left pane, right click on BRICSCAD and click on Append Quad Tab.
Drag and drop your BRX Quad application buttons to your newly created Quad Tab.

Solution 2 :
------------
create a dedicated partial CUI file, which contains only the declarations of the
Quad Tab(s) and Item(s), then load that menu (i.e. in kInitAppMsg, or when registering
the QuadReactor).

Existing application code still works as before - there is no break;
the difference with V18.2. is, that Quad tabs + items are no longer shown by default,
until the user explicitly enables those Quad tabs + items as he wishes (Solution 1)

But this also causes side-effects for applications, unexpectedly - the Quad tabs + items
are not there (and which worked before V18.2.).

To overcome this bottleneck, an extra mechanism has been introduced - applications can
additionally provide an application-specific partial menu (cui) file, which declares
all Quad tabs + items, as those are used + provided by the application, via this Quad API.
(Solution 2)

The application can check for the presence of the menugroup (as declared in that CUI file),
and if necessary, load the CUI file, i.e. during kInitAppMsg, and/or together with the
reactor registration.

Below is a sample of such a CUI menu file, defining 5 items - it is used in our "brxSample"
sample application.

Explanations :
--------------

<QuadTab ID="qt_MyQuad" Name="MyQuad" NameRef="MyQuad">
    the definition for the Quad tab

<QuadButton ID="id_1" QuadAnalyzerId="6C5E7CF3-DC10-4ED3-A339-39156C8B7B3F"/>
    ID : the ID for the Quad item, to be identified as "id_1" by the application code;
    QuadAnalyzerId : the GUID as provided by the application's QuadReactor;
    => the QuadManager identifies the associated Quad handler by that GUID


Example CUI file content, as used by the "brxSample" sample application (MyQuadExtension.cui)
=============================================================================================

<?xml version="1.0" encoding="UTF-8" standalone="no" ?>
<CustSection xml:lang="en-US">
  <MenuGroup Name="MyQuadExtension">
    <MenuRoot>
      <QuadRoot>
        <QuadTabs>
          <QuadTab ID="qt_MyQuad" Name="MyQuad" NameRef="MyQuad">
            <QuadButton ID="id_1" QuadAnalyzerId="6C5E7CF3-DC10-4ED3-A339-39156C8B7B3F"/>
            <QuadButton ID="id_2" QuadAnalyzerId="6C5E7CF3-DC10-4ED3-A339-39156C8B7B3F"/>
            <QuadButton ID="id_3" QuadAnalyzerId="6C5E7CF3-DC10-4ED3-A339-39156C8B7B3F"/>
            <QuadButton ID="id_4" QuadAnalyzerId="6C5E7CF3-DC10-4ED3-A339-39156C8B7B3F"/>
            <QuadButton ID="id_5" QuadAnalyzerId="6C5E7CF3-DC10-4ED3-A339-39156C8B7B3F"/>
          </QuadTab>
        </QuadTabs>
      </QuadRoot>
    </MenuRoot>
  </MenuGroup>
</CustSection>

*/


//---------------------------------------------------------------------------------------
// 'AcBoundary' class represents an array of loops being the boundary of a planar domain.
// The first item is the outer loop, all further item(s) are one or more inner loop(s).
typedef AcArray<AcDbCurve*> AcDbCurvePtrArray;

class BRX_IMPORTEXPORT AcBoundary
{
public:
    // Returns 'true' if this boundary is valid; returns 'false' for an empty boundary
    virtual bool isValid() const = 0;
    
    // Returns the plane, the loops belong to
    virtual AcGePlane plane() const = 0;

    // Returns path to a 'face' subentity, if the boundary belongs to any; may be empty
    virtual AcDbFullSubentPath path() const = 0;

    // Returns 'true' if an edge overlaps with an edge of the face it belongs to, if any
    virtual bool overlapsWithFaceEdge(Adesk::UInt32 loopIndex, Adesk::UInt32 edgeIndex) const = 0;

    // Service method to get the boundary as AcDbRegion (will be initialised as NULL);
    // return value of 'true' guarantees a non-null AcDbRegion
    virtual bool getAsRegion(AcDbRegion* pRegion) const = 0;

    // Returns the boundary's loops as an array of 'AcDbCurve*' objects, one curve per loop.
    // If a loop is composed of a set of AcGeCurves, an AcDbPpolyline is created, else a single
    // appropriate AcDbCurve. If 'whichLoops == eOuter', then only the outer loop is returned;
    // for 'whichLoops == eInner' all inner loops, and for 'whichLoops == eAllLoops' the outermost
    // loop (as first curve, index 0) and all inner loops (starting from index 1) are returned.
    //
    // The curves are not database-resident; client side *MUST* *NOT* delete the curves, or
    // add them to a database - the AcBoundary destructor automatically deletes the curves !
    // Client side code needs to clone the contained curve objects, if further, independent use
    // is intended.
    // Calling 'getAsDbCurves()' multiple times will clear the passed-in array, and fill the
    // array again with same curve objects (those are cached & hold by this AcBoundary instance).
    //
    // If no curves are found, this function returns 'false'.
    enum {
        eOuterLoop  = 0x01,
        eInnerLoops = 0x02,
        eAllLoops   = eOuterLoop | eInnerLoops,
    };
    virtual bool getAsDbCurves(AcDbCurvePtrArray& boundaryCurves, int whichLoops) const = 0;
};

//---------------------------------------------------------------------------------------
// This class encapsulates the preselected, hovered, or otherwise dynamic selection, usually
// from user selection of any kind; the AcSelection class allows to modify the dynamic selection.

class BRX_IMPORTEXPORT AcSelectionData
{
public:
    enum SelectedType {
        eEntity   = 0x01,
        eSubent   = 0x02,
        eBoundary = 0x04,
    };

    // Returns 'true' if this AcSelectionData is valid; returns 'false' for an empty object
    virtual bool isValid() const = 0;

    // returns the number of contained entities, subentities and boundaries
    virtual Adesk::UInt32 length() const = 0;

    // returns a combination of 'SelectedType' values, indicating the types
    // of contained entities, subentities and boundaries.
    virtual int hasTypes() const = 0;

    // returns the type of entity in selection, at given index
    virtual const SelectedType typeAt(Adesk::UInt32 index) const = 0;

    // returns the entity in selection, at given index
    virtual AcDbObjectId entityAt(Adesk::UInt32 index) const = 0;

    // returns the full entity path in selection, at given index
    virtual AcDbFullSubentPath subentAt(Adesk::UInt32 index) const = 0;

    // returns the complete selection as array of AcDbFullSubentPath, at given index
    virtual AcDbFullSubentPathArray selectionSet() const = 0;

    // returns the complete selection as array of AcDbFullSubentPath, at given index
    virtual const AcBoundary& boundaryAt(Adesk::UInt32 index) const = 0;
};

//---------------------------------------------------------------------------------------
// This class represents the collection of QuadItems, collected by the Quad menu/cursor, when the
// Quad menu/cursor is about to be shown - at that moment, the Quad queries all registered QuadReactors,
// to add desired items to the Quad's item collection, the 'AcEdQuadItems'.

class BRX_IMPORTEXPORT AcEdQuadItems
{
public:
    // Call this function from your reactor's implementation of 'AcEdQuadReactor::appendQuadItems()',
    // using the provided 'AcEdQuadItems' instance.

    // appends the 'AcEdQuadItem' specified by 'quadItemId' to the Quad, when the Quad is about to be shown;
    // the 'AcEdQuadItem' must be registered earlier via a call to 'AcEdQuadItemRegistry::append()';
    // please see "Specifying command strings and passing selection sets" (above) for help on selSet1, selSet2
    // and selSet3;
    // Note : if 'selSetX' specifies an empty AcDbFullSubentPathArray, it is treated like a NULL argument
    // returns false, if the 'QuadItem' was not appended

    virtual bool append(const ACHAR* szQuadItemId,
                        const AcDbFullSubentPathArray* selSet1 = NULL,
                        const AcDbFullSubentPathArray* selSet2 = NULL,
                        const AcDbFullSubentPathArray* selSet3 = NULL) = 0;

    virtual Adesk::UInt32 length() const = 0;
};

//---------------------------------------------------------------------------------------
// This helper class provides access to actual entity selection (picked, hovered), when the Quad
// is about to be shown - the AcEdQuadReactor::appendQuadItems() provides an instance of this class,
// to provide the Quad client information about actual selection.

class BRX_IMPORTEXPORT AcEdQuadSelection
{
public:
    // Returns 'true' if this AcEdQuadSelection is valid; returns 'false' for an empty object,
    // without any (hovered or pickfirst) data
    virtual bool isValid() const = 0;

    // the hovered set contains the entity/boundary over which the mouse is just hovering;
    // this entity can also be in the pickfirst set, when it is also (pre-)selected
    virtual bool hasHoveredData() const = 0;
    virtual const AcSelectionData& hoveredData() const = 0;

    // the pickfirst set contains the pre-selected entities/boundaries;
    // this can also contain the hovered entity/boundary, if that is pre-selected
    virtual bool hasPickFirstData() const = 0;
    virtual const AcSelectionData& pickFirstData() const = 0;

    // the full set will contain entities/boundaries from both (pickfirst and hovered) sets;
    // this function is provided to reduce efforts and operations at client side
    virtual const AcSelectionData& fullData() const = 0;
};

//---------------------------------------------------------------------------------------
// This helper class is provied to collect all the QuadItems, the client implementation intends to use;
// all QuadItems must be declared upfront, prior to its usage.
// QuadItems can be declared using this class, during 'AcEdQuadReactor::registerQuadItems()' callback.

class BRX_IMPORTEXPORT AcEdQuadItemRegistry
{
public:
    // use this function from inside your implementation of 'AcEdQuadReactor::registerQuadItems()',
    // to register all your QuadItems;
    // 'szQuadItemId' should be unique within the scope of the reactor;
    // 'szLabel', 'szIcon' and 'szCommand' should not be NULL or empty; 'szTooltip' can be NULL or empty;
    // returns true if registration was successful
    virtual bool append(const ACHAR* szQuadItemId, const ACHAR* szLabel, const ACHAR* szIcon,
                        const ACHAR* szCommand, const ACHAR* szTooltip = NULL) = 0;
};

//---------------------------------------------------------------------------------------
// This class handlers the QuadReactors management, mainly adding + removing client reactors.

class AcEdQuadReactor;

class BRX_IMPORTEXPORT AcEdQuadReactorManager
{
public:
    // Registers a Quad reactor. Reactor is added to the internal list, but caller owns the memory.
    // Function returns false if another reactor has same GUID (the reactor will not get added in that case).
    // The function should return true if reactors were added.
    virtual bool addQuadReactor(AcEdQuadReactor* pQuadReactor) = 0;

    // Unregisters a Quad reactor. Reactor is removed from the internal list, caller still owns the memory.
    // Function returns false if reactor was not present in the list.
    // The function should return true if reactors were removed.
    virtual bool removeQuadReactor(AcEdQuadReactor* pQuadReactor) = 0;
};

AcEdQuadReactorManager* acedQuadReactorManager();

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

class BRX_IMPORTEXPORT AcEdQuadReactor
{
public:
    AcEdQuadReactor() {};

    // client is not enforced to explicitly unregister the reactor, automatically done at DTor
    virtual ~AcEdQuadReactor()
    {
        if (acedQuadReactorManager() != NULL)
            acedQuadReactorManager()->removeQuadReactor(this);
    };

    // The GUID has to be a globally unique identifier (use VS201x->Tools->CreateGUID, "guidgen.exe")
    // and will be used to internally identify the reactor across sessions, releases and
    // different third party applications, so it should always be the same for this reactor. 
    // Therefore, once a reactor is published by a developer, its GUID should NEVER be changed.
    // Note : any string format from "CreateGUID" / "guidgen.exe" is accepted, suggested format
    //        is like "C2160591-FC06-4A74-A9B8-2E28635279BA" (not brackets)
    virtual const ACHAR* GUID() = 0;

    // The display name will be shown to users in the UI for identifying/enabling/disabling/
    // prioritising your reactor.
    virtual const ACHAR* displayName() = 0;

    // This function is called whenever BricsCAD needs to know ALL the commands supported by
    // your reactor during, but not limited to loading of your module, adding your reactor
    // to the AcEdQuadReactorManager, displaying the CUI dialog. Your implementation of this
    // interface is expected to call AcEdQuadItemRegistry::append() for each QuadItem your
    // reactor supports / requires. 
    // If a QuadItem has not been registered, AcEdQuadItems::append will not append that
    // QuadItem to the Quad when its shown.
    // The function should return true if items are registered.
    virtual bool registerQuadItems(AcEdQuadItemRegistry& quadItemRegistry) = 0;

    // Implement appendQuadItems to append QuadItems to the Quad. This function will be called
    // when the Quad is about to be shown.
    // Only those QuadItems that have been registered will be successfully appended.
    // Several reactors may be registered, but only those which are active (as per settings)
    // will append their items to the Quad.
    // *
    // This function is called when a Quad is to be shown for a selection.
    // AcEdQuadSelection can be queried further for hovered and pickfirst selection data,
    // to make intelligent decisions of relevant QuadItems to be added to the Quad.
    // The function should return true if items are appended.
    virtual bool appendQuadItems(const AcEdQuadSelection& quadSelection, AcEdQuadItems& quadItems)
    {
        return false;
    };

    // This function is called when the no-selection Quad is to be shown.
    // Add selection-independent items in this function.
    // The function should return true if items are registered.
    virtual bool appendQuadItems(AcEdQuadItems& quadItems)
    {
        return false;
    };
};
