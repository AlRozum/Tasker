#pragma once

namespace TaskerUnit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TaskerUnitDialog
	/// </summary>
	public ref class TaskerUnitDialog : public System::Windows::Forms::Form
	{
	public:
		TaskerUnitDialog(String^ name, String^ performer)
		{
			InitializeComponent();
			this->txt_TaskName->Text = name;
			this->txt_TaskPerformer->Text = performer;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TaskerUnitDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_Ok;
	protected:

	private: System::Windows::Forms::TextBox^ txt_TaskName;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txt_TaskPerformer;
	private: System::Windows::Forms::Label^ label2;

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
			this->btn_Ok = (gcnew System::Windows::Forms::Button());
			this->txt_TaskName = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_TaskPerformer = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_Ok
			// 
			this->btn_Ok->Location = System::Drawing::Point(144, 111);
			this->btn_Ok->Name = L"btn_Ok";
			this->btn_Ok->Size = System::Drawing::Size(90, 40);
			this->btn_Ok->TabIndex = 5;
			this->btn_Ok->Text = L"OK";
			this->btn_Ok->UseVisualStyleBackColor = true;
			this->btn_Ok->Click += gcnew System::EventHandler(this, &TaskerUnitDialog::btn_Ok_Click);
			this->btn_Ok->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &TaskerUnitDialog::btn_Ok_KeyUp);
			// 
			// txt_TaskName
			// 
			this->txt_TaskName->Location = System::Drawing::Point(114, 31);
			this->txt_TaskName->Name = L"txt_TaskName";
			this->txt_TaskName->Size = System::Drawing::Size(155, 22);
			this->txt_TaskName->TabIndex = 4;
			this->txt_TaskName->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &TaskerUnitDialog::btn_Ok_KeyUp);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(154, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Task name";
			// 
			// txt_TaskPerformer
			// 
			this->txt_TaskPerformer->Location = System::Drawing::Point(114, 80);
			this->txt_TaskPerformer->Name = L"txt_TaskPerformer";
			this->txt_TaskPerformer->Size = System::Drawing::Size(155, 22);
			this->txt_TaskPerformer->TabIndex = 7;
			this->txt_TaskPerformer->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &TaskerUnitDialog::btn_Ok_KeyUp);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(158, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 16);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Performer";
			// 
			// TaskerUnitDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 173);
			this->Controls->Add(this->txt_TaskPerformer);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btn_Ok);
			this->Controls->Add(this->txt_TaskName);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"TaskerUnitDialog";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"TaskerUnitDialog";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		public: String^ Get_TaskName()
		{
			if (txt_TaskName->Text != "")
				return txt_TaskName->Text;
			else
				return "(Empty name)";
		}
		public: String^ Get_TaskPerformer()
		{
			if (txt_TaskPerformer->Text != "")
				return txt_TaskPerformer->Text;
			else
				return "(Empty performer)";
		}
#pragma endregion
	private: System::Void btn_Ok_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Close();
	}
private: System::Void btn_Ok_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if (e->KeyValue == (int)Keys::Enter)
	{
		Close();
	}
}
};
}
