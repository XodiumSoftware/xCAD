using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Collections.ObjectModel;

using _AcAp = Bricscad.ApplicationServices;

namespace CsBrxMgd
{
    /// <summary>
    /// Interaction logic for CsMgdSamples.xaml
    /// </summary>
    public partial class CsMgdSamples : UserControl
    {
        public CsMgdSamples()
        {
            InitializeComponent();
        }

        private void TreeViewItem_MouseDoubleClick(object sender, RoutedEventArgs e)
        {
            TreeViewItem item = sender as TreeViewItem;
            if (item == null)
                return;
            string command = item.Name;
            if (command.Length > 0)
            {
                command = command.Replace("_", " ");
                if (command.StartsWith("lisp"))
                    command = "(" + command + ")";
                _AcAp.Application.DocumentManager.CurrentDocument.SendStringToExecute(command + "\n", false, false, true);
            }
        }
    }
}
