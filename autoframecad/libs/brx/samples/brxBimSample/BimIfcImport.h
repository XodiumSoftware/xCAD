// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BIM API : IFC import reactor sample

#include "BrxSpecific/bim/IfcImportReactor.h"

#if (__BRXTARGET >= 23)

void cmdMyBimIfcImport();

// reactor handler/instance handling both IFC2x3 + IFC4 exports
// (but separate instances can be used)
class IfcImportReactorInstance : public BimIfcImportReactorInstance
{
public:
    IfcImportReactorInstance() {};
    virtual ~IfcImportReactorInstance() {};

    virtual void onStart(Context& context, const Ice::IfcApi::Entity& project, const BimIfcImportInfo& info) override;

    virtual bool onIfcProduct(Context& context, const Ice::IfcApi::Entity& product, bool isParent,
                              const Ice::IfcApi::Entity& parentProduct) override;

    virtual void beforeCompletion(Context& context, bool success) override;
    virtual void IfcImportReactorInstance::onIfcProductImported(const Ice::IfcApi::Entity& sourceEntity, bool isParent, const Ice::IfcApi::Entity& sourceParentEntity, AcDbEntityPtrArray& createdAcEntites, const AcGeMatrix3d* constructedAcEntityTransformation) override;

public:
    mutable bool m_onStartCalled    = false;
    mutable bool m_onProductCalled  = false;
    mutable bool m_completionCalled = false;
    mutable bool m_onIfcProductImportedCalled = false;
};

// general IFC Import reactor
class IfcImportReactor : public BimIfcImportReactor
{
    IfcImportReactorInstance  m_reactorInstance;

private:
    IfcImportReactor();

public:
    IfcImportReactor(const ACHAR* name, const ACHAR* guid);

    virtual ~IfcImportReactor();

    // clients should pick a unique GUID and hard-code it in / their application.
    // BricsCAD will internally use this GUID to identify the reactor & application
    // accross sessions, releases and different third party applications
    // notation : enclosed hexadecimal (e.g. "{3F2504E0-4F89-41D3-9A0C-0305E82C3301}")
    virtual const ACHAR* GUID() const override;

    // the display name will be used in the user interface for users to identify/enable/
    // disable/prioritize your application
    virtual const ACHAR* displayName() const override;

    // callback to provide a reactor handler of IFC2x3
    // (can be a unified instance, as long as no low-level, IFC version dependent implementations are used)
    virtual BimIfcImportReactorInstance* getIfcReactorInstance(Ice::EIfcSchemaId schema) override
    {
        // return single reactor for each schema
        return &m_reactorInstance;
    };

public:
    AcString m_guid;
    AcString m_displayName;

    mutable bool m_guidCalled        = false;
    mutable bool m_displaynameCalled = false;
    mutable bool m_getInstanceCalled = false;

    static const ACHAR* m_refGUID;
};

#endif // (__BRXTARGET >= 23)
