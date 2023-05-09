// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbGlobal.h"
#include "AcPl/AcPlPlotLogger.h"
#include "DMM/AcDMMEPlotProperties.h"
#include "DMM/AcDMMNode.h"

/** _ */
class BRX_IMPORTEXPORT AcDMMEntityReactorInfo
{
protected:
    AcDMMEntityReactorInfo() {}
public:
    ~AcDMMEntityReactorInfo() {}

    virtual AcDbEntity* entity() const = 0;
    virtual AcDbObjectId effectiveBlockLayerId() const = 0;
    virtual AcPlPlotLogger* GetPlotLogger() = 0;
    virtual bool add3DDwfProperty(const ACHAR*,const ACHAR*,const ACHAR*) = 0;
    virtual bool AddNodeToMap(AcDbObjectId,AcDbObjectIdArray,int) = 0;
    virtual bool AddProperties(const AcDMMEPlotProperties*) = 0;
    virtual bool AddPropertiesIds(AcDMMStringVec*,AcDMMNode&) = 0;
    virtual bool GetCurrentEntityNode(AcDMMNode&,AcDbObjectIdArray) const = 0;
    virtual bool GetEntityNode(AcDbObjectId,AcDbObjectIdArray,int&) const = 0;
    virtual bool isCancelled() const = 0;
    virtual bool SetCurrentNode(int,AcDbObjectIdArray) = 0;
    virtual bool SetNodeName(int,const ACHAR*) = 0;
    virtual const AcArray<long>& getGraphicIDs() = 0;
    virtual const AcDbObjectIdArray& getEntityBlockRefPath() = 0;
    virtual const AcDMMNode* GetNode(int) const = 0;
    virtual const ACHAR* UniqueEntityId() = 0;
    virtual int GetNextAvailableNodeId() const = 0;
    virtual void cancelTheJob() = 0;
    virtual void flush() = 0;
};