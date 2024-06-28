// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD SheetMetal Operations

#include <memory>  // std::shared_ptr
#include <vector>  // std::vector

#include "Misc/MiscGlobal.h"
#include "Misc/AcArray.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbGlobal.h"
#include "AcDb/AcDbFullSubentPath.h"
#include "AcDb/AcDbRegion.h"
#include "AcDb/AcDb3dSolid.h"
#include "AcGe/AcGePoint3d.h"
#include "AcAp/AcApDocument.h"

#include "BrxSpecific/sheetmetal/SheetMetal.h"


// error and warnings reporting
enum EErrorObjectIdent
{
    eObjectNone = 0,
    eObjectId,
    eSubentPath,
    eObjectPtr,
};
struct BrxErrorData
{
    int                 m_errcode = 0;
    bool                m_isWarning = true;
    AcString            m_msgEng;  // actually same as 'm_msgLoc'
    AcString            m_msgLoc;
    EErrorObjectIdent   m_errIdent = eObjectId;
    AcDbObjectId        m_id;
    AcDbFullSubentPath  m_fsp;
    AcDbEntity*         m_entity = nullptr;;
};
typedef AcArray< BrxErrorData, AcArrayObjectCopyReallocator<BrxErrorData> > BrxErrorList;


// ! underlying core data - for internal use only !
#ifndef BRX_API // proxy classes
namespace OdSheetMetal
{
    class IBendCreateOperation {};
    class IConvertOperation {};
    class IDeleteOperation {};
    class IFlangeBaseOperation {};
    class IFlangeBendOperation {};
    class IFlangeConnectOperation {};
    class IFlangeContourOperation {};
    class IFlangeEdgeOperation {};
    class IFlipOperation {};
    class IJunctionCreateOperation {};
    class IJunctionSwitchOperation {};
    class ILoftOperation {};
    //
    class IReliefCreateOperation {};
    class IReliefSwitchOperation {};
    class IRepairOperation {};
    class IRibCreateOperation {};
    class ITabCreateOperation {};
    class ITabEdgeCreateOperation {};
    class IHemCreateOperation {};
    class IExplodeOperation {};
    class ISplitOperation {};
    //
    class IUnfoldGroupAppearance {};
    class IUnfoldAppearance {};
    class IUnfoldOperation {};
    class ISideSelectOperation {};
    class IFeatureValidateOperation {};

    class IAssemblyExportBehaviour {};
    class IAssemblyExportOperation {};
};
#endif


// BRX forwards
class BrxSmAssemblyExportReactor;


//===== SheetMetal Bend Creation  : API analogue of 'SmBendCreate' command =====

class BRX_IMPORTEXPORT BrxSmBendCreator
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IBendCreateOperation>  m_bendCreator = nullptr;
    
public:
    BrxSmBendCreator();
    BrxSmBendCreator(const BrxSmBendCreator& other);
    virtual BrxSmBendCreator& operator= (const BrxSmBendCreator& other);
    virtual ~BrxSmBendCreator();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // sets flange entities which will be analysed for hard edges;
    // found hard edges will be converted to bends
    virtual Acad::ErrorStatus setFlanges(const AcDbObjectIdArray& flangeIds);

    // sets junction entities which will be converted to bends
    virtual Acad::ErrorStatus setJunctions(const AcDbObjectIdArray& junctionIds);

    // deprecated, will be removed in the future; use setSubentPaths()
    Acad::ErrorStatus setSubentPathes(const AcDbFullSubentPathArray& subentPaths)
    {
        return setSubentPaths(subentPaths);
    }

    // sets combined input, defined by sub-entity paths to sub entities;
    // each element can be :
    //    full sub-entity path to hard edge
    //    full sub-entity path to flange   - in this case all hard edges for flange will be treated
    //    full sub-entity path to junction - in this case junction will be converted to bend
    virtual Acad::ErrorStatus setSubentPaths(const AcDbFullSubentPathArray& subentPaths);

    // get + set the radius of the bend feature
    virtual double bendRadius() const;
    virtual Acad::ErrorStatus setBendRadius(double value);

    // creates suggestions (i.e. FullSubentPaths on which bends may be created) on given solids and returns
    // them as array of AcDbFullSubentPathArray, where each AcDbFullSubentPathArray corresponds to one
    // possibly created bend; actually, it is either a hard edge or faces of junction
    //
    static Acad::ErrorStatus createSuggestions(const AcDbObjectIdArray& solids, AcArray<AcDbFullSubentPathArray>& suggestions);

    // main function to perform the bend operation, and uses optional BrxErrorList
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed.
    // if all the messages are warnings, it means the operation finished, but result has to be checked.
    //
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//==== SheetMetal Conversion Operation : API analogue of 'SmConvert' command ===

class BRX_IMPORTEXPORT BrxSmConverter
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IConvertOperation>  m_converter = nullptr;
    
public:
    BrxSmConverter();
    BrxSmConverter(const BrxSmConverter& other);
    virtual BrxSmConverter& operator= (const BrxSmConverter& other);
    virtual ~BrxSmConverter();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // sets the solid entity on which features shall be recognized;
    // note : the solid may already have some features
    virtual Acad::ErrorStatus setSolid(const AcDbObjectId& solidId);

    // sets the faces on which features shall be recognized;
    // allows to recognize features only on given faces of solid (partial recognition);
    // note : the part should already have some SheetMetal features
    virtual Acad::ErrorStatus setFaces(const AcDbFullSubentPathArray& faceIds);

    // set + get the option to refine the flange side, based on heuristics;
    // allows to keep external dimensions of the part during thickness modification
    virtual bool refineFlangeSides() const;
    virtual Acad::ErrorStatus setRefineFlangeSides(bool doRefine);

    // get + set the ratio limit responsible for recognizing feature as a lofted bend;
    // ratio is the relation of the radius to the thickness;
    // at application level 'SmDefaultSharpBendRadiusLimit' controls the default value
    virtual double sharpBendRadiusThicknessRatioLimit() const;
    virtual Acad::ErrorStatus setSharpBendRadiusThicknessRatioLimit(double value);

    // get + set the option, whether path for rib feature will be created;
    // if enabled, the control curve will be recognized for rib feature and added to
    // block table record owning solid
    virtual bool createPathForRibFeature() const;
    virtual Acad::ErrorStatus setCreatePathForRibFeature(bool doCreate);

    // get + set the option, whether form feature recognition will be preferred
    // if enabled, form feature recognition will be preferred over recognition as
    // set of flanges and bends
    virtual bool preferFormFeatureRecognition() const;
    virtual Acad::ErrorStatus setPreferFormFeatureRecognition(bool preferFormFeature);

    // get + set the option, whether hem feature recognition will be preferred over flange and bend
    virtual bool preferHemFeatures() const;
    virtual Acad::ErrorStatus setPreferHemFeatures(bool preferHemFeature);

    // get + set the option, whether zero bend feature recognition will be preferred over wrong bends
    virtual bool preferZeroBendFeatures() const;
    virtual Acad::ErrorStatus setPreferZeroBendFeatures(bool preferZeroBendFeature);

    // get + set the option, whether straight holes will be recognized as hole features
    virtual bool recognizeHoles() const;
    virtual Acad::ErrorStatus setRecognizeHoles(bool enableHoles);

    // get + set the deviation value of wrong feature thickness;
    // depending upon the 'wrongFeatureThicknessDeviationType' value can be interpreted as:
    // - relative to recognized or existing thickness
    // - absolute value in the units of the document
    // Thus features, i.e. flanges, which don't match exact thickness T, but have it in range
    // (-D+T, D+T) for absolute and ( (1.0 - D)*T, (1.0 + D)*T ) for relative
    // will be recognized as wrong flanges;
    // input 'value' has to be non-negative;
    // passing 0.0 will result in neither feature will pass the criteria
    virtual double wrongFeatureThicknessDeviationValue() const;
    virtual Acad::ErrorStatus setWrongFeatureThicknessDeviationValue(double value);

    // get + set the type of deviation of wrong feature thickness (absolute or relative)
    virtual BrxSmSheetMetalContext::ERelationToThicknessType wrongFeatureThicknessDeviationType() const;
    virtual Acad::ErrorStatus setWrongFeatureThicknessDeviationType(BrxSmSheetMetalContext::ERelationToThicknessType deviationType);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed.
    // if all the messages are warnings, it means the operation finished, but result has to be checked.
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//====== SheetMetal Delete Operation : API analogue of 'SmDelete' command ======

class BRX_IMPORTEXPORT BrxSmDelete
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IDeleteOperation>  m_deleter = nullptr;
    
public:
    BrxSmDelete();
    BrxSmDelete(const BrxSmDelete& other);
    virtual BrxSmDelete& operator= (const BrxSmDelete& other);
    virtual ~BrxSmDelete();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // sets the features to be deleted;
    // returns eOk if input is accepted
    virtual Acad::ErrorStatus setFeatures(const AcDbObjectIdArray& features);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//====== SheetMetal FlangeBase Operation : API analogue of 'SmFlangeBase' command ======

class BRX_IMPORTEXPORT BrxSmFlangeBase
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IFlangeBaseOperation>  m_flangeBase = nullptr;
    
public:
    BrxSmFlangeBase();
    BrxSmFlangeBase(const BrxSmFlangeBase& other);
    virtual BrxSmFlangeBase& operator= (const BrxSmFlangeBase& other);
    virtual ~BrxSmFlangeBase();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // sets the planar curves which make one or several closed contours to create
    // the flange by extruding them;
    virtual Acad::ErrorStatus setCurves(const AcDbFullSubentPathArray& curveIds);

    // sets the regions to create the flange by extruding them;
    // regions can be non-database-resident objects;
    virtual Acad::ErrorStatus setRegions(const AcArray<AcDbRegion*>& regions);

    // get + set current value of thickness of the flange to be created from closed polygon
    virtual double            thickness() const;
    virtual Acad::ErrorStatus setThickness(double value);

    // Enum specifying the placement of the flange to be created from closed polygon
    //   eUp     - flange will be created via extrusion of closed polygon along its normal on thickness units
    //   eMiddle - flange will be created via extrusion of closed polygon both along and opposite direction
    //             to its normal on half of the thickness units in each direction
    //   eDown   - flange will be created via extrusion of closed polygon in opposite direction to its normal
    //             on thickness units
    enum class EDirection
    {
      eUp = 0,
      eMiddle,
      eDown
    };
    // get + set direction along the flange will be created
    virtual EDirection        direction() const;
    virtual Acad::ErrorStatus setDirection(EDirection direction);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // returns all the solids created from selected closed polygon
    virtual Acad::ErrorStatus getResult(AcDbObjectIdArray& solidIds);

    // Result generation is split into two stages:
    // 1.  Solid generation, 'getResult()' can be used for preview
    // 2.  Feature generation; at 'applyFeatures()', the 3dSolids returned by 'getResult()'
    //     must be database-resident
    // NOTE : getResult() should be called before applyFeatures()!
    virtual Acad::ErrorStatus applyFeatures();

    // returns new features created by operation; to be called after applyFeatures
    virtual Acad::ErrorStatus createdFeatures(AcDbObjectIdArray& newFeatures) const;
};

//====== SheetMetal FlangeBend Operation : API analogue of 'SmFlangeBend' command ======

class BRX_IMPORTEXPORT BrxSmFlangeBend
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IFlangeBendOperation>  m_flangeBend = nullptr;
    
public:
    BrxSmFlangeBend();
    BrxSmFlangeBend(const BrxSmFlangeBend& other);
    virtual BrxSmFlangeBend& operator= (const BrxSmFlangeBend& other);
    virtual ~BrxSmFlangeBend();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // sets the flange face on which bending line lies;
    // note that this flange face also implicitly defines the sheet metal solid,
    // which will be used in bending operation here;
    // the result of bending operation is not immediately applied to the given solid !
    // the result is applied by explicitly calling 'applyResult' and 'applyFeatures'
    virtual Acad::ErrorStatus setFlangeFace(const AcDbFullSubentPath& flangeFace);

    // defines bending line which must be on the flangeFace
    virtual Acad::ErrorStatus setBendLine(const AcGePoint3d& startPoint, const AcGePoint3d& endPoint);

    // defines the point on solid to determine the side which will be moved during bending
    virtual Acad::ErrorStatus setBendSide(const AcGePoint3d& sidePoint);

    // flips the bending side to opposite
    virtual Acad::ErrorStatus switchBendSide();

    // deprecated, will be removed in the future; use bendAngle()
    double angle() const
    {
        return bendAngle();
    }
    // deprecated, will be removed in the future; use setBendAngle()
    Acad::ErrorStatus setAngle(double value)
    {
        return setBendAngle(value);
    }

    // get + set the bend angle (in radians)
    virtual double bendAngle() const;
    virtual Acad::ErrorStatus setBendAngle(double value);

    // get + set the bend radius (positive)
    virtual double bendRadius() const;
    virtual Acad::ErrorStatus setBendRadius(double value);

    // get + set the K-Factor, that defines position of neutral surface during bending;
    // K-Factor must be in in range [0,1]
    virtual double kFactor() const;
    virtual Acad::ErrorStatus setKFactor(double value);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // applies result of given type to given solid;
    // should be called after successful 'run()' call
    virtual Acad::ErrorStatus applyResult(AcDb3dSolid* pSolid);

    // Result generation is split into two stages:
    // 1. Solid generation, can be used for preview
    // 2. Feature generation, same solid has to be provided as for applyResult()
    //    the result entity has to be already added to database
    // NOTE: applyResult() should be called before applyFeatures()!
    virtual Acad::ErrorStatus applyFeatures(AcDb3dSolid* pSolid);
};

//====== SheetMetal FlangeConnect Operation : API analogue of 'SmFlangeConnect' command ======

class BRX_IMPORTEXPORT BrxSmFlangeConnect
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IFlangeConnectOperation>  m_flangeConnect = nullptr;
    
public:
    BrxSmFlangeConnect();
    BrxSmFlangeConnect(const BrxSmFlangeConnect& other);
    virtual BrxSmFlangeConnect& operator= (const BrxSmFlangeConnect& other);
    virtual ~BrxSmFlangeConnect();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // defines the faces to be connected; currently accepts two thickness faces
    virtual Acad::ErrorStatus setFaces(const AcDbFullSubentPathArray& faceIds);

    // defines the flanges to be connected; provide exactly two flanges
    virtual Acad::ErrorStatus setFlanges(const AcDbObjectIdArray& flangeIds);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // returns new features created by operation; to be called after successful run();
    // the returned array can be empty, if thickness faces already have junction features;
    // in such case, the result of 'modifiedJunctionFeatures()' will be non empty
    virtual Acad::ErrorStatus createdFeatures(AcDbObjectIdArray& createdFeatures) const;

    // returns array of modified junction features; to be called after successful run();
    // array is not empty when junction already exists between connected faces
    virtual Acad::ErrorStatus modifiedJunctionFeatures(AcDbObjectIdArray& modifiedFeatures) const;
};

//====== SheetMetal FlangeContour Operation : API analogue of 'SmFlangeContour' command ======

class BRX_IMPORTEXPORT BrxSmFlangeContour
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IFlangeContourOperation>  m_flangeContour = nullptr;
    
public:
    BrxSmFlangeContour();
    BrxSmFlangeContour(const BrxSmFlangeContour& other);
    virtual BrxSmFlangeContour& operator= (const BrxSmFlangeContour& other);
    virtual ~BrxSmFlangeContour();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // defines the planar curves which make one or several closed contours to create flange by extruding them;
    // currently accepts a single curve;
    virtual Acad::ErrorStatus setCurves(const AcDbFullSubentPathArray& curves);

    // defines the existing flanges to connect new flange with
    virtual Acad::ErrorStatus setFlanges(const AcDbObjectIdArray& flanges);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//====== SheetMetal FlangeEdge Operation : API analogue of 'SmFlangeEdge' command ======

class BRX_IMPORTEXPORT BrxSmFlangeEdge
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IFlangeEdgeOperation>  m_flangeEdge = nullptr;
    
public:
    // when flanges are created with default taper angle, junctions or miters can
    // be automatically created between flanges next to each other;
    // this enum allows to specify the required behavior :
    //   eAuto   - junctions and miters will be only created to avoid self-intersections
    //   eAlways - junctions and miters will be always created between adjacent flanges when possible
    enum class EConnectionType
    {
        eAuto = 0,
        eAlways
    };

    // controls whether operation cuts new flanges during creation, when multiple edges are in the input
    enum class EAutoTaperMode
    {
        eDisabled = 0,
        eSmart    = 1, // only when angle is less or equal 90 degrees
        eAlways   = 2
    };

    BrxSmFlangeEdge();
    BrxSmFlangeEdge(const BrxSmFlangeEdge& other);
    virtual BrxSmFlangeEdge& operator= (const BrxSmFlangeEdge& other);
    virtual ~BrxSmFlangeEdge();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // defines the edges to create new flanges from; all edges should belong to the same solid
    virtual Acad::ErrorStatus setEdges(const AcDbFullSubentPathArray& edgeIds);

    // deprecated, will be removed in the future; use bendAngle()
    double angle() const
    {
        return bendAngle();
    }
    // deprecated, will be removed in the future; use setBendAngle()
    Acad::ErrorStatus setAngle(double value)
    {
        return setBendAngle(value);
    }

    // get + set the required swept angle, in radians; which can be considered as
    // angle on which cylindrical face spreads on its cylindrical surface
    // if angle is PI/2 (90 degrees), straight angle is built;
    // for PI (180 degrees) hem is built; for 3*PI/2 (270 degrees) - tear drop 
    // angle must be positive. Negative angles will lead to operation failure
    // for multiple input, the same angle is used for all new flanges.
    virtual double            bendAngle() const;
    virtual Acad::ErrorStatus setBendAngle(double value);

    // get + set the height for new flanges (must be positive);
    // value is in current drawing unit
    virtual double            height() const;
    virtual Acad::ErrorStatus setHeight(double value);

    // get + set the relative offset for the left side of the new flange, from the
    // left point of the edge; default value is 0.0;
    // it must be less than the rightRelOffset;
    // negative value mean that the length of the flange will be greater than the
    // length of the edge; it is not advised to use negative offsets as it can lead
    // to self intersections.
    // NOTE: offsets are not supported for multiple input
    virtual double            leftRelOffset() const;
    virtual Acad::ErrorStatus setLeftRelOffset(double value);

    // get + set the relative offset for the right side of the new flange, from the
    // left point of the edge; default value is 1.0;
    // it must be greater than the leftRelOffset;
    // negative value mean that the length of the flange will be greater than the
    // length of the edge; it is not advised to use negative offsets as it can lead
    // to self intersections.
    // NOTE : offsets are not supported for multiple input
    virtual double            rightRelOffset() const;
    virtual Acad::ErrorStatus setRightRelOffset(double value);

    // get + set the taper angle at the left side of the edge;
    // taper angle is measured from the line orthogonal to the edge;
    // NOTE : taper angles are not supported for multiple inputs;
    // angle can be positive or negative, but must follow the condition :
    // -Pi/2 < angle < Pi/2. Default value is 0.
    virtual double            leftTaperAngle() const;
    virtual Acad::ErrorStatus setLeftTaperAngle(double value);

    // get + set the taper angle at the right side of the edge
    // taper angle is measured from the line orthogonal to the edge.
    // NOTE : taper angles are not supported for multiple inputs
    // angle can be positive or negative, but must follow the condition :
    // -Pi/2 < angle < Pi/2. Default value is 0.
    virtual double            rightTaperAngle() const;
    virtual Acad::ErrorStatus setRightTaperAngle(double value);

    // get + set the bend radius
    virtual double            bendRadius() const;
    virtual Acad::ErrorStatus setBendRadius(double value);

    // get + set the minimal gap value between the base flange and the new flange;
    // this value is used to limit the angle of the new flange to avoid self-intersections;
    // NOTE : that the gap between new flanges is controlled by either junction or miter gaps
    virtual double            minimalBaseFlangeNewFlangeGap() const;
    virtual Acad::ErrorStatus setMinimalBaseFlangeNewFlangeGap(double value);

    // get + set the connection type between adjacent flanges;
    // adjacent flanges can be connected by either miter or junction if they have default
    // taper angles and offsets from their respective closest sides;
    // NOTE : this mode will be taken into account only in multiple input case
    virtual EConnectionType   connectionType() const;
    virtual Acad::ErrorStatus setConnectionType(EConnectionType requiredConnection);

    // get + set the mode for automatic tapering;
    // if enabled, the taper angles of the new flanges will be adjusted to match the shape of the
    // base flange when possible;
    // auto-tapering will be used only if the corresponding taper angle is not set;
    //   eDisabled - disables auto tapering
    //   eSmart - the auto tapering will be applied only if the corresponding angle of the
    //            base flange is <= 90 degrees
    //   eAlways - the auto tapering will be applied when the corresponding angle of the
    //             base flange is not 0 or 180 degrees
    virtual EAutoTaperMode autoTaperingMode() const;
    virtual Acad::ErrorStatus setAutoTaperingMode(EAutoTaperMode mode);

    // enables or disables the forced no-relief-mode for junctions created by this operation;
    // if true, all junctions made by this operation will be forced to no relief configuration;
    // if false, the global setting will be used;
    virtual bool isNoReliefJunctionsForced() const;
    virtual Acad::ErrorStatus forceNoReliefJunctions(bool forceNoReliefs);

    // verifies whether the height is valid; to be valid, height must be positive
    virtual bool isHeightValid() const;

    // verifies whether the angle is valid, matching the condition : 0 < angle < 2 * Pi
    virtual bool isAngleValid() const;

    // verifies whether the left taper angle is valid, matching the condition : -Pi/2 < angle < Pi/2
    virtual bool isLeftTaperAngleValid() const;

    // verifies whether the right taper angle is valid, matching the condition : -Pi/2 < angle < Pi/2
    virtual bool isRightTaperAngleValid() const;

    // verifies whether the left relative offset is valid;
    // it must be less than 1.0 and less than the right relative offset
    virtual bool isLeftRelOffsetValid() const;

    // verifies whether the right relative offset is valid;
    // It must be greater than 0.0 and greater than the left relative offset
    virtual bool isRightRelOffsetValid() const;

    // verifies whether the bend radius is valid; must be positive.
    virtual bool isBendRadiusValid() const;

    // verifies whether the parameters of the operation are valid.
    // NOTE : this does not guarantee that it is possible to make such flanges,
    // only that given values of parameters are in valid range
    virtual bool areParametersValid() const;

    // calculates the maximum angle for the given parameters in radians;
    // height is an optional parameter, if not given, the angle will be computed using
    // the maximum possible height for the case
    virtual double computeMaximumAngle(double bendRadius, double sheetThickness, double height = 0.0) const;

    // calculates the minimum possible height for given thickness, bend radius and angle;
    // as the height of the flange is measured from the base point which is in the
    // base flange plane, its height must be sufficient to fit a bend.
    virtual double computeMinimumHeight(double bendRadius, double bendAngle, double thickness) const;

    // calculates the maximum possible height of the flange for given parameters
    // taper angles are in radians for left side of the new flange
    virtual double computeMaximumHeight(double bendRadius,
                                        double bendAngle,
                                        double bodyThickness,
                                        double leftTaperAngle,
                                        double rightTaperAngle,
                                        double flangeWidth) const;

    // calculates base point coordinates
    // - base point is the intersection point of the line, coplanar with the
    //   bottom sheet face and orthogonal to the bending axis, and the line, which
    //   is coplanar with the flange bottom sheet face and orthogonal to the bending
    //   axis (in case of the bend angles, less then PI/2.0). In case of the bend
    //   angles from the interval [PI/2.0, PI], the base point is the point of tangency
    //   between the bending surface and the plane, parallel to the top side face
    //   of the newly created flange
    // - It is assumed that the coordinate system has an origin in the flange edge
    //   starting point and it's Z-axis is parallel to the bend direction and
    //   X-axis is parallel to the side face normal (this side face shares the flange
    //   edge with the sheet face)
    virtual AcGePoint3d computeBasePoint(double bendRadius, double sheetThickness, double bendAngle) const;

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // applies result of given type to given solid;
    // should be called after successful 'run()' call
    // NOTE : for performance reason, the result is moved to the provided solid;
    //        therefore, it is not possible to apply the same result twice !
    virtual Acad::ErrorStatus applyResult(AcDb3dSolid* pSolid);

    // Result generation is split into two stages:
    // 1. Solid generation, can be used for preview
    // 2. Feature generation, same solid has to be provided as for applyResult()
    //    the result entity has to be already added to database
    // NOTE: applyResult() should be called before applyFeatures()!
    virtual Acad::ErrorStatus applyFeatures(AcDb3dSolid* pSolid);

    // creates suggestions (i.e. end edge AcDbFullSubentPath similar to provided one) for given
    // AcDbFullSubentPath of end edge and returns them as an array of AcDbFullSubentPathArray, where
    // each AcDbFullSubentPath corresponds to one end for which flange edge operation could be applied
    // endEdgeFsp - AcDbFullSubentPath of end edge
    // shortEdgeThicknessFactor - if edge is smaller than (edge thickness * shortEdgeThicknessFactor),
    //                            then this edges will be omitted; negative value means 'use default value'
    static Acad::ErrorStatus createSuggestions(const AcDbFullSubentPath& endEdgeFsp,
                                               double shortEdgeThicknessFactor,
                                               AcArray<AcDbFullSubentPathArray>& suggestions);
};

//====== SheetMetal FlangeFlip Operation : API analogue of 'SmFlip' command ======

class BRX_IMPORTEXPORT BrxSmFlangeFlip
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IFlipOperation>  m_flangeFlip = nullptr;
    
public:
    BrxSmFlangeFlip();
    BrxSmFlangeFlip(const BrxSmFlangeFlip& other);
    virtual BrxSmFlangeFlip& operator= (const BrxSmFlangeFlip& other);
    virtual ~BrxSmFlangeFlip();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // defines the flanges to be flipped
    virtual Acad::ErrorStatus setFlanges(const AcDbObjectIdArray& flangeIds);

    // defines whether the flange(s) shall to be shifted after side flip
    // if true, geometry of given flange(s) will be shifted
    // if false, geometry will remain unchanged and only bottom faces will be switched with top ones
    virtual bool              allowRebuildGeometry() const;
    virtual Acad::ErrorStatus setAllowRebuildGeometry(bool allowRebuild);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//====== SheetMetal Junction Create Operation : API analogue of 'SmJunctionCreate' command ======

class BRX_IMPORTEXPORT BrxSmJunctionCreator
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IJunctionCreateOperation>  m_junctionCreator = nullptr;
    
public:
    BrxSmJunctionCreator();
    BrxSmJunctionCreator(const BrxSmJunctionCreator& other);
    virtual BrxSmJunctionCreator& operator= (const BrxSmJunctionCreator& other);
    virtual ~BrxSmJunctionCreator();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // get + set the option to heal coincident flange faces by creating hard edges from them
    virtual bool healCoincidence() const;
    virtual Acad::ErrorStatus setHealCoincidence(bool enableHealing);

    // specifies the edges, faces and solids, on which junctions will be created;
    // the array may contain the sub-entity paths for
    //   a) hard edges : instead of hard edges junctions will be created
    //   b) bend or lofted bend faces : instead of bends junctions will be created
    //   c) flange faces : all the hard edges adjacent to given flange will be converted to junctions
    //   d) solids : all the hard edges of given solid will be converted to junctions
    virtual Acad::ErrorStatus setEntities(const AcDbFullSubentPathArray& entityIds);

    // creates suggestions (i.e. FullSubentPaths on which junctions may be created) on given solids and returns
    // them as array of AcDbFullSubentPathArray, where each AcDbFullSubentPathArray corresponds to one
    // possibly created junction; actually, it is either a hard edge or faces of bend
    static Acad::ErrorStatus createSuggestions(const AcDbObjectIdArray& solids, AcArray<AcDbFullSubentPathArray>& suggestions);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//====== SheetMetal Junction Switch Operation : API analogue of 'SmJunctionSwitch' command ======

class BRX_IMPORTEXPORT BrxSmJunctionSwitcher
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IJunctionSwitchOperation>  m_junctionSwitcher = nullptr;
    
public:
    BrxSmJunctionSwitcher();
    BrxSmJunctionSwitcher(const BrxSmJunctionSwitcher& other);
    virtual BrxSmJunctionSwitcher& operator= (const BrxSmJunctionSwitcher& other);
    virtual ~BrxSmJunctionSwitcher();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // specifies junction faces which junction type will be switched from symmetrical to aligned and vice versa;
    // when the junction is switched from symmetrical, selected junction faces will be pulled until it becomes
    // aligned with adjacent flange;
    // passing two faces of the same junction causes ambiguous behavior : any of the chosen faces may be pulled;
    // however, this selection is assumed to be valid.
    virtual Acad::ErrorStatus setJunctionFaces(const AcDbFullSubentPathArray& faceIds);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//======== SheetMetal Loft Operation : API analogue of 'SmLoft' command ========

class BRX_IMPORTEXPORT BrxSmLofter
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::ILoftOperation>  m_lofter = nullptr;
    
public:
    //Enum responsible for thicken type when creating loft
    //  eInside  - thicken operation applied to sheet body will be made
    //             along the normal direction on thickness units
    //  eBoth    - thicken operation applied to sheet body will be made
    //             in both directions on half of thickness units
    //  eOutside - thicken operation applied to sheet body will be made
    //             opposite to the normal direction on thickness units
    //
    enum ELoftThickenType
    {
        eInside = 0,
        eBoth,
        eOutside,
    };

    BrxSmLofter();
    BrxSmLofter(const BrxSmLofter& other);
    virtual BrxSmLofter& operator= (const BrxSmLofter& other);
    virtual ~BrxSmLofter();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // defines the curves to create lofted geometry using them as guide curves;
    // currently accepts two curves;
    virtual Acad::ErrorStatus setCurves(const AcDbFullSubentPathArray& curveIds);

    // get + set the type of 'thickness' processing
    virtual ELoftThickenType  thickenType() const;
    virtual Acad::ErrorStatus setThickenType(ELoftThickenType thickenType);

    // get the effective fillet radius set after successful run
    virtual double            filletRadius() const;
    // set the desired fillet radius to be used
    virtual Acad::ErrorStatus setFilletRadius(double value);

    // get + set the thickness of the lofts to be created
    virtual double            thickness() const;
    virtual Acad::ErrorStatus setThickness(double value);

    // get + set the option to create lofts with or without flanges
    virtual bool              simpleLoft() const;
    virtual Acad::ErrorStatus setSimpleLoft(bool createSimpleLofts);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // applies result of given type to given solid;
    // should be called after successful 'run()' call
    // NOTE : for performance reason, the result is moved to the provided solid;
    //        therefore, it is not possible to apply the same result twice !
    virtual Acad::ErrorStatus applyResult(AcDb3dSolid* pSolid);

    // Result generation is split into two stages:
    // 1. Solid generation, can be used for preview
    // 2. Feature generation, same solid has to be provided as for applyResult()
    //    the result entity has to be already added to database
    // NOTE: applyResult() should be called before applyFeatures()!
    virtual Acad::ErrorStatus applyFeatures(AcDb3dSolid* pSolid);
};

//=== SheetMetal Relief Creation : API analogue of 'SmReliefCreate' command ====

class BRX_IMPORTEXPORT BrxSmReliefCreator
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IReliefCreateOperation>  m_reliefCreator = nullptr;
    
public:
    BrxSmReliefCreator();
    BrxSmReliefCreator(const BrxSmReliefCreator& other);
    virtual BrxSmReliefCreator& operator= (const BrxSmReliefCreator& other);
    virtual ~BrxSmReliefCreator();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // get + set the option whether created reliefs may spoil adjacent features
    virtual bool              avoidAdjacentFeaturesInBendReliefs() const;
    virtual Acad::ErrorStatus setAvoidAdjacentFeaturesInBendReliefs(bool avoid);

    // get + set the option whether reliefs will be created on sharp bends;
    // sets whether reliefs will be created on bends with radius greater than the sharp bend radius limit
    virtual bool              detectSharpBends() const;
    virtual Acad::ErrorStatus setDetectSharpBends(bool detectSharpBends);

    // get + set the relief size, as ratio to bend radius value
    virtual double            reliefSizeRatio() const;
    virtual Acad::ErrorStatus setReliefSizeRatio(double value);

    // get + set the option, whether bend relief creation is enforced
    virtual bool              forceBendReliefs() const;
    virtual Acad::ErrorStatus setForceBendReliefs(bool forceReliefs);

    // defines the adjacent entities, for which reliefs will be created;
    // possible inputs are:
    //   a) one flange face fsp
    //   b) one or two bend or wrong bend faces or hard edges
    virtual Acad::ErrorStatus setAdjacentEntities(const AcDbFullSubentPathArray& entities);

    // defines the 3dSolid entities set, where all the possible reliefs will be created on
    virtual Acad::ErrorStatus setSolids(const AcDbObjectIdArray& solids);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//=== SheetMetal Relief Switch : API analogue of 'SmReliefSwitch' command ====

class BRX_IMPORTEXPORT BrxSmReliefSwitcher
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IReliefSwitchOperation>  m_reliefSwitcher = nullptr;
    
public:
    // Enum defining the shape of changed relief
    //    eRectangular - both corner and bend reliefs will be switched to rectangular
    //    eVType       - bend reliefs will not be switched. Corner reliefs will be switched to V-shape reliefs
    //    eCircular    - bend reliefs will not be switched. Corner reliefs will be switched to circular
    //    eRound       - corner reliefs will not be switched. Bend reliefs will be switched to round
    //    eSmooth      - corner reliefs will not be switched. Bend reliefs will be switched to smooth
    //    eRip         - corner reliefs will not be switched. Bend reliefs will be switched to rip
    enum EReliefType
    {
        eRectangular = 0x01,
        eVType       = 0x02,
        eCircular    = 0x04,
        eRound       = 0x08,
        eSmooth      = 0x10,
        eRip         = 0x20,
        eUndefined   = 0x40,
    };

    // Enum defining where the center of corner relief will be located
    //    eMiddle  - the center is on the intersection of bend lines
    //    eCorner  - the center is determined by 3 points
    //    eDefault - the center will be taken from the features
    enum EReferencePointType
    {
        eMiddle = 0,
        eCorner,
        eDefault,
    };

    BrxSmReliefSwitcher();
    BrxSmReliefSwitcher(const BrxSmReliefSwitcher& other);
    virtual BrxSmReliefSwitcher& operator= (const BrxSmReliefSwitcher& other);
    virtual ~BrxSmReliefSwitcher();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // get + set the current relief diameter value
    virtual double            reliefDiameter() const;
    virtual Acad::ErrorStatus setReliefDiameter(double value);

    // get + set the current relief extension value
    virtual double            reliefExtension() const;
    virtual Acad::ErrorStatus setReliefExension(double value);

    // get + set the target relief type, the specified reliefs will be switched to
    virtual EReliefType       reliefType() const;
    virtual Acad::ErrorStatus setReliefType(EReliefType reliefType);

    // get + set the reference point type for corner relief features
    virtual EReferencePointType referencePointType() const;
    virtual Acad::ErrorStatus   setReferencePointType(EReferencePointType referencePointType);

    // defines the relief features (sub-entities) that will be switched
    virtual Acad::ErrorStatus setReliefFeaturePaths(const AcDbFullSubentPathArray& reliefPaths);

    // defines the entities that will be switched
    // given solids will be switched
    virtual Acad::ErrorStatus setReliefFeatureEntities(const AcDbObjectIdArray& featureEntities);

    // defines the 3dSolid entities set, from which all the reliefs that belong to
    // given solids will be switched
    virtual Acad::ErrorStatus setSolidsWithReliefs(const AcDbObjectIdArray& solidIds);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//===== SheetMetal Repair Operations : API analogue of 'SmRepair' command ======

class BRX_IMPORTEXPORT BrxSmRepair
{
    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IRepairOperation>  m_repair = nullptr;
    
public:
    BrxSmRepair();
    BrxSmRepair(const BrxSmRepair& other);
    virtual BrxSmRepair& operator= (const BrxSmRepair& other);
    virtual ~BrxSmRepair();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // get + set the option, whether to merge lofts
    virtual bool              mergeLofts() const;
    virtual Acad::ErrorStatus setMergeLofts(bool mergeLofts);

    // sometimes after healing, some significant pieces of initial body are remaining;
    // by default, operation doesn't search for it, but it may search all the left out
    // bodies with volume > smallBodyVolumeRatioThreshold * initialVolume;
    // if volume of left out bodies is less than smallBodyVolumeRatioThreshold * bodyVolume,
    // bodies will be erased;
    // using negative input value means that left out bodies will not be built;
    virtual bool              buildLeftOutBodies(double& bodyVolumeRatioThreshold) const;
    virtual Acad::ErrorStatus setBuildLeftOutBodies(double bodyVolumeRatioThreshold);

    // the repair operation expects to receive a single face related to flange
    // or lofted bend feature; the side will be used as primary during thickness repairing;
    // repair operation accepts exactly one of these inputs types :
    // - flange or lofted bend face, wrong bend face
    // - or hard edge for local repair
    // another call to 'setSideFace()' will just erase previous set
    virtual Acad::ErrorStatus setSideFace(const AcDbFullSubentPath& face);

    // this function defines the entity set used by the local repair :
    // either one wrong bend feature to repair, or arbitrary number of
    // thickness faces of flange, so they will be locally orthogonalized,
    // or edges adjacent to thickness faces of flange and flange.
    // This edge will determine flange side to use for local repair;
    // flange faces - will repair only thickness faces adjacent to given flange
    virtual Acad::ErrorStatus setEntitiesForLocalRepair(const AcDbFullSubentPathArray& entitySet);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // to be called after successful run, if setBuildLeftOutBodies was called and succeeded;
    // returns the array of non-database-resident 3dSolid entities, representing the
    // difference between original and healed 3dSolid
    virtual Acad::ErrorStatus getLeftOutBodies(AcArray<AcDbEntity*>& leftOutBodies);
};

//======= SheetMetal Rib Create : API analogue of 'SmRibCreate' command ========

class BRX_IMPORTEXPORT BrxSmRibCreator
{
    std::shared_ptr<OdSheetMetal::IRibCreateOperation>  m_ribCreator = nullptr;
    
public:
    BrxSmRibCreator();
    BrxSmRibCreator(const BrxSmRibCreator& other);
    virtual BrxSmRibCreator& operator= (const BrxSmRibCreator& other);
    virtual ~BrxSmRibCreator();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // get + set the intended profile radius (must be positive)
    virtual double            profileRadius() const;
    virtual Acad::ErrorStatus setProfileRadius(double value);

    // get + set the intended round radius (must be non-negative)
    virtual double            roundRadius() const;
    virtual Acad::ErrorStatus setRoundRadius(double value);

    // defines the flange face, on which rib features will be created
    virtual Acad::ErrorStatus setFlangeFace(const AcDbFullSubentPath& face);

    // defines the curve entities set, which rib features will be made of
    virtual Acad::ErrorStatus setCurveEntities(const AcDbFullSubentPathArray& curveIds);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//======= SheetMetal Tab Create : API analogue of 'SmTabCreate' command ========

class BRX_IMPORTEXPORT BrxSmTabCreator
{
    std::shared_ptr<OdSheetMetal::ITabCreateOperation>  m_tabCreator = nullptr;
    
public:
    // determines whether operation has to build single or multiple tab
    enum class ETabType
    {
        eSingle = 0,
        eArray  = 1,
    };

    // determines the overlapping type
    enum class ETabOverlappingType
    {
        eNoOverlap          = 0,
        eFull               = 1,
        eFirstSidedPartial  = 2,
        eSecondSidedPartial = 3,
    };

    // determines whether the center position will be tab or slot
    enum class ETabPlacement
    {
        eSymmetricTabInCenter  = 0,
        eSymmetricSlotInCenter = 1,
        eNotDefined            = 2,
    };

    BrxSmTabCreator();
    BrxSmTabCreator(const BrxSmTabCreator& other);
    virtual BrxSmTabCreator& operator= (const BrxSmTabCreator& other);
    virtual ~BrxSmTabCreator();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // get + set the tab type to be created
    virtual ETabType          tabType() const;
    virtual Acad::ErrorStatus setTabType(ETabType tabType);

    // get + set the tab overlapping type
    virtual ETabOverlappingType tabOverlappingType() const;
    virtual Acad::ErrorStatus   setTabOverlappingType(ETabOverlappingType type);

    // get + set the tab placement type;
    // setting the tab placement only works for the array tab type;
    virtual ETabPlacement     tabPlacement() const;
    virtual Acad::ErrorStatus setTabPlacement(ETabPlacement placement);

    // get + set the current central point;
    // setting the central point only works for the single tab configuration
    virtual AcGePoint3d       centralPoint() const;
    virtual Acad::ErrorStatus setCentralPoint(const AcGePoint3d& pt);

    // get + set the number of slots;
    // setting the number of slots only works for the array tab configuration
    virtual int               slotNumber() const;
    virtual Acad::ErrorStatus setSlotNumber(int slotNumber);

    // get + set the height of the tab
    virtual double            height() const;
    virtual Acad::ErrorStatus setHeight(double height);

    // get + set the distance of the tab
    virtual double            distance() const;
    virtual Acad::ErrorStatus setDistance(double distance);

    // get + set the length of the tab
    virtual double            length() const;
    virtual Acad::ErrorStatus setLength(double length);

    // get + set the clearance of the tab
    virtual double            clearance() const;
    virtual Acad::ErrorStatus setClearance(double clearance);

    // get + set the fillet radius of the tab
    virtual double            filletRadius() const;
    virtual Acad::ErrorStatus setFilletRadius(double radius);

    // get + set the chamfer distance of the tab
    virtual double chamferDistance() const;
    virtual Acad::ErrorStatus setChamferDistance(double distance);

    // sets the junction feature to create tabs from
    virtual Acad::ErrorStatus setJunction(const AcDbObjectId& junctionId);

    // sets the face of junction or bend feature;
    virtual Acad::ErrorStatus setFace(const AcDbFullSubentPath& face);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//======= SheetMetal TabEdge Create : API analogue of 'SmTabCreate' command for curved tabs ========

class BRX_IMPORTEXPORT BrxSmTabEdgeCreator
{
    std::shared_ptr<OdSheetMetal::ITabEdgeCreateOperation>  m_tabEdgeCreator = nullptr;
    
public:
    enum class ECurvedTabArrayMode
    {
        eLengthNumber         = 0,  // the distance is calculated automatically (ignoring value by the set method)
        eLengthNumberDistance = 1,  // all parameters to be given explicitly
        eLengthDistance       = 2,  // the number is calculated automatically (ignoring value by the set method)
    };

    // tab placement determines whether center position will be tab or slot
    enum class ETabPlacement
    {
        eSymmetricTabInCenter  = 0,
        eSymmetricSlotInCenter = 1,
        eNotDefined            = 02,
    };

    BrxSmTabEdgeCreator();
    BrxSmTabEdgeCreator(const BrxSmTabEdgeCreator& other);
    virtual BrxSmTabEdgeCreator& operator= (const BrxSmTabEdgeCreator& other);
    virtual ~BrxSmTabEdgeCreator();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // defines the hard edge 
    virtual Acad::ErrorStatus setEdge(const AcDbFullSubentPath& edge);

    // defines the mode to split the curved edge into tabs and slots regions
    virtual Acad::ErrorStatus setTabArrayControlMode(ECurvedTabArrayMode mode);

    // get + set the parameter for the tab's central point on the edge
    virtual Acad::ErrorStatus centralPointParameter(double& param) const;
    virtual Acad::ErrorStatus setCentralPointParameter(double param);

    // get + set the current tab placement type
    virtual Acad::ErrorStatus tabPlacement(ETabPlacement& placement) const;
    virtual Acad::ErrorStatus setTabPlacement(ETabPlacement placement);

    // get + set the current number of slots
    // setting the number of slots only works for the array tab configuration
    virtual Acad::ErrorStatus slotNumber(int& slotNumber) const;
    virtual Acad::ErrorStatus setSlotNumber(int slotNumber);

    // get + set the current height of the tab
    virtual Acad::ErrorStatus height(double& value) const;
    virtual Acad::ErrorStatus setHeight(double value);

    // get + set the current distance of the tab
    virtual Acad::ErrorStatus distance(double& value) const;
    virtual Acad::ErrorStatus setDistance(double value);

    // get + set the current length of the tab
    virtual Acad::ErrorStatus length(double& value) const;
    virtual Acad::ErrorStatus setLength(double value);

    // get + set the current clearance of the tab
    virtual Acad::ErrorStatus clearance(double& value) const;
    virtual Acad::ErrorStatus setClearance(double value);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//======= SheetMetal Hem Create : API analogue of 'SmHemCreatee' command ========

class BRX_IMPORTEXPORT BrxSmHemCreator
{
    std::shared_ptr<OdSheetMetal::IHemCreateOperation>  m_hemCreator = nullptr;
    
public:
    enum class EHemType
    {
        eUndefinedHem = 0,
        eClosedHem    = 1,
        eOpenHem      = 2,
        eTearDrop     = 3,
        eRound        = 4
    };

    BrxSmHemCreator();
    BrxSmHemCreator(const BrxSmHemCreator& other);
    virtual BrxSmHemCreator& operator= (const BrxSmHemCreator& other);
    virtual ~BrxSmHemCreator();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // defines the array of edges to create new hems on it; all edges should belong to the same solid;
    // should be called before any other setter.
    virtual Acad::ErrorStatus setEdges(const AcDbFullSubentPathArray& edgeArray);

    // get + set the current type of hem feature to be created; to be called after successful setEdges() call
    virtual Acad::ErrorStatus hemType(EHemType& type) const;
    virtual Acad::ErrorStatus setHemType(EHemType type);

    // get the value of the required swept angle for the bend in radians
    virtual Acad::ErrorStatus bendAngle(double& angle) const;

    // get + set the length of the hem to be created; to be called after successful setEdges() call
    virtual Acad::ErrorStatus length(double& value) const;
    virtual Acad::ErrorStatus setLength(double value);

    // get + set the relative offset of the left side of the new flange from the left point of the edge;
    // default value is 0.0;
    // it must be less than the right side relative offset;
    // relative offset is the fraction of the current edge length;
    // negative values mean that the length of the flange will be greater than the length of the edge;
    // it is not advised to use negative offsets as it can lead to self intersections.
    // NOTE: offsets are not supported for multiple input
    virtual Acad::ErrorStatus leftRelOffset(double& offset) const;
    virtual Acad::ErrorStatus setLeftRelOffset(double offset);

    // get + set the relative offset of the right side of the new flange from the left point of the edge;
    // default value is 1.0;
    // it must be greater than the left side relative offset;
    // relative offset is the fraction of the current edge length;
    // negative values mean that the length of the flange will be greater than the length of the edge;
    // it is not advised to use negative offsets as it can lead to self intersections.
    // NOTE: offsets are not supported for multiple input
    virtual Acad::ErrorStatus rightRelOffset(double& offset) const;
    virtual Acad::ErrorStatus setRightRelOffset(double offset);

    // get + set the taper angle at the left side of the edge;
    // taper angle is measured from the line orthogonal to the edge;
    // default value is 0.0;
    // angle can be positive or negative, but must satisfy the condition : -Pi/2 < angle < Pi/2
    virtual Acad::ErrorStatus leftTaperAngle(double& angle) const;
    virtual Acad::ErrorStatus setLeftTaperAngle(double angle);

    // get + set the taper angle at the right side of the edge;
    // taper angle is measured from the line orthogonal to the edge;
    // default value is 0.0;
    // angle can be positive or negative, but must satisfy the condition : -Pi/2 < angle < Pi/2
    virtual Acad::ErrorStatus rightTaperAngle(double& angle) const;
    virtual Acad::ErrorStatus setRightTaperAngle(double angle);

    // get + set the bend radius in the units of WCS
    virtual Acad::ErrorStatus bendRadius(double& radius) const;
    virtual Acad::ErrorStatus setBendRadius(double radius);

    // calculates the maximum angle for the given hem parameters, respecting length semantics for each hem type;
    // applies to round and tear drop hems
    virtual Acad::ErrorStatus computeMaximalAngle(double& angle, double bendRadius,
                                                  double sheetThickness, double requestedHemLength = 0.0) const;

    // calculates the base point for hems, specified specified parameters
    virtual Acad::ErrorStatus computeBasePoint(AcGePoint3d& basePoint, double bendRadius,
                                               double sheetThickness, double bendAngle) const;

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // applies result of given type to given solid;
    // should be called after successful 'run()' call
    // NOTE : for performance reason, the result is moved to the provided solid;
    //        therefore, it is not possible to apply the same result twice !
    virtual Acad::ErrorStatus applyResult(AcDb3dSolid* pSolid);

    // Result generation is split into two stages:
    // 1. Solid generation, can be used for preview
    // 2. Feature generation, same solid has to be provided as for applyResult()
    //    the result entity has to be already added to database
    // NOTE: applyResult() should be called before applyFeatures()!
    virtual Acad::ErrorStatus applyFeatures(AcDb3dSolid* pSolid);
};

//======= SheetMetal Explode Operation : API analogue of 'SmExplode' command ========

class BRX_IMPORTEXPORT BrxSmExplode
{
    std::shared_ptr<OdSheetMetal::IExplodeOperation>  m_explodeOperator = nullptr;
    
public:
    enum class EExplodeTestResult
    {
        eExplodable          = 0,
        ePartiallyExplodable = 1,
        eNotExplodable       = 2,
    };

    BrxSmExplode();
    BrxSmExplode(const BrxSmExplode& other);
    virtual BrxSmExplode& operator= (const BrxSmExplode& other);
    virtual ~BrxSmExplode();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // defines the features to be exploded
    virtual Acad::ErrorStatus setFeatures(const AcDbObjectIdArray& featureIds);

    // verifies whether the given feature object can be exploded :
    //
    //   Bend         - not explodable, if contains single component
    //
    //   Form Feature - explodable, if geometry can be completely represented as set of flanges and bend;
    //                  partially, if flanges and bends can partially cover feature
    //
    //   Hem          - always explodable, if feature has no major invalidities
    //
    //   Junction     - not explodable, if contains single component;
    //                  partially, if there is overlap of junction sides
    //
    //   Tab          - always explodable, if feature has no major invalidities
    //
    virtual Acad::ErrorStatus isExplodabale(const AcDbObjectId& featureId, EExplodeTestResult& explodableStatus);

    // returns the new features, created by a successful explode operation (after calling the ::run() function)
    virtual Acad::ErrorStatus newFeatures(AcDbObjectIdArray& newFeatures) const;

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};

//======= SheetMetal Split Operation : API analogue of 'SmSplit' command =======

class BRX_IMPORTEXPORT BrxSmSplit
{
    std::shared_ptr<OdSheetMetal::ISplitOperation>  m_splitter = nullptr;
    
public:
    enum EFlangeSplitType
    {
        eCenter  = 0,
        eLeft    = 1,
        eRight   = 2,
        eUnknown = 3
    };

    BrxSmSplit();
    BrxSmSplit(const BrxSmSplit& other);
    virtual BrxSmSplit& operator= (const BrxSmSplit& other);
    virtual ~BrxSmSplit();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // get + set the flange split type
    virtual EFlangeSplitType  flangeSplitType() const;
    virtual Acad::ErrorStatus setFlangeSplitType(EFlangeSplitType flangeSplitType);

    // get + set the currents cut depth of the flange face, which is connected with
    // selected flange face via bend that is intersected by the given line
    // NOTE : this option is applicable only to flange face splitting
    virtual double            cutDepth() const;
    virtual Acad::ErrorStatus setCutDepth(double cutDepth);

    // get + set the option whether one of bends will be converted to junction in case
    // of line intersection, after split;
    // if true, one of the bends adjacent to selected flange created by splitting will
    //          be converted to junction, if it is adjacent to bend relief feature
    // if false, bends will never be converted to junctions
    // 
    // NOTE : this option is applicable only to flange face splitting
    virtual bool              convertBendToJunction() const;
    virtual Acad::ErrorStatus setConvertBendToJunction(bool convertToJunction);

    // get + set the option whether the cut will be orthogonal to bend in case
    // of intersection;
    // if true, the cut will be made perpendicular to bend in case of intersection
    // NOTE : this option is applicable only to flange face splitting
    virtual bool              orthogonalSplit() const;
    virtual Acad::ErrorStatus setOrthogonalSplit(bool splitOrthogonal);

    // get + set the option whether coincident faces of selected flange will be
    // healed via splitting along the common line belonging to selected flange face
    // NOTE : this option is applicable only to flange face splitting
    virtual bool              healCoincidence() const;
    virtual Acad::ErrorStatus setHealCoincidence(bool healCoincidence);

    // get + set the reference/split point on a lofted bend feature face;
    // if the lofted bend is a ruled surface, the cut will be made along the line
    // containing this point
    virtual AcGePoint3d       loftSplitPoint() const;
    virtual Acad::ErrorStatus setLoftSplitPoint(const AcGePoint3d& point);

    // defines the feature face(s) (flange face(s) or lofted bend face(s)) which shall be split
    virtual Acad::ErrorStatus setFeatureFaces(const AcDbFullSubentPathArray& faceIds);

    // defines the curve(s) on flange face, which will split the face
    virtual Acad::ErrorStatus setFlangeSplitCurves(const AcDbObjectIdArray& curveIds);

    // main function which performs the operation and uses the optional 'BrxErrorList'
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed;
    // if all the messages are warnings, it means the operation finished, but result has to be checked;
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // applies result of given type to given solid;
    // should be called after successful 'run()' call
    // NOTE : for performance reason, the result is moved to the provided solid;
    //        therefore, it is not possible to apply the same result twice !
    virtual Acad::ErrorStatus applyResult(AcDb3dSolid* pSolid);

    // Result generation is split into two stages:
    // 1. Solid generation, can be used for preview
    // 2. Feature generation, same solid has to be provided as for applyResult()
    //    the result entity has to be already added to database
    // NOTE: applyResult() should be called before applyFeatures()!
    virtual Acad::ErrorStatus applyFeatures(AcDb3dSolid* pSolid);
};


//================== SheetMetal Unfolding Interface ============================

//------- SheetMetal Unfold group Appearance : handling layer and other traits for Unfold Appearance

// Each unfolded entity is classified to belong to one of the groups,
// see 'BrxIUnfoldAppearance' for description of each group;
// geometry which is taken from
//    bends up
//    bends down
//    form features up
//    form features down
//    bend annotations
//    overall dimensions
//    annotations
// This class determines the properties of the layer on which geometry will be placed and
// some other applied directly to the geometry;
// NOTE that layer properties are applied only if layer is created by the unfold operation;
// if objectId of existing layer is provided or layer with such name already exists, it is just reused

class BRX_IMPORTEXPORT BrxIUnfoldGroupAppearance
{
    friend class BrxIUnfoldAppearance;

    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IUnfoldGroupAppearance>  m_groupAppearance = nullptr;
    
public:
    BrxIUnfoldGroupAppearance();
    BrxIUnfoldGroupAppearance(const BrxIUnfoldGroupAppearance& other);
    virtual BrxIUnfoldGroupAppearance& operator= (const BrxIUnfoldGroupAppearance& other);
    virtual ~BrxIUnfoldGroupAppearance();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // get + set the layer name;
    // if a layer with given name already exists, entity will be put on it
    // without layer modification
    virtual const ACHAR* layerName() const;
    virtual Acad::ErrorStatus setLayerName(const ACHAR* layerName);

    // get + set the real layer Id, optionally keeping the assigned name
    virtual AcDbObjectId layerId() const;
    virtual Acad::ErrorStatus setLayerId(const AcDbObjectId& layerId, bool bKeepName = false);

    // get + set the linetype name, to be assigned to newly created layer(s)
    virtual const ACHAR* layerLineTypeName() const;
    virtual Acad::ErrorStatus setLayerLineTypeName(const ACHAR* lineTypeName);

    // get + set the layer linetype Id, to be assigned assign to newly created layer(s)
    virtual AcDbObjectId layerLineTypeId() const;
    virtual Acad::ErrorStatus setLayerLineTypeId(const AcDbObjectId& lineTypeId);

    // get + set the layer ACI color index, to be assigned to newly created layer(s)
    virtual int layerColorIndex() const;
    virtual Acad::ErrorStatus setLayerColorIndex(int colorIndex);

    // get + set the layer lineweight, to be assigned assign to newly created layer(s)
    virtual AcDb::LineWeight layerLineWeight() const;
    virtual Acad::ErrorStatus setLayerLineWeight(AcDb::LineWeight lineWeight);

    // get + set the textstyle ObjectId (for text entities, including text in dimensions)
    virtual AcDbObjectId textStyleId() const;
    virtual Acad::ErrorStatus setTextStyleId(const AcDbObjectId& styleId);
};

//------- SheetMetal Unfold Appearance : controls appearance of unfolded object

class BrxIUnfoldAppearanceImpl;

class BRX_IMPORTEXPORT BrxIUnfoldAppearance
{
    friend class BrxIUnfoldAppearanceImpl;
    friend class BrxSmUnfoldOperation;

    // ! underlying core data - for internal use only !
    std::shared_ptr<OdSheetMetal::IUnfoldAppearance>  m_appearance = nullptr;
    
public:
    // enum to define the behaviour for form and rib features appearance in unfolded part :
    // eKeep     Valid for 3D mode only, keeps feature geometry
    // eRemove   Geometry is removed from unfolded part
    // eProject  2D geometry is obtained by projecting 3D geometry on flange plane, including internal edges
    // eContour  Similar to eProject but only border edges are kept
    // eSymbol   2D geometry is taken from layers defined by UNFOLD_SYMBOL_UP and UNFOLD_SYMBOL_DOWN layers in
    //           definition of form feature
    enum class EFormFeatureUnfoldingMode
    {
        eKeep    = 0,
        eRemove  = 1,
        eProject = 2,
        eContour = 3,
        eSymbol  = 4,
    };

    // deprecated, will be removed in the future; use EFormFeatureUnfoldingMode
    enum class EUnfoldingMode
    {
        eKeep    = 0,
        eRemove  = 1,
        eProject = 2,
        eContour = 3,
        eSymbol  = 4,
    };

    BrxIUnfoldAppearance();
    BrxIUnfoldAppearance(const BrxIUnfoldAppearance& other);
    virtual BrxIUnfoldAppearance& operator= (const BrxIUnfoldAppearance& other);
    virtual ~BrxIUnfoldAppearance();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // this method initializes the appearance object from BricsCAD defaults
    // blockId - the block id with Sheet Metal 3D solid that will be unfolded.
    // The data for setup will be taken from Sheet Metal context of this block
    // and settings of the database owning the block
    // unitsString - specifies the units as to be used in annotations
    virtual Acad::ErrorStatus setSheetMetalDefaults(const AcDbObjectId& blockId, const ACHAR* unitsString);

    // get + set the current bend line extent;
    // that is the absolute value how a bend line is extended out of contour;
    // value can be positive, zero or negative
    virtual double            bendLineExtent() const;
    virtual Acad::ErrorStatus setBendLineExtent(double value);

    // get + set the option to control appearance of thickness/material text in unfolded block :
    //   Thickness = 2 mm
    //   Material  = Steel
    virtual bool addAttributeText() const;
    virtual Acad::ErrorStatus setAddAttributeText(bool addAttribute);

    // deprecated, will be removed in the future; use formFeatureUnfoldingMode()
    EUnfoldingMode unfoldingMode() const
    {
        return (EUnfoldingMode)formFeatureUnfoldingMode();
    }
    // deprecated, will be removed in the future; use setFormFeatureUnfoldingMode()
    Acad::ErrorStatus setUnfoldingMode(EUnfoldingMode unfoldingMode)
    {
        return setFormFeatureUnfoldingMode((EFormFeatureUnfoldingMode)unfoldingMode);
    }

    // controls appearance of form features in unfolded part, see 'EUnfoldingMode'
    virtual EFormFeatureUnfoldingMode formFeatureUnfoldingMode() const;
    virtual Acad::ErrorStatus setFormFeatureUnfoldingMode(EFormFeatureUnfoldingMode unfoldingMode);

    // defines whether attribute text will have units, by default it is "mm" or "inch" depending on database
    virtual const ACHAR* unitsAbbreviation() const;
    virtual Acad::ErrorStatus setUnitsAbbreviation(const ACHAR* unitsAbbreviation);

    // provides path to linetype filename which should contain linetypes with names assigned to the entities;
    // this function must be called to make unfolding to succeed
    virtual const ACHAR* linetypeFilename() const;
    virtual Acad::ErrorStatus setLinetypeFilename(const ACHAR* linetypeFilename);

    // controls the properties of geometry group which describes 2D entities from unfolded part geometry
    virtual BrxIUnfoldGroupAppearance geometryAppearance() const;
    virtual Acad::ErrorStatus setGeometryAppearance(const BrxIUnfoldGroupAppearance& unfoldGroupAppearance);

    // controls the properties of annotations for "up" bends geometry;
    // 'up bends' are the ones which are bent in opposite direction to watcher when
    // looking on the unfolded part from above (in -Z direction)
    virtual BrxIUnfoldGroupAppearance bendLinesUpAppearance() const;
    virtual Acad::ErrorStatus setBendLinesUpAppearance(const BrxIUnfoldGroupAppearance& unfoldGroupAppearance);

    // controls the properties of annotations for "down" bends geometry;
    // 'down bends' are the ones which are bent in opposite direction to watcher when
    // looking on the unfolded part from above (in -Z direction)
    virtual BrxIUnfoldGroupAppearance bendLinesDownAppearance() const;
    virtual Acad::ErrorStatus setBendLinesDownAppearance(const BrxIUnfoldGroupAppearance& unfoldGroupAppearance);
   
    // controls the properties of annotations for "up" rolled edges geometry;
    // 'up rolled edges' are the ones which are bent in opposite direction to watcher when
    // looking on the unfolded part from above (in -Z direction)
    virtual BrxIUnfoldGroupAppearance rolledEdgeLinesUpAppearance() const;
    virtual Acad::ErrorStatus setRolledEdgeLinesUpAppearance(const BrxIUnfoldGroupAppearance & unfoldGroupAppearance);

    // controls the properties of annotations for "down" rolled edges geometry;
    // 'down rolled edges' are the ones which are bent in opposite direction to watcher when
    // looking on the unfolded part from above (in -Z direction)
    virtual BrxIUnfoldGroupAppearance rolledEdgeLinesDownAppearance() const;
    virtual Acad::ErrorStatus setRolledEdgeLinesDownAppearance(const BrxIUnfoldGroupAppearance & unfoldGroupAppearance);

    // controls properties of annotations for rolled edge labels.
    virtual BrxIUnfoldGroupAppearance rolledEdgeAnnotationAppearance() const;
    virtual Acad::ErrorStatus setRolledEdgeAnnotationAppearance(const BrxIUnfoldGroupAppearance& unfoldGroupAppearance);

    // controls the properties of annotations for "up" form and rib features geometry;
    // the up and down sides are selected the same as for the bends
    virtual BrxIUnfoldGroupAppearance formFeaturesUpAppearance() const;
    virtual Acad::ErrorStatus setFormFeaturesUpAppearance(const BrxIUnfoldGroupAppearance& unfoldGroupAppearance);

    // controls the properties of annotations for "down" form and rib features geometry.
    // the up and down sides are selected the same as for the bends
    virtual BrxIUnfoldGroupAppearance formFeaturesDownAppearance() const;
    virtual Acad::ErrorStatus setFormFeaturesDownAppearance(const BrxIUnfoldGroupAppearance& unfoldGroupAppearance);

    // controls the properties of annotations for annotations for overall dimensions
    virtual BrxIUnfoldGroupAppearance overallDimensionsAppearance() const;
    virtual Acad::ErrorStatus setOverallDimensionsAppearance(const BrxIUnfoldGroupAppearance& unfoldGroupAppearance);

    // controls the properties of annotations for annotations for bend lines
    virtual BrxIUnfoldGroupAppearance bendAnnotationsAppearance() const;
    virtual Acad::ErrorStatus setBendAnnotationsAppearance(const BrxIUnfoldGroupAppearance& unfoldGroupAppearance);

    // controls the properties of annotations for part properties
    // Example:
    //   Thickness = 2 mm
    //   Material = Steel
    virtual BrxIUnfoldGroupAppearance attributesAppearance() const;
    virtual Acad::ErrorStatus setAttributesAppearance(const BrxIUnfoldGroupAppearance& unfoldGroupAppearance);
};

//----- SheetMetal Unfold Operation : API analogue of 'SmUnfold' command -------

class BRX_IMPORTEXPORT BrxSmUnfoldOperation
{
    std::shared_ptr<OdSheetMetal::IUnfoldOperation>  m_unfolder = nullptr;
    
public:
    typedef AcArray< std::pair<AcDbObjectId, AcDbObjectId> >  ClashingPairArray;

    BrxSmUnfoldOperation();
    BrxSmUnfoldOperation(const BrxSmUnfoldOperation& other);
    virtual BrxSmUnfoldOperation& operator= (const BrxSmUnfoldOperation& other);
    virtual ~BrxSmUnfoldOperation();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // sets start face for the unfolding process;
    // the start face determines the side to be used as primary and also may influence
    // the layout of unfolding;
    // the solid to which 'startFace' relates to should already have SheetMetal features
    // 'startFace' should be the path to a Flange or LoftedBend face
    //
    virtual Acad::ErrorStatus setStartFace(const AcDbFullSubentPath& startFace);

    // get + set the 'appearance' option object, used by this unfolding operation
    virtual BrxIUnfoldAppearance unfoldAppearance();
    virtual Acad::ErrorStatus    setUnfoldAppearance(const BrxIUnfoldAppearance& appearance);

    // main function to perform the unfold operation, and uses optional BrxErrorList
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed.
    // if all the messages are warnings, it means the operation finished, but result has to be checked.
    // 
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // call this function after successful 'run()' (even if operation created some warnings);
    // ff not converted to 2D, the block contains solids per feature :
    //     each flange, unfolded bend and lofted bend is represented by separate solid;
    // same block also contains the single solid, which is a result of union operation(s);
    // returns AcDbObjectId of owner block with unfolded geometry containing solids and
    // 2D entities for annotation
    // 
    virtual AcDbObjectId resultBlock();

    // call this function after successful 'run()' (even if operation created some warnings);
    // returns AcDbObjectId of that solid, which is the result of union operation of those feature solids,
    // which are also present in the block
    // 
    virtual AcDbObjectId resultSolid();

    // generates the 2D geometry for unfolding, to be called after successful 'run()' call;
    virtual Acad::ErrorStatus convertTo2D();

    // rearranges the bend annotations, so they don't intersect each other;
    // can be called several times
    virtual Acad::ErrorStatus optimizeAnnotationPlacement();

    // removes all annotation objects
    virtual Acad::ErrorStatus eraseAnnotations();

    // returns the array of bend lines, after successful run() operation
    virtual Acad::ErrorStatus getBendLines(BrxSmUnfoldedBendLinesArray& bendLines) const;

    // returns the array of bevel edges, after successful run() operation
    virtual Acad::ErrorStatus getBevelEdges(BrxSmUnfoldedBevelEdgeArray& bevelEdges) const;
  
    // returns the FormFeature symbols after their processing
    virtual Acad::ErrorStatus getFormFeatureWires(BrxSmUnfoldedFormFeatureWiresArray& formFeatureWires) const;
  
    // returns the array of clashing feature pairs, after successful run() operation
    virtual Acad::ErrorStatus getClashedFeaturePairs(ClashingPairArray& clashingPairs) const;

    // returns the array of bends which seem to be torn during unfolding, after successful run() operation
    virtual Acad::ErrorStatus getTornBendFeatures(AcDbObjectIdArray& features) const;
};

//---------- SheetMetal Unfold Operation : "Side Selection" interface ----------

class BRX_IMPORTEXPORT BrxSmSideSelection
{
    std::shared_ptr<OdSheetMetal::ISideSelectOperation>  m_sideSelection = nullptr;
    
public:
    BrxSmSideSelection();
    BrxSmSideSelection(const BrxSmSideSelection& other);
    virtual BrxSmSideSelection& operator= (const BrxSmSideSelection& other);
    virtual ~BrxSmSideSelection();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // sets the reference face for the side selection;
    // all faces that lie on the same side as the reference face will be selected
    // by a successful 'run()' call;
    //    'refFace' can be a face of one of these features :
    //     a) bend
    //     b) flange
    //     c) form feature
    //     d) lofted bend
    //     e) wrong bend
    //     f) wrong flange
    //
    virtual Acad::ErrorStatus setFace(const AcDbFullSubentPath& refFace);

    // main function to perform the SideSelection operation, and uses optional BrxErrorList
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed.
    // if all the messages are warnings, it means the operation finished, but result has to be checked.
    // 
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // call this function after successful 'run()' (even if operation created some warnings);
    // returns the 'sideFaces' array with all detected side faces;
    // 'sideFaces' array is cleared upon function entry
    // 
    virtual Acad::ErrorStatus getSideFaces(AcDbFullSubentPathArray& sideFaces);
};

//================== SheetMetal AssemblyExport Interface ============================

//----- BrxSmAssemblyExportReactor : customizing the 'BrxSmAssemblyExport' behaviour -------

// this reactor interface contains possible overrides for BrxSmAssemblyExport; it gives set of
// possible callbacks which allow to customize the processing of given solid in given component

class BrxSmAssemblyExport;

enum class EAssumeSheetMetal
{
    eAuto           = 0,
    eError          = 1,
    eSheetMetal     = 2,
    ePoorSheetMetal = 3,
    eNotSheetMetal  = 4,
    eStandardPart   = 5,
    eHollowLinearSolid = 6, // Type is set if solid is a extruded linear solid with hollow contour
    eHollowCircularTubeLinearSolid = 7 // Special case of linear solid when it is a circular tube
                                       // Contour is circular hollow
};

class BRX_IMPORTEXPORT BrxSmAssemblyExportReactor
{
    friend class BrxSmAssemblyExport;
    std::shared_ptr<OdSheetMetal::IAssemblyExportBehaviour>  m_exportBehaviour = nullptr;

public:

    enum class EProcessResult
    {
        eProcessSolid = 0,
        eSkipSolid    = 1,
        eFailContinue = 2,
        eFailFatal    = 3,
    };

    BrxSmAssemblyExportReactor();
    virtual ~BrxSmAssemblyExportReactor();

    // provides a flexible assignment of bend table per sheetmetal entity; default implementation does nothing;
    //
    // originalComponentId
    //   refers to the original component in the original drawing; note : the component can be empty
    //   and at the moment the callback is called you work with temporary drawing
    // 
    // temporaryComponentId
    //   represent id of the component in given temporary drawing
    // 
    // originalSolidId
    //   3dSolid id in the original drawing; this solid might have no sheet metal features at the moment of the call
    // 
    // temporarySolidId
    //   3dSolid id in the temporary drawing; this solid should have sheet metal features at the moment of the call,
    //   so you can acquire its thickness, bends, etc...
    // 
    // bendTablePath
    //   absolute path for a .csv bend table for given 3dSolid; note that the given bend table should have a
    //   thickness for the given 3dSolid; if bend table is wrong, default policy will be used, part will
    //   be exported with warning;
    //   you can also provide empty string, then default policies will be applied; no warnings will not be created
    // 
    // return
    //   Acad::eOk if path was set (even empty);
    //   for other status codes : the default policies will be used; part will be exported with warning
    //
    virtual Acad::ErrorStatus getBendTablePath(const AcDbObjectId& originalComponentId,
                                               const AcDbObjectId& temporaryComponentId,
                                               const AcDbObjectId& originalSolidId,
                                               const AcDbObjectId& temporarySolidId,
                                               AcString& bendTablePath)
    {
        bendTablePath.setEmpty();
        return Acad::eOk;
    };

    // Provides overriding of unfolding appearance; default implementation returns an empty instance;
    // 
    // originalComponentId
    //   refers to the original component in original drawing; note the component might be empty
    //   and at the moment the callback is called you work with temporary drawing
    // 
    // temporaryComponentId
    //   represents the id of the component in given temporary drawing
    // 
    // originalSolidId
    //   3dSolid id in the original drawing; this solid might have no sheet metal features at the moment of the call
    // 
    // temporarySolidId
    //   3dSolid id in the temporary drawing; this solid should have sheet metal features at the moment of the call,
    //   so you can acquire its thickness, bends, etc...
    // 
    // pUnfoldAppearance
    //   unfold appearance to be applied for unfolding of given 3dSolid; if an empty object (or default object)
    //   is provided, default unfold appearance is used; this will not lead to marking unfolding as warning
    // 
    // return
    //   Acad::eOk if appearance was explicitly assigned; for default behaviour, return i.e. Acad::eNotApplicable
    //   for other status codes : the default unfold appearance will be used
    // 
    virtual Acad::ErrorStatus getUnfoldAppearance(const AcDbObjectId& originalComponentId,
                                                  const AcDbObjectId& temporaryComponentId,
                                                  const AcDbObjectId& originalSolidId,
                                                  const AcDbObjectId& temporarySolidId,
                                                  BrxIUnfoldAppearance& pUnfoldAppearance)
    {
        return Acad::eNotApplicable;
    }

    // provides overriding of the sheet metal status; default implementation delegates to sheet metal default;
    // 
    // originalComponentId
    //   refers to the original component in the original drawing; note the component can be empty
    //   and at the moment the callback is called you work with temporary drawing
    // 
    // temporaryComponentId
    //   represents the id of the component in given temporary drawing
    // 
    // originalSolidId
    //   3dSolid id in the original drawing; this 3dSolid might have no sheet metal features at the moment of the call
    // 
    // temporarySolidId
    //   3dSolid id in the temporary drawing; hhis 3dSolid should have sheet metal features at the moment of the call,
    //   so you can acquire its thickness, bends, etc...
    // 
    // autoAssumeResult
    //   indicates how this part is classified by built-in AI
    // 
    // assumeResult
    //   eAuto            built-in default AI has to decide if the part is sheet metal
    //   eSheetMetal      part will be classified as sheet metal; if unfolding fails, it will be reclassified as poor sheet metal
    //   ePoorSheetMetal  part will be classified as poor sheet metal; for manual rework; no output unfolding will be created
    //   eNotSheetMetal   part will be classified as not sheet metal; no output unfolding will be created
    //   eStandardPart    part will be classified as standard part; no output unfolding will be created
    //   eHollowLinearSolid part will be classified as extruded hollow solid; no output unfolding will be created
    //   eHollowCircularTubeLinearSolid part will be classified as tube; no output unfolding will be created
    //
    // return
    //   Acad::eOk if path was set (even empty);
    //   for other status codes : the default policies will be used; part will be exported with warning;
    //   'AssumeSheetMetal' column of the report will indicate an error
    //
    virtual Acad::ErrorStatus assumeSheetMetal(const AcDbObjectId& originalComponentId,
                                               const AcDbObjectId& temporaryComponentId,
                                               const AcDbObjectId& originalSolidId,
                                               const AcDbObjectId& temporarySolidId,
                                               const EAssumeSheetMetal autoAssumeResult,
                                               EAssumeSheetMetal& assumeResult)
    {
        assumeResult = EAssumeSheetMetal::eAuto;
        return Acad::eOk;
    };

    // provides preprocessing of 3dSolid before general treatment; preprocessing should be done with temporary solid;
    // default implementation does nothing;
    //
    // originalComponentId
    //   refers to the original component in original drawing; note the component might be empty
    //   and at the moment the callback is called you work with temporary drawing
    //
    // temporaryComponentId
    //   represents the id of the component in given temporary drawing
    //
    // originalSolidId
    //   3dSolid id in the original drawing; this 3dSolid might have no sheet metal features at the moment of the call
    //
    // temporarySolidId
    //   3dSolid id in the temporary drawing; this 3dSolid should have sheet metal features at the moment of the call,
    //   so you can acquire its thickness, bends, etc...
    //
    // return
    //   process result; see EProcessResult enum
    //
    virtual EProcessResult onBeginProcessing(const AcDbObjectId& originalComponentId,
                                             const AcDbObjectId& temporaryComponentId,
                                             const AcDbObjectId& originalSolidId,
                                             const AcDbObjectId& temporarySolidId)
    {
        return EProcessResult::eProcessSolid;
    };

    // Provides preprocessing of 3dSolid before unfold. Preprocessing should be done with temporary solid
    // default implementation does nothing;
    // 
    // originalComponentId
    //   refers to the original component in original drawing; note the component might be empty
    //   and at the moment the callback is called you work with temporary drawing
    // 
    // temporaryComponentId
    //   represents the id of the component in given temporary drawing
    // 
    // originalSolidId
    //   3dSolid id in the original drawing; this 3dSolid might have no sheet metal features at the moment of the call
    // 
    // temporarySolidId
    //   3dSolid id in the temporary drawing; this 3dSolid should have sheet metal features at the moment of the call,
    //   so you can acquire its thickness, bends, etc...
    // 
    // return
    //   process result; see EProcessResult enum
    //
    virtual EProcessResult onUnfoldBegin(const AcDbObjectId& originalComponentId,
                                         const AcDbObjectId& temporaryComponentId,
                                         const AcDbObjectId& originalSolidId,
                                         const AcDbObjectId& temporarySolidId)
    {
        return EProcessResult::eProcessSolid;
    };

    // provides preprocessing of the 3dSolid before convert; Preprocessing should be done with temporary solid;
    // default implementation does nothing;
    // 
    // originalComponentId
    //   refers to the original component in original drawing; note the component might be empty
    //   and at the moment the callback is called you work with temporary drawing
    // 
    // temporaryComponentId
    //   represents the id of component in given temporary drawing
    // 
    // originalSolidId
    //   3dSolid id in the original drawing; this solid might have no sheet metal features at the moment of the call
    // 
    // temporarySolidId
    //   3dSolid id in the temporary drawing; this solid should have sheet metal features at the moment of the call,
    //   So you can acquire its thickness, bends, etc...
    // 
    // return
    //   process result; see EProcessResult enum
    // 
    virtual EProcessResult onConvertBegin(const AcDbObjectId& originalComponentId,
                                          const AcDbObjectId& temporaryComponentId,
                                          const AcDbObjectId& originalSolidId,
                                          const AcDbObjectId& temporarySolidId)
    {
        return EProcessResult::eProcessSolid;
    };
};

//----- SheetMetal AssemblyExport Operation : API analogue of 'SmAssemblyExport' command -------

// Please note : SheetMetal AssemblyExport only operates properly on the current drawing !

class BRX_IMPORTEXPORT BrxSmAssemblyExport
{
    friend class BrxSmAssemblyExportReactor;
    std::shared_ptr<OdSheetMetal::IAssemblyExportOperation>  m_assemblyExporter = nullptr;
    
public:


    // Determines how paths to files will be written in the report
    //   eRelativePaths - relative paths will be written
    //   eAbsolutePaths - absolute paths will be written
    enum class EReportPathType
    {
        eRelativePaths = 0x00,
        eAbsolutePaths = 0x01
    };

    // Defines which solid types will be in the report. Sheet metal and poor sheet metal
    // solids are always present in the report.
    //   eNone                           - neither non sheet metal nor standard part component solids will
    //                                     be included in the report
    //   eNonSheetMetalSolids            - only non sheet metal solids will be included in the report
    //   eStandardPartComponentSolids    - only standard part component solids will be included in the report
    //   eHollowLinearSolids             - hollow linear solids will be detected and treated as non sheet metal solids
    //   eHollowCircularTubeLinearSolids - hollow circular tube solids will be detected and treated as non sheet metal solids
    //   eAll                            - both non sheet metal and standard part component solids will be
    //                                     included in the report
    enum ESolidTypesInReport
    {
        eNone                           = 0x00,
        eNonSheetMetalSolids            = 0x01,
        eStandardPartComponentSolids    = 0x02,
        eHollowLinearSolids             = 0x04,
        eHollowCircularTubeLinearSolids = 0x08,
        eAll                            = eNonSheetMetalSolids | eStandardPartComponentSolids |
                                            eHollowLinearSolids | eHollowCircularTubeLinearSolids,
        eDefault                        = eNonSheetMetalSolids | eStandardPartComponentSolids
    };

    BrxSmAssemblyExport();
    BrxSmAssemblyExport(const BrxSmAssemblyExport& other);
    virtual BrxSmAssemblyExport& operator= (const BrxSmAssemblyExport& other);
    virtual ~BrxSmAssemblyExport();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // defines the set of entities to be exported
    virtual Acad::ErrorStatus setEntities(const AcDbObjectIdArray& entities);

    // get + set the output folder path string
    virtual Acad::ErrorStatus outputFolderPath(const ACHAR*& szOutputFolderPath) const;
    virtual Acad::ErrorStatus setOutputFolderPath(const ACHAR* szOutputFolderPath);

    // get + set the output file format and version
    virtual Acad::ErrorStatus outputFileVersion(AcApDocument::SaveFormat& format);
    virtual Acad::ErrorStatus setOutputFileVersion(AcApDocument::SaveFormat format = AcApDocument::k2010_dxf);

    // get + set report path type which determines if report will have relative or absolute path to .dwg, .dxf and pictures
    virtual Acad::ErrorStatus reportPathType(EReportPathType & type) const;
    virtual Acad::ErrorStatus setReportPathType(EReportPathType type);

    // get + set which flags for types will be present in the report
    virtual Acad::ErrorStatus solidTypesInReport(int & typeFlags) const;
    virtual Acad::ErrorStatus setSolidTypesInReport(int typeFlags);

    // attach a BrxSmAssemblyExportReactor instance, allows to customize the assembly export operation
    virtual Acad::ErrorStatus attachReactor(BrxSmAssemblyExportReactor* pAssemblyExportReactor);

    // main function to perform the Export operation, and uses optional BrxErrorList
    // to report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed.
    // if all the messages are warnings, it means the operation finished, but result has to be checked.
    // 
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);
};


//--------------------- SheetMetal Feature Validation --------------------------

class BRX_IMPORTEXPORT BrxFeatureIdError
{
public:

    // Possible error codes, compare errorId() code with them
    // Enum shows the errors which might occur during the feature validation.
    // It should be taken into account that each feature may
    // have several errors the behavior for this case depends on ErrorMode.
    enum class EValidationErrorId
    {
        eUnknown = 0,
        eAdjacentToWrongFlange = 1,
        eBadAdjacencyBend = 2,
        eBadAlignedJunction = 3,
        eBadTopologyBend = 4,
        eBadTopologyJunction = 5,
        eDuplicateFeature = 6,
        eFeatureClash = 7,
        eFlangeBelongsToSeveralBodies = 8,
        eFlangeConnectionIsNotPossible = 9,
        eFlangeHasIncorrectThickness = 10,
        eFlangeThicknessCalculationFailed = 11,
        eHardEdgeInWrongBend = 12,
        eHasAdjacentCoincidentGeometry = 13,
        eHemGapIncorrect = 14,
        eHemLengthIncorrect = 15,
        eHemRadiusIncorrect = 16,
        eIncompleteFeature = 17,
        eIncorrectJunctionGap = 18,
        eInsufficientFeature = 19,
        eInternallyDuplicateFeature = 20,
        eInvalidFeature = 21,
        eInvalidMiterNotchFaces = 22,
        eInvalidMiterSplitGap = 23,
        eInvalidRibPath = 24,          // Since V22 Rib is called as Bead feature in user interface
        eInvalidRibProfileRadius = 25, // Since V22 Rib is called as Bead feature in user interface
        eInvalidRibRoundRadius = 26,   // Since V22 Rib is called as Bead feature in user interface
        eInvalidThickness = 27,
        eInvalidUnderlyingFlange = 28,
        eNonCoaxialBend = 29,
        eNonCoplanarFlange = 30,
        eNonCoplanarJunction = 31,
        eNonCylindricalBend = 32,
        eNonOrthoThickness = 33,
        eNonParallelFlange = 34,
        eNonPlanarFlange = 35,
        eNonTangentAdjacentBend = 36,
        eNotMatchSurfaceBend = 37,
        eNotOrthoExternalBendRelief = 38,
        eNotOrthoFlangeBendRelief = 39,
        eNotTangentialConnection = 40,
        eRibHasDifferentRoundRadius = 41, // Since V22 Rib is called as Bead feature in user interface
        eSeparatedFlange = 42,
        eSeparatedJunction = 43,
        eSeparatedLoftedBend = 44,
        eTabIncorrectLengthOfSlot = 45,
        eTabInvalidNumberOfSlots = 46,
        eWrongDistanceBendRelief = 47,
        eWrongFeatureGeometry = 48,
        eWrongFormFeatureTransf = 49,
        eWrongRadiusBend = 50
    };

private:

    AcDbObjectId       m_id;
    int                m_err = 0;
    EValidationErrorId m_errId = EValidationErrorId::eUnknown;
    AcString           m_msg;

public:

    BrxFeatureIdError();
    // errorCode is a deprecated parameter
    BrxFeatureIdError(const AcDbObjectId& featureId, int errorCode,
        EValidationErrorId errId, const ACHAR* errorMessage);
    virtual ~BrxFeatureIdError();

    BrxFeatureIdError(const BrxFeatureIdError& other);
    virtual BrxFeatureIdError& operator=(const BrxFeatureIdError& other);

    // id of the related feature
    virtual const AcDbObjectId& featureId()    const;

    // deprecated, will be removed in the future; use errorId()
    // errorCode to be compared with one of the enums in BrxFeatureValidation
    // depending on feature time
    virtual int                 errorCode()    const;

    // this is global enum of potential validation errors for all feature types
    virtual EValidationErrorId  errorId()      const;

    // user-friendly message describing validation error
    virtual const ACHAR*        errorMessage() const;
};
typedef std::vector<BrxFeatureIdError> BrxFeatureIdErrorList;

class BRX_IMPORTEXPORT BrxFeatureValidation
{
    std::shared_ptr<OdSheetMetal::IFeatureValidateOperation>  m_featureValidation = nullptr;
    
public:

    // Enum shows the errors which might occur during the flange feature validation.
    // This enum of errors is sorted by their criticality level, beginning with
    // the most crucial. It should be taken into account that if flange feature
    // has several errors the behavior for this case depends on ErrorMode.
    // see ErrorMode
    //   eDuplicateFeature                - error that occurs if faces of current feature
    //                                      belongs to other features
    //   eInvalidFeature                  - current feature is not valid
    //   eInsufficientFeature             - error that occurs if flange feature do not
    //                                      have top or bottom faces
    //   eWrongFeatureGeometry            - error that occurs if flange feature face is
    //                                      not a plane (e. g. spline)
    //   eIncorrectThickness              - error that occurs if flange feature thickness
    //                                      differs from one from sheet metal context
    //   eNotPerpendicularToThicknessFace - error that occurs if flange feature faces
    //                                      are not perpendicular to its thickness faces
    //   eFeatureBelongsToSeveralBodies   - the error that occurs if a flange feature
    //                                      belongs more than one solid
    //   eSeparatedFlange                 - error that occurs if flange feature top or
    //                                      bottom faces are separated from each other
    //   eFacesNotCoplanar                - error that occurs if flange feature faces that
    //                                      belong to the same mask (top or bottom) have
    //                                      different normals
    //   eFacesNotAntiparallel            - error that occurs if top and bottom flange feature
    //                                      faces normals are not anti parallel
    //   eIncompleteFeature               - error that occurs if there are adjacent faces with
    //                                      similar parameters which do not belong to the feature
    //
    enum class EFlangeFeatureValidationCheck
    {
        eDuplicateFeature                = 1,
        eInvalidFeature                  = 2,
        eInsufficientFeature             = 3,
        eWrongFeatureGeometry            = 4,
        eIncorrectThickness              = 5,
        eNotPerpendicularToThicknessFace = 6,
        eFeatureBelongsToSeveralBodies   = 7,
        eSeparatedFlange                 = 8,
        eFacesNotCoplanar                = 9,
        eFacesNotAntiparallel            = 10,
        eIncompleteFeature               = 11
    };

    // Enum shows the errors which might occur during the wrong flange feature validation.
    // This enum of errors is sorted by their criticality level, beginning with
    // the most crucial. It should be taken into account that if wrong flange feature
    // has several errors the behavior for this case depends on ErrorMode.
    // see ErrorMode
    //   eDuplicateFeature     - error that occurs if faces of current feature
    //                           belongs to other features
    //   eInvalidFeature       - current feature is not valid
    //   eInsufficientFeature  - error that occurs if wrong flange feature do
    //                           not have top or bottom faces
    //   eWrongFeatureGeometry - error that occurs if flange feature face is
    //                           not a plane (e. g. spline)
    //   eIncorrectThickness   - error that occurs if wrong flange feature thickness
    //                           differs from one from sheet metal context
    //
    enum class EWrongFlangeFeatureValidationCheck
    {
        eDuplicateFeature     = 1,
        eInvalidFeature       = 2,
        eInsufficientFeature  = 3,
        eWrongFeatureGeometry = 4,
        eIncorrectThickness   = 5
    };

    // Enum shows the errors which might occur during the bend feature validation.
    // This enum of errors is sorted by their criticality level, beginning with
    // the most crucial. It should be taken into account that if bend feature
    // has several errors the behavior for this case depends on ErrorMode.
    // see ErrorMode
    //   eDuplicateFeature                - error that occurs if faces of current feature
    //                                      belongs to other features
    //   eInvalidFeature                  - current feature is not valid
    //   eInsufficientFeature             - error that occurs if bend feature do
    //                                      not have external or internal faces
    //   eNonCylindrical                  - error that occurs if bend feature face is
    //                                      not a cone (e. g. spline)
    //   eNotTangentToAdjacentFeature     - error that occurs if bend feature external
    //                                      or internal faces are not tangent to adjacent
    //                                      feature faces
    //   eNotPerpendicularToThicknessFace - error that occurs if bend feature faces
    //                                      are not perpendicular to its thickness faces
    //   eAdjacentToWrongFlange           - error that occurs if bend feature is adjacent
    //                                      to wrong flange
    //   eNotMatchedBendFaces             - error that occurs if bend feature external and
    //                                      internal faces do not match (not coaxial, have
    //                                      have different swept angle etc.)
    //   eWrongBendRadius                 - error that occurs if bend feature assigned
    //                                      radius differs from calculated one
    //   eBadAdjacency                    - error that occurs if the boundary between current
    //                                      bend and adjacent flanges is not correct
    //   eIncompleteFeature               - error that occurs if there are adjacent faces with
    //                                      similar parameters which do not belong to the feature
    //   eBadTopology                     - error that occurs if current bend is not adjacent
    //                                      to two flanges
    //   eNonTangentAdjacentBend          - error that occurs if bend has a common edge with another
    //                                      bend or lofted bend, which can lead to material conflicts
    // 
    enum class EBendFeatureValidationCheck
    {
        eDuplicateFeature                = 1,
        eInvalidFeature                  = 2,
        eInsufficientFeature             = 3,
        eNonCylindrical                  = 4,
        eNotTangentToAdjacentFeature     = 5,
        eNotPerpendicularToThicknessFace = 6,
        eAdjacentToWrongFlange           = 7,
        eNotMatchedBendFaces             = 8,
        eWrongBendRadius                 = 9,
        eBadAdjacency                    = 10,
        eIncompleteFeature               = 11,
        eBadTopology                     = 12,
        eNonTangentAdjacentBend          = 13
    };

    // Enum shows the errors which might occur during the wrong bend feature validation.
    // This enum of errors is sorted by their criticality level, beginning with
    // the most crucial. It should be taken into account that if wrong bend feature
    // has several errors the behavior for this case depends on ErrorMode.
    // see ErrorMode
    //   eDuplicateFeature            - error that occurs if faces of current feature
    //                                  belongs to other features
    //   eInvalidFeature              - current feature is not valid
    //   eInsufficientFeature         - error that occurs if wrong bend feature do not
    //                                  have external or internal faces
    //   eNonCylindrical              - error that occurs if wrong bend feature faces
    //                                  are not cylindrical
    //   eNotTangentToAdjacentFeature - error that occurs if wrong bend feature external
    //                                  or internal faces are not tangent to adjacent
    //                                  feature faces
    //   eHardEdgeInWrongBend         - error that occurs if wrong bend feature instead
    //                                  of internal faces has hard edge(s)
    //   eNotCoaxial                  - error that occurs if wrong bend feature external
    //                                  and internal faces have not coaxial axes
    //   eHasAdjacentCoincidentFaces  - error that occurs if adjacent thickness faces
    //                                  are coincident with other faces of the model
    // 
    enum class EWrongBendFeatureValidationCheck
    {
        eDuplicateFeature            = 1,
        eInvalidFeature              = 2,
        eInsufficientFeature         = 3,
        eNonCylindrical              = 4,
        eNotTangentToAdjacentFeature = 5,
        eHardEdgeInWrongBend         = 6,
        eNotCoaxial                  = 7,
        eHasAdjacentCoincidentFaces  = 8
    };

    // Enum shows the errors which might occur during the lofted bend feature validation.
    // This enum of errors is sorted by their criticality level, beginning with
    // the most crucial. It should be taken into account that if lofted bend feature
    // has several errors the behavior for this case depends on ErrorMode.
    // see ErrorMode
    //   eDuplicateFeature                - error that occurs if faces of current feature
    //                                      belongs to other features
    //   eInvalidFeature                  - current feature is not valid
    //   eInsufficientFeature             - error that occurs if lofted bend feature do not
    //                                      have top or bottom faces
    //   eSeparatedLoftedBend             - error that occurs if lofted bend feature faces
    //                                      are separated
    //   eNotTangentToAdjacentFeature     - error that occurs if lofted bend feature top
    //                                      or bottom faces are not tangent to adjacent
    //                                      feature faces
    //   eNotPerpendicularToThicknessFace - error that occurs if lofted bend feature faces
    //                                      are not perpendicular to its thickness faces
    //   eInvalidThickness                - error that occurs if lofted bend feature thickness
    //                                      differs from one from sheet metal context
    // 
    enum class ELoftedBendFeatureValidationCheck
    {
        eDuplicateFeature                = 1,
        eInvalidFeature                  = 2,
        eInsufficientFeature             = 3,
        eSeparatedLoftedBend             = 4,
        eNotTangentToAdjacentFeature     = 5,
        eNotPerpendicularToThicknessFace = 6,
        eInvalidThickness                = 7
    };

    // Enum shows the errors which might occur during the junction feature validation.
    // This enum of errors is sorted by their criticality level, beginning with
    // the most crucial. It should be taken into account that if junction feature
    // has several errors the behavior for this case depends on ErrorMode.
    // see ErrorMode
    //   eDuplicateFeature      - error that occurs if there are more than one
    //                            junction feature with this set of faces
    //   eInvalidFeature        - current feature is not valid
    //   eInsufficientFeature   - error that occurs if junction feature do not
    //                            have first or second part faces
    //   ePartsAreNotCoplanar   - error that occurs if junction feature faces
    //                            that belongs to the same part are not coplanar
    //   eNotAdjacentToFlanges  - error that occurs if junction part faces are not
    //                            adjacent to flange feature
    //   eNotCoincidentToRelief - error that occurs if junction feature is not
    //                            coincident to relief
    //   eSeparatedJunction     - error that occurs if one part of the junction
    //                            faces has separated components
    //   eIncorrectGap          - error that occurs if junction feature gap is not
    //                            constant or different from the specified value
    // 
    enum class EJunctionFeatureValidationCheck
    {
        eDuplicateFeature      = 1,
        eInvalidFeature        = 2,
        eInsufficientFeature   = 3,
        ePartsAreNotCoplanar   = 4,
        eNotAdjacentToFlanges  = 5,
        eNotCoincidentToRelief = 6,
        eSeparatedJunction     = 7,
        eIncorrectGap          = 8,
    };

    // Enum shows the errors which might occur during the form feature validation.
    // This enum of errors is sorted by their criticality level, beginning with
    // the most crucial. It should be taken into account that if form feature
    // has several errors the behavior for this case depends on ErrorMode.
    // see ErrorMode
    //   eDuplicateFeature          - error that occurs if faces of current feature
    //                                belongs to other features
    //   eInvalidFeature            - current feature is not valid
    //   eInsufficientFeature       - error that occurs if form feature do not
    //                                have top, bottom or thickness faces
    //   eInvalidUnderlyingFlange   - error that occurs if rib feature underlying
    //                                flange is not valid
    // 
    enum class EFormFeatureValidationCheck
    {
        eDuplicateFeature        = 1,
        eInvalidFeature          = 2,
        eInsufficientFeature     = 3,
        eInvalidUnderlyingFlange = 4,
        eWrongFormFeatureTransf  = 5,
    };

    // Enum shows the errors which might occur during the rib feature validation.
    // This enum of errors is sorted by their criticality level, beginning with
    // the most crucial. It should be taken into account that if rib feature
    // has several errors the behavior for this case depends on ErrorMode.
    // see ErrorMode
    //   eDuplicateFeature          - error that occurs if faces of current feature
    //                                belongs to other features
    //   eInvalidFeature            - current feature is not valid
    //   eInsufficientFeature       - error that occurs if rib feature do not
    //                                have top or bottom faces
    //   eInvalidUnderlyingFlange   - error that occurs if rib feature underlying
    //                                flange is not valid
    //   eInvalidProfileRadius      - error that occurs if rib feature assigned
    //                                profile radius differs from calculated one
    //   eInvalidRoundRadius        - error that occurs if rib feature assigned
    //                                round radius differs from calculated one
    //   eInvalidPath               - error that occurs if rib feature assigned
    //                                path differs from calculated one
    // 
    enum class ERibFeatureValidationCheck
    {
        eDuplicateFeature        = 1,
        eInvalidFeature          = 2,
        eInsufficientFeature     = 3,
        eInvalidUnderlyingFlange = 4,
        eInvalidProfileRadius    = 5,
        eInvalidRoundRadius      = 6,
        eInvalidPath             = 7,
        eDifferentRoundRadius    = 8
    };

    // Enum shows the errors which might occur during the miter validation.
    // This enum of errors is sorted by their criticality level, beginning with
    // the most crucial. It should be taken into account that if miter feature
    // has several errors the behavior for this case depends on ErrorMode.
    // see ErrorMode
    //   eDuplicateFeature    - error that occurs if faces of current feature
    //                          belongs to other features
    //   eInvalidFeature      - current feature is not valid
    //   eInsufficientFeature - error that occurs if miter feature do not
    //                          have first or second faces
    //   eInvalidSplitGap     - error that occurs if miter feature assigned
    //                          split gap differs from calculated one
    //   eInvalidNotchFaces   - error that occurs if miter feature notch
    //                          faces are invalid
    //
    enum class EMiterFeatureValidationCheck
    {
        eDuplicateFeature    = 1,
        eInvalidFeature      = 2,
        eInsufficientFeature = 3,
        eInvalidSplitGap     = 4,
        eInvalidNotchFaces   = 5
    };

    // Enum shows the errors which might occur during the hole feature validation.
    // This enum of errors is sorted by their criticality level, beginning with
    // the most crucial. It should be taken into account that if miter feature
    // has several errors the behavior for this case depends on ErrorMode.
    // see ErrorMode
    //   eDuplicateFeature        - error that occurs if faces of current feature
    //                              belongs to other features
    //   eInvalidFeature          - current feature is not valid
    //   eInsufficientFeature     - error that occurs if hole feature do not
    //                              have feature faces
    //   eInvalidUnderlyingFlange - error that occurs if hole feature underlying
    //                              flange is not valid
    //
    enum class EHoleFeatureValidationCheck
    {
        eDuplicateFeature        = 1,
        eInvalidFeature          = 2,
        eInsufficientFeature     = 3,
        eInvalidUnderlyingFlange = 4
    };

    // Enum shows what errors occur during the tab feature validation.
    // This enum of errors is sorted by their severity level, beginning with the most crucial.
    // It should be taken into account that if tab feature has several errors the behavior for
    // this case depends on ErrorMode.
    // see EErrorMode
    //   eDuplicateFeature      - error that occurs if faces of current feature
    //                            belongs to other features
    //   eInvalidFeature        - current feature is not valid
    //   eInsufficientFeature   - error that occurs if tab feature do not have
    //                            first and second base, extruded or thickness faces
    //   eInvalidNumberOfSlots  - error that occurs when assigned number of slots
    //                            contradicts with the real number of slots
    //   eIncorrectLengthOfSlot - error that occurs when assigned slot length
    //                            contradicts with the real slot length
    //
    enum class ETabFeatureValidationCheck
    {
        eDuplicateFeature      = 1,
        eInvalidFeature        = 2,
        eInsufficientFeature   = 3,
        eInvalidNumberOfSlots  = 4,
        eIncorrectLengthOfSlot = 5
    };

    // Enum responsible for behavior of validator in case of feature error
    //   eStopOnFirstError - feature validation stops on any first error (economy mode)
    //   eContinueOnError  - feature validation continues if it is possible. E.g. if
    //                       feature has no faces, we can't conitnue; else we can gather
    //                       all the validation errors
    // 
    enum class EErrorMode
    {
        eStopOnFirstError = 0,
        eContinueOnError  = 1
    };

    // Constructors / Destructors / Operators

    BrxFeatureValidation();
    BrxFeatureValidation(const BrxFeatureValidation& other);
    virtual BrxFeatureValidation& operator= (const BrxFeatureValidation& other);
    virtual ~BrxFeatureValidation();

    // verifies whether the object is empty
    virtual bool isNull() const;
    virtual void setNull();

    // get + set the error behaviour mode : defines how feature validation will behave in
    // case of a found feature error
    //   eStopOnFirstError : feature validation stops on first any error (economy mode)
    //   eContinueOnError  : feature validation continues if possible
    //
    virtual EErrorMode        errorMode() const;
    virtual Acad::ErrorStatus setErrorMode(EErrorMode errorMode);

    // sets the SheetMetal objects to be validated
    virtual Acad::ErrorStatus setSolids(const AcDbObjectIdArray& solids);

    // main function to perform the feature validation, uses optional BrxErrorList to
    // report about problems during operation;
    // check the list whether it has error or warning messages :
    // if there are error messages, the operation failed.
    // if all the messages are warnings, it means the operation finished, but result has to be checked.
    //
    virtual Acad::ErrorStatus run(BrxErrorList* failures = nullptr);

    // retrieves the list of errors & warnings of the feature validation by "run()" function;
    // descriptions are written to the given BrxFeatureIdErrorList list (is cleared upfront)
    // 
    virtual Acad::ErrorStatus getFeatureIdErrorDescriptions(BrxFeatureIdErrorList& errorDescriptions);
};
