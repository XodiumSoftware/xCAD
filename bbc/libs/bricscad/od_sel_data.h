// od_sel_data.h : OdBoundary and OdSelectionData class declaration

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "od_api_exports.h"
#include "SmartPtr.h"
#include "Ge/GeCurve3dPtrArray.h"

class OdGiPathNode;
class OdDbRegion;
typedef OdSmartPtr<OdDbRegion> OdDbRegionPtr;
typedef OdSmartPtr<const OdDbRegion> OdDbRegionConstPtr;
class OdDbCurve;
typedef OdSmartPtr<OdDbCurve> OdDbCurvePtr;
typedef OdArray<OdDbCurvePtr> OdDbCurvePtrArray;
class OdGePlane;
class OdDbFullSubentPath;
class OdDbSelectionMethod;
class OdDbSelectionSet;

// Transients, that are not database resident but can be selected and highlighted
class ODAPI OdTransient : public OdRxObject
{
    ODRX_DECLARE_MEMBERS(OdTransient);
    virtual ~OdTransient() {}
    virtual const OdChar* name() const = 0; // friendly name displayed in quad, properties, etc
    virtual void highlight(bool bHighlight) const = 0;
    virtual bool isOnTop() const { return true; }
};
typedef OdSmartPtr<OdTransient> OdTransientPtr;

// Use ODRX_NO_CONS_DEFINE_MEMBERS_DXFNAME to define children of OdTransient
// This will allow us to define quad commands for such entities from the CUI dialog
//
#define ODRX_NO_CONS_DEFINE_MEMBERS_DXFNAME(ClassName,ParentClass,DxfName) \
ODRX_DEFINE_MEMBERS2(ClassName,ParentClass,0,0,0,0,OD_T(#ClassName),OD_T(#DxfName),OdString::kEmpty,0) \
ODRX_DEFINE_PSEUDOCONSTRUCTOR(ClassName,EMPTY_CONSTR)

// Special type of transient (transient drawable), is not database resident and selected as OdGiPathNode
class ODAPI OdDrawableNode : public OdTransient
{
public:
    ODRX_DECLARE_MEMBERS(OdDrawableNode);
    virtual ~OdDrawableNode() {}
    virtual const OdGiPathNode* giPathNode() const = 0;
    virtual bool isValid() const = 0;
};
using OdDrawableNodePtr = OdSmartPtr<OdDrawableNode>;

// Special type of transient, is computed from geometry in the drawing. 
// Contains an array of loops being a boundary of a planar domain.
// The first item is an outer loop, the rest are inner ones.
class ODAPI OdBoundary : public OdTransient
{
public:
    ODRX_DECLARE_MEMBERS(OdBoundary);
    virtual ~OdBoundary() {}
    //Plane the loops belong to
    virtual const OdGePlane* plane() const = 0;
    //Path to a face if the boundary belongs to any, may be empty
    virtual const OdDbFullSubentPath& path() const = 0;
    //Returns true if an edge overlaps with an edge of the face it belongs to, if any
    virtual bool overlapsWithFaceEdge(OdUInt32 iLoop,OdUInt32 iEdge) const = 0;
    //Service method to get the boundary as constant OdDbRegion, not allowed for modification or adding to database.
    //Return value of true guarantees non null OdDbRegionPtr.
    virtual bool getAsConstRegion(OdDbRegionConstPtr& pRegion) const = 0 ;
    //Service method to get the boundary as OdDbRegion, allowed for modification.
    //Return value of true guarantees non null OdDbRegionPtr.
    virtual bool getAsRegionCopy(OdDbRegionPtr& pRegion) const = 0;
    // Gets the boundary's loops as an array of dbcurves, one dbcurve per loop. If a loop is composed of a set of
    // gecurves, a polyline is created else a single appropriate curve. If whichLoops==eOuter, then only outer loop,
    // if eInner then all inner loops and if eOuter|eInner then the outermost loop is the first curve followed 
    // by the inner loops. The curves are not added to the database. If no curves are found, function returns false.
    enum {eOuterLoop=1, eInnerLoops=2};
    virtual bool getAsDbCurves(OdDbCurvePtrArray& boundingCurves, int whichLoops) const = 0;
    // gets the boundary's loops as an array of gecurves, one gecurve array per loop. Rest is same as getAsDbCurves.
    virtual bool getAsGeCurves(OdArray<OdGeCurve3dPtrArray>& boundingGeCurves, int whichLoops) const = 0;
    virtual OdGsMarker gsMarker() const = 0;
};
typedef OdSmartPtr<OdBoundary> OdBoundaryPtr;

class ODAPI OdSelectionData: public OdRxObject
{
public:
    ODRX_DECLARE_MEMBERS(OdSelectionData);
    virtual ~OdSelectionData() {}

    // use this function instead of createObject()
    static OdSmartPtr<OdSelectionData> create();

    virtual OdUInt32 size() const = 0;

    enum Type {eEntity=1, eSubent=2, eTransient=4};
    virtual int hasTypes() const = 0; // tells us if it has entities, subentities or virtual entities
    virtual const Type typeAt(OdUInt32 index) const = 0;

    virtual const OdDbObjectId& entityAt(OdUInt32 index) const = 0;
    virtual const OdDbFullSubentPath& subentAt(OdUInt32 index) const = 0;
    virtual const OdTransient* transientAt(OdUInt32 index) const = 0;
    virtual const OdDbSelectionMethod* methodAt(OdUInt32 index) const = 0;
    virtual const OdDbSelectionSet* selectionSet() const = 0; // gets all the database resident entities/subents as a selection set

    virtual bool append(const OdDbObjectId& id, const OdDbSelectionMethod* pMethod) = 0;
    virtual bool append(const OdDbFullSubentPath& subent, const OdDbSelectionMethod* pMethod) = 0;
    virtual bool append(const OdTransient* pTransient, const OdDbSelectionMethod* pMethod) = 0;

    //it is in client's repsonsibility to check pSSet pointer
    virtual void append(const OdDbSelectionSet* pSSet) = 0;

    //it is in client's repsonsibility to check pSelData pointer
    virtual void append(const OdSelectionData* pSelData) = 0;

    virtual bool insertAt(OdUInt32 index, const OdDbObjectId& id, const OdDbSelectionMethod* pMethod) = 0;
    virtual bool insertAt(OdUInt32 index, const OdDbFullSubentPath& subent, const OdDbSelectionMethod* pMethod) = 0;
    virtual bool insertAt(OdUInt32 index, const OdTransient* pTransient, const OdDbSelectionMethod* pMethod) = 0;

    virtual bool contains(const OdDbObjectId& id) const = 0;
    virtual bool contains(const OdDbFullSubentPath& subent) const = 0;
    virtual bool contains(const OdTransient* pTransient) const = 0;
    virtual bool contains(const OdSelectionData* pSelData) const = 0;

    virtual void removeAt(OdUInt32 index) = 0;
    virtual bool remove(const OdDbObjectId& id) = 0;
    virtual bool remove(const OdDbFullSubentPath& subent) = 0;
    virtual bool remove(const OdTransient* pTransient) = 0;

    virtual void clear() = 0;
};
typedef OdSmartPtr<OdSelectionData> OdSelectionDataPtr;

class ODAPI OdTransientCollector
{
public:
    OdTransientCollector() {}
    virtual ~OdTransientCollector() {}

    virtual void selected(const OdGiPathNode& pathNode, const OdGiViewport& viewInfo) = 0;
    virtual bool append(OdSelectionData* pSelData, const OdDbSelectionMethod* pMethod) = 0;
};

class ODAPI OdTransientCollectorManager
{
protected:
    virtual ~OdTransientCollectorManager() {}

public:
    virtual void add(OdTransientCollector* pTransientCollector) = 0;
    virtual void remove(OdTransientCollector* pTransientCollector) = 0;
    virtual bool isCommandActive() const = 0;
};

OdTransientCollectorManager* odTransientCollectorManager();
