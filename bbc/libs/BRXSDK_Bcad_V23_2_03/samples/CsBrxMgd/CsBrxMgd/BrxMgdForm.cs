using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;


//ODA
using Teigha.Runtime;
using Teigha.DatabaseServices;
using Teigha.Geometry;

//Bricsys
using Bricscad.ApplicationServices;

//com
using BricscadDb;
using BricscadApp;

// alias
using _AcAp = Bricscad.ApplicationServices;
using _AcDb = Teigha.DatabaseServices;
using _AcGe = Teigha.Geometry;
using _AcEd = Bricscad.EditorInput;

namespace CsBrxMgd
{
    public partial class BrxMgdForm : Form
    {
        AcadDocument m_document;
        public BrxMgdForm(AcadDocument document)
        {
            if (document == null)
                throw new System.ArgumentNullException("document == null");
            InitializeComponent();
            m_document = document;
        }

        private void select_Click(object sender, EventArgs e)
        {
            _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
            try
            {
                _AcEd.PromptPointOptions pntOpt = new _AcEd.PromptPointOptions("Get First Point");
                _AcEd.PromptPointResult pntRes = editor.GetPoint(pntOpt);

                if (pntRes.Status != Bricscad.EditorInput.PromptStatus.OK)
                    throw new System.Exception("_AcEd.Editor.GetPoint failed");

                _AcEd.PromptDistanceOptions distOpt = new _AcEd.PromptDistanceOptions("Get Next Point");
                distOpt.UseBasePoint = true;
                distOpt.BasePoint = pntRes.Value;
                _AcEd.PromptDoubleResult distRes = editor.GetDistance(distOpt);

                if (distRes.Status != Bricscad.EditorInput.PromptStatus.OK)
                    throw new System.Exception("_AcEd.Editor.GetDistance failed");

                System.Windows.Forms.MessageBox.Show(distRes.ToString());
            }
            catch (System.Exception ex)
            {
                System.Windows.Forms.MessageBox.Show(ex.Message);
            }
        }

        private void buttonSelectEnt_Click(object sender, EventArgs e)
        {
            try
            {
                _AcEd.Editor editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor;
                _AcEd.PromptEntityResult pres = editor.GetEntity("Select Entity");
                System.Windows.Forms.MessageBox.Show(pres.ToString());
            }
            catch
            {
                System.Windows.Forms.MessageBox.Show("Selection Failed");
            }
        }

    }
}