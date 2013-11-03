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

            try
            {
                StreamReader reader = new StreamReader("ClassGeneratorFiles\\dataTypes.txt");

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
            if (GenerateHeader() &&
                GenerateCpp() &&
                AddToProjectIncludes() &&
                AddToVCXProj() &&
                AddToVCXFilters() &&
                AddToDataTypes())
            {
                MessageBox.Show("Class successfully generated");
                ClearPage();
            }
            else
                MessageBox.Show("Class Generation failed");
        }

        private void ClearButton_Click(object sender, EventArgs e)
        {
            ClearPage();
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

            VariableDecl += VariableNameBox.Text.ToString();

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
            MethodDecl += MethodParametersBox.Text.ToString() + ")";

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
            if (e.KeyCode == Keys.Delete)
            {
                if (PrivateVariableList.Capacity > 0)
                {
                    String selected = PrivateVariableDisplay.SelectedItem.ToString();

                    PrivateVariableList.Remove(selected);

                    PrivateVariableDisplay.DataSource = new List<string>(PrivateVariableList);
                }
            }
        }

        private void PublicVariableDisplay_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                if (PublicVariableList.Capacity > 0)
                {
                    String selected = PublicVariableDisplay.SelectedItem.ToString();

                    PublicVariableList.Remove(selected);

                    PublicVariableDisplay.DataSource = new List<string>(PublicVariableList);
                }
            }
        }

        private void ProtectedVariableDisplay_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                if (ProtectedVariableList.Capacity > 0)
                {
                    String selected = ProtectedVariableDisplay.SelectedItem.ToString();

                    ProtectedVariableList.Remove(selected);

                    ProtectedVariableDisplay.DataSource = new List<string>(ProtectedVariableList);
                }
            }
        }

        private void PrivateMethodDisplay_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                if (PrivateMethodList.Capacity > 0)
                {
                    String selected = PrivateMethodDisplay.SelectedItem.ToString();

                    PrivateMethodList.Remove(selected);

                    PrivateMethodDisplay.DataSource = new List<string>(PrivateMethodList);
                }
            }
        }

        private void PublicMethodDisplay_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                if (PublicMethodList.Count > 0)
                {
                    String selected = PublicMethodDisplay.SelectedItem.ToString();

                    PublicMethodList.Remove(selected);

                    PublicMethodDisplay.DataSource = new List<string>(PublicMethodList);
                }
            }
        }

        private void ProtectedMethodDisplay_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Delete)
            {
                if(ProtectedMethodList.Count > 0)
                {
                    String selected = ProtectedMethodDisplay.SelectedItem.ToString();

                    ProtectedMethodList.Remove(selected);

                    ProtectedMethodDisplay.DataSource = new List<string>(ProtectedMethodList);
                }
            }
        }

        private void ClearPage()
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

        private bool GenerateHeader()
        {
            List<string> buff = new List<string>();

            // load the header template
            try
            {
                StreamReader reader = new StreamReader("ClassGeneratorFiles\\HTemplate.txt");

                do
                {
                    buff.Add(reader.ReadLine());
                }
                while (reader.Peek() != -1);

                reader.Close();
            }
            catch
            {
                return false;
            }

            // alter the loaded template to include the data input
            for(int i = 0; i < buff.Count; ++i)
            {
                // create define macros
                if (buff[i] == "#ifndef")
                    buff[i] += " _" + ClassNameTextBox.Text.ToUpper() +"_H_";
                if (buff[i] == "#define")
                    buff[i] += " _" + ClassNameTextBox.Text.ToUpper() + "_H_";

                // add inheritance decl if required
                if (buff[i] == "class CLASSNAME")
                {
                    if (GameObjectSelector.Checked)
                    {
                        buff[i] += " : public GameObject";
                    }
                    else if (ScreenSelector.Checked)
                    {
                        buff[i] += " : public Screen";
                    }
                }

                // replace all classname tags with the users classname
                buff[i] = buff[i].Replace("CLASSNAME", ClassNameTextBox.Text.ToString());

                // add username and description
                if (buff[i] == "USERNAME")
                    buff[i] = "// Created by: " + UserNameBox.Text.ToString();
                if (buff[i] == "DESCRIPTION")
                    buff[i] = "// " + DescriptionBox.Text.ToString();

                // insert private variables and functions
                if (buff[i] == "private:")
                {
                    for (int j = 0; j < PrivateVariableList.Count; ++j)
                    {
                        buff.Insert(i + 3, "\t" + PrivateVariableList[j].ToString() + ";");
                        ++i;
                    }

                    for (int j = 0; j < PrivateMethodList.Count; ++j)
                    {
                        buff.Insert(i + 4, "\t" + PrivateMethodList[j].ToString() + ";");
                        ++i;
                    }
                }

                // insert protected variables and functions
                if (buff[i] == "protected:")
                {
                    for (int j = 0; j < ProtectedVariableList.Count; ++j)
                    {
                        buff.Insert(i + 1, "\t" + ProtectedVariableList[j].ToString() + ";");
                        ++i;
                    }

                    for (int j = 0; j < ProtectedMethodList.Count; ++j)
                    {
                        buff.Insert(i + 2, "\t" + ProtectedMethodList[j].ToString() + ";");
                        ++i;
                    }
                }

                // insert public variables and functions
                if (buff[i] == "public:")
                {
                    // ensure that the constructor and destructor match the class name
                    buff[i+1] = buff[i+1].Replace("CLASSNAME", ClassNameTextBox.Text.ToString());
                    buff[i+2] = buff[i+2].Replace("CLASSNAME", ClassNameTextBox.Text.ToString());
                    buff[i+3] = buff[i+3].Replace("CLASSNAME", ClassNameTextBox.Text.ToString());

                    for (int j = 0; j < PublicVariableList.Count; ++j)
                    {
                        buff.Insert(i + 5, "\t" + PublicVariableList[j].ToString() + ";");
                        ++i;
                    }

                    for (int j = 0; j < PublicMethodList.Count; ++j)
                    {
                        buff.Insert(i + 6, "\t" + PublicMethodList[j].ToString() + ";");
                        ++i;
                    }
                }

                // add required inherited functions
                if (buff[i] == "};")
                {
                    if (CreateCheck.Checked)
                    {
                        buff.Insert(i, "\tvoid Create();");
                        ++i;
                    }
                    if (InitCheck.Checked)
                    {
                        buff.Insert(i, "\tvoid Init();");
                        ++i;
                    }
                    if (UpdateCheck.Checked)
                    {
                        buff.Insert(i, "\tvoid Update(float deltaTime);");
                        ++i;
                    }
                    if (RenderCheck.Checked)
                    {
                        buff.Insert(i, "\tvoid Render();");
                        ++i;
                    }
                }
            }

            StreamWriter output = new StreamWriter("source\\" + ClassNameTextBox.Text.ToString() + ".h");

            // write buffer to file
            for (int i = 0; i < buff.Count; ++i)
            {
                output.WriteLine(buff[i]);
            }
   
            output.Close();

            return true;
        }

        private bool GenerateCpp()
        {
            List<string> buff = new List<string>();

            String functionTemplate = "";

            try
            {
                StreamReader reader = new StreamReader("ClassGeneratorFiles\\CppTemplate.txt");

                do
                {
                    buff.Add(reader.ReadLine());
                }
                while (reader.Peek() != -1);

                reader.Close();
            }
            catch
            {
                return false;
            }

            // alter the loaded template to include the input data
            for (int i = 0; i < buff.Count; ++i)
            {
                // add in call to base object constructor if required
                if (buff[i] == "CLASSNAME::CLASSNAME(char* name)")
                {
                    if (GameObjectSelector.Checked)
                        buff[i] += " : GameObject(name, " + ClassNameTextBox.Text.ToUpper() +"_OBJECT)";
                }

                // get the function template for future functions
                if (buff[i] == "RETURNTYPE CLASSNAME::FUNCTIONNAME(ARGS1ARGS2ARGS3ARGS4ARGS5ARGS6)")
                {
                    functionTemplate = buff[i].Replace("CLASSNAME", ClassNameTextBox.Text.ToString());
                    buff[i] = buff[i].Remove(0);
                }
                // replace classname take with users classname
                buff[i] = buff[i].Replace("CLASSNAME", ClassNameTextBox.Text.ToString());
            }

            // add in the functions input by the user.
            foreach (string s in PrivateMethodList)
            {
                // split function in list into [0] = return, [1] = name, [2] = args
                char[] seperators = {' ', '(', ')'};
                string[] functionData = s.Split(seperators);

                // copy function template
                string function = functionTemplate;

                // replace the function tags with the required data
                function = function.Replace("RETURNTYPE", functionData[0].ToString());
                function = function.Replace("FUNCTIONNAME", functionData[1].ToString());
                //replace args with input args
                for (int i = 2; i < functionData.Length-1; ++i)
                {
                    function = function.Replace("ARGS" + (i - 1).ToString(), functionData[i].ToString() + " " + functionData[++i].ToString());

                }
                // replace any args tags that werent overwridden with nothing
                function = function.Replace("ARGS1", "");
                function = function.Replace("ARGS2", "");
                function = function.Replace("ARGS3", "");
                function = function.Replace("ARGS4", "");
                function = function.Replace("ARGS5", "");
                function = function.Replace("ARGS6", "");

                // add the function to the buffer
                buff.Add(function);
                buff.Add("{");
                buff.Add("\tdebugPrint(debugClassName, \"" + functionData[1].ToString() + "\");");
                buff.Add("}");
                buff.Add("");
            }

            foreach (string s in ProtectedMethodList)
            {
                // split function in list into [0] = return, [1] = name, [2] = args
                char[] seperators = { ' ', '(', ')' };
                string[] functionData = s.Split(seperators);

                // copy function template
                string function = functionTemplate;

                // replace the function tags with the required data
                function = function.Replace("RETURNTYPE", functionData[0].ToString());
                function = function.Replace("FUNCTIONNAME", functionData[1].ToString());
                //replace args with input args
                for (int i = 2; i < functionData.Length-1; ++i)
                {
                    function = function.Replace("ARGS" + (i - 1).ToString(), functionData[i].ToString() + " " + functionData[++i].ToString());
                }
                // replace any args tags that werent overwridden with nothing
                function = function.Replace("ARGS1", "");
                function = function.Replace("ARGS2", "");
                function = function.Replace("ARGS3", "");
                function = function.Replace("ARGS4", "");
                function = function.Replace("ARGS5", "");
                function = function.Replace("ARGS6", "");

                // add the function to the buffer
                buff.Add(function);
                buff.Add("{");
                buff.Add("\tdebugPrint(debugClassName, \"" + functionData[1].ToString() + "\");");
                buff.Add("}");
                buff.Add("");
            }

            foreach (string s in PublicMethodList)
            {
                // split function in list into [0] = return, [1] = name, [2] = args
                char[] seperators = { ' ', '(', ')' };
                string[] functionData = s.Split(seperators);

                // copy function template
                string function = functionTemplate;

                // replace the function tags with the required data
                function = function.Replace("RETURNTYPE", functionData[0].ToString());
                function = function.Replace("FUNCTIONNAME", functionData[1].ToString());
                //replace args with input args
                for (int i = 2; i < functionData.Length-1; ++i)
                {
                    function = function.Replace("ARGS" + (i - 1).ToString(), functionData[i].ToString() + " " + functionData[++i].ToString());
                }
                // replace any args tags that werent overwridden with nothing
                function = function.Replace("ARGS1", "");
                function = function.Replace("ARGS2", "");
                function = function.Replace("ARGS3", "");
                function = function.Replace("ARGS4", "");
                function = function.Replace("ARGS5", "");
                function = function.Replace("ARGS6", "");

                // add the function to the buffer
                buff.Add(function);
                buff.Add("{");
                buff.Add("\tdebugPrint(debugClassName, \"" + functionData[1].ToString() + "\");");
                buff.Add("}");
                buff.Add("");
            }

            if (CreateCheck.Checked)
            {
                // copy function template
                string function = functionTemplate;

                // replace the function tags with the required data
                function = function.Replace("RETURNTYPE", "void");
                function = function.Replace("FUNCTIONNAME", "Create");
                // replace any args tags that werent overwridden with nothing
                function = function.Replace("ARGS1", "");
                function = function.Replace("ARGS2", "");
                function = function.Replace("ARGS3", "");
                function = function.Replace("ARGS4", "");
                function = function.Replace("ARGS5", "");
                function = function.Replace("ARGS6", "");

                // add the function to the buffer
                buff.Add(function);
                buff.Add("{");
                buff.Add("\tdebugPrint(debugClassName, \"Create\");");
                buff.Add("}");
                buff.Add("");
            }

            if (InitCheck.Checked)
            {
                // copy function template
                string function = functionTemplate;

                // replace the function tags with the required data
                function = function.Replace("RETURNTYPE", "void");
                function = function.Replace("FUNCTIONNAME", "Init");
                // replace any args tags that werent overwridden with nothing
                function = function.Replace("ARGS1", "");
                function = function.Replace("ARGS2", "");
                function = function.Replace("ARGS3", "");
                function = function.Replace("ARGS4", "");
                function = function.Replace("ARGS5", "");
                function = function.Replace("ARGS6", "");

                // add the function to the buffer
                buff.Add(function);
                buff.Add("{");
                buff.Add("\tdebugPrint(debugClassName, \"Init\");");
                buff.Add("}");
                buff.Add("");
            }

            if (UpdateCheck.Checked)
            {
                // copy function template
                string function = functionTemplate;

                // replace the function tags with the required data
                function = function.Replace("RETURNTYPE", "void");
                function = function.Replace("FUNCTIONNAME", "Update");
                function = function.Replace("ARGS1", "float deltaTime");

                // replace any args tags that werent overwridden with nothing
                function = function.Replace("ARGS2", "");
                function = function.Replace("ARGS3", "");
                function = function.Replace("ARGS4", "");
                function = function.Replace("ARGS5", "");
                function = function.Replace("ARGS6", "");

                // add the function to the buffer
                buff.Add(function);
                buff.Add("{");
                buff.Add("\tdebugPrint(debugClassName, \"Update\");");
                buff.Add("}");
                buff.Add("");
            }

            if (RenderCheck.Checked)
            {
                // copy function template
                string function = functionTemplate;

                // replace the function tags with the required data
                function = function.Replace("RETURNTYPE", "void");
                function = function.Replace("FUNCTIONNAME", "Render");

                // replace any args tags that werent overwridden with nothing
                function = function.Replace("ARGS1", "");
                function = function.Replace("ARGS2", "");
                function = function.Replace("ARGS3", "");
                function = function.Replace("ARGS4", "");
                function = function.Replace("ARGS5", "");
                function = function.Replace("ARGS6", "");

                // add the function to the buffer
                buff.Add(function);
                buff.Add("{");
                buff.Add("\tdebugPrint(debugClassName, \"Render\");");
                buff.Add("}");
                buff.Add("");
            }

            StreamWriter output = new StreamWriter("source\\" + ClassNameTextBox.Text.ToString() + ".cpp");

            for (int i = 0; i < buff.Count; ++i)
            {
                output.WriteLine(buff[i]);
            }

            output.Close();

            return true;
        }

        private bool AddToProjectIncludes()
        {
            List<string> buff = new List<string>();
            try
            {
                StreamReader reader = new StreamReader("source\\GameIncludes.h");

                do
                {
                    buff.Add(reader.ReadLine());
                }
                while (reader.Peek() != -1);

                reader.Close();
            }
            catch
            {
                return false;
            }

            bool countObjects = false;
            int objectCount = -1;

            for(int i = 0; i < buff.Count; ++i)
            {
                if (buff[i] == "//insertNewIncludeHere")
                {
                    buff.Insert(i, "#include \"" + ClassNameTextBox.Text.ToString() + ".h\"");
                    i++;
                }

                if (countObjects)
                    ++objectCount;

                if (buff[i] == "//ObjectTypes")
                    countObjects = true;

                if (buff[i] == "//insertNewObjectTypeHere")
                {
                    buff.Insert(i, "#define " + ClassNameTextBox.Text.ToUpper() + "_OBJECT " + objectCount.ToString());
                    i++;
                }
            }

            StreamWriter output = new StreamWriter("source\\GameIncludes.h");

            for (int i = 0; i < buff.Count; ++i)
            {
                output.WriteLine(buff[i]);
            }

            output.Close();

            return true;
        }

        public bool AddToVCXProj()
        {
            int numItemGroupsCpp = 3;
            int numItemGroupsH = 4;

            List<string> buff = new List<string>();

            try
            {
                StreamReader reader = new StreamReader("BulletTest.vcxproj");

                do
                {
                    buff.Add(reader.ReadLine());
                }
                while (reader.Peek() != -1);

                reader.Close();
            }
            catch
            {
                return false;
            }

            int count = 0;
            bool cppAdded = false;
            bool hAdded = false;

            for (int i = 0; i < buff.Count; ++i)
            {
                if (buff[i].Contains("</ItemGroup>"))
                {
                    count++;
                }

                if ((count == numItemGroupsCpp) && (!cppAdded))
                {
                    buff.Insert(i, "    <ClCompile Include=\"source\\" + ClassNameTextBox.Text.ToString() + ".cpp\" />");
                    ++i;
                    cppAdded = true;
                }

                if ((count == numItemGroupsH) && (!hAdded))
                {
                    buff.Insert(i, "    <ClCompile Include=\"source\\" + ClassNameTextBox.Text.ToString() + ".h\" />");
                    ++i;
                    hAdded = true;
                }
            }

            StreamWriter output = new StreamWriter("BulletTest.vcxproj");

            for (int i = 0; i < buff.Count; ++i)
            {
                output.WriteLine(buff[i]);
            }

            output.Close();

            return true;
        }

        public bool AddToVCXFilters()
        {
            int numItemGroupsCpp = 3;
            int numItemGroupsH = 4;

            List<string> buff = new List<string>();

            try
            {
                StreamReader reader = new StreamReader("BulletTest.vcxproj.filters");

                do
                {
                    buff.Add(reader.ReadLine());
                }
                while (reader.Peek() != -1);

                reader.Close();
            }
            catch
            {
                return false;
            }

            int count = 0;
            bool cppAdded = false;
            bool hAdded = false;

            for (int i = 0; i < buff.Count; ++i)
            {
                if (buff[i].Contains("</ItemGroup>"))
                {
                    count++;
                }

                if ((count == numItemGroupsCpp) && (!cppAdded))
                {
                    buff.Insert(i, "    <ClCompile Include=\"source\\" + ClassNameTextBox.Text.ToString() + ".cpp\">");
                    ++i;
                    buff.Insert(i, "      <Filter>Source Files</Filter>");
                    ++i;
                    buff.Insert(i, "    </ClCompile>");
                    ++i;
                    cppAdded = true;
                }

                if ((count == numItemGroupsH) && (!hAdded))
                {
                    buff.Insert(i, "    <ClCompile Include=\"source\\" + ClassNameTextBox.Text.ToString() + ".h\">");
                    ++i;
                    buff.Insert(i, "      <Filter>Header Files</Filter>");
                    ++i;
                    buff.Insert(i, "    </ClCompile/>");
                    ++i;
                    hAdded = true;
                }
            }

            StreamWriter output = new StreamWriter("BulletTest.vcxproj.filters");

            for (int i = 0; i < buff.Count; ++i)
            {
                output.WriteLine(buff[i]);
            }

            output.Close();

            return true;
        }

        public bool AddToDataTypes()
        {
            List<string> buff = new List<string>();

            try
            {
                StreamReader reader = new StreamReader("ClassGeneratorFiles\\dataTypes.txt");

                do
                {
                    buff.Add(reader.ReadLine());
                }
                while (reader.Peek() != -1);

                reader.Close();
            }
            catch
            {
                return false;
            }

            buff.Add(ClassNameTextBox.Text.ToString());

            StreamWriter output = new StreamWriter("ClassGeneratorFiles\\dataTypes.txt");

            for (int i = 0; i < buff.Count; ++i)
            {
                output.WriteLine(buff[i]);
            }

            output.Close();


            return true;
        }
    }
}
