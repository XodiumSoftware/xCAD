// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrBrep;
class AcBrFace;

class AcBrBrepFaceTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrBrepFaceTraverser);

    AcBrBrepFaceTraverser();
    AcBrBrepFaceTraverser(const AcBrBrepFaceTraverser&);
    ~AcBrBrepFaceTraverser();

    AcBr::ErrorStatus getBrep(AcBrBrep&) const;
    AcBr::ErrorStatus getFace(AcBrFace&) const;
    AcBr::ErrorStatus setBrep(AcBrBrep&);
    AcBr::ErrorStatus setBrep(const AcBrBrep&);
    AcBr::ErrorStatus setBrepAndFace(const AcBrFace&);
    AcBr::ErrorStatus setFace(AcBrFace&);
    AcBr::ErrorStatus setFace(const AcBrFace&);

    AcBrBrepFaceTraverser& operator=(const AcBrBrepFaceTraverser&);
};