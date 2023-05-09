// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

#include "AcDb/AcDbObject.h"
#include "Misc/AcHyperlink.h"
#include "Misc/AcValue.h"

class AcDbField;
typedef AcArray<AcDbField*> AcDbFieldArray;

/** _ */
class BRX_EXPORT AcDbField: public AcDbObject
{
public:
    enum EvalContext
    {
        kOpen = 1,
        kSave = 2,
        kPlot = 4,
        kEtransmit = 8,
        kRegen = 16,
        kDemand = 32,
        kPreview = 64,
        kPlotPreview = 128
    };

    enum EvalOption
    {
        kDisable = 0,
        kOnOpen = 1,
        kOnSave = 2,
        kOnPlot = 4,
        kOnEtransmit = 8,
        kOnRegen = 16,
        kOnDemand = 32,
        kAutomatic = 63
    };

    enum EvalStatus
    {
        kNotYetEvaluated = 1,
        kSuccess = 2,
        kEvaluatorNotFound = 4,
        kSyntaxError = 8,
        kInvalidCode = 16,
        kInvalidContext = 32,
        kOtherError = 64
    };

    enum FieldCodeFlag
    {
        kFieldCode = 1,
        kEvaluatedText = 2,
        kEvaluatedChildren = 4,
        kObjectReference = 8,
        kAddMarkers = 16,
        kEscapeBackslash = 32,
        kStripOptions = 64,
        kPreserveFields = 128,
        kTextField = 256
    };

    enum FilingOption
    {
        kSkipFilingResult = 1
    };

    enum State
    {
        kInitialized = 1,
        kCompiled = 2,
        kModified = 4,
        kEvaluated = 8,
        kHasCache = 16
    };

    ACDB_DECLARE_MEMBERS(AcDbField);

    AcDbField();
    AcDbField(const ACHAR*,bool = false);
    ~AcDbField();

    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus subClose();

    Acad::ErrorStatus convertToTextField();
    Acad::ErrorStatus evaluate(int,AcDbDatabase*,int* = NULL,int* = NULL);
    Acad::ErrorStatus getChild(int,AcDbField*&,AcDb::OpenMode);
    Acad::ErrorStatus getData(const ACHAR*,AcValue*) const;
    Acad::ErrorStatus getFieldCode(ACHAR*&,FieldCodeFlag,AcArray<AcDbField*>* = NULL,AcDb::OpenMode = AcDb::kForRead) const;
    Acad::ErrorStatus getFormat(ACHAR*&) const;
    Acad::ErrorStatus getHyperlink(ACHAR**,ACHAR**,ACHAR**,ACHAR**,long*) const;
    Acad::ErrorStatus getHyperlink(AcHyperlink&) const;
    Acad::ErrorStatus getValue(AcFdFieldValue&) const;
    Acad::ErrorStatus getValue(ACHAR*&) const;
    Acad::ErrorStatus getValue(AcValue&) const;
    Acad::ErrorStatus postInDatabase(AcDbDatabase*);
    Acad::ErrorStatus removeHyperlink();
    Acad::ErrorStatus setData(const ACHAR*,const AcValue*);
    Acad::ErrorStatus setData(const ACHAR*,const AcValue*,bool);
    Acad::ErrorStatus setEvaluationOption(EvalOption);
    Acad::ErrorStatus setEvaluatorId(const ACHAR*);
    Acad::ErrorStatus setFieldCode(const ACHAR*,FieldCodeFlag = (FieldCodeFlag) 0,AcDbFieldArray* = NULL);
    Acad::ErrorStatus setFilingOption(FilingOption);
    Acad::ErrorStatus setFormat(const ACHAR*);
    Acad::ErrorStatus setHyperlink(const ACHAR*,const ACHAR*,const ACHAR* = NULL);
    Acad::ErrorStatus setHyperlink(const ACHAR*,const ACHAR*,const ACHAR*,long);
    Acad::ErrorStatus setHyperlink(const AcHyperlink&);
    Acad::ErrorStatus setInObject(AcDbObject*,const ACHAR*);
    AcValue::DataType dataType() const;
    bool hasHyperlink() const;
    bool isTextField() const;
    const ACHAR* evaluatorId() const;
    const ACHAR* getFieldCode(FieldCodeFlag,AcArray<AcDbField*>* = NULL,AcDb::OpenMode = AcDb::kForRead) const;
    const ACHAR* getFormat() const;
    const ACHAR* getValue() const;
    EvalOption evaluationOption() const;
    EvalStatus evaluationStatus(int* = NULL,ACHAR** = NULL) const;
    FilingOption filingOption() const;
    int childCount() const;
    State state() const;
};
