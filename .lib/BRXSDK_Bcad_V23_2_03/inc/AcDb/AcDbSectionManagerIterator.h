// Copyright (C) Menhirs NV. All rights reserved.
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
