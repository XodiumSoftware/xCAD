// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"

#include "civil_alignment_sample.h"
#include "civil_civil3dconverter_sample.h"
#include "civil_gis_sample.h"
#include "civil_grading_sample.h"
#include "civil_point_sample.h"
#include "civil_surface_sample.h"

class BrxCivilSample: public AcRxArxApp
{
public:
    BrxCivilSample(): AcRxArxApp() {}

    virtual void RegisterServerComponents()
    {
    }

    virtual AcRx::AppRetCode On_kInitAppMsg(void* pAppData)
    {
        AcRx::AppRetCode result = AcRxArxApp::On_kInitAppMsg(pAppData);

        acrxRegisterAppMDIAware(pAppData); // is able to work in MDI context
        acrxUnlockApplication(pAppData);   // allows to unload the module during session

        return result;
    }

    virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pAppData)
    {
        return AcRxArxApp::On_kUnloadAppMsg(pAppData);
    }

    virtual AcRx::AppRetCode On_kLoadDwgMsg(void* pAppData)
    {
        return AcRxArxApp::On_kLoadDwgMsg(pAppData);
    }

    virtual AcRx::AppRetCode On_kUnloadDwgMsg(void* pAppData)
    {
        return AcRxArxApp::On_kUnloadDwgMsg(pAppData);
    }

    virtual AcRx::AppRetCode On_kQuitMsg(void* pAppData)
    {
        return AcRxArxApp::On_kQuitMsg(pAppData);
    }


    //------------------------------------------------------------------------
    //Surface commands
    //------------------------------------------------------------------------
    static void BrxCivilSample_Surface_Create(void)
    {
        cmdCivilCreateSurface();
    }

    static void BrxCivilSample_Surface_List(void)
    {
        cmdCivilSurfaceList();
    }

    static void BrxCivilSample_Surface_ListAllSurfaces(void)
    {
        cmdCivilListAllSurfaces();
    }


    static void BrxCivilSample_Surface_AddBreakline(void)
    {
        cmdCivilAddBreakline();
    }

    static void BrxCivilSample_Surface_AddBoundary(void)
    {
        cmdCivilAddBoundary();
    }

    static void BrxCivilSample_Surface_AddDBRBreaklines(void)
    {
        cmdCivilAddBreaklineDBRO();
    }

    static void BrxCivilSample_Surface_AddDBRBoundaries(void)
    {
        cmdCivilAddBoundaryDBRO();
    }

    static void BrxCivilSample_Surface_RemoveBreakline(void)
    {
        cmdCivilRemoveBreakline();
    }

    static void BrxCivilSample_Surface_RemoveBoundary(void)
    {
        cmdCivilRemoveBoundary();
    }

    static void BrxCivilSample_Surface_ChangeStyle(void)
    {
        cmdCivilChangeStyle();
    }

    static void BrxCivilSample_Surface_MapElevation(void)
    {
        cmdCivilSurfaceMapElevations();
    }

    static void BrxCivilSample_Surface_MapSlope(void)
    {
        cmdCivilSurfaceMapSlope();
    }

    static void BrxCivilSample_Surface_Merge(void)
    {
        cmdCivilSurfaceMerge();
    }

    static void BrxCivilSample_Surface_Mesh(void)
    {
        cmdCivilSurfaceMesh();
    }

    static void BrxCivilSample_Surface_Drape(void)
    {
        cmdCivilSurfaceDrape();
    }

    static void BrxCivilSample_Surface_Jig(void)
    {
        cmdCivilSurfaceJig();
    }

    //------------------------------------------------------------------------
    //Volume surface commands
    //------------------------------------------------------------------------

    static void BrxCivilSample_VolumeSurface_Create(void)
    {
        cmdCivilVolumeSurfaceCreate();
    }

    static void BrxCivilSample_VolumeSurface_CreateElev(void)
    {
        cmdCivilVolumeSurfaceCreateElev();
    }

    static void BrxCivilSample_VolumeSurface_Bounded(void)
    {
        cmdCivilVolumeSurfaceBounded();
    }

    //------------------------------------------------------------------------
    //Grading commands
    //------------------------------------------------------------------------
    static void BrxCivilSample_Grading_CreateSlopeOffset(void)
    {
        cmdCivilCreateGradingSlopeOffset();
    }

    static void BrxCivilSample_Grading_CreateSlopeSurface(void)
    {
        cmdCivilCreateGradingSlopeSurface();
    }

    static void BrxCivilSample_Grading_TestParams(void)
    {
        cmdCivilGradingParams();
    }

    static void BrxCivilSample_Grading_SetRegion(void)
    {
        cmdCivilGradingSetRegion();
    }

    //------------------------------------------------------------------------
    //Converter commands
    //------------------------------------------------------------------------

    static void BrxCivilSample_ConvertAllEntities(void)
    {
        cmdCivil3DConvertAll();
    }

    //------------------------------------------------------------------------
    //Alignment commands
    //------------------------------------------------------------------------

    static void BrxCivilSample_Alignment_Create(void)
    {
        cmdCivilCreateAlignment();
    }

    static void BrxCivilSample_Alignment_Create_FromPolyline(void)
    {
        cmdCivilCreateAlignmentFromPolyline();
    }

    static void BrxCivilSample_Alignment_Replace_Element(void)
    {
        cmdCivilReplaceAlignmentElement();
    }

    static void BrxCivilSample_Alignment_Annotate(void)
    {
        cmdCivilAnnotateAlignment();
    }

    static void BrxCivilSample_Alignment_Stations_And_Param_Relations(void)
    {
        cmdCivilStationsAndParamRelations();
    }

    static void BrxCivilSample_Alignment_Station_Equations(void)
    {
        cmdCivilStationEquations();
    }

    static void BrxCivilSample_Alignment_Jig(void)
    {
        cmdCivilAlignmentJig();
    }

    static void BrxCivilSample_Gis_Workflow(void)
    {
        cmdCivilGisWorkflow();
    }

    static void BrxCivilSample_Points_Workflow(void)
    {
        cmdCivilPointsWorkflow();
    }
};

IMPLEMENT_ARX_ENTRYPOINT(BrxCivilSample)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_List,             Sample_Surface_List,                  ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_ListAllSurfaces,  Sample_Surface_ListAllSurfaces,       ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_Create,           Sample_Surface_Create,                ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_AddBreakline,     Sample_Surface_AddBreakline,          ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_AddBoundary,      Sample_Surface_AddBoundary,           ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_AddDBRBreaklines, Sample_Surface_AddDBRBreaklines,      ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_AddDBRBoundaries, Sample_Surface_AddDBRBoundaries,      ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_RemoveBreakline,  Sample_Surface_RemoveBreakline,       ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_RemoveBoundary,   Sample_Surface_RemoveBoundary,        ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_ChangeStyle,      Sample_Surface_ChangeStyle,           ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_MapElevation,     Sample_Surface_MapElevation,          ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_MapSlope,         Sample_Surface_MapSlope,              ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_Merge,            Sample_Surface_Merge,                 ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_Mesh,             Sample_Surface_Mesh,                  ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_Drape,            Sample_Surface_Drape,                 ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Surface_Jig,              Sample_Surface_Jig,                   ACRX_CMD_TRANSPARENT | ACRX_CMD_NOPAPERSPACE, NULL)
                                                                                                                            
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_VolumeSurface_Create,     Sample_VolumeSurface_Create,          ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_VolumeSurface_CreateElev, Sample_VolumeSurface_CreateElev,      ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_VolumeSurface_Bounded,    Sample_VolumeSurface_Bounded,         ACRX_CMD_TRANSPARENT, NULL)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Grading_CreateSlopeOffset,  Sample_Grading_CreateSlopeOffset,   ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Grading_CreateSlopeSurface, Sample_Grading_CreateSlopeSurface,  ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Grading_TestParams,         Sample_Grading_TestParams,          ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Grading_SetRegion,          Sample_Grading_SetRegion,           ACRX_CMD_TRANSPARENT, NULL)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_ConvertAllEntities, Sample_ConvertAllEntities, ACRX_CMD_TRANSPARENT, NULL)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Alignment_Create, Sample_Alignment_Create, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Alignment_Create_FromPolyline, Sample_Alignment_Create_FromPolyline, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Alignment_Replace_Element, Sample_Alignment_Replace_Element, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Alignment_Annotate, Sample_Alignment_Annotate, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Alignment_Stations_And_Param_Relations, Sample_Alignment_Stations_And_Param_Relations, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Alignment_Station_Equations, Sample_Alignment_Station_Equations, ACRX_CMD_TRANSPARENT, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Alignment_Jig, Sample_Alignment_Jig, ACRX_CMD_TRANSPARENT, NULL)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Gis_Workflow, Sample_Gis_Workflow, ACRX_CMD_TRANSPARENT, NULL)

ACED_ARXCOMMAND_ENTRY_AUTO(BrxCivilSample, BrxCivil, Sample_Points_Workflow, Sample_Points_Workflow, ACRX_CMD_TRANSPARENT, NULL)
