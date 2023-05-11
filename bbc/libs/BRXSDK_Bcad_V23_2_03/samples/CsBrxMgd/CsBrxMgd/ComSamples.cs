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

// com
using BricscadDb;
using BricscadApp;

// alias
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;

namespace CsBrxMgd
{
    public class ComSamples
    {
        public static void do_performanceTest()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            Stopwatch sw = Stopwatch.StartNew();
            AcadApplication app = Application.AcadApplication as AcadApplication;
            if (app == null)
                throw new NullReferenceException("Could Not Get Application");

            int count = 0;
            foreach (AcadEntity X in app.ActiveDocument.ModelSpace)
            {
                count++;
            }
            editor.WriteMessage("\n{0} Entities found in {1} Milliseconds", count, sw.ElapsedMilliseconds);
        }

        public static void do_comSSet()
        {
            Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            Database database = HostApplicationServices.WorkingDatabase;
            _AcDb.TransactionManager manager = database.TransactionManager;
            using (Transaction action = manager.StartTransaction())
            {
                ObjectIdCollection idset = ComSamples.ComSelectionSet(new object[] { "POINT,LINE,CIRCLE,INSERT" });
                foreach (ObjectId id in idset)
                {
                    Entity ent = action.GetObject(id, OpenMode.ForWrite) as Entity;
                    if (ent != null)
                        ent.Layer = "0";
                }
                action.Commit();
            }
        }

        //using COM with wrappers
        public static ObjectIdCollection ComSelectionSet(object[] filter)
        {

            AcadApplication application = _AcAp.Application.AcadApplication as AcadApplication;
            if (application == null)
                throw new System.Exception("Could Not Get Application");

            ObjectIdCollection setids = new ObjectIdCollection();
            AcadSelectionSet selection = application.ActiveDocument.SelectionSets.Add("samp04Set");
            try
            {
                selection.SelectOnScreen(new int[] { 0 }, filter);
                foreach (AcadObject obj in selection)
                    setids.Add(new ObjectId((IntPtr)obj.ObjectID));
            }
            finally
            {
                selection.Delete();
            }
            return setids;
        }
    }
}
