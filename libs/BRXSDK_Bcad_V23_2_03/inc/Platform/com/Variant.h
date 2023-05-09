// Copyright (C) 2010-2014 Menhirs NV. All rights reserved.

// COM VARIANT structure and related functionality

#pragma once

#ifndef _BS_COM_VARIANT_INCLUDED_
#define _BS_COM_VARIANT_INCLUDED_

#include "com_defs.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


// ===== All Platforms =====

#define _VARIANT_TRUE   0xFFFF
#define _VARIANT_FALSE  0x0000


#ifndef _WIN32  // on Linux/Mac

  //  VARENUM usage key,
  //
  //    [V] - may appear in a VARIANT
  //    [T] - may appear in a TYPEDESC
  //    [P] - may appear in an OLE property set
  //    [S] - may appear in a Safe Array
  //
  //  VT_EMPTY            [V]   [P]     nothing
  //  VT_NULL             [V]   [P]     SQL style Null
  //  VT_I2               [V][T][P][S]  2 byte signed int
  //  VT_I4               [V][T][P][S]  4 byte signed int
  //  VT_R4               [V][T][P][S]  4 byte real
  //  VT_R8               [V][T][P][S]  8 byte real
  //  VT_CY               [V][T][P][S]  currency
  //  VT_DATE             [V][T][P][S]  date
  //  VT_BSTR             [V][T][P][S]  OLE Automation string
  //  VT_DISPATCH         [V][T][P][S]  IDispatch *
  //  VT_ERROR            [V][T]   [S]  SCODE
  //  VT_BOOL             [V][T][P][S]  True=-1, False=0
  //  VT_VARIANT          [V][T][P][S]  VARIANT *
  //  VT_UNKNOWN          [V][T]   [S]  IUnknown *
  //  VT_DECIMAL          [V][T]   [S]  16 byte fixed point
  //  VT_I1                  [T]        signed char
  //  VT_UI1              [V][T][P][S]  unsigned char
  //  VT_UI2                 [T][P]     unsigned short
  //  VT_UI4                 [T][P]     unsigned short
  //  VT_I8                  [T][P]     signed 64-bit int
  //  VT_UI8                 [T][P]     unsigned 64-bit int
  //  VT_INT                 [T]        signed machine int
  //  VT_UINT                [T]        unsigned machine int
  //  VT_VOID                [T]        C style void
  //  VT_HRESULT             [T]        Standard return type
  //  VT_PTR                 [T]        pointer type
  //  VT_SAFEARRAY           [T]        (use VT_ARRAY in VARIANT)
  //  VT_CARRAY              [T]        C style array
  //  VT_USERDEFINED         [T]        user defined type
  //  VT_LPSTR               [T][P]     null terminated string
  //  VT_LPWSTR              [T][P]     wide null terminated string
  //  VT_FILETIME               [P]     FILETIME
  //  VT_BLOB                   [P]     Length prefixed bytes
  //  VT_STREAM                 [P]     Name of the stream follows
  //  VT_STORAGE                [P]     Name of the storage follows
  //  VT_STREAMED_OBJECT        [P]     Stream contains an object
  //  VT_STORED_OBJECT          [P]     Storage contains an object
  //  VT_BLOB_OBJECT            [P]     Blob contains an object
  //  VT_CF                     [P]     Clipboard format
  //  VT_CLSID                  [P]     A Class ID
  //  VT_VECTOR                 [P]     simple counted array
  //  VT_ARRAY            [V]           SAFEARRAY*
  //  VT_BYREF            [V]           void* for local use

  // ----- VARENUM
  enum VARENUM
  {
      VT_EMPTY     = 0,
      VT_NULL      = 1,
      VT_I2        = 2,
      VT_I4        = 3,
      VT_R4        = 4,
      VT_R8        = 5,
      VT_CY        = 6,
      VT_DATE      = 7,
      VT_BSTR      = 8,
      VT_DISPATCH  = 9,
      VT_ERROR     = 10,
      VT_BOOL      = 11,
      VT_VARIANT   = 12,
      VT_UNKNOWN   = 13,
      VT_DECIMAL   = 14,
      VT_I1        = 16,
      VT_UI1       = 17,
      VT_UI2       = 18,
      VT_UI4       = 19,
      VT_I8        = 20,
      VT_UI8       = 21,
      VT_INT       = 22,
      VT_UINT      = 23,
      VT_VOID      = 24,
      VT_HRESULT   = 25,
      VT_PTR       = 26,
      VT_SAFEARRAY = 27,
      VT_CARRAY    = 28,
      VT_USERDEFINED = 29,
      VT_LPSTR     = 30,
      VT_LPWSTR    = 31,
      VT_RECORD    = 36,
      VT_INT_PTR   = 37,
      VT_UINT_PTR  = 38,
      VT_FILETIME  = 64,
      VT_BLOB      = 65,
      VT_STREAM    = 66,
      VT_STORAGE   = 67,
      VT_STREAMED_OBJECT = 68,
      VT_STORED_OBJECT = 69,
      VT_BLOB_OBJECT = 70,
      VT_CF        = 71,
      VT_CLSID     = 72,
      VT_VERSIONED_STREAM = 73,
      VT_BSTR_BLOB = 0xfff,
      VT_VECTOR    = 0x1000,
      VT_ARRAY     = 0x2000,
      VT_BYREF     = 0x4000,
      VT_RESERVED  = 0x8000,
      VT_ILLEGAL   = 0xffff,
      VT_ILLEGALMASKED = 0xfff,
      VT_TYPEMASK  = 0xfff
  };

  // ----- VARIANT
  #define __tagVARIANT
  #define __VARIANT_NAME_1
  #define __VARIANT_NAME_2
  #define __VARIANT_NAME_3
  #define __tagBRECORD
  #define __VARIANT_NAME_4

  struct tagVARIANT
  {
    union
    {
      struct __tagVARIANT
      {
        VARTYPE vt;
        WORD wReserved1;
        WORD wReserved2;
        WORD wReserved3;
        union
        {
          LONGLONG llVal;
          LONG lVal;
          BYTE bVal;
          SHORT iVal;
          FLOAT fltVal;
          DOUBLE dblVal;
          VARIANT_BOOL boolVal;
         _VARIANT_BOOL boolean;  // obsolete
          SCODE scode;
          CY cyVal;
          DATE date;
          BSTR bstrVal;
          IUnknown *punkVal;
          IDispatch *pdispVal;
          SAFEARRAY *parray;
          BYTE *pbVal;
          SHORT *piVal;
          LONG *plVal;
          LONGLONG *pllVal;
          FLOAT *pfltVal;
          DOUBLE *pdblVal;
          VARIANT_BOOL *pboolVal;
         _VARIANT_BOOL *pboolean;
          SCODE *pscode;
          CY *pcyVal;
          DATE *pdate;
          BSTR *pbstrVal;
          IUnknown **ppunkVal;
          IDispatch **ppdispVal;
          SAFEARRAY **pparray;
          VARIANT *pvarVal;
          PVOID byref;
          CHAR cVal;
          USHORT uiVal;
          ULONG ulVal;
          ULONGLONG ullVal;
          INT intVal;
          UINT uintVal;
          DECIMAL *pdecVal;
          CHAR *pcVal;
          USHORT *puiVal;
          ULONG *pulVal;
          ULONGLONG *pullVal;
          INT *pintVal;
          UINT *puintVal;

          struct __tagBRECORD
          {
            PVOID pvRecord;
            IRecordInfo *pRecInfo;
          } __VARIANT_NAME_4;

        } __VARIANT_NAME_3;

      } __VARIANT_NAME_2;

      DECIMAL decVal;
    } __VARIANT_NAME_1;
  };
  typedef struct tagVARIANT VARIANT;


  BRXEXPORT VOID     VariantInit         (VARIANTARG * pvarg);
  BRXEXPORT VOID     VariantInit         (VARIANTARG * pvarg, VARTYPE vt);
  BRXEXPORT HRESULT  VariantClear        (VARIANTARG * pvarg);
  BRXEXPORT HRESULT  VariantCopy         (VARIANTARG * pvargDest, VARIANTARG * pvargSrc);
  BRXEXPORT HRESULT  VariantCopyInd      (VARIANTARG * pvargDest, VARIANTARG * pvargSrc);
  BRXEXPORT HRESULT  VariantChangeType   (VARIANTARG * pvargDest, VARIANTARG * pvarSrc, USHORT wFlags, VARTYPE vt);
  BRXEXPORT HRESULT  VariantChangeTypeEx (VARIANTARG * pvargDest, VARIANTARG * pvarSrc, LCID lcid, USHORT wFlags, VARTYPE vt);

  // Flags for VariantChangeType/VariantChangeTypeEx
  #define VARIANT_NOVALUEPROP         0x01
  #define VARIANT_ALPHABOOL           0x02 // For VT_BOOL to VT_BSTR conversions, convert to "True"/"False" instead of "-1"/"0"
  #define VARIANT_NOUSEROVERRIDE      0x04 // For conversions to/from VT_BSTR, passes LOCALE_NOUSEROVERRIDE to core coercion routines
  #define VARIANT_CALENDAR_HIJRI      0x08
  #define VARIANT_LOCALBOOL           0x10 // For VT_BOOL to VT_BSTR and back, convert to local language rather than English
  #define VARIANT_CALENDAR_THAI       0x20 // SOUTHASIA calendar support
  #define VARIANT_CALENDAR_GREGORIAN  0x40 // GREGORIAN calendar support
  #define VARIANT_USE_NLS             0x80 // NLS function call support

  /* The VarDateFromStr and VarBstrFromDate functions also accept the
   * VAR_TIMEVALUEONLY and VAR_DATEVALUEONLY flags
   */
  #define VAR_TIMEVALUEONLY       ((DWORD)0x00000001)    /* return time value */
  #define VAR_DATEVALUEONLY       ((DWORD)0x00000002)    /* return date value */

  /* VarDateFromUdate() only */
  #define VAR_VALIDDATE           ((DWORD)0x00000004)

  /* Accepted by all date & format APIs */
  #define VAR_CALENDAR_HIJRI      ((DWORD)0x00000008)    /* use Hijri calender */

  /* Booleans can optionally be accepted in localized form. Pass VAR_LOCALBOOL
   * into VarBoolFromStr and VarBstrFromBool to use localized boolean names
   */
  #define VAR_LOCALBOOL           ((DWORD)0x00000010)

  /* When passed into VarFormat and VarFormatFromTokens, prevents substitution
   * of formats in the case where a string is passed in that can not be
   * coverted into the desired type. (for evar, 'Format("Hello", "General Number")')
   */
  #define VAR_FORMAT_NOSUBSTITUTE ((DWORD)0x00000020)

  /*
   * For VarBstrFromDate only - forces years to be 4 digits rather than shortening
   * to 2-digits when the years is in the date window.
   */
  #define VAR_FOURDIGITYEARS    ((DWORD)0x00000040)

  /*
   * Use NLS functions to format date, currency, time, and number.
   */
  #define LOCALE_USE_NLS 0x10000000

  #define VTDATEGRE_MAX 2958465   /* Dec 31, 9999, 0:0:0 in Gregorain Calendar */
  #define VTDATEGRE_MIN -657434   /* Jan  1,  100, 0:0:0 in Gregorain Calendar */

  /* SOUTHASIA
   * For VarBstrFromDate only - forces years to be 4 digits rather than shortening
   * to 2-digits when the years is in the date window.
   */
  #define VAR_CALENDAR_THAI    ((DWORD)0x00000080)
  #define VAR_CALENDAR_GREGORIAN ((DWORD)0x00000100)


  /* Note: The routines that convert *from* a string are defined
   * to take a OLECHAR* rather than a BSTR because no allocation is
   * required, and this makes the routines a bit more generic.
   * They may of course still be passed a BSTR as the strIn param.
   */

  BRXEXPORT HRESULT VarUI1FromI2    (SHORT sIn, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromI4    (LONG lIn, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromI8    (LONG64 i64In, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromR4    (FLOAT fltIn, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromR8    (DOUBLE dblIn, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromCy    (CY cyIn, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromDate  (DATE dateIn, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromStr   (OLECHAR * strIn, LCID lcid, ULONG dwFlags, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromDisp  (IDispatch * pdispIn, LCID lcid, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromBool  (VARIANT_BOOL boolIn, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromI1    (CHAR cIn, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromUI2   (USHORT uiIn, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromUI4   (ULONG ulIn, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromUI8   (ULONG64 ui64In, BYTE * pbOut);
  BRXEXPORT HRESULT VarUI1FromDec   (DECIMAL * pdecIn, BYTE * pbOut);

  BRXEXPORT HRESULT VarI2FromUI1    (BYTE bIn, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromI4     (LONG lIn, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromI8     (LONG64 i64In, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromR4     (FLOAT fltIn, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromR8     (DOUBLE dblIn, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromCy     (CY cyIn, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromDate   (DATE dateIn, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromStr    (OLECHAR * strIn, LCID lcid, ULONG dwFlags, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromDisp   (IDispatch * pdispIn, LCID lcid, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromBool   (VARIANT_BOOL boolIn, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromI1     (CHAR cIn, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromUI2    (USHORT uiIn, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromUI4    (ULONG ulIn, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromUI8    (ULONG64 ui64In, SHORT * psOut);
  BRXEXPORT HRESULT VarI2FromDec    (DECIMAL * pdecIn, SHORT * psOut);

  BRXEXPORT HRESULT VarI4FromUI1    (BYTE bIn, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromI2     (SHORT sIn, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromI8     (LONG64 i64In, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromR4     (FLOAT fltIn, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromR8     (DOUBLE dblIn, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromCy     (CY cyIn, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromDate   (DATE dateIn, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromStr    (OLECHAR * strIn, LCID lcid, ULONG dwFlags, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromDisp   (IDispatch * pdispIn, LCID lcid, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromBool   (VARIANT_BOOL boolIn, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromI1     (CHAR cIn, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromUI2    (USHORT uiIn, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromUI4    (ULONG ulIn, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromUI8    (ULONG64 ui64In, LONG * plOut);
  BRXEXPORT HRESULT VarI4FromDec    (DECIMAL * pdecIn, LONG * plOut);
  //BRXEXPORT HRESULT VarI4FromInt  (INT intIn, LONG * plOut);

  BRXEXPORT HRESULT VarI8FromUI1    (BYTE bIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromI2     (SHORT sIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromI4     (LONG lIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromR4     (FLOAT fltIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromR8     (DOUBLE dblIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromCy     (CY cyIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromDate   (DATE dateIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromStr    (OLECHAR * strIn, LCID lcid, unsigned long dwFlags, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromDisp   (IDispatch * pdispIn, LCID lcid, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromBool   (VARIANT_BOOL boolIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromI1     (CHAR cIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromUI2    (USHORT uiIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromUI4    (ULONG ulIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromUI8    (ULONG64 ui64In, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromDec    (DECIMAL * pdecIn, LONG64 * pi64Out);
  BRXEXPORT HRESULT VarI8FromInt    (INT intIn, LONG64 * pi64Out);

  BRXEXPORT HRESULT VarR4FromUI1    (BYTE bIn, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromI2     (SHORT sIn, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromI4     (LONG lIn, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromI8     (LONG64 i64In, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromR8     (DOUBLE dblIn, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromCy     (CY cyIn, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromDate   (DATE dateIn, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromStr    (OLECHAR * strIn, LCID lcid, ULONG dwFlags, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromDisp   (IDispatch * pdispIn, LCID lcid, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromBool   (VARIANT_BOOL boolIn, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromI1     (CHAR cIn, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromUI2    (USHORT uiIn, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromUI4    (ULONG ulIn, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromUI8    (ULONG64 ui64In, FLOAT * pfltOut);
  BRXEXPORT HRESULT VarR4FromDec    (DECIMAL *pdecIn, FLOAT * pfltOut);

  BRXEXPORT HRESULT VarR8FromUI1    (BYTE bIn, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromI2     (SHORT sIn, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromI4     (LONG lIn, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromI8     (LONG64 i64In, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromR4     (FLOAT fltIn, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromCy     (CY cyIn, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromDate   (DATE dateIn, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromStr    (OLECHAR *strIn, LCID lcid, ULONG dwFlags, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromDisp   (IDispatch * pdispIn, LCID lcid, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromBool   (VARIANT_BOOL boolIn, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromI1     (CHAR cIn, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromUI2    (USHORT uiIn, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromUI4    (ULONG ulIn, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromUI8    (ULONG64 ui64In, DOUBLE * pdblOut);
  BRXEXPORT HRESULT VarR8FromDec    (DECIMAL * pdecIn, DOUBLE * pdblOut);

  BRXEXPORT HRESULT VarDateFromUI1  (BYTE bIn, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromI2   (SHORT sIn, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromI4   (LONG lIn, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromI8   (LONG64 i64In, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromR4   (FLOAT fltIn, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromR8   (DOUBLE dblIn, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromCy   (CY cyIn, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromStr  (OLECHAR *strIn, LCID lcid, ULONG dwFlags, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromDisp (IDispatch * pdispIn, LCID lcid, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromBool (VARIANT_BOOL boolIn, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromI1   (CHAR cIn, DATE *pdateOut);
  BRXEXPORT HRESULT VarDateFromUI2  (USHORT uiIn, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromUI4  (ULONG ulIn, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromUI8  (ULONG64 ui64In, DATE * pdateOut);
  BRXEXPORT HRESULT VarDateFromDec  (DECIMAL * pdecIn, DATE * pdateOut);

  BRXEXPORT HRESULT VarCyFromUI1    (BYTE bIn, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromI2     (SHORT sIn, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromI4     (LONG lIn, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromI8     (LONG64 i64In, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromR4     (FLOAT fltIn, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromR8     (DOUBLE dblIn, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromDate   (DATE dateIn, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromStr    (OLECHAR * strIn, LCID lcid, ULONG dwFlags, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromDisp   (IDispatch * pdispIn, LCID lcid, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromBool   (VARIANT_BOOL boolIn, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromI1     (CHAR cIn, CY *pcyOut);
  BRXEXPORT HRESULT VarCyFromUI2    (USHORT uiIn, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromUI4    (ULONG ulIn, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromUI8    (ULONG64 ui64In, CY * pcyOut);
  BRXEXPORT HRESULT VarCyFromDec    (DECIMAL * pdecIn, CY * pcyOut);

  BRXEXPORT HRESULT VarBstrFromUI1  (BYTE bVal, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromI2   (SHORT iVal, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromI4   (LONG lIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromI8   (LONG64 i64In, LCID lcid, unsigned long dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromR4   (FLOAT fltIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromR8   (DOUBLE dblIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromCy   (CY cyIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromDate (DATE dateIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromDisp (IDispatch * pdispIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromBool (VARIANT_BOOL boolIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromI1   (CHAR cIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromUI2  (USHORT uiIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromUI4  (ULONG ulIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromUI8  (ULONG64 ui64In, LCID lcid, unsigned long dwFlags, BSTR * pbstrOut);
  BRXEXPORT HRESULT VarBstrFromDec  (DECIMAL * pdecIn, LCID lcid, ULONG dwFlags, BSTR * pbstrOut);

  BRXEXPORT HRESULT VarBoolFromUI1  (BYTE bIn, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromI2   (SHORT sIn, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromI4   (LONG lIn, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromI8   (LONG64 i64In, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromR4   (FLOAT fltIn, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromR8   (DOUBLE dblIn, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromDate (DATE dateIn, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromCy   (CY cyIn, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromStr  (OLECHAR * strIn, LCID lcid, ULONG dwFlags, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromDisp (IDispatch * pdispIn, LCID lcid, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromI1   (CHAR cIn, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromUI2  (USHORT uiIn, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromUI4  (ULONG ulIn, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromUI8  (ULONG64 i64In, VARIANT_BOOL * pboolOut);
  BRXEXPORT HRESULT VarBoolFromDec  (DECIMAL * pdecIn, VARIANT_BOOL * pboolOut);

  BRXEXPORT HRESULT VarI1FromUI1    (BYTE bIn, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromI2     (SHORT uiIn, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromI4     (LONG lIn, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromI8     (LONG64 i64In, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromR4     (FLOAT fltIn, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromR8     (DOUBLE dblIn, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromDate   (DATE dateIn, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromCy     (CY cyIn, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromStr    (OLECHAR * strIn, LCID lcid, ULONG dwFlags, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromDisp   (IDispatch *pdispIn, LCID lcid, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromBool   (VARIANT_BOOL boolIn, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromUI2    (USHORT uiIn, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromUI4    (ULONG ulIn, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromUI8    (ULONG64 i64In, CHAR * pcOut);
  BRXEXPORT HRESULT VarI1FromDec    (DECIMAL * pdecIn, CHAR * pcOut);

  BRXEXPORT HRESULT VarUI2FromUI1   (BYTE bIn, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromI2    (SHORT uiIn, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromI4    (LONG lIn, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromI8    (LONG64 i64In, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromR4    (FLOAT fltIn, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromR8    (DOUBLE dblIn, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromDate  (DATE dateIn, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromCy    (CY cyIn, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromStr   (OLECHAR * strIn, LCID lcid, ULONG dwFlags, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromDisp  (IDispatch * pdispIn, LCID lcid, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromBool  (VARIANT_BOOL boolIn, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromI1    (CHAR cIn, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromUI4   (ULONG ulIn, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromUI8   (ULONG64 i64In, USHORT * puiOut);
  BRXEXPORT HRESULT VarUI2FromDec   (DECIMAL * pdecIn, USHORT * puiOut);

  BRXEXPORT HRESULT VarUI4FromUI1   (BYTE bIn, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromI2    (SHORT uiIn, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromI4    (LONG lIn, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromI8    (LONG64 i64In, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromR4    (FLOAT fltIn, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromR8    (DOUBLE dblIn, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromDate  (DATE dateIn, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromCy    (CY cyIn, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromStr   (OLECHAR * strIn, LCID lcid, ULONG dwFlags, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromDisp  (IDispatch * pdispIn, LCID lcid, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromBool  (VARIANT_BOOL boolIn, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromI1    (CHAR cIn, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromUI2   (USHORT uiIn, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromUI8   (ULONG64 ui64In, ULONG * pulOut);
  BRXEXPORT HRESULT VarUI4FromDec   (DECIMAL * pdecIn, ULONG * pulOut);

  BRXEXPORT HRESULT VarUI8FromUI1   (BYTE bIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromI2    (SHORT sIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromI4    (LONG lIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromI8    (LONG64 ui64In, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromR4    (FLOAT fltIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromR8    (DOUBLE dblIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromCy    (CY cyIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromDate  (DATE dateIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromStr   (OLECHAR * strIn, LCID lcid, unsigned long dwFlags, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromDisp  (IDispatch * pdispIn, LCID lcid, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromBool  (VARIANT_BOOL boolIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromI1    (CHAR cIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromUI2   (USHORT uiIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromUI4   (ULONG ulIn, ULONG64 * pi64Out);
  BRXEXPORT HRESULT VarUI8FromDec   (DECIMAL * pdecIn, ULONG64 * pi64Out);

  BRXEXPORT HRESULT VarDecFromUI1   (BYTE bIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromI2    (SHORT uiIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromI4    (LONG lIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromI8    (LONG64 i64In, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromR4    (FLOAT fltIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromR8    (DOUBLE dblIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromDate  (DATE dateIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromCy    (CY cyIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromStr   (OLECHAR * strIn, LCID lcid, ULONG dwFlags, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromDisp  (IDispatch * pdispIn, LCID lcid, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromBool  (VARIANT_BOOL boolIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromI1    (CHAR cIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromUI2   (USHORT uiIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromUI4   (ULONG ulIn, DECIMAL * pdecOut);
  BRXEXPORT HRESULT VarDecFromUI8   (ULONG64 ui64In, DECIMAL * pdecOut);

  #define VarUI4FromUI4(in, pOut) (*(pOut) = (in))
  #define VarI4FromI4(in, pOut)   (*(pOut) = (in))
  #define VarUI8FromUI8(in, pOut) (*(pOut) = (in))
  #define VarI8FromI8(in, pOut)   (*(pOut) = (in))

  #define VarUI1FromInt       VarUI1FromI4
  #define VarUI1FromUint      VarUI1FromUI4
  #define VarI2FromInt        VarI2FromI4
  #define VarI2FromUint       VarI2FromUI4
  #define VarI4FromInt        VarI4FromI4
  #define VarI4FromUint       VarI4FromUI4
  #define VarI8FromInt        VarI8FromI4
  #define VarI8FromUint       VarI8FromUI4
  #define VarR4FromInt        VarR4FromI4
  #define VarR4FromUint       VarR4FromUI4
  #define VarR8FromInt        VarR8FromI4
  #define VarR8FromUint       VarR8FromUI4
  #define VarDateFromInt      VarDateFromI4
  #define VarDateFromUint     VarDateFromUI4
  #define VarCyFromInt        VarCyFromI4
  #define VarCyFromUint       VarCyFromUI4
  #define VarBstrFromInt      VarBstrFromI4
  #define VarBstrFromUint     VarBstrFromUI4
  #define VarBoolFromInt      VarBoolFromI4
  #define VarBoolFromUint     VarBoolFromUI4
  #define VarI1FromInt        VarI1FromI4
  #define VarI1FromUint       VarI1FromUI4
  #define VarUI2FromInt       VarUI2FromI4
  #define VarUI2FromUint      VarUI2FromUI4
  #define VarUI4FromInt       VarUI4FromI4
  #define VarUI4FromUint      VarUI4FromUI4
  #define VarUI8FromInt       VarUI8FromI4
  #define VarUI8FromUint      VarUI8FromUI4
  #define VarDecFromInt       VarDecFromI4
  #define VarDecFromUint      VarDecFromUI4
  #define VarIntFromUI1       VarI4FromUI1
  #define VarIntFromI2        VarI4FromI2
  #define VarIntFromI4        VarI4FromI4
  #define VarIntFromI8        VarI4FromI8
  #define VarIntFromR4        VarI4FromR4
  #define VarIntFromR8        VarI4FromR8
  #define VarIntFromDate      VarI4FromDate
  #define VarIntFromCy        VarI4FromCy
  #define VarIntFromStr       VarI4FromStr
  #define VarIntFromDisp      VarI4FromDisp
  #define VarIntFromBool      VarI4FromBool
  #define VarIntFromI1        VarI4FromI1
  #define VarIntFromUI2       VarI4FromUI2
  #define VarIntFromUI4       VarI4FromUI4
  #define VarIntFromUI8       VarI4FromUI8
  #define VarIntFromDec       VarI4FromDec
  #define VarIntFromUint      VarI4FromUI4
  #define VarUintFromUI1      VarUI4FromUI1
  #define VarUintFromI2       VarUI4FromI2
  #define VarUintFromI4       VarUI4FromI4
  #define VarUintFromI8       VarUI4FromI8
  #define VarUintFromR4       VarUI4FromR4
  #define VarUintFromR8       VarUI4FromR8
  #define VarUintFromDate     VarUI4FromDate
  #define VarUintFromCy       VarUI4FromCy
  #define VarUintFromStr      VarUI4FromStr
  #define VarUintFromDisp     VarUI4FromDisp
  #define VarUintFromBool     VarUI4FromBool
  #define VarUintFromI1       VarUI4FromI1
  #define VarUintFromUI2      VarUI4FromUI2
  #define VarUintFromUI4      VarUI4FromUI4
  #define VarUintFromUI8      VarUI4FromUI8
  #define VarUintFromDec      VarUI4FromDec
  #define VarUintFromInt      VarUI4FromI4


  BRXEXPORT HRESULT VarBstrCat (BSTR bstrLeft, BSTR bstrRight, LPBSTR pbstrResult);


  // utility macros for VARIANT
  #define V_UNION(var, elem) ((var)->elem)
  #define V_VT(var)          ((var)->vt)
  #define V_RECORDINFO(var)  ((var)->pRecInfo)
  #define V_RECORD(var)      ((var)->pvRecord)
                             
  #define V_ISBYREF(var)     (V_VT(var)&VT_BYREF)
  #define V_ISARRAY(var)     (V_VT(var)&VT_ARRAY)
  #define V_ISVECTOR(var)    (V_VT(var)&VT_VECTOR)
  #define V_NONE(var)        V_I2(var)

  #define V_UI1(var)         V_UNION(var, bVal)
  #define V_UI1REF(var)      V_UNION(var, pbVal)
  #define V_I2(var)          V_UNION(var, iVal)
  #define V_I2REF(var)       V_UNION(var, piVal)
  #define V_I4(var)          V_UNION(var, lVal)
  #define V_I4REF(var)       V_UNION(var, plVal)
  #define V_I8(var)          V_UNION(var, llVal)
  #define V_I8REF(var)       V_UNION(var, pllVal)
  #define V_R4(var)          V_UNION(var, fltVal)
  #define V_R4REF(var)       V_UNION(var, pfltVal)
  #define V_R8(var)          V_UNION(var, dblVal)
  #define V_R8REF(var)       V_UNION(var, pdblVal)
  #define V_I1(var)          V_UNION(var, cVal)
  #define V_I1REF(var)       V_UNION(var, pcVal)
  #define V_UI2(var)         V_UNION(var, uiVal)
  #define V_UI2REF(var)      V_UNION(var, puiVal)
  #define V_UI4(var)         V_UNION(var, ulVal)
  #define V_UI4REF(var)      V_UNION(var, pulVal)
  #define V_UI8(var)         V_UNION(var, ullVal)
  #define V_UI8REF(var)      V_UNION(var, pullVal)
  #define V_INT(var)         V_UNION(var, intVal)
  #define V_INTREF(var)      V_UNION(var, pintVal)
  #define V_UINT(var)        V_UNION(var, uintVal)
  #define V_UINTREF(var)     V_UNION(var, puintVal)
  #define V_CY(var)          V_UNION(var, cyVal)
  #define V_CYREF(var)       V_UNION(var, pcyVal)
  #define V_DATE(var)        V_UNION(var, date)
  #define V_DATEREF(var)     V_UNION(var, pdate)
  #define V_BSTR(var)        V_UNION(var, bstrVal)
  #define V_BSTRREF(var)     V_UNION(var, pbstrVal)
  #define V_DISPATCH(var)    V_UNION(var, pdispVal)
  #define V_DISPATCHREF(var) V_UNION(var, ppdispVal)
  #define V_ERROR(var)       V_UNION(var, scode)
  #define V_ERRORREF(var)    V_UNION(var, pscode)
  #define V_BOOL(var)        V_UNION(var, boolVal)
  #define V_BOOLREF(var)     V_UNION(var, pboolVal)
  #define V_UNKNOWN(var)     V_UNION(var, punkVal)
  #define V_UNKNOWNREF(var)  V_UNION(var, ppunkVal)
  #define V_VARIANTREF(var)  V_UNION(var, pvarVal)
  #define V_ARRAY(var)       V_UNION(var, parray)
  #define V_ARRAYREF(var)    V_UNION(var, pparray)
  #define V_BYREF(var)       V_UNION(var, byref)
  #define V_DECIMAL(var)     V_UNION(var, decVal)
  #define V_DECIMALREF(var)  V_UNION(var, pdecVal)

  #ifdef _WIN64
    #define V_INT_PTR(var)      V_UNION(var, llVal)
    #define V_UINT_PTR(var)     V_UNION(var, ullVal)
    #define V_INT_PTRREF(var)   V_UNION(var, pllVal)
    #define V_UINT_PTRREF(var)  V_UNION(var, pullVal)
  #else
    #define V_INT_PTR(var)      V_UNION(var, lVal)
    #define V_UINT_PTR(var)     V_UNION(var, ulVal)
    #define V_INT_PTRREF(var)   V_UNION(var, plVal)
    #define V_UINT_PTRREF(var)  V_UNION(var, pulVal)
  #endif


  static VARIANT_BOOL   VARIANT_TRUE  = 0xFFFF;
  static VARIANT_BOOL   VARIANT_FALSE = 0x0000;


#endif // _WIN32


// ----- VARIANT helper functions

// forwards
typedef double ads_point[3];
typedef double sds_point[3];

namespace VariantHelper
{
  BRXEXPORT void setOptionalArgumentVariant (VARIANT * pVariant);

  BRXEXPORT bool getNumberFromVariant    (const VARIANT * pVariant, int & value);
  BRXEXPORT bool getNumberFromVariant    (const VARIANT * pVariant, long & value);
  BRXEXPORT bool getNumberFromVariant    (const VARIANT * pVariant, double & value);
  BRXEXPORT bool getStringFromVariant    (const VARIANT * pVariant, LPCTSTR * value);
  BRXEXPORT bool getDispatchFromVariant  (const VARIANT * pVariant, IDispatch * & value);
  BRXEXPORT bool getSafeArrayFromVariant (const VARIANT * pVariant, SAFEARRAY * & value);
  BRXEXPORT bool getBoolFromVariant      (const VARIANT * pVariant, bool & value);
  BRXEXPORT bool getPointFromVariant     (const VARIANT * pVariant, ads_point & value);
  BRXEXPORT bool getPointFromSafeArray   (const SAFEARRAY * pArray, ads_point & value, VARTYPE vtype = VT_R8);

  BRXEXPORT bool isArrayVarType   (const VARTYPE vt);
  BRXEXPORT bool isIntegerVarType (const VARTYPE vt);
  BRXEXPORT bool isNumberVarType  (const VARTYPE vt);
  BRXEXPORT bool isFloatVarType   (const VARTYPE vt);
  BRXEXPORT bool isStringVarType  (const VARTYPE vt);
  BRXEXPORT bool isBoolVarType    (const VARTYPE vt);

  static VARIANT sv_OptionalArgumentVariant = { { { VT_ERROR, 0, 0, 0, { DISP_E_PARAMNOTFOUND } } } };

} // namespace VariantHelper

#define sv_empty_argument  (VariantHelper::sv_OptionalArgumentVariant)

#endif // _BS_COM_VARIANT_INCLUDED_
