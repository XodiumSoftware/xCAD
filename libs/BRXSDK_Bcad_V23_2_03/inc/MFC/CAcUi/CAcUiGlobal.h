// Copyright (C) Menhirs NV. All rights reserved.
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
