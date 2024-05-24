// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDbAssocGlobal.h"
#include "AcDbCompoundObjectId.h"

class BRX_IMPORTEXPORT AcDbAssocActionParam : public AcDbObject
{
public:
    ACDB_DECLARE_MEMBERS(AcDbAssocActionParam)

    AcDbAssocActionParam();
    ~AcDbAssocActionParam() noexcept = default;

    const AcString& name() const;
    AcDbObjectId parentAction() const;
    AcDbAssocStatus status(bool) const;

    Acad::ErrorStatus getCompoundObjectIds(bool, bool, AcArray<AcDbCompoundObjectId>&) const;
    Acad::ErrorStatus setStatus(AcDbAssocStatus, bool = true, bool = false);

    virtual Acad::ErrorStatus detachDependencies();
    virtual Acad::ErrorStatus getDependencies(bool, bool, AcDbObjectIdArray&) const;
    virtual Acad::ErrorStatus makeParamConstant();
    virtual Acad::ErrorStatus makeParamEmpty(bool);
    virtual Acad::ErrorStatus setName(const AcString&);
    virtual Acad::ErrorStatus transformConstantGeometry(const AcGeMatrix3d&);

    virtual void auditAssociativeData(AcDbAssocStatus&);
    virtual void clonePersSubentNamingDataOverride(AcDbAssocPersSubentManagerCloner*);
    virtual void collectPersSubentNamingDataOverride(AcDbPersStepIdArray&, AcDbPersSubentIdArray&) const;
};
