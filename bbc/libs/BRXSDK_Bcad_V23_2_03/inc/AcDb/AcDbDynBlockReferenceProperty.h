// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEvalVariant.h"
#include "AcDb/AcDbObjectId.h"
#include "Misc/AcHeapOperators.h"

/** _ */
class BRX_IMPORTEXPORT AcDbDynBlockReferenceProperty: public AcHeapOperators
{
public:
    enum UnitsType
    {
        kNoUnits = 0,
        kAngular,
        kDistance,
        kArea
    };

    AcDbDynBlockReferenceProperty();
    AcDbDynBlockReferenceProperty(const AcDbDynBlockReferenceProperty&);
    virtual ~AcDbDynBlockReferenceProperty();

    Acad::ErrorStatus getAllowedValues(AcDbEvalVariantArray&);
    Acad::ErrorStatus setValue(const AcDbEvalVariant&);
    AcDbEvalVariant value() const;
    AcDb::DwgDataType propertyType() const;
    AcDbObjectId blockId() const;
    AcString description() const;
    AcString propertyName() const;
    bool readOnly() const;
    bool show() const;
    UnitsType unitsType() const;

    AcDbDynBlockReferenceProperty& operator=(const AcDbDynBlockReferenceProperty&);

//BRX START
private:
    class BrxDbDynBlockReferencePropertyImp* m_pBrxImpl;
//BRX END
};

typedef AcArray< AcDbDynBlockReferenceProperty, AcArrayObjectCopyReallocator<AcDbDynBlockReferenceProperty> > AcDbDynBlockReferencePropertyArray;
