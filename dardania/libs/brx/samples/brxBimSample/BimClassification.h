// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// BIM API : object classification sample

// few utilities
Acad::ErrorStatus postToDatabase(AcDbObjectId& idObj, AcDbDatabase* pDb, AcDbEntity* pEnt, bool doClose = true);
AcDbObjectId createBoxSolid(double length, double depth, double height, const AcGeVector3d& translation,
                            Adesk::UInt16 aciColorIndex = 256);


void cmdMyBimClassify();
