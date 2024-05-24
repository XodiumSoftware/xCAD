// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BrxSpecific/civil/BrxCvDbObjectManager.h"

template<typename STYLECLASS> class BrxCvDbStyleManagerT;

// declare style-specific type names for use in specializing the associated style manager
class BrxCvDbPointLabelStyle;
class BrxCvDbSurfaceContourLabelStyle;
class BrxCvDbSurfaceElevationLabelStyle;
class BrxCvDbSurfaceSlopeLabelStyle;
class BrxCvDbSymbolStyle;

// declare specialized style managers
using BrxCvDbPointLabelStyleManager = BrxCvDbStyleManagerT<BrxCvDbPointLabelStyle>;
using BrxCvDbSurfaceContourLabelStyleManager = BrxCvDbStyleManagerT<BrxCvDbSurfaceContourLabelStyle>;
using BrxCvDbSurfaceElevationLabelStyleManager = BrxCvDbStyleManagerT<BrxCvDbSurfaceElevationLabelStyle>;
using BrxCvDbSurfaceSlopeLabelStyleManager = BrxCvDbStyleManagerT<BrxCvDbSurfaceSlopeLabelStyle>;
using BrxCvDbSymbolStyleManager = BrxCvDbStyleManagerT<BrxCvDbSymbolStyle>;

/** Generic manager class for handling civil styles of various types */
class BRX_EXPORT BrxCvDbStyleManager : public BrxCvDbObjectManager
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbStyleManager);
    virtual ~BrxCvDbStyleManager();

protected:
    // this helper must be called from a specialized derived class
    template<typename STYLECLASS> static
    Acad::ErrorStatus openManager(BrxCvDbStyleManagerT<STYLECLASS>*& pManager,
                                  AcDbDatabase* db,
                                  AcDb::OpenMode mode = AcDb::kForRead,
                                  bool createIfNeeded = true)
    {
        AcDbObjectId mgrId;
        Acad::ErrorStatus es = BrxCvDbStyleManagerT<STYLECLASS>::getManager(mgrId, db, createIfNeeded);
        if (es != Acad::eOk)
            return es;
        return acdbOpenObject(pManager, mgrId, mode);
    }
};

template<typename STYLECLASS>
class BRX_EXPORT BrxCvDbStyleManagerT : public BrxCvDbStyleManager
{
public:
    // returns the manager instance object id
    static Acad::ErrorStatus getManager(AcDbObjectId& id, AcDbDatabase* db, bool createIfNeeded = true);

    // returns the manager instance opened in desired mode
    static Acad::ErrorStatus openManager(BrxCvDbStyleManagerT<STYLECLASS>*& pManager,
                                         AcDbDatabase* db,
                                         AcDb::OpenMode mode = AcDb::kForRead,
                                         bool createIfNeeded = true)
    {
        return BrxCvDbStyleManager::openManager(pManager, db, mode, createIfNeeded);
    }
};
