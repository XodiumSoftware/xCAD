// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"

#include "civil_grading_sample.h"
#include "civil_utils.h"

#include "BrxSpecific/civil/AcDbCivilTinSurface.h"

static AcDbPolyline* createSamplePolyline(const AcGePoint2dArray* points,
                                          const AcGeDoubleArray* bulges,
                                          const double elevation,
                                          const bool closed,
                                          const bool reverseCurve)
{
    AcDbPolyline* pPolyline = new AcDbPolyline;

    pPolyline->setElevation(elevation);

    if (points)
    {

        for (int i = 0; i < points->length(); ++i)
        {
            double bulge = 0.0;
            if (bulges && i < bulges->length())
                bulge = bulges->at(i);
            pPolyline->addVertexAt(pPolyline->numVerts(), points->at(i), bulge);
        }
    }
    else
    {
        pPolyline->addVertexAt(0, AcGePoint2d(-5, -20));
        pPolyline->addVertexAt(1, AcGePoint2d(5, -20), 1);
        pPolyline->addVertexAt(2, AcGePoint2d(5, 20));
        pPolyline->addVertexAt(3, AcGePoint2d(-5, 20));
    }

    pPolyline->setClosed(closed);

    if (reverseCurve)
        pPolyline->reverseCurve();

    return pPolyline;
}

static AcDb3dPolyline* create3dPolyline(const AcGePoint3dArray* points,
                                        const bool closed,
                                        const bool reverseCurve)
{
    AcDb3dPolyline* pPolyline = new AcDb3dPolyline;

    if (points)
    {
        for (const AcGePoint3d& point : *points)
        {
            pPolyline->appendVertex(new AcDb3dPolylineVertex(point));
        }
    }
    else
    {
        pPolyline->appendVertex(new AcDb3dPolylineVertex(AcGePoint3d(-5, -20, 1)));
        pPolyline->appendVertex(new AcDb3dPolylineVertex(AcGePoint3d(5, -20, 1)));
        pPolyline->appendVertex(new AcDb3dPolylineVertex(AcGePoint3d(5, 20, 1)));
        pPolyline->appendVertex(new AcDb3dPolylineVertex(AcGePoint3d(-5, 20, 1)));
    }

    pPolyline->setClosed(closed);

    if (reverseCurve)
        pPolyline->reverseCurve();


    return pPolyline;
}


void echoErrorStatus(const ETinGradingStatus es)
{
    acutPrintf(L"Error code: %d", es);
}

void cmdCivilCreateGradingSlopeOffset()
{
    auto rawPolyline = create3dPolyline(nullptr, false, true);
    AcDbObjectPointer<AcDb3dPolyline> pInputCurve; pInputCurve.acquire(rawPolyline);
    AcDbObjectId inputCurveId;
    addEntityToModelSpace(pInputCurve, inputCurveId, false);

    AcDbObjectPointer<AcDbCivilTinGrading> pGrading; pGrading.create();
    /*
        Set the (input) grading curve from which the rays are calculated based on 
        grading type, slope angles and other grading parameters.
    */
    ETinGradingStatus status = pGrading->setInputData(inputCurveId);

    if (!(status & ETinGradingStatus::eGradingOk))
    {
        acutPrintf(L"Set grading curve is invalid.\n");
    }

    /*
        Create a TinSlopeOffsetRule which is defined by an angle/slope (at which
        the rays are fired) and the offset from the grading curve.

        Default slope format is in radians. Positive angle values specify positive
        change in Z direction (meaning rays are fired upwards from given grading
        curve) and opposite for negative values.

        Valid range for slope in TinSlopeOffsetRule is (-Pi/2, 0] and [0, Pi/2).
        The offset must be  greater than 0. 
    */
    TinSlopeOffsetRule rule(degToRad(45.0), 1);

    /*
        The setSide function specifies on which side of the grading
        curve, the rays should be projected. Reversing the direction of the curve
        changes (visually) the side of the grading.
    */
    rule.setSide(ETinGradingSide::eGradingSideRight);
    
    /*
        Apply the created rule to the grading entity.
    */
    status = pGrading->setRule(rule);

    if (!(status & ETinGradingStatus::eGradingOk))
    {
        acutPrintf(L"Set rule is invalid.\n");
    }

    /*
        Similar to the AcDbCivilTinSurface, the AcDbCivilTinGrading is also
        automatically updated when pGrading->close() is called.
        In order to the trigger the calculation and get the result of the 
        update you can also call pGrading->update().
    */
    AcDbObjectId gradingId;
    addEntityToModelSpace(pGrading, gradingId, false);
}

void cmdCivilCreateGradingSlopeSurface()
{
    AcDbObjectId surfaceId;
    auto rawSurface = createSampleTinSurface();
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface; pSurface.acquire(rawSurface);
    addEntityToModelSpace(pSurface, surfaceId, false);

    auto rawPolyline = create3dPolyline(nullptr, false, true);
    AcDbObjectPointer<AcDb3dPolyline> pInputCurve; pInputCurve.acquire(rawPolyline);
    AcDbObjectId inputCurveId;
    addEntityToModelSpace(pInputCurve, inputCurveId, false);

    AcDbObjectPointer<AcDbCivilTinGrading> pGrading; pGrading.create();
    /*
        Set the (input) grading curve from which the rays are calculated based on
        grading type, slope angles and other grading parameters.
    */
    ETinGradingStatus status = pGrading->setInputData(inputCurveId);

    if (!(status & ETinGradingStatus::eGradingOk))
    {
        acutPrintf(L"Set grading curve is invalid.\n");
    }

    /*
        Create a TinSlopeSurfaceRule which is defined by a given target
        surface (on which the rays are projected), cutSlope (used when
        the given grading curve is below the target surface) and fillSlope
        (used when the given grading curve is above the target surface).
        
        Given AcDbObjectId can be any (isKindOf) AcDbCivilTinSurface
        (that includes AcDbCivilTinGrading).
        Default slope format is in radians.
        Valid range for both slopes is [0, Pi/2).
    */
    const double cutSlope = degToRad(77.0);
    const double fillSlope = degToRad(33.0);
    TinSlopeSurfaceRule rule(surfaceId, cutSlope, fillSlope);
    rule.setSide(ETinGradingSide::eGradingSideRight);
    
    status = pGrading->setRule(rule);

    if (!(status & ETinGradingStatus::eGradingOk))
    {
        acutPrintf(L"Set grading rule is invalid.\n");
    }

    /*
        Similar to the AcDbCivilTinSurface, the AcDbCivilTinGrading is also
        automatically updated when pGrading->close() is called.
        In order to the trigger the calculation and get result immediately,
        you can also call pGrading->update().
    */
    status = pGrading->update();

    if (!(status & ETinGradingStatus::eGradingOk))
    {
        acutPrintf(L"Grading calculation failed.\n");
    }

    AcDbObjectId gradingId;
    addEntityToModelSpace(pGrading, gradingId, false);
}


static void initEntitiesGradingParams(AcDbObjectId& straightLineId,
                                      AcDbObjectId& rightAngleLineId, 
                                      AcDbObjectId& lineWithArc,
                                      AcDbObjectId& surfaceId)
{
    //straightLineId
    {
        AcGePoint2dArray points;
        points.append(AcGePoint2d(0, 0));
        points.append(AcGePoint2d(0, 10));
        auto rawPolyline = createSamplePolyline(&points, nullptr, 1.0, false, true);
        AcDbObjectPointer<AcDbPolyline> pPolyline; pPolyline.acquire(rawPolyline);
        addEntityToModelSpace(pPolyline, straightLineId, false);
    }
    //rightAngleLineId
    {
        AcGePoint2dArray points;
        points.append(AcGePoint2d(0, 0));
        points.append(AcGePoint2d(5, 0));
        points.append(AcGePoint2d(5, 10));
        auto rawPolyline = createSamplePolyline(&points, nullptr, 1.0, false, true);
        AcDbObjectPointer<AcDbPolyline> pPolyline; pPolyline.acquire(rawPolyline);
        addEntityToModelSpace(pPolyline, rightAngleLineId, false);
    }
    //lineWithArc
    {
        AcGePoint2dArray points;
        points.append(AcGePoint2d(0, 0));
        points.append(AcGePoint2d(0, 5));
        points.append(AcGePoint2d(0, 10));
        points.append(AcGePoint2d(0, 15));

        AcGeDoubleArray bulges;
        bulges.append(0.0);
        bulges.append(1.0);
        bulges.append(-1.0);
        bulges.append(0.0);
        auto rawPolyline = createSamplePolyline(&points, &bulges, 1.0, false, true);
        AcDbObjectPointer<AcDbPolyline> pPolyline; pPolyline.acquire(rawPolyline);
        addEntityToModelSpace(pPolyline, lineWithArc, false);
    }
    //surfaceId
    {
        auto rawSurface = createSampleTinSurface();
        AcDbObjectPointer<AcDbCivilTinSurface> pSurface; pSurface.acquire(rawSurface);
        addEntityToModelSpace(pSurface, surfaceId, false);
    }
}

void cmdCivilGradingParams()
{
    AcDbObjectId straightLineId;
    AcDbObjectId rightAngleLineId;
    AcDbObjectId lineWithArc;
    AcDbObjectId surfaceId;

    initEntitiesGradingParams(straightLineId, rightAngleLineId, lineWithArc, surfaceId);

    AcDbObjectPointer<AcDbCivilTinGrading> pGrading1; pGrading1.create();
    AcDbObjectPointer<AcDbCivilTinGrading> pGrading2; pGrading2.create();
    AcDbObjectPointer<AcDbCivilTinGrading> pGrading3; pGrading3.create();
    {
        double segMaxLen = 2;
        acedGetReal(L"Enter segMaxLen distance: ", &segMaxLen);

        /*
            Straight segments are split into multiple pieces to create
            smoother surfaces. The following parameter sets the maximal
            length of each piece (a ray is projected at each piece).
        */
        pGrading1->setSegmentMaxLength(segMaxLen);
    }

    {
        double segMaxAngle = 30.0;
        acedGetReal(L"Enter segMaxAngle(deg): " , &segMaxAngle);
        segMaxAngle = degToRad(segMaxAngle);

        /*
            When grading to the surface at an obtuse-angled vertex (e.g.
            if you have a triangle shaped polyline and the grading is calculated
            on the outside of the triangle, all the vertices used are
            obtuse-angled) multiple rays are projected from the same vertex
            at different angled to improve the surface smoothnes. 

            setSegmentMaxAngle function controls the max angle between each
            projected ray at such vertices.
        */
        pGrading2->setSegmentMaxAngle(segMaxAngle);
    }

    {
        double midOrdinateDist = 10;
        acedGetReal(L"Enter midOrdinateDist: ", &midOrdinateDist);

        /*
            If the entity/curve used to create the grading contains arcs,
            then setMidOrdinateDist controls the maximal distance between the
            actual arc and the tessellated one (used by grading entity).
        */
        pGrading3->setMidOrdinateDist(midOrdinateDist);
    }

    pGrading1->setInputData(straightLineId);
    pGrading2->setInputData(rightAngleLineId);
    pGrading3->setInputData(lineWithArc);

    const double cutSlope = M_PI_4;
    const double fillSlope = M_PI_4;
    TinSlopeSurfaceRule rule(surfaceId, cutSlope, fillSlope);
    rule.setSide(ETinGradingSide::eGradingSideLeft);
    pGrading1->setRule(rule);
    pGrading2->setRule(rule);
    pGrading3->setRule(rule);
    
    AcDbObjectId gradingId;
    addEntityToModelSpace(pGrading1, gradingId, false);
    addEntityToModelSpace(pGrading2, gradingId, false);
    addEntityToModelSpace(pGrading3, gradingId, false);
}

void cmdCivilGradingSetRegion()
{
    AcDbObjectId lineWithArcId;
    AcGePoint2dArray points;
    points.append(AcGePoint2d(0, 0));
    points.append(AcGePoint2d(0, 5));
    points.append(AcGePoint2d(0, 10));
    points.append(AcGePoint2d(0, 15));

    AcGeDoubleArray bulges;
    bulges.append(0.0);
    bulges.append(1.0);
    bulges.append(-1.0);
    bulges.append(0.0);

    auto rawPolyline = createSamplePolyline(&points, &bulges, 1.0, false, true);
    AcDbObjectPointer<AcDbPolyline> pPolyline; pPolyline.acquire(rawPolyline);
    addEntityToModelSpace(pPolyline, lineWithArcId, false);

    AcDbObjectPointer<AcDbCivilTinGrading> pGrading; pGrading.create();
    pGrading->setInputData(lineWithArcId);

    const double slope = M_PI_4;
    const double offset = 1.0;
    TinSlopeOffsetRule rule(slope, offset);
    rule.setSide(ETinGradingSide::eGradingSideLeft);
    pGrading->setRule(rule);

    Acad::ErrorStatus es;
    double polyStartParam = 0.0, polyEndParam = 0.0;

    es = pPolyline->getStartParam(polyStartParam);
    assert(es == Acad::eOk);
    es = pPolyline->getEndParam(polyEndParam);
    assert(es == Acad::eOk);

    double startRegionParam = polyStartParam + (polyStartParam + polyEndParam) / 2;
    acutPrintf(L"Enter startRegionParam (max: %f): ", polyEndParam);
    acedGetReal(L"", &startRegionParam);

    double endRegionParam = -1;
    acutPrintf(L"Enter endRegionParam (min: %f max: %f): ", startRegionParam, polyEndParam);
    acedGetReal(L"", &endRegionParam);

    pGrading->setRegionStart(startRegionParam);
    pGrading->setRegionEnd(endRegionParam);

    AcDbObjectId gradingId;
    addEntityToModelSpace(pGrading, gradingId, false);
}
