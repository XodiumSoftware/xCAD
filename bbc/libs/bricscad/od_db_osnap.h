// od_db_osnap.h : OdDbCustomOsnapInfo, OdDbCustomOsnapMode
// and OdDbCustomOsnapManager classes definition

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "od_api_exports.h"

#include "RxObject.h"
#include "Ge/GeIntArray.h"
#include "Ge/GeCurve3dPtrArray.h"
#include "od_gi_glyph.h"

class ODAPI OdDbCustomOsnapInfo: public OdRxObject
{
public:
    ODRX_DECLARE_MEMBERS(OdDbCustomOsnapInfo);

    virtual OdResult getOsnapInfo(
       OdDbEntity*           pPickedEntity,
       OdGsMarker            gsMarker,
       const OdGePoint3d&    pickPt,
       const OdGePoint3d&    lastPt,
       const OdGeMatrix3d&   xWorldToEye,
       OdGePoint3dArray&     snapPts,
       OdGeIntArray&         geomIdsOfPoints,
       OdGeCurve3dPtrArray&  snapCurves,
       OdGeIntArray&         geomIdsOfLines) = 0;
};

class OdDbCustomOsnapMode
{
public:
    virtual ~OdDbCustomOsnapMode() {};

    // The next 2 functions specify the custom osnap keyword strings.
    // Both "local" and "global" keyword strings will be used by snapping;
    // local + global strings should follow the usual rules for keywords.
    virtual const TCHAR* globalModeString() const = 0;
    virtual const TCHAR* localModeString() const = 0;

    // This function must return an OdRxClass* pointer of the protocol extension
    // class which is used for all entity classes supporting this snap mode.
    // That protocol extension class needs to be deribed from OdDbCustomOsnapInfo.
    virtual const OdRxClass* entityOsnapClass() const = 0;

    // Returns the glyph class instance responsible to draw the osnap glyph;
    // returning NULL indicates that no custom glyph is used.
    virtual OdGiGlyph* glyph() const = 0;

    // Returns the tooltip string associated with this osnap mode;
    // returning NULL indicates that no tooltip is used.
    virtual const TCHAR* tooltipString() const = 0;
};

// Registered custom osnap modes are managed by OdDbCustomOsnapManager.
class OdDbCustomOsnapManager
{
public:
    virtual ~OdDbCustomOsnapManager() {};

    // Adds a custom osnap mode to the system. 
    // Custom osnap modes need to provide : global + local string and entityOsnapClass
    virtual OdResult addCustomOsnapMode(OdDbCustomOsnapMode* pMode) = 0;

    // Removes a custom osnap mode.
    virtual OdResult removeCustomOsnapMode(OdDbCustomOsnapMode* pMode) = 0;

    // Activates a custom osnap mode.
    // Argument osnap mode string can be the localised name (no underscore _ character)
    // or the global / name (specified with underscore _ character).
    virtual OdResult activateOsnapMode(const TCHAR * modeStr) = 0;

    // Deactivates a custom osnap mode.
    // Argument osnap mode string can be the localised name (no underscore _ character)
    // or the global / name (specified with underscore _ character).
    virtual OdResult deactivateOsnapMode(const TCHAR * modeStr) = 0;

    // Returns whether a particular custom osnap mode is active.
    // Argument osnap mode string can be the localised name (no underscore _ character)
    // or the global / name (specified with underscore _ character).
    virtual bool modeIsActive(const TCHAR * modeStr) = 0;

    // Returns the size of the glyph (defaults to APERTURE and PICKBOX).
    virtual int osnapGlyphSize() const = 0;
};

OdDbCustomOsnapManager* oddbCustomOsnapManager();
