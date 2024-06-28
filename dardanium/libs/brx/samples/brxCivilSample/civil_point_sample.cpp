// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"

#include "civil_point_sample.h"
#include "civil_utils.h"

#include "BrxSpecific/civil/BrxCvDbPoint.h"
#include "BrxSpecific/civil/BrxCvDbPointGroupManager.h"
#include "BrxSpecific/civil/BrxCvDbStyleManager.h"

void cmdCivilPointsWorkflow()
{
    //This sample assumes the current database is 'empty'
    AcDbObjectId pointId;
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    //Create points
    {
        AcDbObjectPointer<BrxCvDbPoint> point1;
        point1.create();
        assert(0 == point1->number());
        point1->setDatabaseDefaults(pDb); //Sets the default label and symbol style.
        point1->setEasting(-50);
        point1->setNorthing(-50);
        point1->setElevation(-50);
        point1->setName(_T("firstpoint"));
        addEntityToModelSpace(point1, pointId, false);
        assert(1 == point1->number()); //Point number is set when added to the database (0 is a reserved value)

    }
    {
        AcDbObjectPointer<BrxCvDbPoint> point2;
        point2.create();
        assert(0 == point2->number());
        point2->setDatabaseDefaults(pDb); //Sets the default label and symbol style.
        point2->setEasting(-60);
        point2->setNorthing(-60);
        point2->setElevation(-60);
        point2->setName(_T("point2"));
        addEntityToModelSpace(point2, pointId, false);
        assert(2 == point2->number()); //Because point number 1 is already taken, the next available point number is used.
    }
    {
        for (Adesk::UInt32 i = 10; i < 108; i++)
        {
            AcDbObjectPointer<BrxCvDbPoint> point;
            point.create();
            point->setNumber(i);
            AcString pointName;
            pointName.format(_T("point%03u"), i); //point010, point011, ..., point108
            point->setName(pointName.constPtr());
            point->setDatabaseDefaults(pDb); //Sets the default label and symbol style.
            point->setEasting(-55.0 + 2 * cos(0.2 * i) * i);
            point->setNorthing(-55.0 + 2 * sin(0.2 * i) * i);
            point->setElevation((double)i);
            addEntityToModelSpace(point, pointId, false);
            assert(i == point->number());
        }
    }

    //Point groups and manager
    {
        AcDbObjectId managerId;
        BrxCvDbPointGroupManager::getManager(managerId, pDb, false);
        AcDbObjectPointer<BrxCvDbPointGroupManager> manager(managerId, AcDb::kForWrite);
        assert(manager);
        if (manager == nullptr)
            return;
        assert(1 == manager->elementCount()); //By default only '_All points' group is present
        AcDbObjectId groupAllPointsId = manager->idAt(_T("_All points"));
        AcDbObjectPointer<BrxCvDbPointGroup> groupAllPoints(groupAllPointsId);
        assert(groupAllPoints);
        if (groupAllPoints == nullptr)
            return;
        assert(100 == groupAllPoints->pointCount()); //There were 3 points created

        AcDbObjectId groupNewId = manager->createPointGroup(_T("NewPointGroup"));
        AcDbObjectPointer<BrxCvDbPointGroup> groupNew(groupNewId, AcDb::kForWrite);
        assert(0 == groupNew->pointCount());

        //Current filters support two types of checking, a numerical filter and string comparsion filter
        //Valid wildcard tokens for numerical filering are: '-' a range of values (inclusive), '>=', '<=', '>', '<', '!='
        //Valid wildcard tokens for string filtering are: '*', '?'
        // '*' - matches any character multiple times
        // '?' - matches any character 0 or 1 time
        //Multiple conditions can be specified using ',' (comma).

        //Setup some filters for the new point group
        groupNew->setIncludeNumbers(_T("1-200")); //This means include all points with numbers from 1 to 200 (inclusive).
        groupNew->update();
        assert(100 == groupNew->pointCount());
        //Multiple conditions are sparated by a comma. The next filter will exclude points 1,2 and all point numbers greater than 100
        groupNew->setExcludeNumbers(_T("1,2,>=100"));
        groupNew->update();
        assert(90 == groupNew->pointCount());
        //reset the filter
        groupNew->setExcludeNumbers(_T(""));
        groupNew->update();
        assert(100 == groupNew->pointCount());
        //Will exclude any point whose name ends in 'point';
        //Will also exclude any point with a name that starts with 'point' followed by 0,1 or 2 random characters followed by a '2'
        groupNew->setExcludeNames(_T("*point,point??2"));
        groupNew->update();
        assert(89 == groupNew->pointCount());
    }

    //Point styles
    {
        AcDbObjectId managerId;
        BrxCvDbPointGroupManager::getManager(managerId, pDb, false);
        AcDbObjectPointer<BrxCvDbPointGroupManager> manager(managerId, AcDb::kForWrite);

        AcDbObjectId groupBelow30Id = manager->createPointGroup(_T("groupBelow30Elev"));
        AcDbObjectPointer<BrxCvDbPointGroup> groupBelow30(groupBelow30Id, AcDb::kForWrite);
        groupBelow30->setIncludeElevations(_T("<30.0"));
        groupBelow30->update();

        //Set the label style for points below 30 elevation
        AcDbObjectId labelStyleManagerId;
        //Retrieving manager id is similar to the one for point groups.
        BrxCvDbPointLabelStyleManager::getManager(labelStyleManagerId, pDb, true);
        //There is also a 'BrxCvDbSymbolStyleManager' that holds styles which define the point's graphics at it's insertion spot
        AcDbObjectPointer<BrxCvDbPointLabelStyleManager> labelStyleManager(labelStyleManagerId);
        if (labelStyleManager == nullptr)
            return;
        for (Adesk::UInt32 i = 0; i < labelStyleManager->elementCount(); i++)
        {
            AcDbObjectPointer<BrxCvDbObject> style(labelStyleManager->idAt(i), AcDb::kForRead);
            assert(style);
            acutPrintf(_T("Point Label style %u is named: %s  | Description: %s\n"),
                       i, labelStyleManager->nameAt(i), style->description());
        }
        AcDbObjectId labelStyleId = labelStyleManager->idAt(_T("Below30PointLabelStyle"));
        //Either label style with such name exists or we get a kNull id. Both is fine to set later.
        const AcDbObjectIdArray ids = groupBelow30->pointIds();
        for (const AcDbObjectId& id : ids)
        {
            AcDbObjectPointer<BrxCvDbPoint> point(id, AcDb::kForWrite);
            if (point == nullptr)
                continue;
            point->setLabelId(labelStyleId);
        }
    }
}
