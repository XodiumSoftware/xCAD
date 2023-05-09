Namespace CsBrxMgd
	Partial Public Class BrxMgdForm
		''' <summary>
		''' Required designer variable.
		''' </summary>
		Private components As System.ComponentModel.IContainer = Nothing

		''' <summary>
		''' Clean up any resources being used.
		''' </summary>
		''' <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		Protected Overrides Sub Dispose(ByVal disposing As Boolean)
			If disposing AndAlso (components IsNot Nothing) Then
				components.Dispose()
			End If
			MyBase.Dispose(disposing)
		End Sub

		#Region "Windows Form Designer generated code"

		''' <summary>
		''' Required method for Designer support - do not modify
		''' the contents of this method with the code editor.
		''' </summary>
		Private Sub InitializeComponent()
            Me.buttonDist = New System.Windows.Forms.Button
            Me.buttonSelectEnt = New System.Windows.Forms.Button
            Me.SuspendLayout()
            '
            'buttonDist
            '
            Me.buttonDist.Location = New System.Drawing.Point(81, 83)
            Me.buttonDist.Name = "buttonDist"
            Me.buttonDist.Size = New System.Drawing.Size(75, 23)
            Me.buttonDist.TabIndex = 0
            Me.buttonDist.Text = "Distance"
            Me.buttonDist.UseVisualStyleBackColor = True
            '
            'buttonSelectEnt
            '
            Me.buttonSelectEnt.Location = New System.Drawing.Point(166, 83)
            Me.buttonSelectEnt.Name = "buttonSelectEnt"
            Me.buttonSelectEnt.Size = New System.Drawing.Size(75, 23)
            Me.buttonSelectEnt.TabIndex = 1
            Me.buttonSelectEnt.Text = "Select "
            Me.buttonSelectEnt.UseVisualStyleBackColor = True
            '
            'BrxMgdForm
            '
            Me.ClientSize = New System.Drawing.Size(320, 175)
            Me.Controls.Add(Me.buttonSelectEnt)
            Me.Controls.Add(Me.buttonDist)
            Me.Name = "BrxMgdForm"
            Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
            Me.Text = "BrxMgdForm"
            Me.ResumeLayout(False)

        End Sub

		#End Region

		Private WithEvents buttonDist As Button
		Private WithEvents buttonSelectEnt As Button

	End Class
End Namespace