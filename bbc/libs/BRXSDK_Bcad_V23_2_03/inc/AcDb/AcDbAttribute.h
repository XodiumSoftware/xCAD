// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbText.h"

/** _ */
class BRX_EXPORT AcDbAttribute: public AcDbText
{
public:
    ACDB_DECLARE_MEMBERS(AcDbAttribute);

    AcDbAttribute();
    AcDbAttribute(const AcGePoint3d&,const ACHAR*,const ACHAR*,AcDbObjectId = AcDbObjectId::kNull);
    ~AcDbAttribute();

    ACHAR* tag() const;
    Acad::ErrorStatus setAttributeFromBlock(const AcDbAttributeDefinition*,const AcGeMatrix3d&);
    Acad::ErrorStatus setAttributeFromBlock(const AcGeMatrix3d&);
    Acad::ErrorStatus setFieldLength(Adesk::UInt16);
    Acad::ErrorStatus setInvisible(Adesk::Boolean);
    Acad::ErrorStatus setLockPositionInBlock(bool);
    Acad::ErrorStatus setTag(const ACHAR*);
    Adesk::Boolean isConstant() const;
    Adesk::Boolean isInvisible() const;
    Adesk::Boolean isPreset() const;
    Adesk::Boolean isVerifiable() const;
    Adesk::UInt16 fieldLength() const;
    bool lockPositionInBlock() const;
    const ACHAR* tagConst() const;
    AcDbMText* getMTextAttribute() const;
    const AcDbMText* getMTextAttributeConst() const;
    Acad::ErrorStatus convertIntoMTextAttribute(Adesk::Boolean = Adesk::kTrue);
    Acad::ErrorStatus setMTextAttribute(AcDbMText*);
    Acad::ErrorStatus updateMTextAttribute();
    bool isMTextAttribute() const;
};
