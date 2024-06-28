// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcDbModelDocViewStyle;
class AcCmColor;

class BRX_IMPORTEXPORT AcDbDetailViewStyle : public AcDbModelDocViewStyle
{
public:
    ACDB_DECLARE_MEMBERS(AcDbDetailViewStyle);

    enum IdentifierPlacement
    {
        kOutsideBoundary = 0,
        kOutsideBoundaryWithLeader,
        kOnBoundary,
        kOnBoundaryWithLeader,
    };

    enum ModelEdge
    {
        kSmooth = 0,
        kSmoothWithBorder,
        kSmoothWithConnectionLine,
        kJagged,
    };

    AcDbDetailViewStyle();
    ~AcDbDetailViewStyle();

    Acad::ErrorStatus getViewLabelPattern    (AcString&, AcDbField* = NULL) const;
    Acad::ErrorStatus setArrowSymbolColor    (const AcCmColor&);
    Acad::ErrorStatus setArrowSymbolId       (const AcDbObjectId&);
    Acad::ErrorStatus setArrowSymbolSize     (double);
    Acad::ErrorStatus setBorderLineColor     (const AcCmColor&);
    Acad::ErrorStatus setBorderLineTypeId    (const AcDbObjectId&);
    Acad::ErrorStatus setBorderLineWeight    (AcDb::LineWeight);
    Acad::ErrorStatus setBoundaryLineColor   (const AcCmColor&);
    Acad::ErrorStatus setBoundaryLineTypeId  (const AcDbObjectId&);
    Acad::ErrorStatus setBoundaryLineWeight  (AcDb::LineWeight);
    Acad::ErrorStatus setConnectionLineColor (const AcCmColor&);
    Acad::ErrorStatus setConnectionLineTypeId(const AcDbObjectId&);
    Acad::ErrorStatus setConnectionLineWeight(AcDb::LineWeight);
    Acad::ErrorStatus setIdentifierColor     (const AcCmColor&);
    Acad::ErrorStatus setIdentifierHeight    (double);
    Acad::ErrorStatus setIdentifierOffset    (double);
    Acad::ErrorStatus setIdentifierPlacement (AcDbDetailViewStyle::IdentifierPlacement);
    Acad::ErrorStatus setIdentifierStyleId   (const AcDbObjectId&);
    Acad::ErrorStatus setModelEdge           (AcDbDetailViewStyle::ModelEdge);
    Acad::ErrorStatus setShowArrows          (bool);
    Acad::ErrorStatus setShowViewLabel       (bool);
    Acad::ErrorStatus setViewLabelAlignment  (AcDbModelDocViewStyle::TextAlignment);
    Acad::ErrorStatus setViewLabelAttachment (AcDbModelDocViewStyle::AttachmentPoint);
    Acad::ErrorStatus setViewLabelOffset     (double);
    Acad::ErrorStatus setViewLabelPattern    (const ACHAR*, const AcDbField* = NULL);
    Acad::ErrorStatus setViewLabelTextColor  (const AcCmColor&);
    Acad::ErrorStatus setViewLabelTextHeight (double);
    Acad::ErrorStatus setViewLabelTextStyleId(const AcDbObjectId&);

    AcCmColor         arrowSymbolColor()     const;
    AcCmColor         borderLineColor()      const;
    AcCmColor         boundaryLineColor()    const;
    AcCmColor         connectionLineColor()  const;
    AcCmColor         identifierColor()      const;
    AcCmColor         viewLabelTextColor()   const;

    AcDb::LineWeight  borderLineWeight()     const;
    AcDb::LineWeight  boundaryLineWeight()   const;
    AcDb::LineWeight  connectionLineWeight() const;

    AcDbDetailViewStyle::IdentifierPlacement identifierPlacement() const;
    AcDbDetailViewStyle::ModelEdge           modelEdge()           const;
    AcDbModelDocViewStyle::AttachmentPoint   viewLabelAttachment() const;
    AcDbModelDocViewStyle::TextAlignment     viewLabelAlignment()  const;

    AcDbObjectId      arrowSymbolId()        const;
    AcDbObjectId      borderLineTypeId()     const;
    AcDbObjectId      boundaryLineTypeId()   const;
    AcDbObjectId      connectionLineTypeId() const;
    AcDbObjectId      identifierStyleId()    const;
    AcDbObjectId      viewLabelTextStyleId() const;

    bool              showArrows()           const;
    bool              showViewLabel()        const;

    const ACHAR*      viewLabelPattern()     const;
                                            
    double            arrowSymbolSize()      const;
    double            identifierHeight()     const;
    double            identifierOffset()     const;
    double            viewLabelOffset()      const;
    double            viewLabelTextHeight()  const;
};
