// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"

#include "civil_gis_sample.h"
#include "civil_utils.h"

#include "BrxSpecific/civil/BrxCvDbGis.h"


AcDbObjectId createLine(const AcGePoint3d& p1, const AcGePoint3d& p2, AcDbDatabase* pDb,
    const bool draw)
{
    AcDbLine* pLine = new AcDbLine(p1, p2);
    AcDbObjectId id;
    addEntityToModelSpace(pLine, id, true);
    if (draw) {
        pLine->draw(); // to ensure the entity is immediately redrawn after close !
    }
    pLine->close(), pLine = NULL;
    return id;
}

void cmdCivilGisWorkflow()
{
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    if (!pDb)
        return;


    // Create gis layer definition and set gis layer name and attributes
    // Also add some features to one of the GIS layers and set some attribute data to one of the features
    {
        AcDbObjectId idGisPropMan;
        BrxCvDbGisPropertyManager::getManager(idGisPropMan, pDb, true);
        AcDbObjectPointer<BrxCvDbGisPropertyManager> gisPropMan(idGisPropMan, AcDb::OpenMode::kForWrite);
        if (!gisPropMan)
            return;

        BrxCvGisFeatureAttributeDefinition attr1(_T("Double value"), EGisAttrType::eDouble);
        BrxCvGisFeatureAttributeDefinition attr2(_T("Text"), EGisAttrType::eString);
        BrxCvGisFeatureAttributeDefinition attr3(_T("Text to be removed"), EGisAttrType::eString);
        BrxCvGisFeatureAttributeDefinition attr4(_T("Integer value"), EGisAttrType::eInt32);
        BrxCvGisFeatureAttributeDefinition attr5(_T("Long integer value"), EGisAttrType::eInt64);

        BrxCvGisLayerDefinition gisFeatureTable1;
        gisFeatureTable1.addAttributeDefinition(attr1);
        gisFeatureTable1.addAttributeDefinition(attr2);
        gisFeatureTable1.addAttributeDefinition(attr3);
        gisFeatureTable1.addAttributeDefinition(attr4);
        gisFeatureTable1.addAttributeDefinition(attr5);

        // add the created GIS layer to the database
        // specify the geometry type of the layer and a description of layer source
        // layerSource is only used for UI, to inform user, where did the layer come from (API, current drawing, filepath to the source file ...)
        gisPropMan->createLayer(_T("SampleLayer"), gisFeatureTable1, EGisGeomType::eWkbLineString, _T("from API 1"));
        gisPropMan->createLayer(_T("SampleLayer 2"), gisFeatureTable1, EGisGeomType::eWkbLineString, _T("from API 2"));
        gisPropMan->createLayer(_T("Layer to be removed"), gisFeatureTable1, EGisGeomType::eWkbLineString, _T("from API 3"));

        // Get all layers from database
        auto layers = gisPropMan->layers();

        // Get the first layer
        auto layer = gisPropMan->getLayer(layers.at(0));

        // add first feature to the GIS layer
        ///////////////////////////////////////////////////////////////////////////////////////////////////////

        //_AcDb.ObjectIdCollection idArray = new _AcDb.ObjectIdCollection();

        //// add a line to the drawing - we will create a GIS feature from it
        auto lineId = createLine(AcGePoint3d(0, 0, 0), AcGePoint3d(10, 10, 10), pDb, true);
        AcDbObjectIdArray ids;
        ids.append(lineId);

        //add feature to the GIS layer
        Adesk::UInt64 featureId;
        layer->addFeature(ids, featureId);
        ///////////////////////////////////////////////////////////////////////////////////////////////////////



        //add second feature to the gis layer
        //////////////////////////////////////////////////////////////////////////////////////////////////////
        lineId = createLine(AcGePoint3d(10, 10, 10), AcGePoint3d(20, 0, 0), pDb, true);
        ids.removeAll();
        ids.append(lineId);

        //add feature to the GIS layer
        Adesk::UInt64 featureId2;
        layer->addFeature(ids, featureId2);
        ///////////////////////////////////////////////////////////////////////////////////////////////////////



        //add third feature to the gis layer
        ///////////////////////////////////////////////////////////////////////////////////////////////////////
        lineId = createLine(AcGePoint3d(20, 0, 0), AcGePoint3d(30, 30, 30), pDb, true);
        ids.removeAll();
        ids.append(lineId);

        //add feature to the GIS layer
        Adesk::UInt64 featureId3;
        layer->addFeature(ids, featureId3);
        ///////////////////////////////////////////////////////////////////////////////////////////////////////

        // Get the fist feature from the first layer
        BrxCvDbGisFeaturePtr gisFeature = layer->getFeature(featureId);

        // Update feature with data in gisLD
        BrxCvGisFeatureAttributeData featureTable = gisFeature->featureData();
        BrxCvGisFeatureAttribute attr = featureTable.attributeAt(0);
        attr.setVal(58.46);
        featureTable.setAttributeAt(0, attr);
        
        attr = featureTable.attributeAt(1);
        attr.setVal(_T("My text"));
        featureTable.setAttributeAt(1, attr);
        
        attr = featureTable.attributeAt(2);
        attr.setVal(_T("My useless text"));
        featureTable.setAttributeAt(2, attr);
        
        attr = featureTable.attributeAt(3);
        attr.setVal(243);
        featureTable.setAttributeAt(3, attr);
        
        attr = featureTable.attributeAt(4);
        attr.setVal(223372036854775808);
        featureTable.setAttributeAt(4, attr);

        gisFeature->updateAttributeData(featureTable);
    }

    // Change a value in an attribute
    if (true)
    {
        AcDbObjectId idGisPropMan;
        BrxCvDbGisPropertyManager::getManager(idGisPropMan, pDb, true);
        AcDbObjectPointer<BrxCvDbGisPropertyManager> gisPropMan(idGisPropMan, AcDb::OpenMode::kForWrite);
        if (!gisPropMan)
            return;

        // Get all layers from database
        auto layers = gisPropMan->layers();

        // Get the first layer
        auto layer = gisPropMan->getLayer(layers.at(0));

        // Get the first featureId from layer
        Adesk::UInt64 featureId = layer->features().at(0);

        // Get the feature by id
        auto feature = layer->getFeature(featureId);

        // find attribute by name
        auto attrib = feature->attribute(_T("Double value"));

        // Change attribute data
        if (attrib.type() == EGisAttrType::eDouble)
        {
            attrib.setVal(46.58);
        }
        else
        {
            //wrong type - should not happen
        }

        // Update atrribute with new data
        feature->updateAttribute(attrib);
    }

    // Add new attribute
    if (true)
    {
        AcDbObjectId idGisPropMan;
        BrxCvDbGisPropertyManager::getManager(idGisPropMan, pDb, true);
        AcDbObjectPointer<BrxCvDbGisPropertyManager> gisPropMan(idGisPropMan, AcDb::OpenMode::kForWrite);
        if (!gisPropMan)
            return;

        // Get all layers from database
        auto layers = gisPropMan->layers();

        // Get the first layer
        auto layer = gisPropMan->getLayer(layers.at(0));

        // Get the first featureId from layer
        Adesk::UInt64 featureId = layer->features().at(0);

        // Get the feature by id
        auto feature = layer->getFeature(featureId);

        BrxCvGisFeatureAttributeDefinition attrDef(_T("New int attribute"), EGisAttrType::eInt32);

        // add new attribute definition to a layer
        // features are not yet updated with attribute values at this stage
        layer->addAttribute(attrDef);
        auto attrib = feature->attribute(_T("New int attribute"));
        attrib.setVal(77);

        // Update attribute values for a feature
        feature->updateAttribute(attrib);
    }

    // Remove an attribute
    if (true)
    {
        AcDbObjectId idGisPropMan;
        BrxCvDbGisPropertyManager::getManager(idGisPropMan, pDb, true);
        AcDbObjectPointer<BrxCvDbGisPropertyManager> gisPropMan(idGisPropMan, AcDb::OpenMode::kForWrite);
        if (!gisPropMan)
            return;

        // Get all layers from database
        auto layers = gisPropMan->layers();

        // Get the first layer
        auto layer = gisPropMan->getLayer(layers.at(0));

        // Remove attribute from layer
        layer->removeAttribute(_T("Text to be removed"));
    }

    // Change layer name
    if (true)
    {
        AcDbObjectId idGisPropMan;
        BrxCvDbGisPropertyManager::getManager(idGisPropMan, pDb, true);
        AcDbObjectPointer<BrxCvDbGisPropertyManager> gisPropMan(idGisPropMan, AcDb::OpenMode::kForWrite);
        if (!gisPropMan)
            return;

        // Get all layers from database
        auto layers = gisPropMan->layers();

        // Get the second layer
        auto layer = gisPropMan->getLayer(layers.at(1));

        // Remove attribute from layer
        layer->setName(_T("Renamed SampleLayer"));
    }

    // Remove a GIS layer
    if (true)
    {
        AcDbObjectId idGisPropMan;
        BrxCvDbGisPropertyManager::getManager(idGisPropMan, pDb, true);
        AcDbObjectPointer<BrxCvDbGisPropertyManager> gisPropMan(idGisPropMan, AcDb::OpenMode::kForWrite);
        if (!gisPropMan)
            return;

        // Remove a GIS layer from database
        gisPropMan->removeLayer(_T("Layer to be removed"));
    }

    // Remove a feature
    if (true)
    {
        AcDbObjectId idGisPropMan;
        BrxCvDbGisPropertyManager::getManager(idGisPropMan, pDb, true);
        AcDbObjectPointer<BrxCvDbGisPropertyManager> gisPropMan(idGisPropMan, AcDb::OpenMode::kForWrite);
        if (!gisPropMan)
            return;

        // Get all layers from database
        auto layers = gisPropMan->layers();

        // Get the first layer
        auto layer = gisPropMan->getLayer(layers.at(0));

        // Get all features on a GIS layer
        auto allLayerFeatures = layer->features();

        // Remove second feature from GIS layer
        layer->removeFeature(allLayerFeatures.at(1));
    }

    // Simple report
    if (true)
    {
        AcDbObjectId idGisPropMan;
        BrxCvDbGisPropertyManager::getManager(idGisPropMan, pDb, true);
        AcDbObjectPointer<BrxCvDbGisPropertyManager> gisPropMan(idGisPropMan, AcDb::OpenMode::kForWrite);
        if (!gisPropMan)
            return;

        // Get all GIS layers in the database
        auto layerNames = gisPropMan->layers();
        acutPrintf(_T("\nNumber of layers in the database: %d."), layerNames.length());

        for (auto layerName : layerNames)
        {
            acutPrintf(_T("\n*Layer name: %s."), layerName.kwszPtr());
            auto layer = gisPropMan->getLayer(layerName);

            // Get all features on a GIS layer
            auto allLayerFeatures = layer->features();
            acutPrintf(_T("\n**Number of features: %d."), allLayerFeatures.length());

            for (auto featureId : allLayerFeatures)
            {
                // Get the feature by id
                auto feature = layer->getFeature(featureId);
                auto featureAttributes = feature->featureData().attributes();
                acutPrintf(_T("\n***Number of attributes: %d."), featureAttributes.length());
                for (auto attr : featureAttributes)
                {
                    switch (attr.type())
                    {
                    case EGisAttrType::eDouble:
                        acutPrintf(_T("\n****Attribute type: Double, Value: %f."), attr.valDbl());
                        break;
                    case EGisAttrType::eInt32:
                        acutPrintf(_T("\n****Attribute type: Int32, Value: %d."), attr.valInt());
                        break;
                    case EGisAttrType::eInt64:
                        acutPrintf(_T("\n****Attribute type: Int64, Value: %lld."), attr.valInt64());
                        break;
                    case EGisAttrType::eString:
                        acutPrintf(_T("\n****Attribute type: String, Value: %s."), attr.valStr().kwszPtr());
                        break;
                    case EGisAttrType::eNone:
                        acutPrintf(_T("\n****Attribute type: None"));
                        break;
                    }
                }
            }
            acutPrintf(_T("\n-----------------------------------------------\n"));
        }

    }

}

