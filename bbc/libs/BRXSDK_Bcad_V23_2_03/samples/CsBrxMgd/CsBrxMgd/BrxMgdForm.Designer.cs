namespace CsBrxMgd
{
    partial class BrxMgdForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.buttonDist = new System.Windows.Forms.Button();
            this.buttonSelectEnt = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // buttonDist
            // 
            this.buttonDist.Location = new System.Drawing.Point(81, 83);
            this.buttonDist.Name = "buttonDist";
            this.buttonDist.Size = new System.Drawing.Size(75, 23);
            this.buttonDist.TabIndex = 0;
            this.buttonDist.Text = "Distance";
            this.buttonDist.UseVisualStyleBackColor = true;
            this.buttonDist.Click += new System.EventHandler(this.select_Click);
            // 
            // buttonSelectEnt
            // 
            this.buttonSelectEnt.Location = new System.Drawing.Point(166, 83);
            this.buttonSelectEnt.Name = "buttonSelectEnt";
            this.buttonSelectEnt.Size = new System.Drawing.Size(75, 23);
            this.buttonSelectEnt.TabIndex = 1;
            this.buttonSelectEnt.Text = "Select ";
            this.buttonSelectEnt.UseVisualStyleBackColor = true;
            this.buttonSelectEnt.Click += new System.EventHandler(this.buttonSelectEnt_Click);
            // 
            // BrxMgdForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(320, 175);
            this.Controls.Add(this.buttonSelectEnt);
            this.Controls.Add(this.buttonDist);
            this.Name = "BrxMgdForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "BrxMgdForm";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonDist;
        private System.Windows.Forms.Button buttonSelectEnt;

    }
}