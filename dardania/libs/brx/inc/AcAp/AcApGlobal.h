// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#ifdef _WIN32
#include <wtypes.h> //HINSTANCE
#endif

//common forward declarations
class AcApDocManager;
class AcApDocument;
class AcApLongTransactionManager;
class AcApStatusBar;
class AcDbDatabase;
class AcEdInputPointManager;
class AcTransactionManager;
class CDocument;
class CView;
struct IDispatch;

struct AcAp
{
    enum DocLockMode
    {
        kNone = 0,
        kAutoWrite = 1,
        kNotLocked = 2,
        kWrite = 4,
        kProtectedAutoWrite = 20,
        kRead = 32,
        kXWrite = 64
    };
};

#define AC_DOCUMENT_MANAGER_OBJ _T("AcApDocManager")
#define AC_LONG_TRANSACTION_MANAGER_OBJ _T("AcApLongTransactionManager")

AcApDocManager* acDocManagerPtr();
#define acDocManager acDocManagerPtr()

AcApLongTransactionManager* acapLongTransactionManagerPtr();
#define acapLongTransactionManager acapLongTransactionManagerPtr()

AcDbDatabase* AcApGetDatabase(CView*);