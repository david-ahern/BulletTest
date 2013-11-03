namespace ClassGenerator
{
    partial class Form1
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
            this.GenerateButton = new System.Windows.Forms.Button();
            this.CancelButton = new System.Windows.Forms.Button();
            this.GameObjectSelector = new System.Windows.Forms.RadioButton();
            this.ScreenSelector = new System.Windows.Forms.RadioButton();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.ClassNameTextBox = new System.Windows.Forms.TextBox();
            this.CreateCheck = new System.Windows.Forms.CheckBox();
            this.InitCheck = new System.Windows.Forms.CheckBox();
            this.UpdateCheck = new System.Windows.Forms.CheckBox();
            this.RenderCheck = new System.Windows.Forms.CheckBox();
            this.ClearButton = new System.Windows.Forms.Button();
            this.VariableAccessListBox = new System.Windows.Forms.ComboBox();
            this.VariableDataTypeListBox = new System.Windows.Forms.ComboBox();
            this.VariablePointer = new System.Windows.Forms.CheckBox();
            this.VariableNameBox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.AddVariableBox = new System.Windows.Forms.GroupBox();
            this.AddNewVariable = new System.Windows.Forms.Button();
            this.AddMethodBox = new System.Windows.Forms.GroupBox();
            this.AddMethod = new System.Windows.Forms.Button();
            this.MethodParametersBox = new System.Windows.Forms.TextBox();
            this.label10 = new System.Windows.Forms.Label();
            this.MethodNameBox = new System.Windows.Forms.TextBox();
            this.label9 = new System.Windows.Forms.Label();
            this.MethodReturnPointer = new System.Windows.Forms.CheckBox();
            this.MethodReturnTypeListBox = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.MethodAccessListBox = new System.Windows.Forms.ComboBox();
            this.NoBaseObjectButton = new System.Windows.Forms.RadioButton();
            this.UserNameBox = new System.Windows.Forms.TextBox();
            this.label11 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.DescriptionBox = new System.Windows.Forms.RichTextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.AddVariableBox.SuspendLayout();
            this.AddMethodBox.SuspendLayout();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // GenerateButton
            // 
            this.GenerateButton.Location = new System.Drawing.Point(481, 591);
            this.GenerateButton.Name = "GenerateButton";
            this.GenerateButton.Size = new System.Drawing.Size(75, 23);
            this.GenerateButton.TabIndex = 0;
            this.GenerateButton.Text = "Generate";
            this.GenerateButton.UseVisualStyleBackColor = true;
            this.GenerateButton.Click += new System.EventHandler(this.GenerateButton_Click);
            // 
            // CancelButton
            // 
            this.CancelButton.Location = new System.Drawing.Point(319, 591);
            this.CancelButton.Name = "CancelButton";
            this.CancelButton.Size = new System.Drawing.Size(75, 23);
            this.CancelButton.TabIndex = 1;
            this.CancelButton.Text = "Cancel";
            this.CancelButton.UseVisualStyleBackColor = true;
            this.CancelButton.Click += new System.EventHandler(this.CancelButton_Click);
            // 
            // GameObjectSelector
            // 
            this.GameObjectSelector.AutoSize = true;
            this.GameObjectSelector.Location = new System.Drawing.Point(294, 9);
            this.GameObjectSelector.Name = "GameObjectSelector";
            this.GameObjectSelector.Size = new System.Drawing.Size(84, 17);
            this.GameObjectSelector.TabIndex = 2;
            this.GameObjectSelector.TabStop = true;
            this.GameObjectSelector.Text = "GameObject";
            this.GameObjectSelector.UseVisualStyleBackColor = true;
            this.GameObjectSelector.CheckedChanged += new System.EventHandler(this.GameObjectSelector_CheckedChanged);
            // 
            // ScreenSelector
            // 
            this.ScreenSelector.AutoSize = true;
            this.ScreenSelector.Location = new System.Drawing.Point(384, 9);
            this.ScreenSelector.Name = "ScreenSelector";
            this.ScreenSelector.Size = new System.Drawing.Size(59, 17);
            this.ScreenSelector.TabIndex = 3;
            this.ScreenSelector.TabStop = true;
            this.ScreenSelector.Text = "Screen";
            this.ScreenSelector.UseVisualStyleBackColor = true;
            this.ScreenSelector.CheckedChanged += new System.EventHandler(this.ScreenSelector_CheckedChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(187, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(101, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Select Base Object:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(12, 13);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(63, 13);
            this.label2.TabIndex = 5;
            this.label2.Text = "ClassName:";
            // 
            // ClassNameTextBox
            // 
            this.ClassNameTextBox.Location = new System.Drawing.Point(81, 10);
            this.ClassNameTextBox.Name = "ClassNameTextBox";
            this.ClassNameTextBox.Size = new System.Drawing.Size(100, 20);
            this.ClassNameTextBox.TabIndex = 6;
            // 
            // CreateCheck
            // 
            this.CreateCheck.AutoSize = true;
            this.CreateCheck.Location = new System.Drawing.Point(6, 19);
            this.CreateCheck.Name = "CreateCheck";
            this.CreateCheck.Size = new System.Drawing.Size(57, 17);
            this.CreateCheck.TabIndex = 7;
            this.CreateCheck.Text = "Create";
            this.CreateCheck.UseVisualStyleBackColor = true;
            this.CreateCheck.EnabledChanged += new System.EventHandler(this.CreateCheck_EnabledChanged);
            // 
            // InitCheck
            // 
            this.InitCheck.AutoSize = true;
            this.InitCheck.Location = new System.Drawing.Point(6, 42);
            this.InitCheck.Name = "InitCheck";
            this.InitCheck.Size = new System.Drawing.Size(40, 17);
            this.InitCheck.TabIndex = 8;
            this.InitCheck.Text = "Init";
            this.InitCheck.UseVisualStyleBackColor = true;
            this.InitCheck.EnabledChanged += new System.EventHandler(this.InitCheck_EnabledChanged);
            // 
            // UpdateCheck
            // 
            this.UpdateCheck.AutoSize = true;
            this.UpdateCheck.Location = new System.Drawing.Point(6, 65);
            this.UpdateCheck.Name = "UpdateCheck";
            this.UpdateCheck.Size = new System.Drawing.Size(61, 17);
            this.UpdateCheck.TabIndex = 9;
            this.UpdateCheck.Text = "Update";
            this.UpdateCheck.UseVisualStyleBackColor = true;
            this.UpdateCheck.EnabledChanged += new System.EventHandler(this.UpdateCheck_EnabledChanged);
            // 
            // RenderCheck
            // 
            this.RenderCheck.AutoSize = true;
            this.RenderCheck.Location = new System.Drawing.Point(6, 88);
            this.RenderCheck.Name = "RenderCheck";
            this.RenderCheck.Size = new System.Drawing.Size(61, 17);
            this.RenderCheck.TabIndex = 10;
            this.RenderCheck.Text = "Render";
            this.RenderCheck.UseVisualStyleBackColor = true;
            this.RenderCheck.EnabledChanged += new System.EventHandler(this.RenderCheck_EnabledChanged);
            // 
            // ClearButton
            // 
            this.ClearButton.Location = new System.Drawing.Point(400, 591);
            this.ClearButton.Name = "ClearButton";
            this.ClearButton.Size = new System.Drawing.Size(75, 23);
            this.ClearButton.TabIndex = 12;
            this.ClearButton.Text = "Clear";
            this.ClearButton.UseVisualStyleBackColor = true;
            this.ClearButton.Click += new System.EventHandler(this.ClearButton_Click);
            // 
            // VariableAccessListBox
            // 
            this.VariableAccessListBox.FormattingEnabled = true;
            this.VariableAccessListBox.Location = new System.Drawing.Point(6, 32);
            this.VariableAccessListBox.Name = "VariableAccessListBox";
            this.VariableAccessListBox.Size = new System.Drawing.Size(93, 21);
            this.VariableAccessListBox.TabIndex = 13;
            // 
            // VariableDataTypeListBox
            // 
            this.VariableDataTypeListBox.FormattingEnabled = true;
            this.VariableDataTypeListBox.Location = new System.Drawing.Point(6, 72);
            this.VariableDataTypeListBox.Name = "VariableDataTypeListBox";
            this.VariableDataTypeListBox.Size = new System.Drawing.Size(93, 21);
            this.VariableDataTypeListBox.TabIndex = 14;
            // 
            // VariablePointer
            // 
            this.VariablePointer.AutoSize = true;
            this.VariablePointer.Location = new System.Drawing.Point(9, 99);
            this.VariablePointer.Name = "VariablePointer";
            this.VariablePointer.Size = new System.Drawing.Size(59, 17);
            this.VariablePointer.TabIndex = 15;
            this.VariablePointer.Text = "Pointer";
            this.VariablePointer.UseVisualStyleBackColor = true;
            // 
            // VariableNameBox
            // 
            this.VariableNameBox.Location = new System.Drawing.Point(6, 135);
            this.VariableNameBox.Name = "VariableNameBox";
            this.VariableNameBox.Size = new System.Drawing.Size(93, 20);
            this.VariableNameBox.TabIndex = 16;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 16);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(42, 13);
            this.label4.TabIndex = 17;
            this.label4.Text = "Access";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(6, 56);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(57, 13);
            this.label5.TabIndex = 18;
            this.label5.Text = "Data Type";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 119);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(76, 13);
            this.label6.TabIndex = 19;
            this.label6.Text = "Variable Name";
            // 
            // AddVariableBox
            // 
            this.AddVariableBox.Controls.Add(this.AddNewVariable);
            this.AddVariableBox.Controls.Add(this.label4);
            this.AddVariableBox.Controls.Add(this.VariableAccessListBox);
            this.AddVariableBox.Controls.Add(this.VariableNameBox);
            this.AddVariableBox.Controls.Add(this.label6);
            this.AddVariableBox.Controls.Add(this.label5);
            this.AddVariableBox.Controls.Add(this.VariableDataTypeListBox);
            this.AddVariableBox.Controls.Add(this.VariablePointer);
            this.AddVariableBox.Location = new System.Drawing.Point(15, 184);
            this.AddVariableBox.Name = "AddVariableBox";
            this.AddVariableBox.Size = new System.Drawing.Size(117, 193);
            this.AddVariableBox.TabIndex = 21;
            this.AddVariableBox.TabStop = false;
            this.AddVariableBox.Text = "Add Variable";
            // 
            // AddNewVariable
            // 
            this.AddNewVariable.Location = new System.Drawing.Point(6, 164);
            this.AddNewVariable.Name = "AddNewVariable";
            this.AddNewVariable.Size = new System.Drawing.Size(75, 23);
            this.AddNewVariable.TabIndex = 20;
            this.AddNewVariable.Text = "Add";
            this.AddNewVariable.UseVisualStyleBackColor = true;
            this.AddNewVariable.Click += new System.EventHandler(this.AddNewVariable_Click);
            // 
            // AddMethodBox
            // 
            this.AddMethodBox.Controls.Add(this.AddMethod);
            this.AddMethodBox.Controls.Add(this.MethodParametersBox);
            this.AddMethodBox.Controls.Add(this.label10);
            this.AddMethodBox.Controls.Add(this.MethodNameBox);
            this.AddMethodBox.Controls.Add(this.label9);
            this.AddMethodBox.Controls.Add(this.MethodReturnPointer);
            this.AddMethodBox.Controls.Add(this.MethodReturnTypeListBox);
            this.AddMethodBox.Controls.Add(this.label8);
            this.AddMethodBox.Controls.Add(this.label7);
            this.AddMethodBox.Controls.Add(this.MethodAccessListBox);
            this.AddMethodBox.Location = new System.Drawing.Point(15, 383);
            this.AddMethodBox.Name = "AddMethodBox";
            this.AddMethodBox.Size = new System.Drawing.Size(117, 230);
            this.AddMethodBox.TabIndex = 22;
            this.AddMethodBox.TabStop = false;
            this.AddMethodBox.Text = "Add Method";
            // 
            // AddMethod
            // 
            this.AddMethod.Location = new System.Drawing.Point(6, 200);
            this.AddMethod.Name = "AddMethod";
            this.AddMethod.Size = new System.Drawing.Size(75, 23);
            this.AddMethod.TabIndex = 26;
            this.AddMethod.Text = "Add";
            this.AddMethod.UseVisualStyleBackColor = true;
            this.AddMethod.Click += new System.EventHandler(this.AddMethod_Click);
            // 
            // MethodParametersBox
            // 
            this.MethodParametersBox.Location = new System.Drawing.Point(6, 174);
            this.MethodParametersBox.Name = "MethodParametersBox";
            this.MethodParametersBox.Size = new System.Drawing.Size(93, 20);
            this.MethodParametersBox.TabIndex = 25;
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(6, 158);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(60, 13);
            this.label10.TabIndex = 24;
            this.label10.Text = "Parameters";
            // 
            // MethodNameBox
            // 
            this.MethodNameBox.Location = new System.Drawing.Point(6, 135);
            this.MethodNameBox.Name = "MethodNameBox";
            this.MethodNameBox.Size = new System.Drawing.Size(93, 20);
            this.MethodNameBox.TabIndex = 23;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(6, 119);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(74, 13);
            this.label9.TabIndex = 22;
            this.label9.Text = "Method Name";
            // 
            // MethodReturnPointer
            // 
            this.MethodReturnPointer.AutoSize = true;
            this.MethodReturnPointer.Location = new System.Drawing.Point(9, 99);
            this.MethodReturnPointer.Name = "MethodReturnPointer";
            this.MethodReturnPointer.Size = new System.Drawing.Size(59, 17);
            this.MethodReturnPointer.TabIndex = 21;
            this.MethodReturnPointer.Text = "Pointer";
            this.MethodReturnPointer.UseVisualStyleBackColor = true;
            // 
            // MethodReturnTypeListBox
            // 
            this.MethodReturnTypeListBox.FormattingEnabled = true;
            this.MethodReturnTypeListBox.Location = new System.Drawing.Point(6, 72);
            this.MethodReturnTypeListBox.Name = "MethodReturnTypeListBox";
            this.MethodReturnTypeListBox.Size = new System.Drawing.Size(93, 21);
            this.MethodReturnTypeListBox.TabIndex = 20;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(6, 56);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(66, 13);
            this.label8.TabIndex = 19;
            this.label8.Text = "Return Type";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(6, 16);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(42, 13);
            this.label7.TabIndex = 18;
            this.label7.Text = "Access";
            // 
            // MethodAccessListBox
            // 
            this.MethodAccessListBox.FormattingEnabled = true;
            this.MethodAccessListBox.Location = new System.Drawing.Point(6, 32);
            this.MethodAccessListBox.Name = "MethodAccessListBox";
            this.MethodAccessListBox.Size = new System.Drawing.Size(93, 21);
            this.MethodAccessListBox.TabIndex = 14;
            // 
            // NoBaseObjectButton
            // 
            this.NoBaseObjectButton.AutoSize = true;
            this.NoBaseObjectButton.Location = new System.Drawing.Point(449, 9);
            this.NoBaseObjectButton.Name = "NoBaseObjectButton";
            this.NoBaseObjectButton.Size = new System.Drawing.Size(51, 17);
            this.NoBaseObjectButton.TabIndex = 23;
            this.NoBaseObjectButton.TabStop = true;
            this.NoBaseObjectButton.Text = "None";
            this.NoBaseObjectButton.UseVisualStyleBackColor = true;
            this.NoBaseObjectButton.CheckedChanged += new System.EventHandler(this.NoBaseObjectButton_CheckedChanged);
            // 
            // UserNameBox
            // 
            this.UserNameBox.Location = new System.Drawing.Point(227, 54);
            this.UserNameBox.Name = "UserNameBox";
            this.UserNameBox.Size = new System.Drawing.Size(198, 20);
            this.UserNameBox.TabIndex = 24;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(159, 57);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(62, 13);
            this.label11.TabIndex = 25;
            this.label11.Text = "Created By:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.CreateCheck);
            this.groupBox1.Controls.Add(this.InitCheck);
            this.groupBox1.Controls.Add(this.UpdateCheck);
            this.groupBox1.Controls.Add(this.RenderCheck);
            this.groupBox1.Location = new System.Drawing.Point(15, 47);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(117, 131);
            this.groupBox1.TabIndex = 26;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Inherit Methods";
            // 
            // DescriptionBox
            // 
            this.DescriptionBox.Location = new System.Drawing.Point(162, 112);
            this.DescriptionBox.Name = "DescriptionBox";
            this.DescriptionBox.Size = new System.Drawing.Size(394, 75);
            this.DescriptionBox.TabIndex = 27;
            this.DescriptionBox.Text = "Enter discription of class here.";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(159, 93);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(63, 13);
            this.label3.TabIndex = 28;
            this.label3.Text = "Description:";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(568, 626);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.DescriptionBox);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.UserNameBox);
            this.Controls.Add(this.NoBaseObjectButton);
            this.Controls.Add(this.AddMethodBox);
            this.Controls.Add(this.AddVariableBox);
            this.Controls.Add(this.ClearButton);
            this.Controls.Add(this.ClassNameTextBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.ScreenSelector);
            this.Controls.Add(this.GameObjectSelector);
            this.Controls.Add(this.CancelButton);
            this.Controls.Add(this.GenerateButton);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.AddVariableBox.ResumeLayout(false);
            this.AddVariableBox.PerformLayout();
            this.AddMethodBox.ResumeLayout(false);
            this.AddMethodBox.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button CancelButton;
        private System.Windows.Forms.RadioButton GameObjectSelector;
        private System.Windows.Forms.RadioButton ScreenSelector;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button GenerateButton;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox ClassNameTextBox;
        private System.Windows.Forms.CheckBox CreateCheck;
        private System.Windows.Forms.CheckBox InitCheck;
        private System.Windows.Forms.CheckBox UpdateCheck;
        private System.Windows.Forms.CheckBox RenderCheck;
        private System.Windows.Forms.Button ClearButton;
        private System.Windows.Forms.ComboBox VariableAccessListBox;
        private System.Windows.Forms.ComboBox VariableDataTypeListBox;
        private System.Windows.Forms.CheckBox VariablePointer;
        private System.Windows.Forms.TextBox VariableNameBox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.GroupBox AddVariableBox;
        private System.Windows.Forms.Button AddNewVariable;
        private System.Windows.Forms.GroupBox AddMethodBox;
        private System.Windows.Forms.ComboBox MethodReturnTypeListBox;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox MethodAccessListBox;
        private System.Windows.Forms.CheckBox MethodReturnPointer;
        private System.Windows.Forms.TextBox MethodNameBox;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Button AddMethod;
        private System.Windows.Forms.TextBox MethodParametersBox;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.RadioButton NoBaseObjectButton;
        private System.Windows.Forms.TextBox UserNameBox;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RichTextBox DescriptionBox;
        private System.Windows.Forms.Label label3;

    }
}

