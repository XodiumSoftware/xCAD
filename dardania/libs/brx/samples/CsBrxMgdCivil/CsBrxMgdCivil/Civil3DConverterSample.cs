// Property of Bricsys NV. All rights reserved.
// This file is part of the BRX SDK, and its use is subject to the terms
// of the BRX SDK license agreement.
/////////////////////////////////////////////////////////////////////////

// system
using System;
using System.Text;
using System.Diagnostics;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.IO;

// ODA
using Teigha.Runtime;
using Teigha.DatabaseServices;
using Teigha.Geometry;

// Bricsys
using Bricscad.ApplicationServices;
using Bricscad.Runtime;
using Bricscad.EditorInput;

// alias
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;
using _AcCiv = Bricscad.Civil;

namespace CsBrxMgdCivil
{
    public class Civil3DConverterSample
    {
        public static void do_civil3DConvertAll()
        {
            _AcAp.Document doc = _AcAp.Application.DocumentManager.MdiActiveDocument;
            _AcEd.Editor ed = doc.Editor;
            _AcDb.Database curDb = doc.Database;
            //initialize constructor with source database
            //all supported Civil3D entities in source database will be converted
            //there is also possibility to convert only selected enitities 
            //by passing ObjectId or ObjectIdCollection to constructor
            _AcCiv.Civil3DConverter convC3D = new _AcCiv.Civil3DConverter(curDb);

            //should labels be converted to blocks
            //combine different options
            convC3D.ConversionOptions = _AcCiv.Civil3DConversionOptions.ConvertAllLabels;
            //this option will convert alignment labels and surface labels
            //convC3D.ConversionOptions = _AcCiv.Civil3DConversionOptions.ConvertSurfaceLabels |
            //    _AcCiv.Civil3DConversionOptions.ConvertAlignmentLabels;

            //convert supported elements to destination database
            //in results are only succesfully converted entities
            var results = convC3D.Convert(curDb);
            using (_AcDb.Transaction tx = doc.TransactionManager.StartTransaction())
            {
                foreach (_AcCiv.Civil3DConversion conv in results)
                {
                    if (conv.Source.Id.IsNull)
                        continue;
                    //if conv.Source is AECC_PROFILE conv.Source.Relatives are baseAlignment() and baseSurface()
                    //if conv.Source is AECC_ALIGNMENT conv.Source.Relatives are its profiles
                    if (conv.Source.Relatives != null)
                    {
                        foreach (var relative in conv.Source.Relatives)
                        {
                            if (conv.Source.Id.ObjectClass.DxfName == "AECC_PROFILE" &&
                                relative.Id.ObjectClass.DxfName == "AECC_ALIGNMENT")
                            {
                                ed.WriteMessage(string.Format("\nProfile {0} has parent Alignment with handle {1}.",
                                    conv.Source.Name, relative.Id.Handle.ToString()));
                            }
                        }
                    }
                    //check result entities
                    //if converted element is horizontal alignment get length
                    //if converted element is tin surface get number of points
                    //if converted element is alignment vertical view get base elevation
                    //if converted element is vertical alignment get its elements count
                    foreach (ObjectId id in conv.Result)
                    {
                        if (!id.IsValid)
                            continue;
                        var entity = id.GetObject(OpenMode.ForRead) as _AcDb.Entity;
                        if (entity == null)
                            continue;
                        if (entity.GetType() == typeof(_AcCiv.AlignmentHorizontal))
                        {
                            var alignment = entity as _AcCiv.AlignmentHorizontal;
                            var lengthOfAlignment = alignment.Length;
                            ed.WriteMessage(string.Format("\nLength of Alignment {0} is {1}.", alignment.Name, lengthOfAlignment));
                        }
                        else if (entity.GetType() == typeof(_AcCiv.TinSurface))
                        {
                            var tinSurface = entity as _AcCiv.TinSurface;
                            var numberOfSurfacePoints = tinSurface.GetGeneralProperties(false).NumberOfPoints;
                            ed.WriteMessage(string.Format("\nTinSurface {0} has {1} points.", tinSurface.Name, numberOfSurfacePoints));
                        }
                        else if (entity.GetType() == typeof(_AcCiv.AlignmentViewVertical))
                        {
                            var verticalView = entity as _AcCiv.AlignmentViewVertical;
                            var baseElevation = verticalView.BaseElevation;
                            ed.WriteMessage(string.Format("\nVerticalView {0} base elevation is {1}.", verticalView.Name, baseElevation));
                        }
                        else if (entity.GetType() == typeof(_AcCiv.AlignmentVertical))
                        {
                            var verticalAlignment = entity as _AcCiv.AlignmentVertical;
                            var elementCount = verticalAlignment.VAElementCount;
                            ed.WriteMessage(string.Format("\nVerticalAlignment {0} has {1} elements.", verticalAlignment.Name, elementCount));
                        }
                    }

                }
                tx.Commit();
            }
        }
    }
}
