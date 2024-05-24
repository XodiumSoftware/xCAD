// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcGe/AcGeVector3d.h"
#include "AcGi/AcGiGlobal.h"
#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcGiViewport: public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcGiViewport);

    virtual AcGeVector3d viewDir() const;
    virtual Adesk::Boolean doInversePerspective(AcGePoint3d&) const = 0;
    virtual Adesk::Boolean doPerspective(AcGePoint3d&) const = 0;
    virtual Adesk::Boolean getFrontAndBackClipValues(Adesk::Boolean&,Adesk::Boolean&,double&,double&) const = 0;
    virtual Adesk::Boolean isPerspective() const = 0;
    virtual Adesk::Boolean layerVisible(const AcDbObjectId&) const;
    virtual Adesk::Int16 acadWindowId() const = 0;
    virtual Adesk::ULongPtr viewportId() const = 0;
    virtual const AcGiContextualColors* contextualColors() const;
    virtual double linetypeGenerationCriteria() const = 0;
    virtual double linetypeScaleMultiplier() const = 0;
    virtual void getCameraLocation(AcGePoint3d&) const = 0;
    virtual void getCameraTarget(AcGePoint3d&) const = 0;
    virtual void getCameraUpVector(AcGeVector3d&) const = 0;
    virtual void getEyeToModelTransform(AcGeMatrix3d&) const = 0;
    virtual void getEyeToWorldTransform(AcGeMatrix3d&) const = 0;
    virtual void getModelToEyeTransform(AcGeMatrix3d&) const = 0;
    virtual void getNumPixelsInUnitSquare(const AcGePoint3d&,AcGePoint2d&,bool = true) const = 0;
    virtual void getViewportDcCorners(AcGePoint2d&,AcGePoint2d&) const = 0;
    virtual void getWorldToEyeTransform(AcGeMatrix3d&) const = 0;
};
