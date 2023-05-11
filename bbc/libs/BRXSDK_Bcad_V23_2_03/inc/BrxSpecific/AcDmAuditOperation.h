// AcDmAuditOperation.h
//
// declares the high-level 3D DirectModeling Audit API (validating + fixing ACIS entities)
//
// Copyright (c) 2020 Bricsys NV
// All rights reserved.
//
//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#pragma once

#ifndef _AcDmAudit_h_Included
#define _AcDmAudit_h_Included

#include "brx_importexport.h"
#include "Misc/MiscGlobal.h"
#include "AcDb/AcDbObjectId.h"
#include "AcDb/AcDbEntity.h"
#include "AcDb/AcDbSubentId.h"

#include <vector>


// specifies the validation level for the checking / fixing operation
enum EDmValidationLevel
{
    // low level covers only critical flaws.
    eLevelLow       = 1,
    
    // medium level covers typical flaws, default level.
    eLevelMedium    = 2,

    // high level covers all the flaws and produces heavy
    // checking / fixing of entities (i.e. checking entity self-intersections)
    eLevelHigh      = 3,
};

// specifies the type of the flaw
enum EDmAuditSeverity
{
    eSeverityNone    = -1,
    eSeverityError   =  0,
    eSeverityWarning =  1,
    eSeverityNote    =  2,
    eSeverityInfo    =  3,
};

//---------------- Audit Options
// specifies options for the validation + fixing operation

class BRX_IMPORTEXPORT BrxDmAuditOptions
{
    friend class BrxDmAuditOperation;

    class BrxDmAuditOptionsImpl* m_pImpl = nullptr;
    BrxDmAuditOptions(const BrxDmAuditOptionsImpl*);

public:
    BrxDmAuditOptions();
    BrxDmAuditOptions(const BrxDmAuditOptions& other);
    BrxDmAuditOptions& operator=(const BrxDmAuditOptions& other);
    virtual ~BrxDmAuditOptions();

    // returns whether this options object is valid
    virtual bool isValid() const;

    // get + set the 'severity level' for the checking/fixing operation;
    // higher values make more time expensive checks, i.e. level 'eLevelHigh' checks self-intersections.
    virtual EDmValidationLevel level() const;
    virtual void setLevel(EDmValidationLevel level = eLevelMedium);

    // get + set the 'fix errors' option;
    // if enabled, then errors will be fixed
    virtual bool fixFlaws() const;
    virtual void setFixFlaws(bool fixErrors = false);

    // get + set the 'coincident faces' checking option;
    // if enabled, coincident faces will be checked/fixed;
    // only topologically adjacent coincident faces are treated;
    // a typical case is in corner reliefs of sheet metal models with bends
    // using zero radius value.
    virtual bool treatCoincidentFaces() const;
    virtual void setTreatCoincidentFaces(bool bTreatCoincidentFaces = false);

    // get + set the 'sliver faces' checking option;
    // if enabled, then sliver faces will be checked/fixed
    virtual bool treatSliverFaces() const;
    virtual void setTreatSliverFaces(bool bTreatSliverFaces = true);

    // get + set the 'dynamic range' checking option;
    // this option enables checking whether all the geometry is inside -1.E+5 - 1.E+5 bounding box
    virtual bool treatDynamicRangeErrors() const;
    virtual void setTreatDynamicRangeErrors(bool bTreatDynamicRangeErrors = true);

    // get + set the Multi-Threaded mode flag;
    // enables auditing/fixing in multi-threaded mode;
    // NOTE : multi-threading is only useful, if multiple entities are validated
    // (not used for a single entity)
    virtual bool multiThreadedMode() const;
    virtual void setMultiThreadedMode(bool bMultiThreadedMode = false);
};

//---------------- Audit Flaw
// contains information about found / fixed flaws detected by audit operation

class BRX_IMPORTEXPORT BrxDmAuditFlaw
{
    friend class BrxDmAuditReport;
    friend class BrxDmAuditOperation;

    class BrxDmAuditFlawImpl* m_pImpl = nullptr;
    BrxDmAuditFlaw(const BrxDmAuditFlawImpl*);

public:
    BrxDmAuditFlaw();
    BrxDmAuditFlaw(const BrxDmAuditFlaw& other);
    BrxDmAuditFlaw& operator=(const BrxDmAuditFlaw& other);
    virtual ~BrxDmAuditFlaw();

    // returns the flaw severity
    virtual EDmAuditSeverity severity() const;

    // returns the flaw's user message
    virtual const ACHAR* message() const;

    // returns the flaw's description
    virtual const ACHAR* description() const;

    // returns the sub-entity associated with this flaw
    virtual bool subentId(AcDbSubentIdArray& idArray) const;
};

typedef std::vector<BrxDmAuditFlaw>  BrxDmAuditFlawArray;

//---------------- Audit Report
// contains informations on the result of the validation + fixing operation

class BRX_IMPORTEXPORT BrxDmAuditReport
{
    friend class BrxDmAuditOperation;

    class BrxDmAuditReportImpl* m_pImpl = nullptr;
    BrxDmAuditReport(const BrxDmAuditReportImpl*);

public:
    BrxDmAuditReport();
    BrxDmAuditReport(const BrxDmAuditReport& other);
    BrxDmAuditReport& operator=(const BrxDmAuditReport& other);
    virtual ~BrxDmAuditReport();

    // returns the audit/validation level used to generate this report
    virtual EDmValidationLevel level() const;

    // returns whether this report was generated with 'fix errors' option active
    virtual bool isFixMode() const;

    // returns the number of skipped entities
    virtual int numberOfSkippedEntities() const;

    // returns the number of entities processed in 'audit only' mode
    virtual int numberOfCheckedEntities() const;

    // returns the number of entities processed in 'fix errors' mode (0 in checking mode)
    virtual int numberOfFixedEntities() const;

    // returns the number of flaws
    virtual int numberOfFlaws() const;

    // returns whether the entity was ignored in validation/fixing (i.e. no ACIS data, hidden etc.)
    virtual bool isSkipped(const AcDbEntity* pEntity) const;
    virtual bool isSkipped(const AcDbObjectId& entId) const;

    // returns whether the entity was only validated (not fixed)
    virtual bool isCheckedOnly(const AcDbEntity* pEntity) const;
    virtual bool isCheckedOnly(const AcDbObjectId& entId) const;

    // returns the number of flaws for the entity, before fixing;
    // -1 if report was generated in check mode or report doesn't contain information about given entity
    virtual int numberOfFlawsBeforeFix(const AcDbEntity* pEntity) const;
    virtual int numberOfFlawsBeforeFix(const AcDbObjectId& entId) const;

    // returns the flaws detected for the entity
    // -1 if report was produced in check mode or if report doesn't contain information about given entity
    virtual bool getFlaws(const AcDbEntity* pEntity, BrxDmAuditFlawArray& flaws) const;
    virtual bool getFlaws(const AcDbObjectId& entId, BrxDmAuditFlawArray& flaws) const;
};

//---------------- Audit Operation
// the main access to the validation + fixing operation

class BRX_IMPORTEXPORT BrxDmAuditOperation
{
    class BrxDmAuditImpl* m_pImpl = nullptr;

public:
    BrxDmAuditOperation();
    BrxDmAuditOperation(const BrxDmAuditOperation& other);
    BrxDmAuditOperation& operator=(const BrxDmAuditOperation& other);
    virtual ~BrxDmAuditOperation();

    // returns the options object, used by this BrxDmAuditOperation object
    virtual bool auditOptions(BrxDmAuditOptions& auditOptions);

    // add a single entity to the collection to be audited
    virtual Acad::ErrorStatus add(const AcDbObjectId& entId);

    // add a set of entities to the collection to be audited
    virtual Acad::ErrorStatus add(const AcDbObjectIdArray& entIdArray);

    // add an opened entity to the collection to be audited (NDBR supported);
    // NOTE : 'pEntity' *MUST NOT* be database-resident ! only NDBR 'pEntity' can be added here;
    // for database-resident entities, use the AcDbObjectId based 'add()' functions
    virtual Acad::ErrorStatus add(const AcDbEntity* pEntity);

    // add a set of opened entities to the collection to be audited (NDBR supported);
    // NOTE : all entities *MUST NOT* be database-resident ! only NDBR entities can be added here;
    // for database-resident entities, use the AcDbObjectId based 'add()' functions
    virtual Acad::ErrorStatus add(const AcDbEntityPtrArray& entityArray);

    // process the validation for the entity set
    // NOTE : 'run()' will automatically clear the entity collection
    virtual Acad::ErrorStatus run();

    // returns the results from previous validation process
    virtual bool report(BrxDmAuditReport& auditReport) const;
};

#endif // _AcDmAudit_h_Included
