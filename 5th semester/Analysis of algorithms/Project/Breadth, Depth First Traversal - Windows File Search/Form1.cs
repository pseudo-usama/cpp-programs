using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.IO;    // For File Handling
using System.Diagnostics;
using System.Threading;   // For using Queue (in Breadth Firth)

namespace Breadth__Depth_First_Traversal___Windows_File_Search
{
    public partial class MainForm : Form
    {
        CancellationTokenSource call = null;

        #region Cunstructor & Load Event

        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            Search_Btn.Parent = this;
            Search_Btn.Location = new Point(Search_Btn.Location.X + 12, Search_Btn.Location.Y + 12);
            TotalResult_lbl.Text = "";

            Search_Btn.BringToFront();
        }
        
        #endregion

        #region Search Button Click

        private async void Search_Btn_Click(object sender, EventArgs e)
        {
            if (call == null)
            {
                if (FileName_TxtBx.Text == string.Empty)
                {
                    MessageBox.Show("Please provide a file name", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    FileName_TxtBx.Focus();
                }
                else if (Directory_TxtBx.Text == string.Empty)
                {
                    MessageBox.Show("Please provide the folder to search in", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    Directory_TxtBx.Focus();
                }
                else if (SearchForFile_ChkBx.Checked == false && SearchForDirectory_ChkBx.Checked == false)
                {
                    MessageBox.Show("Please provide which to search", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    SearchForFile_ChkBx.Focus();
                }
                else
                {
                    if (!Directory.Exists(Directory_TxtBx.Text))
                    {
                        MessageBox.Show("Invalid folder path.", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        Directory_TxtBx.Focus();
                    }
                    else
                    {
                        call = new CancellationTokenSource();
                        Main_Pnl.Enabled = false;
                        Search_Btn.Text = "Cancel";

                        Results_LstBx.Items.Clear();
                        TotalResult_lbl.Text = "";

                        Task tsk;

                        if (Breadth_RdoBtn.Checked)
                        {
                            tsk = new Task(BreadthFirst);
                            tsk.Start();
                            await tsk;
                        }
                        else
                        {
                            tsk = new Task(DepthFirst);
                            tsk.Start();
                            await tsk;
                        }
                    }
                }
            }
            else
            {
                call.Cancel();
            }
        }
        
        #endregion

        #region Breadth First

        private void BreadthFirst()
        {
            Queue<string> Directories = new Queue<string>();
            Directories.Enqueue(Directory_TxtBx.Text);
            string CurrentDir;

            uint TotalFile = 0, TotalDirectories = 1, NotAccessFolders = 0, Found = 0;
            bool flag;
            string[] dirs = new string[] { };
            string[] dirfiles = new string[] { };

            while (Directories.Count != 0)
            {
                CurrentDir = Directories.Dequeue();
                flag = true;

                try
                {
                    dirs = Directory.GetDirectories(CurrentDir);
                    dirfiles = Directory.GetFiles(CurrentDir);
                }
                catch
                {
                    NotAccessFolders++;
                    flag = false;
                }

                if (flag)
                {
                    foreach (string dir in dirs)
                    {
                        Directories.Enqueue(dir);
                        TotalDirectories++;

                        if (SearchForDirectory_ChkBx.Checked)
                            if (MathFullName_ChkBx.Checked)
                            {
                                if (CaseSensitive_ChkBx.Checked ? Path.GetFileName(dir) == FileName_TxtBx.Text : Path.GetFileName(dir).ToLower() == FileName_TxtBx.Text.ToLower())
                                {
                                    Results_LstBx.Items.Add(dir);
                                    Found++;
                                }
                            }
                            else
                                if (CaseSensitive_ChkBx.Checked ? Path.GetFileName(dir).Contains(FileName_TxtBx.Text) : Path.GetFileName(dir).ToLower().Contains(FileName_TxtBx.Text.ToLower()))
                                {
                                    Results_LstBx.Items.Add(dir);
                                    Found++;
                                }
                    }

                    foreach (string file in dirfiles)
                    {
                        TotalFile++;

                        if (SearchForFile_ChkBx.Checked)
                            if (MathFullName_ChkBx.Checked)
                            {
                                if (CaseSensitive_ChkBx.Checked ? Path.GetFileName(file) == FileName_TxtBx.Text : Path.GetFileName(file).ToLower() == FileName_TxtBx.Text.ToLower())
                                {
                                    Results_LstBx.Items.Add(file);
                                    Found++;
                                }
                            }
                            else
                                if (CaseSensitive_ChkBx.Checked ? Path.GetFileName(file).Contains(FileName_TxtBx.Text) : Path.GetFileName(file).ToLower().Contains(FileName_TxtBx.Text.ToLower()))
                                {
                                    Results_LstBx.Items.Add(file);
                                    Found++;
                                }
                    }

                    TotalResult_lbl.Text = "Results found: " + Found.ToString() + " | Searched in: " + TotalFile.ToString() + " File(s) & " + TotalDirectories.ToString() + " Folder(s) | " + " Unaccessed Folder(s) " + NotAccessFolders.ToString();
                }

                try
                {
                    call.Token.ThrowIfCancellationRequested();  // It stop searching if Cancel button is pressed
                }
                catch
                {
                    Main_Pnl.Enabled = true;
                    call = null;
                    Search_Btn.Text = "Search";
                    return;
                }
            }

            Main_Pnl.Enabled = true;
            call = null;
            Search_Btn.Text = "Search";
        }

        #endregion

        #region Depth First

        private void DepthFirst()
        {
            Stack<string> Directories = new Stack<string>();
            Directories.Push(Directory_TxtBx.Text);
            string CurrentDir;

            uint TotalFile = 0, TotalDirectories = 1, NotAccessFolders = 0, Found = 0;
            bool flag;
            string[] dirs = new string[] { };
            string[] dirfiles = new string[] { };

            while (Directories.Count != 0)
            {
                CurrentDir = Directories.Pop();
                flag = true;

                try
                {
                    dirs = Directory.GetDirectories(CurrentDir);
                    dirfiles = Directory.GetFiles(CurrentDir);
                }
                catch
                {
                    NotAccessFolders++;
                    flag = false;
                }

                if (flag)
                {
                    for (int i = dirs.Length - 1; i > -1; i--)
                    {
                        Directories.Push(dirs[i]);
                        TotalDirectories++;

                        if (SearchForDirectory_ChkBx.Checked)
                            if (MathFullName_ChkBx.Checked)
                            {
                                if (CaseSensitive_ChkBx.Checked ? Path.GetFileName(dirs[i]) == FileName_TxtBx.Text : Path.GetFileName(dirs[i]).ToLower() == FileName_TxtBx.Text.ToLower())
                                {
                                    Results_LstBx.Items.Add(dirs[i]);
                                    Found++;
                                }
                            }
                            else
                                if (CaseSensitive_ChkBx.Checked ? Path.GetFileName(dirs[i]).Contains(FileName_TxtBx.Text) : Path.GetFileName(dirs[i]).ToLower().Contains(FileName_TxtBx.Text.ToLower()))
                                {
                                    Results_LstBx.Items.Add(dirs[i]);
                                    Found++;
                                }
                    }

                    for (int i = dirfiles.Length - 1; i > -1; i--)
                    {
                        TotalFile++;

                        if (SearchForFile_ChkBx.Checked)
                            if (MathFullName_ChkBx.Checked)
                            {
                                if (CaseSensitive_ChkBx.Checked ? Path.GetFileName(dirfiles[i]) == FileName_TxtBx.Text : Path.GetFileName(dirfiles[i]).ToLower() == FileName_TxtBx.Text.ToLower())
                                {
                                    Results_LstBx.Items.Add(dirfiles[i]);
                                    Found++;
                                }
                            }
                            else
                                if (CaseSensitive_ChkBx.Checked ? Path.GetFileName(dirfiles[i]).Contains(FileName_TxtBx.Text) : Path.GetFileName(dirfiles[i]).ToLower().Contains(FileName_TxtBx.Text.ToLower()))
                                {
                                    Results_LstBx.Items.Add(dirfiles[i]);
                                    Found++;
                                }
                    }

                    TotalResult_lbl.Text = "Results found: " + Found.ToString() + " | Searched in: " + TotalFile.ToString() + " File(s) & " + TotalDirectories.ToString() + " Folder(s) | " + " Unaccessed Folder(s) " + NotAccessFolders.ToString();
                }

                try
                {
                    call.Token.ThrowIfCancellationRequested();  // It stop searching if Cancel button is pressed
                }
                catch
                {
                    Main_Pnl.Enabled = true;
                    call = null;
                    Search_Btn.Text = "Search";
                    return;
                }
            }

            Main_Pnl.Enabled = true;
            call = null;
            Search_Btn.Text = "Search";
        }

        #endregion

        #region Other Functions

        private void Results_LstBx_DoubleClick(object sender, EventArgs e)
        {
            if (Results_LstBx.SelectedIndex != -1)
            {
                //Process.Start("explorer.exe",@"/select,F:\3UOG\30Web\30Tutorial Practise\99) else\1) Easy Tutorials\1) Easy Tutorials (Youtube Channel)(UCkjoHfkLEy7ZT4bA2myJ8xA))\@Complete Websites (Designes)\Job Clues\images\banner-1.jpg");

                Process.Start("explorer.exe", @"/select," + string.Format(Results_LstBx.SelectedItem.ToString()));
            }
        }

        private void Reset_Btn_Click(object sender, EventArgs e)
        {
            FileName_TxtBx.Text = Directory_TxtBx.Text = string.Empty;
            SearchForFile_ChkBx.Checked = SearchForDirectory_ChkBx.Checked =
            MathFullName_ChkBx.Checked = CaseSensitive_ChkBx.Checked
            = false;

            Results_LstBx.Items.Clear();
            TotalResult_lbl.Text = "";
        }

        #endregion
    }
}
