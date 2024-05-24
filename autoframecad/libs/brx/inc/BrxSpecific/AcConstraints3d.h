// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// declares the high-level 3D Constraints API

#ifndef _AcConstraints3d_h_Included
#define _AcConstraints3d_h_Included

#include "brx_importexport.h"
#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcGe/AcGePlane.h"
#include "AcSharedPtr.h"

// The following deprecated global functions have been renamed to reflect their expanded
// capabilities. The old names are mapped to new names here for backward compatibility.
#define acdb3DCGetConstraintsGroup acdbGetConstraintsGroup
#define acdb3DCGetAllConstraintsGroups acdbGetAllConstraintsGroups
#define acdb3DCGetComponentParametersNames acdbGetBlockParametersNames
#define acdb3DCSetComponentParameterExpression acdbSetBlockParameterExpression
#define acdb3DCGetComponentParameterExpression acdbGetBlockParameterExpression
#define acdb3DCGetComponentParameterValue acdbGetBlockParameterValue
#define acdb3DCGetEntityGuiName acdbGetEntityGuiName
#define acdb3DCSetEntityGuiName acdbSetEntityGuiName
#define acdb3DCComponentParameterHasStringValue acdbBlockParameterHasStringValue
#define acdb3DCGetComponentParameterStringValue acdbGetBlockParameterStringValue
#define acdb3DCEffectiveBlockRefName acdbEffectiveBlockRefName
#define acdb3DCEffectiveBlockTableRecord acdbEffectiveBlockTableRecord

// Constraints related definitions
class AcVariable;
class AcConstraintArgument;
class AcConstraint;
class AcConstraintsGroup;

typedef AcSharedPtr<AcVariable>         AcVariablePtr;
typedef AcSharedPtr<AcConstraint>       AcConstraintPtr;
typedef AcSharedPtr<AcConstraintsGroup> AcConstraintsGroupPtr;

typedef AcArray<AcVariablePtr>          AcVariablePtrArray;
typedef AcArray<AcConstraintPtr>        AcConstraintPtrArray;
typedef AcArray<AcConstraintsGroupPtr>  AcConstraintsGroupPtrArray;

// DesignTable related definitions
class AcDesignTableConfigurationEntry;
class AcDesignTableConfiguration;
class AcDesignTable;

typedef AcSharedPtr<AcDesignTableConfigurationEntry> AcDesignTableConfigurationEntryPtr;
typedef AcSharedPtr<AcDesignTableConfiguration>      AcDesignTableConfigurationPtr;
typedef AcSharedPtr<AcDesignTable>                   AcDesignTablePtr;

typedef AcArray<AcDesignTableConfigurationEntryPtr>  AcDesignTableConfigurationEntryArray;
typedef AcArray<AcDesignTableConfigurationPtr>       AcDesignTableConfigurationArray;
typedef AcArray<AcDesignTablePtr>                    AcDesignTableArray;

//========================= Constraints related Classes ========================

// AcConstraintArgument represents constraint argument: ether AcDbFullSubentPath,
//   or World Coordinate system object, or Coordinate system object for block reference
class BRX_IMPORTEXPORT AcConstraintArgument
{
  public:
    // names for coordinate system objects which can be used as constraint arguments: origin, axes and planes.
    enum CoordinateSystemObject
    {
        eCSOrigin,
        eCSX,
        eCSY,
        eCSZ,
        eCSXY,
        eCSYZ,
        eCSZX,
    };

    AcConstraintArgument() {}

    // use AcDbFullSubentPath as the constraint argument
    explicit AcConstraintArgument(const AcDbFullSubentPath& path) : m_path(path) {}

    // use World Coordinate System object as the constraint argument
    explicit AcConstraintArgument(CoordinateSystemObject cs) : m_isCS(true), m_CS(cs) {}

    // use the Coordinate System object of given block reference as the constraint argument
    AcConstraintArgument(const AcDbFullSubentPath& blockReferencePath, CoordinateSystemObject cs)
      : m_path(blockReferencePath), m_isCS(true), m_CS(cs)
    {}

    // return path of the constraint argument, the path of the block reference in particular
    // returns empty path on pure coordinate system object case
    const AcDbFullSubentPath& path() const { return m_path; }

    // returns true if the coordinate system object is used
    bool isCoordinateSystemObject() const { return m_isCS; }

    // returns type of the coordinate system object if it is used, undefined otherwise
    CoordinateSystemObject coordinateSystemObject() const { return m_CS; }

  private:
    AcDbFullSubentPath m_path;
    CoordinateSystemObject m_CS{eCSOrigin};
    bool m_isCS{false};
};

typedef AcArray<AcConstraintArgument> AcConstraintArgumentArray;

// AcVariable class holds the constraints parameter for a single 3D constraint
class BRX_IMPORTEXPORT AcVariable
{
public:
    enum class ExposeMode { eOff = 0, eOn = 1, eUndefined = 2 };
    enum class EGdMode { eOff = 0, eOn = 1, eAuto = 2 };

    virtual ~AcVariable() {};

    /**
     * returns the constraint variable from specified block table record, by variable's name
     * @param[in] blockId - AcDbObjectId of the block table record
     * @param[in] name - name of the variable
     * @param[in] createIfNotExist - if 'true', the constraint variable will be created, if not yet existing
     * @return shared pointer to AcVariable
     */
    static AcVariablePtr getByName(const AcDbObjectId& blockId, const ACHAR* name, bool createIfNotExist = false);

    /**
     * returns all constraint variables from specified block table record
     * @param[in] blockId - AcDbObjectId of block table record
     * @return array of shared pointers to AcVariable
     */
    static AcVariablePtrArray getFromBlock(const AcDbObjectId& blockId);

    /**
     * returns the owner block table record of this constraint variable
     * @return AcDbObjectId of block table record
     */
    virtual AcDbObjectId getBlockId() const = 0;

    /**
     * returns the name of this constraint variable
     * @return variable name
     */
    virtual AcString name() const = 0;

    /**
     * sets the new name of this constraint variable
     * @param[in] name - new variable name
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus setName(const ACHAR* name) = 0;

    /**
     * returns the expression string of this constraint variable
     * @return current expression string of this variable
     */
    virtual AcString expression() const = 0;

    /**
     * sets the new name of this constraint variable
     * @param[in] expr - new expression for this variable
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus setExpression(const ACHAR* expr) = 0;

    /**
     * returns the last successful result of expression evaluation of this constraint variable
     * @return current expression value of this variable, as double
     */
    virtual double value() const = 0;

    /**
     * sets the new expression value for this constraint variable
     * @param[in] value - the new current value
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus setValue(double value) = 0;

    /**
     * @return true if the lower/upper bound is specified for this variable
     */
    virtual bool hasLowerBound() const = 0;
    virtual bool hasUpperBound() const = 0;

    /**
     * @return the current value for the lower/upper bound of this variable
     */
    virtual double lowerBound() const = 0;
    virtual double upperBound() const = 0;

    /**
     * sets the new value for the lower/upper bound of this variable
     * @param[in] value - the new bound value
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus setLowerBound(double value) = 0;
    virtual Acad::ErrorStatus setUpperBound(double value) = 0;

    /**
     * unsets the lower/upper bound of this variable
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus unsetLowerBound() = 0;
    virtual Acad::ErrorStatus unsetUpperBound() = 0;

    /**
     * returns whether this constraint variable is anonymous or not
     * @return true if variable is anonymous, false otherwise
     */
    virtual bool isAnonymous() const = 0;

    /**
     * erase this constraints variable
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus erase() = 0;

    /**
    * @return the current value of Exposed parameter of this constraint variable
    */
    virtual ExposeMode exposed() const = 0;

    /**
    * sets the new value to Exposed parameter of this constraint variable
    * @param[in] mode - the new parameter value
    * @return Acad::eOk if successful, error status otherwise
    */
    virtual Acad::ErrorStatus setExposed(ExposeMode) = 0;

    /**
    * @return the current value of Geometry-driven parameter of this constraint variable
    */
    virtual EGdMode geometryDrivenMode() const = 0;

    /**
    * sets the new value to Geometry-driven parameter of this constraint variable
    * @param[in] mode - the new parameter value
    * @return Acad::eOk if successful, error status otherwise
    */
    virtual Acad::ErrorStatus setGeometryDrivenMode(EGdMode) = 0;

protected:
    AcVariable() {};
private:
    AcVariable(const AcVariable&);
};


// AcConstraint class represents a 3D constraint
class BRX_IMPORTEXPORT AcConstraint
{
public:
    enum ConstraintType
    {
        eAcUnknown = 0,
        eAc3DAngle,
        eAc3DCoincident,
        eAc3DConcentric,
        eAc3DDistance,
        eAc3DFix,
        eAc3DMajorRadius,
        eAc3DMinorRadius,
        eAc3DParallel,
        eAc3DPerpendicular,
        eAc3DPlanarAngle,
        eAc3DRadius,
        eAc3DRigidSet,
        eAc3DTangent,
        eAcCircularArray,
        eAcObjectAngle,
        eAcPath,
    };

    // the values of the attribute that may be assigned to the constraint object
    enum Directions
    {
        eDirectionsAny,
        eDirectionsSame,
        eDirectionsOpposite,
        eDirectionsKeep
    };

    // the values of the attributes that may be assigned to the constraint arguments
    enum MeasurementMode
    {
      eMeasurementModeCenter,      // the center of sphere; the axis of circle, cone, cylinder, or torus
      eMeasurementModeBoundary,    // the boundary of circle, cone, cylinder, sphere, or torus
      eMeasurementModeCentralPoint // the center of circle or torus; the vertex of cone;
                                   // not supported for cylinders and spheres
    };

    enum Placement
    {
      ePlacementAny,
      ePlacementOutside,
      ePlacementInside,
      ePlacementKeep
    };
    // In BRX API the placement arguments should be assigned in the order that DB uses.
    // For example, for the point-plane distance the app should specify the
    // placement attribute for the plane argument, not for the point one.
    // The same order is used in the public API of lgs3d.
    // 3D constraints GUI uses the reverted order.

    virtual ~AcConstraint() {};

    /**
     * returns the owner block table record for this constraint object
     * @return AcDbObjectId of owner block table record
     */
    virtual AcDbObjectId getBlockId() const = 0;

    /**
     * returns whether this constraint variable is dimensional or not
     * @return true if variable is dimensional, false otherwise
     */
    virtual bool isDimensional() const = 0;

    /**
     * returns the parameter variable of dimensional constraint
     * @return shared pointer to variable (might be a NULL pointer)
     */
    virtual AcVariablePtr parameter() const = 0;

    /**
     * returns the associated dimension object for this constraint object
     * @return AcDbObjectId of AcDbDimension object (might be kNull)
     */
    virtual AcDbObjectId getDimension() const = 0;

    /**
     * deprecated
     * returns the array of subentities for this constraint object
     * @return AcDbFullSubentPathArray
     */
    virtual AcDbFullSubentPathArray arguments() const = 0;

    /**
     * returns the array of the arguments for this constraint object
     * @return AcConstraintArgumentArray
     */
    virtual AcConstraintArgumentArray getArguments() const = 0;

    /**
     * returns the name of this constraint object
     * @return constraint name
     */
    virtual AcString name() const = 0;

    /**
     * sets the new name for this constraint object
     * @param[in] name - the new name
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus setName(const ACHAR* name) = 0;

    /**
     * returns the type of this constraint object
     * @return constraint type
     */
    virtual ConstraintType getType() const = 0;

    /**
     * returns the index of this constraints object, unique within the constraints group
     * @return constraint id as Adesk::UInt32
     */
    virtual Adesk::UInt32 nodeId() const = 0;

    ////////////////////////////////////////
    // non-virtual declarations for V22.2
    /**
     * returns whether this constraint is enabled or not
     * @return true if constraint is enabled, false otherwise
     */
    virtual bool isEnabled() const = 0;

    /**
     * sets the Enabled status of this constraint object
     * @param[in] isEnabled - the new status value
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus setEnabled(bool) = 0;

    /**
     * gets the current value of Directions attribute of this constraint object
     * @param[out] directions - it gets the current value of the Directions attribute
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus getDirections(Directions& directions) const = 0;

    /**
     * sets the Directions attribute of this constraint object
     * @param[in] newDirections - the new attribute value
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus setDirections(Directions newDirections) = 0;

    /** set/get the value of given attribute of the given constraint argument of this constraint object
     * @param[in] argIndex - the index of the argument: 0 or 1
     * @param[in] newMeasureMode - new value of MeasurementMode attribute
     * @param[in] newPlacement - new value of Placement attribute
     * @param[out] measureMode - it gets the current value of MeasurementMode attribute
     * @param[out] placement - it gets the current value of Placement attribute
     */
    virtual Acad::ErrorStatus getMeasurementMode(MeasurementMode& measureMode, unsigned int argIndex) const = 0;
    virtual Acad::ErrorStatus setMeasurementMode(MeasurementMode newMeasureMode, unsigned int argIndex) = 0;

    virtual Acad::ErrorStatus getPlacement(Placement& placement, unsigned int argIndex) const = 0;
    virtual Acad::ErrorStatus setPlacement(Placement newPlacement, unsigned int argIndex) = 0;

protected:
    AcConstraint() {};
private:
    AcConstraint(const AcConstraint&);
};


// AcConstraintsGroup class represents the 3D constraints group of a block table record
class BRX_IMPORTEXPORT AcConstraintsGroup
{
public:
    virtual ~AcConstraintsGroup() {};

    /**
     * returns the owner block table record for this constraints group object
     * @return AcDbObjectId of block table record
     */
    virtual AcDbObjectId getBlockId() const = 0;

    /**
     * returns whether this constraints group uses a sketch plane
     * @return true if constraints group has sketch plane, false otherwise
     * @remark reserved for future use, returns false
     */
    virtual bool hasSketchPlane() const = 0;

    /**
     * returns whether this constraints group is transient or not
     * @return true if constraints are transient (not stored in database)
     * @remark reserved for future use, returns false
     */
    virtual bool isTransient() const = 0;

    /**
     * returns the sketch plane for this constraints group
     * Reserved for future use, not implemented yet.
     * @return AcGePlane for 2D groups (currently always the XY plane)
     * @remark reserved for future use, not implemented yet
     */
    virtual AcGePlane getSketchPlane() const = 0;

    /**
     * returns all AcConstraints objects for this constraints group as array
     * @return all constraints as array of shared pointers to AcConstraints for this group
     */
    virtual AcConstraintPtrArray constraints() const = 0;

    /**
     * returns the constraint object as specified by its index (nodeId)
     * @param nodeId - constraint index as Adesk::UInt32
     * @return shared pointer to constraint object (NULL, if not found)
     */
    virtual AcConstraintPtr getConstraintByNodeId(Adesk::UInt32 nodeId) const = 0;

    /**
     * adds a new constraint of specified type with given subentities to this constraints group
     * @param[in] type - constraint type
     * @param[in] arguments - subentities as AcDbFullSubentPathArray
     * @return pointer to created constraint, not NULL if succeeded
     */
    virtual AcConstraintPtr addConstraint(AcConstraint::ConstraintType type,
                                          const AcDbFullSubentPathArray& arguments) = 0;

    /**
     * adds a new constraint of specified type with given constraint arguments
     * @param[in] type - constraint type
     * @param[in] arguments - array of constraint arguments
     * @return pointer to created constraint, not NULL if succeeded
     */
    virtual AcConstraintPtr addConstraint(AcConstraint::ConstraintType type,
                                          const AcConstraintArgumentArray& arguments) = 0;

    /**
     * deletes the specified constraints object from this constraints group
     * @param pConstraint - constraints object
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus deleteConstraint(AcConstraint* pConstraint) = 0;

    /**
     * evaluate all constraints of this constraints group
     * @return Acad::eOk if successful, error status otherwise
     */
    virtual Acad::ErrorStatus evaluate() = 0;

protected:
    AcConstraintsGroup() {};
private:
    AcConstraintsGroup(const AcConstraintsGroup&);
};


//========================= DesignTable related Classes ========================

// Interface class for design table configuration entry for variable
class BRX_IMPORTEXPORT AcDesignTableConfigurationEntry
{
public:
    virtual ~AcDesignTableConfigurationEntry() {};

    // returns the name of this configuration entry
    virtual Acad::ErrorStatus variableName(AcString& name) const = 0;

    // returns the value of this configuration entry as a string
    virtual Acad::ErrorStatus value(AcString& value) const = 0;

    // returns whether this configuration entry represents a double value
    virtual Acad::ErrorStatus isDoubleValue(bool& isDouble) const = 0;

    // returns the value of this configuration entry as double;
    // only valid if the value can be represented as double;
    virtual Acad::ErrorStatus valueAsDouble(double& value) const = 0;
};

// Interface class for design table configuration
class BRX_IMPORTEXPORT AcDesignTableConfiguration
{
public:
    virtual ~AcDesignTableConfiguration() {};

    // returns the name of this design table configuration
    virtual Acad::ErrorStatus name(AcString& configName) const = 0;

    // returns the array of variables described by this configuration
    virtual Acad::ErrorStatus variables(AcDesignTableConfigurationEntryArray& configArray) const = 0;
};

// Interface class for design table
class BRX_IMPORTEXPORT AcDesignTable
{
public:
    virtual ~AcDesignTable() {};

    // returns the owner block Id for this AcDesignTable
    virtual Acad::ErrorStatus getBlockId(AcDbObjectId& blockId) const = 0;

    // returns the key name string of this AcDesignTable
    virtual Acad::ErrorStatus keyName(AcString& keyName) const = 0;

    // returns the name string of this AcDesignTable
    virtual Acad::ErrorStatus name(AcString& name) const = 0;

    // returns all configurations for this AcDesignTable
    virtual Acad::ErrorStatus configurations(AcDesignTableConfigurationArray& allConfigs) const = 0;

    // returns the current configurations for this AcDesignTable, can be a NULL object
    virtual Acad::ErrorStatus currentConfiguration(AcDesignTableConfigurationPtr& curConfig) = 0;

    // returns all design available design tables tables from specified block
    static Acad::ErrorStatus getAllDesignTables(const AcDbObjectId& fromBlockId, AcDesignTableArray& designTables);
};


//=========================== Global access functions ==========================

/**
 * returns the 3D constraints group for specified block table record
 * @param[in] blockId - block table record
 * @param[in] createIfNotExist - if 'true' and the 3D constraints group does not exist, it will be created
 * @return shared pointer to AcConstraintsGroup
 */
BRX_IMPORTEXPORT AcConstraintsGroupPtr acdbGetConstraintsGroup(const AcDbObjectId& blockId,
                                                               bool createIfNotExist = false);

/**
 * returns all constraints groups for specified database
 * @param[in] pDb - database
 * @return array of AcConstraintsGroup shared pointers
 */
BRX_IMPORTEXPORT AcConstraintsGroupPtrArray acdbGetAllConstraintsGroups(AcDbDatabase* pDb);

/**
 * returns the names of all parameters of a parametric block
 * @param[in] blockRefId - AcDbObjectId of the block reference
 * @return AcStringArray of parameter names
 */
BRX_IMPORTEXPORT AcStringArray acdbGetBlockParametersNames(const AcDbObjectId& blockRefId);

/**
 * sets new expression for a block parameter
 * @param[in] blockRefId - AcDbObjectId of the block reference
 * @param[in] name - parameter name
 * @param[in] expr - new expression
 * @return Acad::eOk if successful, error status otherwise
 */
BRX_IMPORTEXPORT Acad::ErrorStatus acdbSetBlockParameterExpression(const AcDbObjectId& blockRefId,
                                                                   const ACHAR* name,
                                                                   const ACHAR* expr);

/**
 * returns the expression string for specified block parameter
 * @param[in] blockRefId - AcDbObjectId of the block reference
 * @param[in] name - parameter name
 * @return expression string (may be empty)
 */
BRX_IMPORTEXPORT AcString acdbGetBlockParameterExpression(const AcDbObjectId& blockRefId,
                                                          const ACHAR* name);

/**
 * returns the expression value for specified block parameter
 * @param[in] blockRefId - AcDbObjectId of the block reference
 * @param[in] name - parameter name
 * @param[out] resValue - expression value
 * @return Acad::eOk if successful, error status otherwise
 */
BRX_IMPORTEXPORT Acad::ErrorStatus acdbGetBlockParameterValue(const AcDbObjectId& blockRefId,
                                                              const ACHAR* name,
                                                              double& resValue);

/**
 * returns the constrained entity's GUI name (as shown in MechanicalBrowser)
 * @param[in] entId - AcDbObjectId of the constrained entity
 * @return string - GUI name of the constrained entity
 */
BRX_IMPORTEXPORT AcString acdbGetEntityGuiName(const AcDbObjectId& entId);

/**
 * assigns a new GUI name to the constrained entity's GUI name (as shown in MechanicalBrowser)
 * @param[in] entId - AcDbObjectId of the constrained entity
 * @param[in] name - the new GUI name for the constrained entity
 * @return Acad::eOk if successful, error status otherwise
 */
BRX_IMPORTEXPORT Acad::ErrorStatus acdbSetEntityGuiName(const AcDbObjectId& entId, const ACHAR* name);

/**
 * verifies whether the block parameter is of 'string' type
 * @param[in] blockRefId - AcDbObjectId of the block reference
 * @param[in] name - parameter name
 * @return true if the block parameter uses a string value, false otherwise
 */
BRX_IMPORTEXPORT bool acdbBlockParameterHasStringValue(const AcDbObjectId& blockRefId, const ACHAR* name);

/**
 * returns the block parameter value as string (empty, if parameter value is not of string type)
 * @param[in] blockRefId - AcDbObjectId of the block reference
 * @param[in] name - parameter name
 * @return current value string (can be empty)
 */
BRX_IMPORTEXPORT AcString acdbGetBlockParameterStringValue(const AcDbObjectId& blockRefId, const ACHAR* name);

/**
 * returns the effective name for the specified BlockReference instance
 * @param[in] blockRefId - AcDbObjectId of the block reference
 * @return AcString - effective name of the BlockReference
 */
BRX_IMPORTEXPORT AcString acdbEffectiveBlockRefName(const AcDbObjectId& blockRefId);

/**
 * returns AcDbObjectId of the effective BlockTableRecord for the specified BlockReference;
 * if the BlockTableRecord is anonymous then the AcDbObjectId of the original BlockTableRecord from
 * which that anonymous BlockTableRecord was derived from (when constraints were changed) is returned
 * @param[in] blockRefId - AcDbObjectId of the block reference
 * @return AcDbObjectId of the effective BlockTableRecord
 */
BRX_IMPORTEXPORT AcDbObjectId acdbEffectiveBlockTableRecord(const AcDbObjectId& blockRefId);

#endif // _AcConstraints3d_h_Included
