// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbLayoutManager.h"

/** _ */
class AcApLayoutManager: public AcDbLayoutManager
{
public:
    virtual Acad::ErrorStatus getClipBoundaryElaboration(AcDbObjectId,AcGePoint2dArray*&) = 0;
    virtual Acad::ErrorStatus pointInViewports(const AcGePoint3d&,AcDbObjectIdArray&) = 0;
    virtual ACHAR* getNextNewLayoutName(AcDbDatabase* = NULL) = 0; //deprecated
    virtual Adesk::Boolean createViewports() = 0;
    virtual Adesk::Boolean showPageSetup() = 0;
    virtual Adesk::Boolean showPaperBackground() = 0;
    virtual Adesk::Boolean showPaperMargins() = 0;
    virtual Adesk::Boolean showPrintBorder() = 0;
    virtual Adesk::Boolean showTabs() = 0;
    virtual const ACHAR* findActiveTab() = 0; //deprecated
    virtual int pageSetup(AcDbObjectId = AcDbObjectId::kNull,void* = NULL,Adesk::Boolean = TRUE) = 0;
    virtual void setCreateViewports(Adesk::Boolean) = 0;
    virtual void setDefaultPlotConfig(AcDbObjectId) = 0;
    virtual void setShowPageSetup(Adesk::Boolean) = 0;
    virtual void setShowPaperBackground(Adesk::Boolean) = 0;
    virtual void setShowPaperMargins(Adesk::Boolean) = 0;
    virtual void setShowPrintBorder(Adesk::Boolean) = 0;
    virtual void setShowTabs(Adesk::Boolean) = 0;
    virtual void updateCurrentPaper(Adesk::Boolean = Adesk::kFalse) = 0;
    virtual void updateLayoutTabs() = 0;
    virtual void setCaptureOnLayoutSwitch(Adesk::Boolean) = 0;

    // since V24
    virtual Acad::ErrorStatus getActiveTab(AcString&) = 0;
    virtual Acad::ErrorStatus generateNextNewLayoutName(AcString&, AcDbDatabase* = NULL) = 0;
    virtual Acad::ErrorStatus createLayoutFromTemplate(const ACHAR*, AcDbObjectId&, const ACHAR*, const ACHAR*, AcDbDatabase* = NULL) = 0;
};
