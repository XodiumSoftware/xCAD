// Copyright (C) Menhirs NV. All rights reserved.
//
// This is an example how to use the C++ Quad Extension API,
// a BricsCAD specific interface

#include "StdAfx.h"


#if !defined(BRX_APP) || (__BRXTARGET < 17) // dummy implemented for ARX build + BRX < V17
bool registerMyQuadExtension()
{
    return false;
}
bool unregisterMyQuadExtension()
{
    return false;
}
#endif // !BRX_APP


#ifdef BRX_APP  // not available with ARX

#include "MyQuadExtension.h"

MyAcEdQuadReactor* s_myQuadReactor = NULL;

bool MyAcEdQuadReactor::collectEntities(AcDbFullSubentPathArray& arrEnts,
                                        const AcSelectionData& data,
                                        const AcRxClass* entClass,
                                        const AcSelectionData::SelectedType etype,
                                        bool allowDerived)
{
    if (!data.isValid())
        return false;
    if ((data.hasTypes() & etype) == 0)
        return false;

    bool validType(false);
    AcDbObject* pObject(NULL);
    AcDbObjectId id;
    AcDbFullSubentPath path;
    AcDbSubentId emptySubentId;

    const Adesk::UInt32 numEntries = data.length();
    for (Adesk::UInt32 i = 0; i < numEntries; ++i)
    {
        const AcSelectionData::SelectedType selType = data.typeAt(i);
        if (selType != etype)
            continue;

        if (selType == AcSelectionData::eEntity)
        {
            id = data.entityAt(i);
            path = AcDbFullSubentPath(id, emptySubentId);
        }
        else
        if (selType == AcSelectionData::eSubent)
        {
            path = data.subentAt(i);
            id = path.objectIds().first();
        }

        pObject = NULL;
        if (acdbOpenObject(pObject, id, AcDb::kForRead) == Acad::eOk)
        {
            validType = (pObject->isA() == entClass) ||
                        (allowDerived && pObject->isKindOf(entClass));
            pObject->close();
            if (validType)
            {
                arrEnts.append(path);
            }
        }
    }

    return !arrEnts.isEmpty();
}

const ACHAR* MyAcEdQuadReactor::GUID()
{
    return _T("6C5E7CF3-DC10-4ED3-A339-39156C8B7B3F");
}

const ACHAR* MyAcEdQuadReactor::displayName()
{
    return _T("MyQuad");
}

// "iconId"                        : one of the builtin icon IDs (visible in the Customize dialog)
// "icon16id|icon32id"             : a different ID for small and large icon (separated with '|' char)
// "iconfile.png"                  : a bitmap file name (with or without path)
// "icon16file.png|icon32file.png" : two bitmap file names, small and large (with or without path)
// "resName[iconid]"               : resName is the name of a resource DLL in which the icon can be found
// "resName[icon16id|icon32id]"    : resName is the name of a resource DLL in which both icons can be found
//                                   (resName is usually the same as the CUI menugroup name)
// "(abbreviation)"                : abbreviation is a short text (1 to 3 chars) that will be drawn in a circle

// !!! NOTE !!! subfolder ./icons contains the PNG images, please copy into BricsCAD folder,
//              or adjust the subsequent code to use an application-specific folder

bool MyAcEdQuadReactor::registerQuadItems(AcEdQuadItemRegistry& quadItemRegistry)
{
    bool bs = false;
    AcString png1 = _T("custom_1.png");
    AcString png2 = _T("custom_2.png");
    AcString png3 = _T("download_16.png|download_32.png");
    AcString png4 = _T("downloading_16.png");

    // for ALL
    bs = quadItemRegistry.append(_T("id_1"), _T("Custom 'id_2'"), png1.kwszPtr(), _T("_regen"),      _T("'Regen' command"));
    // for LINE
    bs = quadItemRegistry.append(_T("id_2"), _T("Custom 'id_1'"), png2.kwszPtr(), _T("_chprop;^S;"), _T("'ChProp' for LINE"));
    // for CIRCLE
    bs = quadItemRegistry.append(_T("id_3"), _T("Custom 'id_3'"), png3.kwszPtr(), _T("_move;^S;"),   _T("'Move' for CIRCLE"));
    // for 3DSOLID subentity
    bs = quadItemRegistry.append(_T("id_4"), _T("Custom 'id_4'"), png4.kwszPtr(), _T("_offset;_s;"), _T("'Offset' for 3DSOLID edge + face"));
    // for NoSelection
    bs = quadItemRegistry.append(_T("id_5"), _T("Custom 'id_5'"), _T("(H)"),      _T("_help"),       _T("'Help' command"));

    return bs;
}

bool MyAcEdQuadReactor::appendQuadItems(const AcEdQuadSelection& quadSelection, AcEdQuadItems& quadItems)
{
    bool bs = false;

    bool selectionValid = quadSelection.isValid();

    bool hasHover = quadSelection.hasHoveredData();
    const AcSelectionData& hoverData = quadSelection.hoveredData();
    bool hoverValid = hoverData.isValid();

    bool hasPicked = quadSelection.hasPickFirstData();
    const AcSelectionData& pickData = quadSelection.pickFirstData();
    bool pickedValid = pickData.isValid();

    const AcSelectionData& allData = quadSelection.fullData();
    bool hasValidData = allData.isValid();

    AcDbFullSubentPathArray arrLines;
    AcDbFullSubentPathArray arrCircles;
    AcDbFullSubentPathArray arr3dSolids;
    bool hasLines    = collectEntities(arrLines,    allData, AcDbLine::desc(),    AcSelectionData::eEntity, true);
    bool hasCircles  = collectEntities(arrCircles,  allData, AcDbCircle::desc(),  AcSelectionData::eEntity, false);
    bool has3dSolids = collectEntities(arr3dSolids, allData, AcDb3dSolid::desc(), AcSelectionData::eSubent, false);

    if (hasValidData)
        bs = quadItems.append(_T("id_1")); // all

    if (hasLines)
        bs = quadItems.append(_T("id_2"), &arrLines);    // for LINE entities

    if (hasCircles)
        bs = quadItems.append(_T("id_3"), &arrCircles);  // for CIRCLE entities

    if (has3dSolids)
        bs = quadItems.append(_T("id_4"), NULL); // for 3DSOLID (edge+face) entities, uses hovered + selected automatically

    return bs;
}

bool MyAcEdQuadReactor::appendQuadItems(AcEdQuadItems& quadItems)
{
    bool bs = quadItems.append(_T("id_5"));
    return bs;
}


bool registerMyQuadExtension()
{
    bool res = false;

    // optionally : pre-load the "MyQuadExtension.cui" menu file to have all our Quad items known
    // (for the CUI management) - otherwise, user needs to explicitly active our Quad tab + items
    if (acedIsMenuGroupLoaded(_T("MyQuadExtension")) == Adesk::kFalse)
    {
        res = acedLoadPartialMenu(_T("MyQuadExtension.cui"));
    }

    AcEdQuadReactorManager* quadMngr = acedQuadReactorManager();
    if (quadMngr != NULL)
    {
        s_myQuadReactor = new MyAcEdQuadReactor();
        res = quadMngr->addQuadReactor(s_myQuadReactor);
    }

    return res;
}

bool unregisterMyQuadExtension()
{
    if (s_myQuadReactor != NULL)
    {
        AcEdQuadReactorManager* quadMngr = acedQuadReactorManager();
        if (quadMngr != NULL)
            quadMngr->removeQuadReactor(s_myQuadReactor);
    }

    return true;
}



#endif // BRX_APP
