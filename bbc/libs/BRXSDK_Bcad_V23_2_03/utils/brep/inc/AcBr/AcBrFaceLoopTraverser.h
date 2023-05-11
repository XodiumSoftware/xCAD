// Copyright (C) 2010-2011 Menhirs NV. All rights reserved.
#pragma once

#include "AcBr/AcBrTraverser.h"

class AcBrFace;
class AcBrLoop;
class AcBrShellFaceTraverser;

class AcBrFaceLoopTraverser: public AcBrTraverser
{
public:
    ACRX_DECLARE_MEMBERS(AcBrFaceLoopTraverser);

    AcBrFaceLoopTraverser();
    AcBrFaceLoopTraverser(const AcBrFaceLoopTraverser&);
    ~AcBrFaceLoopTraverser();

    AcBr::ErrorStatus getFace(AcBrFace&) const;
    AcBr::ErrorStatus getLoop(AcBrLoop&) const;
    AcBr::ErrorStatus setFace(AcBrFace&);
    AcBr::ErrorStatus setFace(const AcBrFace&);
    AcBr::ErrorStatus setFace(const AcBrShellFaceTraverser&);
    AcBr::ErrorStatus setFaceAndLoop(const AcBrLoop&);
    AcBr::ErrorStatus setLoop(AcBrLoop&);
    AcBr::ErrorStatus setLoop(const AcBrLoop&);

    AcBrFaceLoopTraverser& operator=(const AcBrFaceLoopTraverser&);
};