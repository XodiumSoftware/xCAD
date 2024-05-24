// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifndef _AcMeshListener_h_Included
#define _AcMeshListener_h_Included

#include "brx_importexport.h"
#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbObjectId.h"
#include "AcGi/AcGiMapper.h"
#include "AcGe/AcGeMatrix3d.h"

#include <memory>  // std::shared_ptr
#include <vector>


typedef void* AcMeshHandle;
typedef void* AcTransformHandle;
typedef std::vector<AcTransformHandle> AcTransformHandleVector;


// Mesh Instance Identifier
struct BRX_IMPORTEXPORT AcMeshInstanceId
{
public:
    AcMeshHandle             m_meshHandle;
    AcTransformHandleVector  m_transformHandles;

    // This is the index into m_transformHandles;
    // if this is equal to 'm_transformHandles.size()', then the mesh itself is the root.
    // Sometimes, the mesh making up our logical shape is split into a transform shape +
    // another mesh. For example, this can be done when the mesh contains vertices with
    // huge coordinates. This is then replaced // by a transform shape with huge coordinates
    // + a mesh at smaller coordinates.
    // Sometimes, it can be important to know that the transform is also part of the logical
    // geometry. For example, UV mapping parameters will be based on logical coordinates of the mesh.
    unsigned int  m_logicalShapeRoot;
};


typedef Adesk::UInt32  ACCOLORREF;

struct BRX_IMPORTEXPORT AcMeshMaterial
{
public:
    AcDbObjectId  m_materialId;      // AcDbMaterial: most of the needed material parameters are here
    ACCOLORREF    m_objectColor;     // Some colors in AcDbMaterial can be 'ByObject'. This color will be needed then.
    double        m_objectOpacity;   // Same as above, but for opacity
    bool          m_doubleSided;     // Whether faces are double sided
    AcGiMapper    m_mapper;          // Mesh might not have the required UV data. In that case, m_mapper and m_blockTransform
    AcGeMatrix3d  m_blockTransform;  // will be needed in order to generate them (similar to addUVdataFromMapper function).
};
//std::shared_ptr<AcGiMapper*> ?
//std::shared_ptr<AcGeMatrix3d*> ?

struct BRX_IMPORTEXPORT AcMeshInstance
{
public:
    AcMeshInstanceId  m_instanceId;
    AcDbObjectId      m_objectId; // object id of the root object; i.e., if this concerns an insert, this
                                  // is the object id of the topmost insert.
};

typedef std::vector<AcMeshInstance>  AcMeshInstanceVector;

struct BRX_IMPORTEXPORT AcMeshData
{
    unsigned int m_numTriangles = 0;
    unsigned int m_numVertices  = 0;

    const int*    m_pIndices  = nullptr;  // count = 3 * m_numTriangles
    const float*  m_pVertices = nullptr;  // count = 3 * m_numVertices
    const float*  m_pNormals  = nullptr;  // count = 3 * m_numVertices
    const float*  m_pUV       = nullptr;  // count = 2 * m_numVertices
};


class AcMeshSource;

class BRX_IMPORTEXPORT AcMeshListener
{
public:
    virtual ~AcMeshListener() {};

    virtual void onSourceBeingDestroyed(AcMeshSource& src) {};
    virtual void onBeginUpdate(const AcMeshSource& src) {};
    virtual void onEndUpdate(const AcMeshSource& src) {};
    virtual void onInstanceAdded(const AcMeshSource& src, const AcMeshInstance& instance) {};
    virtual void onInstanceRemoved(const AcMeshSource& src, const AcMeshInstanceId& instanceId) {};
};


class BRX_IMPORTEXPORT AcMeshSource
{
public:
    virtual ~AcMeshSource() {};

    virtual bool addListener(AcMeshListener* pListener) = 0;
    virtual bool removeListener(AcMeshListener* pListener) = 0;

    virtual bool getExistingInstances(AcMeshInstanceVector& instances) = 0;
    virtual bool getMeshData(AcMeshHandle meshHandle, AcMeshData& meshData) = 0;
    virtual bool getTransformMatrix(AcTransformHandle transformHandle, AcGeMatrix3d& matrix) = 0;
    virtual bool getMaterial(AcMeshInstanceId id, AcMeshMaterial& material) = 0;
};

// create a new AcMeshSource* instance; caller is responsible to delete this, when finished;
// supports to register exactly 1 AcMeshListener instance (at one time), repeated calls will return 'false'
BRX_IMPORTEXPORT AcMeshSource* getAcMeshSource(const AcGsView* pGsView);


#endif // _AcMeshListener_h_Included
