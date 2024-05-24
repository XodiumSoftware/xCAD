///////////////////////////////////////////////////////////////////////////////
//
//  Copyright 2024 Autodesk, Inc.  All rights reserved.
//
//  Use of this software is subject to the terms of the Autodesk license 
//  agreement provided at the time of installation or download, or which 
//  otherwise accompanies this software in either electronic or hard copy form. 
//
// DESCRIPTION:
//
// A sample callback class for outputting the results of Body::hideDisplay(), 
// Body::triangulate(), and Face::triangulate() methods to a DXF file.
//
// Usage:
//
//   OutputToDxfFileCallback callback(dxfFileName);
// 
//   body.hideDisplay(projTransf, &callback);
//            or
//   body.triangulate(&callback);
//            or
//   face.triangulate(&callback);
//
// The constrcutor opens the DXF file and writes the initial section. The
// destructor writes the end section and closes the DXF file.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef AMODELER_INC_DXFOUT_H
#define AMODELER_INC_DXFOUT_H


#include "callback.h"

AMODELER_NAMESPACE_BEGIN


class DllImpExp OutputToDxfFileCallback : public OutputPolylineCallback, 
                                          public OutputTriangleCallback
//
// Callback class for writing the line segments generated by Body::hideDisplay()
// and triangles/quads generated by Body::triangulate() to a DXF file. We have
// combined the two callback classes into one because the prologue and epilogue
// (constructor and destructor) are the same.
//
{
public:

    // The constructor opens the DXF file and writes the SECTION ENTITIES header
    //
    OutputToDxfFileCallback(const wchar_t* dxfFileName);

    // The destructor writes the ENDSEC and EOF groups and closes the file
    //
    ~OutputToDxfFileCallback();

    virtual void outputPolyline(Edge*             edgeArray [],
                                const Point3d     pointArray[], 
                                const double      bulgeArray[],
                                int               numPoints, 
                                bool              isClosed, 
                                bool              isVisible); 

    virtual void outputArc     (Edge*          edge,
                                const Point3d& center,
                                double         radius,
                                double         startAngle,
                                double         endAngle,
                                bool           isVisible);

    virtual void outputTriangle(Edge* edgeArray[], int arrayLength);

    virtual void outputTriStrip(Edge* edgeArray[], int arrayLength, 
                                bool firstTriangleIsCcw);

private:

    FILE* mpFile;

    // Write group code and group value
    //
    void g(int code, const char*    value) const;
    void g(int code, int            value) const;
    void g(int code, double         value) const;
    void g(int code, const Point2d& value) const;
    void g(int code, const Point3d& value) const;

}; // class OutputToDxfFileCallback



// Print the triangle to stdout
//
DllImpExp extern void printTriangle(Edge* edgeArray[], int numSides); 


AMODELER_NAMESPACE_END
#endif
