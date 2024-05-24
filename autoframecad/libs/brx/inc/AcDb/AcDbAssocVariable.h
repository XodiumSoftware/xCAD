// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbAssocAction.h"

AcString& dummyString();

class BRX_EXPORT AcDbAssocVariable : public AcDbAssocAction
{

public:
    ACRX_DECLARE_MEMBERS(AcDbAssocVariable)
    AcDbAssocVariable();
    ~AcDbAssocVariable() noexcept = default;

    const AcDbEvalVariant& value() const;
    const AcString& name() const;
    const AcString& expression() const;
    const AcString& expression(bool) const;
    const AcString& description() const;
    AcString mergeableVariableName() const;

    AcDbObjectId findObjectByName(const AcString&, const AcRxClass*) const;

    bool isAnonymous() const;
    bool isMergeable() const;
    bool mustMerge() const;

    Acad::ErrorStatus setName(const AcString&, bool);
    Acad::ErrorStatus validateNameAndExpression(const AcString&, const AcString&, AcString&) const;
    Acad::ErrorStatus setExpression(const AcString&, const AcString&, bool, bool, AcString& = dummyString(), bool = false);
    Acad::ErrorStatus setEvaluatorId(const AcString&);
    Acad::ErrorStatus setValue(const AcDbEvalVariant&);
    Acad::ErrorStatus setDescription(const AcString&);
    Acad::ErrorStatus evaluateExpression(AcDbEvalVariant&, AcString& = dummyString()) const;
    Acad::ErrorStatus evaluateExpression(AcDbObjectIdArray&, AcArray<AcDbEvalVariant>&, AcDbEvalVariant&, AcString & = dummyString()) const;
    static Acad::ErrorStatus evaluateExpression(const AcString&, const AcString&, const AcDbObjectId&, AcDbEvalVariant&, AcString&, AcString & = dummyString());

    void setIsMergeable(bool, bool = false, const AcString& = AcString());
    static void addGlobalCallback(class AcDbAssocVariableCallback*);
    static void removeGlobalCallback(class AcDbAssocVariableCallback*);
    
    static class AcDbAssocVariableCallback* globalCallback();
    
private:
    mutable AcString m_string;
};

class AcDbAssocVariableCallback
{
public:
    AcDbAssocVariableCallback();
    virtual ~AcDbAssocVariableCallback();

    virtual bool canBeErased(const AcDbAssocVariable*) = 0;
    virtual Acad::ErrorStatus validateNameAndExpression(const AcDbAssocVariable*, const AcString&, const AcString&, AcString&) = 0;
};
