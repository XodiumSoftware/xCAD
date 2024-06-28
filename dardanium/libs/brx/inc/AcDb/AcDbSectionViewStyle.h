// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcDbModelDocViewStyle;
class AcCmColor;

class BRX_IMPORTEXPORT AcDbSectionViewStyle : public AcDbModelDocViewStyle
{
public:
    ACDB_DECLARE_MEMBERS(AcDbSectionViewStyle);

    enum IdentifierPosition
    {
        kEndCuttingPlane = 0,
        kAboveDirectionArrowLine = 1,
        kAboveDirectionArrowSymbol = 2,
        kStartDirectionArrow = 3,
        kEndDirectionArrow = 4,
    };

    enum ArrowDirection
    {
        kTowardsCuttingPlane = 0,
        kAwayFromCuttingPlane = 1,
    };

    AcDbSectionViewStyle();
    ~AcDbSectionViewStyle();

    Acad::ErrorStatus getViewLabelPattern            (AcString&, AcDbField* = NULL) const;
    Acad::ErrorStatus setArrowEndSymbolId            (const AcDbObjectId&);
    Acad::ErrorStatus setArrowPosition               (AcDbSectionViewStyle::ArrowDirection);
    Acad::ErrorStatus setArrowStartSymbolId          (const AcDbObjectId&);
    Acad::ErrorStatus setArrowSymbolColor            (const AcCmColor&);
    Acad::ErrorStatus setArrowSymbolExtensionLength  (double);
    Acad::ErrorStatus setArrowSymbolSize             (double);
    Acad::ErrorStatus setBendLineColor               (const AcCmColor&);
    Acad::ErrorStatus setBendLineLength              (double);
    Acad::ErrorStatus setBendLineTypeId              (const AcDbObjectId&);
    Acad::ErrorStatus setBendLineWeight              (AcDb::LineWeight);
    Acad::ErrorStatus setContinuousLabeling          (bool);
    Acad::ErrorStatus setEndLineLength               (double);
    Acad::ErrorStatus setEndLineOvershoot            (double);
    Acad::ErrorStatus setHatchAngles                 (const AcArray<double>&);
    Acad::ErrorStatus setHatchBackgroundColor        (const AcCmColor&);
    Acad::ErrorStatus setHatchColor                  (const AcCmColor&);
    Acad::ErrorStatus setHatchPattern                (const ACHAR*);
    Acad::ErrorStatus setHatchScale                  (double);
    Acad::ErrorStatus setHatchTransparency           (const AcCmTransparency&);
    Acad::ErrorStatus setIdentifierColor             (const AcCmColor&);
    Acad::ErrorStatus setIdentifierExcludeCharacters (const ACHAR*);
    Acad::ErrorStatus setIdentifierHeight            (double);
    Acad::ErrorStatus setIdentifierStyleId           (const AcDbObjectId&);
    Acad::ErrorStatus setPlaneLineColor              (const AcCmColor&);
    Acad::ErrorStatus setPlaneLineTypeId             (const AcDbObjectId&);
    Acad::ErrorStatus setPlaneLineWeight             (AcDb::LineWeight);
    Acad::ErrorStatus setShowAllBendIndentifiers     (bool);
    Acad::ErrorStatus setShowAllPlaneLines           (bool);
    Acad::ErrorStatus setShowArrowheads              (bool);
    Acad::ErrorStatus setShowEndAndBendLines         (bool);
    Acad::ErrorStatus setShowHatching                (bool);
    Acad::ErrorStatus setShowViewLabel               (bool);
    Acad::ErrorStatus setViewIdentifierOffset        (double);
    Acad::ErrorStatus setViewIdentifierPosition      (AcDbSectionViewStyle::IdentifierPosition);
    Acad::ErrorStatus setViewLabelAlignment          (AcDbModelDocViewStyle::TextAlignment);
    Acad::ErrorStatus setViewLabelAttachment         (AcDbModelDocViewStyle::AttachmentPoint);
    Acad::ErrorStatus setViewLabelOffset             (double);
    Acad::ErrorStatus setViewLabelPattern            (const ACHAR*, const AcDbField* = NULL);
    Acad::ErrorStatus setViewLabelTextColor          (const AcCmColor&);
    Acad::ErrorStatus setViewLabelTextHeight         (double);
    Acad::ErrorStatus setViewLabelTextStyleId        (const AcDbObjectId&);

    AcCmColor         arrowSymbolColor()             const;
    AcCmColor         bendLineColor()                const;
    AcCmColor         hatchBackgroundColor()         const;
    AcCmColor         hatchColor()                   const;
    AcCmColor         identifierColor()              const;
    AcCmColor         planeLineColor()               const;
    AcCmColor         viewLabelTextColor()           const;
                                                     
    AcCmTransparency  hatchTransparency()            const;
                                                     
    AcDb::LineWeight  bendLineWeight()               const;
    AcDb::LineWeight  planeLineWeight()              const;

    AcDbModelDocViewStyle::AttachmentPoint viewLabelAttachment() const;
    AcDbModelDocViewStyle::TextAlignment   viewLabelAlignment()  const;
                                                     
    AcDbObjectId      arrowEndSymbolId()             const;
    AcDbObjectId      arrowStartSymbolId()           const;
    AcDbObjectId      bendLineTypeId()               const;
    AcDbObjectId      identifierStyleId()            const;
    AcDbObjectId      planeLineTypeId()              const;
    AcDbObjectId      viewLabelTextStyleId()         const;

    AcDbSectionViewStyle::ArrowDirection     arrowPosition()          const;
    AcDbSectionViewStyle::IdentifierPosition viewIdentifierPosition() const;

    bool              isContinuousLabeling()         const;
    bool              showAllBendIndentifiers()      const;
    bool              showAllPlaneLines()            const;
    bool              showArrowheads()               const;
    bool              showEndAndBendLines()          const;
    bool              showHatching()                 const;
    bool              showViewLabel()                const;
                                                     
    const AcArray<double>& hatchAngles()             const;
                                                     
    const ACHAR*      hatchPattern()                 const;
    const ACHAR*      identifierExcludeCharacters()  const;
    const ACHAR*      viewLabelPattern()             const;
                                                     
    double            arrowSymbolExtensionLength()   const;
    double            arrowSymbolSize()              const;
    double            bendLineLength()               const;
    double            endLineLength()                const;
    double            endLineOvershoot()             const;
    double            hatchScale()                   const;
    double            identifierHeight()             const;
    double            viewIdentifierOffset()         const;
    double            viewLabelOffset()              const;
    double            viewLabelTextHeight()          const;

    static bool       validateIdentifierExcludeCharacters(const ACHAR*);
};
