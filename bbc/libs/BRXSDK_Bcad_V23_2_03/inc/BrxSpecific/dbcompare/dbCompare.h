// Copyright (C) Menhirs NV. All rights reserved.

// dbCompare.h
// BRX API for "DWG Compare" functionality for custom entities

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include "Misc/MiscGlobal.h"


/* This header file is provided to allow custom entities to participate in
 * BricsCAD's "DWG Compare" functionality.
 *
 * "DWG Compare" is based on the data stream written via 'dwgOutFields()';
 * therefore, custom entities, if they want to participate in "DWG Compare",
 * they need to 'register' a description of their custom data, written during
 * dwgOutFields, after the base class dwgOutFields() call
 * (meaning, only the *OWN* data are to be described)
 *
 * Such registration is available by the 'acdbRegisterSchema()' function -
 * it registers a XML file, which describes the custom data items being filed.
 *
 * For an example for a custom entity description via Schema Xml see :
 * "BrxSpecific/dbcompare/CustomEntityExample.txds"
 * 
 * As an example, BRX SDK also provides
 * BrxSpecific/dbcompare/AcDbCustomEntitySample.cpp/h
 * BrxSpecific/dbcompare/AcDbCustomEntitySample.txds
 * 
 * ---------------------------------------------------------------------------
 * 
 * short description of it's content :
 * 
 * 
 * <xs:complexType name="AcDbLineOrCircle" oda:version="1.0">
 *    specifies the custom entity class name
 * 
 * <xs:extension base="AcDbEntity">
 *    specifies the base class name for the AcDbLineOrCircle custom entity
 * 
 * <xs:sequence>
 *     :
 * </xs:sequence>
 *    contains the sequence of data items as written in dwgOutFields() function,
 *    following the base class' default data items;
 * 
 * -------- items definition between <xs:sequence> and </xs:sequence> --------
 * 
 * <xs:element name="BasePoint" type="OdGePoint3d"/>
 *    specifies a "BasePoint" data item, using OdGePoint3d (same as AcGePoint3d) type
 * 
 * <xs:element name="IsLine" type="xs:boolean" oda:isCondition=""/>
 *    specifies a "IsLine" data item, using 'bool' type
 * 
 * <oda:condition name="IsLine" oda:conditionValue="false">
 *   <xs:element name="Radius" type="xs:double"/>
 * </oda:condition>
 *    specifies a "Radius" data item, using 'double' type;
 *    but read-in only if the preceding data item "IsLine" is 'false'
 * 
 * <oda:condition name="IsLine" oda:conditionValue="true">
 *   <xs:element name="EndPoint" type="OdGePoint3d"/>
 * </oda:condition>
 *    specifies a "EndPoint" data item, using 'OdGePoint3d' type;
 *    but read-in only if the preceding data item "IsLine" is 'true'
 * 
 * ---------------------------------------------------------------------------
 * 
 * Hint 1 :
 *   ideally, registering the custom entity Schema XML is best done at a code
 *   place close to CustomEntity::rxInit() call, or inside kInitAppMsg stage;
 *   multiple registration is no problem;
 *   unregistering the Schema XML file is not necessary
 * 
 * Hint 2 :
 *   data item types are specified as ODA Teigha types :
 *      OdGePoint2d   (AcGePoint2d)
 *      OdGePoint3d   (AcGePoint3d)
 *      OdGeVector2d  (AcGeVector2d)
 *      OdGeVector3d  (AcGeVector3d)
 *      OdGeMatrix2d  (AcGeMatrix2d)
 *      OdGeMatrix3d  (AcGeMatrix3d)
 * 
 * Hint 3 :
 *   complete documentation for the Schema definition can be found here :
 *   https://docs.opendesign.com/td/db_xmlScheme.html
 */

// register the XML file describing the custom entity data items
bool acdbRegisterSchema(const ACHAR* schemaXmlFile);

