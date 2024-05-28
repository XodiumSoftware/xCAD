// Property of Bricsys NV. All rights reserved. 
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil GIS functionality + interfaces

#include "BrxSpecific/AcSharedPtr.h"
#include "Misc/AcArray.h"
#include "Misc/AcString.h"
#include "AcDb/AcDbObjectId.h"

#include "BrxSpecific/civil/BrxCvDbSubObject.h"
#include "BrxSpecific/civil/BrxCvDbObject.h"

enum class EGisAttrType : int
{
    eNone   = -1,
    eInt32  = 0,
    eInt64  = 1,
    eDouble = 2,
    eString = 3,
};

enum class EGisGeomType : int
{
    eWkbUnknown            = 0,
    eWkbPoint              = 1,
    eWkbLineString         = 2,
    eWkbPolygon            = 3,
    eWkbMultiPoint         = 4,
    eWkbMultiLineString    = 5,
    eWkbMultiPolygon       = 6,
    eWkbGeometryCollection = 7,
};

class BrxCvGisFeatureAttributeImpl; // internal usage only

// data class to hold a single GIS Feature Attribute Definition
class BRX_EXPORT BrxCvGisFeatureAttributeDefinition
{
    friend BrxCvGisFeatureAttributeImpl;
    friend AcArray<BrxCvGisFeatureAttributeDefinition, AcArrayObjectCopyReallocator<BrxCvGisFeatureAttributeDefinition> >;
    BrxCvGisFeatureAttributeImpl* m_pImpl;

    BrxCvGisFeatureAttributeDefinition(BrxCvGisFeatureAttributeImpl* pImpl); // for internal use only

protected:
    BrxCvGisFeatureAttributeDefinition(); // for internal use only

public:
    BrxCvGisFeatureAttributeDefinition(const BrxCvGisFeatureAttributeDefinition& other);
    BrxCvGisFeatureAttributeDefinition& operator=(const BrxCvGisFeatureAttributeDefinition& other);

    BrxCvGisFeatureAttributeDefinition(const ACHAR* szName, const EGisAttrType type);
    virtual ~BrxCvGisFeatureAttributeDefinition();

    bool setType(const EGisAttrType type);
    EGisAttrType type() const;
    bool setName(const ACHAR* szName);
    AcString name() const;
};

// data class to hold a single GIS Feature Attribute
class BRX_EXPORT BrxCvGisFeatureAttribute
{
    friend BrxCvGisFeatureAttributeImpl;
    friend AcArray<BrxCvGisFeatureAttribute, AcArrayObjectCopyReallocator<BrxCvGisFeatureAttribute> >;
    BrxCvGisFeatureAttributeImpl* m_pImpl;

    BrxCvGisFeatureAttribute(BrxCvGisFeatureAttributeImpl* pImpl); // for internal use only

protected:
    BrxCvGisFeatureAttribute(); // for internal use only

public:
    BrxCvGisFeatureAttribute(const BrxCvGisFeatureAttribute& other);
    BrxCvGisFeatureAttribute& operator=(const BrxCvGisFeatureAttribute& other);

    BrxCvGisFeatureAttribute(const BrxCvGisFeatureAttributeDefinition& attrDef);
    virtual ~BrxCvGisFeatureAttribute();

    EGisAttrType type() const;
    AcString name() const;
    int valInt() const;
    Adesk::Int64 valInt64() const;
    double valDbl() const;
    AcString valStr() const;

    bool setVal(const int val);
    bool setVal(const Adesk::Int64 szVal);
    bool setVal(const double val);
    bool setVal(const ACHAR* val);
};

typedef AcArray<BrxCvGisFeatureAttributeDefinition>  BrxCvGisFeatureAttributeDefinitionArray;
typedef AcArray<BrxCvGisFeatureAttribute>  BrxCvGisFeatureAttributeArray;

class BrxCvGisFeatureAttributeDataImpl; // internal usage only

// BrxCvGisLayerDefinition : this is a list of attribute names and types representing the definition of a GIS layer
class BRX_EXPORT BrxCvGisLayerDefinition
{
    friend BrxCvGisFeatureAttributeDataImpl;
    BrxCvGisFeatureAttributeDataImpl* m_pImpl;

    BrxCvGisLayerDefinition(BrxCvGisFeatureAttributeDataImpl* impl); // for internal use only

public:
    BrxCvGisLayerDefinition();
    BrxCvGisLayerDefinition(const BrxCvGisLayerDefinition& other);
    BrxCvGisLayerDefinition& operator=(const BrxCvGisLayerDefinition& other);
    virtual ~BrxCvGisLayerDefinition();

    Adesk::UInt64 count() const;
    void reserve(const Adesk::UInt64 len);

    bool addAttributeDefinition(const BrxCvGisFeatureAttributeDefinition& attribute);
    bool insertAttributeDefinitionAt(const Adesk::UInt64 idx, const BrxCvGisFeatureAttributeDefinition& attribute);
    bool setAttributeDefinitionAt(const Adesk::UInt64 idx, const BrxCvGisFeatureAttributeDefinition& attribute);
    BrxCvGisFeatureAttributeDefinition attributeDefinitionAt(const Adesk::UInt64 idx) const;
    bool findAttributeDefinition(const ACHAR* attributeName, Adesk::UInt64& index) const;

    BrxCvGisFeatureAttributeDefinitionArray attributeDefinitions() const;
    bool addAttributeDefinitions(const BrxCvGisFeatureAttributeDefinitionArray& attributes);

    bool removeAttributeDefinition(const Adesk::UInt64 idx);
    bool clear();
};

// BrxCvGisFeatureAttributeData : this is a list of attributes representing one table in a GIS feature
class BRX_EXPORT BrxCvGisFeatureAttributeData
{
    friend BrxCvGisFeatureAttributeDataImpl;
    friend AcArray<BrxCvGisFeatureAttributeData, AcArrayObjectCopyReallocator<BrxCvGisFeatureAttributeData> >;
    BrxCvGisFeatureAttributeDataImpl* m_pImpl;

    BrxCvGisFeatureAttributeData(BrxCvGisFeatureAttributeDataImpl* impl); // for internal use only

public:
    BrxCvGisFeatureAttributeData();
    BrxCvGisFeatureAttributeData(const BrxCvGisFeatureAttributeData& other);
    BrxCvGisFeatureAttributeData& operator=(const BrxCvGisFeatureAttributeData& other);
    virtual ~BrxCvGisFeatureAttributeData();

    Adesk::UInt64 count() const;
    void reserve(const Adesk::UInt64 len);

    Adesk::UInt64 featureId() const;

    bool addAttribute(const BrxCvGisFeatureAttribute& attribute);
    bool insertAttributeAt(const Adesk::UInt64 idx, const BrxCvGisFeatureAttribute& attribute);
    bool setAttributeAt(const Adesk::UInt64 idx, const BrxCvGisFeatureAttribute& attribute);
    BrxCvGisFeatureAttribute attributeAt(const Adesk::UInt64 idx) const;

    bool findAttribute(const ACHAR* attributeName, Adesk::UInt64& index) const;

    BrxCvGisFeatureAttributeArray attributes() const;
    bool addAttributes(const BrxCvGisFeatureAttributeArray& attributes);

    bool removeAttribute(const Adesk::UInt64 idx);
    bool clear();
};

typedef AcArray<BrxCvGisFeatureAttributeData> BrxCvGisFeatureAttributeDataArray;

// BrxCvGisTable : table of attributes of features on the same layer;
// each row is one feature, the columns are the attributes
class BrxCvGisTableImpl;  // internal usage only

class BRX_EXPORT BrxCvGisTable
{
    friend BrxCvGisTableImpl;
    BrxCvGisTableImpl* m_pImpl;

    BrxCvGisTable(BrxCvGisTableImpl* impl); // for internal use only

public:
    BrxCvGisTable();
    BrxCvGisTable(const BrxCvGisTable& other);
    BrxCvGisTable& operator=(const BrxCvGisTable& other);
    virtual ~BrxCvGisTable();

    Adesk::UInt64 count() const;
    void reserve(const Adesk::UInt64 len);

    bool addFeatureAttributeData(const BrxCvGisFeatureAttributeData& table);
    bool insertFeatureAttributeDataAt(const Adesk::UInt64 idx, const BrxCvGisFeatureAttributeData& table);

    BrxCvGisFeatureAttributeData featureAttributeDataAt(const Adesk::UInt64 idx) const;
    Adesk::UInt64 findFeatureAttributeData(const Adesk::UInt64 featureId) const;
    bool setFeatureAttributeDataAt(const Adesk::UInt64 idx, const BrxCvGisFeatureAttributeData& table);

    BrxCvGisFeatureAttributeDataArray attributeData() const;

    bool removeFeatureAttributeData(const Adesk::UInt64 idx);
    bool clear();
};

// BrxCvDbGisFeature : a Point, Line, Polygon, closed Polygon, ... in GIS context
class BrxCvDbGisFeatureImpl;  // internal usage only

class BRX_EXPORT BrxCvDbGisFeature : public BrxCvDbSubObject
{
    friend BrxCvDbGisFeatureImpl;
    friend AcArray<BrxCvDbGisFeature, AcArrayObjectCopyReallocator<BrxCvDbGisFeature> >;

protected:
    BrxCvDbGisFeature(); // for internal use only

public:
    ACRX_DECLARE_MEMBERS(BrxCvDbGisFeature);

    virtual ~BrxCvDbGisFeature();

    // feature type
    EGisGeomType type() const;

    // feature id
    Adesk::UInt64 featureId() const;

    // layerName
    AcString layerName() const;

    // get all parts (object ids) for a feature (id)
    AcDbObjectIdArray parts() const;

    // get an attribute from a feature
    BrxCvGisFeatureAttribute attribute(const ACHAR* szAttributeName) const;

    // get all attributes from a feature
    BrxCvGisFeatureAttributeData featureData() const;

    // update an attribute of an entity
    bool updateAttribute(const BrxCvGisFeatureAttribute& attribute);

    // update all attribute data of a feature
    bool updateAttributeData(const BrxCvGisFeatureAttributeData& featureData);
};

typedef AcSharedPtr<BrxCvDbGisFeature>  BrxCvDbGisFeaturePtr;

class BrxCvDbGisLayerImpl;  // internal usage only

// BrxCvDbGisLayer : manages layer-related GIS features
class BRX_EXPORT BrxCvDbGisLayer : public BrxCvDbSubObject
{
    friend BrxCvDbGisLayerImpl;
    friend AcArray<BrxCvDbGisLayer, AcArrayObjectCopyReallocator<BrxCvDbGisLayer> >;

protected:
    BrxCvDbGisLayer(); // for internal use only

public:
    ACRX_DECLARE_MEMBERS(BrxCvDbGisLayer);

    virtual ~BrxCvDbGisLayer();

    // returns the layer type
    EGisGeomType type() const;

    // returns the layer source
    AcString layerSource() const;

    // returns all features located on this layer
    AcUInt64Array features() const;

    // get all featureIds on this layer and attribute tables for them
    BrxCvGisTable layerData() const;

    // remove features from this layer
    bool removeFeatures(const AcUInt64Array& featureIds);

    // remove feature from this layer
    bool removeFeature(const Adesk::UInt64 featureId);

    // add a feature to this layer
    bool addFeature(const AcDbObjectIdArray& ids, Adesk::UInt64& id);

    // get attribute definitions from this layer
    BrxCvGisLayerDefinition layerDefinition() const;

    // add an attribute to this layer
    bool addAttribute(const BrxCvGisFeatureAttributeDefinition& attribute);

    // remove an attribute from this layer
    bool removeAttribute(const ACHAR* szAttribute);

    // check if feature featureId is on this layer
    bool isOnLayer(const Adesk::UInt64 featureId) const;

    // get a feature
    BrxCvDbGisFeaturePtr getFeature(const Adesk::UInt64 featureId) const;
};

typedef AcSharedPtr<BrxCvDbGisLayer>  BrxCvDbGisLayerPtr;

// BrxCvDbGisPropertyManager : main GIS property manager object
class BRX_EXPORT BrxCvDbGisPropertyManager : public BrxCvDbObject
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbGisPropertyManager);

    // returns the AcDbObjectId if the GIS PropertyManager for a database
    static Acad::ErrorStatus getManager(AcDbObjectId& idGisPropMngr, AcDbDatabase* db,
                                        bool createIfNotExists = true);

    // returns the GIS PropertyManager for a database, opened for read or write
    static Acad::ErrorStatus openManager(BrxCvDbGisPropertyManager*& pGisPropMngr, AcDbDatabase* db,
                                         AcDb::OpenMode openMode = AcDb::kForRead,
                                         bool createIfNotExists = true);

    virtual ~BrxCvDbGisPropertyManager();

    // returns the Feature ID for the specified entity
    bool featureId(const AcDbObjectId& idEntity, Adesk::UInt64& id) const;

    // returns all GIS Features from the associated database
    AcUInt64Array features() const;

    // returns all GIS Layers (table names !) from the associated database
    AcStringArray layers() const;

    // creates a new GIS Layer and returns it (if not yet existing) using the given layer definition and specifying the source of the layer
    BrxCvDbGisLayerPtr createLayer(const ACHAR *szLayerName, const BrxCvGisLayerDefinition& layerDefinition, const EGisGeomType& geomType, const ACHAR* szLayerSource);

    // removes the specified Layer including all features
    bool removeLayer(const ACHAR* szGisLayerName);

    // get the GIS Layer object for specified layer name
    BrxCvDbGisLayerPtr getLayer(const ACHAR* szGisLayerName) const;
};
