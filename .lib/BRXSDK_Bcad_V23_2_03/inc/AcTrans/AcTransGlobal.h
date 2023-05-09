// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

//common forward declarations
class AcTransaction;
class AcTransactionManager;
class AcTransactionReactor;

AcTransactionManager* acTransactionManagerPtr();
#define actrTransactionManager acTransactionManagerPtr()