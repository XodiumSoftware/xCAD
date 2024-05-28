// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "cmdDbx.h"

#include "../dbx/MyEntity.h"


void cmdMyEntity()
{
    ads_point adsPoint;
    if (RTNORM != acedGetPoint(NULL, _T("\nInsertion point..."), adsPoint))
        return;

    const double r = 1.0;
    AcGePoint3d center = asPnt3d(adsPoint);
    AcGePoint3d point1(center.x - r, center.y, center.z);
    AcGePoint3d point2(center.x, center.y + r, center.z);
    AcGePoint3d point3(center.x + r, center.y, center.z);

    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();

    AcDbBlockTable* pBlockTable = NULL;
    pDb->getSymbolTable(pBlockTable, AcDb::kForRead);

    AcDbBlockTableRecord* pBlockTableRecord = NULL;
    pBlockTable->getAt(ACDB_MODEL_SPACE, pBlockTableRecord, AcDb::kForWrite);
    pBlockTable->close();

    CMyEntity* pMyEntity = new CMyEntity(point1, point2, point3);

    pMyEntity->setDatabaseDefaults(pDb);
    pBlockTableRecord->appendAcDbEntity(pMyEntity);
    pBlockTableRecord->close();

    pMyEntity->close();

#ifdef BRX_APP
    acutPrintf(_T("\nCustom entity added to the drawing. Please try grip edit on this entity.\nSee PropertiesPanel : entity properties + NoSelection properties are shown."));
#else
    acutPrintf(_T("\nCustom entity added to the drawing. Please try grip edit on this entity."));
#endif
}



static AcString getPath(AcDbDatabase* pDb)
{
    const ACHAR* pFileName = nullptr;
    pDb->getFilename(pFileName);

    AcString path(pFileName);
    int n = path.findRev(_T('\\'));
    if (n >= 0)
        path = path.mid(0, n + 1);
    else
    {
        n = path.findRev(_T('/'));
        if (n >= 0)
            path = path.mid(0, n + 1);
    }
    return path;
}

static AcString validBlockName(const AcString& name)
{
    AcString validName(name);
    int n = -1;
    while ((n = validName.find('|')) >= 0)
    {
        validName = validName.mid(0, n) + AcString(_T("_")) + validName.mid(n + 1, validName.length() - n - 1);
    }
    return validName;
}

static bool saveBitmapToFile(const AcDbBlockTableRecord::PreviewIcon& previewIcon, const AcString& fileName)
{
    bool ret = false;
    const BITMAPINFO* pBitmapInfo = reinterpret_cast<const BITMAPINFO*>(previewIcon.asArrayPtr());
    if (pBitmapInfo)
    {
        BITMAPFILEHEADER bmpFileHdr;
        bmpFileHdr.bfType = 0x4d42;        // 0x42 = 'B' 0x4d = 'M'
        bmpFileHdr.bfReserved1 = bmpFileHdr.bfReserved2 = 0;

        // offset into the bmp file to the array of color indices
        bmpFileHdr.bfOffBits = (DWORD) sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) +
            pBitmapInfo->bmiHeader.biClrUsed * sizeof(RGBQUAD);

        // bmp file size
        bmpFileHdr.bfSize = bmpFileHdr.bfOffBits + pBitmapInfo->bmiHeader.biSizeImage;

        FILE* pBmpFile = _wfopen(fileName.constPtr(), L"w");
        if (pBmpFile)
        {
            // Add the BITMAPFILEHEADER to the .BMP file
            fwrite(&bmpFileHdr, 1, sizeof(BITMAPFILEHEADER), pBmpFile);

            assert(previewIcon.length() == sizeof(BITMAPINFOHEADER) +
                pBitmapInfo->bmiHeader.biClrUsed * sizeof(RGBQUAD) +
                pBitmapInfo->bmiHeader.biSizeImage);

            // Add the BITMAPINFOHEADER, RGBQUAD array and bitmap to the .BMP file
            fwrite(previewIcon.asArrayPtr(), 1, previewIcon.length(), pBmpFile);
            fclose(pBmpFile);
        }
        else
        {
            acutPrintf(_T("\nFile was not created: \"%ls\""), fileName.constPtr());
        }
    }
    return ret;
}

void cmdGetBlockPreviewIcon()
{
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    const AcString path = getPath(pDb);
    //acutPrintf(_T("\npath=\"%ls\""), path.constPtr());

    AcDbBlockTable* blkTbl = nullptr;
    if (pDb->getSymbolTable(blkTbl, AcDb::kForRead) != Acad::eOk)
        return;
    
    AcDbBlockTableIterator* tblIter = nullptr;
    if (blkTbl->newIterator(tblIter) != Acad::eOk)
    {
        blkTbl->close();
        return;
    }

    int nHasIcon = 0, nBlocks = 0;
    for (; !tblIter->done(); tblIter->step()) 
    {
        AcDbBlockTableRecord* pBlockRec = nullptr;
        if (tblIter->getRecord(pBlockRec, AcDb::kForRead) == Acad::eOk)
        {
            if (!pBlockRec->isLayout() && !pBlockRec->isAnonymous())
            {
                nBlocks++;

                AcString name;
                pBlockRec->getName(name);
                const AcString validName = validBlockName(name); //name has '|' when pBlockRec->isFromExternalReference()

                AcDbBlockTableRecord::PreviewIcon previewIcon;
                if (pBlockRec->hasPreviewIcon() && pBlockRec->getPreviewIcon(previewIcon) == Acad::eOk)
                {
                    //const BITMAPINFO* pBitmapInfo = reinterpret_cast<const BITMAPINFO*>(previewIcon.asArrayPtr());
 
                    if(!path.isEmpty())
                        saveBitmapToFile(previewIcon, path + validName + _T(".bmp"));

                    nHasIcon++;
                    acutPrintf(_T("\nBlock \"%ls\" has preview icon"), name.constPtr());
                }
                else
                {
                    acutPrintf(_T("\nBlock \"%ls\" has not preview icon"), name.constPtr());
                }
            }
            pBlockRec->close();
        }
    }
    delete tblIter;
    blkTbl->close();

    acutPrintf(_T("\n%d blocks from %d have preview icons"), nHasIcon, nBlocks);
    if (nHasIcon > 0)
        acutPrintf(_T("\nBitmaps were created in folder: %ls"), path.constPtr());
}
