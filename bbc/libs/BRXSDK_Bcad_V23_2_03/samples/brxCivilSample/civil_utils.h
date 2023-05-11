// Copyright (C) Menhirs NV. All rights reserved.

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

class AcDbCivilTinSurface;


Acad::ErrorStatus addEntityToModelSpace(AcDbEntity* pEnt,
                                        AcDbObjectId& entityId,
                                        bool closeEnt);

void addEntitiesToModelSpace(AcDbEntityPtrArray& pEntities);

AcDbObjectId selectEntityPrompt(const AcString& prompt,
                                AcRxClass* pClassDesc,
                                bool acceptDerived);


inline bool doubleEqual(double x, double y, double tol = AcGeContext::gTol.equalPoint())
{
    return abs(x - y) < tol;
}

inline bool isZero(double x, double tol = AcGeContext::gTol.equalPoint())
{
    return doubleEqual(x, 0.0, tol);
}

inline double degToRad(const double& deg)
{
    return deg * M_PI / 180.0;
}

AcDbObjectId getActiveViewportTableRecordId();

AcGeMatrix3d worldToViewport(const AcDbViewportTableRecordPointer& pVTR);

//Copy of cmdCivilCreateSurface used in other commands that need a sample surface
AcDbCivilTinSurface* createSampleTinSurface();

Acad::ErrorStatus getModelSpaceId(AcDbDatabase * pDb, AcDbObjectId & blockId);

Acad::ErrorStatus getBlockTableRecordIterator(const AcDbBlockTableRecord * pBTR,
                                              std::unique_ptr<AcDbBlockTableRecordIterator> & pUniqueBTRIter);

Acad::ErrorStatus getGsMarker(AcDbObjectId& objId, int& marker);
