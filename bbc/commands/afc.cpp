#include <aced.h>
#include <rxregsvc.h>
#include <dbents.h>
#include <dbapserv.h>

void drawRectangle()
{
    // Get the current database and start a transaction
    AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
    AcDbBlockTable *pBlockTable;
    pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
    AcDbBlockTableRecord *pBlockTableRecord;
    pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
    pBlockTable->close();

    // Create a rectangle
    AcGePoint3d pt1(0, 0, 0);
    AcGePoint3d pt2(10, 10, 0);
    AcDbPolyline *pRectangle = new AcDbPolyline(4);
    pRectangle->addVertexAt(0, AcGePoint2d(pt1.x, pt1.y));
    pRectangle->addVertexAt(1, AcGePoint2d(pt2.x, pt1.y));
    pRectangle->addVertexAt(2, AcGePoint2d(pt2.x, pt2.y));
    pRectangle->addVertexAt(3, AcGePoint2d(pt1.x, pt2.y));
    pRectangle->setClosed(Adesk::kTrue);

    // Add the rectangle to the database
    pBlockTableRecord->appendAcDbEntity(pRectangle);
    pBlockTableRecord->close();
    pRectangle->close();
}

extern "C" __declspec(dllexport) AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void *pkt)
{
    switch (msg)
    {
    case AcRx::kInitAppMsg:
        acrxDynamicLinker->registerAppMDIAware(pkt);
        acedRegCmds->addCommand(_T("DRAW_RECTANGLE"), _T("DRAWRECT"), _T("DRAWRECT"), ACRX_CMD_MODAL, drawRectangle);
        break;
    case AcRx::kUnloadAppMsg:
        acedRegCmds->removeGroup(_T("DRAW_RECTANGLE"));
        break;
    default:
        break;
    }
    return AcRx::kRetOK;
}
