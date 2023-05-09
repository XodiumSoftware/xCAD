// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbHatch.h"

/** _ */
class BRX_EXPORT AcDbSectionSettings: public AcDbObject
{
public:
    enum Generation
    {
        kSourceAllObjects = 1,
        kSourceSelectedObjects = 2,
        kDestinationNewBlock = 16,
        kDestinationReplaceBlock = 32,
        kDestinationFile = 64
    };

    enum Geometry
    {
        kIntersectionBoundary = 1,
        kIntersectionFill = 2,
        kBackgroundGeometry = 4,
        kForegroundGeometry = 8,
        kCurveTangencyLines = 16
    };

    enum SectionType
    {
        kLiveSection = 1,
        k2dSection = 2,
        k3dSection = 4
    };

    ACDB_DECLARE_MEMBERS(AcDbSectionSettings);

    AcDbSectionSettings();
    ~AcDbSectionSettings();

    Acad::ErrorStatus getHatchPattern(SectionType,Geometry,AcDbHatch::HatchPatternType&,const ACHAR*&) const;
    Acad::ErrorStatus getSourceObjects(SectionType,AcDbObjectIdArray&) const;
    Acad::ErrorStatus reset();
    Acad::ErrorStatus reset(SectionType);
    Acad::ErrorStatus setColor(SectionType,Geometry,const AcCmColor&);
    Acad::ErrorStatus setCurrentSectionType(SectionType);
    Acad::ErrorStatus setDestinationBlock(SectionType,const AcDbObjectId&);
    Acad::ErrorStatus setDestinationFile(SectionType,const ACHAR*);
    Acad::ErrorStatus setDivisionLines(SectionType,Geometry,bool);
    Acad::ErrorStatus setEdgeTransparency(SectionType,Geometry,int);
    Acad::ErrorStatus setFaceTransparency(SectionType,Geometry,int);
    Acad::ErrorStatus setGenerationOptions(SectionType,Generation);
    Acad::ErrorStatus setHatchAngle(SectionType,Geometry,double);
    Acad::ErrorStatus setHatchPattern(SectionType,Geometry,AcDbHatch::HatchPatternType,const ACHAR*);
    Acad::ErrorStatus setHatchScale(SectionType,Geometry,double);
    Acad::ErrorStatus setHatchSpacing(SectionType,Geometry,double);
    Acad::ErrorStatus setHatchVisibility(SectionType,Geometry,bool);
    Acad::ErrorStatus setHiddenLine(SectionType,Geometry,bool);
    Acad::ErrorStatus setLayer(SectionType,Geometry,const ACHAR*);
    Acad::ErrorStatus setLinetype(SectionType,Geometry,const ACHAR*);
    Acad::ErrorStatus setLinetypeScale(SectionType,Geometry,double);
    Acad::ErrorStatus setLineWeight(SectionType,Geometry,AcDb::LineWeight);
    Acad::ErrorStatus setPlotStyleName(SectionType,Geometry,const ACHAR*);
    Acad::ErrorStatus setSourceObjects(SectionType,const AcDbObjectIdArray&);
    Acad::ErrorStatus setVisibility(SectionType,Geometry,bool);
    AcCmColor color(SectionType,Geometry) const;
    AcDb::LineWeight lineWeight(SectionType,Geometry) const;
    AcDbObjectId destinationBlock(SectionType) const;
    bool divisionLines(SectionType,Geometry) const;
    bool hatchVisibility(SectionType,Geometry) const;
    bool hiddenLine(SectionType,Geometry) const;
    bool visibility(SectionType,Geometry) const;
    const ACHAR* destinationFile(SectionType) const;
    const ACHAR* layer(SectionType,Geometry) const;
    const ACHAR* linetype(SectionType,Geometry) const;
    const ACHAR* plotStyleName(SectionType,Geometry) const;
    double hatchAngle(SectionType,Geometry) const;
    double hatchScale(SectionType,Geometry) const;
    double hatchSpacing(SectionType,Geometry) const;
    double linetypeScale(SectionType,Geometry) const;
    Generation generationOptions(SectionType) const;
    int edgeTransparency(SectionType,Geometry) const;
    int faceTransparency(SectionType,Geometry) const;
    SectionType currentSectionType() const;
};
