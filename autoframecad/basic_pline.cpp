#include <aced.h>
#include <dbents.h>
#include <dbapserv.h>

void DrawLine()
{
    AcGePoint3d startPt(0.0, 0.0, 0.0);
    AcGePoint3d endPt(10.0, 10.0, 0.0);

    AcDbLine *pLine = new AcDbLine(startPt, endPt);
    AcDbBlockTable *pBlockTable;
    acdbHostApplicationServices()->workingDatabase()->getBlockTable(pBlockTable, AcDb::kForRead);

    AcDbBlockTableRecord *pBlockTableRecord;
    pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
    pBlockTable->close();

    pBlockTableRecord->appendAcDbEntity(pLine);
    pBlockTableRecord->close();

    acutPrintf("Line drawn successfully.\n");
}

void HelloWorldCmd()
{
    DrawLine();
}

extern "C" __declspec(dllexport) AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void *pkt)
{
    switch (msg)
    {
    case AcRx::kInitAppMsg:
        acedRegCmds->addCommand(_T("HELLO"), _T("HELLO"), _T("WORLD"), ACRX_CMD_MODAL, HelloWorldCmd);
        break;
    case AcRx::kUnloadAppMsg:
        acedRegCmds->removeGroup(_T("HELLO"));
        break;
    }
    return AcRx::kRetOK;
}