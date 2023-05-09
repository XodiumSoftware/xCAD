// Copyright (C) Menhirs NV. All rights reserved.
// BIM API : object classification sample

#include "StdAfx.h"
#include "BrxSpecific/bim/BuildingElements.h"

#include "BimClassification.h"


Acad::ErrorStatus postToDatabase(AcDbObjectId& idObj, AcDbDatabase* pDb,
                                 AcDbEntity* pEnt, bool doClose /*=true*/)
{
    assert(pEnt != NULL);

    //----- Get a pointer to the current drawing
    if (pDb == nullptr)
        pDb = acdbCurDwg();

    Acad::ErrorStatus es = Acad::eOk;
    AcDbBlockTable* pBlockTable = nullptr;
    es = pDb->getBlockTable(pBlockTable, AcDb::kForRead);
    if (es != Acad::eOk)
        return es;

    AcDbBlockTableRecord* pSpaceRecord = nullptr;
    es = pBlockTable->getAt(ACDB_MODEL_SPACE, pSpaceRecord, AcDb::kForWrite);
    pBlockTable->close();
    if (es != Acad::eOk)
        return es;

    es = pSpaceRecord->appendAcDbEntity(idObj, pEnt);
    pSpaceRecord->close();

    if ((es == Acad::eOk) && doClose)
        pEnt->close();

    return es;
}

AcDbObjectId createBoxSolid(double length, double depth, double height, const AcGeVector3d& translation,
                            Adesk::UInt16 aciColorIndex /* = 256*/)
{
    AcDb3dSolid* pSolid = new AcDb3dSolid();
    Acad::ErrorStatus es = pSolid->createBox(length, depth, height);
    if (es != Acad::eOk)
        return AcDbObjectId::kNull;

    if (aciColorIndex < 256)
        pSolid->setColorIndex(aciColorIndex);

    AcGeMatrix3d mtx;
    if (!translation.isEqualTo(AcGeVector3d::kIdentity))
    {
        mtx.setToTranslation(translation);
        pSolid->transformBy(mtx);
    }

    AcDbObjectId id;
    if (postToDatabase(id, nullptr, pSolid) == Acad::eOk)
        return id;

    delete pSolid;
    return AcDbObjectId::kNull;
}


// this sample code demonstrates BIM classification, and usage of BIM objects
// uses some dummy AcDb3dSolid object as BIM objects
void cmdMyBimClassify()
{
    if (!isLicenseAvailable(BricsCAD::eBimLicense)) // requires BIM license/RunAsLevel
        return;

    AcDbDatabase* pDb = acdbCurDwg();

    BimApi::ResultStatus bimRes = BimApi::eOk;

    // get or create our Building: "North Tower"
    BrxBimBuilding ourBuilding;
    bimRes = BrxBimBuilding::getBuilding(ourBuilding, pDb, _T("Tower North"));
    if (bimRes != BimApi::eOk)
        bimRes = BrxBimBuilding::createBuilding(ourBuilding, pDb, _T("Tower North"));

    // sets the description of this Building object, returns 'eOK' if succeeds, or an error status
    bimRes = ourBuilding.setDescription(_T("the north side tower building"));
    AcString name = ourBuilding.name();
    LPCTSTR szString = name.kwszPtr();
    AcString desc = ourBuilding.description();
    szString = desc.kwszPtr();

    // get or create Story : "Floor 1"
    BrxBimStory floor_1;
    bimRes = BrxBimStory::getStory(floor_1, pDb, _T("Tower North"), _T("Floor 1"));
    if (bimRes != BimApi::eOk)
        bimRes = BrxBimStory::createStory(floor_1, pDb, _T("Tower North"), _T("Floor 1"));

    name = floor_1.name();
    szString = name.kwszPtr();
    bimRes = floor_1.setDescription(_T("first floor"));
    desc = floor_1.description();
    szString = desc.kwszPtr();

    bimRes = floor_1.setElevation(1.0); // drawing units
    double elev = floor_1.elevation();

    // get or create Story : "Floor 2"
    BrxBimStory floor_2;
    bimRes = ourBuilding.getStory(floor_2, _T("Floor 2"));
    if (bimRes != BimApi::eOk)
        bimRes = ourBuilding.createStory(floor_2, _T("Floor 2"));

    name = floor_1.name();
    szString = name.kwszPtr();
    bimRes = floor_2.setDescription(_T("second floor"));
    desc = floor_2.description();
    szString = desc.kwszPtr();

    bimRes = floor_2.setElevation(6.0); // drawing units
    elev = floor_2.elevation();

    // create third floor
    BrxBimStory floor_3;
    bimRes = floor_3.createStory(_T("Floor X"), ourBuilding);

    name = floor_3.name();
    szString = name.kwszPtr();
    bimRes = floor_3.setName(_T("Floor 3"));
    AcString floorName = floor_3.name();
    szString = floorName.kwszPtr();

    bimRes = floor_3.setElevation(11.0); // drawing units
    elev = floor_3.elevation();

    // assign floors & building to "hull entities"
    AcDbObjectId idBuilding;
    AcDbObjectIdArray idsForBuilding;
    bimRes = ourBuilding.assignedObjects(idsForBuilding, pDb);
    if (idsForBuilding.isEmpty())
    {
        idBuilding = createBoxSolid(100, 35, 20, AcGeVector3d(0,0,10.0), 1);
        bimRes = ourBuilding.assignToEntity(idBuilding);
    }

    BrxBimBuilding building;
    bimRes = BrxBimBuilding::assignedBuilding(building, idBuilding);
    bool valid = !building.isNull();
    bool isSame = (building == ourBuilding);

    AcDbObjectIdArray idsForFloor_1, idsForFloor_2, idsForFloor_3;
    bimRes = floor_1.assignedObjects(idsForFloor_1, pDb);
    bimRes = floor_2.assignedObjects(idsForFloor_2, pDb);
    bimRes = floor_3.assignedObjects(idsForFloor_3, pDb);

    AcDbObjectId idFloor_1, idFloor_2, idFloor_3;
    if (idsForFloor_1.isEmpty())
    {
        idFloor_1 = createBoxSolid(98, 33, 4, AcGeVector3d(0,0,3.0), 4);
        bimRes = floor_1.assignToEntity(idFloor_1);
    }
    if (idsForFloor_2.isEmpty())
    {
        idFloor_2 = createBoxSolid(98, 33, 4, AcGeVector3d(0,0,8.0), 4);
        bimRes = floor_2.assignToEntity(idFloor_2);
    }
    if (idsForFloor_3.isEmpty())
    {
        idFloor_3 = createBoxSolid(98, 33, 4, AcGeVector3d(0,0,13.0), 4);
        bimRes = floor_3.assignToEntity(idFloor_3);
    }

    building.setNull();
    bimRes = floor_1.getBuilding(building);
    isSame = (building == ourBuilding);

    building.setNull();
    bimRes = floor_2.getBuilding(building);
    isSame = (building == ourBuilding);

    building.setNull();
    bimRes = floor_3.getBuilding(building);
    isSame = (building == ourBuilding);

    // put some objects to the floors

    // floor 1
    AcDbObjectId id = createBoxSolid(2, 1, 0.5, AcGeVector3d(0,0,3.0)); // sofa 1
    bimRes = BimClassification::classifyAs(id, BimApi::eBimFurnishingElement);
    bimRes = BimClassification::setName(id, _T("sofa 1"));
    bimRes = BimClassification::setDescription(id, _T("leather, brown"));
    bimRes = floor_1.assignToEntity(id);

    id = createBoxSolid(10, 0.5, 1, AcGeVector3d(0,0,3.0)); // railing 1
    bimRes = BimClassification::classifyAs(id, BimApi::eBimRailing);
    bimRes = BimClassification::setName(id, _T("railing 1"));
    bimRes = BimClassification::setDescription(id, _T("to 2nd floor"));
    bimRes = floor_1.assignToEntity(id);

    id = createBoxSolid(10, 2.5, 0.5, AcGeVector3d(0,0,3.0)); // stair 1
    bimRes = BimClassification::classifyAs(id, BimApi::eBimStair);
    bimRes = BimClassification::setName(id, _T("stair 1"));
    bimRes = BimClassification::setDescription(id, _T("to 2nd floor"));
    bimRes = floor_1.assignToEntity(id);

    // floor 2
    id = createBoxSolid(2, 1, 0.5, AcGeVector3d(0,0,8.0)); // sofa 2
    bimRes = BimClassification::classifyAs(id, BimApi::eBimFurnishingElement);
    bimRes = BimClassification::setName(id, _T("sofa 2"));
    bimRes = BimClassification::setDescription(id, _T("cotton, white"));
    bimRes = floor_2.assignToEntity(id);

    id = createBoxSolid(10, 0.5, 1, AcGeVector3d(0,0,8.0)); // railing 2
    bimRes = BimClassification::classifyAs(id, BimApi::eBimRailing);
    bimRes = BimClassification::setName(id, _T("railing 2"));
    bimRes = BimClassification::setDescription(id, _T("to 3rd floor"));
    bimRes = floor_2.assignToEntity(id);

    id = createBoxSolid(10, 2.5, 0.5, AcGeVector3d(0,0,8.0)); // stair 2
    bimRes = BimClassification::classifyAs(id, BimApi::eBimStair);
    bimRes = BimClassification::setName(id, _T("stair 2"));
    bimRes = BimClassification::setDescription(id, _T("to 3rd floor"));
    bimRes = floor_2.assignToEntity(id);

    // floor 3
    id = createBoxSolid(2, 1, 0.5, AcGeVector3d(0,0,13.0)); // sofa 3
    bimRes = BimClassification::classifyAs(id, BimApi::eBimFurnishingElement);
    bimRes = BimClassification::setName(id, _T("sofa 3"));
    bimRes = BimClassification::setDescription(id, _T("leather, beige"));
    bimRes = floor_3.assignToEntity(id);

    id = createBoxSolid(10, 0.5, 1, AcGeVector3d(0,0,13.0)); // railing 3
    bimRes = BimClassification::classifyAs(id, BimApi::eBimRailing);
    bimRes = BimClassification::setName(id, _T("railing 3"));
    bimRes = BimClassification::setDescription(id, _T("to roof"));
    bimRes = floor_3.assignToEntity(id);


    // some checking
    AcDbObjectIdArray storyObjects;
    bimRes = floor_1.assignedObjects(storyObjects, pDb);
    int numObjects = storyObjects.length();  // 3

    storyObjects.removeAll();
    bimRes = floor_2.assignedObjects(storyObjects, pDb);
    numObjects = storyObjects.length();  // 3

    storyObjects.removeAll();
    bimRes = floor_2.assignedObjects(storyObjects, pDb);
    numObjects = storyObjects.length();  // 2

    // some more checking
    BimApi::BimBuildings buildings;
    bimRes = BrxBimBuilding::allBuildings(buildings, pDb);
    int numBuildings = buildings.length();

    BimApi::BimStories stories;
    bimRes = BrxBimStory::allStories(stories, pDb);
    int numStories = stories.length();

    AcDbObjectIdArray ids;
    bimRes = ourBuilding.assignedObjects(ids, pDb);
    int numEnts = ids.length();

}
