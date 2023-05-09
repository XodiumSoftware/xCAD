// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObjectId.h"
#include "AcGe/AcGePoint3d.h"
#include "AcGi/AcGiGlobal.h"
#include "AcRx/AcRxClass.h"

template<> struct T_AcArrayAllocatorSelector<AcDbGripData, false> {
  typedef AcArrayMemCopyReallocator<AcDbGripData> Allocator; }; //AcDbGripData can use fast MemCopyReallocator
typedef AcArray< AcDbGripData*, AcArrayMemCopyReallocator<AcDbGripData*> > AcDbGripDataPtrArray;
typedef AcArray< AcDbGripData, AcArrayObjectCopyReallocator<AcDbGripData> > AcDbGripDataArray;

typedef AcDbGripOperations::ReturnValue (*GripInputPointPtr)(AcDbGripData*,const AcDbObjectId&,bool&,AcGePoint3d&,const AcGiViewport&,const AcDbObjectId&,bool,int,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,const AcGePoint3d&,AcDb::OsnapMask,const AcArray<AcDbCustomOsnapMode*>&,AcDb::OsnapMask,const AcArray<AcDbCustomOsnapMode*>&,const AcDbObjectIdArray&,const AcDbObjectIdArray&,const AcArray<Adesk::GsMarker>&,const AcDbObjectIdArray&,const AcDbObjectIdArray&,const AcArray<Adesk::GsMarker>&,const AcArray<AcGeCurve3d*>&,const AcGePoint3d&);
typedef AcDbGripOperations::ReturnValue (*GripOperationPtr)(AcDbGripData*,const AcDbObjectId&,int);
typedef bool (*GripWorldDrawPtr)(AcDbGripData*,AcGiWorldDraw*,const AcDbObjectId&,AcDbGripOperations::DrawType,AcGePoint3d*,double);
typedef const ACHAR* (*GripToolTipPtr)(AcDbGripData*);
typedef void (*ContextMenuItemIndexPtr)(unsigned int);
typedef void (*GripDimensionPtr)(AcDbGripData*,const AcDbObjectId&,double,AcDbDimDataPtrArray&);
typedef void (*GripOpStatusPtr)(AcDbGripData*,const AcDbObjectId&,AcDbGripOperations::GripStatus);
typedef void (*GripViewportDrawPtr)(AcDbGripData*,AcGiViewportDraw*,const AcDbObjectId&,AcDbGripOperations::DrawType,AcGePoint3d*,int);
typedef AcDbGripOperations::ReturnValue (*GripRtClkHandler)(AcDbGripDataArray&,const AcDbObjectIdArray&,ACHAR*&,HMENU&,ContextMenuItemIndexPtr&);

//BRX START
class BrxDbGripDataImp;
//BRX END
/** _ */
class BRX_IMPORTEXPORT AcDbGripData
{
public:
    AcDbGripData();
    AcDbGripData(const AcDbGripData&);
    AcDbGripData(const AcGePoint3d&,void*,GripOperationPtr = NULL,GripOperationPtr = NULL,GripRtClkHandler = NULL,GripWorldDrawPtr = NULL,GripViewportDrawPtr = NULL,GripOpStatusPtr = NULL,GripToolTipPtr = NULL,GripDimensionPtr = NULL,GripDimensionPtr = NULL,unsigned int = 0,AcGePoint3d* = NULL,GripInputPointPtr = NULL);
    AcDbGripData(const AcGePoint3d&,void*,AcRxClass*,GripOperationPtr = NULL,GripOperationPtr = NULL,GripRtClkHandler = NULL,GripWorldDrawPtr wd = NULL, GripViewportDrawPtr = NULL,GripOpStatusPtr = NULL,GripToolTipPtr = NULL,GripDimensionPtr = NULL,GripDimensionPtr = NULL,unsigned int = 0,AcGePoint3d* = NULL,GripInputPointPtr = NULL);
    ~AcDbGripData();

    AcGePoint3d* alternateBasePoint() const;
    AcRxClass* appDataAcRxClass() const;
    bool areModeKeywordsDisabled() const;
    bool drawAtDragImageGripPoint() const;
    bool forcedPickOn() const;
    bool gizmosEnabled() const;
    bool isRubberBandLineDisabled() const;
    bool mapGripHotToRtClk() const;
    bool skipWhenShared() const;
    bool triggerGrip() const;
    const AcGePoint3d& gripPoint() const;
    GripDimensionPtr hotGripDimensionFunc() const;
    GripDimensionPtr hoverDimensionFunc() const;
    GripInputPointPtr inputPointFunc() const;
    GripOperationPtr hotGripFunc() const;
    GripOperationPtr hoverFunc() const;
    GripOpStatusPtr gripOpStatFunc() const;
    GripRtClkHandler rtClk() const;
    GripToolTipPtr toolTipFunc() const;
    GripViewportDrawPtr viewportDraw() const;
    GripWorldDrawPtr worldDraw() const;
    unsigned int bitFlags() const;
    void disableModeKeywords(bool);
    void disableRubberBandLine(bool);
    void setAllData(const AcGePoint3d&,void*,GripOperationPtr = NULL,GripOperationPtr = NULL,GripRtClkHandler = NULL,GripWorldDrawPtr = NULL,GripViewportDrawPtr = NULL,GripOpStatusPtr = NULL,GripToolTipPtr = NULL,GripDimensionPtr = NULL,GripDimensionPtr = NULL,unsigned int = 0,AcGePoint3d* = NULL,GripInputPointPtr = NULL,AcRxClass* = NULL);
    void setAlternateBasePoint(AcGePoint3d*);
    void setAppData(void*);
    void setAppDataAcRxClass(AcRxClass*);
    void setBitFlags(unsigned int);
    void setDrawAtDragImageGripPoint(bool);
    void setForcedPickOn(bool);
    void setGizmosEnabled(bool);
    void setGripOpStatFunc(GripOpStatusPtr);
    void setGripPoint(const AcGePoint3d&);
    void setHotGripDimensionFunc(GripDimensionPtr);
    void setHotGripFunc(GripOperationPtr);
    void setHoverDimensionFunc(GripDimensionPtr);
    void setHoverFunc(GripOperationPtr);
    void setInputPointFunc(GripInputPointPtr);
    void setMapGripHotToRtClk(bool);
    void setRtClk(GripRtClkHandler);
    void setSkipWhenShared(bool);
    void setToolTipFunc(GripToolTipPtr);
    void setTriggerGrip(bool);
    void setViewportDraw(GripViewportDrawPtr);
    void setWorldDraw(GripWorldDrawPtr);
    void* appData() const;

    AcDbGripData& operator=(const AcDbGripData&);
//BRX START
private:
    friend class BrxDbGripDataImp;
    BrxDbGripDataImp* m_pBrxImp;
//BRX END
};
