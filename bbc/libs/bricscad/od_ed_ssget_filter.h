// od_ed_ssget_filter.h : OdEdSSGetFilter, OdEdSSGetFilter2, OdEdSelectionSetService
//                        classes definition

// Copyright © Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "od_ed_input.h"

class OdTransient;
typedef OdArray<OdDbFullSubentPath> OdDbFullSubentPathArray;
typedef OdArray<OdGeIntArray> OdGeArrayIntArray;


class OdEdSelectionSetService
{
public:
    virtual ~OdEdSelectionSetService() noexcept = default;
    virtual OdResult add(resbuf* entToAdd, const OdDbFullSubentPath* subEntToHighlight = 0,
        const OdDbObjectId* entselSubEntToAdd = 0) noexcept = 0;
    virtual OdResult addSubentity(resbuf* entToAdd, const OdDbFullSubentPath& subEntToAdd) noexcept = 0;
    virtual OdResult remove(int idx) noexcept = 0;
    virtual OdResult remove(const OdIntArray& indices) noexcept = 0;
    virtual OdResult removeSubentity(int idx, int subEntIdx) noexcept = 0;
    virtual OdResult removeSubentities(int idx, const OdIntArray& subEntIndices) noexcept = 0;
    virtual OdResult ssNameX(bool subSelection, int idx, resbuf*& ssNameXResult) noexcept = 0;
    virtual OdResult ssNameSubentityX(bool subSelection, int idx, int subEntIdx,
        resbuf*& ssNameXResult) noexcept = 0;
    virtual OdResult ssNameSubentities(bool subSelection, int idx,
        OdDbFullSubentPathArray& subEntities) noexcept = 0;
    virtual OdResult highlight(int idx, const OdDbFullSubentPath& subEntToHighlight) noexcept = 0;
};

class OdEdSSGetFilter : public virtual OdEdInputContextReactor
{
public:
enum ESSGetFlags
{
    eNormal         = 0,
    ePickPoints     = 1,
    eDuplicates     = 1 << 1,
    eNestedEntities = 1 << 2,
    eSubEntities    = 1 << 3,
    eSinglePick     = 1 << 4,
    ePickfirstSet   = 1 << 5,
    ePreviousSet    = 1 << 6,
    eSubSelection   = 1 << 7
};

enum ESSGetModes
{
    eWin = 1,
    eCross,
    eBox,
    eLast,
    eEntity,
    eAll,
    eFence,
    eCPoly,
    eWPoly,
    ePick,
    eEvery,
    eXten,
    eGroup,
    ePrevious
};

public:
    virtual void ssgetAddFilter(int flags, OdEdSelectionSetService&,
        const OdDbObjectIdArray& ss, const OdDbObjectIdArray& subSS) {}
    virtual void ssgetRemoveFilter(int flags, OdEdSelectionSetService&,
        const OdDbObjectIdArray& ss, const OdDbObjectIdArray& subSS,
        OdGeIntArray& indicesToRemove, OdGeArrayIntArray& subentIndicesToRemove) {}
    virtual void ssgetAddFailed(int flags, int mode, OdEdSelectionSetService&,
        const OdDbObjectIdArray& ss, resbuf* selPoints) {}
    virtual void ssgetRemoveFailed(int flags, int mode, OdEdSelectionSetService&,
        const OdDbObjectIdArray& ss, resbuf* selPoints, OdGeIntArray& indicesToRemove,
        OdGeArrayIntArray& subentIndicesToRemove) {}
    virtual void endSSGet(OdEd::EPromptStatus, int flags, OdEdSelectionSetService&,
        const OdDbObjectIdArray& ss) {}
    virtual void endEntsel(OdEd::EPromptStatus, const OdDbObjectId& retEntity,
        const OdGePoint3d& retPoint, OdEdSelectionSetService&) {}
    virtual void ssgetAddFilter(int flags, const OdArray<const OdTransient*>& transients) {}
    virtual void ssgetRemoveFilter(int flags, const OdArray<const OdTransient*>& transients) {}
};


class OdEdSSGetFilter2 : public virtual OdEdSSGetFilter
{
public:
    virtual void ssgetRolloverFilter(const OdDbFullSubentPath& subEnt,
        OdDbFullSubentPath& toHighlight) {}
};


class OdEdPreselectReactor
{
public:
    virtual ~OdEdPreselectReactor() noexcept = default;
    virtual void dbEntitySelected(const OdDbFullSubentPath& subEnt, const OdGePoint3d* pickPt) {}
    virtual void transientSelected(const OdTransient* pTransient) {}
};
