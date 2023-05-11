Imports System
Imports System.ComponentModel
Imports System.Drawing
Imports System.Runtime.InteropServices
Imports System.Windows.Forms

' ODA
Imports Teigha.Runtime
Imports Teigha.DatabaseServices
Imports Teigha.Geometry

' Bricsys
Imports Bricscad.ApplicationServices
Imports Bricscad.Runtime
Imports Bricscad.EditorInput


' com
Imports BricscadDb
Imports BricscadApp

' alias
Imports _AcRx = Teigha.Runtime
Imports _AcAp = Bricscad.ApplicationServices
Imports _AcDb = Teigha.DatabaseServices
Imports _AcGe = Teigha.Geometry
Imports _AcEd = Bricscad.EditorInput
Imports _AcGi = Teigha.GraphicsInterface
Imports _AcClr = Teigha.Colors
Imports _AcWnd = Bricscad.Windows

Namespace CsBrxMgd
    Partial Public Class BrxMgdForm
        Inherits Form
        Private m_document As AcadDocument
        Public Sub New(ByVal document As AcadDocument)
            If (document Is Nothing) Then
                Throw New ArgumentNullException("document == null")
            End If
            InitializeComponent()
            Me.m_document = document
        End Sub

        Private Sub buttonSelectEnt_Click(ByVal sender As Object, ByVal e As EventArgs) Handles buttonDist.Click
            Try

                MessageBox.Show(_AcAp.Application.DocumentManager.MdiActiveDocument.Editor.GetEntity("Select Entity").ToString)

            Catch ex As System.Exception
                MessageBox.Show("Selection Failed")
            End Try
        End Sub

        Private Sub select_Click(ByVal sender As Object, ByVal e As EventArgs) Handles buttonSelectEnt.Click
            Dim editor As Editor = _AcAp.Application.DocumentManager.MdiActiveDocument.Editor
            Try
                Dim pntOpt As New PromptPointOptions("Get First Point")
                Dim pntRes As PromptPointResult = editor.GetPoint(pntOpt)
                If (pntRes.Status <> PromptStatus.OK) Then
                    Throw New System.Exception("_AcEd.Editor.GetPoint failed")
                End If
                Dim distOpt As New PromptDistanceOptions("Get Next Point")
                distOpt.UseBasePoint = True
                distOpt.BasePoint = pntRes.Value
                Dim distRes As PromptDoubleResult = editor.GetDistance(distOpt)
                If (distRes.Status <> PromptStatus.OK) Then
                    Throw New System.Exception("_AcEd.Editor.GetDistance failed")
                End If
                MessageBox.Show(distRes.ToString)
            Catch ex As System.Exception
                MessageBox.Show(ex.Message)
            End Try
        End Sub

    End Class
End Namespace

