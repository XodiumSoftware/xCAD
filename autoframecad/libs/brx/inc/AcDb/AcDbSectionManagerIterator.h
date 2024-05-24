// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"

class AcDbSection;

/** _ */
class BRX_IMPORTEXPORT AcDbSectionManagerIterator
{
protected:
    void* m_pBrxImp;
    friend class AcDbSectionManager;
    AcDbSectionManagerIterator();

public:
    virtual ~AcDbSectionManagerIterator();

    Acad::ErrorStatus getSection(AcDbSection*&,AcDb::OpenMode) const;
    AcDbObjectId getSection() const;
    bool done() const;
    void start();
    void step();
};
