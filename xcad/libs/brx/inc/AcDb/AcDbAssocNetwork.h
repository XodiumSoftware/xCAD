// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbAssocAction.h"

class BRX_EXPORT AcDbAssocNetwork : public AcDbAssocAction
{
public:
    ACRX_DECLARE_MEMBERS(AcDbAssocNetwork)
    AcDbAssocNetwork();
    ~AcDbAssocNetwork() noexcept = default;

    static AcDbObjectId getInstanceFromDatabase(AcDbDatabase*, bool, const AcString & = ACRX_T(""));
    static AcDbObjectId getInstanceFromObject(const AcDbObjectId&, bool, bool = true, const AcString & = ACRX_T(""));

    const AcDbObjectIdArray& getActions() const;
    const AcDbObjectIdArray& getActionsToEvaluate() const;

    Acad::ErrorStatus addAction(const AcDbObjectId&, bool);
    Acad::ErrorStatus removeAction(const AcDbObjectId&, bool);
    Acad::ErrorStatus addActions(const AcDbObjectIdArray&, bool);
    Acad::ErrorStatus removeAllActions(bool);
    Acad::ErrorStatus ownedActionStatusChanged(AcDbAssocAction*, AcDbAssocStatus);

    static Acad::ErrorStatus removeInstanceFromObject(const AcDbObjectId&, bool, const AcString& = ACRX_T(""));
    static Acad::ErrorStatus removeInstanceFromDatabase(AcDbDatabase*, bool, const AcString& = ACRX_T(""));
};

class AcDbAssocNetworkIterator
{
public:
    explicit AcDbAssocNetworkIterator(const AcDbAssocNetwork*);
    AcDbObjectId current() const;

    bool moveNext() { return m_pAssocNetwork != NULL ? ++m_nAssocIndex < m_pAssocNetwork->getActions().length() : false; }
    void reset() { m_nAssocIndex = -1; }

private:
    const AcDbAssocNetwork* const m_pAssocNetwork;
    int m_nAssocIndex;
};
