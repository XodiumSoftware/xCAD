// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"

#include "civil_alignment_sample.h"
#include "civil_utils.h"

#include "BrxSpecific/civil/AcDbCivilAlignments.h"
#include "BrxSpecific/civil/AcDbCivilTinSurface.h"

static void createSimpleHAlignment(AcDbObjectId& hAlignmentId)
{
    AcDbObjectPointer<AcDbCivilDbHAlignment> hAlignment; hAlignment.create();
    addEntityToModelSpace(hAlignment, hAlignmentId, false);
    hAlignment->setDatabaseDefaults();
    {
        auto lineId1 = hAlignment->addLineFixed({ 0.0, 0.0 }, { 5.0, 0.0 });
        auto lineId2 = hAlignment->addLineFixed({ 10.0, 10.0 }, { 10.0, 15.0 });
        auto autoSCSId = hAlignment->addSCSAuto(lineId1, lineId2);
    }
}

static void setupForAlignmentJig(AcDbObjectId& surfaceId)
{
    AcDbObjectPointer<AcDbCivilTinSurface> surface; surface.create();
    surface->initialize({ -15, -15, -10 }, { 15, 15, 10 }, 20);
    AcGePoint3dArray points;
    points.append({ -10, -10, 0 }); points.append({ 10, -10, 0 }); points.append({ 10, 10, 0 }); points.append({ -10, 10, 0 });
    points.append({ -7, -7, 0.5 }); points.append({ 7, -7, 0.5 }); points.append({ 7, 7, 0.5 }); points.append({ -7, 7, 0.5 });
    points.append({ -5, -5, 0.5 }); points.append({ 5, -5, 0.5 }); points.append({ 5, 5, 0.5 }); points.append({ -5, 5, 0.5 });
    points.append({ -2, -2, -0.5 }); points.append({ 2, -2, -0.5 }); points.append({ 2, 2, -0.5 }); points.append({ -2, 2, -0.5 }); points.append({ 0, 0, -0.5 });
    surface->addPoints(points);
    addEntityToModelSpace(surface, surfaceId, false);
}


void cmdCivilCreateAlignment()
{

    AcDbCivilDbHAlignment* pAlign = new AcDbCivilDbHAlignment();

    if (pAlign)
    {
        pAlign->setDatabaseDefaults();
        Adesk::UInt64 s1 = pAlign->addLineFixed(AcGePoint2d(-33530.804, 76119.244), AcGePoint2d(-29901.528, 83858.280));
        Adesk::UInt64 s2 = pAlign->addLineFixed(AcGePoint2d(-26151.278, 85672.116), AcGePoint2d(-19556.921, 84118.951));
        Adesk::UInt64 a1 = pAlign->addArcBetween(s1, s2, AcGePoint2d(-28348.133, 85430.400));
        Adesk::UInt64 s3 = pAlign->addLineFixed(AcGePoint2d(-15747.356, 86518.573), AcGePoint2d(-14230.211, 93457.297));
        Adesk::UInt64 a2 = pAlign->addArcBetween(s2, s3, AcGePoint2d(-17149.510, 84520.805));
        AcDbObjectId entityId;
        Acad::ErrorStatus es = addEntityToModelSpace(pAlign, entityId, true);
        // This looks great
    }

    AcDbCivilDbHAlignment* pAlign2 = new AcDbCivilDbHAlignment();
    if (pAlign2)
    {
        pAlign2->setDatabaseDefaults();
        Adesk::UInt64 s1 = pAlign2->addLineFixed(AcGePoint2d(-6432.542, 75636.284), AcGePoint2d(-4133.936, 83496.466));
        Adesk::UInt64 s2 = pAlign2->addLineFixed(AcGePoint2d(414.674, 84997.253), AcGePoint2d(3638.151, 81620.721));
        AcDbCivilDbHAlignment::ESpiralDefinitionType spiralDefinition = AcDbCivilDbHAlignment::ESpiralDefinitionType::eClothoid;
        AcDbCivilDbHAlignment::ESpiralParameterType spiralParamType = AcDbCivilDbHAlignment::ESpiralParameterType::eParamA;
        double spiral1Param = 2367.950;
        double spiral2Param = 1888.772;
        double radius = 1979.309;

        // This doesn't work as I think it should
        Adesk::UInt64 scs1 = pAlign2->addSCSBetween(s1, s2, spiral1Param, spiral2Param, spiralParamType, radius, spiralDefinition);
        //auto pHAlignSCS1 = AcDbCivilHAlignmentSCS::cast(pAlign2->elementAtId(scs1).get());
        auto element1 = pAlign2->elementAtId(scs1);
        AcDbCivilHAlignmentSCS* pHAlignSCS1a = AcDbCivilHAlignmentSCS::cast(element1.get());
        AcDbCivilHAlignmentSCS* pHAlignSCS1 = AcDbCivilHAlignmentSCS::cast(pAlign2->elementAtId(scs1).get());
        pHAlignSCS1->spiralIn()->setParamA(spiral1Param);
        pHAlignSCS1->spiralOut()->setParamA(spiral2Param);

        Adesk::UInt64 s3 = pAlign2->addLineFixed(AcGePoint2d(8726.345, 83826.027), AcGePoint2d(6101.459, 95155.461));
        
        // Same here
        spiral1Param = 2892.101;
        spiral2Param = 2421.629;
        radius = 2253.352;

        Adesk::UInt64 scs2 = pAlign2->addSCSBetween(s2, s3, spiral1Param, spiral2Param, spiralParamType, radius, spiralDefinition);
        //auto pHAlignSCS2 = AcDbCivilHAlignmentSCS::cast(pAlign2->elementAtId(scs2).get());
        auto element2 = pAlign2->elementAtId(scs2);
        AcDbCivilHAlignmentSCS* pHAlignSCS2 = AcDbCivilHAlignmentSCS::cast(element2.get());
        //AcDbCivilHAlignmentSCS* pHAlignSCS2 = AcDbCivilHAlignmentSCS::cast(pAlign2->elementAtId(scs2).get());
        pHAlignSCS2->spiralIn()->setParamA(spiral1Param);
        pHAlignSCS2->spiralOut()->setParamA(spiral2Param);

        AcDbObjectId entityId;
        Acad::ErrorStatus es = addEntityToModelSpace(pAlign2, entityId, true);
    }


    ////First create horizontal alignment
    //AcDbObjectId hAlignmentId;
    //AcDbObjectPointer<AcDbCivilDbHAlignment> hAlignment; hAlignment.create();
    //addEntityToModelSpace(hAlignment, hAlignmentId, false);
    //hAlignment->setDatabaseDefaults();
    //{
    //    auto lineId1 = hAlignment->addLineFixed({ 0.0, 0.0 }, { 5.0, 0.0 });
    //    auto lineId2 = hAlignment->addLineFixed({ 10.0, 10.0 }, { 10.0, 15.0 });
    //    auto autoSCSId = hAlignment->addSCSAuto(lineId1, lineId2);
    //}

    ////Now we can create vertical alignment that uses previously created hAlignment
    //AcDbObjectId vAlignmentId;
    //AcDbObjectPointer<AcDbCivilDbVAlignment> vAlignment; vAlignment.create();
    //vAlignment->setDatabaseDefaults();
    //{
    //    auto tangentId1 = vAlignment->addTangentFixed({ 0.0, 0.0 }, { 4.0, 4.0 });
    //    auto tangentId2 = vAlignment->addTangentFixed({ 10.0, 8.0 }, { 50.0, 4.0 });
    //    auto autoParabola1 = vAlignment->addParabolaAuto(tangentId1, tangentId2);
    //}
    //addEntityToModelSpace(vAlignment, vAlignmentId, false);
    //vAlignment->setBaseHAlignment(hAlignmentId);

    ////Create vertical alignment view so we can display the vAlignment
    //AcDbObjectId vAlignmentViewId;
    //AcDbObjectPointer<AcDbCivilVAlignmentView> vAlignmentView; vAlignmentView.create();
    //vAlignmentView->setDatabaseDefaults();
    //addEntityToModelSpace(vAlignmentView, vAlignmentViewId, false);
    //vAlignmentView->setBaseHAlignment(hAlignmentId);
    //vAlignmentView->setOrigin({ 0.0, -15.0 });

    ////Create 3d alignment from horizonal and vertical alignment
    //AcDbObjectId alignment3dId;
    //AcDbObjectPointer<AcDbCivilDb3dAlignment> alignment3d; alignment3d.create();
    //addEntityToModelSpace(alignment3d, alignment3dId, false);
    //alignment3d->setBaseHAlignment(hAlignmentId);
    //alignment3d->setVAlignment(vAlignmentId);

    ////Change some alignment visuals
    //{
    //    hAlignment->setLineElementColor(256); //ByLayer
    //    hAlignment->setCurveElementColor(2);
    //    hAlignment->setSpiralElementColor(3);
    //    hAlignment->setTangentExtensionColor(4);
    //    hAlignment->setStyle(static_cast<Adesk::UInt32>(AcDbCivilDbHAlignment::EHAlignmentVisualStyle::eElements) |
    //                         static_cast<Adesk::UInt32>(AcDbCivilDbHAlignment::EHAlignmentVisualStyle::eTangentExtensions) |
    //                         static_cast<Adesk::UInt32>(AcDbCivilDbHAlignment::EHAlignmentVisualStyle::eElementExtensions));
    //    vAlignment->setLineElementColor(256);
    //    vAlignment->setCurveElementColor(5);
    //    vAlignment->setTangentPolygonColor(6);
    //    vAlignment->setStyle(static_cast<Adesk::UInt32>(AcDbCivilDbVAlignment::EVAlignmentVisualStyle::eElements) |
    //                         static_cast<Adesk::UInt32>(AcDbCivilDbVAlignment::EVAlignmentVisualStyle::eTangents));
    //}

    ////Add another vertical alignment to the same horizontal alignment and the same view.
    //AcDbObjectPointer<AcDbCivilDbVAlignment> vAlignment2; vAlignment2.create();
    //vAlignment2->setBaseHAlignment(hAlignmentId);
    //AcDbObjectId vAlignmentId2;
    //addEntityToModelSpace(vAlignment2, vAlignmentId2, false);
    //{
    //    auto tangentId1 = vAlignment2->addTangentFixed({ 5.0, 5.0 }, { 9.0, 6.0 });
    //    auto tangentId2 = vAlignment2->addTangentFixed({ 9.0, 6.0 }, { 15.0, 5.0 });
    //}
    //vAlignmentView->addGraph(vAlignmentId2);
}

void cmdCivilCreateAlignmentFromPolyline()
{
    AcDbObjectPointer<AcDbPolyline> polyline(selectEntityPrompt(L"\nSelect polyline: ", AcDbPolyline::desc(), true));
    if (polyline.openStatus() != eOk)
        return;
    AcDbObjectId hAlignmentId;
    AcDbObjectPointer<AcDbCivilDbHAlignment> hAlignment; hAlignment.create();
    if (polyline->numVerts() < 2)
        return;

    double bulge = 0.0;
    AcGeLineSeg2d lineSeg;
    AcGeCircArc2d arcSeg;
    for (unsigned int i = 0; i < polyline->numVerts() - 1; i++)
    {
        polyline->getBulgeAt(i, bulge);
        if (isZero(bulge))
        {
            polyline->getLineSegAt(i, lineSeg);
            auto elementId = hAlignment->addLineFixed(lineSeg.startPoint(), lineSeg.endPoint());
        }
        else
        {
            polyline->getArcSegAt(i, arcSeg);
            const auto& startPt = arcSeg.startPoint();
            const auto& endPt = arcSeg.endPoint();
            double startParam = arcSeg.paramOf(startPt);
            double endParam = arcSeg.paramOf(endPt);
            const auto& midPt = arcSeg.evalPoint((startParam + endParam) / 2.0);
            auto elementId = hAlignment->addArcFixed(startPt, midPt, endPt);
        }
    }
    if (hAlignment->elementCount() == 0)
        return;

    addEntityToModelSpace(hAlignment, hAlignmentId, false);
}

void cmdCivilReplaceAlignmentElement()
{
    AcDbObjectId alignmentId;
    int marker = 0;
    Acad::ErrorStatus es = getGsMarker(alignmentId, marker);
    if (es != eOk || marker == 0)
        return;
    AcDbObjectPointer<AcDbCivilDbHAlignment> hAlignment(alignmentId, AcDb::kForWrite);
    if (hAlignment.openStatus() != eOk)
        return;
    //You can convert GsMarkers to elementId by using the following function.
    //If the selected GsMarker does not belong to an element, the function will return 0.
    auto elementId = hAlignment->getElementId(marker);
    auto element = hAlignment->elementAtId(elementId);
    if (element == nullptr || !element->isKindOf(AcDbCivilHAlignmentSCS::desc()))
        return;
    AcDbCivilHAlignmentSCS* pHAlignSCS = AcDbCivilHAlignmentSCS::cast(element.get());
    if (pHAlignSCS->tangencyConstraint() == AcDbCivilHAlignmentElement::ETangencyConstraint::eFixed)
        return;
    auto prevId = pHAlignSCS->previousId();
    auto nextId = pHAlignSCS->nextId();
    if (prevId && nextId)
    {
        hAlignment->deleteElement(elementId);
        //After removing element from alignment using it is undefined behaviour,
        //so it's best to discard it as soon as possible.
        pHAlignSCS = nullptr;
        //Element must be added after previous was removed
        hAlignment->addArcAuto(prevId, nextId);
    }
}

static void annotateHAlignmentCurve(const AcDbCivilDbHAlignment& alignment,
                                    const AcDbCivilHAlignmentCurve& curve)
{
    //Get some data from alignment or from the specific element
    //to display as AcMText to the users
    double length = curve.length();
    double startStation = curve.startStation();
    double endStation = curve.endStation();
    double stationAtMiddle = startStation + length / 2.0;
    const auto& startPoint = curve.startPoint();
    const auto& endPoint = curve.endPoint();
    AcGePoint3d pointAtMiddle;
    AcGeVector3d firstDerivAtMiddle;
    double param = 0.0;
    alignment.getParamAtDist(stationAtMiddle, param);
    alignment.getPointAtParam(param, pointAtMiddle);
    alignment.getFirstDeriv(param, firstDerivAtMiddle);
    AcDbObjectPointer<AcDbMText> text; text.create();
    AcString string;
    string.format(L"Length: %.2f\nStart station: %.2f\nEnd station: %.2f",
                  length, startStation, endStation);
    text->setContents(string.kACharPtr());
    text->setLocation(pointAtMiddle - firstDerivAtMiddle.normalize().perpVector());
    AcDbObjectId textId;
    addEntityToModelSpace(text, textId, false);
}

void cmdCivilAnnotateAlignment()
{
    AcDbObjectPointer<AcDbCivilDbHAlignment> hAlignment(
        selectEntityPrompt(L"\nSelect horizontal alignment: ", AcDbCivilDbHAlignment::desc(), true));
    if (hAlignment.openStatus() != eOk)
        return;
    auto elementId = hAlignment->firstElementId();
    while (elementId != 0)
    {
        auto element = hAlignment->elementAtId(elementId);
        if (element.get() && element->isKindOf(AcDbCivilHAlignmentCurve::desc()))
            annotateHAlignmentCurve(*hAlignment, *AcDbCivilHAlignmentCurve::cast(element.get()));
        elementId = element->nextId();
    }
}

static void createXMarkAtHorizontalAlignment(const AcDbCivilDbHAlignment& hAlignment,
                                             double station)
{
    AcGePoint2d point;
    if (!hAlignment.getPointAtStation(station, point))
        return;
    AcDbObjectId pointId;
    AcDbObjectPointer<AcDbPoint> dbPoint; dbPoint.create();
    dbPoint->setPosition({ point.x, point.y, 0.0 });
    addEntityToModelSpace(dbPoint, pointId, false);
}

static void createXMarkAtAlignmentViews(const AcDbCivilDbHAlignment& hAlignment,
                                        const AcGePoint2d& vAlignmentPoint)
{
    for (Adesk::UInt32 i = 0; i < hAlignment.verticalAlignmentViewCount(); i++)
    {
        AcDbObjectPointer<AcDbCivilVAlignmentView> view(hAlignment.verticalAlignmentViewAt(i));
        if (view.openStatus() != eOk)
            continue;
        AcDbObjectId pointId;
        AcDbObjectPointer<AcDbPoint> dbPoint; dbPoint.create();
        auto wcPoint = view->toWCSPoint2d(vAlignmentPoint);
        dbPoint->setPosition({ wcPoint.x, wcPoint.y, 0.0 });
        addEntityToModelSpace(dbPoint, pointId, false);
    }
}

static void createXMarkAt3dAlignments(const AcDbCivilDbHAlignment& hAlignment,
                                      double station)
{
    for (Adesk::UInt32 i = 0; i < hAlignment.alignment3dCount(); i++)
    {
        AcDbObjectPointer<AcDbCivilDb3dAlignment> alignment(hAlignment.alignment3dAt(i));
        AcGePoint3d point;
        if (alignment->getPointAtParam(station, point) != eOk)
            continue;
        AcDbObjectId pointId;
        AcDbObjectPointer<AcDbPoint> dbPoint; dbPoint.create();
        dbPoint->setPosition(point);
        addEntityToModelSpace(dbPoint, pointId, false);
    }
}

void cmdCivilStationsAndParamRelations()
{
    const int SPLIT_COUNT = 4;
    Acad::ErrorStatus es;
    AcGePoint3d point;
    AcDbObjectPointer<AcDbCivilDbVAlignment> vAlignment(selectEntityPrompt(L"\nSelect vertical alignment: ", AcDbCivilDbVAlignment::desc(), true));
    if (vAlignment.openStatus() != eOk)
        return;
    AcDbObjectPointer<AcDbCivilDbHAlignment> hAlignment(vAlignment->baseHAlignment());
    if (hAlignment.openStatus() != eOk)
        return;
    //Make points more visible for this sample
    hAlignment->database()->setPdmode(3);
    //Currently the parameter of vertical and 3d alignment is defined by
    //the station. E.g. vertical alignment that starts at station 10
    //then getStartParam should return 10. And getEndParam returns "start station + 2d length".
    //Similar for 3d alignment.
    double verticalStartStation = 0.0, verticalEndStation = 0.0;
    es = vAlignment->getStartParam(verticalStartStation);
    assert(es == eOk);
    es = vAlignment->getEndParam(verticalEndStation);
    assert(es == eOk);
    double startStation = max(0.0, verticalStartStation);
    double endStation = min(hAlignment->length(), verticalEndStation);
    double markCreationDistance = (endStation - startStation) / SPLIT_COUNT;
    for (int i = 0; i <= SPLIT_COUNT; i++)
    {
        double currentStation = startStation + i * markCreationDistance;
        double distance3d = 0.0;
        es = vAlignment->getDistAtParam(currentStation, distance3d);
        assert(es == eOk);
        es = vAlignment->getPointAtDist(distance3d, point);
        assert(es == eOk);
        createXMarkAtAlignmentViews(*hAlignment, { point.x, point.y });
        createXMarkAtHorizontalAlignment(*hAlignment, currentStation);
        createXMarkAt3dAlignments(*hAlignment, currentStation);
    }
}

void cmdCivilStationEquations()
{
    AcDbObjectId hAlignmentId;
    createSimpleHAlignment(hAlignmentId);
    {
        AcDbObjectPointer<AcDbCivilDbHAlignment> hAlignment(hAlignmentId);
        if (hAlignment.openStatus() != eOk)
            return;
        AcCivilStationEquations stationEquations;
        AcCivilStationEquation stationEquation;
        stationEquation.setRawStation(25);
        stationEquation.setStationForward(15);
        //new station equation is added at raw station 25
        stationEquations.addStationEquation(stationEquation);
        hAlignment->upgradeOpen();
        hAlignment->setStationEquations(stationEquations);
    }
    {
        AcDbObjectPointer<AcDbCivilDbHAlignment> hAlignment(hAlignmentId);
        if (hAlignment.openStatus() != eOk)
            return;
        AcCivilStationEquations stationEquations = hAlignment->stationEquations();
        AcCivilStationEquation stationEquation;
        stationEquation.setRawStation(25);
        stationEquation.setStationForward(20);
        //because there is already station equation with raw station 25,
        //it will get replaced with this new one
        stationEquations.addStationEquation(stationEquation);
        hAlignment->upgradeOpen();
        hAlignment->setStationEquations(stationEquations);
    }
    {
        AcDbObjectPointer<AcDbCivilDbHAlignment> hAlignment(hAlignmentId);
        if (hAlignment.openStatus() != eOk)
            return;
        AcCivilStationEquations stationEquations = hAlignment->stationEquations();
        AcCivilStationEquation stationEquation;
        stationEquation.setRawStation(35);
        stationEquation.setStationForward(25);
        //new station equation is added at raw station 35
        stationEquations.addStationEquation(stationEquation);
        hAlignment->upgradeOpen();
        hAlignment->setStationEquations(stationEquations);
    }
}

class MyAlignmentJig final : public AcEdJig
{
public:

    MyAlignmentJig(AcDbObjectId surfaceId) : m_point(0.0, -8.0)
    {
        AcDbObjectId hAlignmentId, vAlignmentId, alignment3dId;
        m_hAlignment.create();
        m_lineId1 = m_hAlignment->addLineFixed({ -8.0, -8.0 }, m_point);
        m_lineId2 = m_hAlignment->addLineFixed(m_point, { 0.0, 8.0 });
        auto autoSCSId = m_hAlignment->addSCSAuto(m_lineId1, m_lineId2);
        //Create vertical alignment that is 'draped' to the given surface.
        AcDbObjectPointer<AcDbCivilDbVAlignment> vAlignment; vAlignment.create();
        addEntityToModelSpace(m_hAlignment, hAlignmentId, false);
        addEntityToModelSpace(vAlignment, vAlignmentId, false);
        vAlignment->setBaseHAlignment(hAlignmentId);
        vAlignment->setBaseSurface(surfaceId);
        AcDbObjectPointer<AcDbCivilDb3dAlignment> alignment3d; alignment3d.create();
        addEntityToModelSpace(alignment3d, alignment3dId, false);
        alignment3d->setBaseHAlignment(hAlignmentId);
        alignment3d->setVAlignment(vAlignmentId);
    }

    virtual ~MyAlignmentJig()
    {
    }

protected:

    virtual AcDbEntity* entity() const
    {
        return m_hAlignment;
    }

    virtual Adesk::Boolean update()
    {
        auto element1 = m_hAlignment->elementAtId(m_lineId1);
        auto element2 = m_hAlignment->elementAtId(m_lineId2);
        auto line1 = AcDbCivilHAlignmentLine::cast(element1.get());
        auto line2 = AcDbCivilHAlignmentLine::cast(element2.get());
        if (line1 && line2)
        {
            line1->setPassThroughPoint2(m_point);
            line2->setPassThroughPoint1(m_point);
            m_hAlignment->update();
            return true;
        }
        return false;
    }

    virtual DragStatus sampler()
    {
        AcGePoint3d point;
        DragStatus status = acquirePoint(point);
        if (status == DragStatus::kNormal)
            m_point.set(point.x, point.y);
        return status;
    }

    AcGePoint2d m_point;
    mutable AcDbObjectPointer<AcDbCivilDbHAlignment> m_hAlignment;
    Adesk::UInt64 m_lineId1 = 0, m_lineId2 = 0;
};

void cmdCivilAlignmentJig()
{
    AcDbObjectId surfaceId;
    setupForAlignmentJig(surfaceId);
    MyAlignmentJig jig(surfaceId);
    jig.drag();
}

