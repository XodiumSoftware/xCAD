// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "brx_importexport.h"  // BRX_IMPORTEXPORT
#include "AcEd/AcEdGlobalMfc.h"

#include "AcCm/AcCmComplexColor.h"
#include "AcDb/AcDb2LineAngularDimension.h"
#include "AcDb/AcDb3PointAngularDimension.h"
#include "AcDb/AcDbAlignedDimension.h"
#include "AcDb/AcDbArcDimension.h"
#include "AcDb/AcDbDatabase.h"
#include "AcDb/AcDbDatabaseReactor.h"
#include "AcDb/AcDbDiametricDimension.h"
#include "AcDb/AcDbEntityReactor.h"
#include "AcDb/AcDbExtents.h"
#include "AcDb/AcDbExtents2d.h"
#include "AcDb/AcDbObjectIterator.h"
#include "AcDb/AcDbOrdinateDimension.h"
#include "AcDb/AcDbRadialDimension.h"
#include "AcDb/AcDbRadialDimensionLarge.h"
#include "AcDb/AcDbRotatedDimension.h"
#include "AcEd/AcEdJig.h"
#include "Misc/AcDmUtil.h"
#include <string.h>


//////////////////////////////////////////////////////////////////////////////////////////

#define IDR_ASDKPROMPTBASE 700
BOOL acedSetIUnknownForCurrentCommand(const LPUNKNOWN);

struct PROMPT_MAP_ENTRY {
    LPCWSTR m_szDesc;
    DISPID m_dispId;
    int m_promptType;
    int m_cronly;
    int m_nInitget;
    UINT m_nKeywords;
    UINT m_nDefaultValue;
    UINT m_nPrompt;
    bool m_bJigThisProperty;
    bool m_bGotThisProperty;
    VARTYPE m_paramType;
    VARIANT m_vValue;
};

template <typename T, const GUID *TWrapperCLSID>
class ATL_NO_VTABLE AsdkPromptBase 
    : public CComObjectRootEx<CComSingleThreadModel>
    , public CComCoClass<AsdkPromptBase<T,TWrapperCLSID>, NULL>
    , public IPropertyNotifySink
    , public AcEdJig
{
protected:
    DECLARE_REGISTRY_RESOURCEID(IDR_ASDKPROMPTBASE) 
    BEGIN_COM_MAP(AsdkPromptBase)
        COM_INTERFACE_ENTRY(IPropertyNotifySink)
    END_COM_MAP() 
    DECLARE_PROTECT_FINAL_CONSTRUCT()

    AsdkPromptBase()
        : AcEdJig()
        , m_pDbrObject(NULL)
        , m_dConnectionID(-1)
        , m_pDb(NULL)
        , m_pDoc(NULL)
        , m_cursor3dPos()
        , m_pos3d()
        , m_cursorPos()
        , m_pos()
        , m_cursorDist(0)
        , m_dist(0)
        , m_cursorAngle(0)
        , m_angle(0)
        , m_szCursorString(NULL)
        , m_szString(NULL)
        , m_jigCursorType(AcEdJig::kNoSpecialCursor)
        , m_jigUserInputControls((AcEdJig::UserInputControls)0)
        , m_cRef(0)
    {
        m_CLSID_ObjectWrapper = *TWrapperCLSID;
    }
    virtual ~AsdkPromptBase()
    {
    }

    virtual HINSTANCE GetResourceInstance() = 0;
    virtual PROMPT_MAP_ENTRY* GetPromptMap() = 0;
    virtual VARTYPE propertyTypeCallback(int idx, VARTYPE t) 
    { 
        return t; 
    }
    virtual void setProperty(int idx, VARIANT& variantOut, short valIn)
    {
        if(VT_I4 == variantOut.vt) {
            variantOut.lVal = valIn;
        } else if(VT_I2 == variantOut.vt) {
            variantOut.iVal = valIn;
        }
    }
    virtual void setProperty(int idx, VARIANT& variantOut, long valIn)
    {
        if(VT_I4 == variantOut.vt) {
            variantOut.lVal = valIn;
        } else if(VT_I2 == variantOut.vt) {
            variantOut.iVal = (SHORT)valIn;
        }
    }
    virtual void setProperty(int idx, VARIANT& variantOut, double valIn)
    {
        if(VT_R8 == variantOut.vt) {
            variantOut.dblVal = valIn;
        } else if(VT_R4 == variantOut.vt) {
            variantOut.fltVal = (float)valIn;
        }
    }
    virtual void setProperty(int idx, VARIANT& variantOut, float valIn)
    {
        if(VT_R8 == variantOut.vt) {
            variantOut.dblVal = valIn;
        } else if(VT_R4 == variantOut.vt) {
            variantOut.fltVal = valIn;
        }
    }
    virtual void setProperty(int idx, VARIANT& variantOut, TCHAR* valIn)
    {
        variantOut.bstrVal = ::SysAllocString(valIn);
    }
    virtual void setProperty(int idx, VARIANT& variantOut, AcGePoint3d &valIn)
    {
        AcAxPoint3d axPoint(valIn);
        axPoint.setVariant(variantOut);
    }
    virtual void setProperty(int idx, VARIANT& variantOut, AcGePoint2d &valIn)
    {
        AcAxPoint2d axPoint(valIn);
        axPoint.setVariant(variantOut);
    }
    HRESULT FinalConstruct()
    {
        return(S_OK); 
    }
    void FinalRelease()
    {
    }
    void SetDocument(AcApDocument* pDoc)
    {
        m_pDoc = pDoc;
    }
    int GetPromptMapSize()
    {
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
        int ix = 0;
        for(ix; !promptMapEnd(ix); ix++) ;
        return ix;
    }
    HRESULT GetPropertyTypeInfo() 
    {
        HRESULT hr = E_FAIL;
        ITypeInfo* pTypeInfo = NULL;
        hr = m_pWrapperObject->GetTypeInfo(0, LOCALE_SYSTEM_DEFAULT, &pTypeInfo);
        TYPEATTR* pTypeAttr = NULL;
        if(SUCCEEDED(hr)) {
            hr = pTypeInfo->GetTypeAttr(&pTypeAttr);
        }
        if(SUCCEEDED(hr)) {
            int functionCnt = pTypeAttr->cFuncs;
            pTypeInfo->ReleaseTypeAttr(pTypeAttr), pTypeAttr = NULL;

            PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
            for(int ix = 0; ix < functionCnt; ix++) {
                FUNCDESC* pFuncDesc = NULL;
                hr = pTypeInfo->GetFuncDesc(ix, &pFuncDesc);
                if(!SUCCEEDED(hr)) {
                    break;
                }
                UINT arrSize = 0;
                UINT nrNames = 0;
                BSTR *pBstrNames = NULL;
                for(int iy = 0; iy < this->GetPromptMapSize(); iy++) {
                    if(pFuncDesc->memid == pMap[iy].m_dispId) {
                        arrSize = pFuncDesc->cParams + 1;
                        nrNames = 0;
                        pBstrNames = new BSTR[arrSize];
                        hr = pTypeInfo->GetNames(pFuncDesc->memid, pBstrNames, arrSize, &nrNames);
                        if(!SUCCEEDED(hr)) {
                            break;
                        }
                        delete[] pBstrNames, pBstrNames = NULL;
                        if(nrNames >= 1 && INVOKE_PROPERTYPUT == pFuncDesc->invkind) {
                            pMap[iy].m_paramType = this->propertyTypeCallback(iy, pFuncDesc->lprgelemdescParam[nrNames - 1].tdesc.vt);
                        }
                    }
                }
                pTypeInfo->ReleaseFuncDesc(pFuncDesc), pFuncDesc = NULL;
            }
        }
        if(NULL != pTypeInfo) {
            pTypeInfo->Release(), pTypeInfo = NULL;
        }
        return hr;
    }
    void setPropertyDefault(int ix)
    {
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
        pMap[ix].m_vValue.vt = pMap[ix].m_paramType;
        TCHAR defaultStr[256] = _T("");
        if(!this->defaultValueCallback(ix, defaultStr)) {
            this->LoadString(pMap[ix].m_nDefaultValue, defaultStr, 255);
        }
        TCHAR delimiter[] = L" ,";
        AcGePoint3d pt3d;
        TCHAR* pCoordVal = NULL;
        switch(pMap[ix].m_paramType) {
        case VT_I4:
            this->setProperty(ix, pMap[ix].m_vValue, _ttol(defaultStr));
            break;
        case VT_I2:
            this->setProperty(ix, pMap[ix].m_vValue, (short)_ttoi(defaultStr));
            break;
        case VT_R8:
            this->setProperty(ix, pMap[ix].m_vValue, _tstof(defaultStr));
            break;
        case VT_R4:
            this->setProperty(ix, pMap[ix].m_vValue, (float)_tstof(defaultStr));
            break;
        case VT_BSTR:
            this->setProperty(ix, pMap[ix].m_vValue, defaultStr);
            break;
        case VT_ARRAY | VT_R8:
            pCoordVal = wcstok(defaultStr, delimiter);
            for(long idx = 0; NULL != pCoordVal; idx++) {
                if(idx < 3) {
                    pt3d[idx] = _tstof(pCoordVal);
                }
                pCoordVal = wcstok(NULL, delimiter);
            }
            this->setProperty(ix, pMap[ix].m_vValue, pt3d);
            break;
        default:
            break;
        }
        if(0 != pMap[ix].m_dispId) {
            this->PutProperty(ix);
        }
        pMap[ix].m_bGotThisProperty = false;
    }
    HRESULT PutProperty(int idx) 
    {
        static bool callSetDefaults = true;
        HRESULT hr = E_FAIL;

        CComPtr<IDispatch> pDisp;
        m_pWrapperObject.QueryInterface(&pDisp);
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();

        EXCEPINFO exceptInfo;
        memset(&exceptInfo, 0, sizeof(EXCEPINFO));
        UINT nArgErr = (UINT)-1;

        DISPPARAMS dispParam;
        memset(&dispParam, 0, sizeof(DISPPARAMS));
        dispParam.cArgs = 1;
        dispParam.cNamedArgs = 1;
        dispParam.rgvarg = &pMap[idx].m_vValue;
        DISPID dispidNamed = DISPID_PROPERTYPUT;
        dispParam.rgdispidNamedArgs = &dispidNamed;
        hr = pDisp->Invoke(pMap[idx].m_dispId, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_PROPERTYPUT, 
            &dispParam, NULL, &exceptInfo, &nArgErr);
        if(!SUCCEEDED(hr) && callSetDefaults) {
            callSetDefaults = false;
            this->setPropertyDefault(idx);
            callSetDefaults = true;
        }
        return hr;
    }
    HRESULT __stdcall OnRequestEdit(DISPID dispID)
    { 
        return S_OK;
    }
    HRESULT __stdcall OnChanged(DISPID dispID)
    {
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
        int ix = 0;
        for(int ix = 0; !promptMapEnd(ix); ix++) {
            if(dispID == pMap[ix].m_dispId) {
                pMap[ix].m_bGotThisProperty = true;
                break;
            }
        }
        if(NULL != m_pDoc) {
            ;
            acDocManager->sendModelessInterrupt(m_pDoc);
        }
        return S_OK;
    }
    int LoadString(UINT id, LPWSTR str, int bufSize = 255) 
    {
        str[0] = L'\0';
        if(0 != id && -1 != id) {
            return ::LoadString(this->GetResourceInstance(), id, str, bufSize);
        }
        return 0;
    }
    LPCWSTR BuildPromptString(int idx) 
    {
        static TCHAR promptStr[256] = _T("");
        TCHAR promptText[256] = _T("");
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
        this->LoadString(pMap[idx].m_nPrompt, promptText, 255);

        TCHAR defStr[256] = _T("");
        if(!this->defaultValueCallback(idx, defStr)) {
            this->LoadString(pMap[idx].m_nDefaultValue, defStr, 255);
        }
        bool hasDef = L'\0' != defStr[0];
        swprintf(promptStr, 255, hasDef ? _T("%s <%s>: ") : _T("%s: %s"), promptText, defStr);
        return promptStr;
    }
    bool entryHasKeywords(int ix)
    {
        return 0 != GetPromptMap()[ix].m_nKeywords;
    }
    bool promptMapEnd(int ix)
    {
        return NULL == GetPromptMap()[ix].m_szDesc;
    }
    int promptInput(int ix)
    {
        int rt = RTINPUTTRUNCATED;
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
        TCHAR keywords[133] = _T("");;
        if(entryHasKeywords(ix)) {
            this->LoadString(pMap[ix].m_nKeywords, keywords, 132);
            acedInitGet(pMap[ix].m_nInitget, keywords);
        }
        LPCWSTR promptStr = this->BuildPromptString(ix);

        int i = 0;
        double d = 0;
        ads_point point = {0, 0, 0};
        TCHAR str[132] = _T("");
        ads_name ename;
        int type = pMap[ix].m_promptType;
        switch(type) {
        case RTSHORT:
        case RTLONG:
            rt = acedGetInt(promptStr, &i);
            if(RTKWORD == rt) {
                acedGetInput(keywords);
                rt = this->keywordCallback(ix, keywords, &i) ? RTNORM : rt;
            }
            if(RTNORM == rt) {
                this->setProperty(ix, pMap[ix].m_vValue, RTSHORT == type ? (short)i : (long)i);
                this->PutProperty(ix);
            }
            break;
        case RTREAL:
        case RTANG: 
            rt = RTREAL == type ? acedGetReal(promptStr, &d) : acedGetAngle(NULL, promptStr, &d);
            if(RTKWORD == rt) {
                acedGetInput(keywords);
                rt = this->keywordCallback(ix, keywords, &d) ? RTNORM : rt;
            }
            if(RTNORM == rt) {
                this->setProperty(ix, pMap[ix].m_vValue, d);
                this->PutProperty(ix);
            }
            break;
        case RTPOINT:
        case RT3DPOINT:
            rt = acedGetPoint(NULL, promptStr, point);
            if(RTKWORD == rt) {
                acedGetInput(keywords);
                rt = this->keywordCallback(ix, keywords, point) ? RTNORM : rt;
            }
            if(RTNORM == rt) {
                if(RTPOINT == type) {
                    this->setProperty(ix, pMap[ix].m_vValue, AcGePoint2d(point[X], point[Y]));
                } else {
                    this->setProperty(ix, pMap[ix].m_vValue, AcGePoint3d(point[X], point[Y], point[Z]));
                }
                this->PutProperty(ix);
            }
            break;
        case RTSTR:
            rt = acedGetString(pMap[ix].m_cronly, promptStr, str);
            if(RTKWORD == rt) {
                acedGetInput(keywords);
                rt = this->keywordCallback(ix, keywords, str) ? RTNORM : rt;
            }
            if(RTNORM == rt) {
                if(L'\0' != str[0]) { // skip empty strings
                    this->setProperty(ix, pMap[ix].m_vValue, str);
                }
                this->PutProperty(ix);
            } 
            break;
        case RTENAME:
            rt = acedEntSel(promptStr, ename, point);
            if(RTKWORD == rt) {
                acedGetInput(keywords);
                rt = this->keywordCallback(ix, keywords, ename) ? RTNORM : rt;
            }
            if(RTNORM == rt) {
                this->setProperty(ix, pMap[ix].m_vValue, (long)(ename[0]));
                this->PutProperty(ix);
            }
            break;
        } // switch
        return rt == RTNONE ? RTNORM : rt;
    }
    AcEdJig::DragStatus dragInput(int ix) 
    {
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
        setDispPrompt(this->BuildPromptString(ix));
        AcEdJig::DragStatus dragStat = drag();
        if(AcEdJig::kNormal == dragStat) {
            int type = pMap[ix].m_promptType;
            switch(type) {
            case RTREAL:
                this->setProperty(ix, pMap[ix].m_vValue, m_cursorDist);
                this->PutProperty(ix);
                break;
            case RTANG:
                this->setProperty(ix, pMap[ix].m_vValue, m_cursorAngle);
                this->PutProperty(ix);
                break;
            case RTPOINT:
                this->setProperty(ix, pMap[ix].m_vValue, m_cursorPos);
                this->PutProperty(ix);
                break;
            case RT3DPOINT:
                this->setProperty(ix, pMap[ix].m_vValue, m_cursor3dPos);
                this->PutProperty(ix);
                break;
            case RTSTR:
                this->setProperty(ix, pMap[ix].m_vValue, m_szCursorString);
                this->PutProperty(ix);
                break;
            }
        }
        return dragStat;
    }
    virtual void setPropertyDefaults(int idx = -1)
    {
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
        if(-1 == idx) {
            for(int ix = 0; !promptMapEnd(ix); ix++) {
                this->setPropertyDefault(ix);
            }
        } else {
            this->setPropertyDefault(idx);
        }
    }
    virtual void initSampler() = 0;
    virtual AcEdJig::DragStatus sampler() 
    {
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
        AcEdJig::DragStatus dragStat = AcEdJig::kCancel;
        setUserInputControls(m_jigUserInputControls);
        setSpecialCursorType(m_jigCursorType);
        int ix = 0;
        AcGePoint3d pt3d;
        while(!promptMapEnd(ix)) {
            if(pMap[ix].m_bJigThisProperty && !pMap[ix].m_bGotThisProperty) {
                bool changed = false;
                if(entryHasKeywords(ix)) {
                    TCHAR keywords[256] = _T("");
                    this->LoadString(pMap[ix].m_nKeywords, keywords, 255);
                    setKeywordList(keywords);
                }
                dragStat = this->samplerCallback(ix, changed);
                if(AcEdJig::kKW1 <= dragStat) {
                    this->keywordCallback(ix, (TCHAR*)&dragStat, NULL);
                }
                if(AcEdJig::kOther == dragStat) {
                    int type = pMap[ix].m_promptType;
                    switch(type) {
                    case RTANG:
                        dragStat = acquireAngle(m_cursorAngle);
                        if(AcEdJig::kKW1 <= dragStat) {
                            this->keywordCallback(ix, (TCHAR* )&dragStat, &m_cursorAngle);
                        }
                        changed = (m_cursorAngle != m_angle);
                        break;
                    case RTREAL:
                        dragStat = acquireDist(m_cursorDist);
                        if(AcEdJig::kKW1 <= dragStat) {
                            this->keywordCallback(ix, (TCHAR* )&dragStat, &m_cursorDist);
                        }
                        changed = (m_cursorDist != m_dist);
                        break;
                    case RTSTR:
                        dragStat = acquireString(m_szCursorString);
                        if(AcEdJig::kKW1 <= dragStat) {
                            this->keywordCallback(ix, (TCHAR* )&dragStat, &m_szCursorString);
                        }
                        changed = (m_szCursorString != m_szString);
                        break;
                    case RTPOINT:
                        dragStat = acquirePoint(pt3d);
                        m_cursorPos.x = pt3d.x;
                        m_cursorPos.y = pt3d.y;
                        if(AcEdJig::kKW1 <= dragStat) {
                            this->keywordCallback(ix, (TCHAR* )&dragStat, &m_pos);
                        }
                        changed = !m_cursorPos.isEqualTo(m_pos);
                        break;
                    case RT3DPOINT:
                        dragStat = acquirePoint(m_cursor3dPos);
                        if(AcEdJig::kKW1 <= dragStat) {
                            this->keywordCallback(ix, (TCHAR* )&dragStat, &m_cursor3dPos);
                        }
                        changed = !m_cursor3dPos.isEqualTo(m_pos3d);
                        break;
                    default:
                        break;
                    } // switch type
                    if(AcEdJig::kNull == dragStat) {
                        pMap[ix].m_bGotThisProperty = true;
                    }
                } // if AcEdJig::kOther
                if(changed) {
                    m_angle = m_cursorAngle;
                    m_dist = m_cursorDist;
                    m_szString = m_szCursorString;
                    m_pos = m_cursorPos;
                    m_pos3d = m_cursor3dPos;
                } else {
                    if(AcEdJig::kNull != dragStat) {
                        dragStat = AcEdJig::kNoChange;
                    }
                }
                break;
            } // If not got this property
            ix++;
        } // while
        return dragStat;
    }
    virtual AcDbEntity* entity() const
    {
        if(NULL == m_pDbrObject) {
            m_pBaseObj->GetObject((AcDbObject* &)m_pDbrObject);
        }
        return((AcDbEntity*)m_pDbrObject);
    }
    virtual Adesk::Boolean update() 
    {
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
        for(int ix = 0; !promptMapEnd(ix); ix++) {
            if(pMap[ix].m_bJigThisProperty && !pMap[ix].m_bGotThisProperty) {
                if(!this->updateCallback(ix)) {
                    int type = pMap[ix].m_promptType;
                    switch(type) {
                    case RTANG:
                        this->setProperty(ix, pMap[ix].m_vValue, m_cursorAngle);
                        break;
                    case RTREAL:
                        this->setProperty(ix, pMap[ix].m_vValue, m_cursorDist);
                        break;
                    case RTSTR:
                        this->setProperty(ix, pMap[ix].m_vValue, m_szCursorString);
                        break;
                    case RTPOINT:
                        this->setProperty(ix, pMap[ix].m_vValue, m_cursorPos);
                        break;
                    case RT3DPOINT:
                        this->setProperty(ix, pMap[ix].m_vValue, m_cursor3dPos);
                        break;
                    default:
                        break;
                    }
                    this->PutProperty(ix);
                    pMap[ix].m_bGotThisProperty = false;
                    break;
                }
            }// If not got this property
        }
        return Adesk::kTrue;
    }
    virtual void constructorCallback()
    {
    }
    // Return: 
    // - RTINPUTTRUNCATED, for AsdkPromptBase class to do it
    // - RTNORM for got and set the value
    // - RTNONE for got and set the value
    // - RTCAN for aborting the input loop
    // - any other value for retrying to get this value
    virtual int promptCallback(int idx)
    { 
        return RTINPUTTRUNCATED; 
    }
    virtual AcEdJig::DragStatus samplerCallback(int idx, bool &changed)
    {
        return kOther;
    }
    virtual bool updateCallback(int idx)
    { 
        return false;
    }
    virtual bool keywordCallback(int idx, TCHAR* kword, void *value)
    {
        return false;
    }
    virtual bool defaultValueCallback(int idx, LPWSTR defStr)
    { 
        return false;
    }
public:
    virtual AcDbObjectId promptLoop()
    {
        PROMPT_MAP_ENTRY* pMap = this->GetPromptMap();
        int rt = RTNORM;
        this->setPropertyDefaults(-1);
        AcEdJig::DragStatus dragStat = AcEdJig::kCancel;
        bool loopAgain = true;
        while(loopAgain) {
            loopAgain = false;;
            int ix = 0;
            bool done = false;
            while(!done && !promptMapEnd(ix)) { 
                if(!pMap[ix].m_bGotThisProperty) {
                    rt = this->promptCallback(ix);
                    if(RTINPUTTRUNCATED == rt) { // we (AsdkPromptBase) should do it
                        if(pMap[ix].m_bJigThisProperty) { // Do a jigged property
                            dragStat = dragInput(ix); // Will change pMap[ix].m_bGotThisProperty
                            rt = AcEdJig::kCancel == dragStat ? RTCAN : 
                                 AcEdJig::kNull   == dragStat ? RTNONE : 
                                 AcEdJig::kNormal == dragStat ? RTNORM : RTERROR;
                            if((RTNORM == rt || RTNONE == rt) && !pMap[ix].m_bGotThisProperty) {
                                rt = RTERROR;
                            }
                        } else { // Do a property with command line input
                            rt = this->promptInput(ix); 
                        }
                    } // RTINPUTTRUNCATED
                    if(RTCAN == rt) {
                        done = true;
                        loopAgain = false;
                    } else {
                        if(RTNORM == rt || RTNONE == rt) {
                            pMap[ix].m_bGotThisProperty = true;
                        } else {
                            loopAgain = true;
                        }
                    }
                }
                ix++;
            } // while !promptMapEnd(ix)
        } // while loopAgain

        if(AcEdJig::kCancel != dragStat) {
            if(NULL != m_pBaseObj) {
                m_pBaseObj->GetObject(m_pDbrObject);
            }
            return(append()); // AcEdJig::append()
        } else {
            return AcDbObjectId::kNull;
        }
    }

protected:
    CComPtr<T> m_pWrapperObject;
    CLSID m_CLSID_ObjectWrapper;
    AcDbObject* m_pDbrObject;
    DWORD m_dConnectionID;
    CComQIPtr<IAcadBaseObject2> m_pBaseObj;
    CComPtr<IConnectionPoint> m_pConPt;
    AcDbDatabase* m_pDb;
    AcApDocument* m_pDoc;
    AcGePoint3d m_cursor3dPos;
    AcGePoint3d m_pos3d;
    AcGePoint2d m_cursorPos;
    AcGePoint2d m_pos;
    double m_cursorDist;
    double m_dist;
    double m_cursorAngle;
    double m_angle;
    TCHAR* m_szCursorString;
    TCHAR* m_szString;
    AcEdJig::CursorType m_jigCursorType;
    AcEdJig::UserInputControls m_jigUserInputControls;
    volatile LONG m_cRef;
};

#define BEGIN_PROMPT_MAP(PROMPTCLASS) \
    public: \
    PROMPTCLASS() \
    { \
        SetDocument(curDoc()); \
        m_pDb = acdbHostApplicationServices()->workingDatabase(); \
        HRESULT hr = m_pWrapperObject.CoCreateInstance(m_CLSID_ObjectWrapper); \
        if(FAILED(hr)) { \
            acutPrintf(L"Wrapper class could not be created.\n"); \
            throw hr; \
        } \
        m_pBaseObj = m_pWrapperObject; \
        hr = m_pBaseObj->CreateObject(); \
        if(FAILED(hr)) { \
            acutPrintf(L"Wrapper class object could not be created.\n"); \
            throw hr; \
        } \
        CComQIPtr<IConnectionPointContainer> connectionPoints = m_pWrapperObject; \
        hr = connectionPoints->FindConnectionPoint(IID_IPropertyNotifySink, &m_pConPt); \
        if(FAILED(hr)) { \
            acutPrintf(L"Connection Points could not be found.\n"); \
            throw hr; \
        } \
        hr = GetPropertyTypeInfo(); \
        if(FAILED(hr)) { \
            acutPrintf(L"Type information for wrapper class can not be found.\n"); \
            throw hr; \
        } \
        CComPtr<IUnknown> pComPtrIUnknown; \
        hr = this->QueryInterface(IID_IUnknown,(void **)&pComPtrIUnknown); \
        if(FAILED(hr)) { \
            acutPrintf(L"This class has no IUnknown interface.\n"); \
            throw hr; \
        } \
        hr = m_pConPt->Advise(pComPtrIUnknown, &m_dConnectionID); \
        if(FAILED(hr)) { \
            acutPrintf(L"Advise of the connection point failed.\n"); \
            throw hr; \
        } \
        acedSetIUnknownForCurrentCommand(m_pWrapperObject); \
        AcDbObject* pObj = NULL; \
        m_pBaseObj->GetObject(pObj); \
        AcDbEntity* pEntity = AcDbEntity::cast(pObj); \
        if(NULL != pEntity) { \
            pEntity->setDatabaseDefaults(); \
        } \
        m_pDbrObject = pObj; \
        m_pBaseObj->SetObject(pObj); \
        constructorCallback(); \
        initSampler(); \
    } \
    ~PROMPTCLASS() \
    { \
        m_pConPt->Unadvise(m_dConnectionID); \
        if(NULL != m_pBaseObj) { \
            m_pBaseObj->GetObject(m_pDbrObject); \
        } \
    } \
    ULONG STDMETHODCALLTYPE AddRef() \
    { \
        return InterlockedIncrement(&m_cRef); \
    } \
    ULONG STDMETHODCALLTYPE Release() \
    { \
        return InterlockedDecrement(&m_cRef); \
    } \
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID refiid, void **ppvObject) \
    { \
        if(IID_IPropertyNotifySink == refiid || IID_IUnknown == refiid) { \
            *ppvObject = this; \
            static_cast<IUnknown *>(this)->AddRef(); \
            return S_OK; \
        } else { \
            return E_NOINTERFACE; \
        } \
    } \
    virtual PROMPT_MAP_ENTRY* GetPromptMap() \
    { \
        static PROMPT_MAP_ENTRY pMap[] = {

#define PROMPT_ENTRY(desc, dispID, type, defValId, promptId, isJiggedProp) \
    {desc, dispID, type,  1, 0,              0,         defValId, promptId, isJiggedProp },

#define PROMPT_ENTRY_SYMBOL(desc, dispID, defValId, promptId, isJiggedProp) \
    {desc, dispID, RTSTR, 0, 0,              0,         defValId, promptId, isJiggedProp },

#define PROMPT_ENTRY_INITGET(desc, dispID, type, initgetOptions, keywordId, defValId, promptId, isJiggedProp) \
    {desc, dispID, type,  1, initgetOptions, keywordId, defValId, promptId, isJiggedProp },

#define END_PROMPT_MAP \
            {NULL, 0, 0, 0, 0, 0, 0, false, false, VT_EMPTY } \
        }; \
        return(pMap); \
    }

#define DEFINE_SAMPLER(JIGCURSORTYPE, JIGUSERINPUTCONTROLS) \
    virtual void initSampler() { \
        m_jigCursorType = JIGCURSORTYPE; \
        m_jigUserInputControls = JIGUSERINPUTCONTROLS; \
    }
