// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "AcDb/AcDbObject.h"
#include "AcGi/AcGiRequestScanLines.h"
#include "AcGi/AcGiSentScanLines.h"

class IAcReadStream;

/** _ */
class BRX_EXPORT AcDbRasterImageDef: public AcDbObject
{
public:
    enum
    {
        kMaxSuggestNameSize = 2049
    };

    enum Units
    {
        kNone = 0,
        kMillimeter,
        kCentimeter,
        kMeter,
        kKilometer,
        kInch,
        kFoot,
        kYard,
        kMile,
        kMicroinches,
        kMils,
        kAngstroms,
        kNanometers,
        kMicrons,
        kDecimeters,
        kDekameters,
        kHectometers,
        kGigameters,
        kAstronomical,
        kLightYears,
        kParsecs
    };

    ACRX_DECLARE_MEMBERS(AcDbRasterImageDef);

    AcDbRasterImageDef();
    virtual ~AcDbRasterImageDef();

    virtual Acad::ErrorStatus closeImage();
    virtual Acad::ErrorStatus dwgInFields(AcDbDwgFiler*);
    virtual Acad::ErrorStatus dwgOutFields(AcDbDwgFiler*) const;
    virtual Acad::ErrorStatus dxfInFields(AcDbDxfFiler*);
    virtual Acad::ErrorStatus dxfOutFields(AcDbDxfFiler*) const;
    virtual Acad::ErrorStatus embed();
    virtual Acad::ErrorStatus load();
    virtual Acad::ErrorStatus loadThumbnail(Adesk::UInt16&,Adesk::UInt16&,Adesk::UInt8* = NULL,int = 0);
    virtual Acad::ErrorStatus openImage(Atil::Image*&);
    virtual Acad::ErrorStatus setActiveFileName(const ACHAR*);
    virtual Acad::ErrorStatus setImage(const Atil::Image*,const Atil::FileReadDescriptor*,Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus setImageModified(Adesk::Boolean);
    virtual Acad::ErrorStatus setResolutionMMPerPixel(const AcGeVector2d&);
    virtual Acad::ErrorStatus setSourceFileName(const ACHAR*);
    virtual Acad::ErrorStatus setUndoStoreSize(unsigned int = 10);
    virtual Acad::ErrorStatus subClose();
    virtual Acad::ErrorStatus subErase(Adesk::Boolean);
    virtual Acad::ErrorStatus unload(Adesk::Boolean = Adesk::kTrue);
    virtual Acad::ErrorStatus unloadThumbnail();
    virtual AcGeVector2d resolutionMMPerPixel() const;
    virtual AcGeVector2d size() const;
    virtual AcGiImageOrg organization() const;
    virtual AcGiSentScanLines* makeScanLines(const AcGiRequestScanLines*,const AcGeMatrix2d&,AcGePoint2dArray* = NULL,Adesk::Boolean = Adesk::kFalse,Adesk::Boolean = Adesk::kFalse,const double = 50.0,const double = 50.0,const double = 0.0) const;
    virtual Adesk::Boolean imageModified() const;
    virtual Adesk::Boolean isEmbedded() const;
    virtual Adesk::Boolean isLoaded() const;
    virtual Atil::FileReadDescriptor* fileDescCopy() const;
    virtual Atil::Image* imageCopy(Adesk::Boolean = Adesk::kTrue) const;
    virtual const ACHAR* activeFileName() const;
    virtual const ACHAR* fileType() const;
    virtual const ACHAR* searchForActivePath();
    virtual const ACHAR* sourceFileName() const;
    virtual int colorDepth() const;
    virtual int entityCount(Adesk::Boolean* = NULL) const;
    virtual Units resolutionUnits() const;
    virtual unsigned int undoStoreSize() const;
    virtual void setResolutionUnits(Units);
    virtual void updateEntities() const;
    virtual void* createThumbnailBitmap(BITMAPINFO*&,Adesk::UInt8 = 50,Adesk::UInt8 = 50,Adesk::UInt8 = 0);
    virtual IAcReadStream* getReadStream();

    static Acad::ErrorStatus createImageDictionary(AcDbDatabase*,AcDbObjectId&);
    static Acad::ErrorStatus suggestName(AcDbDictionary*,const ACHAR*,ACHAR*); //deprecated
    static Acad::ErrorStatus suggestName(AcDbDictionary*, const ACHAR*, ACHAR*, size_t);
    static AcDbObjectId imageDictionary(AcDbDatabase*);
    static ClassVersion classVersion();
};
