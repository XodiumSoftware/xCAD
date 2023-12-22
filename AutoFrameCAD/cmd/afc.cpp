#include "afc.hpp"

extern "C" AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
    switch (msg) {
    case AcRx::kInitAppMsg:
        acrxDynamicLinker->registerAppMDIAware(pkt);
        acrxDynamicLinker->unlockApplication(pkt); 
        acrxRegisterAppMDIAware(pkt);
        break;
    case AcRx::kUnloadAppMsg:
        acedRegCmds->removeGroup(_T("HELLO_GROUP"));
        break;
    }
    return AcRx::kRetOK;
}

void initApp()
{
    acedRegCmds->addCommand(_T("HELLO_GROUP"), _T("HELLO"), _T("HELLO"), ACRX_CMD_MODAL, hello);
}

void unloadApp()
{
    acedRegCmds->removeGroup(_T("HELLO_GROUP"));
}

void hello()
{
    acutPrintf(_T("\nHello, BricsCAD!"));
}