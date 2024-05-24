// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

class AcDbDimension;

//BRX START
//V12
class BrxDbDimDataImp;
//BRX END

/** _ */
class BRX_IMPORTEXPORT AcDbDimData
{
private:
    //BRX START
    //V12
    friend class BrxDbDimDataImp;
    BrxDbDimDataImp *m_pBrxImp;
    //BRX END

public:
    enum DimDataFlags
    {
        kDimEditable = 1,
        kDimInvisible = 2,
        kDimFocal = 4,
        kDimHideIfValueIsZero = 8,
        kDimEmptyData = 16,
        kDimResultantLength = 32,
        kDimDeltaLength = 64,
        kDimResultantAngle = 128,
        kDimDeltaAngle = 256,
        kDimRadius = 512,
        kDimCustomValue = 1024,
        kDimConstrained = 2048,
        kDimCustomString = 4096
    };

    AcDbDimData();
    AcDbDimData(AcDbDimension*,DimDataSetValueFuncPtr = NULL,unsigned int = 0,void* = NULL,DimDataSetCustomStringFuncPtr = NULL);
    AcDbDimData(const AcDbDimData&);
    ~AcDbDimData();

    Acad::ErrorStatus setAppData(void*);
    Acad::ErrorStatus setBitFlags(unsigned int);
    Acad::ErrorStatus setConstrain(bool);
    Acad::ErrorStatus setCustomDimValue(bool);
    Acad::ErrorStatus setCustomString(bool);
    Acad::ErrorStatus setCustomStringFunc(DimDataSetCustomStringFuncPtr);
    Acad::ErrorStatus setDimDeltaAngle(bool);
    Acad::ErrorStatus setDimDeltaLength(bool);
    Acad::ErrorStatus setDimEditable(bool);
    Acad::ErrorStatus setDimension(AcDbDimension*);
    Acad::ErrorStatus setDimFocal(bool);
    Acad::ErrorStatus setDimHideIfValueIsZero(bool);
    Acad::ErrorStatus setDimInvisible(bool);
    Acad::ErrorStatus setDimRadius(bool);
    Acad::ErrorStatus setDimResultantAngle(bool);
    Acad::ErrorStatus setDimResultantLength(bool);
    Acad::ErrorStatus setDimValueFunc(DimDataSetValueFuncPtr);
    Acad::ErrorStatus setOwnerId(const AcDbObjectId&);
    AcDbDimension* dimension() const;
    AcDbObjectId ownerId() const;
    bool isConstrained() const;
    bool isCustomDimValue() const;
    bool isCustomString() const;
    bool isDimDeltaAngle() const;
    bool isDimDeltaLength() const;
    bool isDimEditable() const;
    bool isDimFocal() const;
    bool isDimHideIfValueIsZero() const;
    bool isDimInvisible() const;
    bool isDimRadius() const;
    bool isDimResultantAngle() const;
    bool isDimResultantLength() const;
    DimDataSetCustomStringFuncPtr customStringFunc() const;
    DimDataSetValueFuncPtr dimValueFunc() const;
    unsigned int bitFlags() const;
    void* appData() const;

    AcDbDimData& operator=(const AcDbDimData&);
};
