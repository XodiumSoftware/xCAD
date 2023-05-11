// od_db_user_io_ex.h : OdDbUserIOEx class declaration

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "od_api_exports.h"
#include "DbUserIO.h"
#include "od_sel_options.h"

namespace OdUI
{;

enum ESelectEntityOptions
{
    kSenDefault = 0x00000000,
    kSenAcceptPickPtOnly = 0x00000001,
    kSenAcceptNoNull = 0x00000002
};


}//OdUI

class OdSelectionData;
typedef OdSmartPtr<OdSelectionData> OdSelectionDataPtr;

// OdDbUserIOEx defines an extension of OdDbUserIO interface
class ODAPI OdDbUserIOEx: public OdDbUserIO
{
public:
    ODRX_DECLARE_MEMBERS(OdDbUserIOEx);

    using OdDbUserIO::select;
    virtual int select(OdDbSelectionSetPtr& pSSet,
                       const OdString& prompt = OdString::kEmpty,
                       int options = OdEd::kSelDefault,
                       const OdString& keywords = OdString::kEmpty,
                       OdSSetTracker* pTracker = 0,
                       OdGePoint3dArray* ptsPointer = NULL) = 0;

    virtual OdDbObjectId selectEntity(const OdString& prompt = OdString::kEmpty,
                                     int options = OdUI::kSenDefault,
                                     const OdString& keywords = OdString::kEmpty,
                                     OdGePoint3d* ptUc = NULL,
                                     bool* bValidPt = NULL,
                                     const OdDbSelectionFilter* pFilter = NULL) = 0;

    virtual OdSelectionDataPtr selectEx(const OdString& prompt = OdString::kEmpty,
                                        const OdString& keywords = OdString::kEmpty,
                                        const int selMethod = OdEd::kSelDefault,
                                        const int subentTypes = OdUI::eSelectNone, 
                                        OdDbSelectionFilter* pFilter = NULL) = 0;
};
