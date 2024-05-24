// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

//common forward declarations
class AcTransaction;
class AcTransactionManager;
class AcTransactionReactor;

AcTransactionManager* acTransactionManagerPtr();
#define actrTransactionManager acTransactionManagerPtr()