// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmEntity.h"
#include "BmMorphingMap.h"
#include "BmTransf3d.h"
#include "BmPolygonVertexData.h"
#include "BmInterval3d.h"

class AcGiCommonDraw;
class AcDbPolyFaceMesh;

namespace AECGe
{
    class Body;
}

namespace AModeler
{

class ImplBody;

class BM_IMPORTEXPORT Body: public Entity
{
private:
    Body(const AECGe::Body&);

public:
    std::shared_ptr<ImplBody> m_pBrxImp;

public:
    enum torus_type
    {
        DONUT_TORUS = 0,
        APPLE_TORUS,
        LEMON_TORUS,
        VORTEX_TORUS
    };

    enum BodyVerificationFlags
    {
        eVFnoErrorFound = 0x00000000,
        // edges verification
        eVFedgeOwner    = 0x00000001,
        eVFedgeLinks    = 0x00000002,
        eVFedgeFaces    = 0x00000004,
        eVFedgeLoops    = 0x00000008,
        eVFedgePairs    = 0x00000010,
        eVFedgePairDir  = 0x00000020,
        eVFedgePartner  = 0x00000040,
        eVFedgeEuler    = 0x00000080,
        eVFedgeAll      = 0x000000FF,
        eVFedgeDefault  = (eVFedgeAll & ~eVFedgeEuler),
        // faces verification
        eVFfaceOwner    = 0x00000100,
        eVFfaceLinks    = 0x00000200,
        eVFfaceLoops    = 0x00000400,
        eVFfacePlanar   = 0x00000800,
        eVFfaceAll      = 0x0000FF00,
        eVFfaceDefault  = eVFfaceAll,
        // surfaces verification
        eVFsurfaceOwner = 0x00010000,
        eVFsurfaceLinks = 0x00020000,
        eVFsurfaceAll   = 0x00FF0000,
        eVFsurfaceDefault = eVFsurfaceAll,
        // common verification
        eVFnoRedundancy = 0x01000000,
        eVFfaceMinEdges = 0x02000000,
        eVFduplicateVtx = 0x04000000,
        eVFnullLength   = 0x08000000,
        eVFclosedBody   = 0x10000000,
        eVForphanVertex = 0x20000000,
        eVFcommonAll    = 0xFF000000,
        eVFcommonDefault = (eVFcommonAll & ~eVForphanVertex),
        // default verification
        eVFverifyDefault = (eVFcommonDefault | eVFedgeDefault | eVFfaceDefault | eVFsurfaceDefault),
        // complete verification
        eVFverifyAll    = 0xFFFFFFFF,
    };

    Body();
    Body(const Body&);
    ~Body();

    Body boolOper(Body&,BoolOperType,bool = true,TopologyChangeCallback* = NULL,bool = keepInputBodiesWhenBooleanOperationsFail());
    Body combine(Body&);
    Body convexHull() const;
    Body copy() const;
    Body extractFace(Face* = NULL);
    Body extractShell(Face* = NULL);
    Body& align(const Point3d&,const Point3d&,const Point3d&,const Point3d&,const Point3d&,const Point3d&);
    Body& align(const Point3d&,const Vector3d&,const Point3d&,const Vector3d&);
    Body& align(const Point3d&,const Vector3d&,const Vector3d&,const Point3d&,const Vector3d&,const Vector3d&);
    Body& mirror(const Plane&);
    Body& negate();
    Body& rotate(const Line3d&,double);
    Body& scale(const Point3d&,const Vector3d&);
    Body& scale(const Point3d&,double);
    Body& stretch(const Line3d&);
    Body& transform(const Transf3d&);
    Body& transform(const AcGeMatrix3d&);
    Body& translate(const Vector3d&);
    Body* next() const;
    Body* pickBody(const Point3d&,double,const HideIntegerTransform&) const;
    BodyInterferenceType interfere(const Body&) const;
    bool containsNonManifoldEdges() const;
    bool isNegated() const;
    bool isNull() const;
    bool isValid(int = -1) const;
    // verifies for valid topology, with level = 0/1/2;
    // returns a bit field with "BodyVerificationFlags" bits set due to errors found,
    // -1 for NULL body
    int validateTopology(int = -1) const;
    // Regenerate the body by parameter:
    // 1) bSetEdgeAssociations        -> set the partners of edges
    // 2) bNormalizeFaceOrientations  -> normalise the orientation of faces
    // 3) bRemoveCoincidentGeometries -> removes orphaned / redundant vertices, edges and faces
    // 4) bMergeCoplanarFaces         -> merge coplanar faces
    void regenerate(bool bSetEdgeAssociations, bool bNormalizeFaceOrientations, bool bRemoveCoincidentGeometries, bool bMergeCoplanarFaces);
    bool mergeCoincidentVertices();
    bool planeIntersectsBody(const Plane&) const;
    bool slice(const Plane&,std::vector<Point3d>&,std::vector<int>&) const;
    const Interval3d& interval(double = 10.0*epsAbs()) const;
    Curve* curveList() const;
    double volume() const;
    Edge* pickEdge(const Point3d&,double,const HideIntegerTransform&,Body** = NULL) const;
    Face* faceList() const;
    Face* pickFace(const Point3d&,double,const HideIntegerTransform&,Body** = NULL) const;
    int curveCount() const;
    int edgeCount() const;
    int faceCount() const;
    int surfaceCount() const;
    int triangleCount() const;
    int vertexCount() const;
    Point3d closestPointOnBody(Point3d,Entity*&) const;
    PointInBodyLocation contains(const Point3d&) const;
    PointInBodyLocation contains(const Point3d&,Entity*&) const;
    RayBodyIntersection rayIntersection(const Line3d&,double,Entity*&) const;
    RayBodyIntersection rayIntersection(const Line3d&,double,Entity*&,double&) const;
    Surface* surfaceList() const;
    Vertex* pickVertex(const Point3d&,double,const HideIntegerTransform&,Body** = NULL) const;
    Vertex* vertexList() const;
    void addCurve(Curve*);
    void addFace(Face*);
    void addSurface(Surface*);
    void addVertex(Vertex*);
    void changeVertexCoordinates(Vertex*[],Point3d[],int,bool = true);
    void classifyLineSegment(const Point3d&,const Point3d&,std::vector<Point3d>&,std::vector<PointInBodyLocation>&);
    void cleanUpNonManifoldEdgesAndCoincidentFaces();
    void convertToTerrainBody(double,bool,std::vector<Face*>&);
    void copyGeomFrom(const Body&,const Transf3d& = Transf3d::kIdentity);
    void decomposeIntoLumps(std::vector<Body*>&);
    void deleteEmptyFaces();
    void deleteFace(Face*);
    void deleteFaceIntervals() const;
    void deleteFaceIntervalsAndPlanes() const;
    void deleteMarkedCurves(Flag);
    void deleteMarkedFaces(Flag);
    void deleteMarkedSurfaces(Flag);
    void deleteMarkedVertices(Flag);
    void deleteUnusedVerticesSurfacesCurves();
    void deleteVertexSurfaceData() const;
    void evaluateVertexSurfaceData() const;
    void generateUnspecifiedSurfaces(double,int = 2);
    void generateUnspecifiedSurfacesFromApproxEdges(int = 2);
    void getAllEdgesReferencingVertex(const Vertex*,std::vector<Edge*>&) const;
    void getPhysicalEdgesAndVertices(bool,bool,std::vector<Edge*>&,std::vector<Vertex*>&);
    void hideDisplay(const Transf3d&,OutputPolylineCallback*,bool = true,HiddenLineDrawingImprove = kNoDrawingImprove,HideIntegerTransform* = NULL);
    void hideDisplayDxf(const Transf3d&,const wchar_t*,bool = true,HiddenLineDrawingImprove = kNoDrawingImprove);
    void init(bool);
    void makeArcTessellationsInExtrusionsCoincide(const Body&,const Vector3d&,bool&,bool&);
    void massProperties(double&,double&,Point3d&,Point3d&,Point3d&) const;
    void mergeCoplanarEntities(bool = true,bool = true,TopologyChangeCallback* = NULL);
    void mergeCoplanarFaces(Edge*);
    void mergeEqualSurfaces();
    void modified();
    void moveFace(Face*,const Vector3d&,bool,bool,Face*&);
    void print(FILE* = NULL) const;
    void removeFace(Face*);
    void save(const wchar_t*) const;
    void save(FILE*) const;
    void save(SaveRestoreCallback*) const;
    void saveToSat(const wchar_t*,bool = false) const;
    void saveToSat(FILE*,bool = false) const;
    void saveToSat(SaveToSatCallback*,bool = false) const;
    void section(const Plane&,bool = keepInputBodiesWhenBooleanOperationsFail());
    void section(const Plane&,const Point3d&,bool = keepInputBodiesWhenBooleanOperationsFail());
    void setAEFAndBEFFlags();
    void setAEFAndBEFFlags(bool);
    void setColor(Color);
    void setCurveFlags(OnOff,Flag) const;
    void setCurveList(Curve*);
    void setEdgeFlags(OnOff,Flag) const;
    void setFaceFlags(OnOff,Flag) const;
    void setFaceList(Face*);
    void setHiddenLineParams(HiddenLinesDisplay = kHiddenLinesInvisible,bool = false,bool = false);
    void setInterval(const Interval3d&);
    void setNext(Body*);
    void setSurfaceFlags(OnOff,Flag) const;
    void setSurfaceList(Surface*);
    void setVertexFlags(OnOff,Flag) const;
    void setVertexList(Vertex*);
    void stitchFaces(bool = false,bool = false,bool = false);
    // kGenerateTriStrips and kGenerateTriStripsPerSurface are not supported yet
    void triangulate(OutputTriangleCallback*,TriangulationType = kGenerateTriangles,bool = true) const;
    void triangulateAllFaces();
    void triangulateDxf(const wchar_t*,TriangulationType = kGenerateTriangles,bool = true) const;
    void triangulateFace(Face*);

// BRX specific extensions
    // new high level API for streaming and entity conversion
    // Optional arguments:
    // bool   asFaces                 if 'true', shell faces are drawn, otherwise only wireframe graphics
    // bool   bQuadrilaterals         create quadrilaterals
    // bool   bOptimizeToSmoothShells optimize faces for a 'smooth shell' representation
    // double dSmoothAngle            angle (between faces) for 'smooth shell' calculation. Negative value set default of 10°+Eps
    // bool   bKeepApproxEdges        native approx edges keep unchanged, when optimized

    // return : true if graphics was drawn (as shell or wire)
    bool draw                    (AcGiCommonDraw* pCD, bool asFaces, bool bQuadrilaterals = false, bool bOptimizeToSmoothShells = false, double dSmoothAngle = -1.0, bool bKeepApproxEdges = false) const;

    // return : true if any AcDbPolyFaceMesh entity was created
    bool convertToPolyFaceMeshes (std::vector <AcDbPolyFaceMesh*>&,  bool bQuadrilaterals = false, bool bOptimizeToSmoothShells = false, double dSmoothAngle = -1.0, bool bKeepApproxEdges = false) const;
// end BRX specific extensions

    // BOP
    Body operator*(const Body&);
    Body operator*(const Transf3d&);
    Body operator+(const Body&);
    Body operator-();
    Body operator-(const Body&);
    Body operator-(const Plane&);
    Body& operator*=(const Body&);
    Body& operator*=(const Transf3d&);
    Body& operator+=(const Body&);
    Body& operator-=(const Body&);
    Body& operator-=(const Plane&);
    Body& operator=(const Body&);
    BodyInterferenceType operator&&(const Body&) const;
    PointInBodyLocation operator&&(const Point3d&) const;

    static Body axisRevolution(const Point3d[],PolygonVertexData*[],int,const Vector3d&,const Line3d&,double,int);
    static Body axisRevolution(const Point3d[],PolygonVertexData*[],int,const Vector3d&,const Line3d&,double,int,const Point3d&,double,double = 0.0);
    static Body box(const Point3d&,const Vector3d&);
    static Body cone(const Line3d&,const Vector3d&,double,double,int);
    static Body cone(const Line3d&,double,double,int);
    static Body convexHull(const Point3d[],int);
    static Body cylinder(const Line3d&,const Vector3d&,double,int);
    static Body cylinder(const Line3d&,double,int);
    static Body endpointRevolution(const Point3d[],PolygonVertexData*[],int,const Vector3d&,double,int);
    static Body extrusion(const Point3d[],PolygonVertexData*[],int,const Vector3d&,const Vector3d&);
    static Body extrusion(const Point3d[],PolygonVertexData*[],int,const Vector3d&,const Vector3d&,const Point3d&,double,double = 0.0);
    static Body extrusionAlongPath(const Body&,const Body&,const Point3d[],PolygonVertexData*[],int,bool,bool = true,const Point3d& = Point3d::kNull,double = 1.0,double = 0.0,const MorphingMap& = MorphingMap::kNull,bool = false,std::vector<int> = std::vector<int>(),std::vector<int> = std::vector<int>());
    static Body pipe(const Line3d&,const Vector3d&,double,double,int);
    static Body pipe(const Line3d&,double,double,int);
    static Body pipeConic(const Line3d&,const Vector3d&,double,double,double,double,int);
    static Body pipeConic(const Line3d&,double,double,double,double,int);
    static Body pyramid(const Point3d[],PolygonVertexData*[],int,const Vector3d&,const Point3d&);
    static Body rectangleToCircleReducer(const Point3d&,const Vector2d&,const Circle3d&,int);
    static Body reducingElbow(const Point3d&,const Point3d&,const Point3d&,double,double,int,int);
    static Body restore(const wchar_t*);
    static Body restore(FILE*);
    static Body restore(SaveRestoreCallback*);
    static Body skin(Body*[],int,bool,bool,MorphingMap** = NULL,bool = false,bool = true);
    static Body sphere(const Point3d&,double,int);
    static Body tetrahedron(const Point3d&,const Point3d&,const Point3d&,const Point3d&);
    static Body torus(const Line3d&,double,double,int,int);
    static Body torus_extension(const Line3d&,double,double,int,int);

};

// Managing the BModeler BooleanOperation mode given by enumeration type
enum eBooleanOperationEngineType {
  cAECModeler,   // 'old' single threaded modeler, provided by the ODA's AEC object enabler code
  cAECModelerMT, // 'new' multi-threaded modeler, provided by the ODA's AEC object enabler code
  // can be extended in the future?
};

//----- BRX-specific

// enables or disables "Point Normalisation" using specified tolerance, to improve numeric stability;
// if 'tolerance' is 0 or negative, BRX BModeler automatically determines a suitable tolerance for
// "Point Normalisation";
// if Normalisation is enabled, it applies to all the BOP and Creator functions
BM_IMPORTEXPORT void setNormaliseGeomPoints(bool enable = false, double tolerance = -1.0);
BM_IMPORTEXPORT bool getNormaliseGeomPoints(double& tolerance);

// set or return the BOP engine type
BM_IMPORTEXPORT void                        setBooleanOperationEngineType(eBooleanOperationEngineType eType);
BM_IMPORTEXPORT eBooleanOperationEngineType getBooleanOperationEngineType();

//----- BRX-specific end

} // namespace AModeler end
