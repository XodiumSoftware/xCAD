// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// system
using System;
using System.Collections.Generic;
using System.Linq;

// ODA
using Teigha.Runtime;
using Teigha.DatabaseServices;
using Teigha.Geometry;

// Bricsys
using Bricscad.ApplicationServices;
using Bricscad.Runtime;
using Bricscad.EditorInput;
using Bricscad.Civil;
using Bricscad.CivilExtensions;

// alias
using _AcRx = Teigha.Runtime;
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;
using _AcCiv = Bricscad.Civil;

namespace CsBrxMgdCivil
{
    class GisSample
    {
        //This is a helper function for adding a line entity to database
        public static _AcDb.ObjectId AddLineEntity(_AcDb.Database db, _AcGe.Point3d startPt, _AcGe.Point3d endPt)
        {
            _AcDb.ObjectId idLine;
            using (var tr = db.TransactionManager.StartTransaction())
            {
                using (var lineObject = new _AcDb.Line(startPt, endPt))
                {
                    _AcDb.ObjectId idSpace = db.CurrentSpaceId;
                    using (var MSpace = tr.GetObject(idSpace, _AcDb.OpenMode.ForWrite))
                    {
                        _AcDb.BlockTableRecord MSpaceBTR = MSpace as _AcDb.BlockTableRecord;
                        idLine = MSpaceBTR.AppendEntity(lineObject);
                    }
                    tr.AddNewlyCreatedDBObject(lineObject, true);
                    tr.Commit();
                }
            }
            return idLine;
        }

        public static void do_GISWorkflow()
        {
            _AcDb.Database db = _AcDb.HostApplicationServices.WorkingDatabase;

            // Get civil GIS property manager id from database or create it if not present
            _AcDb.ObjectId propManagerId = db.GetCivilGisPropertyManager(true);
            if (propManagerId.IsNull)
                return;

            // Create gis layer definition and set gis layer name and attributes
            // Also add some features to one of the GIS layers and set some attribute data to one of the features
            using (_AcDb.Transaction trans = db.TransactionManager.StartTransaction())
            {
                using (_AcCiv.GisPropertyManager gisPM = (_AcCiv.GisPropertyManager)trans.GetObject(propManagerId, _AcDb.OpenMode.ForWrite))
                {

                    // prepare a gis layer definition with attribute names and types
                    _AcCiv.GisLayerDefinition layerDef = new _AcCiv.GisLayerDefinition();
                    ICollection<_AcCiv.GisFeatureAttributeDefinition> attribDefs = new List<_AcCiv.GisFeatureAttributeDefinition>();
                    
                    _AcCiv.GisFeatureAttributeDefinition attribDef = new _AcCiv.GisFeatureAttributeDefinition();
                    attribDef.Name = "Double value";
                    attribDef.Type = _AcCiv.GisFeatureAttributeDefinition.AttributeType.Double;
                    attribDefs.Add(attribDef);
                    
                    attribDef = new _AcCiv.GisFeatureAttributeDefinition();
                    attribDef.Name = "Text";
                    attribDef.Type = _AcCiv.GisFeatureAttributeDefinition.AttributeType.String;
                    attribDefs.Add(attribDef);
                    
                    attribDef = new _AcCiv.GisFeatureAttributeDefinition();
                    attribDef.Name = "Text to be removed";
                    attribDef.Type = _AcCiv.GisFeatureAttributeDefinition.AttributeType.String;
                    attribDefs.Add(attribDef);

                    attribDef = new _AcCiv.GisFeatureAttributeDefinition();
                    attribDef.Name = "Integer value";
                    attribDef.Type = _AcCiv.GisFeatureAttributeDefinition.AttributeType.Int32;
                    attribDefs.Add(attribDef);

                    attribDef = new _AcCiv.GisFeatureAttributeDefinition();
                    attribDef.Name = "Long integer value";
                    attribDef.Type = _AcCiv.GisFeatureAttributeDefinition.AttributeType.Int64;
                    attribDefs.Add(attribDef);


                    layerDef.FeatureAttributeDefinitions = attribDefs;

                    // add several layers to the database
                    // specify the geometry type of the layer and a layer source
                    // layer source is only informational, used in UI to inform user where the layer comes from (API, current drawing, filepath to the source file ...)
                    _AcCiv.GisFeature.GeometryType geomType = _AcCiv.GisFeature.GeometryType.LineString; // geometry type of the layer
                    _AcCiv.GisLayer layer = gisPM.CreateLayer("SampleLayer", layerDef, geomType, "from API 1");
                    _AcCiv.GisLayer layer2 = gisPM.CreateLayer("SampleLayer 2", layerDef, geomType, "from API 2");
                    _AcCiv.GisLayer layer3 = gisPM.CreateLayer("Layer to be removed", layerDef, geomType, "from API 3");


                    // add first feature to the GIS layer
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////

                    _AcDb.ObjectIdCollection idArray = new _AcDb.ObjectIdCollection();

                    // add a line to the drawing - we will create a GIS feature from it
                    _AcDb.ObjectId lineId = AddLineEntity(db, new _AcGe.Point3d(0,0,0), new _AcGe.Point3d(10, 10, 10));
                    idArray.Add(lineId);
                    
                    //add feature to the GIS layer
                    ulong featureId = layer.AddFeature(idArray);
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////


                    //add second feature to the gis layer
                    //////////////////////////////////////////////////////////////////////////////////////////////////////

                    lineId = AddLineEntity(db, new _AcGe.Point3d(10, 10, 10), new _AcGe.Point3d(20, 0, 0));
                    idArray.Clear();
                    idArray.Add(lineId);

                    //add feature to the GIS layer
                    ulong featureId2 = layer.AddFeature(idArray);
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////


                    //add another feature to the gis layer
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////

                    lineId = AddLineEntity(db, new _AcGe.Point3d(20, 0, 0), new _AcGe.Point3d(30, 30, 30));
                    idArray.Clear();
                    idArray.Add(lineId);

                    ulong featureId3 = layer.AddFeature(idArray);
                    ///////////////////////////////////////////////////////////////////////////////////////////////////////


                    // Get the first feature from the first layer
                    _AcCiv.GisFeature feature = layer.GetFeature(featureId);

                    // Set the feature data
                    _AcCiv.GisFeatureAttributeData attribData = feature.FeatureData;
                    ICollection<_AcCiv.GisFeatureAttribute> attribs = attribData.FeatureAttributes;
                    attribs.ElementAt(0).DoubleValue = 58.46;
                    attribs.ElementAt(1).StringValue = "My text";
                    attribs.ElementAt(2).StringValue = "My useless text";
                    attribs.ElementAt(3).IntegerValue = 243;
                    attribs.ElementAt(4).LongIntegerValue = 223372036854775808;
                    attribData.FeatureAttributes = attribs;
                    feature.FeatureData = attribData;
                }
                trans.Commit();
            }

            // Change a value in an attribute
            using (_AcDb.Transaction trans = db.TransactionManager.StartTransaction())
            {
                using (_AcCiv.GisPropertyManager gisPM = (_AcCiv.GisPropertyManager)trans.GetObject(propManagerId, _AcDb.OpenMode.ForWrite))
                {
                    // Get all layers from database
                    var layers = gisPM.Layers;

                    // Get the first layer
                    _AcCiv.GisLayer layer = layers.ElementAt(0);

                    // Get the first featureId from layer
                    ulong featureId = layer.FeatureIds.ElementAt(0);

                    // Get the feature by id
                    _AcCiv.GisFeature feature = layer.GetFeature(featureId);

                    // find attribute by name
                    _AcCiv.GisFeatureAttribute attrib = feature.FindAttribute("Double value");

                    // Change attribute data
                    if (attrib.Type == GisFeatureAttributeDefinition.AttributeType.Double)
                    {
                        attrib.DoubleValue = 46.58;
                    }
                    else
                    {
                        //wrong type - should not happen
                    }

                    // Update atrribute with new data
                    feature.UpdateAttribute(attrib);

                }
                trans.Commit();
            }

            // Add new attribute
            using (_AcDb.Transaction trans = db.TransactionManager.StartTransaction())
            {
                using (_AcCiv.GisPropertyManager gisPM = (_AcCiv.GisPropertyManager)trans.GetObject(propManagerId, _AcDb.OpenMode.ForWrite))
                {
                    // Get all layers from database
                    var layers = gisPM.Layers;

                    // Get the first layer
                    _AcCiv.GisLayer layer = layers.ElementAt(0);

                    // Get the first featureId from layer
                    ulong featureId = layer.FeatureIds.ElementAt(0);

                    // Get the feature by id
                    _AcCiv.GisFeature feature = layer.GetFeature(featureId);

                    _AcCiv.GisFeatureAttributeDefinition attribDef = new _AcCiv.GisFeatureAttributeDefinition();
                    attribDef.Name = "New int attribute";
                    attribDef.Type = _AcCiv.GisFeatureAttributeDefinition.AttributeType.Int32;

                    // add new attribute definition to a layer
                    // features are not yet updated with attribute values at this stage
                    layer.AddAttribute(attribDef);

                    // Update attribute values for a feature
                    _AcCiv.GisFeatureAttribute attrib = feature.FindAttribute("New int attribute");
                    attrib.IntegerValue = 77;
                    feature.UpdateAttribute(attrib);
                }
                trans.Commit();
            }

            // Remove an attribute
            using (_AcDb.Transaction trans = db.TransactionManager.StartTransaction())
            {
                using (_AcCiv.GisPropertyManager gisPM = (_AcCiv.GisPropertyManager)trans.GetObject(propManagerId, _AcDb.OpenMode.ForWrite))
                {
                    // Get all layers from database
                    var layers = gisPM.Layers;

                    // Get the first layer
                    _AcCiv.GisLayer layer = layers.ElementAt(0);

                    // Remove attribute from layer
                    layer.RemoveAttribute("Text to be removed");
                }
                trans.Commit();
            }

            // Change layer name
            using (_AcDb.Transaction trans = db.TransactionManager.StartTransaction())
            {
                using (_AcCiv.GisPropertyManager gisPM = (_AcCiv.GisPropertyManager)trans.GetObject(propManagerId, _AcDb.OpenMode.ForWrite))
                {
                    // Get all layers from database
                    var layers = gisPM.Layers;

                    // get the second layer
                    _AcCiv.GisLayer layer = layers.ElementAt(1);

                    // Change the name of the GIS layer
                    layer.Name = "Renamed SampleLayer";
                }
                trans.Commit();
            }

            // Remove a GIS layer
            using (_AcDb.Transaction trans = db.TransactionManager.StartTransaction())
            {
                using (_AcCiv.GisPropertyManager gisPM = (_AcCiv.GisPropertyManager)trans.GetObject(propManagerId, _AcDb.OpenMode.ForWrite))
                {
                    // Remove a GIS layer from database
                    gisPM.RemoveLayer("Layer to be removed");
                }
                trans.Commit();
            }

            // Remove a feature
            using (_AcDb.Transaction trans = db.TransactionManager.StartTransaction())
            {
                using (_AcCiv.GisPropertyManager gisPM = (_AcCiv.GisPropertyManager)trans.GetObject(propManagerId, _AcDb.OpenMode.ForWrite))
                {
                    // Get all GIS layers in the database
                    var layers = gisPM.Layers;

                    // Get the first layer
                    _AcCiv.GisLayer layer = layers.ElementAt(0);
                    
                    // Get all features on a GIS layer
                    ICollection<ulong> allLayerFeatures = layer.FeatureIds;

                    // Remove second feature from GIS layer
                    layer.RemoveFeature(allLayerFeatures.ElementAt(1));
                }
                trans.Commit();
            }

            //Simple report
            using (_AcDb.Transaction trans = db.TransactionManager.StartTransaction())
            {
                using (_AcCiv.GisPropertyManager gisPM = (_AcCiv.GisPropertyManager)trans.GetObject(propManagerId, _AcDb.OpenMode.ForWrite))
                {
                    _AcAp.Document doc = _AcAp.Application.DocumentManager.MdiActiveDocument;
                    _AcEd.Editor ed = doc.Editor;

                    // Get all GIS layers in the database
                    var layers = gisPM.Layers;
                    ed.WriteMessage(string.Format("\nNumber of layers in the database: {0}.", layers.Count));

                    foreach (_AcCiv.GisLayer layer in layers)
                    {
                        ed.WriteMessage(string.Format("\n*Layer name: {0}.", layer.Name));
                        
                        // Get all features on a GIS layer
                        ICollection<ulong> allLayerFeatures = layer.FeatureIds;
                        ed.WriteMessage(string.Format("\n**Number of features: {0}.", allLayerFeatures.Count));
                        foreach (var featureId in allLayerFeatures)
                        {
                            // Get the feature by id
                            _AcCiv.GisFeature feature = layer.GetFeature(featureId);
                            var featureAttributes = feature.FeatureData.FeatureAttributes;
                            ed.WriteMessage(string.Format("\n***Number of attributes: {0}.", featureAttributes.Count));
                            foreach (var attr in featureAttributes)
                            {
                                switch (attr.Type)
                                {
                                    case GisFeatureAttributeDefinition.AttributeType.Double:
                                        ed.WriteMessage(string.Format("\n****Attribute type: Double, Value: {0}.", attr.DoubleValue));
                                        break;
                                    case GisFeatureAttributeDefinition.AttributeType.Int32:
                                        ed.WriteMessage(string.Format("\n****Attribute type: Int32, Value: {0}.", attr.IntegerValue));
                                        break;
                                    case GisFeatureAttributeDefinition.AttributeType.Int64:
                                        ed.WriteMessage(string.Format("\n****Attribute type: Int64, Value: {0}.", attr.LongIntegerValue));
                                        break;
                                    case GisFeatureAttributeDefinition.AttributeType.String:
                                        ed.WriteMessage(string.Format("\n****Attribute type: String, Value: {0}.", attr.StringValue));
                                        break;
                                    case GisFeatureAttributeDefinition.AttributeType.None:
                                        break;
                                }
                            }
                        }
                        ed.WriteMessage(string.Format("\n-----------------------------------------------\n"));
                    }
                }
                trans.Commit();
            }
        }
    }
}
