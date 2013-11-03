using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Collections;
using System.IO;


namespace ClassGenerator
{
    public partial class Form1 : Form
    {

        const int NO_CLASSTYPE = 0;
        const int SCENE_CLASSTYPE = 1;
        const int GAMEOBJECT_CLASSTYPE = 2;

        public int ClassType;

        public List<string> DataTypeList;

        public List<string> PrivateVariableList = new List<string>();
        public List<string> PublicVariableList = new List<string>();
        public List<string> ProtectedVariableList = new List<string>();

        public List<string> PrivateMethodList = new List<string>();
        public List<string> PublicMethodList = new List<string>();
        public List<string> ProtectedMethodList = new List<string>();

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            GameObjectSelector.Select();
            GenerateButton.Select();

            DataTypeList = GetDataTypeList();

            SetUpAddFunctionality();
        }

        private void SetUpAddFunctionality()
        {
            List<string> AccessList = new List<string> { "private", "public", "protected" };

            VariableAccessListBox.DataSource = new List<string>(AccessList);

            VariableDataTypeListBox.DataSource = new List<string>(DataTypeList);

            MethodAccessListBox.DataSource = new List<string>(AccessList);

            MethodReturnTypeListBox.DataSource = new List<string>(DataTypeList);
        }

        private List<string> GetDataTypeList()
        {
            List<string> list = new List<string>();

            //string winDir = System.Environment.GetEnvironmentVariable("windir");

            try
            {
                StreamReader reader = new StreamReader("dataTypes.txt");

                do
                {
                    list.Add(reader.ReadLine());
                }
                while (reader.Peek() != -1);

                reader.Close();

            }
            catch
            {
                MessageBox.Show("Failed to load existing datatypes");
            }

            return list;
        }

        private void GenerateButton_Click(object sender, EventArgs e)
        {
            // create class
        }

        private void ClearButton_Click(object sender, EventArgs e)
        {
            PrivateVariableList.Clear();
            PublicVariableList.Clear();
            ProtectedVariableList.Clear();

            PrivateMethodList.Clear();
            PublicMethodList.Clear();
            ProtectedMethodList.Clear();

            ClassNameTextBox.Text = "";

            NoBaseObjectButton.Select();
            GameObjectSelector.Select();

            UserNameBox.Text = "";
            DescriptionBox.Text = "";

            PublicVariableDisplay.DataSource = new List<string>(PublicVariableList);
            PrivateVariableDisplay.DataSource = new List<string>(PrivateVariableList);
            ProtectedVariableDisplay.DataSource = new List<string>(ProtectedVariableList);

            PrivateMethodDisplay.DataSource = new List<string>(PrivateMethodList);
            PublicMethodDisplay.DataSource = new List<string>(PublicMethodList);
            ProtectedMethodDisplay.DataSource = new List<string>(ProtectedMethodList);
        }

        private void CancelButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void ScreenSelector_CheckedChanged(object sender, EventArgs e)
        {
            ClassType = SCENE_CLASSTYPE;
            CreateCheck.Enabled = false;
            InitCheck.Enabled = true;
            UpdateCheck.Enabled = true;
            RenderCheck.Enabled = true;
        }

        private void GameObjectSelector_CheckedChanged(object sender, EventArgs e)
        {
            ClassType = GAMEOBJECT_CLASSTYPE;
            CreateCheck.Enabled = true;
            InitCheck.Enabled = true;
            UpdateCheck.Enabled = true;
            RenderCheck.Enabled = true;
        }

        private void NoBaseObjectButton_CheckedChanged(object sender, EventArgs e)
        {
            ClassType = NO_CLASSTYPE;

            CreateCheck.Enabled = false;
            InitCheck.Enabled = false;
            UpdateCheck.Enabled = false;
            RenderCheck.Enabled = false;
        }

        private void CreateCheck_EnabledChanged(object sender, EventArgs e)
        {
            if (!CreateCheck.Enabled)
            {
                CreateCheck.Checked = false;
            }
        }

        private void InitCheck_EnabledChanged(object sender, EventArgs e)
        {
            if (!InitCheck.Enabled)
            {
                InitCheck.Checked = false;
            }
        }

        private void UpdateCheck_EnabledChanged(object sender, EventArgs e)
        {
            if (!UpdateCheck.Enabled)
            {
                UpdateCheck.Checked = false;
            }
        }

        private void RenderCheck_EnabledChanged(object sender, EventArgs e)
        {
            if (!RenderCheck.Enabled)
            {
                RenderCheck.Checked = false;
            }
        }

        private void AddNewVariable_Click(object sender, EventArgs e)
        {
            string VariableDecl;

            VariableDecl = VariableDataTypeListBox.Text.ToString();

            if (VariablePointer.Checked == true)
                VariableDecl += "* ";
            else
                VariableDecl += " ";

            VariableDecl += VariableNameBox.Text.ToString() + ";";

            switch (VariableAccessListBox.Text.ToString())
            {
                case "private":
                    PrivateVariableList.Add(VariableDecl);
                    PrivateVariableDisplay.DataSource = new List<string>(PrivateVariableList);
                    break;
                case "public":
                    PublicVariableList.Add(VariableDecl);
                    PublicVariableDisplay.DataSource = new List<string>(PublicVariableList);
                    break;
                case "protected":
                    ProtectedVariableList.Add(VariableDecl);
                    ProtectedVariableDisplay.DataSource = new List<string>(ProtectedVariableList);
                    break;
            }

            VariablePointer.Checked = false;
            VariableNameBox.Text = "";
        }

        private void AddMethod_Click(object sender, EventArgs e)
        {
            string MethodDecl;

            MethodDecl = MethodReturnTypeListBox.Text.ToString();

            if (MethodReturnPointer.Checked == true)
                MethodDecl += "* ";
            else
                MethodDecl += " ";

            MethodDecl += MethodNameBox.Text.ToString() + "(";
            MethodDecl += MethodParametersBox.Text.ToString() + ");";

            switch (MethodAccessListBox.Text.ToString())
            {
                case "private":
                    PrivateMethodList.Add(MethodDecl);
                    PrivateMethodDisplay.DataSource = new List<string>(PrivateMethodList);
                    break;
                case "public":
                    PublicMethodList.Add(MethodDecl);
                    PublicMethodDisplay.DataSource = new List<string>(PublicMethodList);
                    break;
                case "protected":
                    ProtectedMethodList.Add(MethodDecl);
                    ProtectedMethodDisplay.DataSource = new List<string>(ProtectedMethodList);
                    break;
            }

            MethodNameBox.Text = "";
            MethodParametersBox.Text = "";
        }

        private void PrivateVariableDisplay_KeyDown(object sender, KeyEventArgs e)
        {
            MessageBox.Show("KeyPressed");
        }
    }
}
