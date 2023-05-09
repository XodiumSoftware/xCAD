// Copyright (C) 2017-2018 Menhirs NV. All rights reserved.
#pragma once

#include "Atil/Defs.h"
#include "Atil/ImageReactorInterface.h"
#include "Atil/ImagePixel.h"
#include "Atil/ImageContext.h"
#include "Atil/DataModel.h"
#include "Atil/Size.h"


namespace Atil
{;


class RowProviderInterface;
class FileReadDescriptor;
class ImageContext;
class ImageRep;
class Internal;

class ATIL_IMPORTEXPORT Image
{
public:
    Image();
    Image(const Image&);
    Image(const Size&, const DataModel*, ImagePixel, DataModel::TileSize = DataModel::kUnspecified);
    Image(void*, int, int, const Size&, const DataModel*);
    Image(RowProviderInterface*, DataModel::TileSize = DataModel::kUnspecified);
    Image(RowProviderInterface*, Atil::Orientation, DataModel::TileSize = DataModel::kUnspecified);
    Image(FileReadDescriptor&, DataModel::TileSize = DataModel::kUnspecified);
    ~Image();

    const Image& operator= (const Image&);
    const Image& operator= (RowProviderInterface*);

    bool operator== (const Image&) const;
    bool operator!= (const Image&) const;

    void addReactor(ImageReactorInterface*);
    void blend(RowProviderInterface*, const Offset&, int, bool = false);
    void clear();
    const ImagePixel& clearColor() const;
    ImageContext* createContext(ImageContext::Access, int = 4);
    ImageContext* createContext(ImageContext::Access, const Size&, const Offset&, int = 4);
    const DataModel& dataModel() const;
    bool disablePerTileLocking(bool);
    const FileReadDescriptor* fileReadDescriptor() const;
    void* getUserBuffer() { return nullptr; }
    bool isModified() const { return false; }
    bool isValid() const;
    int numTiles(int&, int&) const;
    void paste(RowProviderInterface*, const Offset&, bool = false);
    RowProviderInterface* read(const Size&, const Offset&) const;
    RowProviderInterface* read(const Size&, const Offset&, Atil::Orientation) const;
    void removeReactor(ImageReactorInterface*);
    void setClearColor(ImagePixel);
    void setDataModel(const DataModel&);
    const Size& size() const;
    Size tileSize() const;
    bool usesUserBuffer() const { return false; }

private:
    friend Internal;
    Image(ImageRep*);
    ImageRep* m_pImp;
};


} //namespace Atil
