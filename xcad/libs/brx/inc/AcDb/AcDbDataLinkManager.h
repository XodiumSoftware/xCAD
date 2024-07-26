// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

class AcDbDataLink;

/** _ */
class BRX_EXPORT AcDbDataLinkManager : public AcRxObject
{
protected:
    AcDbDataLinkManager(void);
public:
    ACRX_DECLARE_MEMBERS(AcDbDataLinkManager);

    virtual ~AcDbDataLinkManager();

    Acad::ErrorStatus addDataLink(AcDbDataLink*);
    Acad::ErrorStatus addDataLink(AcDbDataLink*, AcDbObjectId&);
    Acad::ErrorStatus createDataLink(const ACHAR*, const ACHAR*, const ACHAR*, const ACHAR*, AcDbObjectId&);
    int dataLinkCount(void) const;
    Acad::ErrorStatus getDataLink(const ACHAR*, AcDbObjectId&) const;
    Acad::ErrorStatus getDataLink(const ACHAR*, AcDbDataLink*&, AcDb::OpenMode) const;
    int getDataLink(AcDbObjectIdArray&) const;
    Acad::ErrorStatus removeDataLink(const ACHAR*, AcDbObjectId&);
    Acad::ErrorStatus removeDataLink(const AcDbObjectId&);
    Acad::ErrorStatus update(const AcDbObjectIdArray&, AcDb::UpdateDirection, AcDb::UpdateOption);
    Acad::ErrorStatus update(AcDb::UpdateDirection, AcDb::UpdateOption);
};
