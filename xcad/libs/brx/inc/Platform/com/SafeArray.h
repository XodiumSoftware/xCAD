// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

// COM SAFEARRAY structure and related functionality

#ifndef _BS_COM_SAFEARRAY_INCLUDED_
#define _BS_COM_SAFEARRAY_INCLUDED_

#include "com_defs.h"


#ifndef BRXEXPORT // for client build : import
#define BRXEXPORT
#endif


#ifndef _WIN32  // on Linux/Mac

  // ----- SAFEARRAYBOUND
  typedef struct tagSAFEARRAYBOUND
  {
      ULONG cElements;
      LONG lLbound;
  } SAFEARRAYBOUND;
  typedef struct tagSAFEARRAYBOUND *LPSAFEARRAYBOUND;

  // ----- SAFEARRAY
  typedef struct tagSAFEARRAY
  {
      USHORT cDims;
      USHORT fFeatures;
      ULONG cbElements;
      ULONG cLocks;
      PVOID pvData;
      SAFEARRAYBOUND * rgsabound;//[1];
  } SAFEARRAY;
  typedef SAFEARRAY *LPSAFEARRAY;


  #define  FADF_AUTO         ( 0x1 )
  #define  FADF_STATIC       ( 0x2 )
  #define  FADF_EMBEDDED     ( 0x4 )
  #define  FADF_FIXEDSIZE    ( 0x10 )
  #define  FADF_RECORD       ( 0x20 )
  #define  FADF_HAVEIID      ( 0x40 )
  #define  FADF_HAVEVARTYPE  ( 0x80 )
  #define  FADF_BSTR         ( 0x100 )
  #define  FADF_UNKNOWN      ( 0x200 )
  #define  FADF_DISPATCH     ( 0x400 )
  #define  FADF_VARIANT      ( 0x800 )
  #define  FADF_RESERVED     ( 0xf008 )


  BRXEXPORT HRESULT  SafeArrayAllocDescriptor   (unsigned int cDims, SAFEARRAY ** ppsaOut);
  BRXEXPORT HRESULT  SafeArrayAllocDescriptorEx (VARTYPE vt, unsigned int cDims, SAFEARRAY ** ppsaOut);
  BRXEXPORT HRESULT  SafeArrayAllocData         (SAFEARRAY * psa);

  BRXEXPORT SAFEARRAY * SafeArrayCreate         (VARTYPE vt, unsigned int cDims, SAFEARRAYBOUND * rgsabound);
  BRXEXPORT SAFEARRAY * SafeArrayCreateEx       (VARTYPE vt, unsigned int cDims, SAFEARRAYBOUND * rgsabound, PVOID pvExtra);

  BRXEXPORT SAFEARRAY * SafeArrayCreateVector   (VARTYPE vt, long lLbound, unsigned int cElements);
  BRXEXPORT SAFEARRAY * SafeArrayCreateVectorEx (VARTYPE vt, long lLbound, unsigned int cElements, LPVOID pvExtra);

  BRXEXPORT UINT     SafeArrayGetDim       (SAFEARRAY * psa);
  BRXEXPORT HRESULT  SafeArrayGetLBound    (SAFEARRAY * psa, unsigned int nDim, long * plLbound);
  BRXEXPORT HRESULT  SafeArrayGetUBound    (SAFEARRAY * psa, unsigned int nDim, long * plUbound);

  BRXEXPORT UINT     SafeArrayGetElemsize  (SAFEARRAY * psa);
  BRXEXPORT HRESULT  SafeArrayGetVartype   (SAFEARRAY * psa, VARTYPE * pvt);

  BRXEXPORT HRESULT  SafeArrayPtrOfIndex   (SAFEARRAY * psa, long * rgIndices, void ** ppvData);
  BRXEXPORT HRESULT  SafeArrayGetElement   (SAFEARRAY * psa, long * rgIndices, void * pv);
  BRXEXPORT HRESULT  SafeArrayPutElement   (SAFEARRAY * psa, long * rgIndices, void * pv);

  BRXEXPORT HRESULT  SafeArrayCopy         (SAFEARRAY * psaSrc, SAFEARRAY ** psaDst);
  BRXEXPORT HRESULT  SafeArrayCopyData     (SAFEARRAY * psaSrc, SAFEARRAY * psaDst);

  BRXEXPORT HRESULT  SafeArrayLock         (SAFEARRAY * psa);
  BRXEXPORT HRESULT  SafeArrayUnlock       (SAFEARRAY * psa);

  BRXEXPORT HRESULT  SafeArrayAccessData   (SAFEARRAY * psa, void ** ppvData);
  BRXEXPORT HRESULT  SafeArrayUnaccessData (SAFEARRAY * psa);

  BRXEXPORT HRESULT  SafeArrayDestroyData       (SAFEARRAY * psa);
  BRXEXPORT HRESULT  SafeArrayDestroyDescriptor (SAFEARRAY * psa);
  BRXEXPORT HRESULT  SafeArrayDestroy           (SAFEARRAY * psa);


  BRXEXPORT HRESULT  VectorFromBstr (BSTR source, SAFEARRAY ** ppsa);
  BRXEXPORT HRESULT  BstrFromVector (SAFEARRAY *source, BSTR *pbstr);


#endif // !_WIN32


// ----- SAFEARRAY helper functions

// forwards
typedef double ads_point[3];
typedef double sds_point[3];

namespace SafeArrayHelper
{
  BRXEXPORT SAFEARRAY * makeSafeArrayFromPoint  (ads_point pt, int iDimension);
  BRXEXPORT SAFEARRAY * makeSafeArrayFromArray  (double * arr, int iCount);

  BRXEXPORT bool getPointFromSafeArray  (const SAFEARRAY * pArray, ads_point & value, VARTYPE vtype = VT_R8);
  BRXEXPORT bool getArrayFromSafeArray  (const SAFEARRAY * pArray, double* & value, int & iCount);


} // namespace SafeArrayHelper


#endif // _BS_COM_SAFEARRAY_INCLUDED_
