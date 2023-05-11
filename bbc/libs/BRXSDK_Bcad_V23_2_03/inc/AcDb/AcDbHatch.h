// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"

/** _ */
class BRX_EXPORT AcDbHatch: public AcDbEntity
{
public:

    enum GradientPatternType
    {
        kPreDefinedGradient = 0,
        kUserDefinedGradient
    };

    enum HatchEdgeType
    {
        kLine = 1,
        kCirArc,
        kEllArc,
        kSpline
    };

    enum HatchLoopType
    {
        kDefault = 0,
        kExternal = 1,
        kPolyline = 2,
        kDerived = 4,
        kTextbox = 8,
        kOutermost = 16,
        kNotClosed = 32,
        kSelfIntersecting = 64,
        kTextIsland = 128,
        kDuplicate = 256
    };

    enum HatchObjectType
    {
        kHatchObject = 0,
        kGradientObject
    };

    enum HatchPatternType
    {
        kUserDefined = 0,
        kPreDefined,
        kCustomDefined
    };

    enum HatchStyle
    {
        kNormal = 0,
        kOuter,
        kIgnore
    };

    ACDB_DECLARE_MEMBERS(AcDbHatch);

    AcDbHatch ();
    virtual ~AcDbHatch();

    virtual Acad::ErrorStatus getPlane(AcGePlane&,AcDb::Planarity&) const;
    virtual Acad::ErrorStatus subSwapIdWith(AcDbObjectId,Adesk::Boolean = Adesk::kFalse,Adesk::Boolean = Adesk::kFalse);
    virtual Acad::ErrorStatus swapReferences(const AcDbIdMapping&);
    virtual Adesk::Boolean isGradient() const;
    virtual Adesk::Boolean isHatch() const;
    virtual Adesk::Boolean isPlanar() const;
    virtual bool castShadows() const;
    virtual bool receiveShadows() const;
    virtual void modifiedGraphics(const AcDbEntity*);
    virtual void setCastShadows(bool);
    virtual void setReceiveShadows(bool);

    Acad::ErrorStatus appendLoop(Adesk::Int32,const AcDbObjectIdArray&);
    Acad::ErrorStatus appendLoop(Adesk::Int32,const AcGePoint2dArray&,const AcGeDoubleArray&);
    Acad::ErrorStatus appendLoop(Adesk::Int32,const AcGeVoidPointerArray&,const AcGeIntArray&);
    Acad::ErrorStatus evaluateGradientColorAt(float,AcCmColor&);
    Acad::ErrorStatus evaluateHatch(bool = false);
    Acad::ErrorStatus getArea(double&) const;
    Acad::ErrorStatus getAssocObjIds(AcDbObjectIdArray&) const;
    Acad::ErrorStatus getAssocObjIdsAt(int,AcDbObjectIdArray&) const;
    Acad::ErrorStatus getGradientColors(unsigned int&,AcCmColor*&,float*&);
    Acad::ErrorStatus getHatchLineDataAt(int,AcGePoint2d&,AcGePoint2d&) const;
    Acad::ErrorStatus getHatchLinesData(AcGePoint2dArray&,AcGePoint2dArray&) const;
    Acad::ErrorStatus getLoopAt(int,Adesk::Int32&,AcGePoint2dArray&,AcGeDoubleArray&) const;
    Acad::ErrorStatus getLoopAt(int,Adesk::Int32&,AcGeVoidPointerArray&,AcGeIntArray&) const;
    Acad::ErrorStatus getPatternDefinitionAt(int,double&,double&,double&,double&,double&,AcGeDoubleArray&) const;
    Acad::ErrorStatus insertLoopAt(int,Adesk::Int32,const AcDbObjectIdArray&);
    Acad::ErrorStatus insertLoopAt(int,Adesk::Int32,const AcGePoint2dArray&,const AcGeDoubleArray&);
    Acad::ErrorStatus insertLoopAt(int,Adesk::Int32,const AcGeVoidPointerArray&,const AcGeIntArray&);
    Acad::ErrorStatus removeAssocObjIds();
    Acad::ErrorStatus removeLoopAt(int);
    Acad::ErrorStatus setAssociative(bool);
    Acad::ErrorStatus setElevation(double);
    Acad::ErrorStatus setGradient(GradientPatternType,const ACHAR*);
    Acad::ErrorStatus setGradientAngle(double);
    Acad::ErrorStatus setGradientColors(unsigned int,AcCmColor*,float*);
    Acad::ErrorStatus setGradientOneColorMode(Adesk::Boolean);
    Acad::ErrorStatus setGradientShift(float);
    Acad::ErrorStatus setHatchObjectType(HatchObjectType);
    Acad::ErrorStatus setHatchStyle(HatchStyle);
    Acad::ErrorStatus setNormal(const AcGeVector3d&);
    Acad::ErrorStatus setOriginPoint(const AcGePoint2d&);
    Acad::ErrorStatus setPattern(HatchPatternType,const ACHAR*);
    Acad::ErrorStatus setPatternAngle(double);
    Acad::ErrorStatus setPatternDouble(bool);
    Acad::ErrorStatus setPatternScale(double);
    Acad::ErrorStatus setPatternSpace(double);
    Acad::ErrorStatus setShadeTintValue(float);
    Acad::ErrorStatus setShadeTintValueAndColor2(float);
    AcDbRegion* getRegionArea() const;
    AcGePoint2d originPoint() const;
    AcGeVector3d normal() const;
    Adesk::Boolean getGradientOneColorMode() const;
    Adesk::Int32 loopTypeAt(int) const;
    bool associative() const;
    bool isSolidFill() const;
    bool lineGenerationEnabled() const;
    bool patternDouble() const;
    bool setLineGenerationEnabled(bool);
    const ACHAR* gradientName() const;
    const ACHAR* patternName() const;
    double elevation() const;
    double gradientAngle() const;
    double patternAngle() const;
    double patternScale() const;
    double patternSpace() const;
    float getShadeTintValue() const;
    float gradientShift() const;
    GradientPatternType gradientType() const;
    HatchObjectType hatchObjectType() const;
    HatchPatternType patternType() const;
    HatchStyle hatchStyle() const;
    int numHatchLines() const;
    int numLoops() const;
    int numPatternDefinitions() const;
    void removeHatchLines();
    Acad::ErrorStatus setBackgroundColor(const AcCmColor& );
    AcCmColor backgroundColor() const;
};
