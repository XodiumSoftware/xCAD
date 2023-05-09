// Copyright (C) Menhirs NV. All rights reserved.
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
