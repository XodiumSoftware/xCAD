// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbSymbolTableIterator.h"

class AcDbLayerTable;

/** _ */
class BRX_IMPORTEXPORT AcDbLayerTableIterator: public AcDbSymbolTableIterator
{
protected:
    friend AcDbLayerTable;
    AcDbLayerTableIterator();
public:
    Acad::ErrorStatus getRecord(AcDbLayerTableRecord*&, AcDb::OpenMode = AcDb::kForRead, bool = false) const;
    Acad::ErrorStatus seek(AcDbObjectId);
    Acad::ErrorStatus seek(const AcDbLayerTableRecord*);
    bool getSkipHidden() const;
    void setSkipHidden(bool value);
    bool getSkipReconciled() const;
    void setSkipReconciled(bool);
};
