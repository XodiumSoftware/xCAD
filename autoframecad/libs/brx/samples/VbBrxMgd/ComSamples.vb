'// Property of Bricsys NV. All rights reserved.
'// This file Is part of the BRX SDK, And its use Is subject to the terms
'// of the BRX SDK license agreement.
'/////////////////////////////////////////////////////////////////////////

' system 
Imports System.Text
Imports System.Runtime.InteropServices
Imports System.IO

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
    Public Class ComSamples
        ' Methods
        Public Shared Function ComSelectionSet(ByVal filter As Object()) As ObjectIdCollection
            Dim application As AcadApplication = TryCast(_AcAp.Application.AcadApplication, AcadApplication)
            If (application Is Nothing) Then
                Throw New System.Exception("Could Not Get Application")
            End If
            Dim setids As New ObjectIdCollection
            Dim selection As AcadSelectionSet = application.ActiveDocument.SelectionSets.Add("samp04Set")
            Try
                selection.SelectOnScreen(New Integer() {0}, filter)
                Dim obj As AcadObject
                For Each obj In selection
                    setids.Add(New ObjectId(New IntPtr(obj.ObjectID)))
                Next
            Finally
                selection.Delete()
            End Try
            Return setids
        End Function

        Public Shared Sub do_comSSet()
            Dim editor As Editor = Application.DocumentManager.MdiActiveDocument.Editor
            Using action As Transaction = HostApplicationServices.WorkingDatabase.TransactionManager.StartTransaction
                Dim id As ObjectId
                For Each id In ComSamples.ComSelectionSet(New Object() {"POINT,LINE,CIRCLE,INSERT"})
                    Dim ent As Entity = TryCast(action.GetObject(id, OpenMode.ForWrite), Entity)
                    If (Not ent Is Nothing) Then
                        ent.Layer = "0"
                    End If
                Next
                action.Commit()
            End Using
        End Sub

        Public Shared Sub do_performanceTest()
            Dim editor As Editor = Application.DocumentManager.MdiActiveDocument.Editor
            Dim sw As Stopwatch = Stopwatch.StartNew
            Dim app As AcadApplication = TryCast(_AcAp.Application.AcadApplication, AcadApplication)
            If (app Is Nothing) Then
                Throw New NullReferenceException("Could Not Get Application")
            End If
            Dim count As Integer = 0
            Dim item As AcadEntity
            For Each item In app.ActiveDocument.ModelSpace
                count += 1
            Next
            editor.WriteMessage(vbLf & "{0} Entities found in {1} Milliseconds", New Object() {count, sw.ElapsedMilliseconds})
        End Sub

    End Class
End Namespace

