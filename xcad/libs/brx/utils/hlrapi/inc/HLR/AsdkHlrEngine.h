// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////
#pragma once

#include "HlrGlobal.h"

// begin BRX specific : since V17.1.x
struct HlrProcessingOptions
{
    HlrProcessingOptions(double minRes = 0.001,
                         double occludedEdgeResolution = 0.02,
                         double smoothFaceAngleTol = 1.0)
        : m_minResolution(minRes)
        , m_occludedEdgeResolution(occludedEdgeResolution)
        , m_smoothFaceAngleTolerance(smoothFaceAngleTol)
    {
    };

    // smallest useful unit used by HLR, default is 0.001; smallest accepted value is 1e-05;
    // negative value means 'factory default'
    double m_minResolution;

    // resolution to determine if two lines are occluding each other, default is 0.02;
    // negative value means 'factory default'
    double m_occludedEdgeResolution;

    // the maximum angle at which two connected faces are still considered tangentially smooth;
    // input the cosine of angle between faces (suggested 10 deg. = 0.98)
    // default is "disabled face smoothing"
    // negative value means 'factory default' (1.0)
    double m_smoothFaceAngleTolerance;
};
// end BRX specific

class HLR_IMPORTEXPORT AsdkHlrEngine
{
protected:
    AcDbViewport* mpViewport; // the viewport for HLR process; defines target, camera, view direction etc.
    int mnControl;            // processing flags, see AsdkHlrControl enum
    _AbortCallbackFct mpAbortCallbackFct;
    _ProgressCallbackFct mpAcadConvertionProgressCallbackFct;
    _ProgressCallbackFct mpAcisConvertionProgressCallbackFct;
    _ProgressCallbackFct mpAhlProgressCallbackFct;

public:
    AsdkHlrEngine(int = kBlock|kEntity|kReuse|kShowAll|kSubentity);
    AsdkHlrEngine(AcDbObjectId,int = kBlock|kEntity|kReuse|kShowAll|kSubentity);
    AsdkHlrEngine(AcDbViewport*,int = kBlock|kEntity|kReuse|kShowAll|kSubentity);
    AsdkHlrEngine(AcGePoint3d&,AcGeVector3d&,int = kBlock|kEntity|kReuse|kShowAll|kSubentity);

    virtual ~AsdkHlrEngine();

    Acad::ErrorStatus run(AsdkHlrCollector&);

    // sets the abort and processing callback functions (for monitoring, progress bar, and similar client)
    void setAbortCallback(_AbortCallbackFct);
    void setAcadConversionProgressCallBack(_ProgressCallbackFct);
    void setAcisConversionProgressCallBack(_ProgressCallbackFct);
    void setAhlProgressCallBack(_ProgressCallbackFct);

    // clears the viewport-specific or single HLR cache (actually unused)
    static void cleanHlrCache();
    static void cleanHlrCache(AcDbEntity*,AcDbViewport* = NULL);
    static void cleanHlrCache(AcDbEntity*,AcGePoint3d,AcGeVector3d);

    // BRX specific : since V17.1.x
    // allows fine-tuning of HLR processing
    // note 1 : assigning a 'HlrProcessingOptions*' affects *ONLY* next 'run()' call !
    // note 2 : applying the 3 values can affect performance, memory consumption + precision
    //          in positive and negative sense !
    void setHlrProcessingOptions(const HlrProcessingOptions* options = NULL);
};
