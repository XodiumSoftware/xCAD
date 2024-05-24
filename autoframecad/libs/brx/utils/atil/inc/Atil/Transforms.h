// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "Atil/Defs.h"
#include "Atil/ImagePixel.h"
#include "Atil/BoundingBox.h"
#include "Atil/Point2d.h"
#include "Atil/Vector2d.h"
#include "Atil/Size.h"


namespace Atil
{;

class RowProviderInterface;
class Image;
class Offset;


struct Resample
{
    enum FilterTypes
    {
        kNearest = 0,
        kTriangle = 1,
        kCubic = 2,
        kBell = 3,
        kBSpline = 4,
        kLanczos3 = 5,
        kMitchell = 6,
        kBellBinary = 7
    };
};

struct Shear
{
    enum Quality
    {
        kInterpolate = 0,
        kRound = 1
    };
};

class ATIL_IMPORTEXPORT ImageView
{
public:
    enum RotationMethod
    {
        kInterpolated = 0,
        kNearestNeighbor = 1
    };

public:
    ImageView(const Image&, const Size&);
    ImageView(const Size&, ImagePixel, const Size&);
    ~ImageView();
    ImagePixel fillColor() const { return m_fillcolor; }
    bool getInputandOrientation(Offset&, Size&, Atil::Orientation&) const;
    Matrix2d getTransformation() const;
    RowProviderInterface* getViewedImageData(ImagePixel, Resample::FilterTypes = Resample::kNearest, bool = false, RotationMethod = kInterpolated);
    RowProviderInterface* getViewedImageData(Resample::FilterTypes = Resample::kNearest, bool = false, RotationMethod = kInterpolated);
    RowProviderInterface* getViewedImageData(RowProviderInterface*, Resample::FilterTypes = Resample::kNearest, bool = false, RotationMethod = kInterpolated);
    RowProviderInterface* getViewedImageData(RowProviderInterface*, ImagePixel, Resample::FilterTypes = Resample::kNearest, bool = false, RotationMethod = kInterpolated);
    bool imageInView(Size&, Offset&);
    void moveBy(const double&, const double&);
    void moveTo(const Point2d&);
    Point2d origin() const { return m_origin; }
    const Size& output() const { return m_outsize; }
    bool returnRawData() const { return m_rawdata; }
    void rotateBy(const double&);
    void rotateBy(int);
    double rotation() const;
    void scaleBy(const double&);
    void setByVectors(const Point2d&, const Vector2d&, const Vector2d&);
    void setFillColor(ImagePixel);
    void setRegionOfInterest(const Size&, const Offset&);
    void setReturnRawData(bool);
    void setRotation(const double&);
    void setRotation(int);
    void setSize(const double& w, const double& h);
    void setTransparency(bool v) { m_transparency = v; }
    Point2d transform(Point2d) const;
    bool transparency() const { return m_transparency; }
    Vector2d xAxis() const { return m_xaxis; }
    Vector2d yAxis() const { return m_yaxis; }

private:
    RowProviderInterface* getViewedImageDataImp(const ImagePixel*, Resample::FilterTypes, bool, RotationMethod);
    RowProviderInterface* getViewedImageDataImp(RowProviderInterface*, const ImagePixel*, Resample::FilterTypes, bool, RotationMethod);

    BoundingBox m_bbox;
    const Image* m_image;
    ImagePixel m_fillcolor;
    Point2d m_origin;
    Vector2d m_xaxis;
    Vector2d m_yaxis;

    Size m_imgsize;
    Size m_outsize;
    bool m_usingfillcolor;
    bool m_transparency;
    bool m_rawdata;
};

ATIL_IMPORTEXPORT RowProviderInterface* applyAffine(const Image*, const Size&, const Point2d&, const Vector2d&, const Vector2d&, bool);
ATIL_IMPORTEXPORT bool bufferedImageBottomUpPaste(Image*, RowProviderInterface*, const Offset&, bool = false);
ATIL_IMPORTEXPORT RowProviderInterface* newResampleFilter(const Image*, const Size&, const Offset&, Resample::FilterTypes, bool, bool, const Size&);
ATIL_IMPORTEXPORT RowProviderInterface* newResampleFilter(RowProviderInterface*, const Size&, Resample::FilterTypes, bool = false, bool = false, bool = false, ImagePixel const* = NULL);
ATIL_IMPORTEXPORT RowProviderInterface* newRotateFilter(RowProviderInterface*, const double&, ImagePixel, Shear::Quality, bool = false, bool = false);
ATIL_IMPORTEXPORT RowProviderInterface* newScaleFilter(RowProviderInterface*, const Size&);
ATIL_IMPORTEXPORT RowProviderInterface* newScaleFilter(const Image*, const Size&);
ATIL_IMPORTEXPORT RowProviderInterface* newScaleFilter(const Image*, const Size&, const Offset&, const Size&);
ATIL_IMPORTEXPORT RowProviderInterface* newXShearFilter(RowProviderInterface*, const double&, ImagePixel, Shear::Quality, bool = false, bool = false);
ATIL_IMPORTEXPORT RowProviderInterface* newYShearFilter(RowProviderInterface*, const double&, ImagePixel, Shear::Quality, bool = false, bool = false);


} //namespace Atil
