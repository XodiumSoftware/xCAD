// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "cmdCom.h"

//needed for CLSID_AcadApplication
#include "acadi_i.c"

#ifdef BRX_APP
using namespace BricscadDb;
using namespace BricscadApp;
#else
using namespace AutoCAD;
#endif

void cmdCallCom()
{
    ::CoInitialize(NULL);

    USES_CONVERSION;

    //get the CAD application object
    IAcadApplicationPtr CadApp = NULL;
    CadApp.GetActiveObject(CLSID_AcadApplication);
    assert(NULL != CadApp);

    //get the active document
    IAcadDocumentPtr ActiveDoc = CadApp->ActiveDocument;
    assert(NULL != ActiveDoc);

    //print the name of the active document
    BSTR docName = ActiveDoc->Name;
    acutPrintf(ACRX_T("\nThe active document name is: %s"),W2T(docName));

    //get the active layer
    IAcadLayerPtr Layer = ActiveDoc->ActiveLayer;
    assert(NULL != Layer);

    //print the name of the active layer
    BSTR layerName = Layer->Name;
    acutPrintf(ACRX_T("\nThe active layer name is: %s\n"),W2T(layerName));

    //send a command to the command line
    ActiveDoc->SendCommand(_T("_REDRAW "));

    //cleanup
    Layer = NULL;
    ActiveDoc = NULL;
    CadApp = NULL;

    CoUninitialize(); 
}
