using System;
using System.Collections.Specialized;

using Bricscad.ApplicationServices;
using Bricscad.EditorInput;
using Bricscad.Ribbon;
using Bricscad.Windows;

namespace CsBrxMgd
{
    public class Ribbon
    {
        public static Editor editor()
        {
            Document currentDoc = Application.DocumentManager.MdiActiveDocument;
            return currentDoc.Editor;
        }

        public static void AddButtons()
        {
            RibbonControl rbnCtrl = ComponentManager.Ribbon;

            if (rbnCtrl != null)
            {
                //create Ribbon tab
                RibbonTab tab1 = new RibbonTab();
                tab1.Title = "Tab1";
                tab1.Id = "Tab1";
                RibbonTab tab2 = new RibbonTab();
                tab2.Title = "Tab2";
                tab2.Id = "Tab2";
                RibbonTab tab3 = new RibbonTab();
                tab3.Title = "Tab3";
                tab3.Id = "Tab3";
                RibbonTab tab4 = new RibbonTab();
                tab4.Title = "Tab4";
                tab4.Id = "Tab4";

                rbnCtrl.Tabs.CollectionChanged += Tabs_CollectionChanged;

                rbnCtrl.Tabs.Add(tab1);
                rbnCtrl.Tabs.Add(tab2);
                rbnCtrl.Tabs.Add(tab3);

                //create Ribbon panel
                RibbonPanelSource srcPanel1 = new RibbonPanelSource();
                srcPanel1.Title = "Panel1";
                srcPanel1.Id = "Panel1";
                RibbonPanel panel1 = new RibbonPanel();
                panel1.Source = srcPanel1;

                tab1.Panels.Add(panel1);

                RibbonPanelSource srcPanel2 = new RibbonPanelSource();
                srcPanel2.Id = "Panel2";
                srcPanel2.Title = "Panel2";
                RibbonPanel panel2 = new RibbonPanel();
                panel2.Source = srcPanel2;

                tab2.Panels.Add(panel2);

                RibbonPanelSource srcPanel3 = new RibbonPanelSource();
                srcPanel3.Id = "Panel3";
                srcPanel3.Title = "Panel3";
                RibbonPanel panel3 = new RibbonPanel();
                panel3.Source = srcPanel3;

                tab3.Panels.Add(panel3);

                srcPanel1.Items.CollectionChanged += Buttons_CollectionChanged;
                srcPanel2.Items.CollectionChanged += Buttons_CollectionChanged;

                //buttons
                RibbonButton button1Panel1 = new RibbonButton();
                button1Panel1.ToolTip = "1";
                button1Panel1.Text = "This is a managed ribbon button from the panel with the title \"ManagedRibbonPanel1\"";
                button1Panel1.CommandParameter = "rectang";
                button1Panel1.ImagePath = "a_large.png";
                button1Panel1.Id = "1";

                RibbonButton button1Panel2 = new RibbonButton();
                button1Panel2.ToolTip = "2";
                button1Panel2.CommandParameter = "circle";
                button1Panel2.ImagePath = "circle_r";
                button1Panel2.Id = "2";

                RibbonButton button2Panel2 = new RibbonButton();
                button2Panel2.ToolTip = "3";
                button2Panel2.CommandParameter = "line";
                button2Panel2.ImagePath = "a_small.png";
                button2Panel2.Text = "These are managed ribbon buttons from the panel with the title \"ManagedRibbonPanel2\"";
                button2Panel2.Id = "3";

                //buttons
                RibbonButton button1Panel3 = new RibbonButton();
                button1Panel3.ToolTip = "4";
                button1Panel3.CommandParameter = "pline";
                button1Panel3.ImagePath = "pline";
                button1Panel3.Id = "4";

                RibbonButton button2Panel3 = new RibbonButton();
                button2Panel3.ToolTip = "5";
                button2Panel3.CommandParameter = "ellipse";
                button2Panel3.ImagePath = "ellipse_";
                button2Panel3.Id = "5";

                RibbonButton button3Panel3 = new RibbonButton();
                button3Panel3.ToolTip = "6";
                button3Panel3.CommandParameter = "Box";
                button3Panel3.ImagePath = "acis_box";
                button3Panel3.Text = "These are managed ribbon buttons from the panel with the title \"ManagedRibbonPanel3\"";
                button3Panel3.Id = "6";

                srcPanel1.Items.Add(button1Panel1);
                srcPanel2.Items.Add(button1Panel2);
                srcPanel2.Items.Add(button2Panel2);
                srcPanel3.Items.Add(button1Panel3);
                srcPanel3.Items.Add(button2Panel3);
                srcPanel3.Items.Add(button3Panel3);

                RibbonItem item = srcPanel2.FindItem("3");
                if (item != null)
                    Ribbon.editor().WriteMessage("\"button2Panel2\" found in the panel items collection\n");
            }
        }

        public static void removeTab()
        {
            Ribbon.editor().WriteMessage("Remove Tab:\n");
            PromptStringOptions tabName = new PromptStringOptions("Tab Id:\n");
            tabName.AllowSpaces = false;
            PromptResult strResTab = Ribbon.editor().GetString(tabName);
            RibbonControl ribbonControl = ComponentManager.Ribbon;

            RibbonTab tab = null;
            if (ribbonControl != null)
            {
                tab = ribbonControl.FindTab(strResTab.StringResult);
            }
            else
            {
                Ribbon.editor().WriteMessage("Ribbon control unavailable!\n");
                return;
            }

            if (tab != null)
            {
                ribbonControl.Tabs.CollectionChanged += Tabs_CollectionChanged;
                ribbonControl.Tabs.Remove(tab);
            }
            else
            {
                Ribbon.editor().WriteMessage("Ribbon tab unavailable!\n");
            }
        }

        public static void FindRemoveRibbonButton()
        {
            Ribbon.editor().WriteMessage("Find and remove RibbonButton:\n");
            PromptStringOptions tabName = new PromptStringOptions("RibbonButton Id:\n");
            tabName.AllowSpaces = false;
            PromptResult strResTab = Ribbon.editor().GetString(tabName);

            RibbonControl ribbonControl = ComponentManager.Ribbon;

            if (ribbonControl != null)
            {
                RibbonTabCollection tabCol = ribbonControl.Tabs;
                foreach (RibbonTab tabIdx in tabCol)
                {
                    RibbonItem itemM = tabIdx.FindItem(strResTab.StringResult);
                    if (itemM != null)
                    {
                        Ribbon.editor().WriteMessage("The button has been found\n");
                        RibbonPanelCollection panel = tabIdx.Panels;

                        foreach (RibbonPanel pan in panel)
                        {
                            RibbonPanelSource panSource = pan.Source;
                            if (panSource != null)
                            {
                                Ribbon.editor().WriteMessage("\nThe RibbonButtonSource of the Button is {0}\n", panSource.Title);
                                panSource.Items.Remove(itemM);
                            }
                        }
                    }
                }

                RibbonItem controlFindItem = ribbonControl.FindItem(strResTab.StringResult, false);
                if (controlFindItem != null)
                    Ribbon.editor().WriteMessage("Button has been found and removed in the panel items collection\n");
            }
            else
            {
                Ribbon.editor().WriteMessage("Ribbon control unavailable!\n");
                return;
            }
        }

        public static void FindRemoveRibbonPanel()
        {
            Ribbon.editor().WriteMessage("Find and remove RibbonPanel:\n");
            PromptStringOptions tabName = new PromptStringOptions("RibbonTab Id:\n");
            tabName.AllowSpaces = false;
            PromptResult strResTab = Ribbon.editor().GetString(tabName);

            PromptStringOptions panelName = new PromptStringOptions("RibbonPanel Id:\n");
            panelName.AllowSpaces = false;
            PromptResult strResPanel = Ribbon.editor().GetString(panelName);

            RibbonControl ribbonControl = ComponentManager.Ribbon;

            RibbonPanel ribPan = null;
            RibbonTab tab = null;
            if (ribbonControl != null)
            {
                tab = ribbonControl.FindTab(strResTab.StringResult);
                ribPan = ribbonControl.FindPanel(strResPanel.StringResult, false);
            }
            else
            {
                Ribbon.editor().WriteMessage("Ribbon control unavailable!\n");
                return;
            }

            if (ribPan != null)
            {
                tab.Panels.Remove(ribPan);
                Ribbon.editor().WriteMessage("RibbonPanel has been found!\n");

            }
            else
            {
                Ribbon.editor().WriteMessage("RibbonPanel unavailable!\n");
            }

        }

        public static void Tabs_CollectionChanged(Object obj, NotifyCollectionChangedEventArgs e)
        {
            NotifyCollectionChangedAction enu = e.Action;

            if (enu.ToString() == "Add")
            {
                RibbonTab rbTab = (RibbonTab)e.NewItems[0];
                if (rbTab != null)
                    Ribbon.editor().WriteMessage(rbTab.Title + " added\n");
            }
            else if (enu.ToString() == "Remove")
            {
                RibbonTab rbTab1 = (RibbonTab)e.OldItems[0];
                if (rbTab1 != null)
                    Ribbon.editor().WriteMessage(rbTab1.Title + " removed\n");
            }
        }

        public static void Panels_CollectionChanged(Object obj, NotifyCollectionChangedEventArgs e)
        {
            NotifyCollectionChangedAction enu = e.Action;

            if (enu.ToString() == "Add")
            {
                RibbonPanel rbPanel = (RibbonPanel)e.NewItems[0];
                if (rbPanel != null)
                    Ribbon.editor().WriteMessage(rbPanel.Source.Id + " added\n");
            }
            else if (enu.ToString() == "Remove")
            {
                RibbonPanel rbPanel1 = (RibbonPanel)e.OldItems[0];
                if (rbPanel1 != null)
                    Ribbon.editor().WriteMessage(rbPanel1.Source.Id + " removed\n");
            }
        }

        public static void Buttons_CollectionChanged(Object obj, NotifyCollectionChangedEventArgs e)
        {
            NotifyCollectionChangedAction enu = e.Action;

            if (enu.ToString() == "Add")
            {
                RibbonButton rbBtn = (RibbonButton)e.NewItems[0];
                if (rbBtn != null)
                    Ribbon.editor().WriteMessage(rbBtn.Id + " added\n");
            }
            else if (enu.ToString() == "Remove")
            {
                RibbonButton rbBtn1 = (RibbonButton)e.OldItems[0];
                if (rbBtn1 != null)
                    Ribbon.editor().WriteMessage(rbBtn1.Id + " removed\n");
            }
        }

        public static void RibbonToggle()
        {
            RibbonControl ribbonControl = ComponentManager.Ribbon;

            RibbonTab Tab1 = new RibbonTab();
            Tab1.Title = "LargeWithHorizontalText";
            Tab1.Id = "TESTRIBBON_TAB_ID";

            RibbonTab Tab2 = new RibbonTab();
            Tab2.Title = "LargeWithoutText";
            Tab2.Id = "TESTRIBBON_TAB_ID";

            RibbonTab Tab3 = new RibbonTab();
            Tab3.Title = "LargeWithText";
            Tab3.Id = "TESTRIBBON_TAB_ID";

            RibbonTab Tab4 = new RibbonTab();
            Tab4.Title = "NoStyle";
            Tab4.Id = "TESTRIBBON_TAB_ID";

            RibbonTab Tab5 = new RibbonTab();
            Tab5.Title = "SmallWithoutText";
            Tab5.Id = "TESTRIBBON_TAB_ID";

            RibbonTab Tab6 = new RibbonTab();
            Tab6.Title = "SmallWithText";
            Tab6.Id = "TESTRIBBON_TAB_ID";

            ribbonControl.Tabs.Add(Tab1);
            ribbonControl.Tabs.Add(Tab2);
            ribbonControl.Tabs.Add(Tab3);
            ribbonControl.Tabs.Add(Tab4);
            ribbonControl.Tabs.Add(Tab5);
            ribbonControl.Tabs.Add(Tab6);

            RibbonPanelSource srcPanel1 = new RibbonPanelSource();
            RibbonPanelSource srcPanel2 = new RibbonPanelSource();
            RibbonPanelSource srcPanel3 = new RibbonPanelSource();
            RibbonPanelSource srcPanel4 = new RibbonPanelSource();
            RibbonPanelSource srcPanel5 = new RibbonPanelSource();
            RibbonPanelSource srcPanel6 = new RibbonPanelSource();
            srcPanel1.Title = "RibbonPanelSourceTitle";

            RibbonPanel Panel1 = new RibbonPanel();
            Panel1.Source = srcPanel1;
            RibbonPanel Panel2 = new RibbonPanel();
            Panel2.Source = srcPanel2;
            RibbonPanel Panel3 = new RibbonPanel();
            Panel3.Source = srcPanel3;
            RibbonPanel Panel4 = new RibbonPanel();
            Panel4.Source = srcPanel4;
            RibbonPanel Panel5 = new RibbonPanel();
            Panel5.Source = srcPanel5;
            RibbonPanel Panel6 = new RibbonPanel();
            Panel6.Source = srcPanel6;

            Tab1.Panels.Add(Panel1);
            Tab2.Panels.Add(Panel2);
            Tab3.Panels.Add(Panel3);
            Tab4.Panels.Add(Panel4);
            Tab5.Panels.Add(Panel5);
            Tab6.Panels.Add(Panel6);

            RibbonToggleButton button1 = new RibbonToggleButton();
            RibbonToggleButton button2 = new RibbonToggleButton();
            RibbonToggleButton button3 = new RibbonToggleButton();
            RibbonToggleButton button4 = new RibbonToggleButton();
            RibbonToggleButton button5 = new RibbonToggleButton();
            RibbonToggleButton button6 = new RibbonToggleButton();

            button1.PropertyChanged += button1_PropertyChanged;

            button1.CheckState = false;
            button1.Text = "Toggle Button";
            button1.ImagePath = "circle";
            button1.CommandParameter = "pline";

            button1.ToolTip = "LargeWithHorizontalText";
            button1.ButtonStyle = RibbonButtonStyle.LargeWithHorizontalText;
            srcPanel1.Items.Add(button1);

            button2.Text = "Toggle Button";
            button2.ImagePath = "circle";
            button2.CommandParameter = "pline";
            button2.ToolTip = "LargeWithoutText";
            button2.ButtonStyle = RibbonButtonStyle.LargeWithoutText;
            srcPanel2.Items.Add(button2);

            button3.Text = "Toggle Button";
            button3.ImagePath = "circle";
            button3.CommandParameter = "pline";
            button3.ToolTip = "LargeWithText";
            button3.ButtonStyle = RibbonButtonStyle.LargeWithText;
            srcPanel3.Items.Add(button3);

            button4.Text = "Toggle Button";
            button4.ImagePath = "circle";
            button4.CommandParameter = "pline";
            button4.ToolTip = "NoStyle";
            button4.ButtonStyle = RibbonButtonStyle.NoStyle;
            srcPanel4.Items.Add(button4);

            button5.Text = "Toggle Button";
            button5.ImagePath = "circle";
            button5.CommandParameter = "pline";
            button5.ToolTip = "SmallWithoutText";
            button5.ButtonStyle = RibbonButtonStyle.SmallWithoutText;
            srcPanel5.Items.Add(button5);

            button6.Text = "Toggle Button";
            button6.ImagePath = "circle";
            button6.CommandParameter = "pline";
            button6.ToolTip = "SmallWithText";
            button6.ButtonStyle = RibbonButtonStyle.SmallWithText;
            srcPanel6.Items.Add(button6);
        }

        static void button1_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nThe property name is {0}", e.PropertyName);
        }

        public static void SplitButton()
        {
            RibbonControl ribbonControl = ComponentManager.Ribbon;

            /////////////////////////////////////
            // create Ribbon tab
            RibbonTab Tab = new RibbonTab();
            Tab.Title = "Test Ribbon";
            Tab.Id = "TESTRIBBON_TAB_ID";

            ribbonControl.Tabs.Add(Tab);

            RibbonTab Tab2 = new RibbonTab();
            Tab2.Title = "CloneSplitButton";
            Tab2.Id = "CloneSplitButton";

            ribbonControl.Tabs.Add(Tab2);
            /////////////////////////////////////
            // create Ribbon panel
            RibbonPanelSource srcPanel = new RibbonPanelSource();
            srcPanel.Title = "Panel1";

            RibbonPanel Panel = new RibbonPanel();
            Panel.Source = srcPanel;
            Tab.Panels.Add(Panel);

            RibbonPanelSource srcPanel2 = new RibbonPanelSource();
            srcPanel2.Title = "Panel2";

            RibbonPanel Panel2 = new RibbonPanel();
            Panel2.Source = srcPanel2;
            Tab2.Panels.Add(Panel2);

            //////////////////////////////////////////////////
            // create the buttons listed in the split button
            RibbonButton button1 = new RibbonButton();
            button1.Text = "Button1";
            button1.ImagePath = "rectang";

            RibbonButton button2 = new RibbonButton();
            button2.Text = "Button2";
            button2.ImagePath = "circle";

            ////////////////////////
            // create split button
            RibbonSplitButton ribSplitButton = new RibbonSplitButton();
            ribSplitButton.Text = "RibbonSplitButton";
            ribSplitButton.ToolTip = "Testing";
            ribSplitButton.ImagePath = "line";

            ribSplitButton.Items.Add(button1);
            ribSplitButton.Items.Add(button2);

            RibbonSplitButton clonedRibSplitButton = new RibbonSplitButton();
            clonedRibSplitButton = (RibbonSplitButton)ribSplitButton.Clone();
            clonedRibSplitButton.Items.Add(button1);
            clonedRibSplitButton.Items.Add(button2);

            srcPanel.Items.Add(ribSplitButton);
            srcPanel2.Items.Add(clonedRibSplitButton);
        }

        public static void RowPanelRowBreakSeparator()
        {
            RibbonControl rbnCtrl = ComponentManager.Ribbon;

            if (rbnCtrl != null)
            {
                //create Ribbon tab
                RibbonTab tab1 = new RibbonTab();
                tab1.Title = "Tab1";
                tab1.Id = "Tab1";
                RibbonTab tab2 = new RibbonTab();
                tab2.Title = "Tab2";
                tab2.Id = "Tab2";
                RibbonTab tab3 = new RibbonTab();
                tab3.Title = "Tab3";
                tab3.Id = "Tab3";
                RibbonTab tab4 = new RibbonTab();
                tab4.Title = "Tab4";
                tab4.Id = "Tab4";

                rbnCtrl.Tabs.CollectionChanged += Tabs_CollectionChanged;

                rbnCtrl.Tabs.Add(tab1);

                //create Ribbon panel
                RibbonPanelSource srcPanel1 = new RibbonPanelSource();
                srcPanel1.Title = "Panel1";
                srcPanel1.Id = "Panel1";
                RibbonPanel panel1 = new RibbonPanel();
                panel1.Source = srcPanel1;

                tab1.Panels.Add(panel1);

                RibbonPanelSource srcPanel2 = new RibbonPanelSource();
                srcPanel2.Id = "Panel2";
                srcPanel2.Title = "Panel2";
                RibbonPanel panel2 = new RibbonPanel();
                panel2.Source = srcPanel2;

                tab2.Panels.Add(panel2);

                RibbonPanelSource srcPanel3 = new RibbonPanelSource();
                srcPanel3.Id = "Panel3";
                srcPanel3.Title = "Panel3";
                RibbonPanel panel3 = new RibbonPanel();
                panel3.Source = srcPanel3;

                tab3.Panels.Add(panel3);

                RibbonPanelSource srcPanel4 = new RibbonPanelSource();
                srcPanel4.Id = "Panel4";
                srcPanel4.Title = "Panel4";
                RibbonPanel panel4 = new RibbonPanel();
                panel4.Source = srcPanel4;

                //buttons
                RibbonButton button1Panel1 = new RibbonButton();
                button1Panel1.ToolTip = "1";
                button1Panel1.Text = "This is a managed ribbon button from the panel with the title \"ManagedRibbonPanel1\"";
                button1Panel1.CommandParameter = "rectang";
                button1Panel1.ImagePath = "a_large.png";
                button1Panel1.Id = "1";

                RibbonButton button1Panel2 = new RibbonButton();
                button1Panel2.ToolTip = "2";
                button1Panel2.CommandParameter = "circle";
                button1Panel2.ImagePath = "circle_r";
                button1Panel2.Id = "2";

                RibbonButton button2Panel2 = new RibbonButton();
                button2Panel2.ToolTip = "3";
                button2Panel2.CommandParameter = "line";
                button2Panel2.ImagePath = "a_small.png";
                button2Panel2.Text = "These are managed ribbon buttons from the panel with the title \"ManagedRibbonPanel2\"";
                button2Panel2.Id = "3";

                //buttons
                RibbonButton button1Panel3 = new RibbonButton();
                button1Panel3.ToolTip = "4";
                button1Panel3.CommandParameter = "pline";
                button1Panel3.ImagePath = "pline";
                button1Panel3.Id = "4";

                RibbonButton button2Panel3 = new RibbonButton();
                button2Panel3.ToolTip = "5";
                button2Panel3.CommandParameter = "ellipse";
                button2Panel3.ImagePath = "ellipse_";
                button2Panel3.Id = "5";

                RibbonButton button3Panel3 = new RibbonButton();
                button3Panel3.ToolTip = "6";
                button3Panel3.CommandParameter = "Box";
                button3Panel3.ImagePath = "acis_box";
                button3Panel3.Text = "These are managed ribbon buttons from the panel with the title \"ManagedRibbonPanel3\"";
                button3Panel3.Id = "6";

                RibbonRowPanel pan1row1 = new RibbonRowPanel();
                pan1row1.Items.Add(button1Panel1);
                pan1row1.Items.Add(new RibbonRowBreak());
                pan1row1.Items.Add(button2Panel2);
                pan1row1.Items.Add(new RibbonSeparator());
                pan1row1.Items.Add(button3Panel3);
                pan1row1.Items.Add(new RibbonRowBreak());
                pan1row1.Items.Add(button3Panel3);
                srcPanel1.Items.Add(pan1row1);
            }
        }

        public static void AddClonedObjects()
        {
            RibbonControl rbnCtrl = ComponentManager.Ribbon;

            //create Cloned Ribbon tab
            RibbonTab tab1 = new RibbonTab();
            tab1.Title = "Tab1";
            tab1.Name = "Tab1";
            tab1.Id = "Tab1";

            RibbonTab clonedTab = tab1.Clone();

            RibbonTab tab2 = new RibbonTab();
            tab2.Title = "Tab2";
            tab2.Name = "Tab2";
            tab2.Id = "Tab2";

            RibbonTab clonedTab2 = tab2.Clone();

            rbnCtrl.Tabs.Add(tab1);
            rbnCtrl.Tabs.Add(clonedTab);
            rbnCtrl.Tabs.Add(tab2);
            rbnCtrl.Tabs.Add(clonedTab2);

            //create Cloned Ribbon panel
            RibbonPanelSource srcPanel1 = new RibbonPanelSource();
            srcPanel1.Title = "Panel1";
            srcPanel1.Id = "Panel1";
            RibbonPanel panel1 = new RibbonPanel();
            panel1.Source = srcPanel1;

            tab1.Panels.Add(panel1);

            RibbonPanelSource clonedSrcPanel1 = srcPanel1.Clone();
            RibbonPanel clonedPanel = panel1.Clone();
            clonedPanel.Source = clonedSrcPanel1;

            clonedTab.Panels.Add(clonedPanel);

            RibbonPanelSource srcPanel2 = new RibbonPanelSource();
            srcPanel2.Title = "Panel2";
            srcPanel2.Id = "Panel2";
            RibbonPanel panel2 = new RibbonPanel();
            panel2.Source = srcPanel2;

            tab2.Panels.Add(panel2);

            RibbonPanelSource clonedSrcPanel2 = srcPanel2.Clone();
            RibbonPanel clonedPanel2 = panel2.Clone();
            clonedPanel2.Source = clonedSrcPanel2;

            clonedTab2.Panels.Add(clonedPanel2);

            //buttons
            RibbonButton button1 = new RibbonButton();
            button1.ToolTip = "1";
            button1.Text = "button1";
            button1.CommandParameter = "circle";
            button1.ImagePath = "circle";
            button1.Id = "1";

            //Cloned button
            RibbonButton clonedButton1 = (RibbonButton)button1.Clone();

            RibbonToggleButton toggleButton = new RibbonToggleButton();
            toggleButton.Text = "Toggle Button";
            toggleButton.Id = "1";
            toggleButton.ImagePath = "rectang";
            toggleButton.CommandParameter = "pline";
            toggleButton.ToolTip = "LargeWithHorizontalText";

            RibbonToggleButton clonedToggleButton = (RibbonToggleButton)toggleButton.Clone();

            RibbonButton clonedButton = (RibbonButton)button1.Clone();
            RibbonButton clonedClonedButton = (RibbonButton)clonedButton1.Clone();
            RibbonToggleButton clonedToggleButton1 = (RibbonToggleButton)toggleButton.Clone();
            RibbonToggleButton clonedclonedToggleButton1 = (RibbonToggleButton)clonedToggleButton.Clone();

            RibbonRowPanel pan1row1 = new RibbonRowPanel();
            pan1row1.Items.Add(clonedButton);
            pan1row1.Items.Add(new RibbonRowBreak());
            pan1row1.Items.Add(clonedToggleButton1);
            pan1row1.Items.Add(new RibbonSeparator());
            pan1row1.Items.Add(clonedClonedButton);
            pan1row1.Items.Add(new RibbonRowBreak());
            pan1row1.Items.Add(clonedclonedToggleButton1);

            RibbonRowPanel clonedpan1row1 = (RibbonRowPanel)pan1row1.Clone();

            srcPanel1.Items.Add(button1);
            srcPanel1.Items.Add(toggleButton);

            srcPanel2.Items.Add(pan1row1);

            clonedSrcPanel1.Items.Add(clonedButton1);
            clonedSrcPanel1.Items.Add(clonedToggleButton);

            clonedSrcPanel2.Items.Add(clonedpan1row1);
        }

        public static void AddRibbonComboRibbonTextBox()
        {
            RibbonControl rbnCtrl = ComponentManager.Ribbon;

            RibbonTab tab = new RibbonTab();

            tab.PropertyChanged += tab_PropertyChanged;

            tab.Title = "Tab1";
            tab.Name = "Tab1";
            tab.Id = "Tab1";

            RibbonPanelSource srcPanel = new RibbonPanelSource();
            srcPanel.Title = "Panel1";
            srcPanel.Name = "Name";
            srcPanel.Id = "Panel1";
            RibbonPanel panel = new RibbonPanel();
            panel.Source = srcPanel;

            RibbonTextBox textBox = new RibbonTextBox();
            textBox.ShowText = true;
            textBox.ShowImage = true;
            textBox.TextValue = "TextValue";
            textBox.Text = "Text";
            textBox.ImagePath = "circle";
            srcPanel.Items.Add(textBox);

            RibbonCombo ribCombo = new RibbonCombo();
            RibbonRowPanel ribRowPan = new RibbonRowPanel();
            ribRowPan.Items.Add(ribCombo);
            srcPanel.Items.Add(ribRowPan);

            RibbonButton button1 = new RibbonButton();
            button1.ToolTip = "1";
            button1.Text = "button1";
            button1.CommandParameter = "circle";
            button1.ImagePath = "circle";
            button1.Id = "1";

            RibbonButton button2 = new RibbonButton();
            button2.ToolTip = "2";
            button2.CommandParameter = "line";
            button2.ImagePath = "a_small.png";
            button2.Text = "These are managed ribbon buttons from the panel with the title \"ManagedRibbonPanel2\"";
            button2.Id = "2";

            ribCombo.DropDownOpened += ribCombo_DropDownOpened;
            ribCombo.DropDownClosed += ribCombo_DropDownClosed;
            ribCombo.CurrentChanged += ribCombo_CurrentChanged;

            ribCombo.Items.Add(button1);
            ribCombo.Items.Add(button2);
            ribCombo.Current = button2;


            tab.Panels.Add(panel);
            rbnCtrl.Tabs.Add(tab);


        }

        public static void addWPFControls()
        {
            RibbonControl rbnCtrl = ComponentManager.Ribbon;

            if (rbnCtrl == null)
                return;
            RibbonPanelSource srcPanel = new RibbonPanelSource();
            srcPanel.Title = "Panel hosting WPF Controls";
            srcPanel.Id = "PanelWithWPF";
            RibbonPanel panel = new RibbonPanel();
            panel.Source = srcPanel;
            RibbonTab tab = new RibbonTab();
            tab.Title = "Tab with WPF Controls";
            tab.Id = "TabWPF";

            tab.Panels.Add(panel);
            rbnCtrl.Tabs.Add(tab);

            System.Windows.Controls.StackPanel wrapPanel = new System.Windows.Controls.StackPanel();
            wrapPanel.HorizontalAlignment = System.Windows.HorizontalAlignment.Stretch;

            System.Windows.Controls.Button myButton = new System.Windows.Controls.Button();
            myButton.Content = "Click Me";
            myButton.ToolTip = "ceva";
            myButton.HorizontalAlignment = System.Windows.HorizontalAlignment.Center;
            myButton.Click += myButton_Click;

            wrapPanel.Children.Add(myButton);

            System.Windows.Controls.ListBox listBox = new System.Windows.Controls.ListBox();
            listBox.Items.Add("Item 1");
            listBox.Items.Add("Item 2");
            listBox.HorizontalAlignment = System.Windows.HorizontalAlignment.Stretch;

            wrapPanel.Children.Add(listBox);

            System.Windows.Controls.ComboBox comboBox = new System.Windows.Controls.ComboBox();
            comboBox.Items.Add("Combo item 1");
            comboBox.Items.Add("Combo item 2");
            comboBox.Items.Add("Combo item 3");
            comboBox.SelectedIndex = 1;

            wrapPanel.Children.Add(comboBox);
            panel.SetWPFControl(wrapPanel, "test");
        }

        public static void addRibbonPanelBreak()
        {
            RibbonControl rbnCtrl = ComponentManager.Ribbon;

            RibbonTab tab = new RibbonTab();

            tab.PropertyChanged += tab_PropertyChanged;

            tab.Title = "Tab1";
            tab.Name = "Tab1";
            tab.Id = "Tab1";

            RibbonPanelSource srcPanel = new RibbonPanelSource();
            srcPanel.Title = "Panel with slide out panel";
            srcPanel.Name = "Name";
            srcPanel.Id = "Panel1";
            RibbonPanel panel = new RibbonPanel();
            panel.Source = srcPanel;

            RibbonTextBox textBox = new RibbonTextBox();
            textBox.ShowText = true;
            textBox.ShowImage = true;
            textBox.TextValue = "TextValue";
            textBox.Text = "Text";
            textBox.ImagePath = "circle";
            srcPanel.Items.Add(textBox);

            // Adding a panel break so the next items will be moved to the slide out panel
            srcPanel.Items.Add(new RibbonPanelBreak());

            RibbonCombo ribCombo = new RibbonCombo();
            srcPanel.Items.Add(ribCombo);

            ribCombo.DropDownOpened += ribCombo_DropDownOpened;
            ribCombo.DropDownClosed += ribCombo_DropDownClosed;
            ribCombo.CurrentChanged += ribCombo_CurrentChanged;

            RibbonButton button1 = new RibbonButton();
            button1.ToolTip = "1";
            button1.Text = "Button 1";
            button1.CommandParameter = "circle";
            button1.ImagePath = "circle";
            button1.Id = "1";

            RibbonButton button2 = new RibbonButton();
            button2.ToolTip = "2";
            button2.CommandParameter = "line";
            button2.ImagePath = "a_small.png";
            button2.Text = "Button 2";
            button2.Id = "2";

            ribCombo.Items.Add(button1);
            ribCombo.Items.Add(button2);
            ribCombo.Current = button2;

            button1 = (RibbonButton)button1.Clone();
            srcPanel.Items.Add(button1);


            tab.Panels.Add(panel);
            rbnCtrl.Tabs.Add(tab);
        }

        static void ribCombo_CurrentChanged(object sender, EventArgs e)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nCurrentChanged\n");
        }

        static void ribCombo_DropDownClosed(object sender, EventArgs e)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nDropDownClosed\n");
        }

        static void ribCombo_DropDownOpened(object sender, EventArgs e)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nDropDownOpened\n");
        }

        static void tab_PropertyChanged(object sender, System.ComponentModel.PropertyChangedEventArgs e)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nTab PropertyChanged\n");
        }

        static void myButton_Click(object sender, System.Windows.RoutedEventArgs e)
        {
            Application.DocumentManager.MdiActiveDocument.Editor.WriteMessage("\nWPF button was clicked\n"); ;
        }
    };
}

