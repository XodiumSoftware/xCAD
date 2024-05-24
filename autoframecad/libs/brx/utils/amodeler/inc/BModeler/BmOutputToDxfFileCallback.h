// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmOutputPolylineCallback.h"
#include "BmOutputTriangleCallback.h"

namespace AModeler
{

class ImplOutputToDxfFileCallback;

class BM_IMPORTEXPORT OutputToDxfFileCallback: public OutputPolylineCallback, public OutputTriangleCallback
{
private:
    std::shared_ptr<ImplOutputToDxfFileCallback> m_pBrxImp;

public:
    OutputToDxfFileCallback(const wchar_t*);
    ~OutputToDxfFileCallback();

    virtual void outputArc(Edge*,const Point3d&,double,double,double,bool);
    virtual void outputPolyline(Edge*[],const Point3d[],const double[],int,bool,bool);
    virtual void outputTriangle(Edge*[],int);
    virtual void outputTriStrip(Edge*[],int,bool);
};

}
