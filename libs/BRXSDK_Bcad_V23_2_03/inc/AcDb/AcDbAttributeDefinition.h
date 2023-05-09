// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbText.h"

/** _ */
class BRX_EXPORT AcDbAttributeDefinition: public AcDbText
{
public:
    ACDB_DECLARE_MEMBERS(AcDbAttributeDefinition);

    AcDbAttributeDefinition();
    AcDbAttributeDefinition(const AcGePoint3d&,const ACHAR*,const ACHAR*,const ACHAR*,AcDbObjectId = AcDbObjectId::kNull);
    ~AcDbAttributeDefinition();

    virtual Acad::ErrorStatus adjustAlignment(const AcDbDatabase* = NULL);

    ACHAR* prompt() const;
    ACHAR* tag() const;
    Acad::ErrorStatus setConstant(Adesk::Boolean);
    Acad::ErrorStatus setFieldLength(Adesk::UInt16);
    Acad::ErrorStatus setInvisible(Adesk::Boolean);
    Acad::ErrorStatus setLockPositionInBlock(bool);
    Acad::ErrorStatus setPreset(Adesk::Boolean);
    Acad::ErrorStatus setPrompt(const ACHAR*);
    Acad::ErrorStatus setTag(const ACHAR*);
    Acad::ErrorStatus setVerifiable(Adesk::Boolean);
    Adesk::Boolean isConstant() const;
    Adesk::Boolean isInvisible() const;
    Adesk::Boolean isPreset() const;
    Adesk::Boolean isVerifiable() const;
    Adesk::UInt16 fieldLength() const;
    bool lockPositionInBlock() const;
    const ACHAR* promptConst() const;
    const ACHAR* tagConst() const;
    Acad::ErrorStatus convertIntoMTextAttributeDefinition(Adesk::Boolean value = Adesk::kTrue);
    AcDbMText * getMTextAttributeDefinition() const;
    bool isMTextAttributeDefinition() const;
    Acad::ErrorStatus setMTextAttributeDefinition(AcDbMText*);
    Acad::ErrorStatus updateMTextAttributeDefinition();
};
