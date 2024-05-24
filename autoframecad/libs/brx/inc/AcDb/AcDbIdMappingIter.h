// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbIdMapping.h"

class BrxDbIdMappingIterImp;

/** _ */
class BRX_IMPORTEXPORT AcDbIdMappingIter: public AcRxObject
{
private:
    BrxDbIdMappingIterImp* m_pBrxImp;

public:
    ACRX_DECLARE_MEMBERS(AcDbIdMappingIter);

    AcDbIdMappingIter(const AcDbIdMapping&);
    virtual ~AcDbIdMappingIter();

    virtual Acad::ErrorStatus iterateOn(const AcDbIdMapping&);
    virtual bool done();
    virtual bool getMap(AcDbIdPair&);
    virtual bool next();
    virtual void start();
};
