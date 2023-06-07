#pragma once

namespace Tasker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NewProjectDialog
	/// </summary>
	public ref class NewProjectDialog : public System::Windows::Forms::Form
	{
	public:
		NewProjectDialog(void)
		{
			InitializeComponent();
		}
		NewProjectDialog(String^ text)
		{
			InitializeComponent();
			this->txt_ProjName->Text = text;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~NewProjectDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ txt_ProjName;
	private: System::Windows::Forms::Button^ Ok;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_ProjName = (gcnew System::Windows::Forms::TextBox());
			this->Ok = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(148, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Project name";
			// 
			// txt_ProjName
			// 
			this->txt_ProjName->Location = System::Drawing::Point(114, 51);
			this->txt_ProjName->Name = L"txt_ProjName";
			this->txt_ProjName->Size = System::Drawing::Size(155, 22);
			this->txt_ProjName->TabIndex = 1;
			this->txt_ProjName->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &NewProjectDialog::txt_ProjName_KeyUp);
			// 
			// Ok
			// 
			this->Ok->Location = System::Drawing::Point(144, 101);
			this->Ok->Name = L"Ok";
			this->Ok->Size = System::Drawing::Size(90, 40);
			this->Ok->TabIndex = 2;
			this->Ok->Text = L"OK";
			this->Ok->UseVisualStyleBackColor = true;
			this->Ok->Click += gcnew System::EventHandler(this, &NewProjectDialog::Ok_Click);
			// 
			// NewProjectDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 153);
			this->Controls->Add(this->Ok);
			this->Controls->Add(this->txt_ProjName);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"NewProjectDialog";
			this->Text = L"Enter project name";
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &NewProjectDialog::txt_ProjName_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	public: String^ Get_ProjName()
	{
		if (txt_ProjName->Text == "")
			txt_ProjName->Text = "(Empty name)";
		return txt_ProjName->Text;
	}
#pragma endregion
	private: System::Void Ok_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Close();
	}
private: System::Void txt_ProjName_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyValue == (int)Keys::Enter)
	{
		Close();
	}
}
};
}
