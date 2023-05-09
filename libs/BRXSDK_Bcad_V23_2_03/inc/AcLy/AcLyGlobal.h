// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

//common forward declarations
class AcDbDatabase;
class AcLyLayerFilterManager;

BRX_IMPORTEXPORT AcLyLayerFilterManager* aclyGetLayerFilterManager(AcDbDatabase*);