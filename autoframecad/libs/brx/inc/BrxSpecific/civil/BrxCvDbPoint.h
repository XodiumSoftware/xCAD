// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil Point functionality + interfaces

#include "Misc/AcArray.h"
#include "AcGe/AcGePoint3d.h"
#include "AcRx/AcRxClass.h"
#include "AcRx/AcRxObject.h"
#include "AcDb/AcDbEntity.h"
#include "AcDb/AcDbObjectId.h"

#include "BrxSpecific/civil/BrxCvDbEntity.h"
#include "BrxSpecific/civil/BrxCvDbObject.h"
#include "BrxSpecific/civil/BrxCvDbSubObject.h"

class BrxCvDbPointReferencedEntity;

typedef AcSharedPtr<BrxCvDbPointReferencedEntity> BrxCvDbPointReferencedEntityPtr;

/** Civil Db Point base class */
class BRX_EXPORT BrxCvDbPoint : public BrxCvDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbPoint);
    BrxCvDbPoint();
    virtual ~BrxCvDbPoint();

    // return this point's number
    Adesk::UInt32 number() const;
    // sets this point's number; returns false if the number is already taken
    bool setNumber(const Adesk::UInt32 number);

    const ACHAR* rawDescription() const;
    bool         setRawDescription(const ACHAR* szDescription);

    const ACHAR* fullDescription() const;

    double       easting() const;
    bool         setEasting(const double easting);

    double       northing() const;
    bool         setNorthing(const double northing);

    double       elevation() const;
    bool         setElevation(const double elevation);

    AcGePoint3d  position() const;
    bool         setPosition(const AcGePoint3d& value);

    // returns all point group ids which contain 'this' point
    AcDbObjectIdArray pointGroupsIds() const;
    // returns all point group names which contain 'this' point
    AcStringArray     pointGroupsNames() const;


    // labeling settings

    // returns symbol style id - can be cast to BrxCvDbSymbolStyle
    AcDbObjectId symbolId() const;
    // sets symbol style id - must be some kind of BrxCvDbSymbolStyle
    bool setSymbolId(const AcDbObjectId& symbolId);

    // returns label style id - can be cast to BrxCvDbLabelStyle
    AcDbObjectId labelId() const;
    // sets label style id - must be some kind of BrxCvDbLabelStyle
    bool setLabelId(const AcDbObjectId& labelId);

    // returns the position the point's label
    AcGePoint3d  labelPosition() const;
    // sets the position of point's label
    bool setLabelPosition(const AcGePoint3d& position);

    // returns the symbol rotation in radians
    double symbolRotation() const;
    // sets the symbol rotation in radians
    bool   setSymbolRotation(const double rotation);

    // returns the label rotation in radians
    double labelRotation() const;
    // sets the label rotation in radians
    bool setLabelRotation(const double rotation);

    // returns if label is pinned; when set the leader vertices and label position are not moved along with point's position
    bool isLabelPinned() const;
    // sets if label is pinned; when set the leader vertices and label position are not moved along with point's position
    bool setLabelPinned(const bool value);

    // returns if label is in 'dragged' state; when in dragged state a leader and dragged state components are drawn
    bool isLabelDragged() const;

    // returns label's leader vertices; only visible in dragged state
    AcGePoint3dArray labelLeaderVertices() const;
    // sets or unsets label's leader vertices; only visible in dragged state
    bool setLabelLeaderVertices(const AcGePoint3dArray& vertices);

    // resets the label position, leader vertices, symbol rotation and label rotation
    bool resetLabel();

    // number of referenced entities; defined by label style text components
    Adesk::UInt32 referencedEntityCount() const;
    // returns a single referenced entity at given index; defined by label style text components
    BrxCvDbPointReferencedEntityPtr referencedEntityAt(Adesk::UInt32 index) const;

    // if needed updates point groups based on new point data
    bool update();
};


/** Civil Db Point Referenced Entity class */
class BRX_EXPORT BrxCvDbPointReferencedEntity : public BrxCvDbSubObject
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbPointReferencedEntity);

    BrxCvDbPointReferencedEntity();
    virtual ~BrxCvDbPointReferencedEntity();

    BrxCvDbPointReferencedEntity(const BrxCvDbPointReferencedEntity& other) = delete;
    BrxCvDbPointReferencedEntity& operator=(const BrxCvDbPointReferencedEntity& other) = delete;

    AcDbObjectId id() const;
    bool setId(const AcDbObjectId& value);

    AcRxClass* type() const;
};


/** Civil Db Point Group base class */
class BRX_EXPORT BrxCvDbPointGroup : public BrxCvDbObject
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbPointGroup);

    BrxCvDbPointGroup();
    virtual ~BrxCvDbPointGroup();

    // returns true if this group contains point with this 'number'
    bool hasPoint(const Adesk::UInt32 number) const;
    // returns true if this group contains point with this 'number' and sets pointId to the AcDbObjectId of the same BrxCvDbPoint
    bool hasPoint(const Adesk::UInt32 number, AcDbObjectId& pointId) const;
    // returns a number of points in this group
    Adesk::UInt32 pointCount() const;
    // returns all the AcDbObjectIds of the BrxCvDbPoints in this group
    AcDbObjectIdArray pointIds() const;

    // returns if this group can be edited
    bool isEditable() const;

    // returns true if the given point satisfies all the filters
    bool isApplicable(const BrxCvDbPoint* point) const;

    const ACHAR* includeNumbers() const;
    const ACHAR* excludeNumbers() const;

    const ACHAR* includeElevations() const;
    const ACHAR* excludeElevations() const;

    const ACHAR* includeRawDescriptions() const;
    const ACHAR* excludeRawDescriptions() const;

    const ACHAR* includeFullDescriptions() const;
    const ACHAR* excludeFullDescriptions() const;

    const ACHAR* includeNames() const;
    const ACHAR* excludeNames() const;

    const ACHAR* includeUserAttributesKeys() const;
    const ACHAR* excludeUserAttributesKeys() const;

    const ACHAR* includeUserAttributesValues() const;
    const ACHAR* excludeUserAttributesValues() const;

    bool setIncludeNumbers(const ACHAR* szFilter);
    bool setExcludeNumbers(const ACHAR* szFilter);

    bool setIncludeElevations(const ACHAR* szFilter);
    bool setExcludeElevations(const ACHAR* szFilter);

    bool setIncludeRawDescriptions(const ACHAR* szFilter);
    bool setExcludeRawDescriptions(const ACHAR* szFilter);

    bool setIncludeFullDescriptions(const ACHAR* szFilter);
    bool setExcludeFullDescriptions(const ACHAR* szFilter);

    bool setIncludeNames(const ACHAR* szFilter);
    bool setExcludeNames(const ACHAR* szFilter);

    bool setIncludeUserAttributesKeys(const ACHAR* szFilter);
    bool setExcludeUserAttributesKeys(const ACHAR* szFilter);

    bool setIncludeUserAttributesValues(const ACHAR* szFilter);
    bool setExcludeUserAttributesValues(const ACHAR* szFilter);

    bool updateNeeded() const;

    // updates the points in this group based on filters
    bool update();
};
