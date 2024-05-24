'// Property of Bricsys NV. All rights reserved.
'// This file Is part of the BRX SDK, And its use Is subject to the terms
'// of the BRX SDK license agreement.
'/////////////////////////////////////////////////////////////////////////

Imports System
Imports Teigha.DatabaseServices
Imports Teigha.Geometry
Imports Teigha.GraphicsInterface

Namespace CsBrxMgd
    Public Class BricscadDrawOverrule
        Inherits DrawableOverrule
        ' Methods
        Public Overrides Function WorldDraw(ByVal drawable As Drawable, ByVal wd As WorldDraw) As Boolean
            Dim point As DBPoint = TryCast(drawable, DBPoint)
            Dim pos As Point3d = point.Position
            Dim text As String = String.Format("x={0}, y={1}, z={2}", pos.X.ToString("F"), pos.Y.ToString("F"), pos.Z.ToString("F"))
            Dim texthight As Double = point.Database.Textsize
            wd.Geometry.Text(point.Position, point.Normal, point.Normal.GetPerpendicularVector, texthight, ((texthight * [text].Length) * 0.4), 0, [text])
            Return MyBase.WorldDraw(drawable, wd)
        End Function

    End Class
End Namespace

