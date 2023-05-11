//
// StdArx.h : include file for ObjectARX/DBX include files
// this file is only included once by your stdafx.h

#if !defined(AFX_STDARX_H__FA0C08E0_5302_4391_B0BF_D9B7F1AF3BEE__INCLUDED_)
#define AFX_STDARX_H__FA0C08E0_5302_4391_B0BF_D9B7F1AF3BEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef _WIN32 // Linux,Mac
  #include "brx_platform_linux.h"
#endif

#ifdef DD_T
#undef DD_T
#endif
#ifdef __DD_T
#undef __DD_T
#endif
#define DD_T(x) ((const OdChar*)__DD_T(x))
#define __DD_T(x) L ## x

#endif 
