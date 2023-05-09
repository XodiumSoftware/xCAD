// Copyright (C) Menhirs NV. All rights reserved.
// BIM API : IFC export reactor sample

#include "StdAfx.h"
#include "BrxSpecific/bim/BuildingElements.h"

#include "BimIfcExport.h"
#include "BimClassification.h" // utility functions

#include "BrxSpecific/bim/BimDefs.h"

#include "BrxSpecific/bim/ifc/IfcConstants.h"

// sample reactor to participate in IFC export
// uses some dummy AcDb3dSolid object as BIM objects

const ACHAR* IfcExportReactor::m_refGUID = _T("{ABE15A35-A89F-4C28-9E12-BEF2713D1450}");

//------------------ main reactor instance callbacks -----------------------------
IfcExportReactor::IfcExportReactor(const ACHAR* name, const ACHAR* guid,
                                   const AcDbObjectId& idMainBuilding /*=AcDbObjectId::kNull*/)
    : m_displayName(name), m_guid(guid), m_idMainBuilding(idMainBuilding)
{
}

IfcExportReactor::~IfcExportReactor()
{
}

const ACHAR* IfcExportReactor::GUID() const
{
    m_guidCalled = true;
    return m_guid.kwszPtr();
}

// the display name will be used in the user interface for users to identify/enable/
// disable/prioritize your application
const ACHAR* IfcExportReactor::displayName() const
{
    m_displaynameCalled = true;
    return m_displayName.kwszPtr();
}

//----------------- reactor handler instance callbacks ---------------------------
void IfcExportReactorInstance::adjustProjectData(Context& context, BimApi::BimIfcProjectData& data)
{
    m_adjustProjectDataCalled = true;

    data.project.name             = _T("BRX BIM IFC Export Sample");
    data.project.description      = _T("this is a BRX BIM sample case");
    data.project.phase            = _T("testing");
    data.project.northAngle       = 0.0;
    
    data.author.givenName         = _T("noname");
    data.author.familyName        = _T("none");
    data.author.organization      = _T("privat");
    
    data.application.fullName     = _T("BRX BIM sample");
    data.application.identifier   = _T("12345-67890");
    data.application.version      = _T("1.2.3");
    data.application.developer    = _T("Bricsys BRX Team");
    
    data.site.name                = _T("OnTheMoon");
    data.site.description         = _T("crater on the moon");
    
    data.site.landTitleNumber     = _T("xyz");
    data.site.internalLocation    = _T("---xyz---");
    data.site.postalBox           = _T("12345");
    data.site.town                = _T("MoonCity");
    data.site.region              = _T("MoonLand");
    data.site.postalCode          = _T("Moon12345");
    data.site.country             = _T("AllMoon");
    data.site.adressLines         = _T("left-right");
    data.site.buildableArea       = 123.0;
    data.site.totalArea           = 234.0;
    data.site.buildingHeightLimit =  33.0;
}

void IfcExportReactorInstance::onBeginIfcModelSetup(Context& context)
{
    m_onBeginCalled = true;

    if (m_idMainBuilding.isNull())
        return;

    // main building provided : create BIM building + 2 floors
    AcDbDatabase* pDb = m_idMainBuilding.database();

    BrxBimBuilding mainBuilding;
    BimApi::ResultStatus bimRes = BrxBimBuilding::createBuilding(mainBuilding, pDb, _T("Main Building"));
    if (bimRes != BimApi::eOk)
        return;

    BrxBimStory floor_1, floor_2;
    bimRes = mainBuilding.createStory(floor_1, _T("Floor 1"));
    bimRes = mainBuilding.createStory(floor_2, _T("Floor 2"));
    bimRes = floor_1.setElevation(1.0);
    bimRes = floor_2.setElevation(4.0);

    bimRes = mainBuilding.assignToEntity(m_idMainBuilding);
    if (bimRes != BimApi::eOk)
        return;

    // check for unclassified AcDb3dSolid entities : assign to floor 1/2, as unspecific "General Building Element"
    AcDbObjectIdArray ids;
    bimRes = BimClassification::getAllUnclassified(ids, pDb);

    bool useFirstFloor(true);
    for (int i = 0, num = ids.length(); i < num; ++i, useFirstFloor = !useFirstFloor)
    {
        if (ids.at(i) == m_idMainBuilding)
            continue;

        AcDbObject* pObject = NULL;
        if (acdbOpenObject(pObject, ids.at(i), AcDb::kForRead) != Acad::eOk)
            continue;

        bool is3dSolid = (AcDb3dSolid::cast(pObject) != NULL);
        bool is3dFace  = (AcDbFace::cast(pObject) != NULL);
        pObject->close();

        if (is3dSolid)
            bimRes = BimClassification::classifyAs(ids.at(i), BimApi::eBimWall); // all as Walls
        else
        if (is3dFace)
            bimRes = BimClassification::classifyAs(ids.at(i), BimApi::eBimFurnishingElement); // other stuff

        bimRes = useFirstFloor ? floor_1.assignToEntity(ids.at(i)) : floor_2.assignToEntity(ids.at(i));
    }
}

Ice::IfcApi::Entity IfcExportReactorInstance::onEntity(Context& context, AcDbEntity* pEntity)
{
    m_onEntityCalled = true;

    if (AcDb3dSolid::cast(pEntity) != nullptr)
        m_3dSolidEntFound = true;

    Ice::IfcApi::Model* model = context.ifcModel();
    AcDbDatabase* db = context.database();
    if (!model || !db)
        return Ice::IfcApi::Entity::s_null;

    m_numGeomToolsOk = 0;

    AcGeMatrix2d coordSys2d; coordSys2d.setToTranslation(AcGeVector2d(2,3));
    AcGeMatrix3d coordSys3d; coordSys3d.setToTranslation(AcGeVector3d(2,3,4));

    Ice::IfcApi::Entity axis2d = context.getAxis2Placement2D(coordSys2d);
    Ice::IfcApi::Entity axis3d = context.getAxis2Placement3D(coordSys3d);
    Ice::IfcApi::Entity pt2d   = context.getCartesianPoint2D(AcGePoint2d(1,2));
    Ice::IfcApi::Entity pt3d   = context.getCartesianPoint3D(AcGePoint3d(1,2,3));
    Ice::IfcApi::Entity vec2d  = context.getDirection2D(AcGeVector2d::kYAxis);
    Ice::IfcApi::Entity vec3d  = context.getDirection3D(AcGeVector3d::kYAxis);

    if (!axis2d.isNull()) ++m_numGeomToolsOk;
    if (!axis3d.isNull()) ++m_numGeomToolsOk;
    if (!pt2d.isNull())   ++m_numGeomToolsOk;
    if (!pt3d.isNull())   ++m_numGeomToolsOk;
    if (!vec2d.isNull())  ++m_numGeomToolsOk;
    if (!vec3d.isNull())  ++m_numGeomToolsOk;
    
    if (m_idMainBuilding.isNull())
        return Ice::IfcApi::Entity::s_null;


    // 1) use another approach to declare IFC objects : for special "custom entities"
    //    (here : an "AcDb3dSolid" with color index 51 or 52)
    Adesk::UInt16 colorIdx = pEntity->colorIndex();
    if ((colorIdx != 51) && (colorIdx != 52))
        return Ice::IfcApi::Entity::s_null;

    if (AcDb3dSolid::cast(pEntity) == NULL)
        return Ice::IfcApi::Entity::s_null;

    Ice::IfcApi::Entity pFurnishing = Ice::IfcApi::Entity::create(*model, Ice::IfcApi::IfcFurnishingElement);
    if (pFurnishing.isNull())
        return Ice::IfcApi::Entity::s_null;

    // 2) set the base information (on the IfcRoot level)
    bool ok = true;
    if (colorIdx == 51)
        ok = context.setIfcRootData(pFurnishing, _T("Special Chair"),  _T("custom made"),   _T("{3F2504E0-4F89-41D3-9A0C-0305E82C3301}"));
    else
        ok = context.setIfcRootData(pFurnishing, _T("Standard Chair"), _T("mass produced"), _T("{3F2504E0-4F89-41D3-9A0C-0305E82C3302}"));

    // 3) set the location (on the IfcProduct level) relative to a building/story (WCS also possible)
    ok = context.setLocationRelToAssignedSpatialLocation(pFurnishing, pEntity);

    // 4) associated material compositions can be set as well
    BrxBimComposition composition;
    BimApi::ResultStatus bimRes = BrxBimComposition::assignedComposition(composition, pEntity->objectId());

    if (bimRes == BimApi::eOk)
        context.setMaterialToAssignedComposition(pFurnishing, pEntity);

    // 5) assign custom properties
    //if (colorIdx == 51)
    assignCustomProperties(context, pFurnishing);

    // 6) return a pointer to the newly created IfcObject; by returning a non-null pointer
    //    the IFC export proceeds to the following entity in model space
    return pFurnishing; 
}

void IfcExportReactorInstance::onEntityConstructed(Ice::IfcApi::Entity& contructedEntity, AcDbEntity* pSourceBCEntity)
{

    m_onEntityConstructedCalled = true;

    if (pSourceBCEntity)
    {
        const auto sourceEntId = pSourceBCEntity->id();
        const auto sourceEntDbId = pSourceBCEntity->objectId();

        AcDbHandle ac_db_handle;
        pSourceBCEntity->getAcDbHandle(ac_db_handle);

        ACHAR mBuffer[256];
        ac_db_handle.getIntoAsciiBuffer(mBuffer,256);
        AcString ac_str_buf(mBuffer);
        Ice::IfcApi::String str_buf(ac_str_buf.kwszPtr());
        Ice::IfcApi::Variant description(str_buf);

        auto res = contructedEntity.setAttribute("Description", description);
    }

}

void IfcExportReactorInstance::onEndIfcModelSetup(Context& context)
{
    m_onEndCalled = true;
}

void IfcExportReactorInstance::assignCustomProperties(Context& context, const Ice::IfcApi::Entity& ent)
{
    Ice::EIfcSchemaId scm = context.ifcModel()->schemaId();

    Ice::IfcApi::VectorValue props(Ice::IfcApi::Set_1_IfcProperty, scm);
    assert(!props.isNull());
    Ice::IfcApi::Entity prop1 = createSimpleTextProperty(context, L"Label property", L"Property 1", Ice::IfcApi::IfcLabel, scm);
    Ice::IfcApi::Entity prop2 = createSimpleTextProperty(context, L"Text property", L"Property 2", Ice::IfcApi::IfcText, scm);
    Ice::IfcApi::Result res = props.add(prop1);
    assert(res == Ice::IfcApi::Result::eOk);
    res = props.add(prop2);
    assert(res == Ice::IfcApi::Result::eOk);

    Ice::IfcApi::Entity propSet = createPropertySet(context, L"Custom property set", props);
    Ice::IfcApi::Entity relDefProp = createRelDefinesByProperties(context, propSet);
    Ice::IfcApi::VectorValue objects(scm == Ice::EIfcSchemaId::eIFC2X3 ? Ice::IfcApi::Set_1_IfcObject : Ice::IfcApi::Set_1_IfcObjectDefinition, scm);
    assert(!objects.isNull());
    res = objects.add(ent);
    assert(res == Ice::IfcApi::Result::eOk);
    res = relDefProp.setAttribute(Ice::IfcApi::RelatedObjects, std::move(objects));
    assert(res == Ice::IfcApi::Result::eOk);
}

Ice::IfcApi::Entity IfcExportReactorInstance::createPropertySet(Context& context, const ACHAR* name, const Ice::IfcApi::VectorValue& set)
{
    Ice::IfcApi::Entity propSet = Ice::IfcApi::Entity::create(*context.ifcModel(), Ice::IfcApi::IfcPropertySet);
    context.setIfcRootData(propSet, name, nullptr, nullptr);
    Ice::IfcApi::Result res = propSet.setAttribute(Ice::IfcApi::HasProperties, set);
    assert(res == Ice::IfcApi::Result::eOk);
    return propSet;
}

Ice::IfcApi::Entity IfcExportReactorInstance::createRelDefinesByProperties(Context& context, const Ice::IfcApi::Entity& propSet)
{
    auto relDefines = Ice::IfcApi::Entity::create(*context.ifcModel(), Ice::IfcApi::IfcRelDefinesByProperties);
    context.setIfcRootData(relDefines, nullptr, nullptr, nullptr);
    Ice::IfcApi::Result res;
    switch (context.ifcModel()->schemaId())
    {
    case Ice::EIfcSchemaId::eIFC2X3 :
        res = relDefines.setAttribute(Ice::IfcApi::RelatingPropertyDefinition, propSet);
        assert(res == Ice::IfcApi::Result::eOk);
        break;
    case Ice::EIfcSchemaId::eIFC4 :
        Ice::IfcApi::SelectValue sv(Ice::IfcApi::IfcPropertySetDefinitionSelect, Ice::EIfcSchemaId::eIFC4);
        assert(!sv.isNull());
        res = sv.setValue(Ice::IfcApi::IfcPropertySetDefinition, propSet);
        assert(res == Ice::IfcApi::Result::eOk);
        res = relDefines.setAttribute(Ice::IfcApi::RelatingPropertyDefinition, std::move(sv));
        assert(res == Ice::IfcApi::Result::eOk);
        break;
    }
    return relDefines;
}

Ice::IfcApi::Entity IfcExportReactorInstance::createSimpleTextProperty(Context& context, ACHAR* propName, ACHAR* propVal, const char* propTag, Ice::EIfcSchemaId scm)
{
    Ice::IfcApi::SelectValue propValue(Ice::IfcApi::IfcValue, scm);
    Ice::IfcApi::SelectValue simpleValue(Ice::IfcApi::IfcSimpleValue, scm);
    Ice::IfcApi::Result res = simpleValue.setValue(propTag, Ice::IfcApi::String(propVal));
    assert(res == Ice::IfcApi::Result::eOk);
    res = propValue.setValue(Ice::IfcApi::IfcSimpleValue, std::move(simpleValue));
    assert(res == Ice::IfcApi::Result::eOk);

    Ice::IfcApi::Entity propSingleValue = Ice::IfcApi::Entity::create(*context.ifcModel(), Ice::IfcApi::IfcPropertySingleValue);
    res = propSingleValue.setAttribute(Ice::IfcApi::Name, Ice::IfcApi::String(propName));
    assert(res == Ice::IfcApi::Result::eOk);
    res = propSingleValue.setAttribute(Ice::IfcApi::NominalValue, std::move(propValue));
    assert(res == Ice::IfcApi::Result::eOk);
    return propSingleValue;
}

// IFC Export example 1 : demonstrates the reactor handling
void cmdMyBimIfcExport1()
{
    if (!isLicenseAvailable(BricsCAD::eBimLicense)) // requires BIM license/RunAsLevel
        return;

    struct resbuf sym;
    int rt = acedGetVar(_T("TEMPPREFIX"), &sym);

    AcString ifcFile = sym.resval.rstring;
    ifcFile += _T("MySampleIfcFile-1.ifc");
    _tremove(ifcFile);

    bool fileOk = (_taccess(ifcFile.kwszPtr(), 0) != 0);

    AcDbObjectId idBox = createBoxSolid(10.0, 6.0, 6.0, AcGeVector3d::kIdentity);

    IfcExportReactor ifcReactor(_T("MyIfcExportReactor"), IfcExportReactor::m_refGUID);

    bool ok = ifcReactor.attachReactor();

    const AcApDocument* pDoc = curDoc();
    BimApi::ResultStatus res = BimApi::exportIfcFile(pDoc, ifcFile.kwszPtr());

    ifcReactor.detachReactor();

    fileOk = (_taccess(ifcFile.kwszPtr(), 0) == 0);

    ok = (res == BimApi::eOk);
    ok = (fileOk == true);
    ok = (ifcReactor.m_guidCalled == true);
    ok = (ifcReactor.m_displaynameCalled == false); // only used with GUI context
}

// IFC Export example 2 : dynamically assign entities to IFC objects
// for this test, create a few AcDb3dSolids, set to color index 51 and 52
void cmdMyBimIfcExport2()
{
    if (!isLicenseAvailable(BricsCAD::eBimLicense)) // requires BIM license/RunAsLevel
        return;

    struct resbuf sym;
    int rt = acedGetVar(_T("TEMPPREFIX"), &sym);

    AcString ifcFile = sym.resval.rstring;
    ifcFile += _T("MySampleIfcFile-2.ifc");
    _tremove(ifcFile);

    bool fileOk = (_taccess(ifcFile.kwszPtr(), 0) != 0);

    // create the "building" as entity
    AcDbObjectId idBuilding = createBoxSolid(50.0, 15.0, 8.0, AcGeVector3d::kIdentity);

    // if "MainBuilding" is provided, the reactor will create the BIM building and 2 floors
    // at 'onBeginIfcModelSetup()' event
    IfcExportReactor ifcReactor(_T("MyIfcExportReactor"), IfcExportReactor::m_refGUID);

    bool ok = ifcReactor.attachReactor();

    const AcApDocument* pDoc = curDoc();
    BimApi::BrxIfcExportOptions op;
    op.setIfcVersion(Ice::EIfcSchemaId::eIFC4);
    BimApi::ResultStatus res = BimApi::exportIfcFile(pDoc, ifcFile.kwszPtr(), &op);

    ifcReactor.detachReactor();

    fileOk = (_taccess(ifcFile.kwszPtr(), 0) == 0);
    fileOk;    
}
