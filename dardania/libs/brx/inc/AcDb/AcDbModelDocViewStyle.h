// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"

class BRX_IMPORTEXPORT AcDbModelDocViewStyle : public AcDbObject
{
protected:
    AcDbModelDocViewStyle(); // protected as abstract class

public:
    ACDB_DECLARE_MEMBERS(AcDbModelDocViewStyle);

    enum AttachmentPoint
    {
        kAboveView = 0,
        kBelowView = 1,
    };

    enum TextAlignment
    {
        kTextAlignmentLeft = 0,
        kTextAlignmentCenter = 1,
        kTextAlignmentRight = 2,
    };

    ~AcDbModelDocViewStyle() = 0;

    Acad::ErrorStatus postViewStyleToDb     (AcDbDatabase*, const ACHAR*, AcDbObjectId&);
    virtual Acad::ErrorStatus getName       (AcString&) const;
    virtual Acad::ErrorStatus setDescription(const ACHAR*);
    virtual Acad::ErrorStatus setName       (const ACHAR*);

    AcString defaultViewName(int)      const;

    bool isModifiedForRecompute()      const;
    bool isViewNameValid(const ACHAR*) const;

    static AcGePoint3d  calculateViewLabelPosition(AcGeVector2d&, AcDbMText::AttachmentPoint&, AcDbModelDocViewStyle::AttachmentPoint, double, const AcGePoint3d&, const AcGePoint3d&);
    static AcGeVector2d setViewLabelPosition      (AcDbMText*, AcDbModelDocViewStyle::AttachmentPoint, double, const AcGePoint3d&, const AcGePoint3d&);
    static AcGeVector2d updateViewLabelPosition   (AcDbMText*, AcDbModelDocViewStyle::AttachmentPoint&, const AcGePoint3d&, const AcGePoint3d&);

    virtual const ACHAR* description(void) const;
    virtual void getDescription(AcString&) const;

    void setDatabaseDefaults(AcDbDatabase*);
};
