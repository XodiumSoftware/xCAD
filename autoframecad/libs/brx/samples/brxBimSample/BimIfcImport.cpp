// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// BIM API : IFC import reactor sample

#include "StdAfx.h"
#include "BrxSpecific/bim/BuildingElements.h"

#if (__BRXTARGET >= 20)

#include "BimIfcImport.h"
#include "BimClassification.h" // utility functions

#include "BrxSpecific/bim/BimDefs.h"

#include "BrxSpecific/bim/ifc/IfcConstants.h"

// sample reactor to participate in IFC import

const ACHAR* IfcImportReactor::m_refGUID = _T("{ABE15A35-A99F-4C28-9E12-BEF2713D1450}");

//------------------ main reactor instance callbacks -----------------------------

IfcImportReactor::IfcImportReactor(const ACHAR* name, const ACHAR* guid)
    : m_displayName(name), m_guid(guid)
{
}

IfcImportReactor::~IfcImportReactor()
{
}

const ACHAR* IfcImportReactor::GUID() const
{
    m_guidCalled = true;
    return m_guid.kwszPtr();
}

// the display name will be used in the user interface for users to identify/enable/
// disable/prioritize your application
const ACHAR* IfcImportReactor::displayName() const
{
    m_displaynameCalled = true;
    return m_displayName.kwszPtr();
}

//----------------- reactor handler instance callbacks ---------------------------

void IfcImportReactorInstance::onStart(Context& context, const Ice::IfcApi::Entity& project, const BimIfcImportInfo& info)
{
    // Get info about file name and time stamp from header of the IFC file
    // and import options
    const auto fileName = info.fileName();
    const auto timeStamp = info.timeStamp();
    const auto importBimData = info.importBimData();
    m_onStartCalled = true;
}

bool IfcImportReactorInstance::onIfcProduct(Context& context, const Ice::IfcApi::Entity& product, bool isParent, const Ice::IfcApi::Entity& parentProduct)
{
    m_onProductCalled = true;

    // here you can modify import process. For example insted windows create boxes
    if (product.isKindOf(Ice::IfcApi::IfcWindow))
    {
        
        auto objTransform = context.getLocalPlacement(product);
        AcGeVector3d translationComponent;
        objTransform.translation(translationComponent);

        // box solid created and automatically inserted to current database
        createBoxSolid(100, 100, 100, translationComponent);
        return true;
    }


    return false;
}

#if __BRXTARGET >= 21
void IfcImportReactorInstance::beforeCompletion(Context& context, bool success)
#else
void IfcImportReactorInstance::beforeCompletion()
#endif
{
    m_completionCalled = true;
}

#if __BRXTARGET >= 21
void IfcImportReactorInstance::onIfcProductImported(const Ice::IfcApi::Entity& sourceEntity, bool isParent, const Ice::IfcApi::Entity& sourceParentEntity, AcDbEntityPtrArray& createdAcEntites, const AcGeMatrix3d* constructedAcEntityTransformation) {
    
    m_onIfcProductImportedCalled = true;

    if (!createdAcEntites.isEmpty())
    {
        AcCmColor clr;
        clr.setRGB(0, 255, 0);

        for (auto& entity : createdAcEntites)
        {
            auto isBlockRef = entity->isA()->isDerivedFrom(AcDbBlockReference::desc());
            auto is3dSolid  = entity->isA()->isDerivedFrom(AcDb3dSolid::desc());

            if (is3dSolid)
            {
                entity->setColor(clr);
            }
            else
            {
                AcDbObject* pAcBlockRef = NULL;
                Acad::ErrorStatus retval = acdbOpenAcDbObject(pAcBlockRef, AcDbBlockReference::cast(entity)->blockTableRecord());

                if (pAcBlockRef)
                {
                    AcDbBlockTableRecord* pAcBlockRefPtr = AcDbBlockTableRecord::cast(pAcBlockRef);

                    AcDbBlockTableRecordIterator* it;
                    auto errIt = pAcBlockRefPtr->newIterator(it);

                    for (it->start(); !it->done(); it->step())
                    {
                        AcDbEntity* iEnt;
                        auto pObj = it->getEntity(iEnt,AcDb::kForWrite);
                        if (iEnt)
                            iEnt->setColor(clr);
                    }
                }
            }
        }
    }

    Ice::IfcApi::Variant attribVal;
    const auto entName = sourceEntity.getAttribute("Name", attribVal);
}
#endif

//----------------- sample command ---------------------------

// IFC Import example 1 : demonstrates the reactor handling
void cmdMyBimIfcImport()
{
    if (!isLicenseAvailable(BricsCAD::eBimLicense)) // requires BIM license/RunAsLevel
        return;

    struct resbuf* result = acutNewRb(RTSTR);

    int rt = acedGetFileD(_T("Select IFC file"), _T(""), _T("ifc"), 0, result);
    if ((rt != RTNORM) || !result)
    {
        acutRelRb(result), result = NULL;
        return;
    }
    AcString ifcFile = result->resval.rstring;
    acutRelRb(result), result = NULL;

    IfcImportReactor ifcReactor(_T("MyIfcImportReactor"), IfcImportReactor::m_refGUID);

    bool ok = ifcReactor.attachReactor();

    const AcApDocument* pDoc = curDoc();

    // assign import options here 
    BimApi::BrxIfcImportOptions opts;
    //opts.setImportIfcProjectStructureAsXrefs(true);
    //opts.setImportBrepGeometryAsMeshes(true);
    BimApi::ResultStatus res = BimApi::importIfcFile(pDoc->database(), ifcFile.kwszPtr(), &opts);

    ifcReactor.detachReactor();

    ok = (res == BimApi::eOk);
    ok = (ifcReactor.m_guidCalled == true);
    ok = (ifcReactor.m_displaynameCalled == false); // only used with GUI context
}


#endif // (__BRXTARGET >= 20)
