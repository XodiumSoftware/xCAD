// Copyright (C) Menhirs NV. All rights reserved.
#pragma once

/** _ */
enum BRX_IMPORTEXPORT AcFileSelectFlags : unsigned int
{
    kDLFNoType = 0x0000000,
    kDLFPut = 0x00000001,
    kDLFDwg = 0x00000002,
    kDLFPathOnly = 0x00000004,
    kDLFNoWarn = 0x00000008,
    kDLFNoExistOk = 0x00000010,
    kDLFAnyExt = 0x00000020,
    kDLFRqBox = 0x00000040,
    kDLFSaveas = 0x00000080,
    kDLFNoLib = 0x00000100,
    kDLFNoXfer = 0x00000200,
    kDLFNoURLs = 0x00000400,
    kDLFDwgDef = 0x00000800,
    kDLFOpenDef = 0x00001000,
    kDLFDvc = 0x00002000,
    kDLFDwt = 0x00004000,
    kDLFOpts = 0x00008000,
    kDLFNoPopup = 0x00010000,
    kDLFFrcWarn = 0x00020000,
    kDLFMulti = 0x00040000,
    kDLFCLI = 0x00080000,
    kDLFRecover = 0x00100000,
    kDLFForceDir = 0x00200000,
    kDLFNoFTP = 0x00400000,
    kDLFNoAnav = 0x00800000,
    kDLFFolders = 0x01000000,
    kDLFNoExtensions = 0x02000000,
    kDLFNoTemplate = 0x04000000,
    kDLFExport = 0x08000000,
    kDLFEnableRememberFolders = 0x10000000,
    kDLFOpenSample = 0x20000000,
    kDLFUseCloud = 0x40000000,
    kDLFCloudControls = 0x80000000
};
