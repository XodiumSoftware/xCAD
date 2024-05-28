// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// API for Section Operation Reactor

#ifndef _AcSectionReactor_h_Included
#define _AcSectionReactor_h_Included

#include "brx_importexport.h"
#include "Misc/AcArray.h"
#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbEntity.h"

class AcDbBlockTableRecord;
class AcGeMatrix3d;
class AcDbSection;

//----- global utility functions to control entity 'Display Clip' & 'Use Lids' -----

BRX_EXPORT bool acdbIsClipDisplayOn(const AcDbObjectId& idEnt);
BRX_EXPORT bool acdbSetClipDisplayOn(const AcDbObjectId& idEnt, bool setOn);

BRX_EXPORT bool acdbIsClipDisplayInPsVportOn(const AcDbObjectId& idEnt, const AcDbObjectId& vpId);
BRX_EXPORT bool acdbSetClipDisplayInPsVport(const AcDbObjectId& idEnt, const AcDbObjectId& vpId, bool setOn);

BRX_EXPORT bool acdbUseClipDisplayLids(const AcDbObjectId& idEnt);
BRX_EXPORT bool acdbSetUseClipDisplayLids(const AcDbObjectId& idEnt, bool setOn);


//-------------BIM  Sectioning Reactor -----------------
// The AcSectioningReactor can be used to monitor the sectioning operations,
// as triggered by the BIM section commands like BIMSECTION BIMSECTIONUPDATE;
// modifying the sectioning result entities is possible and allowed.
// This reactor is not used with the generic sectioning operations.


class BRX_EXPORT AcSectioningReactor : public AcRxObject
{
public:
    ACDB_DECLARE_MEMBERS(AcSectioningReactor);

    AcSectioningReactor();
    virtual ~AcSectioningReactor();

    // called at the begin of section operation
    // pSectionEntity : the AcDbSection entity used for the sectioning operation
    virtual void onBeginSectioning(const AcDbSection* pSectionEntity)
    {
    };

    // called at the end of section operation
    virtual void onEndSectioning(const AcDbSection* pSectionEntity)
    {
    };

    // called when a compound object is about to be processed
    // pCompoundObject : compound object to be processed
    // entityPath      : full subentity path to the processed object
    // return 'false' to skip this AcGiDrawable* for the actual section operation, 'true' to continue sectioning
    virtual bool onBeginCompoundObject(const AcGiDrawable* pCompoundObject,
                                       const AcDbObjectIdArray& entityPath)
    {
        return true;
    };

    // called when a sectionable entity is about to be sectioned
    // pEntity         : the entity to be sectioned
    // entityPath      : full subentity path to the processed entity
    // modelToWorldMtx : "Model to World" transformation matrix, nullptr if matrix is kIdentity
    // return 'false' to skip this AcDbEntity* for the actual section operation, 'true' to continue sectioning
    virtual bool onBeginEntity(const AcDbEntity* pEntity,
                               const AcDbObjectIdArray& entityPath,
                               const AcGeMatrix3d* modelToWorldMtx)
    {
        return true;
    };

    // called when sectionable entity is sectioned and section result is processed
    // pEntity : the entity which was processed
    // any array modification will be ignored; but entities' modifications are allowed and respected
    // arrays : contain the section result geometry
    // the arrays are the same as in AcDbSection::generateSectionGeometry()
    // 
    // Note : this function is only called, if sectioning the entity was successful
    // (see 'onEndEntity' below)
    virtual void onEntityResult(const AcDbEntity* pEntity,
                                AcDbEntityPtrArray& aIntersectBoundary,
                                AcDbEntityPtrArray& aIntersectFill,
                                AcDbEntityPtrArray& aBackgroundGeometry,
                                AcDbEntityPtrArray& aForegroundGeometry,
                                AcDbEntityPtrArray& aCurveTangents)
    {
    };

    // called at the end of the section operation for a specific entity;
    // this function is always called, even if sectioning the entity failed
    virtual void onEndEntity(const AcDbEntity* pEntity)
    {
    };

    // called at the end of compound object processing
    // pCompoundObject : compound object which was processed
    virtual void onEndCompoundObject(const AcGiDrawable* pCompoundObject)
    {
    };

    // called when all entities (affected by a particular section entity) were processed,
    // and the resulting BlockTableRecord has been constructed; client code can apply final
    // modifications to the BlockTableRecord;
    // resultBtr       : BlockTableRecord with generated entities
    // modelToBlockMtx : ModelToBlock transformation matrix, nullptr if matrix is kIdentity
    virtual void onEndSectioning(AcDbBlockTableRecord* resultBtr, const AcGeMatrix3d* modelToBlockMtx)
    {
    };

    // this function is called, when processing 'AcGiDrawable* pCompoundObject' was skipped by any reactor
    // in 'onBeginCompoundObject(const AcGiDrawable* pCompoundObject, ...)';
    // arguments are the same as on begin notification;
    virtual void wasSkipped(const AcGiDrawable* pCompoundObject, const AcDbObjectIdArray& entityPath)
    {
    };

    // this function is called, when processing 'AcDbEntity* pEntity' was skipped by any reactor
    // in 'onBeginCompoundObject(const AcGiDrawable* pCompoundObject, ...)';
    // arguments are the same as on begin notification;
    virtual void wasSkipped(const AcDbEntity* pEntity, const AcDbObjectIdArray& entityPath,
                            const AcGeMatrix3d* modelToWorldMtx)
    {
    };
};


//------------- attaching and detaching the sectioning reactor -----------------

// if MultiThreading is active (see MTFLAGS setting), the Sectioning core system uses
// MultiThreading with the following logic :
// - each AcDbSection object (each section plane) is used in a separate thread then, and all
//   entities which are affected from the particular section entity are processed sequentially
// - if multiple section entities are present resp. used, the section operation then happens
//   with multiple threads
// 
// => therefore, the several reactor events can run parallel, and "overlap", or reenter;
// => it is strongly advised to make sure that the reactor callback function implementation
//    is thread-safe (see recommendations below)
// => also, do not rely on specific sequence of reactor events - for a single thread, the
//    entity processing and the related reactor events are deterministic and sequential
//    (as originating from the entity set, sectioned by a particular section entity);
//    but with multiple AcDbSection entities being used, multiple threads can be started,
//    and the reactor events then originate from multiple sectioning threads, hence the
//    sequence and order of events can vary (i.e. multiple 'onBeginEntity' events before
//    first 'onEntityResult' will arrive;
// 
// Note 1 : for background update (BIMBKUPDATE) MultiThreading *can* be used by the core system,
//          even if MTFLAGS=0 is defined !
// 
// Note 2 : do NOT rely on a specific database of the sectioning entities !
//          the sectioning operation uses temporary databases, i.e. entities to be sectioned
//          can be cloned into a temporary database before sectioning and similar;
//          'pEntity->database()' can be used to retrieve the database, if necessary;
//          also, application-side logic and preparation can be prepared in initial call
//          to 'onBeginSectioning()';
// 
// If not sure whether your client-side reactor is MultiThreading-safe, then set MTFLAGS=0
// when your application module is loaded : acedSetVar(_T("MTFLAGS"), 0);
// but also reset to original value when your module is unloaded.


bool acdbAddSectionReactor(AcSectioningReactor* reactor);
bool acdbRemoveSectionReactor(AcSectioningReactor* reactor);

// some general recommendations for MultiThreading mode :
// 
// - if possible, only use stack-based (local) variables
// - for read-only access (reading values of variables), thread-locking is not necessary
// - for write-access (changing values) a thread-lock is necessary
// 
//     #include <mutex>
//     #include <string>
//     std::mutex mtx;
//
//     std::string test(const std::string& value)
//     {
//         std::lock_guard<std::mutex> lock(mtx);
//         if (value == "")
//             return m_var;
//     
//         m_var = value;
//         return m_var;
//     }
// 
// - use a local variable copy when storing function call results, and use a thread-lock
//   for the "value copy" operation :
//   example :
//     int val = callFuncTest();
// 
//     std::lock_guard<std::mutex> lock(mtx);
//     m_memberVal = val;
// 
// Always use the 'std::lock_guard<std::mutex> lock(mtx);' (or similar RAII implementations),
// as this ensure that the lock applies to the complete scope, and that the lock is always removed.
// 
// There are extensive and good documentations about threads, local + global data access using
// multiple threads, and recommended programming logic and coding style.


#endif // _AcSectionReactor_h_Included
