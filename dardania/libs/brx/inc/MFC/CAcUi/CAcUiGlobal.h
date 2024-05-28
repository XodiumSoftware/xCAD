// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

void InitAcUiDLL();
BOOL AcUiEnableToolTips();
BOOL AcUiIsInputPending();
HINSTANCE AcUiAppResourceInstance();
LPCTSTR AcUiContextHelpFileName();

#ifdef _WIN32 // currently only under Windows

CWnd* AcUiMainWindow();
BOOL AcUiFindContextHelpFullPath(LPCTSTR,CString&);
void AcUiRootKey(CString&);

#endif // _WIN32
