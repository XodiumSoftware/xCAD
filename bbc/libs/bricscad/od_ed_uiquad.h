// od_ed_uiquad.h : The Quad API: Interface classes required for implementing quad features
// Copyright © Menhirs NV. All rights reserved.
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "od_api_exports.h"
#include "OdString.h"
#include "DbSSet.h"

/* Specifying icons:
*  "iconId"                        : one of the builtin icon IDs (visible in the Customize dialog)
*  "icon16id|icon32id"             : a different ID for small and large icon (separated with '|' char)
*  "iconfile.png"                  : a bitmap file name (with or without path)
*  "icon16file.png|icon32file.png" : two bitmap file names, small and large (with or without path)
*  "resName[iconid]"               : resName is the name of a resource DLL in which the icon can be found
*  "resName[icon16id|icon32id]"    : resName is the name of a resource DLL in which both icons can be found
(resName is usually the same as the CUI menugroup name)
*  "(abbreviation)"                : abbreviation is a short text (1 to 3 chars) that will be drawn in a circle
*/

/* Specifying command strings and passing selection sets:
*  A command string is usually specified as ^C^CCOMMANDNAME followed by additional parameters if any. The syntax is the same
as that used when menu macros are specified. In addition,
*  If the command string does not contain a ^S, the pickfirst set (pre-selected/grip set), if any, is fed to the command.
If the cursor is hovering on a selection thats not in the pickfirst set, that will also get appended to the pickfirst
set, and the combined set fed to the command. Note that this works only for commands that accept pickfirst sets.
* Commands that dont accept pickfirst sets can still use pickfirst/hovered sets by specifying a ^S in the command string,
and not passing any selection sets in OdEdUIQuadButtons::append() for that particular command. Then, the combined set consisting
of hovered and picked first set (if any) will be fed to the command. For example, "^c^c_offset;\^S\;". Note however that its
the users responsibility to select the correct selection set while executing this macro from the quad, else the command may
give unexpected results.
* If finer control is desired, pSSets can be populated and passed, with one selection set for every ^S in the command string.
Example, ^c^c_GCFIX;_E;^S with one selection set in pSSets, ^c^c_GCSYMMETRIC;^S;^S;^S with three selection sets in pSSets, etc.
*/
class OdSelectionData;
typedef OdSmartPtr<OdSelectionData> OdSelectionDataPtr;
class ODAPI OdEdUIQuadButtons
{
protected:
    virtual ~OdEdUIQuadButtons() {}

public:
    // Call this function in your analyzer's implementation of OdEdUIQuadAnalyzer::appendQuadButtons. 
    // It appends the QuadButton corresponding to the quadButtonId to the quad when the quad is about to be shown. 
    // The QuadButton must be be registered earlier via a call to OdEdUIQuadButtonRegistry::append.
    // Please see "Specifying command strings and passing selection sets" (above) for help on pSSets.
    // Returns false if the QuadButton was not appended.
    virtual bool append(const OdString& quadButtonId) = 0;
    virtual bool append(const OdString& quadButtonId, const OdArray<OdDbSelectionSetPtr>& pSSets) = 0;
    virtual bool append(const OdString& quadButtonId, const OdArray<OdSelectionDataPtr>& pArrSelData) = 0;

    virtual unsigned int length() const = 0;
};

class OdSelectionData;
class ODAPI OdEdUIQuadSelection
{
protected:
    virtual ~OdEdUIQuadSelection() {}

public:
    // Entity/boundary over which the mouse hovers will be in the hovered set. This entity can also be in the pickfirst set if its selected.
    virtual bool hasHoveredData() const = 0;
    virtual const OdSelectionData* hoveredData() const = 0;

    // Pre-selected entities/boundaries will be in the pickfirst set. This can also contain the hovered one if its selected.
    virtual bool hasPickFirstData() const = 0;
    virtual const OdSelectionData* pickFirstData() const = 0;

    // The full set will contain entities/boundaries from both (pickfirst and hovered) sets. This function is here to avoid additional 
    // combining operations in client code.
    virtual const OdSelectionData* fullData() const = 0;
};

class ODAPI OdEdUIQuadButtonRegistry
{
public:
    virtual ~OdEdUIQuadButtonRegistry() {}

    // Use this function to register your QuadButton in your implementation of OdEdUIQuadAnalyzer::registerQuadButtons.
    // The quadButtonId should be unique within the scope of the analyzer. 
    // The label, icon and command should be non empty; tooltip can be empty. 
    // Returns true if registration was successful.
    virtual bool append(const OdString &quadButtonId,
        const OdString &label, const OdString &icon, const OdString &command, const OdString &tooltip) = 0;
};

class ODAPI OdEdUIQuadAnalyzer
{
public:
    OdEdUIQuadAnalyzer() {}
    virtual ~OdEdUIQuadAnalyzer() {}

    // The GUID has to be a globally unique identifier (use VS201x->Tools->CreateGUID, "guidgen.exe") and will be used to internally identify
    // the analyzer across sessions, releases and different third party applications, so it should always be the same for this analyzer. 
    // Therefore, once a analyzer is published by a developer, its GUID should NEVER be changed.
    virtual OdString GUID() = 0;

    // The display name will be shown to users in the UI for identifying/enabling/disabling/prioritising your analyzer.
    virtual OdString displayName() = 0;

    // This function is called whenever BricsCAD needs to know ALL the commands supported by your analyzer during, but not limited to
    // loading of your module, adding your analyzer to the OdEdUIQuadAnalyzerManager, displaying the CUI dialog. Your implementation of this
    // interface is expected to call OdEdUIQuadButtonRegistry::append for each QuadButton your analyzer supports. 
    // If a QuadButton has not been registered, OdEdUIQuadButtons::append will not append your QuadButton to the quad when its shown.
    virtual bool registerQuadButtons(OdEdUIQuadButtonRegistry& quadButtonRegistry) = 0;

    // Implement appendQuadButtons to append QuadButtons to the quad. This function will be called when the quad is about to be shown.
    // Only those QuadButtons that have been registered will be successfully appended.
    // Several analyzers may be registered, but only those which are active (as per settings) will append their buttons to the quad.
    //
    // This function is called when a quad is to be shown for a selection. OdEdUIQuadSelection can be queried further for hovered 
    // and pickfirst selection data, to make intelligent decisions of relevant QuadButtons to be added to the quad.
    virtual bool appendQuadButtons(const OdEdUIQuadSelection* pQuadSelection, OdEdUIQuadButtons &buttons) { return false; }

    virtual unsigned int getEntityClassificationForQuad(const OdEdUIQuadSelection* pQuadSelection) { return 0; }
    virtual unsigned int getDoorTypeVal() { return 0; }
    virtual unsigned int getWindowTypeVal() { return 0; }

    //
    // This function is called when the no-selection quad is to be shown. Add selection independent buttons in this function.
    virtual bool appendQuadButtons(OdEdUIQuadButtons &buttons) { return false; }
};

class ODAPI OdEdUIQuadAnalyzerManager
{
protected:
    virtual ~OdEdUIQuadAnalyzerManager() {}

public:
    // Registers a Quad analyzer. Analyzer is added to the internal list,  but caller owns the memory.
    // Function returns false if another analyzer has same GUID (the analyzer will not get added in that case).
    virtual bool addQuadAnalyzer(OdEdUIQuadAnalyzer *pQuadAnalyzer) = 0;

    // Unregisters a Quad analyzer. Analyzer is removed from the internal list, caller still owns the memory.
    // Function returns false if analyzer was not present in the list.
    virtual bool removeQuadAnalyzer(OdEdUIQuadAnalyzer *pQuadAnalyzer) = 0;
};

OdEdUIQuadAnalyzerManager* odEdUIQuadAnalyzerManager();
