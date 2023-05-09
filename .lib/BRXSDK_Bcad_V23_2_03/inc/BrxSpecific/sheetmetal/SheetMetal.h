// Copyright (C) Menhirs NV. All rights reserved.

// SheetMetal.h
// BRX API for BricsCAD SheetMetal functionality + interfaces

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#include <memory>  // std::shared_ptr
                 
#include "Misc/MiscGlobal.h"
#include "Misc/AcString.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcGe/AcGeLine3d.h"
#include "AcGe/AcGePoint3d.h"


// functions to initialise + uninitialise the SheetMetal core;
// both functions can be called multiple times, by multiple client modules
Acad::ErrorStatus acdbInitSheetMetal();
Acad::ErrorStatus acdbUninitSheetMetal();


// ! underlying core data - for internal use only !
#ifndef BRX_API // proxy class
namespace OdFeatures
{
    class ISheetMetalContextPtr {};
    class IFeaturePtr {};
    class IUpdateFeatureScope {};
};
namespace OdSheetMetal
{
    class ISmartFeatureReconstructionScope {};
    class IUnfoldedBendLine {};
    class IUnfoldedBevelEdge {};
    class IUnfoldedFormFeatureWires {};
}
#endif

// class enum
enum ESmObjectType
{
    eTypeFeature = 0,  // base class
    eTypeSmContext,
    eTypeSmBendFeature,
    eTypeSmBendReliefFeature,
    eTypeSmCornerReliefFeature,
    eTypeSmFlangeFeature,
    eTypeSmFormFeature,
    eTypeSmJunctionFeature,
    eTypeSmLoftedBendFeature,
    eTypeSmMiterFeature,
    eTypeSmRibFeature,
    eTypeSmWrongBendFeature,
    eTypeSmWrongFlangeFeature,
    eTypeSmHemFeature,
    eTypeSmTabFeature,
    eTypeSmZeroBendFeature,
    eTypeSmBevelFeature,
    eTypeSmTTabFeature,
    eTypeSmTJunctionFeature,
    //
    eTypeSmUnfoldedFeature,
    eTypeSmUnfoldedBendFeature,
    eTypeSmUnfoldedFlangeFeature,
    eTypeSmUnfoldedHemFeature,
    eTypeSmUnfoldedLoftedBendFeature,
    eTypeSmUnfoldedJunctionFeature,
    eTypeSmUnfoldedMiterFeature,
    eTypeSmUnfoldedTabFeature,
    eTypeSmUnfoldedBendReliefFeature,
    eTypeSmUnfoldedCornerReliefFeature,
    eTypeSmUnfoldedFormFeature,
    eTypeSmUnfoldedRibFeature,
    eTypeSmUnfoldedBevelFeature,
};

// specifies how a measured parameter is represented
// eRelative - value is relative to the thickness
// eAbsolute - value is absolute
// eGlobal   - value is taken from SheetMetal context
enum class EValueType
{
  eRelative = 0,
  eAbsolute = 1,
  eGlobal   = 2
};

// Determines how measured parameter is represented
// eRelative : value is set for given feature only and is relative to the thickness
// eAbsolute : value is set for given feature only and is absolute
// eGlobal   : value is taken from Sheet Metal context value for this type of feature
enum ESmValueType
{
    eRelative = 0,
    eAbsolute,
    eGlobal
};


// Feature Update Scope

// The purpose of this class is to implement update of the model with SheetMetal features.
// Update is needed since, for example, solely changing any of sheet metal context option does
// not change geometry of the model. Instead of direct usage of this class it is better 
// to use macros defined below : BRX_FEATURE_MODIFICATION_START and BRX_FEATURE_MODIFICATION_END
// 
// Here is a small example analogous to changing absolute bend radius value from browser:
//   BRX_FEATURE_MODIFICATION_START(pDb, true); //pDb is a pointer to AcDbDatabase
//     BrxSmSheetMetalContext ctxt = BrxSmSheetMetalContext::getInstance(pDb->getModelSpaceId(), true);
//     ctxt.setBendRadiusAbsoluteValue(10.0);
//   BRX_FEATURE_MODIFICATION_END;
// 
class BRX_IMPORTEXPORT BrxIUpdateFeatureScope
{
protected:
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdFeatures::IUpdateFeatureScope>  m_scope = nullptr;

public:
    BrxIUpdateFeatureScope(AcDbDatabase* pDb, bool updateConstaints);
    BrxIUpdateFeatureScope(const BrxIUpdateFeatureScope& other);
    virtual BrxIUpdateFeatureScope& operator= (const BrxIUpdateFeatureScope& other);
    virtual ~BrxIUpdateFeatureScope();
};

#define BRX_FEATURE_MODIFICATION_START(DATABASE, UPDATE_CONSTRAINTS)  \
{                                                                     \
  BrxIUpdateFeatureScope brxUpdateScope(DATABASE, UPDATE_CONSTRAINTS)

#define BRX_FEATURE_MODIFICATION_END   \
}

// Feature Reconstruction Scope

// The purpose of this class is to implement 'smart feature' behavior when calling any SheetMetal
// operation. That is, using this class together with any existing SheetMetal operation allows you
// to receive the same result as calling analogous command with enabled smart feature setting.
// Instead of direct usage of this class it is better to use macros defined below :
//     BRX_FEATURE_RECONSTRUCTION_START and BRX_FEATURE_RECONSTRUCTION_END
//
// Here is a small example analogous to calling SmJunctionCreate with automatic features reconstruction:
//     BRX_FEATURE_RECONSTRUCTION_START(pSourceDb, true);
//       BrxSmJunctionCreator junctionCreator; 
//       // ... set operation properties and full subentity paths
//       BrxErrorList failures;
//       Acad::ErrorStatus  es = junctionCreator.run(aFailures); // after run smart feature reconstruction will be applied
//     BRX_FEATURE_RECONSTRUCTION_END;
// 
class BRX_IMPORTEXPORT BrxIFeatureReconstructionScope
{
protected:
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::ISmartFeatureReconstructionScope>  m_scope = nullptr;

public:
    BrxIFeatureReconstructionScope(AcDbDatabase* pDb, bool enableReconstruction);
    BrxIFeatureReconstructionScope(const BrxIFeatureReconstructionScope& other);
    virtual BrxIFeatureReconstructionScope& operator= (const BrxIFeatureReconstructionScope& other);
    virtual ~BrxIFeatureReconstructionScope();
};

#define BRX_FEATURE_RECONSTRUCTION_START(DATABASE, ENABLE_FEATURE_RECONSTRUCTION) \
{                                                                                 \
  BrxIFeatureReconstructionScope brxReconstructionScope(DATABASE, ENABLE_FEATURE_RECONSTRUCTION)

#define BRX_FEATURE_RECONSTRUCTION_END  \
}

// base class for all MCAD/SheetMetal objects

class BRX_IMPORTEXPORT BrxIFeature
{
protected:
    // ! underlying core data - for internal use only !
    OdFeatures::IFeaturePtr  m_feature;

public:
    BrxIFeature();
    BrxIFeature(const BrxIFeature& other);
    virtual BrxIFeature& operator= (const BrxIFeature& other);
    virtual ~BrxIFeature();

    // ! underlying core data - for internal use only !
    const OdFeatures::IFeaturePtr& getFeature() const { return m_feature; };

    // Constructs a BrxIFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal Feature
    // (the object effectively holds an instance *derived* from BrxIFeature, verify with objectType())
    BrxIFeature(const AcDbObjectId& id);

    // Sets this BrxIFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal Feature, the instance is empty.
    // (the object effectively holds an instance *derived* from BrxIFeature, verify with objectType())
    virtual BrxIFeature& operator= (const AcDbObjectId& id);

    // returns the object type for 'this' BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    // verifies whether this BrxIFeature (or derived) instance is valid (or empty or of wrong type otherwise)
    virtual bool isNull() const;
    // sets this BrxIFeature instance (or derived) to be empty
    virtual void setNull();

    // returns the feature name
    virtual const ACHAR* name() const;

    // assigns the feature name
    // returns Acad::eOk, or error status
    virtual Acad::ErrorStatus setName(const ACHAR* name);

    // feature may contain several groups of sub-entities, each one identified by a unique mask;
    // returns all masks valid for given feature
    virtual AcDbIntArray masks() const;

    // returns entities related to this feature
    // 'mask' allows to retrieve specific group of faces. Provide -1 to get all entities
    virtual AcDbFullSubentPathArray getFeatureEntities(int mask = -1) const;

    // returns AcDbObjectId of the feature, if the feature is database-resident, or kNull
    virtual AcDbObjectId objectId() const;

    // Retrieves all features from given BlockTableRecord (usually MS BlockTableRecord) or AcDb3dSolid;
    // id can be AcDbObjectId of BlockTableRecord or AcDb3dSolid;
    // returns all the features for given object
    static AcDbObjectIdArray getAllFeatures(const AcDbObjectId& id);

    // Retrieves all features from given Full Subentity path;
    static AcDbObjectIdArray getAllFeatures(const AcDbFullSubentPath& fsp);
};

// SheetMetal Bend Feature

class BRX_IMPORTEXPORT BrxSmBendFeature : public BrxIFeature
{
public:
    // Distinguishes sides of the bend feature
    // Internal faces have radius equal to radius of bend feature
    // External faces have radius greater by thickness of Sheet Metal part
    enum EBendFaceType
    {
        eInternalFaces = 0x1,
        eExternalFaces = 0x2,
    };

    // VDieWidth used as a secondary key in bend table, primary is the thickness
    //   eAbsoluteDieWidth - value is overridden for given bend and may differ from global
    //   eGlobalDieWidth - value is derived from Sheet Metal Context
    enum EBendVDieWidthType
    {
        eAbsoluteDieWidth = 0,
        eGlobalDieWidth   = 1,
    };

    BrxSmBendFeature();
    BrxSmBendFeature(const BrxIFeature& other);
    virtual BrxSmBendFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmBendFeature();

    // Constructs a BrxSmBendFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal Bend Feature
    BrxSmBendFeature(const AcDbObjectId& id);

    // Sets this BrxSmBendFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal Bend Feature, the instance is empty.
    virtual BrxSmBendFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmBendFeature instance, if the queried
    // BrxIFeature object contains a BrxSmBendFeature instance, or an empty instance otherwise
    static BrxSmBendFeature cast(const BrxIFeature& other);

    // returns the object type for 'this' BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the faces (of specified bend face type) of this Bend Feature
    virtual AcDbFullSubentPathArray getFaces(EBendFaceType faceType) const;

    // get the actual radius type for this BrxSmBendFeature instance
    virtual ESmValueType radiusType() const;

    // get + set the actual radius type for the "absolute" mode
    virtual double getRadiusAbsoluteValue() const;
    virtual Acad::ErrorStatus setRadiusAbsoluteValue(double value);

    // get + set the actual radius type for the "relative" (ratio to thickness) mode
    virtual double getRadiusRatio() const;
    virtual Acad::ErrorStatus setRadiusRatio(double value);

    // set the actual radius type for this object to the "global" setting
    // (see BrxSmSheetMetalContext object);
    // also returns whether the radius value/mode was changed
    virtual Acad::ErrorStatus useGlobalRadius(bool& wasChanged);

    // get the actual VDie width type (absolute or global)
    virtual EBendVDieWidthType vDieWidthType() const;

    // get + set the VDie width for this BrxSmBendFeature object
    virtual double vDieWidth() const;
    virtual Acad::ErrorStatus setVDieWidth(double value);

    // set the actual VDie width for this object to use the "global" setting
    // (see BrxSmSheetMetalContext object);
    // also returns whether the VDie width was changed
    virtual Acad::ErrorStatus useGlobalVDieWidth(bool& wasChanged);

    // computes the internal bend angle.;
    // the limit of rotation is that it correctly defines angles only for regular bends.
    // for teardrop will return -Pi/2 while swept angle is 3*Pi/2;
    // -Pi/2 will mean to bend only by Pi/2 degrees down the adjacent flange;
    // returns internal bend angle in radians, in range (-Pi, Pi)
    virtual double getInternalAngle() const;

    // computes the swept bend angle;
    // returns the swept bend angle in radians, in range (-2*Pi, 2*Pi)
    virtual double getSweptAngle() const;
};

// SheetMetal Flange Feature

class BRX_IMPORTEXPORT BrxSmFlangeFeature : public BrxIFeature
{
public:
    enum EFlangeFaceType
    {
        eTopFaces    = 0x1,
        eBottomFaces = 0x2,
    };

    BrxSmFlangeFeature();
    BrxSmFlangeFeature(const BrxIFeature& other);
    virtual BrxSmFlangeFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmFlangeFeature();

    // Constructs a BrxSmBendFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal Bend Feature
    BrxSmFlangeFeature(const AcDbObjectId& id);

    // Sets this BrxSmFlangeFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal Flange Feature, the instance is empty.
    virtual BrxSmFlangeFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmFlangeFeature instance, if the queried
    // BrxIFeature object contains a BrxSmFlangeFeature instance, or an empty instance otherwise
    static BrxSmFlangeFeature cast(const BrxIFeature& other);

    // returns the object type for 'this' BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the faces (of specified flange face type) of this Flange Feature
    virtual AcDbFullSubentPathArray getFaces(EFlangeFaceType faceType) const;
};

// SheetMetal Junction Feature

class BRX_IMPORTEXPORT BrxSmJunctionFeature : public BrxIFeature
{
public:
    // Junction feature consists of faces on two sides.
    // These sides are same in meaning (opposite to flange, where top and bottom operate differently)
    enum EJunctionFaceType
    {
        eFirstPartFaces  = 0x1,
        eSecondPartFaces = 0x2,
    };

    // Here first and second mean flanges adjacent to junction feature
    // 
    // Symmetrical
    //                   Flange_1
    //                 +-------------------
    //            J    |
    //                 +-------------------
    //            +--+
    //            |  |
    //  Flange_2  |  |
    //            |  |
    //            |  |
    // 
    // Aligned to first flange
    // 
    //              J     Flange_1
    //            +--+  +-------------------
    //            |  |  |
    //            |  |  +-------------------
    //            |  |
    //            |  |
    //  Flange_2  |  |
    //            |  |
    //            |  |
    //
    enum EJunctionConnectionType
    {
        eSymmetrical = 0,
        eAlignedToFirst,
        eAlignedToSecond,
        eAny,
    };

    // Alignment of Junction to Relief type. It affects the behavior of junctions when they are
    // adjacent to bend or corner relief(s).
    //   eGlobalType - the behavior will be as set in SheetMetal Context
    //   eDisabled   - the junction will maintain the specified gap
    //   eEnabled    - the junction sides will be moved to be directly adjacent
    //                 to bend side faces of the adjacent reliefs. If the junction is adjacent
    //                 to more than one relief, then its side faces will be moved to the closest
    //                 bend side face. This mode effectively eliminates the notch faces in
    //                 corner reliefs adjacent to junctions, which can be useful for certain cases.
    enum EJunctionAlignmentToReliefType
    {
        eGlobalType = 0,
        eDisabled,
        eEnabled,
    };

    BrxSmJunctionFeature();
    BrxSmJunctionFeature(const BrxIFeature& other);
    virtual BrxSmJunctionFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmJunctionFeature();

    // Constructs a BrxSmJunctionFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal Junction Feature
    BrxSmJunctionFeature(const AcDbObjectId& id);

    // Sets this BrxSmJunctionFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal Junction Feature, the instance is empty.
    virtual BrxSmJunctionFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmFlangeFeature instance, if the queried
    // BrxIFeature object contains a BrxSmFlangeFeature instance, or an empty instance otherwise
    static BrxSmJunctionFeature cast(const BrxIFeature& other);

    // returns the object type for 'this' BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the faces (of specified flange face type) of this Flange Feature
    virtual AcDbFullSubentPathArray getFaces(EJunctionFaceType faceType) const;

    // get the junction alignment type (symmetrical, alignedToFirst, alignedToSecond)
    virtual EJunctionConnectionType connectionType() const;

    // get the junction gap type (global (from sheetmetal context), relative (to thickness), absolute)
    virtual ESmValueType junctionGapType() const;

    // set the junction gap type to "global" (from sheetmetal context)
    virtual Acad::ErrorStatus useGlobalGap(bool& wasChanged);

    // get + set the "absolute" junction gap value
    virtual double junctionGapAbsoluteValue() const;
    virtual Acad::ErrorStatus setJunctionGapAbsoluteValue(double value);

    // get + set the "relative to thickness" junction gap value (ratio) 
    virtual double junctionGapRatio() const;
    virtual Acad::ErrorStatus setJunctionGapRatio(double value);

    // get + set the junction "alignment to relief" type
    virtual EJunctionAlignmentToReliefType junctionAlignmentToReliefType() const;
    virtual Acad::ErrorStatus setJunctionAlignmentToReliefType(EJunctionAlignmentToReliefType type);
};

// SheetMetal Bend Relief Feature

class BRX_IMPORTEXPORT BrxSmBendReliefFeature : public BrxIFeature
{
public:
    // Bend relief is used to resolve material conflict between a flange and a bend.
    // Bend relief may contain up to four different groups of faces, denoted by their role
    // and adjacency. A group of faces is adjacent to an entity if at least one face of this
    // group is adjacent to this entity.
    //    eFlangeSideFaces   - group of faces that is directly adjacent to the bend or the hard edge
    //                       that will be used to construct a bend. This group must be always
    //                       present.
    //    eExternalFaces     - group of faces parallel to the flange side faces. Should be present
    //                       in bend reliefs of eRound and eRip types. May be absent in other
    //                       types of bend reliefs.
    //    eNotchModelFaces   - group of faces perpendicular to flange side faces or that are cylindrical
    //                       in case of eRound type. Its purpose is to separate the (future) bend from
    //                       the flange. This group of faces must be present in any type of bend relief
    //                       except eSmooth
    //    eNotchProfileFaces - group of faces perpendicular to the flange side faces but not coplanar.
    //                       to eNotchModelFaces group. May be absent. The reason to introduce
    //                       this group of faces is that sometimes, bend relief may have both groups of
    //                       notch faces, and this information may be useful for sheet metal operations.
    //
    // Note that the main difference between NotchModel and NotchProfile faces is that eNotchModelFaces
    // corresponds to the main group of notch faces, and eNotchProfileFaces corresponds to the secondary
    // group of notch faces. They are named Model and Profile mainly for internal reasons.
    //
    // The following figure shows each group of faces in the unfolded representation of the bend relief.
    //
    //    Second flange                    /
    //                 eNotchProfileFaces /
    //                              __|__/
    //          Relief extension-->|
    // ----------------------------|
    //    eFlangeSideFaces-------> |
    //                             |
    //            Bend             |   BR    ___________________________
    //                             | width  |
    // ----------------------------|<------>|<---eExternalFaces
    //                             |________|
    //                                  |
    //          First flange    eNotchModelFaces
    //
    enum EBendReliefFaceType
    {
        eFlangeSideFaces   = 0x1,
        eExternalFaces     = 0x2,
        eNotchModelFaces   = 0x4,
        eNotchProfileFaces = 0x8
    };

    // Bend relief type defines its shape in the unfolded representation. Following types are supported:
    //    eRectangular - the default type of the relief. All faces of this type of relief will be planar,
    //                   with the flange side faces being orhogonal to bend axis, and other faces being
    //                   orthogonal or parallel to flange side face. In the unfolded representation, it will
    //                   look as follows:
    //                           \
    //                        ____|
    //                    bend____|   __
    //                            |__|  \
    //    
    //    eRound       - similar to eRectangular, but with the eModelNotchFace group being cylindrical.
    //                   In the unfolded representation, it will look as follows:
    //                           \
    //                        ____|
    //                    bend____|   __
    //                            |   |  \
    //                             \_/     (this is a rough representation of the round shape)
    //    
    //    eSmooth      - corresponds to the relief that looks as a straight line in the unfolded representation:
    //                           |
    //                        ____\
    //                    bend_____\
    //                              |
    //    
    //    eRip         - correspond to the relief that has virtually zero width (the distance between flange side
    //                   and external faces.) Due to limitations of the geometric kernel, it actually has very small
    //                   width, but it is indistinguishable from the real zero width for any practical means.
    //                   In the unfolded representation, it will look as follows:
    //                           \
    //                        ____|
    //                    bend____| __
    //                            ||  \
    //    
    //    eUnknown     - a special type to denote bend reliefs of unknown (not supported or not assigned yet) type.
    //
    enum EBendReliefType
    {
        eRectangular = 0,
        eRound,
        eSmooth,
        eRip,
        eUnknown,
    };

    BrxSmBendReliefFeature();
    BrxSmBendReliefFeature(const BrxIFeature& other);
    virtual BrxSmBendReliefFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmBendReliefFeature();

    // Constructs a BrxSmBendReliefFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal BendRelief Feature
    BrxSmBendReliefFeature(const AcDbObjectId& id);

    // Sets this BrxSmBendReliefFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal BendRelief Feature, the instance is empty.
    virtual BrxSmBendReliefFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmBendReliefFeature instance, if the queried
    // BrxIFeature object contains a BrxSmBendReliefFeature instance, or an empty instance otherwise
    static BrxSmBendReliefFeature cast(const BrxIFeature& other);

    // returns the object type for 'this' BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the faces (of specified face type) of this Bend Relief Feature
    virtual AcDbFullSubentPathArray getFaces(EBendReliefFaceType faceType) const;

    // Bend relief width is defined as the distance between flange side and external faces. If the
    // bend relief does not have external faces, it is not possible to determine or assign the width
    // to it. When a new bend relief is created, the width value hints what should be the width of the
    // new bend relief. However, this value may be ignored if the local configuration of geometry
    // requires for bigger or smaller value.

    // get the width type of this BendRelief Feature
    virtual ESmValueType widthType() const;

    // get + set the relief type of this BendRelief Feature
    virtual EBendReliefType reliefType() const;
    virtual Acad::ErrorStatus setReliefType(EBendReliefType type);

    // Retrieves the absolute non-negative value of the required bend relief width, regardless of
    // its current type. Please note that the returned value is not the actual width
    // but the required width for this bend relief feature.
    virtual double getWidthAbsoluteValue() const;

    // Sets the new required bend relief width and changes its type to eAbsolute.
    // After calling of this function, the bend relief width will become independent
    // from the sheet metal context.
    virtual Acad::ErrorStatus setWidthAbsoluteValue(double value);

    // Retrieves the non-negative ratio of the required bend relief width to the thickness,
    // regardless of its current type. Please note that the returned value is not the actual width
    // but the required width for this bend relief feature.
    virtual double getWidthRatio() const;

    // Sets the new bend relief width as non-negative ratio to the thickness. Also changes the bend relief
    // width type to eRelative. After calling this function, the bend relief width will become independent
    // from the sheet metal context.
    virtual Acad::ErrorStatus setWidthRatio(double value);

    // Takes the new bend relief width from the sheet metal context and sets its type to eGlobal.
    // After calling this function, the bend relief width will become linked to the sheet metal
    // context and will always match it.
    virtual Acad::ErrorStatus useGlobalWidth(bool& wasChanged);

    // returns the extension/thickness ratio;
    // 'extension' is the distance between notch face and bend line to thickness
    virtual Acad::ErrorStatus getExtensionRatio(double& ratio) const;
};

// SheetMetal Corner Relief Feature

class BRX_IMPORTEXPORT BrxSmCornerReliefFeature : public BrxIFeature
{
public:
    // Corner reliefs are used to remove material conflicts between bends and flanges in case when
    // more than two flanges meet at the same corner. Due to this, corner relief feature may consist
    // of an arbitrary number of faces. In general, a corner relief consists of several so-called link
    // components (groups of faces linked to a pair of adjacent flanges in the relief) and auxiliary faces
    // that links the link components together if necessary.
    // For historical reasons, Bricscad treats differently simplest reliefs formed when there are 3 flanges
    // and 2 bends with Pi/2 degrees bend angles. Those reliefs consist of up to 4 group of faces and have
    // eRectangularOld type. Reliefs of eRectangularOld type should be treated differently, as its
    // internal format and face types are different from other types of reliefs.
    // 
    // Following 4 face types should be used only with eRectangularOld type of reliefs:
    //    eBendFaces1  - planar faces adjacent to the first bend. Must be present.
    //    eNotchFaces1 - planar faces adjacent to any face in eBendFaces1 group and orthogonal to eBendFaces1
    //                   faces. May be absent.
    //    eBendFaces2  - planar faces adjacent to the second bend. Must be present.
    //    eNotchFaces2 - planar faces adjacent to any face in eBendFaces2 group and orthogonal to eBendFaces2
    //                   faces. May be absent.
    // 
    // Following 4 face types correspond to the face groups inside link components or auxiliary faces.
    // Those types cannot be used for eRectangularOld types of reliefs.
    // Because there can be many link components, to retrieve all faces of the given type may be not
    // sufficient, as they have to be grouped by link components as well.
    //    eLinkFaces     - group of faces adjacent to the bends or hard edges between pairs of flanges.
    //                     In certain cases, may correspond to junctions between pairs of flanges, if
    //                     the relief has been created before junctions. Must be present in any corner relief
    //                     except eRectangularOld
    //    eNotchFaces    - group of faces directly adjacent to eLinkFaces group. May be absent.
    //    eAuxFaces      - group of faces that link two link components. May be absent.
    //    eExternalFaces - group of faces that parallel to the link faces. May be absent.
    // 
    // All possible types of faces for eRectangularOld type of reliefs are shown in the unfolded representation
    // sketch below:
    // 
    //              eNotchFaces1    /
    //     Flange 2           |    /
    //                      __|___/
    // --------------------|
    //     eBendFaces1---->|
    //   Bend 1            |             _______
    //                     |eBendFaces2 |       \
    // --------------------|_____|______|<-eNotchFaces2
    //                       |         |          \
    //                       |         |           \
    //     Flange 1          | Bend 2  | Flange 3   \
    //                       |         |             \
    // 
    // The all possible types of faces for other types of reliefs is shown in the unfolded representation
    // sketch below:
    // 
    //         eNotchFace (Link component 1)|
    //     Flange 1            |            |        _______________
    //                       __|____        |       /
    // ---------------------|       | <-eExternalFace (Link component 1)
    // eLinkFace ---------->|       |_______|     /      Flange 4
    // (Link component 1)   |                    /
    // Bend 1               |                   /
    // ---------------------|                  |-------------------
    //                       \                 |              Bend 3
    //       eAuxFace-------->\                |<-eLinkFace (Link component 3)
    //                         \_______________|-------------------
    //                            |     |    |
    //  Flange 2           eLinkFace (Link component 2)
    //                            | Bend 2   |             Flange 3
    // 
    // The figure above corresponds to the corner relief with 3 link components and 1 auxiliary face.
    // The first link component has 1 link face, 1 notch face and 1 external face.
    // The second and the third link components have 1 link face each.
    // 
    enum ECornerReliefFaceType
    {
        eBendFaces1    = 0x01,
        eNotchFaces1   = 0x02,
        eBendFaces2    = 0x04,
        eNotchFaces2   = 0x08,
        eLinkFaces     = 0x10,
        eNotchFaces    = 0x20,
        eAuxFaces      = 0x40,
        eExternalFaces = 0x80,
    };

    // Corner relief type defines the shape of this corner relief in the unfolded representation.
    // For historical reasons, rectangular reliefs are divided into two types, depending on the
    // configuration of the corner.
    // 
    // Following types are supported:
    //    eRectangularOld     - corresponds to corner reliefs when there are 3 flanges and 2 bends,
    //                          both bend angles are equal to Pi/2 degrees, and all relief faces are
    //                          planar. Bend side faces must be perpendicular to the corresponding bend
    //                          axis. Notch faces must be perpendicular to corresponding bend side
    //                          faces. Those reliefs will loosely form a rectangular shape in the
    //                          unfolded representation.
    //                          Those reliefs will automatically adjust to the changes in geometry.
    //    
    //    eGenericRectangular - corner reliefs with all planar faces that do not meet the criteria
    //                          for eRectangularOld. The main criterion is that all link faces
    //                          are perpendicular to corresponding bend axis or hard edges.
    //                          They may form various shapes in the unfolded representation, but
    //                          all those shapes will consist of straight lines only.
    //                          Due to an arbitrary shape, those reliefs will not automatically
    //                          adjust to the changes in the model.
    //    
    //    eVType              - corner reliefs, each link component of which forms a single
    //                          straight line in the unfolded representation. Thus, the relief
    //                          forms sort of V-shaped geometry in the unfolded representation.
    //    
    //    eCircular           - corner reliefs that form a round shape in the unfolded representation.
    //                          The diameter of this shape may be computed automatically or be
    //                          set explicitly. However, the relief diameter must be greater or equal
    //                          than the minimal possible diameter. Currently, only corner reliefs
    //                          adjacent to exactly 3 flanges and 2 bends can be switched to circular type.
    //    eUndefined          - corresponds to corner reliefs of not supported or not assigned yet type.
    // 
    enum ECornerReliefType
    {
        eRectangularOld = 0, // corner-relief on two adjacent edges of the flange (maybe, plus parallel modifications)
        eGenericRectangular,
        eVType,
        eCircular,
        eUndefined,
    };

    // Defines how the circular relief shape will be constructed.
    // 
    // To determine the radius, 3 points in the unfolded representation are taken into account:
    //  - external point of the first notch face. If there is no notch face, then it is replaced by the intersection
    //    of the bend edge with the flange border.
    //  - external point of the second notch face. If there is no notch face, then it is replaced by the intersection
    //    of the bend edge with the flange border.
    //  - the point when two link components (or BendFaces1 and BendFaces2) intersects.
    // 
    // ReferencePointType defines how the radius and the center point will be computed from those 3 points.
    //    eMiddle  - the center is on the intersection of bend axial lines. Radius is computed as the largest distance to
    //               those 3 points.
    //    eCorner  - the circle going through all 3 points is constructed, and its radius and center are taken.
    //               Note that geometrically, it is not always possible to construct such circle (for example, if all 3 points
    //               are on the same line)
    //    eDefault - the mode will be taken from sheet metal context.
    // 
    //                              /
    //     Flange 2          Point1/
    //                      __ __\/
    // --------------------|
    // Bend 1 axial line   | Center  Point2
    // --------------------|------.     \_______
    //        Bend 1       |      |     |       \
    // --------------------|______|_____|        \
    //                    /  |    |    |          \
    //                Point 3|    |    |           \
    //     Flange 1          | Bend 2  | Flange 3   \
    //                       |    |    |             \
    // 
    enum EReferencePointType
    {
        eMiddle = 0,
        eCorner,
        eDefault,
    };

    // For eCircular corner reliefs, it is possible to set a specific diameter.
    // The diameter may be set independently for certain corner reliefs or
    // linked to the global value in sheet metal context. If the user sets
    // a specific diameter (as global or per feature value), it will be used
    // when switching the relief to the circular type. Otherwise, the
    // minimal possible diameter will be calculated and used with respect
    // to the current reference point type.
    //    eDiameterGlobal   - relief diameter is derived from Sheet Metal Context
    //    eDiameterAbsolute - relief diameter is set as absolute value
    //    eDiameterMinimal  - relief diameter will be calculated as the minimal
    //                        value with respect to the current reference point type
    // see EReferencePointType
    // 
    enum ECornerReliefDiameterType
    {
        eDiameterGlobal,
        eDiameterAbsolute,
        eDiameterMinimal,
    };

    BrxSmCornerReliefFeature();
    BrxSmCornerReliefFeature(const BrxIFeature& other);
    virtual BrxSmCornerReliefFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmCornerReliefFeature();

    // Constructs a BrxSmCornerReliefFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal CornerRelief Feature
    BrxSmCornerReliefFeature(const AcDbObjectId& id);

    // Sets this BrxSmCornerReliefFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal CornerRelief Feature, the instance is empty.
    virtual BrxSmCornerReliefFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmCornerReliefFeature instance, if the queried
    // BrxIFeature object contains a BrxSmCornerReliefFeature instance, or an empty instance otherwise
    static BrxSmCornerReliefFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the faces (of specified face type) of this Corner Relief Feature
    virtual AcDbFullSubentPathArray getFaces(ECornerReliefFaceType faceType) const;

    // get + set the corner relief type of this Corner Relief Feature
    virtual ECornerReliefType reliefType() const;
    virtual Acad::ErrorStatus setReliefType(ECornerReliefType type);

    // get the relief diameter type
    virtual ECornerReliefDiameterType diameterType() const;

    // get + set the relief diameter for "absolute" type
    virtual double getDiameterAbsoluteValue() const;
    virtual Acad::ErrorStatus setDiameterAbsoluteValue(double value);

    // assigns the relief diameter from the sheet metal context and sets its type to eDiameterGlobal.
    virtual Acad::ErrorStatus useGlobalDiameter(bool& wasChanged);

    // get + set the reference point type;
    // note that reliefs other than eCircular also may have the reference point type set.
    // It will be used when switching to eCircular corner relief type
    virtual EReferencePointType referencePointType() const;
    virtual Acad::ErrorStatus setReferencePointType(EReferencePointType refPointType);

    // Corner relief extension is a minimal required distance between the bend edge and the closest edge
    // between corner relief faces of different type.
    // 
    //                             /
    //     Flange 2               /
    //                      _____/
    //   Relief extension->|
    // --------------------|
    //                     |
    //   Bend 1            |              _______
    //                     |eBendFaces2  |       \
    // --------------------|             |        \
    //    ReliefExtension->|_____|_______|         \
    //                       |         |\           \
    //                       |         | Relief extension
    //     Flange 1          | Bend 2  | Flange 3     \
    //                       |         |               \
    // 
    // This distance may be set independently for certain corner reliefs as well as linked to
    // the global value in sheet metal context.
    //    eExtGlobal   - relief extension is derived from Sheet Metal Context
    //    eExtRelative - relief extension is relative to thickness
    //    eExtAbsolute - relief extension is absolute
    // 
    // Note that the global relief extension value controls both corner and bend reliefs.
    // 

    // get the current extension type
    virtual ESmValueType extensionType() const;

    // get + set the ratio of the relief extension to the thickness, regardless of the extension type
    // ("relative" or "ratio" mode)
    virtual double getExtensionRatio() const;
    virtual Acad::ErrorStatus setExtensionRatio(double value);

    // get + set the absolute value of the relief extension to the thickness, regardless of the extension type
    // ("absolute" or "ratio" mode)
    virtual double getExtensionAbsoluteValue() const;
    virtual Acad::ErrorStatus setExtensionAbsoluteValue(double value);

    // assigns the relief extension type from the sheet metal context and sets its type to eExtGlobal.
    virtual Acad::ErrorStatus useGlobalExtension(bool& wasChanged);
};

// SheetMetal Lofted Bend Feature

class BRX_IMPORTEXPORT BrxSmLoftedBendFeature : public BrxIFeature
{
public:
    enum ELoftedBendFaceType
    {
        eTopFaces    = 0x1,
        eBottomFaces = 0x2,
    };

    enum EUnfoldingMode
    {
        eTriangulation   = 0,
        eQuadrangulation = 1,
        eAnalytical      = 2
    };

    BrxSmLoftedBendFeature();
    BrxSmLoftedBendFeature(const BrxIFeature& other);
    virtual BrxSmLoftedBendFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmLoftedBendFeature();

    // Constructs a BrxSmCornerReliefFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal CornerRelief Feature
    BrxSmLoftedBendFeature(const AcDbObjectId& id);

    // Sets this BrxSmCornerReliefFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal CornerRelief Feature, the instance is empty.
    virtual BrxSmLoftedBendFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmCornerReliefFeature instance, if the queried
    // BrxIFeature object contains a BrxSmCornerReliefFeature instance, or an empty instance otherwise
    static BrxSmLoftedBendFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the faces (of specified face type) of this Lofted Bend Feature
    virtual AcDbFullSubentPathArray getFaces(ELoftedBendFaceType faceType) const;

    // returns whether 'this' BrxSmLoftedBendFeature supports analytical unfolding
    virtual bool supportsAnalyticalUnfolding() const;

    // returns unfolding mode of 'this' BrxSmLoftedBendFeature
    virtual EUnfoldingMode unfoldingMode() const;

    // sets unfolding mode for 'this' BrxSmLoftedBendFeature
    // unfoldMode : unfolding mode of lofted bend feature to set
    virtual Acad::ErrorStatus setUnfoldingMode(BrxSmLoftedBendFeature::EUnfoldingMode unfoldMode);

    // returns number of samples - rough estimation of number of planar quad faces tessellation may have.
    virtual int nbSamples() const;

    // sets number of samples for 'this' BrxSmLoftedBendFeature
    // nbSamples : desired number of samples (3, 10, 100, ...)
    virtual Acad::ErrorStatus setNbSamples(const int nbSamples);

    // Checks if given feature is closed, supports cases when feature has one and several faces
    // "Closed" means that lofted bend surface wraps around 360 degrees and has no split
    //  @return
    //    true if lofted bend is closed
    virtual bool isClosed() const;

    // Describes properties of the lofted bend surface for the given point
    struct BRX_IMPORTEXPORT ProjectionResult
    {
        // The nearest point on the surface for given query point
        AcGePoint3d m_projectionPoint;
        // Face of lofted bend on which projection exists
        AcDbFullSubentPath m_loftedFace;
        // Normal at the projection point
        AcGeVector3d m_normal;
        // The generatrix line of the lofted surface passing through this point
        // Note that both sides of the lofted bend can be only approximations of real lofted surface
        // Instead of returning OdGeLine3d, it is more convenient to return two points
        // Which show the limits of the line on the given face
        AcGePoint3d m_generatrixLineStartPoint;
        AcGePoint3d m_generatrixLineEndPoint;
    };

    // Projects given point on the lofted surface. It is advised that the point is not far from the surface
    // @param srcPoint
    //   Point to project
    // @param result
    //   Result if succeeded
    // @return
    //   eOk if succeeded
    virtual Acad::ErrorStatus projectPoint(const AcGePoint3d & srcPoint, ProjectionResult & projectionResult) const;

};

// SheetMetal Miter Feature

class BRX_IMPORTEXPORT BrxSmMiterFeature : public BrxIFeature
{
public:
    enum EMiterFaceType
    {
        eFirstSideFace  = 0x1,
        eSecondSideFace = 0x2,
        eNotchFace      = 0x4,
    };

    // Miter split type. Defines position of cut volume in relation to source line.
    // This line has start and end point and since it is on flange surface,
    // we can speak of left and right sides in relation to line:
    // 
    //                        * End
    //                       /
    //                      /
    //                     /
    //         Left       /       Right
    //                   /
    //                  /
    //                 /
    //                /
    //               * Start
    // 
    // Thus split type says how cut body is related to split line:
    // Cut body is to the left, eLeft mode
    // 
    //                     /==* End
    //                    /  /
    //                   /  /
    //                  /  /
    //                 /  /
    //                /  /
    //               /  /
    //              /  /
    //             /  /
    //            /==* Start
    // 
    // Cut body is in the center, eCenter mode
    // 
    //                        End
    //                     / * /
    //                    / / /
    //                   / / /
    //                  / / /
    //                 / / /
    //                / / /
    //               / / /
    //              / / /
    //             / / /
    //            / * /
    //             Start
    // 
    // eRight mode has mirror symmetry to the eLeft mode
    // 
    enum EMiterSplitType
    {
        eCenter = 0,
        eLeft,
        eRight,
    };

    BrxSmMiterFeature();
    BrxSmMiterFeature(const BrxIFeature& other);
    virtual BrxSmMiterFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmMiterFeature();

    // Constructs a BrxSmMiterFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal Miter Feature
    BrxSmMiterFeature(const AcDbObjectId& id);

    // Sets this BrxSmMiterFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal Miter Feature, the instance is empty.
    virtual BrxSmMiterFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmMiterFeature instance, if the queried
    // BrxIFeature object contains a BrxSmMiterFeature instance, or an empty instance otherwise
    static BrxSmMiterFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the faces (of specified face type) of this Miter Feature
    virtual AcDbFullSubentPathArray getFaces(EMiterFaceType faceType) const;

    // returns the gap type for this Miter Feature (eRelative, eAbsolute, eGlobal)
    virtual ESmValueType gapType() const;

    // get + set the gap type for "absolute" mode, for this Miter Feature
    virtual double getGapAbsoluteValue() const;
    virtual Acad::ErrorStatus setGapAbsoluteValue(double value);

    // get + set the gap type for "relative to thickness" mode, for this Miter Feature
    virtual double getGapRatio() const;
    virtual Acad::ErrorStatus setGapRatio(double value);

    // set the gap type for this Miter Feature to use the gap type from SheetMetal Context
    virtual Acad::ErrorStatus useGlobalGap(bool& wasChanged);

    // get + set the split type for this Miter Feature
    virtual EMiterSplitType splitType() const;
    virtual Acad::ErrorStatus setSplitType(EMiterSplitType type);
};

// SheetMetal Wrong Bend Feature

class BRX_IMPORTEXPORT BrxSmWrongBendFeature : public BrxIFeature
{
public:
    // This enum has same semantics as for the Bend Feature
    // Exception is that internal side can be collapsed to edges
    enum ESideType
    {
        eInternalSide = 0x1,
        eExternalSide = 0x2
    };

    BrxSmWrongBendFeature();
    BrxSmWrongBendFeature(const BrxIFeature& other);
    virtual BrxSmWrongBendFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmWrongBendFeature();

    // Constructs a BrxSmWrongBendFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal Wrong Bend Feature
    BrxSmWrongBendFeature(const AcDbObjectId& id);

    // Sets this BrxSmWrongBendFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal Wrong Bend Feature, the instance is empty.
    virtual BrxSmWrongBendFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmWrongBendFeature instance, if the queried
    // BrxIFeature object contains a BrxSmWrongBendFeature instance, or an empty instance otherwise
    static BrxSmWrongBendFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // retrieves geometry of this wrong bend feature
    // internal side can be either edges or faces, external side has always faces
    virtual AcDbFullSubentPathArray getGeometry(ESideType type) const;

    // get the radius type used by this Wrong Bend Feature
    virtual ESmValueType radiusType() const;

    // get + set the radius value for "absolute" mode, for this Wrong Bend Feature
    virtual double getRadiusAbsoluteValue() const;
    virtual Acad::ErrorStatus setRadiusAbsoluteValue(double value);

    // get + set the radius value for "relative to thickness" mode, for this Wrong Bend Feature
    virtual double getRadiusRatio() const;
    virtual Acad::ErrorStatus setRadiusRatio(double value);

    // set the radius type + value for this Wrong Bend Feature to use the gap type from SheetMetal Context
    virtual Acad::ErrorStatus useGlobalRadius(bool& wasChanged);
};

// SheetMetal Wrong Flange Feature

class BRX_IMPORTEXPORT BrxSmWrongFlangeFeature : public BrxIFeature
{
public:
    // distinguishes the sides of the flange feature;
    // eBottomFaces differ from eTopFaces that during parametric modification
    // bottom faces are not moved, if possible
    enum class EFaceType
    {
        eTopFaces    = 0x1,
        eBottomFaces = 0x2
    };

    BrxSmWrongFlangeFeature();
    BrxSmWrongFlangeFeature(const BrxIFeature& other);
    virtual BrxSmWrongFlangeFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmWrongFlangeFeature();

    // Constructs a BrxSmWrongFlangeFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal Wrong Flange Feature
    BrxSmWrongFlangeFeature(const AcDbObjectId& id);

    // Sets this BrxSmWrongFlangeFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal Wrong Flange Feature, the instance is empty.
    virtual BrxSmWrongFlangeFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmWrongBendFeature instance, if the queried
    // BrxIFeature object contains a BrxSmWrongBendFeature instance, or an empty instance otherwise
    static BrxSmWrongFlangeFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the faces of specified type for this 'Wrong Flange Feature' object
    virtual AcDbFullSubentPathArray getFaces(EFaceType faceType) const;

    // computes the actual thickness (distance between parallel faces) for this 'Wrong Flange Feature' object
    virtual Acad::ErrorStatus getThickness(double& thickness) const;
};

// SheetMetal Form Feature

class BRX_IMPORTEXPORT BrxSmFormFeature : public BrxIFeature
{
public:
    enum EFormFaceType
    {
        eTopFaces       = 0x1,
        eThicknessFaces = 0x2,
        eBottomFaces    = 0x4
    };

    BrxSmFormFeature();
    BrxSmFormFeature(const BrxIFeature& other);
    virtual BrxSmFormFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmFormFeature();

    // Constructs a BrxSmFormFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal Form Feature
    BrxSmFormFeature(const AcDbObjectId& id);

    // Sets this BrxSmFormFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal Form Feature, the instance is empty.
    virtual BrxSmFormFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmFormFeature instance, if the queried
    // BrxIFeature object contains a BrxSmFormFeature instance, or an empty instance otherwise
    static BrxSmFormFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // defines whether this form feature is a hole; hole features only have thickness faces.
    virtual bool isHole() const;

    // get the faces (of specified face type) of this Form Feature
    virtual AcDbFullSubentPathArray getFaces(EFormFaceType faceType) const;

    // get the coordinate system of insertion of given form feature
    virtual Acad::ErrorStatus getInsertionCS(AcGePoint3d& origin, AcGeVector3d& xAxis, AcGeVector3d& yAxis, AcGeVector3d& zAxis) const;

    // returns the id of block reference which corresponds to instance of mechanical component,
    // inserted to given SheetMetal part from Form Feature library;
    // can be kNull, which is the case for recognized form features
    virtual AcDbObjectId getInsertedBlockRefId() const;
};

// SheetMetal Rib Feature

class BRX_IMPORTEXPORT BrxSmRibFeature : public BrxIFeature
{
public:
    enum ERibFaceType
    {
        eTopFaces    = 0x01,
        eBottomFaces = 0x02
    };

    enum ERibRadiusType
    {
        eGlobal = 0,
        eAbsolute
    };

    BrxSmRibFeature();
    BrxSmRibFeature(const BrxIFeature& other);
    virtual BrxSmRibFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmRibFeature();

    // constructs a BrxSmRibFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a SheetMetal Rib Feature
    BrxSmRibFeature(const AcDbObjectId& id);

    // sets this BrxSmRibFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a SheetMetal Rib Feature, the instance is empty.
    virtual BrxSmRibFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmRibFeature instance, if the queried
    // BrxIFeature object contains a BrxSmRibFeature instance, or an empty instance otherwise
    static BrxSmRibFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the faces (of specified face type) of this Rib Feature
    virtual AcDbFullSubentPathArray getFaces(ERibFaceType faceType) const;

    // Rib feature is defined by trajectory and section geometry,
    // while trajectory is controlled by control curve (to which fillets may be applied);
    // shape of section is controlled by profile and round radii :
    //
    //                  **
    //               *      *  <----R
    //             *    **    *
    //            *    *  *    *
    //            *   *    *    *
    //           *   *      *   * <---- r
    //    ******    *        *   ******
    //             *          *  Flange
    //    *********            ********
    //
    // 'R' is radius of external swept arc, which is called 'Profile Radius';
    // 'r' is small fillet between Profile and Flange in order to make connection between flange
    // and profile tangential - it is called 'Round Radius'

    // get the 'Profile Radius' type
    virtual ERibRadiusType profileRadiusType() const;

    // get + set the 'Profile Radius' value for the "absolute" mode
    virtual double getProfileRadiusAbsoluteValue() const;
    virtual Acad::ErrorStatus setProfileRadiusAbsoluteValue(double value);

    // set the 'Profile Radius' to use the the value from SheetMetal Context
    virtual Acad::ErrorStatus useGlobalProfileRadius(bool& wasChanged);

    // get the 'Round Radius' type
    virtual ERibRadiusType roundRadiusType() const;

    // get + set the 'Round Radius' value for the "absolute" mode
    virtual double getRoundRadiusAbsoluteValue() const;
    virtual Acad::ErrorStatus setRoundRadiusAbsoluteValue(double value);

    // set the 'Round Radius' to use the the value from SheetMetal Context
    virtual Acad::ErrorStatus useGlobalRoundRadius(bool& wasChanged);

    // retrieves the AcDbObjectId of control curve entity which controls trajectory shape
    // of this rib feature;
    // returned value can be kNull, since control curve is not obligatory;
    // the control curve entity will be planar 2D curve lying on some flange
    virtual AcDbObjectId pathId() const;
};

// SheetMetal Hem Feature

class BRX_IMPORTEXPORT BrxSmHemFeature : public BrxIFeature
{
public:
    // distinguishes sides of the hem feature: planar (flange) and curved (bend) parts;
    // 'eFlangeExternalFaces' differ from 'eFlangeInternalFaces' that during parametric modification
    // external faces are not moved if possible, i.e. on thickness increase feature thickens inside
    // keeping external dimensions
    enum EFaceType
    {
        eBendInternalFaces   = 0x01,
        eBendExternalFaces   = 0x02,
        eFlangeInternalFaces = 0x04,
        eFlangeExternalFaces = 0x08
    };
  
    // type of hem feature
    enum EType
    {
        eNotHem    = 0,
        eClosedHem = 1,
        eOpenHem   = 2,
        eTearDrop  = 3,
        eRound     = 4
    };

    BrxSmHemFeature();
    BrxSmHemFeature(const BrxIFeature& other);
    virtual BrxSmHemFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmHemFeature();

    // Constructs a BrxSmHemFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a Hem Feature
    BrxSmHemFeature(const AcDbObjectId& id);

    // sets this BrxSmHemFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a Hem Feature, the instance is empty.
    virtual BrxSmHemFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmHemFeature instance, if the queried
    // BrxIFeature object contains a BrxSmHemFeature instance, or an empty instance otherwise
    static BrxSmHemFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // returns all faces of specific type of this hem feature
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;

    // returns the type of this Hem feature
    virtual Acad::ErrorStatus hemType(EType& type) const;

    // returns the length of the flange part of this Hem feature
    virtual Acad::ErrorStatus length(double& len) const;

    // returns the bend radius type
    virtual Acad::ErrorStatus radiusType(EValueType& type) const;

    // get + set the absolute bend radius
    // Note : the radius value will be returned as absolute with no regard to radiusType()
    virtual Acad::ErrorStatus getRadiusAbsoluteValue(double& radius) const;
    virtual Acad::ErrorStatus setRadiusAbsoluteValue(double  radius);

    // get + set the radius / thickness ratio
    virtual Acad::ErrorStatus getRadiusRatio(double& radiusRatio) const;
    virtual Acad::ErrorStatus setRadiusRatio(double  radiusRatio);

    // defines to use the global value for bend radius;
    // Note : the geometry of model is not recomputed
    // on return, 'wasChanged' reports whether the absolute/relative radius mode has changed
    virtual Acad::ErrorStatus useGlobalRadius(bool& wasChanged);

    // returns the swept bend angle in radians, in range (-2*Pi, 2*Pi)
    virtual Acad::ErrorStatus getSweptAngle(double& angle) const;
};

// SheetMetal Tab Feature

class BRX_IMPORTEXPORT BrxSmTabFeature : public BrxIFeature
{
public:
    enum EFaceType
    {
        eFacesNone            = 0x00,
        eFirstExtrudedFaces   = 0x01,
        eFirstThicknessFaces  = 0x02,
        eFirstBaseFaces       = 0x04,
        eSecondExtrudedFaces  = 0x08,
        eSecondThicknessFaces = 0x10,
        eSecondBaseFaces      = 0x20,
    };
    
    // Overlap type of tab feature
    enum class EOverlappingType
    {
        eNoOverlap          = 0,
        eFull               = 1,
        eFirstSidedPartial  = 2,
        eSecondSidedPartial = 3,
    };
    
    enum class EType
    {
        eSingle = 0,
        eArray  = 1,
        eCurved = 2,
    };
    
    enum class ETabPlacement
    {
        eSymmetricTabInCenter  = 0,
        eSymmetricSlotInCenter = 1,
    };

    BrxSmTabFeature();
    BrxSmTabFeature(const BrxIFeature& other);
    virtual BrxSmTabFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmTabFeature();

    // Constructs a BrxSmTabFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a Tab Feature
    BrxSmTabFeature(const AcDbObjectId& id);

    // sets this BrxSmTabFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a Tab Feature, the instance is empty.
    virtual BrxSmTabFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmTabFeature instance, if the queried
    // BrxIFeature object contains a BrxSmTabFeature instance, or an empty instance otherwise
    static BrxSmTabFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // returns all faces of specific type of this tab feature
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;

    // get + set the type of overlapping
    virtual Acad::ErrorStatus overlappingType(EOverlappingType& type) const;
    virtual Acad::ErrorStatus setOverlappingType(EOverlappingType type);

    // get + set the type of the tab feature
    virtual Acad::ErrorStatus tabType(EType& type) const;
    virtual Acad::ErrorStatus setTabType(EType type);

    // get + set the number of slots for the tab feature
    virtual Acad::ErrorStatus slotNumber(int& numSlots) const;
    virtual Acad::ErrorStatus setSlotNumber(int numSlots);

    // get + set the tab placement
    virtual Acad::ErrorStatus tabPlacement(ETabPlacement& placement) const;
    virtual Acad::ErrorStatus setTabPlacement(ETabPlacement placement);

    // get the tab feature's height type
    virtual Acad::ErrorStatus heightType(EValueType& type) const;

    // set the tab feature to use the global height
    virtual Acad::ErrorStatus useGlobalHeight(bool& wasChanged);

    // get + set the absolute height of the tab feature
    virtual Acad::ErrorStatus heightAbsoluteValue(double& absHeight) const;
    virtual Acad::ErrorStatus setHeightAbsoluteValue(double absHeight);

    // get + set the height/thickness ratio of the tab feature
    virtual Acad::ErrorStatus heightRatio(double& ratio) const;
    virtual Acad::ErrorStatus setHeightRatio(double ratio);

    // get the tab feature's distance type
    virtual Acad::ErrorStatus distanceType(EValueType& type) const;

    // set the tab feature to use the global distance
    virtual Acad::ErrorStatus useGlobalDistance(bool& wasChanged);

    // get + set the absolute distance of the tab feature
    virtual Acad::ErrorStatus distanceAbsoluteValue(double& distance) const;
    virtual Acad::ErrorStatus setDistanceAbsoluteValue(double distance);

    // get + set the distance/thickness ratio of the tab feature
    virtual Acad::ErrorStatus distanceRatio(double& ratio) const;
    virtual Acad::ErrorStatus setDistanceRatio(double ratio);

    // get the tab feature's length type
    virtual Acad::ErrorStatus lengthType(EValueType& type) const;

    // set the tab feature to use the global length
    virtual Acad::ErrorStatus useGlobalLength(bool& wasChanged);

    // get + set the absolute length of the tab feature
    virtual Acad::ErrorStatus lengthAbsoluteValue(double& length) const;
    virtual Acad::ErrorStatus setLengthAbsoluteValue(double length);

    // get + set the length/thickness ratio of the tab feature
    virtual Acad::ErrorStatus lengthRatio(double& ratio) const;
    virtual Acad::ErrorStatus setLengthRatio(double ratio);

    // get the tab feature's clearance type
    virtual Acad::ErrorStatus clearanceType(EValueType& type) const;

    // set the tab feature to use the global clearance value
    virtual Acad::ErrorStatus useGlobalClearance(bool& wasChanged);

    // get + set the absolute clearance value of the tab feature
    virtual Acad::ErrorStatus clearanceAbsoluteValue(double& absClearance) const;
    virtual Acad::ErrorStatus setClearanceAbsoluteValue(double absClearance);

    // get + set the clearance/thickness ratio of the tab feature
    virtual Acad::ErrorStatus clearanceRatio(double& ratio) const;
    virtual Acad::ErrorStatus setClearanceRatio(double ratio);

    // get the tab feature's fillet radius type
    virtual Acad::ErrorStatus filletRadiusType(EValueType& type) const;

    // set the tab feature to use the global fillet radius value
    virtual Acad::ErrorStatus useGlobalFilletRadius(bool& wasChanged);

    // get + set the absolute fillet radius value of the tab feature
    virtual Acad::ErrorStatus filletRadiusAbsoluteValue(double& absRadius) const;
    virtual Acad::ErrorStatus setFilletRadiusAbsoluteValue(double absRadius);

    // get + set the fillet radius/thickness ratio of the tab feature
    virtual Acad::ErrorStatus filletRadiusRatio(double& ratio) const;
    virtual Acad::ErrorStatus setFilletRadiusRatio(double ratio);

    // get the tab feature's chamfer distance radius type
    virtual Acad::ErrorStatus chamferDistanceType(EValueType& type) const;

    // set the tab feature to use the global chamfer distance value
    virtual Acad::ErrorStatus useGlobalChamferDistance(bool& wasChanged);

    // get + set the absolute chamfer distance value of the tab feature
    virtual Acad::ErrorStatus chamferDistanceAbsoluteValue(double& absDistance) const;
    virtual Acad::ErrorStatus setChamferDistanceAbsoluteValue(double absDistance);

    // get + set the chamfer distance/thickness ratio of the tab feature
    virtual Acad::ErrorStatus chamferDistanceRatio(double& ratio) const;
    virtual Acad::ErrorStatus setChamferDistanceRatio(double ratio);
};

// SheetMetal ZeroBend Feature

class BRX_IMPORTEXPORT BrxSmZeroBendFeature : public BrxIFeature
{
public:
    enum EEntityType
    {
        eNoEdges       = 0x0,
        eInternalEdges = 0x1,
        eExternalFaces = 0x2,
    };

    BrxSmZeroBendFeature();
    BrxSmZeroBendFeature(const BrxIFeature& other);
    virtual BrxSmZeroBendFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmZeroBendFeature();

    // Constructs a BrxSmZeroBendFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a ZeroBend Feature
    BrxSmZeroBendFeature(const AcDbObjectId& id);

    // sets this BrxSmZeroBendFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a ZeroBend Feature, the instance is empty.
    virtual BrxSmZeroBendFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmZeroBendFeature instance, if the queried
    // BrxIFeature object contains a BrxSmZeroBendFeature instance, or an empty instance otherwise
    static BrxSmZeroBendFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // returns the entities (faces or edges) of specified type of this zero bend feature;
    // EEntityType can be OR'd
    virtual Acad::ErrorStatus getEntities(AcDbFullSubentPathArray& entities, EEntityType type) const;

    // returns the vee die width type
    virtual BrxSmBendFeature::EBendVDieWidthType vDieWidthType() const;

    // get + set the vee die width value of the tab feature
    virtual Acad::ErrorStatus vDieWidth(double& width) const;
    virtual Acad::ErrorStatus setVDieWidth(double width);

    // defines to use the global value for the vee die width as defined in Sheet Metal context;
    // 'wasChanged' returns whether the effective value for the vee die width has changed
    virtual Acad::ErrorStatus useGlobalVDieWidth(bool& wasChanged);

    // returns the internal bend angle in range (-Pi, Pi);
    // limitation is that it correctly defines angles only for regular bends;
    // for teardrop it will return -Pi/2 while swept angle is 3*Pi/2;
    // -Pi/2 will mean to bend only by Pi/2 degrees down the adjacent flange
    virtual Acad::ErrorStatus getInternalAngle(double& angle) const;

    // returns the swept bend angle in range (-2*Pi, 2*Pi)
    virtual Acad::ErrorStatus getSweptAngle(double& angle) const;
};

// SheetMetal Bevel Feature

class BRX_IMPORTEXPORT BrxSmBevelFeature : public BrxIFeature
{
public:
    enum EFaceType
    {
        eNoFace          = 0x00,
        eFirstSideFaces  = 0x01,
        eOrthogonalFaces = 0x02,
        eSecondSideFaces = 0x04,
    };

    enum class EBevelType
    {
        eNotBevel     = 0,
        eOneSideBevel = 1,
        eLandBevel    = 2,
        eXBevel       = 3,
        eKBevel       = 4
    };

    BrxSmBevelFeature();
    BrxSmBevelFeature(const BrxIFeature& other);
    virtual BrxSmBevelFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmBevelFeature();

    // Constructs a BrxSmBevelFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a Bevel Feature
    BrxSmBevelFeature(const AcDbObjectId& id);

    // sets this BrxSmBevelFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a Bevel Feature, the instance is empty.
    virtual BrxSmBevelFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmBevelFeature instance, if the queried
    // BrxIFeature object contains a BrxSmBevelFeature instance, or an empty instance otherwise
    static BrxSmBevelFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // returns all faces of specific type of this tab feature
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;

    // get + set the bevel type of the tab feature
    virtual Acad::ErrorStatus bevelType(EBevelType& type) const;
    virtual Acad::ErrorStatus setBevelType(EBevelType type);
  
    // get + set the angle value for the first side flange
    virtual Acad::ErrorStatus firstSideAngle(double& angle) const;
    virtual Acad::ErrorStatus setFirstSideAngle(double angle);

    // get + set the angle value for the second side flange
    virtual Acad::ErrorStatus secondSideAngle(double& angle) const;
    virtual Acad::ErrorStatus setSecondSideAngle(double angle);

    // get + set the depth value for the first side flange
    virtual Acad::ErrorStatus firstSideDepth(double& depth) const;
    virtual Acad::ErrorStatus setFirstSideDepth(double depth);

    // get + set the depth value for the second side flange
    virtual Acad::ErrorStatus secondSideDepth(double& depth) const;
    virtual Acad::ErrorStatus setSecondSideDepth(double depth);

    // get + set the orthogonal depth value
    virtual Acad::ErrorStatus orthogonalDepth(double& depth) const;
    virtual Acad::ErrorStatus setOrthogonalDepth(double depth);
};

// SheetMetal TJunction Feature

class BRX_IMPORTEXPORT BrxSmTJunctionFeature : public BrxIFeature
{
public:
    enum class EFaceType
    {
        eNoFace         = 0x00,
        eFirstPartFaces = 0x01,
    };

    BrxSmTJunctionFeature();
    BrxSmTJunctionFeature(const BrxIFeature& other);
    virtual BrxSmTJunctionFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmTJunctionFeature();

    // Constructs a BrxSmTJunctionFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a TJunction Feature
    BrxSmTJunctionFeature(const AcDbObjectId& id);

    // sets this BrxSmTJunctionFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a TJunction Feature, the instance is empty.
    virtual BrxSmTJunctionFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmTJunctionFeature instance, if the queried
    // BrxIFeature object contains a BrxSmTJunctionFeature instance, or an empty instance otherwise
    static BrxSmTJunctionFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // returns all faces of specific type of this TTab feature
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;

    // get the T-junction gap type
    virtual Acad::ErrorStatus junctionGapType(EValueType& type) const;

    // get + set the T-Junction gap absolute value
    virtual Acad::ErrorStatus getJunctionGapAbsoluteValue(double& gap) const;
    virtual Acad::ErrorStatus setJunctionGapAbsoluteValue(double gap);

    // get + set the T-Junction gap/thickness ratio
    virtual Acad::ErrorStatus getJunctionGapRatio(double& ratio) const;
    virtual Acad::ErrorStatus setJunctionGapRatio(double ratio);

    // use global value for the gap; returns whether the gap value was effectively changed
    virtual Acad::ErrorStatus useGlobalGap(bool& wasChanged);
};

// SheetMetal TTab Feature

class BRX_IMPORTEXPORT BrxSmTTabFeature : public BrxIFeature
{
public:
    // face types of this TTab feature (can be combined)
    enum EFaceType
    {
        eFirstExtrudedFaces  = 0x01,
        eFirstThicknessFaces = 0x02,
        eFirstBaseFaces      = 0x04,
        eSecondFaces         = 0x08,
    };

    enum class EType
    {
        eSingle = 0,
        eArray  = 1,
    };

    // Tab placement
    enum class ETabPlacement
    {
        eSymmetricTabInCenter  = 0,
        eSymmetricSlotInCenter = 1,
        eNotDefined            = 2,
    };

    BrxSmTTabFeature();
    BrxSmTTabFeature(const BrxIFeature& other);
    virtual BrxSmTTabFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmTTabFeature();

    // Constructs a BrxSmTTabFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain a TTab Feature
    BrxSmTTabFeature(const AcDbObjectId& id);

    // sets this BrxSmTTabFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain a TTab Feature, the instance is empty.
    virtual BrxSmTTabFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmTTabFeature instance, if the queried
    // BrxIFeature object contains a BrxSmTTabFeature instance, or an empty instance otherwise
    static BrxSmTTabFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // returns all faces of specified type (can be bitwise combined)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType faceType) const;

    // get + set the TTab type of this TTab feature
    virtual Acad::ErrorStatus tabType(EType& type) const;
    virtual Acad::ErrorStatus setTabType(EType type);

    // get + set the slot numbers of this TTab feature
    virtual Acad::ErrorStatus slotNumber(int& numSlots) const;
    virtual Acad::ErrorStatus setSlotNumber(int numSlots);

    // get + set the absolute height value of this TTab feature
    virtual Acad::ErrorStatus heightAbsoluteValue(double& height) const;
    virtual Acad::ErrorStatus setHeightAbsoluteValue(double height);

    // returns the effective height value type;
    // use the global value for tab height + returns whether the height value was effectively changed
    virtual Acad::ErrorStatus heightType(EValueType& type) const;
    virtual Acad::ErrorStatus useGlobalHeight(bool& wasChanged);

    // get + set the height ratio value of this TTab feature
    virtual Acad::ErrorStatus heightRatio(double& ratio) const;
    virtual Acad::ErrorStatus setHeightRatio(double ratio);

    // get + set the absolute distance value of this TTab feature
    virtual Acad::ErrorStatus distanceAbsoluteValue(double& distance) const;
    virtual Acad::ErrorStatus setDistanceAbsoluteValue(double distance);

    // returns the effective distance value type;
    // use the global value for tab distance + returns whether the distance value was effectively changed
    virtual Acad::ErrorStatus distanceType(EValueType& type) const;
    virtual Acad::ErrorStatus useGlobalDistance(bool& wWasChanged);

    // get + set the distance ratio value of this TTab feature
    virtual Acad::ErrorStatus distanceRatio(double& ratio) const;
    virtual Acad::ErrorStatus setDistanceRatio(double value);

    // get + set the absolute length value of this TTab feature
    virtual Acad::ErrorStatus lengthAbsoluteValue(double& length) const;
    virtual Acad::ErrorStatus setLengthAbsoluteValue(double length);

    // returns the effective length value type;
    // use the global value for tab length + returns whether the length value was effectively changed
    virtual Acad::ErrorStatus lengthType(EValueType& type) const;
    virtual Acad::ErrorStatus useGlobalLength(bool& wasChanged);

    // get + set the length ratio value of this TTab feature
    virtual Acad::ErrorStatus lengthRatio(double& ratio) const;
    virtual Acad::ErrorStatus setLengthRatio(double ratio);

    // get + set the absolute clearance value of this TTab feature
    virtual Acad::ErrorStatus clearanceAbsoluteValue(double& clearance) const;
    virtual Acad::ErrorStatus setClearanceAbsoluteValue(double clearance);

    // returns the effective clearance value type;
    // use the global value for tab clearance + returns whether the clearance value was effectively changed
    virtual Acad::ErrorStatus clearanceType(EValueType& type) const;
    virtual Acad::ErrorStatus useGlobalClearance(bool& wasChanged);

    // get + set the clearance ratio value of this TTab feature
    virtual Acad::ErrorStatus clearanceRatio(double& ratio) const;
    virtual Acad::ErrorStatus setClearanceRatio(double ratio);

    // get + set the absolute round radius value of this TTab feature
    virtual Acad::ErrorStatus filletRadiusAbsoluteValue(double& radius) const;
    virtual Acad::ErrorStatus setFilletRadiusAbsoluteValue(double radius);

    // returns the effective radius ratio value type;
    // use the global value for tab radius ratio + returns whether the radius ratio value was effectively changed
    virtual Acad::ErrorStatus filletRadiusRatio(double& ratio) const;
    virtual Acad::ErrorStatus setFilletRadiusRatio(double ratio);

    // get + set the round radius type of this TTab feature
    virtual Acad::ErrorStatus filletRadiusType(EValueType& type) const;
    virtual Acad::ErrorStatus useGlobalFilletRadius(bool& wasChanged);

    // get + set the absolute chamfer distance value of this TTab feature
    virtual Acad::ErrorStatus chamferDistanceAbsoluteValue(double& distance) const;
    virtual Acad::ErrorStatus setChamferDistanceAbsoluteValue(double distance);

    // returns the effective chamfer distance ratio value type;
    // use the global value for tab chamfer distance ratio + returns whether the chamfer distance ratio value was effectively changed
    virtual Acad::ErrorStatus chamferDistanceRatio(double& ratio) const;
    virtual Acad::ErrorStatus setChamferDistanceRatio(double ratio);

    // get + set the chamfer distance type of this TTab feature
    virtual Acad::ErrorStatus chamferDistanceType(EValueType& type) const;
    virtual Acad::ErrorStatus useGlobalChamferDistance(bool& wasChanged);

    // get + set the tab placement of this TTab feature
    virtual Acad::ErrorStatus tabPlacement(ETabPlacement& placement) const;
    virtual Acad::ErrorStatus setTabPlacement(ETabPlacement placement);
};

//============================= Unfolded Features =============================

// SheetMetal UnfoldedBendLine

class BrxSmUnfoldedBendFeature;
class BrxSmUnfoldedHemFeature;
class BrxSmUnfoldedLoftedBendFeature;
class BrxSmUnfoldOperation;

class BRX_IMPORTEXPORT BrxSmUnfoldedBendLine
{
    friend class BrxSmUnfoldedBendFeature;
    friend class BrxSmUnfoldedHemFeature;
    friend class BrxSmUnfoldedLoftedBendFeature;
    friend class BrxSmUnfoldOperation;

    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IUnfoldedBendLine>  m_bendLine = nullptr;

public:
    enum class EType
    {
        eNoBend               = -1,
        eBend                 = 0,
        eLoftedBend           = 1,
        eHem                  = 2,
        eAnalyticalLoftedBend = 3,
    };

    BrxSmUnfoldedBendLine();
    BrxSmUnfoldedBendLine(const BrxSmUnfoldedBendLine& other);
    virtual BrxSmUnfoldedBendLine& operator= (const BrxSmUnfoldedBendLine& other);
    virtual ~BrxSmUnfoldedBendLine();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // gets the AcDbObjectId of the Bend, Hem or LoftedBend Feature on the initial 3D part
    virtual Acad::ErrorStatus featureId(AcDbObjectId& id) const;

    // get the start + end points of the bend line
    virtual Acad::ErrorStatus startPoint(AcGePoint3d& startPnt) const;
    virtual Acad::ErrorStatus endPoint(AcGePoint3d& endPnt) const;

    // get the start and end points, touching the edges of unfolded part
    virtual Acad::ErrorStatus startPointTight(AcGePoint3d& startPntTight) const;
    virtual Acad::ErrorStatus endPointTight(AcGePoint3d& endPntTight) const;

    // get the internal bend angle of corresponding bend in radians, in range (-Pi, Pi)
    virtual Acad::ErrorStatus getInternalAngle(double& angle) const;

    // get the swept bend angle of corresponding bend in radians, in range (-Pi, Pi)
    virtual Acad::ErrorStatus getSweptAngle(double& angle) const;

    // get the type of corresponding bend
    virtual Acad::ErrorStatus type(EType& bendType) const;

    // get the feature type of corresponding bend
    virtual Acad::ErrorStatus getFeatureTypeName(AcString& typeName) const;

    // get the allowance of corresponding bend
    virtual Acad::ErrorStatus bendAllowance(double& allowance) const;

    // get the radius of corresponding bend
    virtual Acad::ErrorStatus bendRadius(double& radius) const;

    // get the K-Factor of corresponding bend
    virtual Acad::ErrorStatus kFactor(double& factor) const;
};
typedef AcArray<BrxSmUnfoldedBendLine, AcArrayObjectCopyReallocator<BrxSmUnfoldedBendLine> > BrxSmUnfoldedBendLinesArray;

// SheetMetal UnfoldedBevelEdge

class BRX_IMPORTEXPORT BrxSmUnfoldedBevelEdge
{
    friend class BrxSmUnfoldOperation;

    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IUnfoldedBevelEdge>  m_bevelEdge = nullptr;

public:
    enum class EUnfoldedBevelSense
    {
        eNoSense  = 0,
        eForward  = 1,
        eReversed = 2,
    };

    BrxSmUnfoldedBevelEdge();
    BrxSmUnfoldedBevelEdge(const BrxSmUnfoldedBevelEdge& other);
    virtual BrxSmUnfoldedBevelEdge& operator= (const BrxSmUnfoldedBevelEdge& other);
    virtual ~BrxSmUnfoldedBevelEdge();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // gets the AcDbObjectId of the Feature on the initial 3D part
    virtual Acad::ErrorStatus featureId(AcDbObjectId& id) const;

    // gets the AcDbObjectId of the edge on the unfolded 2D geometry
    virtual Acad::ErrorStatus edge2dId(AcDbObjectId& id) const;

    // get the top + bottom bevel angle in radians
    virtual Acad::ErrorStatus topBevelAngle(double& topAngle) const;
    virtual Acad::ErrorStatus bottomBevelAngle(double& bottomAngle) const;

    // get the top + bottom bevel depth
    virtual Acad::ErrorStatus topBevelDepth(double& topWidth) const;
    virtual Acad::ErrorStatus bottomBevelDepth(double& bottomWidth) const;

    // returns whether the top + bottom bevels are present
    virtual Acad::ErrorStatus hasTopBevel(bool& hasBevel) const;
    virtual Acad::ErrorStatus hasBottomBevel(bool& hasBevel) const;

    virtual Acad::ErrorStatus bevelSense(EUnfoldedBevelSense& sense) const;
};
typedef AcArray<BrxSmUnfoldedBevelEdge, AcArrayObjectCopyReallocator<BrxSmUnfoldedBevelEdge> > BrxSmUnfoldedBevelEdgeArray;

// SheetMetal UnfoldedFormFeatureWires

class BRX_IMPORTEXPORT BrxSmUnfoldedFormFeatureWires
{
    friend class BrxSmUnfoldOperation;

    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IUnfoldedFormFeatureWires>  m_formFeatureWires = nullptr;

public:
    BrxSmUnfoldedFormFeatureWires();
    BrxSmUnfoldedFormFeatureWires(const BrxSmUnfoldedFormFeatureWires& other);
    virtual BrxSmUnfoldedFormFeatureWires& operator= (const BrxSmUnfoldedFormFeatureWires& other);
    virtual ~BrxSmUnfoldedFormFeatureWires();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // gets the AcDbObjectId of the FormFeature on initial 3D part
    virtual Acad::ErrorStatus featureId(AcDbObjectId& id) const;

    // returns whether this FormFeature is defined on the side of the sheet metal part, which is used
    // as top side in unfolding operation
    virtual Acad::ErrorStatus isUpDirection(bool& isUp) const;

    // returns the ObjectIds of the 2D entities after unfolding
    virtual Acad::ErrorStatus wireEntities(AcDbObjectIdArray& ids) const;
};
typedef AcArray<BrxSmUnfoldedFormFeatureWires, AcArrayObjectCopyReallocator<BrxSmUnfoldedFormFeatureWires> > BrxSmUnfoldedFormFeatureWiresArray;

// SheetMetal Unfolded Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedFeature : public BrxIFeature
{
public:
    BrxSmUnfoldedFeature();
    BrxSmUnfoldedFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedFeature();

    // Constructs a BrxSmUnfoldedFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an Unfolded Feature
    BrxSmUnfoldedFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an Unfolded Feature, the instance is empty.
    virtual BrxSmUnfoldedFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // returns the Id of the original feature
    virtual Acad::ErrorStatus originalFeatureId(AcDbObjectId& id, const AcDbDatabase* pSrcDb) const;

    // returns whether this feature clashes with some other
    virtual Acad::ErrorStatus isClashed(bool& clashes) const;
};

// SheetMetal UnfoldedBend Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedBendFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces       = 0x0,
        eInternalFaces = 0x1,
        eExternalFaces = 0x2
    };

    BrxSmUnfoldedBendFeature();
    BrxSmUnfoldedBendFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedBendFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedBendFeature();

    // Constructs a BrxSmUnfoldedBendFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedBend Feature
    BrxSmUnfoldedBendFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedBendFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedBend Feature, the instance is empty.
    virtual BrxSmUnfoldedBendFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedBendFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedBendFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedBendFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // retrieves the faces of specified type(s) of this unfolded bend feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;

    // returns the bend radius of this bend feature
    virtual Acad::ErrorStatus bendRadius(double& radius) const;

    // computes the bend angle in radians, in range (-180, 180);
    // limitation of notation is that it correctly defines angles only for regular bends;
    // for teardrop will return -Pi/2 while swept angle is 3*Pi/2;
    // -Pi/2 will mean to bend only by Pi/2 degrees down the adjacent flange
    // returns the internal bend angle in radians, in range (-Pi, Pi)
    virtual Acad::ErrorStatus getInternalAngle(double& angle) const;

    // computes the swept bend angle in radians, in range (-2*Pi, 2*Pi)
    virtual Acad::ErrorStatus getSweptAngle(double& angle) const;

    // returns the efficient k-Factor used for unfolding
    virtual Acad::ErrorStatus kFactor(double& factor) const;

    // returns the bend lines associated with this unfolded bend feature
    virtual Acad::ErrorStatus getBendLines(BrxSmUnfoldedBendLinesArray& bendLines) const;
};

// SheetMetal UnfoldedLoftetBend Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedLoftedBendFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces     = 0x0,
        eTopFaces    = 0x1,
        eBottomFaces = 0x2
    };

    BrxSmUnfoldedLoftedBendFeature();
    BrxSmUnfoldedLoftedBendFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedLoftedBendFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedLoftedBendFeature();

    // Constructs a BrxSmUnfoldedLoftedBendFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedLoftedBend Feature
    BrxSmUnfoldedLoftedBendFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedLoftedBendFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedLoftedBend Feature, the instance is empty.
    virtual BrxSmUnfoldedLoftedBendFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedBendFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedBendFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedLoftedBendFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // retrieves the faces of specified type(s) of this unfolded lofted bend feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;

    // returns the bend lines associated with this unfolded lofted bend feature
    virtual Acad::ErrorStatus getBendLines(BrxSmUnfoldedBendLinesArray& bendLines) const;
};

// SheetMetal UnfoldedJunction Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedJunctionFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces         = 0x0,
        eFirstPartFaces  = 0x1,
        eSecondPartFaces = 0x2
    };

    BrxSmUnfoldedJunctionFeature();
    BrxSmUnfoldedJunctionFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedJunctionFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedJunctionFeature();

    // Constructs a BrxSmUnfoldedJunctionFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedJunction Feature
    BrxSmUnfoldedJunctionFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedJunctionFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedJunction Feature, the instance is empty.
    virtual BrxSmUnfoldedJunctionFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedJunctionFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedJunctionFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedJunctionFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // retrieves the faces of specified type(s) of this unfolded junction feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;
};

// SheetMetal UnfoldedFlange Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedFlangeFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces     = 0x0,
        eTopFaces    = 0x1,
        eBottomFaces = 0x2,
    };

    BrxSmUnfoldedFlangeFeature();
    BrxSmUnfoldedFlangeFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedFlangeFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedFlangeFeature();

    // Constructs a BrxSmUnfoldedFlangeFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedFlange Feature
    BrxSmUnfoldedFlangeFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedFlangeFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedFlange Feature, the instance is empty.
    virtual BrxSmUnfoldedFlangeFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedFlangeFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedFlangeFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedFlangeFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // retrieves the faces of specified type(s) of this unfolded flange feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;
};

// SheetMetal UnfoldedTab Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedTabFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces              = 0x00,
        eFirstExtrudedFaces   = 0x01,
        eFirstThicknessFaces  = 0x02,
        eFirstBaseFaces       = 0x04,
        eSecondExtrudedFaces  = 0x08,
        eSecondThicknessFaces = 0x10,
        eSecondBaseFaces      = 0x20,
    };

    BrxSmUnfoldedTabFeature();
    BrxSmUnfoldedTabFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedTabFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedTabFeature();

    // Constructs a BrxSmUnfoldedTabFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedTab Feature
    BrxSmUnfoldedTabFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedTabFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedTab Feature, the instance is empty.
    virtual BrxSmUnfoldedTabFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedTabFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedTabFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedTabFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // retrieves the faces of specified type(s) of this unfolded tab feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;
};

// SheetMetal UnfoldedMiter Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedMiterFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces        = 0x0,
        eFirstSideFace  = 0x1,
        eSecondSideFace = 0x2,
        eNotchFace      = 0x4
    };

    BrxSmUnfoldedMiterFeature();
    BrxSmUnfoldedMiterFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedMiterFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedMiterFeature();

    // Constructs a BrxSmUnfoldedMiterFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedMiter Feature
    BrxSmUnfoldedMiterFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedMiterFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedMiter Feature, the instance is empty.
    virtual BrxSmUnfoldedMiterFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedMiterFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedMiterFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedMiterFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // retrieves the faces of specified type(s) of this unfolded miter feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;
};

// SheetMetal UnfoldedBendRelief Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedBendReliefFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces           = 0x0,
        eFlangeSideFaces   = 0x1,
        eExternalFaces     = 0x2,
        eNotchModelFaces   = 0x4,
        eNotchProfileFaces = 0x8,
    };

    enum class EType
    {
        eRectangular = 0,
        eRound       = 1,
        eSmooth      = 2,
        eRip         = 3,
        eUnknown     = 4,
    };

    BrxSmUnfoldedBendReliefFeature();
    BrxSmUnfoldedBendReliefFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedBendReliefFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedBendReliefFeature();

    // Constructs a BrxSmUnfoldedBendReliefFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedBendRelief Feature
    BrxSmUnfoldedBendReliefFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedBendReliefFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedBendRelief Feature, the instance is empty.
    virtual BrxSmUnfoldedBendReliefFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedBendReliefFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedBendReliefFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedBendReliefFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the bend relief type for this feature
    virtual Acad::ErrorStatus type(EType& type) const;

    // retrieves the faces of specified type(s) of this unfolded bend relief feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;
};

// SheetMetal UnfoldedCornerRelief Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedCornerReliefFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces       = 0x00,
        eBendFaces1    = 0x01,
        eNotchFaces1   = 0x02,
        eBendFaces2    = 0x04,
        eNotchFaces2   = 0x08,
        eLinkFaces     = 0x10,
        eNotchFaces    = 0x20,
        eAuxFaces      = 0x40,
        eExternalFaces = 0x80,
    };

    enum class EType
    {
        eRectangularOld     = 0,  // corner-relief on two adjacent edges of the flange (maybe, plus parallel modifications)
        eGenericRectangular = 1,
        eVType              = 2,
        eCircular           = 3,
        eUndefined          = 4,
    };

    enum class EReferencePointType
    {
        eMiddle  = 0,  //the center is on the intersection of bend lines
        eCorner  = 1,  //the center is determined by 3 points
        eDefault = 2,  //the center will be taken from the features
    };

    BrxSmUnfoldedCornerReliefFeature();
    BrxSmUnfoldedCornerReliefFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedCornerReliefFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedCornerReliefFeature();

    // Constructs a BrxSmUnfoldedCornerReliefFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedCornerRelief Feature
    BrxSmUnfoldedCornerReliefFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedCornerReliefFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedCornerRelief Feature, the instance is empty.
    virtual BrxSmUnfoldedCornerReliefFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedCornerReliefFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedCornerReliefFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedCornerReliefFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // get the unfolded corner relief type for this feature
    virtual Acad::ErrorStatus type(EType& type) const;

    // get the extension value for this feature
    virtual Acad::ErrorStatus getExtensionAbsoluteValue(double& extension) const;

    // get the diameter for this feature (0.0 if the radius is not set or the relief is not circular)
    virtual Acad::ErrorStatus getDiameterAbsoluteValue(double& diameter) const;

    // get the reference point type for this feature (default : eMiddle)
    virtual Acad::ErrorStatus referencePointType(EReferencePointType& refType) const;

    // retrieves the faces of specified type(s) of this unfolded corner relief feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;
};

// SheetMetal UnfoldeForm Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedFormFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces        = 0x0,
        eTopFaces       = 0x1,
        eThicknessFaces = 0x2,
        eBottomFaces    = 0x4
    };

    BrxSmUnfoldedFormFeature();
    BrxSmUnfoldedFormFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedFormFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedFormFeature();

    // Constructs a BrxSmUnfoldedFormFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedForm Feature
    BrxSmUnfoldedFormFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedFormFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedForm Feature, the instance is empty.
    virtual BrxSmUnfoldedFormFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedFormFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedFormFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedFormFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // retrieves whether the form feature is a hole or not
    virtual Acad::ErrorStatus isHole(bool& ishole) const;

    // determines on which side this unfolded form feature lies;
    // true, if on the same side where start face for unfolding
    virtual Acad::ErrorStatus isUpDirection(bool& isUp) const;
 
    // retrieves the IDs of 2D geometry representing the unfolded form feature
    virtual Acad::ErrorStatus wireIds(AcDbObjectIdArray& wires) const;

    // retrieves the faces of specified type(s) of this unfolded form feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;
};

// SheetMetal UnfoldeRib Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedRibFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces     = 0x0,
        eTopFaces    = 0x1,
        eBottomFaces = 0x2
    };

    BrxSmUnfoldedRibFeature();
    BrxSmUnfoldedRibFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedRibFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedRibFeature();

    // Constructs a BrxSmUnfoldedRibFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedRib Feature
    BrxSmUnfoldedRibFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedRibFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedRib Feature, the instance is empty.
    virtual BrxSmUnfoldedRibFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedRibFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedRibFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedRibFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // determines on which side this unfolded rib feature lies;
    // true, if on the same side where start face for unfolding
    virtual Acad::ErrorStatus isUpDirection(bool& isUp) const;
 
    // retrieves the IDs of 2D geometry representing the unfolded rib feature
    virtual Acad::ErrorStatus wireIds(AcDbObjectIdArray& wires) const;

    // retrieves the faces of specified type(s) of this unfolded rib feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;
};

// SheetMetal UnfoldeBevel Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedBevelFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces         = 0x0,
        eFirstSideFaces  = 0x1,
        eOrthogonalFaces = 0x2,
        eSecondSideFaces = 0x4,
    };

    enum class EBevelSense
    {
        eForward  = 1,
        eReversed = 2
    };

    BrxSmUnfoldedBevelFeature();
    BrxSmUnfoldedBevelFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedBevelFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedBevelFeature();

    // Constructs a BrxSmUnfoldedBevelFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedBevel Feature
    BrxSmUnfoldedBevelFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedBevelFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedBevel Feature, the instance is empty.
    virtual BrxSmUnfoldedBevelFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedBevelFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedBevelFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedBevelFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // retrieves the faces of specified type(s) of this unfolded bevel feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;
};

// SheetMetal UnfoldedHem Feature

class BRX_IMPORTEXPORT BrxSmUnfoldedHemFeature : public BrxSmUnfoldedFeature
{
public:
    enum EFaceType
    {
        eNoFaces             = 0x00,
        eBendInternalFaces   = 0x01,
        eBendExternalFaces   = 0x02,
        eFlangeInternalFaces = 0x04,
        eFlangeExternalFaces = 0x08,
    };

    // type of hem feature
    enum class EType
    {
        eNoHem     = 0,
        eClosedHem = 1,
        eOpenHem   = 2,
        eTearDrop  = 3,
        eRound     = 4,
    };

    BrxSmUnfoldedHemFeature();
    BrxSmUnfoldedHemFeature(const BrxIFeature& other);
    virtual BrxSmUnfoldedHemFeature& operator= (const BrxIFeature& other);
    virtual ~BrxSmUnfoldedHemFeature();

    // Constructs a BrxSmUnfoldedHemFeature by given AcDbObjectId;
    // returns an empty instance if the object does not contain an UnfoldedHem Feature
    BrxSmUnfoldedHemFeature(const AcDbObjectId& id);

    // sets this BrxSmUnfoldedHemFeature instance to the given AcDbObjectId;
    // if the specified 'id' does not contain an UnfoldedHem Feature, the instance is empty.
    virtual BrxSmUnfoldedHemFeature& operator= (const AcDbObjectId& id);

    // casting function : returns a BrxSmUnfoldedHemFeature instance, if the queried
    // BrxIFeature object contains a BrxSmUnfoldedHemFeature instance, or an empty instance otherwise
    static BrxSmUnfoldedHemFeature cast(const BrxIFeature& other);

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const;

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const;

    //===== PROPERTIES =====

    // returns the type of this hem feature
    virtual Acad::ErrorStatus hemType(EType& type) const;

    // returns the absolute radius of this hem feature
    virtual Acad::ErrorStatus getRadiusAbsoluteValue(double& radius) const;

    // computes the hem angle in radians, in range (-Pi, Pi);
    // limitation of notation is that it correctly defines angles only for regular hems;
    // for teardrop will return -Pi/2 while swept angle is 3*Pi/2;
    // -Pi/2 will mean to hem only by Pi/2 degrees down the adjacent flange
    // returns the internal hem angle in radians, in range (-Pi, Pi)
    virtual Acad::ErrorStatus getInternalAngle(double& angle) const;

    // computes the swept bend angle in radians, in range (-2*Pi, 2*Pi)
    virtual Acad::ErrorStatus getSweptAngle(double& angle) const;

    // returns the efficient k-Factor used for unfolding
    virtual Acad::ErrorStatus kFactor(double& factor) const;

    // returns the bend lines array associated with this unfolded hem feature
    virtual Acad::ErrorStatus getBendLines(BrxSmUnfoldedBendLinesArray& bendLines) const;

    // retrieves the faces of specified type(s) of this unfolded flange feature;
    // face style flags might be combined (OR'd)
    virtual Acad::ErrorStatus getFaces(AcDbFullSubentPathArray& faces, EFaceType type) const;
};


// SheetMetal Context Object (settings)

class BRX_IMPORTEXPORT BrxSmSheetMetalContext
{
    // ! underlying core data - for internal use only !
    AcDbObjectId  m_idContext;

public:
    enum class ERelationToThicknessType
    {
        eRelative = 0,
        eAbsolute = 1
    };

    enum class ECornerReliefDiameterType
    {
        eAuto     = 0,
        eAbsolute = 1
    };

    enum class EJunctionAlignmentToReliefType
    {
        eDisabled = 0,
        eEnabled  = 1
    };

    enum class ERibFilletRadiusType
    {
        eProfileRatio = 0,
        eAbsolute     = 1
    };

    enum class EFormFeatureUnfoldingMode
    {
        eKeep    = 0,
        eRemove  = 1,
        eProject = 2,
        eContour = 3,
        eSymbol  = 4
    };

    enum class ETabEdgeType
    {
       eSharp   = 0,
       eFillet  = 1,
       eChamfer = 2
    };

    enum class EBevelFeatureUnfoldingMode
    {
        eKeep     = 0,
        eRemove   = 1,
        eAnnotate = 2
    };

    BrxSmSheetMetalContext();
    virtual ~BrxSmSheetMetalContext();

    // returns the object type for this BrxIFeature (or derived) instance
    virtual ESmObjectType objectType() const { return eTypeSmContext; };

    // the BrxSmSheetMetalContext instance is internally open with kForRead mode,
    static BrxSmSheetMetalContext getInstance(const AcDbObjectId& blockId, bool createIfNotExists = false);

    // returns whether 'this' BrxIFeature is a SheetMetal feature
    // (or a BrxIFeature base-class object)
    virtual bool isSheetMetalFeature() const { return false; };

    // verifies whether this BrxSmSheetMetalContext instance is valid (or empty or of wrong type otherwise)
    virtual bool isNull() const;
    // sets this BrxSmSheetMetalContext instance to be empty
    virtual void setNull();

    //===== common options =====

    // get + set the Thickness associated with given Sheet Metal Context in units of the BlockTableRecord;
    virtual double thickness() const;
    virtual Acad::ErrorStatus setThickness(double value);

    //===== BEND LINE related options =====

    // get the bend line type
    virtual ERelationToThicknessType bendLineType() const;

    // get + set the bend line absolute value
    virtual double bendLineAbsoluteValue() const;
    virtual Acad::ErrorStatus setBendLineAbsoluteValue(double value);

    // get + set the bend line ratio
    virtual double bendLineRatio() const;
    virtual Acad::ErrorStatus setBendLineRatio(double value);

    //===== BEND RADIUS related options =====

    // returns the actual type of bend radius, is changed via 'setBendRadiusXxx'
    virtual ERelationToThicknessType bendRadiusType() const;

    // get + set the absolute bend radius
    virtual double bendRadiusAbsoluteValue() const;
    virtual Acad::ErrorStatus setBendRadiusAbsoluteValue(double value);

    // get + set the bend radius ratio
    virtual double bendRadiusRatio() const;
    virtual Acad::ErrorStatus setBendRadiusRatio(double value);

    //===== BEND RADIUS LIMIT related options =====

    virtual ERelationToThicknessType bendRadiusLimitType() const;

    virtual double bendRadiusLimitAbsoluteValue() const;
    virtual Acad::ErrorStatus setBendRadiusLimitAbsoluteValue(double value);

    virtual double bendRadiusLimitRatio() const;
    virtual Acad::ErrorStatus setBendRadiusLimitRatio(double value);

    //===== BEND RELIEF WIDTH related options =====

    // returns the actual type of bend relief width, is changed via 'setBendReliefWidthXxx'
    virtual ERelationToThicknessType bendReliefWidthType() const;

    // get + set the absolute bend relief width
    virtual double bendReliefWidthAbsoluteValue() const;
    virtual Acad::ErrorStatus setBendReliefWidthAbsoluteValue(double value);

    // get + set the bend relief width ratio
    virtual double bendReliefWidthRatio() const;
    virtual Acad::ErrorStatus setBendReliefWidthRatio(double value);

    //===== CORNER RELIEF DIAMETER related options =====

    // get + set the corner relief diameter mode
    virtual ECornerReliefDiameterType cornerReliefDiameterType() const;
    virtual Acad::ErrorStatus setCornerReliefDiameterAutoMode();

    // get + set the corner relief diameter absolute value
    virtual double cornerReliefDiameterAbsoluteValue() const;
    virtual Acad::ErrorStatus setCornerReliefDiameterAbsoluteValue(double value);

    // get + set the corner relief diameter stored absolute value
    virtual double cornerReliefDiameterStoredAbsoluteValue() const;
    virtual Acad::ErrorStatus setCornerReliefDiameterStoredAbsoluteValue(double value);

    //===== RELIEF EXTENSION related options =====

    // get the relief extension type
    virtual ERelationToThicknessType reliefExtensionType() const;

    // get + set the relief extension absolute value
    virtual double reliefExtensionAbsoluteValue() const;
    virtual Acad::ErrorStatus setReliefExtensionAbsoluteValue(double value);

    // get + set the relief extension ratio
    virtual double reliefExtensionRatio() const;
    virtual Acad::ErrorStatus setReliefExtensionRatio(double value);

    //===== MITER GAP related options =====

    // get the miter gap type
    virtual ERelationToThicknessType miterGapType() const;

    // get + set the miter gap absolute value
    virtual double miterGapAbsoluteValue() const;
    virtual Acad::ErrorStatus setMiterGapAbsoluteValue(double value);

    // get + set the miter gap ratio
    virtual double miterGapRatio() const;
    virtual Acad::ErrorStatus setMiterGapRatio(double value);

    //===== MITER EXTENSION related options =====

    // get the miter extension type
    virtual ERelationToThicknessType miterExtensionType() const;

    // get + set the miter extension absolute value
    virtual double miterExtensionAbsoluteValue() const;
    virtual Acad::ErrorStatus setMiterExtensionAbsoluteValue(double value);

    // get + set the miter extension ratio
    virtual double miterExtensionRatio() const;
    virtual Acad::ErrorStatus setMiterExtensionRatio(double value);

    //===== JUNCTION related options =====

    // get the junction gap type
    virtual ERelationToThicknessType junctionGapType() const;

    // get + set the junction gap absolute value
    virtual double junctionGapAbsoluteValue() const;
    virtual Acad::ErrorStatus setJunctionGapAbsoluteValue(double value);

    // get + set the junction gap ratio
    virtual double junctionGapRatio() const;
    virtual Acad::ErrorStatus setJunctionGapRatio(double value);

    // get + set the junction alignment type
    virtual EJunctionAlignmentToReliefType junctionAlignmentToReliefType() const;
    virtual Acad::ErrorStatus setJunctionAlignmentToReliefType(EJunctionAlignmentToReliefType alignmentToReliefType);

    //===== RIB PROFILE related options =====

    //----- rib profile radius related properties

    // get the rib profile radius type
    virtual ERelationToThicknessType ribProfileRadiusType() const;

    // get + set the rib profile absolute radius
    virtual double ribProfileRadiusAbsoluteValue() const;
    virtual Acad::ErrorStatus setRibProfileRadiusAbsoluteValue(double value);

    // get + set the rib profile radius ratio (to thickness)
    virtual double ribProfileRadiusRatio() const;
    virtual Acad::ErrorStatus setRibProfileRadiusRatio(double value);

    //----- rib round radius related properties

    // get + set the rib round radius type
    virtual ERelationToThicknessType ribRoundRadiusType() const;

    // get + set the rib round radius absolute value
    virtual double ribRoundRadiusAbsoluteValue() const;
    virtual Acad::ErrorStatus setRibRoundRadiusAbsoluteValue(double value);

    // get + set the rib round radius ratio (to thickness)
    virtual double ribRoundRadiusRatio() const;
    virtual Acad::ErrorStatus setRibRoundRadiusRatio(double value);

    //----- rib fillet radius To Profile related properties

    // get the rib fillet radius type
    virtual ERibFilletRadiusType ribFilletRadiusType() const;

    // get + set the rib fillet radius absolute value
    virtual double ribFilletRadiusAbsoluteValue() const;
    virtual Acad::ErrorStatus setRibFilletRadiusAbsoluteValue(double value);

    // get + set the global rib fillet radius ratio to rib profile ratio
    virtual double ribFilletRadiusToProfileRatio() const;
    virtual Acad::ErrorStatus setRibFilletRadiusToProfileRatio(double value);

    //===== UNFOLDING related options =====

    // get + set the K factor value
    virtual double kFactorValue() const;
    virtual Acad::ErrorStatus setKFactorValue(double value);

    // get + set the relative path for the bend table file
    virtual const ACHAR* bendTableRelativePath() const;
    virtual Acad::ErrorStatus setBendTableRelativePath(const ACHAR* path);

    // loads the bend table, as previously assigned by 'setBendTableRelativePath()'
    virtual Acad::ErrorStatus loadBendTable(AcStringArray& errorList);

    // deprecated, will be removed in the future; use getAvailableDieWidths()
    Acad::ErrorStatus availableDieWidths(AcArray<double>& dieWidthArray)
    {
        return getAvailableDieWidths(dieWidthArray);
    }

    // get + set the Die width, and the list of available Die widths
    virtual Acad::ErrorStatus getAvailableDieWidths(AcArray<double>& dieWidthArray);

    virtual double dieWidthValue() const;
    virtual Acad::ErrorStatus setDieWidthValue(double value);

    // get + set the form feature unfolding mode
    virtual EFormFeatureUnfoldingMode formFeatureUnfoldingMode() const;
    virtual Acad::ErrorStatus setFormFeatureUnfoldingMode(EFormFeatureUnfoldingMode mode);

    // returns AcDbObjectId used by this context object
    virtual AcDbObjectId objectId() const;

// since V21 begin

    //===== UNFOLDING related options =====

    // get + set the bevel feature unfolding mode
    virtual EBevelFeatureUnfoldingMode bevelFeatureUnfoldingMode() const;
    virtual Acad::ErrorStatus setBevelFeatureUnfoldingMode(EBevelFeatureUnfoldingMode type);

    //===== Lofted bend options =====

    // get + set the number of sample points for lofted bends
    virtual Acad::ErrorStatus loftedBendNumberSamples(int& numSamples) const;
    virtual Acad::ErrorStatus setLoftedBendNumberSamples(int numSamples);

    //===== HEM related options =====

    // returns the HEM gap type
    virtual ERelationToThicknessType hemGapType() const;

    // get + set the HEM gap absolute value
    virtual double hemGapAbsoluteValue() const;
    virtual Acad::ErrorStatus setHemGapAbsoluteValue(double val);

    // get + set the HEM gap ratio
    virtual double hemGapRatio() const;
    virtual Acad::ErrorStatus setHemGapRatio(double val);

    // get + set the HEM relative bend deduction
    virtual double hemRelativeBendDeduction() const;
    virtual Acad::ErrorStatus setHemRelativeBendDeduction(double val);
    
    //===== TAB related options =====

    // get several TAB parameter types
    virtual ERelationToThicknessType tabHeightType() const;
    virtual ERelationToThicknessType tabDistanceType() const;
    virtual ERelationToThicknessType tabLengthType() const;
    virtual ERelationToThicknessType tabClearanceType() const;
    virtual ERelationToThicknessType tabFilletRadiusType() const;
    virtual ERelationToThicknessType tabChamferDistanceType() const;

    // get + set the TAB's slot number
    virtual int tabSlotNumber() const;
    virtual Acad::ErrorStatus setTabSlotNumber(int val);

    // get + set the TAB's absolute height value
    virtual double tabHeightAbsoluteValue() const;
    virtual Acad::ErrorStatus setTabHeightAbsoluteValue(double val);

    // get + set the TAB's height ratio
    virtual double tabHeightRatio() const;
    virtual Acad::ErrorStatus setTabHeightRatio(double val);

    // get + set the TAB's absolute distance value
    virtual double tabDistanceAbsoluteValue() const;
    virtual Acad::ErrorStatus setTabDistanceAbsoluteValue(double val);

    // get + set the TAB's distance ratio
    virtual double tabDistanceRatio() const;
    virtual Acad::ErrorStatus setTabDistanceRatio(double val);

    // get + set the TAB's absolute length value
    virtual double tabLengthAbsoluteValue() const;
    virtual Acad::ErrorStatus setTabLengthAbsoluteValue(double val);

    // get + set the TAB's length ratio
    virtual double tabLengthRatio() const;
    virtual Acad::ErrorStatus setTabLengthRatio(double val);

    // get + set the TAB's absolute clearance value
    virtual double tabClearanceAbsoluteValue() const;
    virtual Acad::ErrorStatus setTabClearanceAbsoluteValue(double val);

    // get + set the TAB's clearance ratio
    virtual double tabClearanceRatio() const;
    virtual Acad::ErrorStatus setTabClearanceRatio(double val);

    // get + set the TAB's edge type
    virtual ETabEdgeType tabEdgeType() const;
    virtual Acad::ErrorStatus setTabEdgeType(ETabEdgeType val);

    // get + set the TAB's absolute radius value
    virtual double tabFilletRadiusAbsoluteValue() const;
    virtual Acad::ErrorStatus setTabFilletRadiusAbsoluteValue(double val);

    // get + set the TAB's radius ratio
    virtual double tabFilletRadiusRatio() const;
    virtual Acad::ErrorStatus setTabFilletRadiusRatio(double val);

    // get + set the TAB's absolute chamfer distance value
    virtual double tabChamferDistanceAbsoluteValue() const;
    virtual Acad::ErrorStatus setTabChamferDistanceAbsoluteValue(double val);

    // get + set the TAB's chamfer distance ratio
    virtual double tabChamferDistanceRatio() const;
    virtual Acad::ErrorStatus setTabChamferDistanceRatio(double val);

// since V21 end
};


// Utility functions to query adjacency

namespace BrxSheetMetal
{

struct BRX_IMPORTEXPORT BrxFaceFeatureAdjacency
{
  BrxFaceFeatureAdjacency();

  // Other face may have several features
  AcDbObjectIdArray m_aOtherFeatureIds;
  AcDbFullSubentPath m_otherFeatureFaceFsp;

  AcDbFullSubentPath m_commonEdgeFsp;
};

struct BRX_IMPORTEXPORT BrxFeatureAdjacency : public BrxFaceFeatureAdjacency
{
  BrxFeatureAdjacency();
  BrxFeatureAdjacency(const BrxFaceFeatureAdjacency & faceAdj,
      const AcDbFullSubentPath & thisFeatureFaceFsp);

  AcDbFullSubentPath m_thisFeatureFaceFsp;

};

using BrxFaceFeatureAdjacencyArray = AcArray<BrxFaceFeatureAdjacency>;
using BrxFeatureAdjacencyArray = AcArray<BrxFeatureAdjacency>;

/**
 * Returns adjacent faces for given feature
 * @param featureId
 *   Feature to get its neighbours
 * @param aFeatureAdjacency
 *   Adjacency data
 * @return
 *   eOk if succeeded
 */
BRX_IMPORTEXPORT Acad::ErrorStatus getAdjacentFeatures(const AcDbObjectId & featureId,
                                                       BrxFeatureAdjacencyArray & aFeatureAdjacency);

/**
 * Returns adjacent faces for given face
 * @param faceId
 *   Face to get its neighbours
 * @param aFaceFeatureAdjacency
 *   Adjacency data
 * @return
 *   eOk if succeeded
 */
BRX_IMPORTEXPORT Acad::ErrorStatus getAdjacentFeatures(const AcDbFullSubentPath & faceFsp,
                                                       BrxFaceFeatureAdjacencyArray & aFaceFeatureAdjacency);

/**
 * Returns adjacent faces for given edge or face
 * @param fsp
 *   Face or edge to get its neighbours
 * @param aAdjacentFaces
 *   Adjacent faces
 * @return
 *   eOk if succeeded
 */
BRX_IMPORTEXPORT Acad::ErrorStatus getAdjacentFaces(const AcDbFullSubentPath & fsp,
                                                    AcDbFullSubentPathArray & aAdjacentFaces);

/**
 * Returns adjacent edges for face
 * @param faceFsp
 *   Face to get its neighbours
 * @param aAdjacentEdges
 *   Adjacent edges
 * @return
 *   eOk if succeeded
 */
BRX_IMPORTEXPORT Acad::ErrorStatus getAdjacentEdges(const AcDbFullSubentPath & faceFsp,
                                                    AcDbFullSubentPathArray & aAdjacentEdges);

}
