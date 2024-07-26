// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BIM API : IFC export reactor sample

#include "BrxSpecific/bim/IfcExportReactor.h"

#if (__BRXTARGET >= 23)

void cmdMyBimIfcExport1();
void cmdMyBimIfcExport2();

// reactor handler/instance handling both IFC2x3 + IFC4 exports
// (but separate instances can be used)
class IfcExportReactorInstance : public BimIfcExportReactorInstance
{
public:
    IfcExportReactorInstance() {};
    virtual ~IfcExportReactorInstance() {};

    // reactor callbacks
    virtual void adjustProjectData(Context& context, BimApi::BimIfcProjectData& data) override;

    virtual void onBeginIfcModelSetup(Context& context) override;

    virtual Ice::IfcApi::Entity onEntity(Context& context, AcDbEntity* pEntity) override;

    virtual void onEntityConstructed(Ice::IfcApi::Entity& contructedEntity, AcDbEntity* pSourceBCEntity) override;

    virtual void onEndIfcModelSetup(Context& context) override;

    void assignCustomProperties(Context& context, const Ice::IfcApi::Entity& ent);
    Ice::IfcApi::Entity createPropertySet(Context& context, const ACHAR* name, const Ice::IfcApi::VectorValue& set);
    Ice::IfcApi::Entity createSimpleTextProperty(Context& context, ACHAR* propName, ACHAR* propVal, const char* propTag, Ice::EIfcSchemaId scm);
    Ice::IfcApi::Entity createMeasureValueProperty(Context& context, ACHAR* propName, double value, const char* propTag, Ice::EIfcSchemaId scm);
    Ice::IfcApi::Entity createRelDefinesByProperties(Context& context, const Ice::IfcApi::Entity& propSet);

public:
    AcDbObjectId m_idMainBuilding;

    mutable bool m_3dSolidEntFound = true;
    mutable bool m_adjustProjectDataCalled = false;
    mutable bool m_onBeginCalled = false;
    mutable bool m_onEntityCalled = false;
    mutable bool m_onEntityConstructedCalled = false;
    mutable bool m_onEndCalled = false;
    mutable bool m_circleEntFound = false;
    mutable int  m_numGeomToolsOk = 0;
};

// general IFC Export reactor
class IfcExportReactor : public BimIfcExportReactor
{
    IfcExportReactorInstance  m_reactorInstance;

private:
    IfcExportReactor();

public:
    IfcExportReactor(const ACHAR* name, const ACHAR* guid,
                     const AcDbObjectId& idMainBuilding = AcDbObjectId::kNull);

    virtual ~IfcExportReactor();

    // clients should pick a unique GUID and hard-code it in / their application.
    // BricsCAD will internally use this GUID to identify the reactor & application
    // accross sessions, releases and different third party applications
    // notation : enclosed hexadecimal (e.g. "{3F2504E0-4F89-41D3-9A0C-0305E82C3301}")
    virtual const ACHAR* GUID() const;

    // the display name will be used in the user interface for users to identify/enable/
    // disable/prioritize your application
    virtual const ACHAR* displayName() const;

    // callback to provide a reactor handler for all schemas
    virtual BimIfcExportReactorInstance* getIfcReactorInstance(Ice::EIfcSchemaId schema) override
    {
        m_getInstanceCalled = true;
        m_reactorInstance.m_idMainBuilding = m_idMainBuilding;
        return &m_reactorInstance;
    };


public:
    AcString     m_guid;
    AcString     m_displayName;
    AcDbObjectId m_idMainBuilding;

    mutable bool m_guidCalled = false;
    mutable bool m_displaynameCalled = false;
    mutable bool m_getInstanceCalled = false;

    static const ACHAR* m_refGUID;
};

#endif // (__BRXTARGET >= 23)
