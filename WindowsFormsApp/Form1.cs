using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using CLRLibrary;

namespace WindowsFormsApp
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonExecute_Click(object sender, EventArgs e)
        {
            int value = int.Parse(textBoxValue.Text);
            string text = textBoxText.Text;

            CLRClass clrClass = new CLRClass();
            clrClass.SetValue(value);
            clrClass.SetText(text);

            string output = clrClass.GetOutput();
            textBoxOutput.Text = output;
        }
    }
}
