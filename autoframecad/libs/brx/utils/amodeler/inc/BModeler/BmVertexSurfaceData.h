// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "BmEntity.h"

namespace AModeler
{

class ImplVertexSurfaceData;

class BM_IMPORTEXPORT VertexSurfaceData: public Entity
{
private:
    std::shared_ptr<ImplVertexSurfaceData> m_pBrxImp;

public:
    VertexSurfaceData();
    VertexSurfaceData(const Edge*);

    const Vector3d& normal() const;
    Surface* surface() const;
    VertexSurfaceData* next() const;
    void print(FILE* = NULL) const;
    void restore(SaveRestoreCallback*);
    void save(SaveRestoreCallback*) const;
    void setNext(VertexSurfaceData*);
    void setSurface(Surface*);
    void transform (const Transf3d&);
};

}
