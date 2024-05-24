// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcCm/AcCmColor.h"
#include "AcCm/AcCmTransparency.h"
#include "AcDb/AcDbSymbolTableRecord.h"

/** _ */
class BRX_EXPORT AcDbLayerTableRecord: public AcDbSymbolTableRecord
{
public:
    typedef AcDbLayerTable TableType;

    enum
    {
        kDxfLayerPlotBit = 290
    };

    ACDB_DECLARE_MEMBERS(AcDbLayerTableRecord);

    AcDbLayerTableRecord();
    virtual ~AcDbLayerTableRecord();

    Acad::ErrorStatus setDescription(const ACHAR*);
    Acad::ErrorStatus setIsFrozen(bool);
    Acad::ErrorStatus setIsHidden(bool);
    Acad::ErrorStatus setIsPlottable(bool);
    Acad::ErrorStatus setLineWeight(AcDb::LineWeight);
    Acad::ErrorStatus setMaterialId(AcDbObjectId);
    Acad::ErrorStatus setPlotStyleName(const AcDbObjectId&);
    Acad::ErrorStatus setPlotStyleName(const ACHAR*);
    Acad::ErrorStatus setTransparency(const AcCmTransparency&);
    AcCmColor color() const;
    AcCmEntityColor entityColor() const;
    AcCmTransparency transparency() const;
    AcDb::LineWeight lineWeight() const;
    AcDbObjectId linetypeObjectId() const;
    AcDbObjectId materialId() const;
    AcDbObjectId plotStyleNameId() const;
    AcGiDrawable* drawable();
    ACHAR* description() const;
    ACHAR* plotStyleName() const;
    bool isFrozen() const;
    bool isHidden() const;
    bool isInUse() const;
    bool isLocked() const;
    bool isOff() const;
    bool isPlottable() const;
    bool VPDFLT() const;
    void setColor(const AcCmColor&);
    void setIsLocked(bool);
    void setIsOff(bool);
    void setLinetypeObjectId(AcDbObjectId);
    void setVPDFLT(bool);

    AcCmTransparency transparency(const AcDbObjectId&, bool&) const;
    Acad::ErrorStatus setTransparency(const AcCmTransparency&, const AcDbObjectId&);
    Acad::ErrorStatus removeTransparencyOverride(const AcDbObjectId&);

    AcCmColor color(const AcDbObjectId&, bool&) const;
    Acad::ErrorStatus setColor(const AcCmColor&, const AcDbObjectId&);
    Acad::ErrorStatus removeColorOverride(const AcDbObjectId&);

    AcDb::LineWeight lineWeight(const AcDbObjectId&, bool&) const;
    Acad::ErrorStatus setLineWeight(AcDb::LineWeight, const AcDbObjectId&);
    Acad::ErrorStatus removeLineWeightOverride(const AcDbObjectId&);

    AcDbObjectId linetypeObjectId(const AcDbObjectId&, bool&) const;
    Acad::ErrorStatus setLinetypeObjectId(const AcDbObjectId&, const AcDbObjectId&);
    Acad::ErrorStatus removeLinetypeOverride(const AcDbObjectId&);

    ACHAR*       plotStyleName(const AcDbObjectId&, bool&) const;
    AcDbObjectId plotStyleNameId(const AcDbObjectId&, bool&) const;
    Acad::ErrorStatus setPlotStyleName(const AcDbObjectId&, const AcDbObjectId&);
    Acad::ErrorStatus setPlotStyleName(const ACHAR*, const AcDbObjectId&);
    Acad::ErrorStatus removePlotStyleOverride(const AcDbObjectId&);

    bool hasOverrides(const AcDbObjectId&) const;
    bool hasAnyOverrides() const;

    Acad::ErrorStatus removeViewportOverrides(const AcDbObjectId&);
    Acad::ErrorStatus removeAllOverrides();

    Acad::ErrorStatus setIsReconciled(bool = true);
    bool isReconciled() const;
    static bool isReconciled(const AcDbObjectId&);

    static bool isHidden(AcDbObjectId);

protected:
    virtual Adesk::Boolean subWorldDraw(AcGiWorldDraw*);
    virtual Adesk::UInt32 subSetAttributes(AcGiDrawableTraits*);
    virtual void subViewportDraw(AcGiViewportDraw*);
};
