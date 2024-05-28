// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// system
using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;

// ODA
using Teigha.Runtime;
using Teigha.Geometry;

// Bricsys
using Bricscad.ApplicationServices;
using Bricscad.Runtime;
using Bricscad.EditorInput;
using Bricscad.Civil;
using Bricscad.CivilExtensions;

// alias
using _AcRx = Teigha.Runtime;
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;
using _AcCiv = Bricscad.Civil;
using System.Runtime.CompilerServices;

namespace CsBrxMgdCivil
{
    class PointSample
    {
        public static void do_PointWorkflow()
        {
            //This sample assumes the current database is 'empty'
            _AcDb.Database db = _AcDb.HostApplicationServices.WorkingDatabase;
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;

            using (_AcDb.Transaction tr = db.TransactionManager.StartTransaction())
            {
                _AcDb.BlockTable blockTable = tr.GetObject(db.BlockTableId, _AcDb.OpenMode.ForRead) as _AcDb.BlockTable;
                _AcDb.BlockTableRecord btr = tr.GetObject(blockTable[_AcDb.BlockTableRecord.ModelSpace], _AcDb.OpenMode.ForWrite) as _AcDb.BlockTableRecord;

                //Create points
                {
                    _AcCiv.Point point1 = new _AcCiv.Point();
                    Trace.Assert(0 == point1.PointNumber, "Point number is 0 by default");
                    point1.SetDatabaseDefaults(db); //Sets the default symbol and label style
                    point1.Easting = -50;
                    point1.Northing = -50;
                    point1.Elevation = -50;
                    point1.Name = "firstpoint";
                    btr.AppendEntity(point1);
                    tr.AddNewlyCreatedDBObject(point1, true);
                    Trace.Assert(1 == point1.PointNumber, "Point number should be 1 here"); //Point number is set when added to the database (0 is a reserved value)
                }
                {
                    _AcCiv.Point point2 = new _AcCiv.Point();
                    Trace.Assert(0 == point2.PointNumber, "Point number is 0 by default");
                    point2.SetDatabaseDefaults(db); //Sets the default symbol and label style
                    point2.Easting = -60;
                    point2.Northing = -60;
                    point2.Elevation = -60;
                    point2.Name = "point2";
                    btr.AppendEntity(point2);
                    tr.AddNewlyCreatedDBObject(point2, true);
                    Trace.Assert(2 == point2.PointNumber, "Point number should be 2 here"); //Because point number 1 is already taken, the next available point number is used.
                }

                for (uint i = 10; i < 108; i++)
                {
                    _AcCiv.Point point = new _AcCiv.Point();
                    point.SetDatabaseDefaults(db); //Sets the default symbol and label style
                    point.PointNumber = i;
                    point.Easting = -55.0 + 2 * Math.Cos(0.2 * i) * i;
                    point.Northing = -55.0 + 2 * Math.Sin(0.2 * i) * i;
                    point.Elevation = i;
                    point.Name = "point" + i.ToString("D3");
                    btr.AppendEntity(point);
                    tr.AddNewlyCreatedDBObject(point, true);
                    Trace.Assert(i == point.PointNumber, "Point number should be equal to i");
                }

                //Point groups and manager
                _AcDb.ObjectId managerId = db.GetCivilPointGroupManager(true);
                Trace.Assert(!managerId.IsNull, "Manager id should not be null");
                _AcCiv.PointGroupManager mgr = tr.GetObject(managerId, _AcDb.OpenMode.ForWrite) as _AcCiv.PointGroupManager;
                Trace.Assert(1 == mgr.ElementCount, "By default there should be only one point group '_All points'.");
                _AcCiv.PointGroup groupAllPoints = tr.GetObject(mgr.Find("_All points"), _AcDb.OpenMode.ForRead) as _AcCiv.PointGroup;
                Trace.Assert(groupAllPoints != null, "gropuAllPoints not opened");
                Trace.Assert(100 == groupAllPoints.PointCount, "_All points always contains all the existing points in MS");

                _AcDb.ObjectId groupNewId = mgr.Create("NewPointGroup");
                _AcCiv.PointGroup groupNew = tr.GetObject(groupNewId, _AcDb.OpenMode.ForWrite) as _AcCiv.PointGroup;
                Trace.Assert(0 == groupNew.PointCount, "Newly created groups are empty by default");

                //Current filters support two types of checking, a numerical filter and string comparsion filter
                //Valid wildcard tokens for numerical filering are: '-' a range of values (inclusive), '>=', '<=', '>', '<', '!='
                //Valid wildcard tokens for string filtering are: '*', '?'
                // '*' - matches any character multiple times
                // '?' - matches any character 0 or 1 time
                //Multiple conditions can be specified using ',' (comma).

                //Setup some filters for the new point group
                groupNew.IncludeNumbers = "1-200"; //This means include all points with numbers from 1 to 200 (inclusive).
                groupNew.Update();
                Trace.Assert(100 == groupNew.PointCount, "groupNew should now contain all the points with numbers from 1-200");

                //Multiple conditions are sparated by a comma. The next filter will exclude points 1,2 and all point numbers greater than 100
                groupNew.ExcludeNumbers = "1,2,>=100";
                groupNew.Update();
                Trace.Assert(90 == groupNew.PointCount, "groupNew should now contain all the points with numbers from 1-200 and excluding 1,2 and everything above 100");

                //reset the filter
                groupNew.ExcludeNumbers = "";
                groupNew.Update();
                Trace.Assert(100 == groupNew.PointCount, "groupNew should now contain all the points with numbers from 1-200");

                //Will exclude any point whose name ends in 'point';
                //Will also exclude any point with a name that starts with 'point' followed by 0,1 or 2 random characters followed by a '2'
                groupNew.ExcludeNames = "*point,point??2";
                groupNew.Update();
                Trace.Assert(89 == groupNew.PointCount, "groupNew now contain 89 points");


                //
                //Point styles
                //Symbol manager - holds styles that define the graphics at 'insertion' point of some entities
                _AcCiv.StyleManager symbolStyleManager = tr.GetObject(db.GetCivilSymbolStylesManager(true), _AcDb.OpenMode.ForRead) as _AcCiv.StyleManager;
                Trace.Assert(1 <= symbolStyleManager.ElementCount, "There should be at least one default style present");
                //Point label style manager - holds styles that define the graphics for labeling part of points
                _AcCiv.StyleManager labelStyleManager = tr.GetObject(db.GetCivilPointLabelStylesManager(true), _AcDb.OpenMode.ForRead) as _AcCiv.StyleManager;
                editor.WriteMessage("Existing point label styles:");
                foreach (_AcDb.ObjectId id in labelStyleManager.Ids)
                {
                    _AcCiv.CivilObjectBase style = tr.GetObject(id, _AcDb.OpenMode.ForRead) as _AcCiv.CivilObjectBase;
                    Trace.Assert(style != null, "Style should not be null");
                    editor.WriteMessage("\n" + style.Name);
                }

                _AcDb.ObjectId groupBelow30Id = mgr.Create("groupBelow30Elev");
                _AcCiv.PointGroup groupBelow30 = tr.GetObject(groupBelow30Id, _AcDb.OpenMode.ForWrite) as _AcCiv.PointGroup;
                groupBelow30.IncludeElevations = "<30.0";
                groupBelow30.Update();

                //Either we find some style or we use null style, both is fine to set.
                _AcDb.ObjectId below30ElevStyleId = labelStyleManager.Find("Below30PointLabelStyle");
                //Set the label style for all the points below 30 elevation
                foreach (_AcDb.ObjectId id in groupBelow30.Points)
                {
                    _AcCiv.Point point = tr.GetObject(id, _AcDb.OpenMode.ForWrite) as _AcCiv.Point;
                    Trace.Assert(point != null, "Point should not be null.");
                    point.LabelStyle = below30ElevStyleId;
                }

                tr.Commit();
            }
        }


    }
}
