// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcRx/AcRxObject.h"

/** _ */
class BRX_IMPORTEXPORT AcDbLayerStateManagerReactor : public AcRxObject
{
public:
    ACRX_DECLARE_MEMBERS(AcDbLayerStateManagerReactor);

    virtual void layerStateCreated(const ACHAR*, const AcDbObjectId&);
    virtual void layerStateCompareFailed(const ACHAR*, const AcDbObjectId&);
    virtual void layerStateToBeRestored(const ACHAR*, const AcDbObjectId&);
    virtual void layerStateRestored(const ACHAR*, const AcDbObjectId&);
    virtual void abortLayerStateRestore(const ACHAR*, const AcDbObjectId&);
    virtual void layerStateToBeDeleted(const ACHAR*, const AcDbObjectId&);
    virtual void layerStateDeleted(const ACHAR*);
    virtual void abortLayerStateDelete(const ACHAR*, const AcDbObjectId&);
    virtual void layerStateToBeRenamed(const ACHAR*, const ACHAR*);
    virtual void layerStateRenamed(const ACHAR*, const ACHAR*);
    virtual void abortLayerStateRename(const ACHAR*, const ACHAR*);
};
