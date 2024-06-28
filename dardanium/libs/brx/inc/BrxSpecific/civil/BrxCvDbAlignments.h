// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BRX API for BricsCAD Civil Alignments + Civil Views interfaces

#include <memory>

#include "Misc/AcArray.h"
#include "AcGe/AcGePoint2d.h"
#include "AcGe/AcGePoint3d.h"
#include "AcGe/AcGeVector2d.h"
#include "AcGe/AcGeVector3d.h"
#include "AcRx/AcRxObject.h"
#include "AcDb/AcDbEntity.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbCurve.h"

#include "BrxSpecific/civil/BrxCvDbEntity.h"
#include "BrxSpecific/civil/BrxCvDbCurve.h"
#include "BrxSpecific/civil/BrxCvDbSubObject.h"

class BrxCvDbView;
class BrxCvDbVAlignmentView;

class BrxCvDbHAlignment;
class BrxCvDbHAlignmentElement;
class BrxCvDbHAlignmentPI;
class BrxCvDbHAlignmentCurve;
class BrxCvDbHAlignmentLine;
class BrxCvDbHAlignmentArc;
class BrxCvDbHAlignmentSpiral;
class BrxCvDbHAlignmentSCS;
class BrxCvDbHAlignmentSTS;
class BrxCvDbHAlignmentSSCSS;

typedef AcSharedPtr<BrxCvDbHAlignmentElement> BrxCvDbHAlignmentElementPtr;
typedef AcSharedPtr<BrxCvDbHAlignmentPI>      BrxCvDbHAlignmentPIPtr;
typedef AcSharedPtr<BrxCvDbHAlignmentCurve>   BrxCvDbHAlignmentCurvePtr;
typedef AcSharedPtr<BrxCvDbHAlignmentLine>    BrxCvDbHAlignmentLinePtr;
typedef AcSharedPtr<BrxCvDbHAlignmentArc>     BrxCvDbHAlignmentArcPtr;
typedef AcSharedPtr<BrxCvDbHAlignmentSpiral>  BrxCvDbHAlignmentSpiralPtr;
typedef AcSharedPtr<BrxCvDbHAlignmentSCS>     BrxCvDbHAlignmentSCSPtr;
typedef AcSharedPtr<BrxCvDbHAlignmentSTS>     BrxCvDbHAlignmentSTSPtr;
typedef AcSharedPtr<BrxCvDbHAlignmentSSCSS>   BrxCvDbHAlignmentSSCSSPtr;

class BrxCvDbVAlignment;
class BrxCvDbVAlignmentElement;
class BrxCvDbVAlignmentPVI;
class BrxCvDbVAlignmentCurve;
class BrxCvDbVAlignmentTangent;
class BrxCvDbVAlignmentArc;
class BrxCvDbVAlignmentParabola;

typedef AcSharedPtr<BrxCvDbVAlignmentElement>   BrxCvDbVAlignmentElementPtr;
typedef AcSharedPtr<BrxCvDbVAlignmentPVI>       BrxCvDbVAlignmentPVIPtr;
typedef AcSharedPtr<BrxCvDbVAlignmentCurve>     BrxCvDbVAlignmentCurvePtr;
typedef AcSharedPtr<BrxCvDbVAlignmentTangent>   BrxCvDbVAlignmentTangentPtr;
typedef AcSharedPtr<BrxCvDbVAlignmentArc>       BrxCvDbVAlignmentArcPtr;
typedef AcSharedPtr<BrxCvDbVAlignmentParabola>  BrxCvDbVAlignmentParabolaPtr;

class BrxCvStationEquation;
class BrxCvStationEquations;

/** Civil View base class */
class BRX_EXPORT BrxCvDbView : public BrxCvDbEntity
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbView);

    BrxCvDbView();
    virtual ~BrxCvDbView();

    // returns the number of graph elements, resp. the graph element at specified index
    Adesk::UInt32 graphCount() const;
    AcDbObjectId  graphAt(Adesk::UInt32 idx) const;

    // removes the specified graph element
    bool removeGraph(const AcDbObjectId& idGraph);

    // get + set the ObjectId of the source horizontal alignment
    AcDbObjectId baseHAlignment() const;
    bool         setBaseHAlignment(const AcDbObjectId& id);

    // get + set the location of the view
    AcGePoint2d origin() const;
    bool        setOrigin(const AcGePoint2d& pnt);

    // get + set the base elevation of the view
    double baseElevation() const;
    bool   setBaseElevation(double elevation);

    // get + set the vertical scale of the view
    double verticalScale() const;
    bool   setVerticalScale(double vScale);

    // get + set the horizontal scale of the view
    double horizontalScale() const;
    bool   setHorizontalScale(double hScale);

    // get + set the length of the view
    double length() const;
    bool   setLength(double viewLength);

    // get + set the height of the view
    double height() const;
    bool   setHeight(double viewHeight);

    // since BRX V22
    bool   addGraph(const AcDbObjectId& idGraph);

    // coordinate transformations
    double toWCSX(double x) const;
    double toWCSY(double y) const;
    AcGePoint2d toWCSPoint2d(const AcGePoint2d& point) const;

    double fromWCSX(double x) const;
    double fromWCSY(double y) const;
    AcGePoint2d fromWCSPoint2d(const AcGePoint2d& point) const;
};

/** Civil VerticalAlignment View base class */
class BRX_EXPORT BrxCvDbVAlignmentView : public BrxCvDbView
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbVAlignmentView);

    BrxCvDbVAlignmentView();
    virtual ~BrxCvDbVAlignmentView();

    // enforces an update of the VerticalAlignment View object
    bool update(bool bUpdateDependencies = true, bool updateOrigin = true);
};

//======================= Horizontal Alignments ==============================

// begin : since BRX V22

// station equation class
class StationEquationImpl;
class BRX_EXPORT BrxCvStationEquation
{
    friend class BrxCvStationEquations;
    std::shared_ptr<StationEquationImpl> m_pImpl = nullptr;  // internal use only

public:
    enum class EStationEquationType
    {
        Increasing = 0,
        Decreasing = 1,
    };

    BrxCvStationEquation();
    BrxCvStationEquation(double rawStation, double stationForward, EStationEquationType type);
    BrxCvStationEquation(const BrxCvStationEquation &equation);
    BrxCvStationEquation& operator=(const BrxCvStationEquation &equation);
    virtual ~BrxCvStationEquation();

    bool isNull() const;

    // get station parameters
    double getRawStation() const;
    double getStationForward() const;
    EStationEquationType getType() const;

    // set station parameters
    // note : the referenced BrxCvDbHAlignment object (if any) must be opened kForWrite !
    bool setRawStation(double rawStation);
    bool setStationForward(double stationForward);
    bool setType(EStationEquationType type);
};

// station equation collection class
class StationEquationsImpl;
class BRX_EXPORT BrxCvStationEquations
{
    friend class BrxCvDbHAlignment;
    std::shared_ptr<StationEquationsImpl> m_pImpl = nullptr;  // internal use only

public:
    BrxCvStationEquations();
    BrxCvStationEquations(BrxCvDbHAlignment* alignmentPtr);
    BrxCvStationEquations(const BrxCvStationEquations& equations);
    BrxCvStationEquations& operator=(const BrxCvStationEquations& equations);
    virtual ~BrxCvStationEquations();

    // get properties functions
    Adesk::UInt64 stationEquationsCount() const;

    double getRefStartingLength() const;
    double getRefRawStartingStation() const;
    double getStartingStation() const;
    double getStation(double rawStation) const;
    double getRawStationFromLength(double length) const;
    double getLengthFromRawStation(double rawStation) const;
    double getStationBack(Adesk::UInt64 idx);

    AcArray<double> getRawStation(double station) const;
    BrxCvStationEquation getStationEquation(Adesk::UInt64 idx) const;

    // set properties functions
    bool setRefStartingLength(double startingStation);
    bool setRefRawStartingStation(double rawStartingStation);

    // edit functions
    bool addStationEquation(const BrxCvStationEquation& equation);
    bool removeStationEquation(Adesk::UInt64 idx);
    bool removeAllStationEquations();

    bool update();
};

// end : since BRX V22

typedef AcArray<BrxCvDbHAlignmentPI*>    BrxCvDbHAlignmentPIArray;
typedef AcArray<BrxCvDbHAlignmentPIPtr>  BrxCvDbHAlignmentPIPtrArray;

/** Civil Db Horizontal Alignment base class */
class BRX_EXPORT BrxCvDbHAlignment : public BrxCvDbCurve
{
public:
    enum class EHAlignmentVisualStyle
    {
        eUndefined         = 0x0,
        eElements          = 0x1,
        eTangentExtensions = 0x2,
        eElementExtensions = 0x4,
    };

    enum class EArcType  // since BRX V22
    {
        eCompound = 0,
        eReverse  = 1
    };

    enum class EArcParameterType  // since BRX V22
    {
        eRadius            = 0,
        eDegreeOfCurve     = 1,
        eTangentLength     = 2,
        eChordLength       = 3,
        eCurveLength       = 4,
        eExternalDist      = 5, 
        eMiddleOrdinate    = 6,
        eCurveAngle        = 7,
        eCurveThroughPoint = 8
    };

    enum class ESpiralDefinitionType
    {
        eClothoid      = 0,
        eCubicParabola = 1
    };

    enum class ESpiralParameterType
    {
        eParamA      = 0,
        eParamLength = 1
    };

    ACDB_DECLARE_MEMBERS(BrxCvDbHAlignment);

    BrxCvDbHAlignment();
    virtual ~BrxCvDbHAlignment();

    // returns number of all vertical alignments belonging to this horizontal alignment
    Adesk::UInt32 verticalAlignmentCount() const;

    // returns AcDbObjectId of the vertical alignment at specified index
    AcDbObjectId verticalAlignmentAt(Adesk::UInt32 index) const;

    // returns number of all 3D alignments belonging to this horizontal alignment
    Adesk::UInt32 alignment3dCount() const;

    // returns AcDbObjectId of the 3D alignment at specified index
    AcDbObjectId alignment3dAt(Adesk::UInt32 index) const;
     
    // returns number of all vertical alignment views belonging to this horizontal alignment
    Adesk::UInt32 verticalAlignmentViewCount() const;

    // returns AcDbObjectId of the vertical alignment view at specified index
    AcDbObjectId verticalAlignmentViewAt(Adesk::UInt32 index) const;
 
    // returns total length of the horizontal alignment
    double length() const;

    // returns number of all elements belonging to this horizontal alignment
    size_t elementCount() const;

    // gets 'station' and 'offset' at given point;
    // range can be specified with 'fromStation' and 'toStation' parameters;
    // returns true if successful
    bool getStationAtPoint(const AcGePoint2d& point, double& station, double& offset,
                           double* fromStation = nullptr, double* toStation = nullptr) const;

    // gets a point at specified station
    // returns false if station is out of range
    bool getPointAtStation(const double station, AcGePoint2d& pt) const;

    // returns id of the first element in this horizontal alignment
    Adesk::UInt64 firstElementId() const;

    // returns id of the last element in this horizontal alignment
    Adesk::UInt64 lastElementId() const;

    // returns id of the first line element in this horizontal alignment
    Adesk::UInt64 firstLineElementId() const;

    // returns id of the first line element that follows the element with specified id
    Adesk::UInt64 nextLineElementId(Adesk::UInt64 id) const;

    // returns id of the first line element that precedes the element with specified id
    Adesk::UInt64 previousLineElementId(Adesk::UInt64 id) const;

    // returns the element with specified id
    BrxCvDbHAlignmentElementPtr elementAtId(Adesk::UInt64 id) const;

    // returns the element at specified station
    BrxCvDbHAlignmentElementPtr elementAtStation(double station) const;

    // returns the id of the curve at specified pi
    Adesk::UInt64 curveAtPI(const BrxCvDbHAlignmentPI* pi) const;

    // returns the array of PIs (points of intersection);
    BrxCvDbHAlignmentPIPtrArray getPIsArray() const;

    // since BRX V22

    // gets unordered array of all element ids; returns result status;
    Acad::ErrorStatus getUnorderedElementIds(AcArray<Adesk::UInt64>& elementIds) const;

    // returns element id for given gsMarker
    Adesk::UInt64 getElementId(Adesk::GsMarker gsMarker) const;

    // update this BrxCvDbHAlignment object, optionally including dependencies (default); returns success
    bool update(bool updateDependencies = true);

    // returns the curve radius at specified position 'parameter'; returns result status
    Acad::ErrorStatus getRadius(double param, double& radius) const;

    //----- add 'line' alignment element functions

    // adds a fixed line at specified 'previous' position index, using given length; returns element index
    Adesk::UInt64 addLineFixed(Adesk::UInt64 prevId, double length);

    // adds a fixed line defined with startPoint + endPoint; returns element index
    Adesk::UInt64 addLineFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint);

    // adds a line element at next position index and the specified pass-through point; returns element index
    Adesk::UInt64 addLineTo(Adesk::UInt64 nextId, const AcGePoint2d& point);

    // adds a line element at previous position index and the specified pass-through point; returns element index
    Adesk::UInt64 addLineFrom(Adesk::UInt64 prevId, const AcGePoint2d& point);

    // adds a line element at next position index and the specified element length; returns element index
    Adesk::UInt64 addLineTo(Adesk::UInt64 nextId, double length);

    // adds a line element at previous position index and the specified element length; returns element index
    Adesk::UInt64 addLineFrom(Adesk::UInt64 prevId, double length);

    // adds a line element defined by previous and next element; returns element index
    Adesk::UInt64 addLineBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId);

    // inserts a line element defined by startPoint + endPoint, after the element with prevId; returns element index
    Adesk::UInt64 insertLineFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, Adesk::UInt64 prevId);

    //----- add 'arc' alignment element functions

    // adds an automatic arc element between the previous and next position index; returns element index
    Adesk::UInt64 addArcAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId);

    // adds an arc element defined by center point, radius and direction; returns element index
    Adesk::UInt64 addArcFixed(const AcGePoint2d& center, double radius, bool isClockwise);

    // adds an arc element defined by start point, middle point and end point; returns element index
    Adesk::UInt64 addArcFixed(const AcGePoint2d& startPoint, const AcGePoint2d& midPoint, const AcGePoint2d& endPoint);

    // adds an arc element defined by next position index and a passthrough point; returns element index
    Adesk::UInt64 addArcTo(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint);

    // adds an arc element defined by previous position index and a passthrough point; returns element index
    Adesk::UInt64 addArcFrom(Adesk::UInt64 prevId, const AcGePoint2d& passThroughPoint);

    // adds an arc element defined by next position index, a passthrough point and the direction at the passthrough point;
    // returns element index
    Adesk::UInt64 addArcTo(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint, const AcGeVector2d& direction);

    // adds an arc element defined by previous position index, a passthrough point and the direction at the passthrough point;
    // returns element index
    Adesk::UInt64 addArcFrom(Adesk::UInt64 prevId, const AcGePoint2d& passThroughPoint, const AcGeVector2d& direction);

    // adds an arc element defined by next position index, a passthrough point, the radius, a flag defining whether
    // the arc is greater PI and the curve type; returns element index
    Adesk::UInt64 addArcTo(Adesk::UInt64 nextId, const AcGePoint2d& passThroughPoint, double radius,
                           bool isGreaterThan180, EArcType arcType);

    // adds an arc element defined by previous position index, a passthrough point, the radius, a flag defining whether
    // the arc is greater PI and the curve type; returns element index
    Adesk::UInt64 addArcFrom(Adesk::UInt64 previous, const AcGePoint2d& passThroughPoint, double radius,
                             bool isGreaterThan180, EArcType arcType);

    // adds an arc element defined by next position index, the radius, a constraint type and value;
    // returns element index
    Adesk::UInt64 addArcTo(Adesk::UInt64 nextId, double radius, double paramValue,
                           EArcParameterType paramType, bool isClockwise);

    // adds an arc element defined by previous position index, the radius, a constraint type and value;
    // returns element index
    Adesk::UInt64 addArcFrom(Adesk::UInt64 prevId, double radius, double paramValue,
                             EArcParameterType paramType, bool isClockwise);

    // adds an arc element between previous and next position index, using a passthrough point;
    // returns element index
    Adesk::UInt64 addArcBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, const AcGePoint2d& passThrough);

    // adds an arc element between previous and next position index, using parameter of given type, and arc size and arc type
    // returns element index
    Adesk::UInt64 addArcBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double parameter,
                                EArcParameterType paramType = EArcParameterType::eRadius,
                                bool isGreaterThan180 = false, EArcType arcType = EArcType::eCompound);

    //----- add 'spiral' alignment element functions

    // adds a spiral-curve-spiral element between previous and next position index, using 2 parameters of given type,
    // radius, and spiral type;
    // returns element index
    Adesk::UInt64 addSCSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
                                double spiral1Param, double spiral2Param,
                                ESpiralParameterType spiralParamType,
                                double radius,
                                ESpiralDefinitionType spiralDefinition);

    // adds a spiral-line-spiral element between previous and next position index, using 2 parameters of given type,
    // and spiral parameter and definition type;
    // returns element index
    Adesk::UInt64 addSTSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
                                double spiral1Param, double spiral2Param,
                                ESpiralParameterType spiralParamType,
                                ESpiralDefinitionType spiralDefinition);

    // adds a spiral-spiral element between previous and next position index, using ratio and
    // spiral parameter and definition type;
    // returns element index
    Adesk::UInt64 addSSBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
                               double spiralRatio,
                               ESpiralParameterType spiralParamType,
                               ESpiralDefinitionType spiralDefinition);

    // adds a spiral element at previous position index, using radius, length and
    // arc orientation flag, based on the spiral definition type
    // returns element index
    Adesk::UInt64 addSpiralFrom(Adesk::UInt64 prevId, double radius, double length, bool isClockwise,
                                ESpiralDefinitionType spiralDefinition);

    // adds a spiral element at next position index, using radius, length and the spiral definition type
    // returns element index
    Adesk::UInt64 addSpiralTo(Adesk::UInt64 nextId, double radius, double length, bool isClockwise,
                              ESpiralDefinitionType spiralDefinition);

    // adds a spiral element between previous and next position index, and the spiral definition type
    // returns element index
    Adesk::UInt64 addSpiralBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId,
                                   ESpiralDefinitionType spiralDefinition);

    // adds a spiral-line element at previous position index, constrained by a spiral parameter
    // and passthrough point for the line
    // returns element index
    Adesk::UInt64 addSTFrom(Adesk::UInt64 prevId, double spiralParam,
                            ESpiralParameterType spiralParamType,
                            const AcGePoint2d& passThroughPoint,
                            ESpiralDefinitionType spiralDefinition);

    // adds a line-spiral element at next position index, constrained by a spiral parameter and
    // passthrough point for the line
    // returns element index
    Adesk::UInt64 addTSTo(Adesk::UInt64 nextId, double spiralParam,
                          ESpiralParameterType spiralParamType,
                          const AcGePoint2d& passThroughPoint,
                          ESpiralDefinitionType spiralDefinition);

    // adds a spiral-line element at previous position index, and constrained by spiral parameters
    // and tangent length
    // returns element index
    Adesk::UInt64 addSTFrom(Adesk::UInt64 prevId, double spiralParam,
                            ESpiralParameterType spiralParamType,
                            double tangentLength,
                            ESpiralDefinitionType spiralDefinition);

    // adds a line-spiral element at next position index, and constrained by spiral parameters
    // and tangent length
    // returns element index
    Adesk::UInt64 addTSTo(Adesk::UInt64 nextId, double spiralParam,
                          ESpiralParameterType spiralParamType,
                          double tangentLength,
                          ESpiralDefinitionType spiralDefinition);

    // adds a spiral-curve element at previous position index, and constrained by spiral parameters,
    // passthrough point and orientation for the arc
    // returns element index
    Adesk::UInt64 addSCFrom(Adesk::UInt64 prevId, double spiralParam,
                            ESpiralParameterType spiralParamType,
                            double radius, const AcGePoint2d& passThroughPoint,
                            bool isGreaterThan180,
                            ESpiralDefinitionType spiralDefinition);

    // adds curve with spiral element defined at next position index, and constrained by a spiral
    // parameter and passthrough point for the arc
    // returns element index
    Adesk::UInt64 addCSTo(Adesk::UInt64 nextId, double spiralParam,
                          ESpiralParameterType spiralParamType,
                          double radius, const AcGePoint2d& passThroughPoint,
                          bool isGreaterThan180,
                          ESpiralDefinitionType spiralDefinition);

    // adds arc with spiral element defined at previous position index, and constrained by a spiral
    // parameter and arc radius and arc length
    // returns element index
    Adesk::UInt64 addSCFrom(Adesk::UInt64 prevId, double spiralParam,
                            ESpiralParameterType spiralParamType,
                            double radius, double arcLength, bool isClockwise,
                            ESpiralDefinitionType spiralDefinition);

    // adds arc with spiral element defined at next position index, and constrained by a spiral
    // parameter and arc radius and arc length
    // returns element index
    Adesk::UInt64 addCSTo(Adesk::UInt64 nextId, double spiralParam,
                          ESpiralParameterType spiralParamType,
                          double radius, double arcLength, bool isClockwise,
                          ESpiralDefinitionType spiralDefinition);

    // adds SSCSS element defined at previous position index, and constrained by spiral1
    // and spiral2 parameters, arc radius and arc passthrough point
    // returns element index
    Adesk::UInt64 addSSCFrom(Adesk::UInt64 prevId, double spiral1Param, double spiral2Param,
                             ESpiralParameterType spiralParamType,
                             double radius, const AcGePoint2d& passThroughPoint,
                             ESpiralDefinitionType spiralDefinition);

    // adds SSCSS element defined at next position index, and constrained by spiral1
    // and spiral2 parameters, arc radius and arc passthrough point
    // returns element index
    Adesk::UInt64 addCSSTo(Adesk::UInt64 nextId, double spiral1Param, double spiral2Param,
                           ESpiralParameterType spiralParamType,
                           double radius, const AcGePoint2d& passThroughPoint,
                           ESpiralDefinitionType spiralDefinition);

    // adds an automatic spiral-curve-spiral element between the previous and next position index;
    // returns element index
    Adesk::UInt64 addSCSAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId);

    //----- general query and edit functions -----

    // deletes the element at specified position index; returns success status
    bool deleteElement(Adesk::UInt64 id);

    // get and set the alignment style, combined bit flags of HAlignmentVisualStyle
    Adesk::UInt32 style() const;
    bool setStyle(const Adesk::UInt32 style);

    // get and set alignment element colors; all color values are ACI index colors (0...256)
    Adesk::UInt32 elementExtensionColor() const;
    Adesk::UInt32 tangentExtensionColor() const;
    Adesk::UInt32 lineElementColor() const;
    Adesk::UInt32 curveElementColor() const;
    Adesk::UInt32 spiralElementColor() const;
    //
    bool setElementExtensionColor(const Adesk::UInt32 color);
    bool setTangentExtensionColor(const Adesk::UInt32 color);
    bool setLineElementColor(const Adesk::UInt32 color);
    bool setCurveElementColor(const Adesk::UInt32 color);
    bool setSpiralElementColor(const Adesk::UInt32 color);

    // get and set station equations; this horizontal alignment must be opened kForWrite to set the equations;
    BrxCvStationEquations stationEquations() const;
    bool setStationEquations(const BrxCvStationEquations& stationEquations);
};

//----------------------- Civil Horizontal Alignment Elements -----------------------

/** Civil HorizontalAlignment base class */
class BRX_EXPORT BrxCvDbHAlignmentElement : public BrxCvDbSubObject
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbHAlignmentElement);

    enum class EElementType
    {
        eUndefined         = 0,
        eLine              = 1,
        eArc               = 2,
        eSpiral            = 3,
        eSpiralCurveSpiral = 4,
        eSpiralLineSpiral  = 5,
        eSpiralLine        = 6,
        eLineSpiral        = 7,
        eSpiralCurve       = 8,
        eCurveSpiral       = 9,
        eSpiralSpiralCurveSpiralSpiral      = 10,
        eMultipleSegments                   = 11,
        eSpiralCurveSpiralCurveSpiral       = 12,
        eSpiralCurveSpiralSpiralCurveSpiral = 13,
        eSpiralSpiral      = 14,
        eSpiralSpiralCurve = 15,
        eCurveSpiralSpiral = 16,
        eCurveLineCurve    = 17,
        eCurveReverseCurve = 18,
        eCurveCurveReverseCurve = 19,
        ePI                = 100
    };

    enum class ETangencyConstraint
    {
        eUndefined = 0,
        eFixed     = 1,
        ePrevious  = 2,
        eNext      = 3,
        eBoth      = 4,
    };

    enum class EParameterConstraint
    {
        eUndefined                  = 0,
        eAutomatic                  = 100,

        eLine_TwoPoints             = 200,
        eLine_ThroughPoint          = 201,
        eLine_Length                = 202,
        eLine_BestFit               = 203,

        eArc_ThreePoints            = 300,
        eArc_CenterRadius           = 301,
        eArc_CenterPassThrough      = 302,
        eArc_PassThroughRadius      = 303,
        eArc_PassThroughAttachToEnd = 304,
        eArc_PassThroughDirection   = 305,
        eArc_Radius                 = 306,
        eArc_PassThrough            = 307,
        eArc_RadiusAndLength        = 308,
        eArc_PointOnTangent         = 309,
        eArc_BestFit = 310,

        eSCS_SpiralInRadiusSpiralOut            = 400,
        eSCS_SpiralLengthRadiusPassThrough      = 401,
        eSCS_SpiralLengthRadiusArcLength        = 402,
        eSCS_SpiralLengthRadius                 = 403,
        eSCS_SpiralLength                       = 404,
        eSCS_SpiralInLengthSpiralOutLength      = 405,
        eSCS_SpiralInAValSpiralOutAVal          = 406,
        eSCS_SpiralInAValRadiusSpiralOutAVal    = 407,
        eSCS_SpiralAValRadiusPassThrough        = 408,
        eSCS_SpiralAValRadiusArcLength          = 409,
        eSCS_SpiralAValRadius                   = 410,
        eSCS_SpiralAVal                         = 411,
        eSCS_PointOnTangent                     = 412,

        eSpiral_StartPointDirRadiusLength               = 500,
        eSpiral_StartPointDirStartAndEndRadiusLength    = 501,

        eSTS_SpiralInLengthSpiralOutLength  = 600,
        eSTS_TangentLength                  = 601,
        eSTS_SpiralInAValSpiralOutAVal      = 602,
        eSTS_SpiralLengthTangentPassThrough = 603,
        eSTS_SpiralLengthTangentLength      = 604,
        eSTS_SpiralAValTangentPassThrough   = 605,
        eSTS_SpiralAValTangentLength        = 606,

        // since BRX V22
        eSSCSS_Sp1LenSp2LenRadiusPt   = 700,
        eSSCSS_Sp1LenSp2LenPt1Pt2     = 701,
        eSSCSS_Sp1AValSp2AValRadiusPt = 702,
        eSSCSS_Sp1AValSp2AValPt1Pt2   = 703,
    };

    virtual ~BrxCvDbHAlignmentElement();

    // alignment element iteration
    Adesk::UInt64 id() const;
    Adesk::UInt64 previousId() const;
    Adesk::UInt64 nextId() const;

    // returns type of this horizontal alignment element
    EElementType type() const;

    // returns type of tangency constraint for this horizontal alignment element
    ETangencyConstraint tangencyConstraint() const;

    // returns type of parameter constraint for this horizontal alignment element
    EParameterConstraint parameterConstraint() const;

    // since BRX 22

    // returns whether this horizontal alignment element is a subentity or not
    bool isSubentity() const;

    // alignment element iteration;
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool setPreviousId(Adesk::UInt64 id);
    bool setNextId(Adesk::UInt64 id);

    // assigns the type of tangency constraint for this horizontal alignment element
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool setTangencyConstraint(ETangencyConstraint constraint);

    // assigns the type of parameter constraint for this horizontal alignment element
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool setParameterConstraint(EParameterConstraint constraint);
};

/** Civil HorizontalAlignment PI (point of intersection) class */
class BRX_EXPORT BrxCvDbHAlignmentPI : public BrxCvDbHAlignmentElement
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbHAlignmentPI);

    BrxCvDbHAlignmentPI();
    BrxCvDbHAlignmentPI(BrxCvDbHAlignment* alignment);
    virtual ~BrxCvDbHAlignmentPI();

    AcGePoint2d location() const;
};

/** Civil HorizontalAlignment Curve base class */
class BRX_EXPORT BrxCvDbHAlignmentCurve : public BrxCvDbHAlignmentElement
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbHAlignmentCurve);

    virtual ~BrxCvDbHAlignmentCurve();

    // returns the start point of the alignment curve
    AcGePoint2d startPoint() const;

    // returns the end point of the alignment curve
    AcGePoint2d endPoint() const;

    // returns the start station parameter of the alignment curve
    double startStation() const;

    // returns the end station parameter of the alignment curve
    double endStation() const;

    // returns the total length of the alignment curve
    double length() const;
};

/** Civil HorizontalAlignment Line class */
class BRX_EXPORT BrxCvDbHAlignmentLine : public BrxCvDbHAlignmentCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbHAlignmentLine);

    BrxCvDbHAlignmentLine();
    BrxCvDbHAlignmentLine(BrxCvDbHAlignment* alignment);
    virtual ~BrxCvDbHAlignmentLine();

    // returns the first passThrough point of this line element
    AcGePoint2d passThroughPoint1();

    // returns the second passThrough point of this line element
    AcGePoint2d passThroughPoint2();

    // since BRX 22
    
    // access the length parameter of this line element
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    double paramLength() const;
    bool   setParamLength(double length);

    // access the points and length parameters of this line element
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool setPassThroughPoint1(const AcGePoint2d& point);
    bool setPassThroughPoint2(const AcGePoint2d& point);
};

/** Civil HorizontalAlignment Arc class */
class BRX_EXPORT BrxCvDbHAlignmentArc : public BrxCvDbHAlignmentCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbHAlignmentArc);

    BrxCvDbHAlignmentArc();
    BrxCvDbHAlignmentArc(BrxCvDbHAlignment* alignment);
    virtual ~BrxCvDbHAlignmentArc();

    // get geometric parameters of the arc alignment element
    double radius() const;
    AcGePoint2d center() const;
    bool isClockwise() const;

    // since BRX 22

    // assign geometric parameters of the arc alignment element
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool setRadius(double rad);
    bool setCenter(const AcGePoint2d& center);
    bool setClockwise(bool isClockwise);

    // access the arc length parameter of the arc alignment element
    bool isLessThan180() const;
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool setLessThan180(bool isLessThan180);

    // access the arc compound status of the arc alignment element
    bool isCompound() const;
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool setCompound(bool isCompound);

    // access the arc definition points of the arc alignment element
    AcGePoint2d passThroughPoint1() const;
    AcGePoint2d passThroughPoint2() const;
    AcGePoint2d passThroughPoint3() const;
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool setPassThroughPoint1(const AcGePoint2d& point);
    bool setPassThroughPoint2(const AcGePoint2d& point);
    bool setPassThroughPoint3(const AcGePoint2d& point);

    // access the length parameter of this line alignment element
    double paramLength() const;
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool   setParamLength(double length);
};

/** Civil HorizontalAlignment Spiral class */
class BRX_EXPORT BrxCvDbHAlignmentSpiral : public BrxCvDbHAlignmentCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbHAlignmentSpiral);

    enum class ESpiralCurveType
    {
        eInCurve  = 0,
        eOutCurve = 1
    };

    enum class ESpiralDefinitionType
    {
        eClothoid      = 0,
        eCubicParabola = 1
    };

    enum class ESpiralParameterType
    {
        eParamA      = 0,
        eParamLength = 1
    };

    enum class ESpiralDirectionType  // since BRX V22
    {
        eDirectionRight = 0,
        eDirectionLeft  = 1
    };

    BrxCvDbHAlignmentSpiral();
    BrxCvDbHAlignmentSpiral(BrxCvDbHAlignment* alignment);
    virtual ~BrxCvDbHAlignmentSpiral();

    // returns the incoming curve radius
    double radiusIn() const;

    // returns the outgoing curve radius
    double radiusOut() const;

    bool isCompound() const;

    // returns eInCurve or eOutCurve
    ESpiralCurveType spiralCurveType() const;

    // returns true if spiral is clockwise oriented
    bool isClockwise() const;

    // returns type of spiral definition: eClothoid, eCubicParabola ...
    ESpiralDefinitionType spiralDefinition() const;

    // returns direction value at start point
    double startDirection() const;

    // returns direction value at end point
    double endDirection() const;

    // returns parameter A of the spiral curve
    double paramA() const;

    // returns parameter Length of the spiral curve
    double paramLength() const;

    // since BRX 22

    // assign the parameters of this spiral curve alignment element
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool setRadiusIn(double rad);
    bool setRadiusOut(double rad);
    bool setCompound(bool isCompound);
    bool setClockwise(bool isClockwise);
    bool setSpiralCurveType(ESpiralCurveType spiralCurveType);
    bool setSpiralDefinition(ESpiralDefinitionType spiralCurveDefinition);
    bool setStartDirection(double direction);
    bool setEndDirection(double direction);
    bool setParamA(double paramA);
    bool setParamLength(double paramLength);
};

/** Civil HorizontalAlignment Spiral-Curve-Spiral class */
class BRX_EXPORT BrxCvDbHAlignmentSCS : public BrxCvDbHAlignmentCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbHAlignmentSCS);

    BrxCvDbHAlignmentSCS();
    BrxCvDbHAlignmentSCS(BrxCvDbHAlignment* alignment);
    virtual ~BrxCvDbHAlignmentSCS();

    // returns arc sub-element of this spiral-curve-spiral element
    BrxCvDbHAlignmentArcPtr arc() const;

    // returns spiral IN sub-element of this spiral-curve-spiral element
    BrxCvDbHAlignmentSpiralPtr spiralIn() const;

    // returns spiral OUT sub-element of this spiral-curve-spiral element
    BrxCvDbHAlignmentSpiralPtr spiralOut() const;
};

// BEGIN : since BRX 22

/** Civil HorizontalAlignment Spiral-Tangent-Spiral class */
class BRX_EXPORT BrxCvDbHAlignmentSTS : public BrxCvDbHAlignmentCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbHAlignmentSTS);

    BrxCvDbHAlignmentSTS();
    BrxCvDbHAlignmentSTS(BrxCvDbHAlignment* alignment);
    virtual ~BrxCvDbHAlignmentSTS();

    // returns line subelement of this spiral-tangent-spiral element
    BrxCvDbHAlignmentLinePtr line() const;

    // returns the IN spiral subelement of this spiral-tangent-spiral element
    BrxCvDbHAlignmentSpiralPtr spiralIn() const;

    // returns the OUT spiral subelement of this spiral-tangent-spiral element
    BrxCvDbHAlignmentSpiralPtr spiralOut() const;

    // returns spiral ratio for spiral-spiral curve: L1/L2 or A1/A2, depending on constraint parameter
    double spiralRatio() const;

    // sets spiral ratio for spiral-spiral curve: L1/L2 or A1/A2, depending on constraint parameter
    // note : parent BrxCvDbHAlignment object must be opened kForWrite !
    bool setSpiralRatio(double ratio);
};

/** Civil HorizontalAlignment Spiral-Spiral-Curve-Spiral-Spiral class */
class BRX_EXPORT BrxCvDbHAlignmentSSCSS : public BrxCvDbHAlignmentCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbHAlignmentSSCSS);

    BrxCvDbHAlignmentSSCSS();
    BrxCvDbHAlignmentSSCSS(BrxCvDbHAlignment* alignment);
    virtual ~BrxCvDbHAlignmentSSCSS();

    // returns arc sub-element of this spiral-spiral-curve-spiral-spiral element
    BrxCvDbHAlignmentArcPtr arc() const;

    // returns the spiral1 subelement of this spiral-spiral-curve-spiral-spiral element
    BrxCvDbHAlignmentSpiralPtr spiral1() const;

    // returns the spiral2 subelement of this spiral-spiral-curve-spiral-spiral element
    BrxCvDbHAlignmentSpiralPtr spiral2() const;

    // returns the spiral3 subelement of this spiral-spiral-curve-spiral-spiral element
    BrxCvDbHAlignmentSpiralPtr spiral3() const;

    // returns the spiral4 subelement of this spiral-spiral-curve-spiral-spiral element
    BrxCvDbHAlignmentSpiralPtr spiral4() const;
};

// END : since BRX 22


//======================= Vertical Alignments ==============================

typedef AcArray<BrxCvDbVAlignmentPVI*>    BrxCvDbVAlignmentPVIArray;
typedef AcArray<BrxCvDbVAlignmentPVIPtr>  BrxCvDbVAlignmentPVIPtrArray;

/** Civil Db Vertical Alignment base class */
class BRX_EXPORT BrxCvDbVAlignment : public BrxCvDbCurve
{
public:
    enum class EVAlignmentType
    {
        eLayout         = 0,
        eStaticSurface  = 1,
        eDynamicSurface = 2,
        eAutomatic      = 3,
    };

    enum class EVAlignmentVisualStyle
    {
        eElements   = 0x01,
        eTangents   = 0x02,
        eExtensions = 0x04,
    };

    ACDB_DECLARE_MEMBERS(BrxCvDbVAlignment);

    BrxCvDbVAlignment();
    virtual ~BrxCvDbVAlignment();

    // returns the AcDbObjectId of the base alignment
    AcDbObjectId baseHAlignment() const;

    // returns the AcDbObjectId of the base surface
    AcDbObjectId baseSurface() const;

    // returns minimum elevation of this vertical alignment
    double elevationMin() const;

    // returns maximum elevation of this vertical alignment
    double elevationMax() const;

    // gets elevation at specified station, returns true if successful
    bool getElevationAt(double station, double& elevation) const;

    // returns total length of the vertical alignment
    double length() const;

    // returns number of all elements belonging to this vertical alignment
    size_t elementCount() const;

    // returns type of vertical alignment: 
    EVAlignmentType type() const;
    
    // returns id of the first element in this vertical alignment
    Adesk::UInt64 firstElementId() const;

    // returns id of the last element in this vertical alignment
    Adesk::UInt64 lastElementId() const;

    // returns id of the first tangent element in this vertical alignment
    Adesk::UInt64 firstTangentElementId() const;

    // returns id of the first tangent element that follows the element with specified id
    Adesk::UInt64 nextTangentElementId(Adesk::UInt64 id) const;

    // returns id of the first tangent element that precedes the element with specified id
    Adesk::UInt64 previousTangentElementId(Adesk::UInt64 id) const;

    // returns the element with specified id
    BrxCvDbVAlignmentElementPtr elementAtId(Adesk::UInt64 id) const;

    // returns the id of the curve at specified PVI (point of vertical intersection)
    Adesk::UInt64 curveAtPVI(const BrxCvDbVAlignmentPVI* pvi) const;

    // returns pvi at specified curve
    BrxCvDbVAlignmentPVIPtr pviAtCurve(const BrxCvDbVAlignmentCurve* curve) const;

    // returns the array of PVIs (points of vertical intersections)
    BrxCvDbVAlignmentPVIPtrArray getPVIsArrays() const;

    // since BRX 22

    // gets unordered array of all element ids; returns result status;
    Acad::ErrorStatus getUnorderedElementIds(AcArray<Adesk::UInt64>& elementIds) const;

    // returns element id for given gsMarker
    Adesk::UInt64 getElementId(Adesk::GsMarker gsMarker) const;

    Acad::ErrorStatus getRadius(double param, double& radius) const;
    bool getElevations(AcGePoint2dArray& elevations) const;

    Adesk::UInt32 style() const;                // bit-combination of 'VAlignmentVisualStyle'
    Adesk::UInt32 tangentPolygonColor() const;  // ACI index color 0...256
    Adesk::UInt32 lineElementColor() const;     // ACI index color 0...256
    Adesk::UInt32 curveElementColor() const;    // ACI index color 0...256

    // note : the BrxCvDbVAlignment object must be opened kForWrite for the following functions !
    bool setBaseHAlignment(const AcDbObjectId& id);
    bool setBaseSurface(const AcDbObjectId& id);
    bool setType(const EVAlignmentType type);

    bool setStyle(const Adesk::UInt32 style);               // bit-combination of 'VAlignmentVisualStyle'
    bool setTangentPolygonColor(const Adesk::UInt32 color); // ACI index color 0...256
    bool setLineElementColor(const Adesk::UInt32 color);    // ACI index color 0...256
    bool setCurveElementColor(const Adesk::UInt32 color);   // ACI index color 0...256

    Adesk::UInt64 addTangentFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint);
    Adesk::UInt64 insertTangentFixed(const AcGePoint2d& startPoint, const AcGePoint2d& endPoint, Adesk::UInt64 prevId);
    Adesk::UInt64 addArcBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double radius);
    Adesk::UInt64 addArcAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId);
    Adesk::UInt64 addParabolaBetween(Adesk::UInt64 prevId, Adesk::UInt64 nextId, double radius);
    Adesk::UInt64 addParabolaAuto(Adesk::UInt64 prevId, Adesk::UInt64 nextId);

    bool deleteElement(Adesk::UInt64 id);
    bool update(bool updateDependencies = true);
};

//----------------------- Civil Vertical Alignment Elements -----------------------

/** Civil VerticalAlignment base class */
class BRX_EXPORT BrxCvDbVAlignmentElement : public BrxCvDbSubObject
{
public:
    enum class EElementType
    {
        eUndefined = 0,
        eTangent   = 1,
        eArc       = 2,
        eParabola  = 3,
        ePVI       = 100,
    };

    enum class ETangencyConstraint
    {
        eUndefined = 0,
        eFixed     = 1,
        ePrevious  = 2,
        eNext      = 3,
        eBoth      = 4,
    };

    enum class EParameterConstraint
    {
        eUndefined         = 0,
        ePassThroughPoints = 1,
        eRadius            = 2,
        eLength            = 3,
        eAngle             = 4,
        eAutomatic         = 5,
        ePointOnTangent    = 6,
    };

    ACDB_DECLARE_MEMBERS(BrxCvDbVAlignmentElement);

    virtual ~BrxCvDbVAlignmentElement();

    // alignment element iteration
    Adesk::UInt64 id() const;
    Adesk::UInt64 previousId() const;
    Adesk::UInt64 nextId() const;

    // returns type of this vertical alignment element
    EElementType type() const;

    // returns type of tangency constraint for this vertical alignment element
    ETangencyConstraint tangencyConstraint() const;

    // returns type of parameter constraint for this vertical alignment element
    EParameterConstraint parameterConstraint() const;

    // since BRX 22
    // note : the BrxCvDbVAlignment parent object must be opened kForWrite for the following functions !
    bool setPreviousId(Adesk::UInt64 id);
    bool setNextId(Adesk::UInt64 id);
    bool setTangencyConstraint(ETangencyConstraint constraint);
    bool setParameterConstraint(EParameterConstraint constraint);
};

/** Civil VerticalAlignment PVI (point of vertical intersection) class */
class BRX_EXPORT BrxCvDbVAlignmentPVI : public BrxCvDbVAlignmentElement
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbVAlignmentPVI);

    BrxCvDbVAlignmentPVI();
    BrxCvDbVAlignmentPVI(BrxCvDbVAlignment* alignment);
    virtual ~BrxCvDbVAlignmentPVI();

    AcGePoint2d location() const;
};

/** Civil VerticalAlignment Curve base class */
class BRX_EXPORT BrxCvDbVAlignmentCurve : public BrxCvDbVAlignmentElement
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbVAlignmentCurve);

    virtual ~BrxCvDbVAlignmentCurve();

    AcGePoint2d startPoint() const;
    AcGePoint2d endPoint() const;
    double length() const;
};

/** Civil VerticalAlignment Tangent class */
class BRX_EXPORT BrxCvDbVAlignmentTangent : public BrxCvDbVAlignmentCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbVAlignmentTangent);

    BrxCvDbVAlignmentTangent();
    BrxCvDbVAlignmentTangent(BrxCvDbVAlignment* alignment);
    virtual ~BrxCvDbVAlignmentTangent();

    // returns the first passThrough point of this tangent element
    AcGePoint2d passThroughPoint1() const;

    // returns the second passThrough point of this tangent element
    AcGePoint2d passThroughPoint2() const;

    // since BRX 22
    // assigns the 'PassThrough' points for this BrxCvDbVAlignmentTangent object
    // note : the BrxCvDbVAlignment parent object must be opened kForWrite for the following functions !
    bool setPassThroughPoint1(const AcGePoint2d& point);
    bool setPassThroughPoint2(const AcGePoint2d& point);
};

/** Civil VerticalAlignment Arc class */
class BRX_EXPORT BrxCvDbVAlignmentArc : public BrxCvDbVAlignmentCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbVAlignmentArc);

    BrxCvDbVAlignmentArc();
    BrxCvDbVAlignmentArc(BrxCvDbVAlignment* alignment);
    virtual ~BrxCvDbVAlignmentArc();

    // returns the radius of the curve
    double radius() const;

    // returns the grade at start point
    double gradeIn() const;

    // returns the grade at end point
    double gradeOut() const;

    // returns the center of the arc
    AcGePoint2d center() const;

    // returns true if the arc is clockwise, false otherwise
    bool isClockwise() const;

    // since BRX 22
    // assigns the parameters for this BrxCvDbVAlignmentTangent object
    // note : the BrxCvDbVAlignment parent object must be opened kForWrite for the following functions !
    bool setRadius(double rad);
    bool setCenter(const AcGePoint2d& center);
    bool setClockwise(bool isClockwise);
};

/** Civil VerticalAlignment Parabola class */
class BRX_EXPORT BrxCvDbVAlignmentParabola : public BrxCvDbVAlignmentCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDbVAlignmentParabola);

    BrxCvDbVAlignmentParabola();
    BrxCvDbVAlignmentParabola(BrxCvDbVAlignment* alignment);
    virtual ~BrxCvDbVAlignmentParabola();

    // returns the radius of the curve
    double radius() const;

    // returns the grade at start point
    double gradeIn() const;

    // returns the grade at end point
    double gradeOut() const;

    // since BRX 22
    bool setRadius(double rad);
};

//======================= 3D Alignment ==============================

/** Civil Db 3D Alignment base class */
class BRX_EXPORT BrxCvDb3dAlignment : public BrxCvDbCurve
{
public:
    ACDB_DECLARE_MEMBERS(BrxCvDb3dAlignment);

    BrxCvDb3dAlignment();
    virtual ~BrxCvDb3dAlignment();

    // returns object id of the source horizontal alignment
    AcDbObjectId baseHAlignment() const;

    // returns object id of the source vertical alignment
    AcDbObjectId vAlignment() const;

    // returns length of the 3d alignment
    double length() const;

    // since BRX V22
    bool getPointsArray(AcGePoint3dArray& alignmentPoints) const;

    bool setBaseHAlignment(const AcDbObjectId& id);
    bool setVAlignment(const AcDbObjectId& id);
};
