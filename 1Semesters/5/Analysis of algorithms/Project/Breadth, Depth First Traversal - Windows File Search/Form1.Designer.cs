namespace Breadth__Depth_First_Traversal___Windows_File_Search
{
    partial class MainForm
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
            this.FileName_TxtBx = new System.Windows.Forms.TextBox();
            this.Directory_TxtBx = new System.Windows.Forms.TextBox();
            this.FileName_lbl = new System.Windows.Forms.Label();
            this.SearchIn_lbl = new System.Windows.Forms.Label();
            this.SearchForFile_ChkBx = new System.Windows.Forms.CheckBox();
            this.SearchForDirectory_ChkBx = new System.Windows.Forms.CheckBox();
            this.Breadth_RdoBtn = new System.Windows.Forms.RadioButton();
            this.UseAlgo_lbl = new System.Windows.Forms.Label();
            this.Depth_RdoBtn = new System.Windows.Forms.RadioButton();
            this.SearchFor_lbl = new System.Windows.Forms.Label();
            this.Search_Btn = new System.Windows.Forms.Button();
            this.TotalResult_lbl = new System.Windows.Forms.Label();
            this.MoreOption_lbl = new System.Windows.Forms.Label();
            this.Results_LstBx = new System.Windows.Forms.ListBox();
            this.Main_Pnl = new System.Windows.Forms.Panel();
            this.Reset_Btn = new System.Windows.Forms.Button();
            this.CaseSensitive_ChkBx = new System.Windows.Forms.CheckBox();
            this.MathFullName_ChkBx = new System.Windows.Forms.CheckBox();
            this.Main_Pnl.SuspendLayout();
            this.SuspendLayout();
            // 
            // FileName_TxtBx
            // 
            this.FileName_TxtBx.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FileName_TxtBx.Location = new System.Drawing.Point(151, 3);
            this.FileName_TxtBx.Name = "FileName_TxtBx";
            this.FileName_TxtBx.Size = new System.Drawing.Size(263, 32);
            this.FileName_TxtBx.TabIndex = 0;
            // 
            // Directory_TxtBx
            // 
            this.Directory_TxtBx.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Directory_TxtBx.Location = new System.Drawing.Point(151, 45);
            this.Directory_TxtBx.Name = "Directory_TxtBx";
            this.Directory_TxtBx.Size = new System.Drawing.Size(263, 32);
            this.Directory_TxtBx.TabIndex = 1;
            // 
            // FileName_lbl
            // 
            this.FileName_lbl.AutoSize = true;
            this.FileName_lbl.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FileName_lbl.Location = new System.Drawing.Point(8, 9);
            this.FileName_lbl.Name = "FileName_lbl";
            this.FileName_lbl.Size = new System.Drawing.Size(113, 23);
            this.FileName_lbl.TabIndex = 1;
            this.FileName_lbl.Text = "File Name:";
            // 
            // SearchIn_lbl
            // 
            this.SearchIn_lbl.AutoSize = true;
            this.SearchIn_lbl.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SearchIn_lbl.Location = new System.Drawing.Point(8, 51);
            this.SearchIn_lbl.Name = "SearchIn_lbl";
            this.SearchIn_lbl.Size = new System.Drawing.Size(104, 23);
            this.SearchIn_lbl.TabIndex = 1;
            this.SearchIn_lbl.Text = "Search in:";
            // 
            // SearchForFile_ChkBx
            // 
            this.SearchForFile_ChkBx.AutoSize = true;
            this.SearchForFile_ChkBx.Location = new System.Drawing.Point(151, 94);
            this.SearchForFile_ChkBx.Name = "SearchForFile_ChkBx";
            this.SearchForFile_ChkBx.Size = new System.Drawing.Size(53, 23);
            this.SearchForFile_ChkBx.TabIndex = 2;
            this.SearchForFile_ChkBx.Text = "File";
            this.SearchForFile_ChkBx.UseVisualStyleBackColor = true;
            // 
            // SearchForDirectory_ChkBx
            // 
            this.SearchForDirectory_ChkBx.AutoSize = true;
            this.SearchForDirectory_ChkBx.Location = new System.Drawing.Point(210, 94);
            this.SearchForDirectory_ChkBx.Name = "SearchForDirectory_ChkBx";
            this.SearchForDirectory_ChkBx.Size = new System.Drawing.Size(73, 23);
            this.SearchForDirectory_ChkBx.TabIndex = 3;
            this.SearchForDirectory_ChkBx.Text = "Folder";
            this.SearchForDirectory_ChkBx.UseVisualStyleBackColor = true;
            // 
            // Breadth_RdoBtn
            // 
            this.Breadth_RdoBtn.AutoSize = true;
            this.Breadth_RdoBtn.Checked = true;
            this.Breadth_RdoBtn.Location = new System.Drawing.Point(443, 93);
            this.Breadth_RdoBtn.Name = "Breadth_RdoBtn";
            this.Breadth_RdoBtn.Size = new System.Drawing.Size(113, 23);
            this.Breadth_RdoBtn.TabIndex = 6;
            this.Breadth_RdoBtn.TabStop = true;
            this.Breadth_RdoBtn.Text = "Breadth First";
            this.Breadth_RdoBtn.UseVisualStyleBackColor = true;
            // 
            // UseAlgo_lbl
            // 
            this.UseAlgo_lbl.AutoSize = true;
            this.UseAlgo_lbl.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.UseAlgo_lbl.Location = new System.Drawing.Point(439, 51);
            this.UseAlgo_lbl.Name = "UseAlgo_lbl";
            this.UseAlgo_lbl.Size = new System.Drawing.Size(143, 23);
            this.UseAlgo_lbl.TabIndex = 5;
            this.UseAlgo_lbl.Text = "Use Algorithm";
            // 
            // Depth_RdoBtn
            // 
            this.Depth_RdoBtn.AutoSize = true;
            this.Depth_RdoBtn.Location = new System.Drawing.Point(443, 126);
            this.Depth_RdoBtn.Name = "Depth_RdoBtn";
            this.Depth_RdoBtn.Size = new System.Drawing.Size(101, 23);
            this.Depth_RdoBtn.TabIndex = 7;
            this.Depth_RdoBtn.Text = "Depth First";
            this.Depth_RdoBtn.UseVisualStyleBackColor = true;
            // 
            // SearchFor_lbl
            // 
            this.SearchFor_lbl.AutoSize = true;
            this.SearchFor_lbl.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.SearchFor_lbl.Location = new System.Drawing.Point(8, 93);
            this.SearchFor_lbl.Name = "SearchFor_lbl";
            this.SearchFor_lbl.Size = new System.Drawing.Size(114, 23);
            this.SearchFor_lbl.TabIndex = 1;
            this.SearchFor_lbl.Text = "Search for:";
            // 
            // Search_Btn
            // 
            this.Search_Btn.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Search_Btn.Location = new System.Drawing.Point(459, 177);
            this.Search_Btn.Name = "Search_Btn";
            this.Search_Btn.Size = new System.Drawing.Size(97, 34);
            this.Search_Btn.TabIndex = 1;
            this.Search_Btn.Text = "Search";
            this.Search_Btn.UseVisualStyleBackColor = true;
            this.Search_Btn.Click += new System.EventHandler(this.Search_Btn_Click);
            // 
            // TotalResult_lbl
            // 
            this.TotalResult_lbl.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.TotalResult_lbl.AutoSize = true;
            this.TotalResult_lbl.Location = new System.Drawing.Point(12, 571);
            this.TotalResult_lbl.Name = "TotalResult_lbl";
            this.TotalResult_lbl.Size = new System.Drawing.Size(94, 19);
            this.TotalResult_lbl.TabIndex = 7;
            this.TotalResult_lbl.Text = "Total Results:";
            // 
            // MoreOption_lbl
            // 
            this.MoreOption_lbl.AutoSize = true;
            this.MoreOption_lbl.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MoreOption_lbl.Location = new System.Drawing.Point(8, 135);
            this.MoreOption_lbl.Name = "MoreOption_lbl";
            this.MoreOption_lbl.Size = new System.Drawing.Size(138, 23);
            this.MoreOption_lbl.TabIndex = 1;
            this.MoreOption_lbl.Text = "MoreOptions:";
            // 
            // Results_LstBx
            // 
            this.Results_LstBx.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.Results_LstBx.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Results_LstBx.FormattingEnabled = true;
            this.Results_LstBx.HorizontalScrollbar = true;
            this.Results_LstBx.ItemHeight = 23;
            this.Results_LstBx.Location = new System.Drawing.Point(12, 231);
            this.Results_LstBx.Name = "Results_LstBx";
            this.Results_LstBx.Size = new System.Drawing.Size(910, 326);
            this.Results_LstBx.TabIndex = 9;
            this.Results_LstBx.TabStop = false;
            this.Results_LstBx.DoubleClick += new System.EventHandler(this.Results_LstBx_DoubleClick);
            // 
            // Main_Pnl
            // 
            this.Main_Pnl.Controls.Add(this.CaseSensitive_ChkBx);
            this.Main_Pnl.Controls.Add(this.MathFullName_ChkBx);
            this.Main_Pnl.Controls.Add(this.FileName_lbl);
            this.Main_Pnl.Controls.Add(this.FileName_TxtBx);
            this.Main_Pnl.Controls.Add(this.Directory_TxtBx);
            this.Main_Pnl.Controls.Add(this.SearchIn_lbl);
            this.Main_Pnl.Controls.Add(this.Reset_Btn);
            this.Main_Pnl.Controls.Add(this.Search_Btn);
            this.Main_Pnl.Controls.Add(this.SearchFor_lbl);
            this.Main_Pnl.Controls.Add(this.UseAlgo_lbl);
            this.Main_Pnl.Controls.Add(this.MoreOption_lbl);
            this.Main_Pnl.Controls.Add(this.Depth_RdoBtn);
            this.Main_Pnl.Controls.Add(this.SearchForFile_ChkBx);
            this.Main_Pnl.Controls.Add(this.Breadth_RdoBtn);
            this.Main_Pnl.Controls.Add(this.SearchForDirectory_ChkBx);
            this.Main_Pnl.Location = new System.Drawing.Point(12, 12);
            this.Main_Pnl.Name = "Main_Pnl";
            this.Main_Pnl.Size = new System.Drawing.Size(588, 217);
            this.Main_Pnl.TabIndex = 0;
            // 
            // Reset_Btn
            // 
            this.Reset_Btn.Font = new System.Drawing.Font("Century Gothic", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Reset_Btn.Location = new System.Drawing.Point(356, 177);
            this.Reset_Btn.Name = "Reset_Btn";
            this.Reset_Btn.Size = new System.Drawing.Size(97, 34);
            this.Reset_Btn.TabIndex = 8;
            this.Reset_Btn.Text = "Reset";
            this.Reset_Btn.UseVisualStyleBackColor = true;
            this.Reset_Btn.Click += new System.EventHandler(this.Reset_Btn_Click);
            // 
            // CaseSensitive_ChkBx
            // 
            this.CaseSensitive_ChkBx.AutoSize = true;
            this.CaseSensitive_ChkBx.Location = new System.Drawing.Point(152, 168);
            this.CaseSensitive_ChkBx.Name = "CaseSensitive_ChkBx";
            this.CaseSensitive_ChkBx.Size = new System.Drawing.Size(128, 23);
            this.CaseSensitive_ChkBx.TabIndex = 5;
            this.CaseSensitive_ChkBx.Text = "Case Sensitive";
            this.CaseSensitive_ChkBx.UseVisualStyleBackColor = true;
            // 
            // MathFullName_ChkBx
            // 
            this.MathFullName_ChkBx.AutoSize = true;
            this.MathFullName_ChkBx.Location = new System.Drawing.Point(152, 139);
            this.MathFullName_ChkBx.Name = "MathFullName_ChkBx";
            this.MathFullName_ChkBx.Size = new System.Drawing.Size(149, 23);
            this.MathFullName_ChkBx.TabIndex = 4;
            this.MathFullName_ChkBx.Text = "Match Full Name";
            this.MathFullName_ChkBx.UseVisualStyleBackColor = true;
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 17F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(934, 596);
            this.Controls.Add(this.Main_Pnl);
            this.Controls.Add(this.Results_LstBx);
            this.Controls.Add(this.TotalResult_lbl);
            this.Font = new System.Drawing.Font("Century Gothic", 7.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.MinimumSize = new System.Drawing.Size(950, 635);
            this.Name = "MainForm";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Breadth & Depth First Traversal (Windows File Search)";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.Main_Pnl.ResumeLayout(false);
            this.Main_Pnl.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox FileName_TxtBx;
        private System.Windows.Forms.TextBox Directory_TxtBx;
        private System.Windows.Forms.Label FileName_lbl;
        private System.Windows.Forms.Label SearchIn_lbl;
        private System.Windows.Forms.CheckBox SearchForFile_ChkBx;
        private System.Windows.Forms.CheckBox SearchForDirectory_ChkBx;
        private System.Windows.Forms.RadioButton Breadth_RdoBtn;
        private System.Windows.Forms.Label UseAlgo_lbl;
        private System.Windows.Forms.RadioButton Depth_RdoBtn;
        private System.Windows.Forms.Label SearchFor_lbl;
        private System.Windows.Forms.Button Search_Btn;
        private System.Windows.Forms.Label TotalResult_lbl;
        private System.Windows.Forms.Label MoreOption_lbl;
        private System.Windows.Forms.ListBox Results_LstBx;
        private System.Windows.Forms.Panel Main_Pnl;
        private System.Windows.Forms.Button Reset_Btn;
        private System.Windows.Forms.CheckBox CaseSensitive_ChkBx;
        private System.Windows.Forms.CheckBox MathFullName_ChkBx;
    }
}

