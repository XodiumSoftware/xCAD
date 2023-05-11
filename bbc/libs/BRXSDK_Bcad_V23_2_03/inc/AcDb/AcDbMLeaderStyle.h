// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"


/** _ */
class BRX_EXPORT AcDbMLeaderStyle: public AcDbObject
{
public:

    enum ContentType
    {
        kNoneContent = 0,
        kBlockContent,      // 1
        kMTextContent,      // 2
        kToleranceContent,  // 3
    };

    enum DrawMLeaderOrderType
    {
        kDrawContentFirst = 0,
        kDrawLeaderFirst,
    };

    enum DrawLeaderOrderType
    {
        kDrawLeaderHeadFirst = 0,
        kDrawLeaderTailFirst,
    };

    enum LeaderType
    {
        kInVisibleLeader = 0,
        kStraightLeader,
        kSplineLeader,
    };

    enum TextAttachmentDirection
    {
        kAttachmentHorizontal = 0,
        kAttachmentVertical,
    };

    enum TextAttachmentType
    {
        kAttachmentTopOfTop = 0,
        kAttachmentMiddleOfTop,      // 1
        kAttachmentMiddle,           // 2
        kAttachmentMiddleOfBottom,   // 3
        kAttachmentBottomOfBottom,   // 4
        kAttachmentBottomLine,       // 5
        kAttachmentBottomOfTopLine,  // 6
        kAttachmentBottomOfTop,      // 7
        kAttachmentAllLine,          // 8
        kAttachmentCenter,           // 9
        kAttachmentLinedCenter,      // 10
    };

    enum TextAngleType
    {
        kInsertAngle = 0,
        kHorizontalAngle,
        kAlwaysRightReadingAngle,
    };

    enum TextAlignmentType
    {
        kLeftAlignment = 0,
        kCenterAlignment,
        kRightAlignment,
    };

    enum BlockConnectionType
    {
        kConnectExtents = 0,
        kConnectBase,
    };

    enum LeaderDirectionType
    {
        kUnknownLeader = 0,
        kLeftLeader,        // 1
        kRightLeader,       // 2
        kTopLeader,         // 3
        kBottomLeader,      // 4
    };

    enum SegmentAngleType
    {
        kAny = 0,
        k15,         // 1
        k30,         // 2
        k45,         // 3
        k60,         // 4
        k90 = 6,
        kHorz = 12,
    };

    ACDB_DECLARE_MEMBERS(AcDbMLeaderStyle);

    AcDbMLeaderStyle();
    virtual ~AcDbMLeaderStyle();

    virtual Acad::ErrorStatus getName(ACHAR*&) const;
    virtual const ACHAR*  description() const;
    virtual Adesk::UInt32 bitFlags() const;

    virtual Acad::ErrorStatus setName(const ACHAR*);
    virtual Acad::ErrorStatus setDescription(const ACHAR*);
    virtual Acad::ErrorStatus setBitFlags(Adesk::UInt32);


    int maxLeaderSegmentsPoints() const;
    bool enableLanding() const;
    bool enableDogleg() const;
    bool textAlignAlwaysLeft() const;
    bool enableFrameText() const;
    bool enableBlockRotation() const;
    bool annotative() const;
    bool extendLeaderToText() const;
    bool isRenamable() const;
    bool enableBlockScale() const;
    bool overwritePropChanged() const;
    double landingGap() const;
    double doglegLength() const;
    double arrowSize() const;
    double textHeight() const;
    double alignSpace() const;
    double blockRotation() const;
    double scale() const;
    double breakSize() const;
    ContentType contentType() const;
    DrawMLeaderOrderType drawMLeaderOrderType() const;
    DrawLeaderOrderType drawLeaderOrderType() const;
    SegmentAngleType firstSegmentAngleConstraint() const;
    SegmentAngleType secondSegmentAngleConstraint() const;
    LeaderType leaderLineType() const;
    AcCmColor leaderLineColor() const;
    AcDbObjectId leaderLineTypeId() const;
    AcDb::LineWeight leaderLineWeight() const;
    AcDbObjectId arrowSymbolId() const;
    AcDbMText* defaultMText() const;
    AcDbObjectId textStyleId() const;
    TextAttachmentType textAttachmentType(LeaderDirectionType) const;
    TextAttachmentType textAttachmentType() const;
    TextAngleType textAngleType() const;
    TextAlignmentType textAlignmentType() const;
    AcCmColor textColor() const;
    AcDbObjectId blockId() const;
    AcCmColor blockColor() const;
    AcGeScale3d blockScale() const;
    Acad::ErrorStatus setEnableBlockScale(bool);
    BlockConnectionType blockConnectionType() const;
    TextAttachmentDirection textAttachmentDirection() const;

    Acad::ErrorStatus setContentType(ContentType);
    Acad::ErrorStatus setDrawMLeaderOrderType(DrawMLeaderOrderType);
    Acad::ErrorStatus setDrawLeaderOrderType(DrawLeaderOrderType);
    Acad::ErrorStatus setMaxLeaderSegmentsPoints(int);
    Acad::ErrorStatus setFirstSegmentAngleConstraint(SegmentAngleType);
    Acad::ErrorStatus setSecondSegmentAngleConstraint(SegmentAngleType);
    Acad::ErrorStatus setLeaderLineType(LeaderType);
    Acad::ErrorStatus setLeaderLineColor(const AcCmColor&);
    Acad::ErrorStatus setLeaderLineTypeId(const AcDbObjectId&);
    Acad::ErrorStatus setLeaderLineWeight(AcDb::LineWeight);
    Acad::ErrorStatus setEnableLanding(bool);
    Acad::ErrorStatus setLandingGap(double);
    Acad::ErrorStatus setEnableDogleg(bool);
    Acad::ErrorStatus setDoglegLength(double);
    Acad::ErrorStatus setArrowSymbolId(const ACHAR*);
    Acad::ErrorStatus setArrowSymbolId(const AcDbObjectId&);
    Acad::ErrorStatus setArrowSize(double);
    Acad::ErrorStatus setDefaultMText(const AcDbMText*);
    Acad::ErrorStatus setTextStyleId(const AcDbObjectId&);
    Acad::ErrorStatus setTextAttachmentType(TextAttachmentType, LeaderDirectionType);
    Acad::ErrorStatus setTextAttachmentType(TextAttachmentType);
    Acad::ErrorStatus setTextAngleType(TextAngleType);
    Acad::ErrorStatus setTextAlignmentType(TextAlignmentType);
    Acad::ErrorStatus setTextAlignAlwaysLeft(bool);
    Acad::ErrorStatus setTextColor(const AcCmColor&);
    Acad::ErrorStatus setTextHeight(double);
    Acad::ErrorStatus setEnableFrameText(bool);
    Acad::ErrorStatus setAlignSpace(double);
    Acad::ErrorStatus setBlockId(const ACHAR*);
    Acad::ErrorStatus setBlockId(const AcDbObjectId&);
    Acad::ErrorStatus setBlockColor(const AcCmColor&);
    Acad::ErrorStatus setBlockScale(const AcGeScale3d&);
    Acad::ErrorStatus setBlockRotation(double);
    Acad::ErrorStatus setEnableBlockRotation(bool);
    Acad::ErrorStatus setBlockConnectionType(BlockConnectionType);
    Acad::ErrorStatus setScale(double);
    Acad::ErrorStatus setAnnotative(bool);
    Acad::ErrorStatus setBreakSize(double);
    Acad::ErrorStatus setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection);
    Acad::ErrorStatus setExtendLeaderToText(bool);

    Acad::ErrorStatus postMLeaderStyleToDb (AcDbDatabase*, const ACHAR*, AcDbObjectId&);
};
