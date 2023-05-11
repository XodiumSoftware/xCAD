// Copyright (C) Menhirs NV. All rights reserved.

#include "StdAfx.h"

#include "civil_surface_sample.h"
#include "civil_utils.h"

#include "BrxSpecific/civil/AcDbCivilTinSurface.h"
#include "AcDb\AcDbSubDMesh.h"

#include <random>
#include <unordered_map>


#define PI 3.14159265358979323846

//////////////////////////////////////////////////////////////////////////////
// TIN surface examples
//////////////////////////////////////////////////////////////////////////////

void cmdCivilCreateSurface()
{
    const double INNER_SURF_POINTS_OFFSET = 10;
    const double OUTER_SURF_POINTS_OFFSET = 50;
    AcGePoint3dArray points;

    points.append(AcGePoint3d(-INNER_SURF_POINTS_OFFSET, -INNER_SURF_POINTS_OFFSET, 0));
    points.append(AcGePoint3d(INNER_SURF_POINTS_OFFSET, -INNER_SURF_POINTS_OFFSET, 0));
    points.append(AcGePoint3d(INNER_SURF_POINTS_OFFSET, INNER_SURF_POINTS_OFFSET, 0));
    points.append(AcGePoint3d(-INNER_SURF_POINTS_OFFSET, INNER_SURF_POINTS_OFFSET, 0));

    points.append(AcGePoint3d(-OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, 10));
    points.append(AcGePoint3d(OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, 10));
    points.append(AcGePoint3d(OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10));
    points.append(AcGePoint3d(-OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10));

    AcDbObjectPointer<AcDbCivilTinSurface> pSurface; pSurface.create();
    pSurface->setDatabaseDefaults();

    /*
        If you have some general idea about the size of your TIN Surface it is best
        to call the initialize(...) function (thought it is not needed).
        The function sets internal data structures to certain values which help
        with the speed and space preformance.
    */
    pSurface->initialize(AcGePoint3d(-OUTER_SURF_POINTS_OFFSET, -OUTER_SURF_POINTS_OFFSET, 0),
                         AcGePoint3d(OUTER_SURF_POINTS_OFFSET, OUTER_SURF_POINTS_OFFSET, 10),
                         100);
    bool successful = pSurface->addPoints(points);

    if (!successful)
    {
        acutPrintf(L"Adding points to TIN Surface failed\n");
        return;
    }

    AcDbObjectId surfaceId;
    Acad::ErrorStatus es = addEntityToModelSpace(pSurface, surfaceId, true);
    if (es != Acad::eOk)
    {
        acutPrintf(L"Failed to add TIN Surface to model space\n");
        return;
    }
}

void cmdCivilSurfaceList()
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), true));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    AcDbHandle surfaceHandle;
    pSurface->getAcDbHandle(surfaceHandle);
    ACHAR surfaceHandleString[17];
    surfaceHandle.getIntoAsciiBuffer(surfaceHandleString, 17);
    acutPrintf(L"\nSurface handle: %s\n", surfaceHandleString);
        acutPrintf(L"\tSurface contains %d points\n", pSurface->pointsCount(true));
        acutPrintf(L"\tSurface contains %d trinagles\n", pSurface->trianglesCount(true));
        acutPrintf(L"\tSurface 2d is: %f\n", pSurface->area2d(true));
        acutPrintf(L"\tSurface 3d is: %f\n", pSurface->area3d(true));

    AcArray<TinSurfaceConstraint> constraints;
    if (pSurface->getConstraints(constraints))
    {
        acutPrintf(L"Surface contains %d constraints\n", constraints.length());
        for (const TinSurfaceConstraint& constraint : constraints)
        {
            ACHAR* constraintTypeName;
            switch(constraint.constraintType())
            {
            case ETinConstraintType::eTinBoundary:
                constraintTypeName = L"eTinBoundary";
                break;
            case ETinConstraintType::eTinBreakline:
                constraintTypeName = L"eTinBreakline";
                break;
            case ETinConstraintType::eTinWall:
                constraintTypeName = L"eTinWall";
                break;
            }
            acutPrintf(L"\t constraint: ID: %d - type: %s - DBR: %s\n",
                       constraint.id(),
                       constraintTypeName,
                       constraint.isDbResident() ? L"true" : L"false");

            //If the constraint is reported DBRO it is possible to convert it to handle
            if (constraint.isDbResident())
            {
                AcDbHandle handle = AcDbHandle(constraint.id());
                AcDbObjectId constraintId;
                ErrorStatus es = pSurface->database()->getAcDbObjectId(constraintId, false, handle);
                if (es == ErrorStatus::eOk && constraintId.isValid())
                {
                    //Do something
                }
            }
        }
    }
    else
    {
        acutPrintf(L"Surface does not contain any constraints.\n");
    }
}

void cmdCivilListAllSurfaces()
{
    AcDbDatabase *pDb = acdbHostApplicationServices()->workingDatabase();
    if (!pDb)
        return;

    AcDbObjectId modelSpaceId;
    Acad::ErrorStatus res = getModelSpaceId(pDb, modelSpaceId);
    if (res != Acad::eOk)
        return;

    AcDbObjectPointer<AcDbBlockTableRecord> pModelSpace(modelSpaceId, AcDb::kForRead);
    if (!pModelSpace)
        return;

    std::unique_ptr<AcDbBlockTableRecordIterator> pBtrIter;
    res = getBlockTableRecordIterator(pModelSpace, pBtrIter);
    if (res != Acad::eOk)
        return;

    if (!pBtrIter)
        return;

    size_t numSurfaces = 0;
    for (pBtrIter->start(); !pBtrIter->done(); pBtrIter->step())
    {
        AcDbObjectId entId;
        pBtrIter->getEntityId(entId);
        AcDbObjectPointer<AcDbEntity> pEnt(entId, AcDb::kForRead);
        if (pEnt && pEnt->isA() == AcDbCivilTinSurface::desc())
        {
            AcDbHandle surfaceHandle;
            pEnt->getAcDbHandle(surfaceHandle);
            ACHAR surfaceHandleString[17];
            surfaceHandle.getIntoAsciiBuffer(surfaceHandleString, 17);
            acutPrintf(L"Surface %d handle: %s\n", ++numSurfaces, surfaceHandleString);
        }
    }

    if (numSurfaces == 0)
    {
        acutPrintf(L"Could not find any TIN surface entities!\n");
    }
}

void cmdCivilAddBreakline()
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), false));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    AcArray<TinSurfaceConstraint> constraints;

    //Non Database Resident Object case
    {
        AcGePoint3dArray points;
        points.append(AcGePoint3d(-20, -20, 5));
        points.append(AcGePoint3d(-30, 0, 0));
        points.append(AcGePoint3d(-20, 20, -5));

        TinSurfaceBreakline breakline(ETinBreaklineType::eTinBreaklineNomal);
        /*
            Currently Non Database Resident constraints require a unique id
            to be added to TIN Surface (you can use non unique one, but in such
            case it will override the previous constraint definition while leaving
            the points that were added by the (previous) definition).
        */
        uint64_t breaklineId = 1007510122;
        breakline.setData(breaklineId, points);

        //add constraint to the array
        constraints.append(breakline);
    }
    //Database Resident Object case
    {
        AcDbObjectId polylineId;
        AcDbObjectPointer<AcDbPolyline> pPolyline; pPolyline.create();
        pPolyline->addVertexAt(0, AcGePoint2d(20, -20), 0.5);
        pPolyline->addVertexAt(1, AcGePoint2d(30, 0), 0.0);
        pPolyline->addVertexAt(2, AcGePoint2d(20, 20), 0.0);
        pPolyline->setClosed(false);

        Acad::ErrorStatus es = addEntityToModelSpace(pPolyline, polylineId, true);
        if (es != Acad::eOk)
        {
            acutPrintf(L"Failed to add polyline to model space\n");
            return;
        }

        if (polylineId.isNull())
        {
            acutPrintf(L"Polyline Id is null\n");
            return;
        }
        TinSurfaceBreakline breakline(ETinBreaklineType::eTinBreaklineNomal);
        /*
            set the data via Database Resident Object,
            midOrdinateDist defines maximal difference between the actual curve and the tessellated one
        */
        breakline.setData(polylineId, 0.1);

        //add constraint to the array
        constraints.append(breakline);
        assert(!breakline.data().isEmpty());
    }

    //Add multiple constraints at once to improve the preformance
    bool successful = pSurface->addConstraints(constraints);

    if (!successful)
    {
        acutPrintf(L"Failed to add constraints\n");
    }
}

void cmdCivilAddBoundary()
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), false));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    const double SHOW_BOUNDARY_POINTS_OFFSET = 5;
    const double HIDE_BOUNDARY_POINTS_OFFSET = 9;

    TinSurfaceBoundary showBoundary(ETinBoundaryType::eTinShow);
    TinSurfaceBoundary hideBoundary(ETinBoundaryType::eTinHide);


    //Non Database Resident Case
    {
        AcGePoint3dArray showBoundaryPoints;
        showBoundaryPoints.append(AcGePoint3d(-SHOW_BOUNDARY_POINTS_OFFSET, -SHOW_BOUNDARY_POINTS_OFFSET, 0));
        showBoundaryPoints.append(AcGePoint3d(SHOW_BOUNDARY_POINTS_OFFSET, -SHOW_BOUNDARY_POINTS_OFFSET, 0));
        showBoundaryPoints.append(AcGePoint3d(SHOW_BOUNDARY_POINTS_OFFSET, SHOW_BOUNDARY_POINTS_OFFSET, 0));
        showBoundaryPoints.append(AcGePoint3d(-SHOW_BOUNDARY_POINTS_OFFSET, SHOW_BOUNDARY_POINTS_OFFSET, 0));

        /*
            Currently Non Database Resident constraints require a unique id
            to be added to TIN Surface (you can use non unique one, but in such
            case it will override the previous constraint definition while leaving
            the points that were added by the (previous) definition).
        */
        uint64_t showBoundaryId = 1054400123;
        showBoundary.setData(showBoundaryId, showBoundaryPoints);
    }
    //Database Resident Case
    {
        AcDbObjectPointer<AcDbPolyline> pPolyline; pPolyline.create();
        pPolyline->setClosed(true);
        pPolyline->addVertexAt(0, AcGePoint2d(-HIDE_BOUNDARY_POINTS_OFFSET, -HIDE_BOUNDARY_POINTS_OFFSET), 0);
        pPolyline->addVertexAt(1, AcGePoint2d(HIDE_BOUNDARY_POINTS_OFFSET, -HIDE_BOUNDARY_POINTS_OFFSET), 0.5);
        pPolyline->addVertexAt(2, AcGePoint2d(HIDE_BOUNDARY_POINTS_OFFSET, HIDE_BOUNDARY_POINTS_OFFSET), 0);
        pPolyline->addVertexAt(3, AcGePoint2d(-HIDE_BOUNDARY_POINTS_OFFSET, HIDE_BOUNDARY_POINTS_OFFSET), 0);

        AcDbObjectId polylineId;
        Acad::ErrorStatus es = addEntityToModelSpace(pPolyline, polylineId, true);
        if (es != Acad::eOk)
        {
            acutPrintf(L"Failed to add polyline to model space\n");
            return;
        }

        /*
            Set the boundary data via AcDbObjectId. The boundary data is automatically parsed
            from the object. Currently supported entities are AcDbPolyline, AcDb2dPolyline, AcDb3dPolyline,
            AcDbLine, 
        */

        hideBoundary.setData(polylineId, 0.1);
        assert(!hideBoundary.data().isEmpty());
    }

    if (!pSurface->isWriteEnabled())
    {
        Acad::ErrorStatus es(eOk);
        es = pSurface->upgradeOpen();
        if (es != Acad::eOk)
        {
            acutPrintf(L"Failed to upgrade open TIN Surface\n");
            return;
        }
    }

    /*
        The two (or more) constraints could be added to TIN Surface
        with single command (pSurface->addConstraints) as in the 
        cmdCivilAddBreakline() sample, to improve the preformance.
        
        When adding the boundaries the user must be careful, since
        changing the order of adding the boundaries can lead to different
        result. (e.g. in this case first adding showBoundary and then
        hideBoundary will _appear_ to only add the hideBoundary)
    */
    bool successful = pSurface->addConstraint(hideBoundary);
    if (!successful)
    {
        acutPrintf(L"Failed to add hideBoundaryId\n");
    }

    successful = pSurface->addConstraint(showBoundary);
    if (!successful)
    {
        acutPrintf(L"Failed to add showBoundary\n");
    }
}

void civilAddDBROConstraints(ETinConstraintType constraintType)
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), false));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    AcString curvePrompt(L"Select DBR Curve to add as a surface constraint: ");
    while (true)
    {
        AcDbObjectPointer<AcDbCurve> pCurve(selectEntityPrompt(curvePrompt, AcDbCurve::desc(), true));
        AcDbObjectId polylineId;
        if (pCurve.openStatus() == eOk)
        {
            polylineId = pCurve->objectId();
            pCurve->close();
        }
        else
        {
            break;
        }

        if (polylineId.isNull())
        {
            acutPrintf(L"Polyline Id is null\n");
            break;
        }

        std::unique_ptr<TinSurfaceConstraint> pConstraint = nullptr;
        if (constraintType == ETinConstraintType::eTinBreakline)
        {
            pConstraint = std::make_unique<TinSurfaceBreakline>(ETinBreaklineType::eTinBreaklineNomal);
        }
        else if (constraintType == ETinConstraintType::eTinBoundary)
        {
            pConstraint = std::make_unique<TinSurfaceBoundary>(ETinBoundaryType::eTinHide);
        }
        else
        {
            pConstraint = std::make_unique<TinSurfaceWall>(ETinWallType::eTinWallNomal);
        }

        /*
            set the data via Database Resident Object,
            midOrdinateDist defines maximal difference between the actual curve and the tessellated one
        */
        pConstraint->setData(polylineId, 0.2);


        if (!pSurface->isWriteEnabled())
        {
            Acad::ErrorStatus es(eOk);
            es = pSurface->upgradeOpen();
            if (es != Acad::eOk)
            {
                acutPrintf(L"Failed to upgrade open TIN Surface\n");
                return;
            }
        }
        /*
            add constraint
            and add reactor to the DBRO so the TIN Surface updates
            it's breakline when users edit the polyline. If you do
            not wish to dynamically conect the two entites you can
            achieve that by passing false instead to addConstraint(s)
            function.
        */
        bool successful = pSurface->addConstraint(*pConstraint, true);
        if (!successful)
        {
            acutPrintf(L"Failed to add constraint\n");
            break;
        }

        /*
            TIN Surface automatically updates when it closes;
            if we wish to update it while it's stil open a call to
            pSurface->updateObjectData() is needed to update surface
            with currently cached data.
        */
        acutPrintf(L"\nSurface 3d area: %f", pSurface->area3d(true));
        pSurface->updateObjectData();
        acutPrintf(L"\nAfter calling updateObjectData 3d area: %f\n", pSurface->area3d(true));

        //flush modifications
        pSurface->downgradeOpen();
    }
}

void cmdCivilAddBreaklineDBRO()
{
    civilAddDBROConstraints(ETinConstraintType::eTinBreakline);
}

void cmdCivilAddBoundaryDBRO()
{
    civilAddDBROConstraints(ETinConstraintType::eTinBoundary);
}

void civilRemoveConstraint(ETinConstraintType constraintType)
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), false));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    AcArray<TinSurfaceConstraint> constraints;
    pSurface->getConstraints(constraints);

    bool removedConstraint = false;
    for (const TinSurfaceConstraint& constraint : constraints)
    {
        if (constraint.constraintType() == constraintType)
        {
            if (!pSurface->isWriteEnabled())
            {
                Acad::ErrorStatus es(eOk);
                es = pSurface->upgradeOpen();
                if (es != Acad::eOk)
                {
                    acutPrintf(L"Failed to upgrade open TIN Surface\n");
                    return;
                }
            }
            if (pSurface->eraseConstraint(constraint.id()))
            {
                acutPrintf(L"Successfully removed constraint with ID: %d\n", constraint.id());
                removedConstraint = true;
                break;
            }
        }
    }
    if (!removedConstraint)
    {
        acutPrintf(L"Could not find any matching constraints for removal. \n");
    }
}

void cmdCivilRemoveBreakline()
{
    civilRemoveConstraint(ETinConstraintType::eTinBreakline);
}

void cmdCivilRemoveBoundary()
{
    civilRemoveConstraint(ETinConstraintType::eTinBoundary);
}

void cmdCivilChangeStyle()
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(
        selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), false), AcDb::kForWrite);
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    //Check existing style
    {
        ETinSurfaceStyle style = pSurface->style();
        acutPrintf(L"Currently active TIN Surface styles: ");
        if (style == eTinStyleNone)
            acutPrintf(L"none ");
        if (style & ETinSurfaceStyle::eTinStyleBoundaryLine)
            acutPrintf(L"eTinStyleBoundaryLine ");
        if (style & ETinSurfaceStyle::eTinStylePoints)
            acutPrintf(L"eTinStylePoints ");
        if (style & ETinSurfaceStyle::eTinStyleTriangles)
            acutPrintf(L"eTinStyleTriangles");
        if (style & ETinSurfaceStyle::eTinStyleContours)
            acutPrintf(L"eTinStyleContours");
        if (style & ETinSurfaceStyle::eTinStyleElevationTooltip)
            acutPrintf(L"eTinStyleElevationTooltip");
        acutPrintf(L"\n");
    }

    ACHAR* getStylePrompt = L"Set style (0 - off, 1 - triangles, 2 - contours and points) :";
    int userSelectedStyle = 0;
    acedGetIntInRange(getStylePrompt, &userSelectedStyle, 0, 3);

    //Update TIN Surface style
    if (userSelectedStyle == 0)
    {
        acutPrintf(L"Switching off all styles.\n");
        /*
            When all styles are switched off TIN Surface displays
            a bounding box (so that the user is still able to select
            the entity).
        */
        pSurface->setStyle(eTinStyleNone);
    }
    else if (userSelectedStyle == 1)
    {
        acutPrintf(L"Switching style to triangles.\n");
        pSurface->setStyle(eTinStyleTriangles);
    }
    else if (userSelectedStyle == 2)
    {
        acutPrintf(L"Switching style to contours and points.\n");
        /*
            You can combine multiple ETinSurfaceStyle to draw multiple
            different styles at once.
        */
        pSurface->setStyle(static_cast<ETinSurfaceStyle>(eTinStyleContours | eTinStylePoints));
    }
    else
    {
        acutPrintf(L"Error selecting style.\n");
        return;
    }

    //Set contour interval
    {
        ACHAR* getMinorContoursIntervalPrompt = L"Enter minor contour interval:";
        ACHAR* getMajorContoursIntervalPrompt = L"Enter major contour interval:";

        double majorContoursInterval = 5, minorContoursInterval = 1;
        ads_real rv;
        int res = acedGetReal(getMinorContoursIntervalPrompt, &rv);
        if (res == RTNORM)
            minorContoursInterval = res;
        res = acedGetReal(getMajorContoursIntervalPrompt, &rv);
        if (res == RTNORM)
            majorContoursInterval = res;

        if (majorContoursInterval > (minorContoursInterval + AcGeContext::gTol.equalPoint()))
        {
            pSurface->setMinorContoursInterval(minorContoursInterval);
            pSurface->setMajorContoursInterval(majorContoursInterval);
        }
        else
        {
            acutPrintf(L"Specified minor contour interval is greater than major interval\n");
        }
    }

    //Set contour colors
    {
        ACHAR* getMinorContoursColorPrompt = L"Enter minor contour color:";
        ACHAR* getMajorContoursColorPrompt = L"Enter major contour color:";
        Adesk::UInt16 majorContoursColor = 1, minorContoursColor = 2;
        int majorCS, minorCS;
        if (acedGetIntInRange(getMinorContoursColorPrompt, &minorCS, 0, 255) == RTNORM)
            minorContoursColor = static_cast<Adesk::UInt16>(minorCS);
        if (acedGetIntInRange(getMajorContoursColorPrompt, &majorCS, 0, 255) == RTNORM)
            majorContoursColor = static_cast<Adesk::UInt16>(majorCS);

        Adesk::UInt16 prevMajorContoursColor, prevMinorContoursColor;

        bool b2 = pSurface->minorContoursColor(prevMinorContoursColor);
        bool b1 = pSurface->majorContoursColor(prevMajorContoursColor);
        assert(b1 && b2);

        acutPrintf(L"Switching (minor, major) contour colors from: %d and %d to %d and %d\n",
                   prevMinorContoursColor,
                   prevMajorContoursColor,
                   minorContoursColor,
                   majorContoursColor);

        bool b4 = pSurface->setMinorContoursColor(minorContoursColor);
        bool b3 = pSurface->setMajorContoursColor(majorContoursColor);
        assert(b3 && b4);
    }
}

AcCmColor generateColorSheme(int typeOfSheme, int colorIndex)
{
    if (colorIndex > 255)
        colorIndex = 255;
    else if(colorIndex < 0)
        colorIndex = 0; 
    AcCmColor color;
    if (typeOfSheme == 0)
        color.setRGB(colorIndex, 0, 0);
    else if (typeOfSheme == 1)
        color.setRGB(0, colorIndex, 0);
    else
        color.setRGB(0, 0, colorIndex);
    return color;
}

AcDbEntityPtrArray generateMeshes(AcArray<AcCivilTinTriangleArray>& tinTrianglesRanges,
    int numOfRanges, int typeOfScheme)
{
    int rangeIndex = 0;
    int colorRange = 255 / (numOfRanges - 1);
    AcDbEntityPtrArray entities;

    for(auto& tinTriangleRange : tinTrianglesRanges)
    {
        if (tinTriangleRange.isEmpty())
        {
            ++rangeIndex;
            continue;
        }
        std::unordered_map<AcCivilTinPoint, int> uniqueVertices(
            (size_t)tinTriangleRange.length() / 2);
       //unique points from triangles
        AcGePoint3dArray uniquePoints;
        for(auto& tinTriangle : tinTriangleRange)
        {
            for (uint16_t i = 0; i < 3; ++i)
            {
                if (uniqueVertices.find(tinTriangle.pointAt(i)) != uniqueVertices.end())
                    continue;
                uniquePoints.append(tinTriangle.pointAt(i).location());
                uniqueVertices[tinTriangle.pointAt(i)] = uniquePoints.length() - 1;
            }
        }
        //make faces indices for meshes
        AcArray<Adesk::Int32> trianglesIndices;
        for (auto& tinTriangle : tinTriangleRange)
        {
            trianglesIndices.append(3);
            for (uint16_t i = 0; i < 3; ++i)
                trianglesIndices.append(uniqueVertices[tinTriangle.pointAt(i)]);
        }
        //create subDMesh-es
        auto subDMesh = new AcDbSubDMesh();
        subDMesh->setDatabaseDefaults(curDoc()->database());
        subDMesh->setSubDMesh(uniquePoints, trianglesIndices, 0);
        int colorIndex = rangeIndex * colorRange;
        if (colorIndex > colorRange * (numOfRanges - 1))
            colorIndex = 255;
        auto color = generateColorSheme(typeOfScheme, colorIndex);
        subDMesh->setColor(color);
        entities.append(subDMesh);
        ++rangeIndex;
    }
    return entities;
}

AcDbEntityPtrArray generateFaces(AcArray<AcCivilTinTriangleArray>& tinTrianglesRanges,
    int numOfRanges, int typeOfScheme)
{
    int rangeIndex = 0;
    int colorRange = 255 / (numOfRanges - 1);
    AcDbEntityPtrArray entities;
    for (auto& tinTriangleRange : tinTrianglesRanges)
    {
        if (tinTriangleRange.isEmpty())
        {
            ++rangeIndex;
            continue;
        }
        int colorIndex = rangeIndex * colorRange;
        if (colorIndex > colorRange * (numOfRanges - 1))
            colorIndex = 255;
        auto color = generateColorSheme(typeOfScheme, colorIndex);
        for (auto& tinTriangle : tinTriangleRange)
        {
            auto dbFace = new AcDbFace(tinTriangle.locationAt(0),
                tinTriangle.locationAt(1),
                tinTriangle.locationAt(2));
            dbFace->setDatabaseDefaults(curDoc()->database());
            dbFace->setColor(color);
            entities.append(dbFace);
        }
        ++rangeIndex;
    }
    return entities;
}

void cmdCivilSurfaceMapElevations()
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), false));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    AcDbCivilTinSurface* clonedSurface = (AcDbCivilTinSurface*)pSurface->clone();
    pSurface->close();

    int numOfRanges = 8;
    if (RTCAN == acedGetIntInRange(_ACRX_T("Enter number of ranges <8>:"), &numOfRanges, 1, 100))
        return;
    int colorScheme = 0;
    acedInitGet(0, _ACRX_T("Red Green Blue"));
    ACHAR szKwordColor[128];
    if (RTCAN == acedGetKword(_ACRX_T("\nEnter color scheme [Red/Green/Blue]:"), szKwordColor))
        return;
    if (0 == _tcscmp(szKwordColor,_ACRX_T("Green")))
        colorScheme = 1;
    else if(0 == _tcscmp(szKwordColor, _ACRX_T("Blue")))
        colorScheme = 2;
    int typeOfEntity = 0;
    acedInitGet(0, _ACRX_T("Meshes Faces"));
    ACHAR szKwordType[128];
    if (RTCAN == acedGetKword(_ACRX_T("\nEnter entity type [Meshes/Faces]:"), szKwordType))
        return;
    if (0 == _tcscmp(szKwordType, _ACRX_T("Faces")))
        typeOfEntity = 1;

    auto minElevation = clonedSurface->minElevation(true);
    auto maxElevation = clonedSurface->maxElevation(true);

    double elevFactor = (maxElevation - minElevation) / numOfRanges;
    double currentElevation = minElevation;

    AcTinSurfaceConstraintArray breaklinesToAdd;
    //create non-destructive breaklines on elevations
    uint64_t breaklineId = 1;
    for (int i = 0; i < numOfRanges; ++i)
    {
        currentElevation += elevFactor;
        AcArray<AcGePoint3dArray> contours;
        if (clonedSurface->contoursAtElevation(contours, currentElevation) && !contours.isEmpty())
        {
            for (int j = 0; j < contours.length(); ++j)
            {
                TinSurfaceBreakline nonDestBreakline(ETinBreaklineType::eTinNonDestructive);
                nonDestBreakline.setData(breaklineId++, contours[j]);
                breaklinesToAdd.append(nonDestBreakline);
            }
        }
    }
    clonedSurface->addConstraints(breaklinesToAdd, false);
    //only memory object - UpdateObjectData must be called
    clonedSurface->updateObjectData();

    //sort triangles by elevations
    AcCivilTinTriangleArray triangles;
    if (!clonedSurface->tinTriangles(triangles) || triangles.isEmpty())
        return;
    AcArray<AcCivilTinTriangleArray> tinTrianglesByRanges;
    for (int i = 0; i < numOfRanges; ++i)
    {
        tinTrianglesByRanges.append(AcCivilTinTriangleArray());
    }

    for (auto& triangle : triangles)
    {
        //check elevation of center
        double midElevation = (triangle.locationAt(0).z +
            triangle.locationAt(1).z + triangle.locationAt(2).z) / 3;
        //create index from elevation
        int index = (int)((midElevation - minElevation) / elevFactor);
        if (index < 0)
            index = 0;
        else if (index > numOfRanges - 1)
            index = numOfRanges - 1;
        tinTrianglesByRanges[index].append(triangle);
    }
    AcDbEntityPtrArray entities;
    if(typeOfEntity == 0)
        entities = generateMeshes(tinTrianglesByRanges, numOfRanges, colorScheme);
    else
        entities = generateFaces(tinTrianglesByRanges, numOfRanges, colorScheme);
    addEntitiesToModelSpace(entities);
}

void cmdCivilSurfaceMapSlope()
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), false));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    AcDbCivilTinSurface* clonedSurface = (AcDbCivilTinSurface*)pSurface->clone();
    pSurface->close();

    int numOfRanges = 8;
    if (RTCAN == acedGetIntInRange(_ACRX_T("Enter number of ranges <8>:"), &numOfRanges, 1, 100))
        return;
    int colorScheme = 0;
    acedInitGet(0, _ACRX_T("Red Green Blue"));
    ACHAR szKwordColor[128];
    if (RTCAN == acedGetKword(_ACRX_T("\nEnter color scheme [Red/Green/Blue]:"), szKwordColor))
        return;
    if (0 == _tcscmp(szKwordColor, _ACRX_T("Green")))
        colorScheme = 1;
    else if (0 == _tcscmp(szKwordColor, _ACRX_T("Blue")))
        colorScheme = 2;
    int typeOfEntity = 0;
    acedInitGet(0, _ACRX_T("Meshes Faces"));
    ACHAR szKwordType[128];
    if (RTCAN == acedGetKword(_ACRX_T("\nEnter entity type [Meshes/Faces]:"), szKwordType))
        return;
    if (0 == _tcscmp(szKwordType, _ACRX_T("Faces")))
        typeOfEntity = 1;

    AcCivilTinTriangleArray tinTriangles;
    if (!clonedSurface->tinTriangles(tinTriangles) || tinTriangles.isEmpty())
        return;

    AcArray<AcCivilTinTriangleArray> tinTrianglesByRanges;
    for (int i = 0; i < numOfRanges; ++i)
    {
        tinTrianglesByRanges.append(AcCivilTinTriangleArray());
    }

    auto angleFactor = (PI * 0.5) / numOfRanges;

    for(auto& tinTriangle : tinTriangles)
    {
        AcGePoint3dArray trianglePoints;
        for(uint16_t i = 0; i < 3; ++i)
            trianglePoints.append(tinTriangle.locationAt(i));
        std::sort(trianglePoints.begin(), trianglePoints.end(),
            [](const AcGePoint3d& a, const AcGePoint3d& b)
        {
            return a.z < b.z;
        });
        AcGeVector3d vec = (trianglePoints[2] - trianglePoints[0]);
        double angleToPlane = vec.angleTo(AcGeVector3d::kZAxis);

        int index = (int)(angleToPlane / angleFactor);
        if (index < 0)
            index = 0;
        else if (index > numOfRanges - 1)
            index = numOfRanges - 1;
        tinTrianglesByRanges[index].append(tinTriangle);
    }
    AcDbEntityPtrArray entities;
    //meshes
    if (typeOfEntity == 0)
        entities = generateMeshes(tinTrianglesByRanges,
            numOfRanges, colorScheme);
    //faces
    else
        entities = generateFaces(tinTrianglesByRanges,
            numOfRanges, colorScheme);
    addEntitiesToModelSpace(entities);
}

void cmdCivilSurfaceMerge()
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(
        selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), false));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    AcDbObjectPointer<AcDbCivilTinSurface> pMergeSurface(
        selectEntityPrompt(L"Select  second TIN Surface: ", AcDbCivilTinSurface::desc(), false));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    int userMergeOption = 1;
    acedGetIntInRange(L"0 - merge to existing, 1 - create new surface", &userMergeOption, 0, 1);

    if (userMergeOption)
    {
        AcDbCivilTinSurface* pNewSurface = AcDbCivilTinSurface::merge(pSurface, pMergeSurface);
        if (!pNewSurface)
        {
            acutPrintf(L"Merge failed.\n");
        }
        else
        {
            AcDbObjectId newSurfaceId;
            Acad::ErrorStatus es = addEntityToModelSpace(pNewSurface, newSurfaceId, true);
            if (es != Acad::eOk)
                acutPrintf(L"Failed adding new surface to model space.\n");
        }
    }
    else
    {
        if (!pSurface->isWriteEnabled())
        {
            Acad::ErrorStatus es(eOk);
            es = pSurface->upgradeOpen();
            if (es != Acad::eOk)
            {
                acutPrintf(L"Failed to upgrade open TIN Surface.\n");
                return;
            }
        }

        bool successful = pSurface->merge(pMergeSurface);
        if (!successful)
            acutPrintf(L"Merging pMergeSurface in to pSurface failed.\n");
    }
}

void cmdCivilSurfaceMesh()
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface( selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), true));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    //ETinSurfaceMeshType::eTinSurfaceMeshDepth
    {
        /*
            eTinSurfaceMeshDepth creates mesh by duplicating the surface vertices (points)
            and adding the 'thickness' parameter to the Z-coordinate of the duplicated points.
            Points are then 'stiched' together to create a closed mesh. 
        */
        auto rawMeshAbove = pSurface->subDMesh(ETinSurfaceMeshType::eTinSurfaceMeshDepth, 1.0);
        auto rawMeshBelow = pSurface->subDMesh(ETinSurfaceMeshType::eTinSurfaceMeshDepth, -1.0);
        AcDbObjectPointer<AcDbSubDMesh> pMeshAbove, pMeshBelow;
        pMeshAbove.acquire(rawMeshAbove);
        pMeshBelow.acquire(rawMeshBelow);
        if (!pMeshAbove || !pMeshBelow)
            return;
        pMeshAbove->setColorIndex(1);
        pMeshBelow->setColorIndex(2);
        AcDbObjectId m1, m2;
        addEntityToModelSpace(pMeshAbove, m1, false);
        addEntityToModelSpace(pMeshBelow, m2, false);
    }

    //ETinSurfaceMeshType::eTinSurfaceMeshElevation
    {
        const double maxElevation = pSurface->maxElevation(true);
        const double minElevation = pSurface->minElevation(true);

        /*
            eTinSurfaceMeshElevation creates mesh by duplicating the surface vertices (points)
            and setting the Z-coordinate of the duplicated points to given parameter.
            Points are then 'stiched' together to create a closed mesh.
        */
        auto rawMeshAbove = pSurface->subDMesh(ETinSurfaceMeshType::eTinSurfaceMeshElevation, maxElevation + 5.0);
        auto rawMeshBetween = pSurface->subDMesh(ETinSurfaceMeshType::eTinSurfaceMeshElevation, (maxElevation + minElevation) / 2.0);
        auto rawMeshBelow = pSurface->subDMesh(ETinSurfaceMeshType::eTinSurfaceMeshElevation, minElevation - 5.0);
        AcDbObjectPointer<AcDbSubDMesh> pMeshAbove, pMeshBetween, pMeshBelow;
        pMeshAbove.acquire(rawMeshAbove);
        pMeshBetween.acquire(rawMeshBetween);
        pMeshBelow.acquire(rawMeshBelow);
        if (!pMeshAbove || !pMeshBetween || !pMeshBelow)
            return;
        pMeshAbove->setColorIndex(3);
        pMeshBetween->setColorIndex(4);
        pMeshBelow->setColorIndex(5);
        AcDbObjectId m1, m2, m3;
        addEntityToModelSpace(pMeshAbove, m1, false);
        addEntityToModelSpace(pMeshBetween, m2, false);
        addEntityToModelSpace(pMeshBelow, m3, false);
    }
}

void cmdCivilSurfaceDrape()
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), true));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    AcGePoint2d minPt, maxPt;
    pSurface->boundingBox(minPt, maxPt);

    AcGePoint3dArray points;
    const double maxElevation = pSurface->maxElevation();
    
    points.append(AcGePoint3d(minPt.x, minPt.y, maxElevation));
    points.append(AcGePoint3d(maxPt.x, maxPt.y, maxElevation));

    points.append(AcGePoint3d(maxPt.x + 10, maxPt.y + 10, maxElevation));
    points.append(AcGePoint3d(maxPt.x + 10, (maxPt.y + minPt.y) / 2, maxElevation));
    points.append(AcGePoint3d(minPt.x, (maxPt.y + minPt.y) / 2, maxElevation));


    {
        AcDbObjectPointer<AcDbPolyline> pPolyline; pPolyline.create();
        pPolyline->setColorIndex(1);
        for(int i = 0; i < points.length(); ++i)
        {
            pPolyline->addVertexAt(i, AcGePoint2d(points[i].x, points[i].y), 0);
        }
        AcDbObjectId lineId;
        addEntityToModelSpace(pPolyline, lineId, false);
    }

    /*
        The drape function projects a 3d polyline onto the given TIN Surface.
        The result can be:
         - empty (given points (polyline vertices) and the surface do not intersect,
           if both would be projected onto XY plane)
         - one AcGePoint3dArray (all the polyline vertices can be projected without
           any discontinuites)
         - multiple resulting AcGePoint3dArray (some parts of the polyline
           can be projected on the surface, while others "fall" of the surface
           or are inside the hide boundaries)
    */

    AcArray<AcGePoint3dArray> drapedPointGroups;
    bool successful = pSurface->drape(drapedPointGroups, points);

    if (successful)
    {
        for(const AcGePoint3dArray& drapedPoints : drapedPointGroups)
        {
            AcDbObjectPointer<AcDb3dPolyline> pPolyline; pPolyline.create();
            pPolyline->setColorIndex(3);
            for (const AcGePoint3d& point : drapedPoints)
                pPolyline->appendVertex(new AcDb3dPolylineVertex(point));

            AcDbObjectId drapedPolylineId;
            addEntityToModelSpace(pPolyline, drapedPolylineId, false);
        }
    }
    else
    {
        acutPrintf(L"Drape failed.\n");
    }
}

//////////////////////////////////////////////////////////////////////////////
// Volume surface examples
//////////////////////////////////////////////////////////////////////////////

/*
CASES:
// initializes the TinVolumeSurface based on 2 surfaces, and a bounding contour
virtual bool initialize(const AcDbCivilTinSurface* baseSurface,
                        const AcDbCivilTinSurface* compSurface,
                        const AcGePoint3dArray& boundingPolygon);
// initializes the TinVolumeSurface based on 2 surfaces, and a bounding contour
// taken from specified contour entity (using midOrdinateDist to determine the smoothness)
virtual bool initialize(const AcDbCivilTinSurface* baseSurface,
                        const AcDbCivilTinSurface* compSurface,
                        const AcDbObjectId& boundingPolygonId,
                        const double midOrdinateDist);
*/
void cmdCivilVolumeSurfaceCreate()
{
    /*
        Most of the BRX Civil Entities do not have to be a Database Residents
        in order to be useful for various calculations. BRX Civil API enables
        you to create and use entities that are created on memory only for
        quicker and lighter calculations.

        In this case we will only create a clone of the selected surface,
        raise it by some offset and then calculate the volume between the
        two surfaces. Then we'll delete the cloned surface without adding
        it to the Database. Same could also be done for the AcDbCivilTinVolumeSurface.
    */

    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), false));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    //Create a clone of the selected surface
    AcDbObjectPointer<AcDbCivilTinSurface> pClonedSurface;
    auto rawClone = AcDbCivilTinSurface::cast(pSurface->clone());
    pClonedSurface.acquire(rawClone);
    if (!pClonedSurface)
    {
        return;
    }

    const double CLONED_SURFACE_OFFSET = 10;
    pClonedSurface->raiseSurface(CLONED_SURFACE_OFFSET);
    //We could also call pClonedSurface->transformBy e.g.:
    //Acad::ErrorStatus es = pClonedSurface->transformBy(AcGeMatrix3d().setTranslation(AcGeVector3d(0, 0, CLONED_SURFACE_OFFSET)));

    AcDbObjectPointer<AcDbCivilTinVolumeSurface> pVolumeSurface; pVolumeSurface.create();
    /*
        Passing empty boundingPolygon parameter (AcGePoint3dArray()) tells the
        AcDbCivilTinVolumeSurface to calculate volume between the surfaces
        without bounds.
    */
    pVolumeSurface->initialize(pSurface, pClonedSurface, AcGePoint3dArray());

    const double area2d = pSurface->area2d(true);
    //Let's check if the volume calculated is correct
    if (!doubleEqual(area2d * CLONED_SURFACE_OFFSET, pVolumeSurface->fillVolume(), 1e10-6))
    {
        acutPrintf(L"Volume between the surfaces: %f\n", pVolumeSurface->fillVolume());
    }
    else
    {
        acutPrintf(L"Volume was wrongly calculated!\n");
    }

    AcDbObjectId pVolumeSurfaceId;
    Acad::ErrorStatus es = addEntityToModelSpace(pVolumeSurface, pVolumeSurfaceId, true);
    if (es != Acad::eOk)
    {
        acutPrintf(L"AcDbCivilTinVolumeSurface could not be added to model space\n");
        return;
    }
}

/*
CASES:
// initializes the TinVolumeSurface based on a surfaces with depth and bounding contour
virtual bool initialize(const AcDbCivilTinSurface* baseSurface,
                        const double depthElevation, const ETinVolumeSurfaceType type,
                        const AcGePoint3dArray& boundingPolygon);
// initializes the TinVolumeSurface based on a surfaces with depth and bounding contour
// taken from specified contour entity (using midOrdinateDist to determine the smoothness)
virtual bool initialize(const AcDbCivilTinSurface* baseSurface,
                        const double depthElevation, const ETinVolumeSurfaceType type,
                        const AcDbObjectId& boundingPolygonId,
                        const double midOrdinateDist);
*/
void cmdCivilVolumeSurfaceCreateElev()
{
    AcDbObjectPointer<AcDbCivilTinSurface> pSurface(selectEntityPrompt(L"Select TIN Surface: ", AcDbCivilTinSurface::desc(), true));
    if (!pSurface || pSurface.openStatus() != eOk)
        return;
    double elevation = 0.0;
    acedGetReal(L"Enter the reference elevation:\n", &elevation);

    AcDbObjectPointer<AcDbCivilTinVolumeSurface> pVolumeSurface1; pVolumeSurface1.create();
    AcDbObjectPointer<AcDbCivilTinVolumeSurface> pVolumeSurface2; pVolumeSurface2.create();
    /*
        ETinVolumeSurfaceType::eTinVolumeToElevation - calculates the volume of between the XY plane
        with specified reference elevation and the provided AcDbCivilTinSurface (or any derived type)
    */
    pVolumeSurface1->initialize(pSurface, elevation,
                                ETinVolumeSurfaceType::eTinVolumeToElevation, AcGePoint3dArray());
    /*
        ETinVolumeSurfaceType::eTinVolumeToDepth - calculates the volume of surface raised / lowered by the
        specified elevation(exactly the same as done in the example cmdCivilVolumeSurfaceCreate).
    */
    pVolumeSurface2->initialize(pSurface, elevation,
                                ETinVolumeSurfaceType::eTinVolumeToDepth, AcGePoint3dArray());

    /*
        Similar to the cmdCivilVolumeSurfaceCreate case there is no need
        to add the AcDbCivilTinVolumeSurface entities to the Database,
        (since we are only interested in the cut/fill volumes).
    */
    acutPrintf(L"eTinVolumeToElevation : Fill volume: %f  Cut volume: %f\n",
               pVolumeSurface1->fillVolume(),
               pVolumeSurface1->cutVolume());
    acutPrintf(L"eTinVolumeToDepth : Fill volume: %f  Cut volume: %f\n",
               pVolumeSurface2->fillVolume(),
               pVolumeSurface2->cutVolume());
}

void cmdCivilVolumeSurfaceBounded()
{
    const double SURFACE_SIZE = 10;
    AcGePoint3dArray roofShapedPoints;
    roofShapedPoints.append(AcGePoint3d(-SURFACE_SIZE, -SURFACE_SIZE, 0));
    roofShapedPoints.append(AcGePoint3d(0,-SURFACE_SIZE, SURFACE_SIZE));
    roofShapedPoints.append(AcGePoint3d(SURFACE_SIZE, -SURFACE_SIZE, 0));
    roofShapedPoints.append(AcGePoint3d(SURFACE_SIZE, SURFACE_SIZE, 0));
    roofShapedPoints.append(AcGePoint3d(0, SURFACE_SIZE, SURFACE_SIZE));
    roofShapedPoints.append(AcGePoint3d(-SURFACE_SIZE, SURFACE_SIZE, 0));

    AcGePoint3dArray flatPoints;
    flatPoints.append(AcGePoint3d(-SURFACE_SIZE, -SURFACE_SIZE, SURFACE_SIZE/2));
    flatPoints.append(AcGePoint3d(0, -SURFACE_SIZE, SURFACE_SIZE/2));
    flatPoints.append(AcGePoint3d(SURFACE_SIZE, -SURFACE_SIZE, SURFACE_SIZE/2));
    flatPoints.append(AcGePoint3d(SURFACE_SIZE, SURFACE_SIZE, SURFACE_SIZE/2));
    flatPoints.append(AcGePoint3d(0, SURFACE_SIZE, SURFACE_SIZE/2));
    flatPoints.append(AcGePoint3d(-SURFACE_SIZE, SURFACE_SIZE, SURFACE_SIZE/2));

    AcDbObjectPointer<AcDbCivilTinSurface> pSurface; pSurface.create();
    AcDbObjectPointer<AcDbCivilTinSurface> pFlatSurface; pFlatSurface.create();
    if (!pSurface || !pFlatSurface)
    {
        acutPrintf(L"Failed to create sample surface.\n");
        return;
    }
    pSurface->initialize(AcGePoint3d(-10, 0, 0), AcGePoint3d(10, 10, 10), roofShapedPoints.length());
    pSurface->addPoints(roofShapedPoints);
    pFlatSurface->initialize(AcGePoint3d(-10, 0, 0), AcGePoint3d(10, 10, 10), flatPoints.length());
    pFlatSurface->addPoints(flatPoints);

    AcDbObjectId surfaceId, flatSurfaceId;
    addEntityToModelSpace(pSurface, surfaceId, false);
    addEntityToModelSpace(pFlatSurface, flatSurfaceId, false);

    AcDbObjectPointer<AcDbCivilTinVolumeSurface> pVolumeSurface1; pVolumeSurface1.create();
    AcDbObjectPointer<AcDbCivilTinVolumeSurface> pVolumeSurface2; pVolumeSurface2.create();

    //Bound the volume calculation to the upper left quarter of the created surface
    {
        AcGePoint3dArray boundaryNDBR;
        boundaryNDBR.append(AcGePoint3d(-SURFACE_SIZE, 0, 0));
        boundaryNDBR.append(AcGePoint3d(0, 0, 0));
        boundaryNDBR.append(AcGePoint3d(0, SURFACE_SIZE, 0));
        boundaryNDBR.append(AcGePoint3d(-SURFACE_SIZE, SURFACE_SIZE, 0));

        /*
            Calculates the volume between the pSurface and the pFlatSurface bounded by the
            array of points passed in (visually only the upper left quarter of the pSurface).
        */
        pVolumeSurface1->initialize(pSurface, pFlatSurface, boundaryNDBR);
    }

    //Bound the volume calculation to the right half of the created surface
    {
        AcDbObjectId polylineId;
        AcDbObjectPointer<AcDbPolyline> pPolyline; pPolyline.create();
        pPolyline->addVertexAt(0, AcGePoint2d(0, -SURFACE_SIZE));
        pPolyline->addVertexAt(1, AcGePoint2d(SURFACE_SIZE, -SURFACE_SIZE));
        pPolyline->addVertexAt(2, AcGePoint2d(SURFACE_SIZE, SURFACE_SIZE));
        pPolyline->addVertexAt(3, AcGePoint2d(0, SURFACE_SIZE));
        pPolyline->setClosed(true);
        Acad::ErrorStatus es = addEntityToModelSpace(pPolyline, polylineId, true);
        if (es != Acad::eOk)
        {
            acutPrintf(L"Failed to add polyline to model space\n");
            return;
        }

        /*
            Calculates the volume between the pSurface and the XY plane with elevation 0 bounded by the 
            polylineId (visually only the right half of the pSurface).
        */
        pVolumeSurface2->initialize(pSurface, 0.0, ETinVolumeSurfaceType::eTinVolumeToElevation, polylineId, 0.1);
    }

    const double fillVolume1 = pVolumeSurface1->fillVolume();
    const double cutVolume1 = pVolumeSurface1->cutVolume();
    const double fillVolume2 = pVolumeSurface2->fillVolume();
    const double cutVolume2 = pVolumeSurface2->cutVolume();

    acutPrintf(L"Fill/cut of pVolumeSurface1: %f, %f.\n", fillVolume1, cutVolume1);
    acutPrintf(L"Fill/cut of pVolumeSurface2: %f, %f.\n", fillVolume2, cutVolume2);
}


class MySurfaceJig : public AcEdJig
{
public:

    MySurfaceJig(AcDbCivilTinSurface* pBaseSurface,
                 const AcGePoint3dArray& outerPolygon,
                 const AcGePoint3dArray& innerPolygon) :
        m_pBaseSurface(pBaseSurface)
    {
        m_elevation = outerPolygon.at(0).z;

        m_innerPoints = m_pBaseSurface->getPointsInsidePolygon(innerPolygon, true);

        AcArray<AcGePoint3dArray> drapedInnerPolygon;
        m_pBaseSurface->drape(drapedInnerPolygon, innerPolygon);
        for (const auto& drapedPolygonPoints : drapedInnerPolygon)
            m_innerPoints.append(drapedPolygonPoints);

        AcArray<AcGePoint3dArray> drapedOuterPolygon;
        m_pBaseSurface->drape(drapedOuterPolygon, outerPolygon);
        for (const auto& drapedPolygonPoints : drapedOuterPolygon)
            m_outerPoints.append(drapedPolygonPoints);

        m_pJigSurface.create();
        m_pJigSurface->setDatabaseDefaults(
            acdbHostApplicationServices()->workingDatabase());
        m_pJigSurface->addPoints(m_innerPoints);
        m_pJigSurface->addPoints(m_outerPoints);
        m_pJigSurface->setColorIndex(1);
        m_pJigSurface->setStyle(ETinSurfaceStyle::eTinStyleTriangles);
        m_pJigSurface->updateObjectData();

        TinSurfaceConstraint outerBreakline = TinSurfaceBreakline(ETinBreaklineType::eTinBreaklineNomal);
        TinSurfaceConstraint innerBreakline = TinSurfaceBreakline(ETinBreaklineType::eTinBreaklineNomal);
        outerBreakline.setData(154535, outerPolygon);
        innerBreakline.setData(154537, innerPolygon);


        TinSurfaceConstraint constraint = TinSurfaceBoundary(ETinBoundaryType::eTinHide);
        constraint.setData(465869, m_outerPoints);

        if (!m_pBaseSurface->isWriteEnabled())
            m_pBaseSurface->upgradeOpen();
        assert(m_pBaseSurface->isWriteEnabled());
        m_pBaseSurface->addConstraint(constraint);
        m_pBaseSurface->downgradeOpen();
    }

    virtual ~MySurfaceJig()
    {
    }

    AcDbCivilTinSurface* getJigSurfacePtr()
    {
        return m_pJigSurface;
    }

protected:

    virtual AcDbEntity* entity() const
    {
        return m_pJigSurface;
    }

    virtual Adesk::Boolean update()
    {
        AcGeDoubleArray newElevations;
        newElevations.setLogicalLength(m_innerPoints.length());
        newElevations.setAll(m_elevation);
        m_pJigSurface->changePointsElevations(m_innerPoints, newElevations);
        m_pJigSurface->updateObjectData();
        return true;
    }

    virtual DragStatus sampler()
    {
        setUserInputControls(static_cast<UserInputControls>(kAccept3dCoordinates));
        AcGePoint3d point;
        DragStatus status = acquirePoint(point);

        AcDbViewportTableRecordPointer pVTR(getActiveViewportTableRecordId(), AcDb::kForRead);
        if (pVTR == nullptr)
            return DragStatus::kCancel;

        //simply get some height
        const AcGeMatrix3d& worldToEye = worldToViewport(pVTR);
        auto p1 = AcGePoint3d(0, 0, 0).transformBy(worldToEye);
        m_elevation = point.y - p1.y;

        return status;
    }

    double m_elevation;
    AcDbCivilTinSurface* m_pBaseSurface;
    mutable AcDbObjectPointer<AcDbCivilTinSurface> m_pJigSurface;
    AcGePoint3dArray m_innerPoints;
    AcGePoint3dArray m_outerPoints;
};

void cmdCivilSurfaceJig()
{
    Acad::ErrorStatus es = Acad::eOk;

    const int NUMBER_OF_POINTS = 1000;
    const double SURFACE_SIZE = 200;
    const double SURFACE_ELEVATION = 300;
    const double ELEVATION_VAR = 3;

    AcDbObjectPointer<AcDbCivilTinSurface> pSurface; pSurface.create();
    pSurface->setDatabaseDefaults(
        acdbHostApplicationServices()->workingDatabase());
    pSurface->initialize(AcGePoint3d(-SURFACE_SIZE, -SURFACE_SIZE, 0.0),
                         AcGePoint3d(SURFACE_SIZE, SURFACE_SIZE, 0.0),
                         NUMBER_OF_POINTS);

    std::uniform_real_distribution<double> xyDistrib(-SURFACE_SIZE, SURFACE_SIZE);
    std::uniform_real_distribution<double> elevDistrib(SURFACE_ELEVATION, SURFACE_ELEVATION + ELEVATION_VAR);
    std::default_random_engine randGen;

    AcGePoint3dArray points(NUMBER_OF_POINTS, 100);
    for (size_t i = 0; i < NUMBER_OF_POINTS; ++i)
        points.append(AcGePoint3d(xyDistrib(randGen), xyDistrib(randGen), elevDistrib(randGen)));
    pSurface->addPoints(points);
    
    AcDbObjectId surfaceId;
    es = addEntityToModelSpace(pSurface, surfaceId, false);
    if (es != Acad::eOk)
        return;

    //Create outer polygon
    AcGePoint3dArray outerPolygon;
    const double OUTER_POLY_SIZE = 50.0;
    const double POLY_HEIGHT = 330;
    outerPolygon.append(AcGePoint3d(-OUTER_POLY_SIZE, -OUTER_POLY_SIZE, POLY_HEIGHT));
    outerPolygon.append(AcGePoint3d(OUTER_POLY_SIZE, -OUTER_POLY_SIZE, POLY_HEIGHT));
    outerPolygon.append(AcGePoint3d(OUTER_POLY_SIZE, OUTER_POLY_SIZE, POLY_HEIGHT));
    outerPolygon.append(AcGePoint3d(-OUTER_POLY_SIZE, OUTER_POLY_SIZE, POLY_HEIGHT));
    outerPolygon.append(AcGePoint3d(-OUTER_POLY_SIZE, -OUTER_POLY_SIZE, POLY_HEIGHT));

    //Create inner polygon
    const double INNER_POLY_SIZE = 40.0;
    AcGePoint3dArray innerPolygon;
    innerPolygon.append(AcGePoint3d(-INNER_POLY_SIZE, -INNER_POLY_SIZE, POLY_HEIGHT));
    innerPolygon.append(AcGePoint3d(INNER_POLY_SIZE, -INNER_POLY_SIZE, POLY_HEIGHT));
    innerPolygon.append(AcGePoint3d(INNER_POLY_SIZE, INNER_POLY_SIZE, POLY_HEIGHT));
    innerPolygon.append(AcGePoint3d(-INNER_POLY_SIZE, INNER_POLY_SIZE, POLY_HEIGHT));
    innerPolygon.append(AcGePoint3d(-INNER_POLY_SIZE, -INNER_POLY_SIZE, POLY_HEIGHT));

    //adjust the view
    {
        AcDbViewportTableRecordPointer pVTR(getActiveViewportTableRecordId(), AcDb::kForWrite);
        if (pVTR == nullptr)
            return;
        pVTR->setPerspectiveEnabled(false);
        pVTR->setViewDirection(AcGeVector3d(0.6, -0.6, 0.3));
        pVTR->setTarget(AcGePoint3d(0, 0, SURFACE_ELEVATION));
        const AcGeMatrix3d& worldToEye = worldToViewport(pVTR);

        AcGePoint3d minPtEye = AcGePoint3d(-SURFACE_SIZE, -SURFACE_SIZE, SURFACE_ELEVATION).transformBy(worldToEye);
        AcGePoint3d maxPtEye = AcGePoint3d(SURFACE_SIZE, SURFACE_SIZE, SURFACE_ELEVATION).transformBy(worldToEye);

        pVTR->setWidth(2.5 * (maxPtEye.x - minPtEye.x));
        pVTR->setCenterPoint(AcGePoint2d((maxPtEye.x + minPtEye.x) / 2.0, (maxPtEye.y + minPtEye.y) / 2.0));
    }

    MySurfaceJig surfaceJigger(pSurface, outerPolygon, innerPolygon);
    AcEdJig::DragStatus stat = surfaceJigger.drag();
    if (stat == AcEdJig::kNormal && surfaceJigger.getJigSurfacePtr() != nullptr)
    {
        bool merge = true;
        if (merge)
        {
            if (!pSurface->isWriteEnabled())
                pSurface->upgradeOpen();
            pSurface->merge(surfaceJigger.getJigSurfacePtr());
            pSurface->downgradeOpen();
        }
        else
        {
            es = addEntityToModelSpace(surfaceJigger.getJigSurfacePtr(), surfaceId, false);
        }
    }
}
