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
    Friend Class EditorSample
        ' Methods
        Public Shared Sub do_getDistance()
            Dim editor As Editor = Application.DocumentManager.MdiActiveDocument.Editor
            Dim ppo As New PromptPointOptions("Select Point")
            Dim ppr As PromptPointResult = editor.GetPoint(ppo)
            If (ppr.Status <> PromptStatus.OK) Then
                Throw New System.Exception("GetPoint failed")
            End If
            Dim pdo As New PromptDistanceOptions("Select next Point")
            pdo.UseBasePoint = True
            pdo.BasePoint = ppr.Value
            pdo.UseDashedLine = True
            Dim pdr As PromptDoubleResult = editor.GetDistance(pdo)
            If (pdr.Status <> PromptStatus.OK) Then
                Throw New System.Exception("GetDistance failed")
            End If
            Application.ShowAlertDialog(pdr.ToString)
        End Sub

        Public Shared Sub do_getEntity()
            Dim editor As Editor = Application.DocumentManager.MdiActiveDocument.Editor
            Dim peo As New PromptEntityOptions("Select a Hatch")
            peo.SetRejectMessage("Not a Hatch!")
            peo.AddAllowedClass(GetType(Hatch), True)
            Dim per As PromptEntityResult = editor.GetEntity(peo)
            If (per.Status = PromptStatus.OK) Then
                Using action As Transaction = HostApplicationServices.WorkingDatabase.TransactionManager.StartTransaction
                    Dim hatch As Hatch = TryCast(action.GetObject(per.ObjectId, OpenMode.ForWrite), Hatch)
                    If (Not hatch Is Nothing) Then
                        Application.ShowAlertDialog(("Area is " & hatch.Area.ToString))
                    End If
                    action.Commit()
                End Using
            End If
        End Sub

        Public Shared Sub do_getEntity2()
            Dim editor As Editor = Application.DocumentManager.MdiActiveDocument.Editor
            Dim peo As New PromptEntityOptions("Select a Line")
            peo.SetRejectMessage("Not a Line!")
            peo.AddAllowedClass(GetType(Line), True)
            Dim per As PromptEntityResult = editor.GetEntity(peo)
            If (per.Status = PromptStatus.OK) Then
                Using action As Transaction = HostApplicationServices.WorkingDatabase.TransactionManager.StartTransaction
                    Dim line As Line = TryCast(action.GetObject(per.ObjectId, OpenMode.ForWrite), Line)
                    If (Not line Is Nothing) Then
                        Application.ShowAlertDialog(("Length is " & line.Length.ToString))
                    End If
                    action.Commit()
                End Using
            End If
        End Sub

        Public Shared Sub do_getKeyWords()
            Dim editor As Editor = Application.DocumentManager.MdiActiveDocument.Editor
            Dim pop As New PromptKeywordOptions("this is a test")
            pop.AppendKeywordsToMessage = True
            pop.AllowNone = False
            pop.Keywords.Add("A_Kwd")
            pop.Keywords.Add("B_Kwd")
            pop.Keywords.Add("C_Kwd")
            Application.ShowAlertDialog(editor.GetKeywords(pop).ToString)
        End Sub

        Public Shared Sub do_getPoint()
            Dim editor As Editor = Application.DocumentManager.MdiActiveDocument.Editor
            Dim pop As New PromptPointOptions("Select Point")
            Application.ShowAlertDialog(editor.GetPoint(pop).ToString)
        End Sub

        Public Shared Sub do_getSelectionSet()
            Dim editor As Editor = Application.DocumentManager.MdiActiveDocument.Editor
            Dim dxfs As TypedValue() = New TypedValue() {New TypedValue(0, "POINT")}
            Dim sfilter As New SelectionFilter(dxfs)
            Dim pso As New PromptSelectionOptions
            pso.MessageForAdding = "Select Points"
            pso.MessageForRemoval = "Remove Points"
            pso.AllowDuplicates = False
            Dim res As PromptSelectionResult = editor.GetSelection(pso, sfilter)
            If (res.Status = PromptStatus.OK) Then
                Dim sset As SelectionSet = res.Value
                editor.WriteMessage(vbLf & "Found {0} points", New Object() {sset.Count})
                editor.WriteMessage(vbLf & "{0}", New Object() {EditorSample.getPointLocations(sset.GetObjectIds).Count})
            End If
        End Sub

        Public Shared Sub do_getString()
            Dim editor As Editor = Application.DocumentManager.MdiActiveDocument.Editor
            Dim pop As New PromptStringOptions("this is a test")
            Application.ShowAlertDialog(editor.GetString(pop).ToString)
        End Sub

        Public Shared Sub do_MainWindow()
            Dim editor As Editor = Application.DocumentManager.MdiActiveDocument.Editor
            Dim w As _AcWnd.Window = _AcAp.Application.MainWindow
            w.Text = "*!*BricsCAD Rocks*!*"
            w.WindowState = FormWindowState.Minimized
            If (w.WindowState = FormWindowState.Minimized) Then
                editor.WriteMessage("Minimized")
            End If
            w.WindowState = FormWindowState.Normal
            If (w.WindowState = FormWindowState.Normal) Then
                editor.WriteMessage("Normal")
            End If
            w.WindowState = FormWindowState.Maximized
            If (w.WindowState = FormWindowState.Maximized) Then
                editor.WriteMessage("Maximized")
            End If
        End Sub

        Public Shared Function getPointLocations(ByVal ids As ObjectId()) As Point3dCollection
            Dim locations As New Point3dCollection
            Using action As Transaction = HostApplicationServices.WorkingDatabase.TransactionManager.StartTransaction
                Dim id As ObjectId
                For Each id In ids
                    Dim point As DBPoint = TryCast(action.GetObject(id, OpenMode.ForRead), DBPoint)
                    If (Not point Is Nothing) Then
                        locations.Add(point.Position)
                    End If
                Next
                action.Commit()
            End Using
            Return locations
        End Function

        Public Shared Sub OnPointMonitor(ByVal sender As Object, ByVal eventArgs As PointMonitorEventArgs)
            Dim null As ObjectId = ObjectId.Null
            Dim editor As Editor = DirectCast(sender, Editor)
            Dim document As Document = editor.Document
            If editor.IsQuiescent Then
                Dim context As InputPointContext = eventArgs.Context
                context.DrawContext.Geometry.Circle(context.RawPoint, 10, Vector3d.ZAxis)
                Dim names As String = Nothing
                Dim paths As FullSubentityPath() = eventArgs.Context.GetPickedEntities
                Using transaction As Transaction = document.TransactionManager.StartTransaction
                    Array.Sort(Of FullSubentityPath)(paths, New Comparison(Of FullSubentityPath)(AddressOf EditorSample.sortByIds))
                    Dim path As FullSubentityPath
                    For Each path In paths
                        Dim ids As ObjectId() = path.GetObjectIds
                        If (ids.Length > 0) Then
                            Dim bref As BlockReference = TryCast(transaction.GetObject(ids(ids.GetLowerBound(0)), OpenMode.ForRead), BlockReference)
                            If (Not bref Is Nothing) Then
                                names = (names & String.Format(vbLf & "Block Name= {0} {1}", bref.Name, path.SubentId.IndexPtr.ToInt32))
                                Exit For
                            End If
                        End If
                    Next
                    transaction.Commit()
                End Using
                eventArgs.AppendToolTipText(names)
            End If
        End Sub

        Public Shared Function sortByIds(ByVal a As FullSubentityPath, ByVal b As FullSubentityPath) As Integer
            Return a.SubentId.IndexPtr.ToInt32.CompareTo(b.SubentId.IndexPtr.ToInt32)
        End Function

    End Class
End Namespace

