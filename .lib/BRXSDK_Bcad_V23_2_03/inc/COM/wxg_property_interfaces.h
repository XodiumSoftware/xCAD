// wxg_property_interfaces.h : 

// Copyright (C) Menhirs NV. All rights reserved.

//HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

#ifndef OPM_INTERFACES_DEFINED
#define OPM_INTERFACES_DEFINED

const int DISPID_DYNAMIC = -23; 

interface IDynamicProperty;

// IPropertyManager interface declaration
// {747617F5-74A5-4771-8CFD-A9C2BC0F46D6}
DEFINE_GUID(IID_IPropertyManager, 0x747617f5, 0x74a5, 0x4771, 0x8c, 0xfd, 0xa9, 0xc2, 0xbc, 0xf, 0x46, 0xd6);

interface DECLSPEC_UUID("747617F5-74A5-4771-8CFD-A9C2BC0F46D6")
IPropertyManager : public IUnknown
{
    BEGIN_INTERFACE     

    STDMETHOD(QueryInterface)(REFIID riid, void** ppObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0;    
    STDMETHOD_(ULONG, Release)() = 0;

    STDMETHOD(GetDynamicProperty)(LONG index, IDynamicProperty** ppDynProp) = 0;
    STDMETHOD(GetDynamicPropertyByName)(BSTR propertyName, IDynamicProperty** ppDynProp) = 0;
    STDMETHOD(GetDynamicPropertyCount)(LONG* pCount) = 0;   
    STDMETHOD(GetDynamicClassInfo)(IUnknown* pObject, ITypeInfo** ppTI, DWORD* pCookie) = 0;

    STDMETHOD(AddProperty)(IDynamicProperty* pDynProp) = 0;
    STDMETHOD(RemoveProperty)(IDynamicProperty* pDynProp) = 0;  
};
typedef IPropertyManager FAR* LPPROPERTYMANAGER;


// IPropertyManager2 interface declaration
// {EFE1169D-60BB-4061-ACD3-73EA2559947D}
DEFINE_GUID(IID_IPropertyManager2, 0xefe1169d, 0x60bb, 0x4061, 0xac, 0xd3, 0x73, 0xea, 0x25, 0x59, 0x94, 0x7d);

interface DECLSPEC_UUID("EFE1169D-60BB-4061-ACD3-73EA2559947D")
IPropertyManager2 : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(REFIID riid, void** ppvObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0;
    STDMETHOD_(ULONG, Release)() = 0;

    STDMETHOD(GetDynamicProperty)(LONG index, IUnknown ** pDynPropObj) = 0;
    STDMETHOD(GetDynamicPropertyByName)(BSTR propName, IUnknown ** pDynPropObj) = 0;
    STDMETHOD(GetDynamicPropertyCountEx)(LONG* count) = 0;
    STDMETHOD(GetDynamicClassInfo)(IUnknown* pObj, ITypeInfo** pptiDynamic, DWORD* dwCookie) = 0;

    STDMETHOD(AddProperty)(IUnknown * pDynPropObj) = 0;
    STDMETHOD(RemoveProperty)(IUnknown * pDynPropObj) = 0;
};

typedef IPropertyManager2 FAR* LPPROPERTYMANAGER2;


// IDynamicEnumProperty interface declaration
// {658B1B8C-0749-46c8-9AA6-F716DFCC95EC}
DEFINE_GUID(IID_IDynamicEnumProperty, 0x658b1b8c, 0x749, 0x46c8, 0x9a, 0xa6, 0xf7, 0x16, 0xdf, 0xcc, 0x95, 0xec);

interface DECLSPEC_UUID("658B1B8C-0749-46c8-9AA6-F716DFCC95EC")
IDynamicEnumProperty : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(REFIID riid, void** ppObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0;
    STDMETHOD_(ULONG, Release)() = 0;

    STDMETHOD(GetNumPropertyValues)(LONG* pNumberValues) = 0;
    STDMETHOD(GetPropValueData)(LONG index, VARIANT* pData) = 0;
    STDMETHOD(GetPropValueName)(LONG index, BSTR* pName) = 0;   
};
typedef IDynamicEnumProperty FAR* LPDYNAMICENUMPROPERTY;


// IAcPiPropertyDisplay/IPerPropertyDisplay interface declaration
// {E158DE71-D47F-4c7b-A8FA-BCDA1E4A9C00}
#define IPerPropertyDisplay IAcPiPropertyDisplay

DEFINE_GUID(IID_IAcPiPropertyDisplay, 0xe158de71, 0xd47f, 0x4c7b, 0xa8, 0xfa, 0xbc, 0xda, 0x1e, 0x4a, 0x9c, 0x0);
#define IID_IPerPropertyDisplay IID_IAcPiPropertyDisplay

interface DECLSPEC_UUID("E158DE71-D47F-4c7b-A8FA-BCDA1E4A9C00")
IAcPiPropertyDisplay : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(GetCustomPropertyCtrl)(VARIANT Id, LCID lcid, BSTR *pProgId) = 0;
    STDMETHOD(GetPropertyIcon)(VARIANT Id, IUnknown **pIcon) = 0;
    STDMETHOD(GetPropTextColor)(VARIANT Id, OLE_COLOR *pTextColor) = 0;
    STDMETHOD(IsFullView)(VARIANT Id, VARIANT_BOOL *pbVisible, DWORD *pIntegralHeight) = 0;
    STDMETHOD(GetPropertyWeight)(VARIANT Id, long *pPropertyWeight) = 0;
};

typedef IAcPiPropertyDisplay FAR* LPPERPROPERTYDISPLAY;


// IDynamicPropertyNotify interface declaration
// {D5B76BA8-5C12-4984-B38F-BF7038F38455}
DEFINE_GUID(IID_IDynamicPropertyNotify, 0xd5b76ba8, 0x5c12, 0x4984, 0xb3, 0x8f, 0xbf, 0x70, 0x38, 0xf3, 0x84, 0x55);

interface DECLSPEC_UUID("D5B76BA8-5C12-4984-B38F-BF7038F38455") 
IDynamicPropertyNotify : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(REFIID riid, void** ppObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0; 
    STDMETHOD_(ULONG, Release)() = 0; 

    // Returns a SAFEARRAY of LONGs representing the objectIDs.
    // The caller is responsible for call VariantClear to cleanup.
    STDMETHOD(GetCurrentSelectionSet)(VARIANT* pSelSet) = 0;
    STDMETHOD(OnChanged)(IDynamicProperty* pDynProp) = 0;   
};
typedef IDynamicPropertyNotify FAR* LPDYNAMICPROPERTYNOTIFY;


// IDynamicPropertyNotify2 interface declaration
// {98B5E94B-F05B-453f-AD12-7574CAF36CFF}
DEFINE_GUID(IID_IDynamicPropertyNotify2, 0x98b5e94b, 0xf05b, 0x453f, 0xad, 0x12, 0x75, 0x74, 0xca, 0xf3, 0x6c, 0xff);

interface DECLSPEC_UUID("98B5E94B-F05B-453f-AD12-7574CAF36CFF") 
IDynamicPropertyNotify2 : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0;
    STDMETHOD_(ULONG, Release)() = 0;

    STDMETHOD(OnChanged)(IUnknown* pDynamicProperty) = 0;
    STDMETHOD(GetCurrentSelectionSet)(VARIANT* pSelection) = 0;
};

typedef IDynamicPropertyNotify2 FAR* LPDYNAMICPROPERTYNOTIFY2;


// IDynamicProperty interface declaration
// {9EBE6DBB-6227-46b2-BD08-A7FD05B25C4A}
DEFINE_GUID(IID_IDynamicProperty, 0x9ebe6dbb, 0x6227, 0x46b2, 0xbd, 0x8, 0xa7, 0xfd, 0x5, 0xb2, 0x5c, 0x4a);

interface DECLSPEC_UUID("9EBE6DBB-6227-46b2-BD08-A7FD05B25C4A")
IDynamicProperty : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(REFIID riid, void** ppObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0;
    STDMETHOD_(ULONG, Release)() = 0;

    STDMETHOD(Connect)(IDynamicPropertyNotify* pNotifySink) = 0;
    STDMETHOD(Disconnect)() = 0;

    STDMETHOD(GetDisplayName)(BSTR* pBstrName) = 0;
    STDMETHOD(IsPropertyEnabled)(LONG_PTR objId, BOOL* pIsEnabled) = 0;
    STDMETHOD(IsPropertyReadOnly)(BOOL* pIsReadonly) = 0;
    STDMETHOD(GetDescription)(BSTR* pBstrDescription) = 0;
    STDMETHOD(GetGUID)(GUID* pPropGUID) = 0;

    //possible strings: "ACAD_COLOR", "ACAD_LAYER", "ACAD_DISTANCE", "ACAD_ANGLE", "ACAD_NOUNITS", "ACAD_AREA", "ACAD_LWEIGHT"   
    STDMETHOD(GetCurrentValueName)(BSTR* pBstrValueName) = 0;
    //possible types: VT_I2, VT_I4, VT_R4, VT_R8, VT_BSTR, VT_BOOL and VT_USERDEFINED
    STDMETHOD(GetCurrentValueType)(VARTYPE* pVarType) = 0; 
    STDMETHOD(GetCurrentValueData)(LONG_PTR objId, VARIANT* pData) = 0; 
    STDMETHOD(SetCurrentValueData)(LONG_PTR objId, const VARIANT data) = 0;     

};
typedef IDynamicProperty FAR* LPDYNAMICPROPERTY;


// IDynamicProperty2 interface declaration
// {6A567A08-930E-4344-941F-61D2CE8044FB}
DEFINE_GUID(IID_IDynamicProperty2, 0x6a567a08, 0x930e, 0x4344, 0x94, 0x1f, 0x61, 0xd2, 0xce, 0x80, 0x44, 0xfb);

interface DECLSPEC_UUID("6A567A08-930E-4344-941F-61D2CE8044FB")
IDynamicProperty2 : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(REFIID riid, void** ppvObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0;
    STDMETHOD_(ULONG, Release)() = 0;

    STDMETHOD(GetGUID)(GUID* propGUID) = 0;
    STDMETHOD(GetDisplayName)(BSTR* bstrName) = 0;
    STDMETHOD(IsPropertyEnabled)(IUnknown *pUnk, BOOL* pbEnabled) = 0;
    STDMETHOD(IsPropertyReadOnly)(BOOL* pbReadonly) = 0;
    STDMETHOD(GetDescription)(BSTR* bstrName) = 0;
   
    STDMETHOD(GetCurrentValueName)(BSTR* pbstrName) = 0;
    STDMETHOD(GetCurrentValueType)(VARTYPE* pVarType) = 0;
    STDMETHOD(GetCurrentValueData)(IUnknown *pUnk, VARIANT* pvarData) = 0;
    STDMETHOD(SetCurrentValueData)(IUnknown *pUnk, const VARIANT varData) = 0;

    STDMETHOD(Connect)(IDynamicPropertyNotify2* pSink) = 0;
    STDMETHOD(Disconnect)() = 0;
};
typedef IDynamicProperty2 FAR* LPDYNAMICPROPERTY2;


// IPropertySource interface declaration
// {974ADEBB-841C-4dbb-8AD3-A59095E2A154}
DEFINE_GUID(IID_IPropertySource, 0x974adebb, 0x841c, 0x4dbb, 0x8a, 0xd3, 0xa5, 0x90, 0x95, 0xe2, 0xa1, 0x54);

interface DECLSPEC_UUID("974ADEBB-841C-4dbb-8AD3-A59095E2A154")
IPropertySource : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(REFIID riid, void** ppObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0;
    STDMETHOD_(ULONG, Release)() = 0;

    STDMETHOD(get_Name)(BSTR* pName) = 0;
    STDMETHOD(GetProperties)(IUnknown* pObject, VARIANT *pPropertyArray) = 0;
};
typedef IPropertySource FAR* LPPROPERTYSOURCE;


// IDynamicDialogProperty interface
// {8CCC560C-0734-4535-985E-C74C97783E51}
DEFINE_GUID(IID_IDynamicDialogProperty, 0x8ccc560c, 0x0734, 0x4535, 0x98, 0x5e, 0xc7, 0x4c, 0x97, 0x78, 0x3e, 0x51);

typedef BOOL (*OPMDIALOGPROC)(void);

interface DECLSPEC_UUID("8CCC560C-0734-4535-985E-C74C97783E51")
IDynamicDialogProperty : public IUnknown
{
    BEGIN_INTERFACE

    STDMETHOD(QueryInterface)(REFIID riid, void** ppvObj) = 0;
    STDMETHOD_(ULONG, AddRef)() = 0;
    STDMETHOD_(ULONG, Release)() = 0;

    STDMETHOD(GetCustomDialogProc)(OPMDIALOGPROC* pDialogProc) = 0;
    STDMETHOD(GetMacroName)(BSTR* bstrName) = 0;
};
typedef IDynamicDialogProperty FAR* LPDYNAMICDIALOGPROPERTY;

#endif //OPM_INTERFACES_DEFINED
