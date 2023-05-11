// Copyright (C) Menhirs NV. All rights reserved.
// BIM API : object classification sample

#pragma once

// few utilities
Acad::ErrorStatus postToDatabase(AcDbObjectId& idObj, AcDbDatabase* pDb, AcDbEntity* pEnt, bool doClose = true);
AcDbObjectId createBoxSolid(double length, double depth, double height, const AcGeVector3d& translation,
                            Adesk::UInt16 aciColorIndex = 256);


void cmdMyBimClassify();
