// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbEntity.h"
#include "AcDb/AcDbMLeaderStyle.h"

#ifndef MAX_LEADER_NUMBER
#define MAX_LEADER_NUMBER  5000
#endif
#ifndef MAX_LEADERLINE_NUMBER
#define MAX_LEADERLINE_NUMBER  MAX_LEADER_NUMBER
#endif

class AcDbMLeaderStyle;
class AcDbMLeaderObjectContextData;

/** _ */
class BRX_EXPORT AcDbMLeader: public AcDbEntity
{
public:

    enum gsMarkType
    {
        kNone = 0,
        kArrowMark = 1,
        kLeaderLineMark     = kArrowMark      + MAX_LEADERLINE_NUMBER,
        kDoglegMark         = kLeaderLineMark + MAX_LEADERLINE_NUMBER,
        kMTextMark          = kDoglegMark     + MAX_LEADER_NUMBER,
        kMTextUnderLineMark = kMTextMark      + 1,
        kToleranceMark      = kMTextUnderLineMark + 1,
        kBlockMark          = kToleranceMark  + 1,
        kBlockAttribute     = kBlockMark      + 1,
    };

    enum MoveType
    {
        kMoveAllPoints = 0,
        kMoveAllExceptArrowHeaderPoints, // 1
        kMoveContentAndDoglegPoints,     // 2
    };

    enum PropertyOverrideType
    {
        kLeaderLineType = 0,
        kLeaderLineColor,            // 1
        kLeaderLineTypeId,           // 2
        kLeaderLineWeight,           // 3
        kEnableLanding,              // 4
        kLandingGap,                 // 5
        kEnableDogleg,               // 6
        kDoglegLength,               // 7
        kArrowSymbolId,              // 8
        kArrowSize,                  // 9
        kContentType,                // 10
        kTextStyleId,                // 11
        kTextLeftAttachmentType,     // 12
        kTextAngleType,              // 13
        kTextAlignmentType,          // 14
        kTextColor,                  // 15
        kTextHeight,                 // 16
        kEnableFrameText,            // 17
        kDefaultMText,               // 18
        kBlockId,                    // 19
        kBlockColor,                 // 20
        kBlockScale,                 // 21
        kBlockRotation,              // 22
        kBlockConnectionType,        // 23
        kScale,                      // 24
        kTextRightAttachmentType,    // 25
        kTextSwitchAlignmentType,    // 26
        kTextAttachmentDirection,    // 27
        kTextTopAttachmentType,      // 28
        kTextBottomAttachmentType,   // 29
        kExtendLeaderToText,         // 30
        kSize = kExtendLeaderToText + 1,
    };

    ACDB_DECLARE_MEMBERS(AcDbMLeader);

    AcDbMLeader();
    ~AcDbMLeader();


    int numLeaders() const;
    int numLeaderLines() const;
    double landingGap() const;
    bool enableLanding() const;
    double arrowSize() const;
    bool hasContent() const;
    AcDbMLeaderStyle::LeaderType leaderLineType() const;
    AcCmColor leaderLineColor() const;
    AcDbObjectId leaderLineTypeId() const;
    AcDb::LineWeight leaderLineWeight() const;

    AcGeVector3d normal() const;
    double scale() const;
    AcGePlane plane() const;
    bool enableDogleg() const;
    double doglegLength() const;

    Acad::ErrorStatus doglegLength(int, double&) const;
    AcDbObjectId arrowSymbolId() const;
    Acad::ErrorStatus getArrowSymbolId(int, AcDbObjectId&) const;
    AcDbObjectId arrowSymbolId(int) const;
    Acad::ErrorStatus getArrowSize(int, double&) const;
    AcDbMLeaderStyle::ContentType contentType() const;
    AcDbObjectId textStyleId() const;

    AcCmColor textColor() const;
    double textHeight() const;
    bool enableFrameText() const;
    AcDbMText* mtext() const;
    AcDbObjectId blockContentId() const;
    AcCmColor blockColor() const;
    AcGeScale3d blockScale() const;
    double blockRotation() const;
    AcDbMLeaderStyle::BlockConnectionType blockConnectionType() const;
    bool enableAnnotationScale() const;
    AcDbObjectId MLeaderStyle();
    void* getContextDataManager() const;
    Acad::ErrorStatus getBlockPosition(AcGePoint3d&) const;
    Acad::ErrorStatus getTextLocation(AcGePoint3d&) const;
    Acad::ErrorStatus getToleranceLocation(AcGePoint3d&) const;
    AcDbMLeaderStyle::TextAttachmentDirection textAttachmentDirection() const;
    bool extendLeaderToText() const;

    AcDbMLeaderStyle::TextAttachmentType textAttachmentType(AcDbMLeaderStyle::LeaderDirectionType) const;
    AcDbMLeaderStyle::TextAttachmentType textAttachmentType() const;
    AcDbMLeaderStyle::TextAngleType textAngleType() const;
    AcDbMLeaderStyle::TextAlignmentType textAlignmentType() const;

    Acad::ErrorStatus recomputeBreakPoints();
    Acad::ErrorStatus postMLeaderToDb(AcDbDatabase*);
    Acad::ErrorStatus updateLeaderLinePosition();
    Acad::ErrorStatus updateContentScale(AcDbMLeaderObjectContextData*);
    Acad::ErrorStatus removeLeaderLineRefAssoc(int) const;

    Acad::ErrorStatus addLeader(int&);
    Acad::ErrorStatus moveMLeader(const AcGeVector3d&, MoveType, bool = true);
    Acad::ErrorStatus removeLeader(int);
    Acad::ErrorStatus numVertices(int, int&) const;

    Acad::ErrorStatus addLeaderLine(int, int&);
    Acad::ErrorStatus addLeaderLine(const AcGePoint3d&, int&);
    Acad::ErrorStatus addFirstVertex(int, const AcGePoint3d&);
    Acad::ErrorStatus addLastVertex(int, const AcGePoint3d&);

    Acad::ErrorStatus removeLeaderLine(int);
    Acad::ErrorStatus removeFirstVertex(int);
    Acad::ErrorStatus removeLastVertex(int);

    Acad::ErrorStatus getBlockAttributeValue(const AcDbObjectId&, AcDbAttribute*&) const;
    Acad::ErrorStatus getBlockAttributeValue(const AcDbObjectId&, ACHAR*&) const;
    Acad::ErrorStatus getContentGeomExtents(AcDbExtents&) const;
    Acad::ErrorStatus getLeaderIndexes(AcDbIntArray&) const;
    Acad::ErrorStatus getLeaderLineIndexes(AcDbIntArray&) const;
    Acad::ErrorStatus getDoglegDirection(int, AcGeVector3d&) const;
    Acad::ErrorStatus getLeaderIndex(int, int&) const;
    Acad::ErrorStatus getLeaderLineIndexes(int, AcDbIntArray&) const;
    Acad::ErrorStatus getLeaderLineType(int, AcDbMLeaderStyle::LeaderType&) const;
    Acad::ErrorStatus getLeaderLineColor(int,AcCmColor&) const;
    Acad::ErrorStatus getLeaderLineTypeId(int, AcDbObjectId&) const;
    Acad::ErrorStatus getLeaderLineWeight(int, AcDb::LineWeight&) const;
    Acad::ErrorStatus getFirstVertex(int, AcGePoint3d&) const;
    Acad::ErrorStatus getLastVertex(int, AcGePoint3d&) const;
    Acad::ErrorStatus getVertex(int, int, AcGePoint3d&) const;

    Acad::ErrorStatus setScale(double);
    void setPlane(const AcGePlane&);
    Acad::ErrorStatus setEnableDogleg(bool);
    Acad::ErrorStatus setDoglegLength(int, double);
    Acad::ErrorStatus setDoglegLength(double);
    Acad::ErrorStatus setArrowSymbolId(const AcDbObjectId&);
    Acad::ErrorStatus setArrowSymbolId(int, const AcDbObjectId&);
    Acad::ErrorStatus setArrowSize(double);
    Acad::ErrorStatus setArrowSize(int, double);
    Acad::ErrorStatus setContentType(AcDbMLeaderStyle::ContentType);
    Acad::ErrorStatus setTextStyleId(const AcDbObjectId& textStyleId);
    Acad::ErrorStatus setTextAttachmentDirection(AcDbMLeaderStyle::TextAttachmentDirection);
    Acad::ErrorStatus setExtendLeaderToText(bool);
    Acad::ErrorStatus setLeaderLineType(AcDbMLeaderStyle::LeaderType);
    Acad::ErrorStatus setLeaderLineType(int, AcDbMLeaderStyle::LeaderType);
    Acad::ErrorStatus setDoglegDirection(int, const AcGeVector3d&);
    Acad::ErrorStatus setFirstVertex(int, const AcGePoint3d&);
    Acad::ErrorStatus setLastVertex(int, const AcGePoint3d&);
    Acad::ErrorStatus setVertex(int, int, const AcGePoint3d&);
    Acad::ErrorStatus setLandingGap(double);
    Acad::ErrorStatus setEnableLanding(bool);
    Acad::ErrorStatus setLeaderLineColor(const AcCmColor&);
    Acad::ErrorStatus setLeaderLineColor(int,const AcCmColor&);
    Acad::ErrorStatus setLeaderLineTypeId(const AcDbObjectId&);
    Acad::ErrorStatus setLeaderLineTypeId(int, const AcDbObjectId&);
    Acad::ErrorStatus setLeaderLineWeight(AcDb::LineWeight);
    Acad::ErrorStatus setLeaderLineWeight(int, AcDb::LineWeight);
    Acad::ErrorStatus setBlockAttributeValue(const AcDbObjectId&, const AcDbAttribute*);
    Acad::ErrorStatus setBlockAttributeValue(const AcDbObjectId&, const ACHAR*);
    Acad::ErrorStatus setTextAttachmentType(AcDbMLeaderStyle::TextAttachmentType, AcDbMLeaderStyle::LeaderDirectionType);
    Acad::ErrorStatus setTextAttachmentType(AcDbMLeaderStyle::TextAttachmentType);
    Acad::ErrorStatus setTextAngleType(AcDbMLeaderStyle::TextAngleType);
    Acad::ErrorStatus setTextAlignmentType(AcDbMLeaderStyle::TextAlignmentType);
    Acad::ErrorStatus setTextColor(const AcCmColor&);
    Acad::ErrorStatus setTextHeight(double);
    Acad::ErrorStatus setEnableFrameText(bool);
    Acad::ErrorStatus setMText(const AcDbMText*);
    Acad::ErrorStatus setBlockContentId(const AcDbObjectId&);
    Acad::ErrorStatus setBlockColor(const AcCmColor&);
    Acad::ErrorStatus setBlockScale (const AcGeScale3d&);
    Acad::ErrorStatus setBlockRotation(double);
    Acad::ErrorStatus setBlockConnectionType(AcDbMLeaderStyle::BlockConnectionType);
    Acad::ErrorStatus setEnableAnnotationScale(bool);
    Acad::ErrorStatus setMLeaderStyle(const AcDbObjectId&);
    Acad::ErrorStatus setContextDataManager(void*);
    Acad::ErrorStatus setBlockPosition(const AcGePoint3d&);
    Acad::ErrorStatus setTextLocation(const AcGePoint3d&);
    Acad::ErrorStatus setToleranceLocation(const AcGePoint3d&);

    Acad::ErrorStatus connectionPoint(const AcGeVector3d&, AcGePoint3d&) const;
    Acad::ErrorStatus connectionPoint(const AcGeVector3d&, AcGePoint3d&, AcDbMLeaderStyle::TextAttachmentDirection) const;

    bool isOverride(PropertyOverrideType propertyType) const;
    Acad::ErrorStatus getOverridedMLeaderStyle(AcDbMLeaderStyle&);
    Acad::ErrorStatus setOverride(PropertyOverrideType, bool = true);

    // virtuals


    virtual void objectClosed(const AcDbObjectId&);
    virtual void modified(const AcDbObject*);

    virtual Acad::ErrorStatus subClose();
    virtual Acad::ErrorStatus subErase(Adesk::Boolean);

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;

    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
};
