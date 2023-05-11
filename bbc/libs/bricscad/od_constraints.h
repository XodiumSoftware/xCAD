///////////////////////////////////////////////////////////////////////////////
//
// Copyright (c) 2015 Menhirs NV
// All rights reserved.
//
// Purpose: declares high-level API to Constraints and Variables
//
///////////////////////////////////////////////////////////////////////////////
#pragma once
#ifndef od_constraints_h__
#define od_constraints_h__

#include "DbDatabase.h"
#include "DbObjectId.h"
#include "DbSubentId.h"
#include "Ge/GePlane.h"
#include "OdArray.h"
#include "OdString.h"
#include "OdaCommon.h"
#include "SharedPtr.h"
#include "StringArray.h"
#include "od_api_exports.h"

namespace OdConstraints {

//////////////////////////////////////////////////////////////////////////

class ConstraintArgument;
class IConstraint;
class IConstraintsGroup;
class IDesignTable;
class IDesignTableConfiguration;
class IDesignTableConfigurationEntry;
class IVariable;

using IConstraintPtr = OdSharedPtr<IConstraint>;
using IConstraintsGroupPtr = OdSharedPtr<IConstraintsGroup>;
using IDesignTablePtr = OdSharedPtr<IDesignTable>;
using IDesignTableConfigurationPtr = OdSharedPtr<IDesignTableConfiguration>;
using IDesignTableConfigurationEntryPtr = OdSharedPtr<IDesignTableConfigurationEntry>;
using IVariablePtr = OdSharedPtr<IVariable>;

using ArgumentArray = OdArray<ConstraintArgument>;
using IConstraintsArray = OdArray<IConstraintPtr>;
using IConstraintsGroupArray = OdArray<IConstraintsGroupPtr>;
using IDesignTableConfigurationArray = OdArray<IDesignTableConfigurationPtr>;
using IDesignTableConfigurationEntryArray = OdArray<IDesignTableConfigurationEntryPtr>;
using IDesignTableArray = OdArray<IDesignTablePtr>;
using IVariableArray = OdArray<IVariablePtr>;

//////////////////////////////////////////////////////////////////////////

/**
 * Interface class for OdDbAssocVariable
 */
class ODAPI IVariable
{
public:

  enum EUnitsType
  {
    eUndefined = 0,
    eLength = 1,
    eArea = 2,
    eVolume = 3
  };

  enum class ExposeMode
  {
    eOff = 0,
    eOn = 1,
    eUndefined = 2
  };

  enum class EGdMode
  {
    eOff = 0,
    eOn = 1,
    eAuto = 2
  };

  /**
   * destructor
   */
  virtual ~IVariable() {}

  /**
   * Get variable from block by it's name
   * @param blockId
   *   OdDbObjectId of block table record
   * @param name
   *   variable name
   * @param createIfDoesNotExist
   *   if true then missed variable will be created
   * @return
   *   pointer to interface of variable
   */
  static IVariablePtr getByName(OdDbObjectId blockId, const OdString& name, bool createIfDoesNotExist = false);

  /**
   * Get all variables from block
   * @param blockId
   *   OdDbObjectId of block table record
   * @return
   *   array of variables
   */
  static IVariableArray getFromBlock(OdDbObjectId blockId);

  /**
   * Get owner block Id for this object
   * @return
   *   OdDbObjectId of block table record
   */
  virtual OdDbObjectId getBlockId() const = 0;

  /**
   * @return
   *   variable name
   */
  virtual OdString name() const = 0;

  /**
   * @return
   *   true if variable is anonymous
   */
  virtual bool isAnonymous() const = 0;

  /**
   * Set variable name
   * @param name
   *   new variable name
   * @return
   *   eOk if succeeded
   */
  virtual OdResult setName(const OdString& name) = 0;

  /**
   * @return
   *   current expression stored at variable
   */
  virtual OdString expression() const = 0;

  /**
   * Set new expression
   * @param expr
   *   expression
   * @return
   *   eOk if succeeded
   */
  virtual OdResult setExpression(const OdString& expr) = 0;

  /**
   * @return
   *   last successful result of expression evaluation as double value
   */
  virtual double valueAsDouble() const = 0;

  /**
  * Set new value
  * @param value
  *   value
  * @return
  *   eOk if succeeded
  */
  virtual OdResult setValue(double value) = 0;

  /**
   * @return
   *   Exposed parameter value
  */
  virtual ExposeMode exposed() const = 0;

  /**
  * Set Exposed parameter value
  * @param mode
  *   new parameter value
  * @return
  *   eOk if succeeded
  */
  virtual OdResult setExposed(ExposeMode mode) = 0;

  /**
   * @return
   *   Geometry-driven parameter value
   */
  virtual EGdMode geometryDrivenMode() const = 0;

  /**
   * Set Geometry-driven parameter value
   * @param mode
   *   new parameter value
   * @return
   *   eOk if succeeded
   */
  virtual OdResult setGeometryDrivenMode(EGdMode mode) = 0;

  /**
  * Get hidden units type parameter value
  * @param units
  *   units type parameter value
  * @return
  *   eOk if succeeded
  */
  virtual OdResult getUnitsType(EUnitsType& units) = 0;

  /**
  * Set hidden units type parameter value
  * @param units
  *   new parameter value
  * @return
  *   eOk if succeeded
  */
  virtual OdResult setUnitsType(EUnitsType units) = 0;

  /**
   * Erase variable
   * @return
   *   eOk if succeeded
   */
  virtual OdResult erase() = 0;
};

//////////////////////////////////////////////////////////////////////////

/**
 * Class representing constraint arguments (entities, sub-entities or elements
 * of coordinate systems)
 */
class ODAPI ConstraintArgument
{
public:
  /**
   * Elements of a coordinate system which can be constrained: origin, axes and planes.
   */
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

  /**
   * Creates empty reference
   */
  ConstraintArgument();

  /**
   * Creates a reference to an entity or sub-entity
   */
  explicit ConstraintArgument(const OdDbFullSubentPath& path);

  /**
   * Creates a reference to the world coordinate system object
   */
  explicit ConstraintArgument(CoordinateSystemObject refCS);

  /**
   * Creates a reference to a coordinate system object of a block reference specified by path
   */
  ConstraintArgument(const OdDbFullSubentPath& path, CoordinateSystemObject refCS);

  /**
   * @return
   *   path of the constrained entity, or of the block reference that contains coordinate system object
   */
  const OdDbFullSubentPath& path() const;

  /**
   * @return
   *   type of the constrained coordinate system object
   */
  CoordinateSystemObject coordinateSystemObject() const;

  /**
   * @return
   *   true in case this constraint argument is a coordinate system object
   */
  bool isCoordinateSystemObject() const;

private:
  OdDbFullSubentPath m_path;
  CoordinateSystemObject m_refCS;
  bool m_isRefCS;
};

//////////////////////////////////////////////////////////////////////////

/**
 * Interface class for constraints
 */
class ODAPI IConstraint
{
public:
  /**
   * Constraint types
   */
  enum Type
  {
    eUnknown         = 0,
    e3DAngle         = 1,
    e3DCoincident    = 2,
    e3DConcentric    = 3,
    e3DDistance      = 4,
    e3DFix           = 5,
    e3DMajorRadius   = 6,
    e3DMinorRadius   = 7,
    e3DParallel      = 8,
    e3DPerpendicular = 9,
    e3DPlanarAngle   = 10,
    e3DRadius        = 11,
    e3DRigidSet      = 12,
    e3DTangent       = 13,
    e3DCircularArray = 14,
    e3DObjectAngle   = 15,
    e3DPath          = 16,
  };

  /**
   * Constraint attribute
   */

  enum Directions
  {
    eDirectionsAny,
    eDirectionsSame,
    eDirectionsOpposite,
    eDirectionsKeep
  };

  /**
   * Constraint argument attributes
   */

  enum MeasurementMode
  {
    eMeasurementModeCenter,
    eMeasurementModeBoundary,
    eMeasurementModeCentralPoint
  };

  enum Placement
  {
    ePlacementAny,
    ePlacementOutside,
    ePlacementInside,
    ePlacementKeep
  };

  /**
   * destructor
   */
  virtual ~IConstraint() {}

  /**
   * Get owner block Id for this object
   * @return
   *   OdDbObjectId of block table record
   */
  virtual OdDbObjectId getBlockId() const = 0;

  /**
   * @return
   *   true if constraint is dimensional
   */
  virtual bool isDimensional() const = 0;

  /**
   * Get parameter of dimensional constraint
   * @return
   *   pointer to interface of variable
   */
  virtual IVariablePtr parameter() const = 0;

  /**
   * Get associated dimension
   * @return
   *   OdDbObjectId of OdDbDimension
   */
  virtual OdDbObjectId getDimension() const = 0;

  /**
   * Get Enabled parameter value
   * @return
   *   true if constraint is enabled
   */
  virtual bool isEnabled() const = 0;

  /**
   * Set Enabled parameter value
   * @param isEnabled
   *   new parameter value
   * @return
   *   eOk if succeeded
   */
  virtual OdResult setEnabled(bool isEnabled) = 0;

  /**
   * Deprecated
   * @return
   *   constraint arguments as OdDbFullSubentPathArray
   */
  virtual OdDbFullSubentPathArray arguments() const = 0;

  /**
   * @return
   *   constraint arguments
   */
  virtual ArgumentArray getArguments() const = 0;

  /**
   * @return
   *   constraint name
   */
  virtual OdString name() const = 0;

  /**
   * Set new constraint name
   * @param name
   *   new name
   * @return
   *   eOk if succeeded
   */
  virtual OdResult setName(const OdString& name) = 0;

  /**
   * @return
   *   constraint type
   */
  virtual Type getType() const = 0;

  /**
  * Get argument's measurement mode
  * @param argIndex
  *   argument index
  */
  virtual OdResult getMeasurementMode(MeasurementMode& result, unsigned int argIndex) const = 0;
  /**
  * Set argument's measurement mode
  * @param argIndex
  *   argument index
  */
  virtual OdResult setMeasurementMode(MeasurementMode value, unsigned int argIndex) = 0;

  /**
  * Get the way constraint arguments' directions are aligned relative to each other
  */
  virtual OdResult getDirections(Directions& result) const = 0;
  /**
  * Set the way constraint arguments' directions are aligned relative to each other
  */
  virtual OdResult setDirections(Directions value) = 0;

  /**
  * Get the way constraint argument is placed relative to another
  * @param argIndex
  *   argument index
  */
  virtual OdResult getPlacement(Placement& result, unsigned int argIndex) const = 0;
  /**
  * Set the way constraint argument is placed relative to another
  * @param argIndex
  *   argument index
  */
  virtual OdResult setPlacement(Placement value, unsigned int argIndex) = 0;

  /**
   * Get constraint index, unique for group of constraints
   * @return
   *   constraint id as OdUInt32
   */
  virtual OdUInt32 nodeId() const = 0;
};

//////////////////////////////////////////////////////////////////////////

/**
 * Interface class for group of constraints
 */
class ODAPI IConstraintsGroup
{
public:
  /**
   * destructor
   */
  virtual ~IConstraintsGroup() {}

  /**
   * Get owner block Id for this object
   * @return
   *   OdDbObjectId of block table record
   */
  virtual OdDbObjectId getBlockId() const = 0;

  /**
   * @return
   *   true if constraints group has sketch plane
   *   reserved for future use, so far returns false
   */
  virtual bool hasSketchPlane() const = 0;

  /**
   * @return
   *   true if constraints are not stored at OdDbDatabase
   *   reserved for future use, so far returns false
   */
  virtual bool isTransient() const = 0;

  /**
   * Get sketch plane for constraints group.
   * Reserved for future use, not implemented yet.
   * @return
   *   OdGePlane for 2D groups, otherwise throw OdError()
   */
  virtual OdGePlane getSketchPlane() const = 0;

  /**
   * @return
   *   constraints as array for this group
   */
  virtual IConstraintsArray constraints() const = 0;

  /**
   * Find constraint by it's nodeId
   * @param nodeId
   *   constraint index as OdUInt32
   * @return
   *   pointer to found constraint
   */
  virtual IConstraintPtr getConstraintByNodeId(OdUInt32 nodeId) const = 0;

  /**
   * Add new constraint of specified type with given arguments
   * @param type
   *   constraint type
   * @param arguments
   *   constraint arguments as OdDbFullSubentPathArray
   * @return
   *   pointer to created constraint, not NULL if succeeded
   */
  virtual IConstraintPtr addConstraint(IConstraint::Type type, const ArgumentArray& arguments) = 0;
  virtual IConstraintPtr addConstraint(IConstraint::Type type, const OdDbFullSubentPathArray& arguments) = 0;

  /**
   * Delete constraint
   * @param pConstraint
   *   constraint pointer
   * @return
   *   eOk if succeeded
   */
  virtual OdResult deleteConstraint(IConstraint* pConstraint) = 0;

  /**
   * Evaluate this constraints group
   * @return
   *   OdResult
   *   eOk if succeeded
   */
  virtual OdResult evaluate() = 0;
};

//////////////////////////////////////////////////////////////////////////

/**
 * Interface class for design table configuration entry for variable
 */
class ODAPI IDesignTableConfigurationEntry
{
public:
  /**
   * destructor
   */
  virtual ~IDesignTableConfigurationEntry() {}

  /**
   * @return
   *   Name of variable referred by configuration
   */
  virtual OdString variableName() const = 0;

  /**
   * @return
   *   String value of variable
   */
  virtual OdString value() const = 0;

  /**
   * @return
   *   True if value can be represented as double
   */
  virtual bool isValueDouble() const = 0;

  /**
   * @return
   *   Valid if value can be represented as double, else 0.0
   */
  virtual double valueAsDouble() const = 0;

};

/**
 * Interface class for design table configuration
 */
class ODAPI IDesignTableConfiguration
{
public:
  /**
   * destructor
   */
  virtual ~IDesignTableConfiguration() {}

  /**
   * @return
   *   Name for given design table configuration
   */
  virtual OdString name() const = 0;

  /**
   * Note that each call returns new pointer, thus don't compare pointers for equality, but compare names as strings
   * @return
   *   Variables described by given configuration
   */
  virtual IDesignTableConfigurationEntryArray variables() const = 0;

};

/**
 * Interface class for design table
 */
class ODAPI IDesignTable
{
public:
  /**
   * destructor
   */
  virtual ~IDesignTable() {}

  /**
   * Get owner block Id for this object
   * @return
   *   OdDbObjectId of block table record
   */
  virtual OdDbObjectId getBlockId() const = 0;

  /**
   * Get variable which selects configuration
   * @return
   *   Name of the variable
   */
  virtual OdString keyVariableName() const = 0;

  /**
   * @return
   *   Name for given design table
   */
  virtual OdString name() const = 0;

  /**
   * Note that each call returns new pointers, thus don't compare pointers for equality, but compare names as strings
   * @return
   *   Configurations for given design table
   */
  virtual IDesignTableConfigurationArray configurations() const = 0;

  /**
   * Get current configuration from design table. Note that each call returns new pointer, thus don't compare pointers for equality,
   * but compare names as strings
   * @return
   *   Current design table configuration or null
   */
  virtual IDesignTableConfigurationPtr currentConfiguration() = 0;

  /**
   * Get all design tables from block. Note that each call returns new pointers, thus don't compare pointers for equality,
   * but compare names as strings
   * @param blockId
   *   OdDbObjectId of block table record
   * @return
   *   array of design tables
   */
  static IDesignTableArray getFromBlock(OdDbObjectId blockId);

};

//////////////////////////////////////////////////////////////////////////

/**
 * Get 3D constraints group at given block
 * @param blockId
 *   OdDbObjectId of block table record
 * @param createIfDoesNotExist
 *   if true then new group will be created
 * @return
 *   pointer to IConstraintsGroup
 */
ODAPI IConstraintsGroupPtr get3DConstraintsGroup(OdDbObjectId blockId, bool createIfDoesNotExist = false);

/**
 * Get all constraints groups at given OdDbDatabase
 * @param pDB
 *   database
 * @return
 *   array of IConstraintsGroup pointers
 */
ODAPI IConstraintsGroupArray getAllConstraintsGroups(OdDbDatabase* pDB);

//////////////////////////////////////////////////////////////////////////

/**
 * Get all parameters from assembly component
 * @param blockRefId
 *   component instance as OdDbObjectId of block reference
 * @return
 *   parameters names as array
 */
ODAPI OdStringArray getComponentParametersNames(OdDbObjectId blockRefId);

/**
 * Set new expression for component parameter
 * @param blockRefId
 *   block reference for component instance
 * @param name
 *   parameter name
 * @param expr
 *   new expression
 * @return
 *   eOk if succeeded
 */
ODAPI OdResult setComponentParameterExpression(OdDbObjectId blockRefId, const OdString& name, const OdString& expr);

/**
 * Get component parameter expression
 * @param blockRefId
 *   block reference for component instance
 * @param name
 *   parameter name
 * @return
 *   current expression, may be empty
 */
ODAPI OdString getComponentParameterExpression(OdDbObjectId blockRefId, const OdString& name);

/**
 * Get component parameter value
 * @param blockRefId
 *   block reference for component instance
 * @param name
 *   parameter name
 * @param units
 *   convert to specified units
 * @return
 *   current value
 */
ODAPI double getComponentParameterValue(OdDbObjectId blockRefId,
                                        const OdString& name,
                                        OdDb::UnitsValue units = OdDb::kUnitsUndefined);

/**
 * Check component parameter value type
 * @param blockRefId
 *   block reference for component instance
 * @param name
 *   parameter name
 * @return
 *   true if component parameter has string value
 */
ODAPI bool componentParameterHasStringValue(OdDbObjectId blockRefId, const OdString& name);

/**
 * Get component parameter string value
 * @param blockRefId
 *   block reference for component instance
 * @param name
 *   parameter name
 * @return
 *   current value
 */
ODAPI OdString getComponentParameterStringValue(OdDbObjectId blockRefId, const OdString& name);

/**
 * Get constrained entity name
 * @param entId
 *   entity
 * @return
 *   entity name
 */
ODAPI OdString getEntityName(OdDbObjectId entId);

/**
 * Set constrained entity name
 * @param entId
 *   entity
 * @param
 *   entity name
 * @return
 *   eOk if succeeded
 */
ODAPI OdResult setEntityName(OdDbObjectId entId, const OdString& name);

//////////////////////////////////////////////////////////////////////////

} // namespace OdConstraints

#endif // od_constraints_h__
