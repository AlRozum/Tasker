#pragma once

namespace TaskerUnit {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TaskerUnitLogWindow
	/// </summary>
	public ref class TaskerUnitLogWindow : public System::Windows::Forms::Form
	{
	public:
		TaskerUnitLogWindow(String^ input_name, String^ input_text)
		{
			InitializeComponent();
			this->Text += " ";
			this->Text += input_name;
			this->LogBox->Text = input_text;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TaskerUnitLogWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ LogBox;
	private: System::Windows::Forms::Button^ btn_Ok;
	private: System::Windows::Forms::Button^ btn_Clear;
	protected:

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
			this->LogBox = (gcnew System::Windows::Forms::TextBox());
			this->btn_Ok = (gcnew System::Windows::Forms::Button());
			this->btn_Clear = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LogBox
			// 
			this->LogBox->Location = System::Drawing::Point(12, 12);
			this->LogBox->Multiline = true;
			this->LogBox->Name = L"LogBox";
			this->LogBox->Size = System::Drawing::Size(436, 342);
			this->LogBox->TabIndex = 0;
			// 
			// btn_Ok
			// 
			this->btn_Ok->Location = System::Drawing::Point(12, 360);
			this->btn_Ok->Name = L"btn_Ok";
			this->btn_Ok->Size = System::Drawing::Size(90, 40);
			this->btn_Ok->TabIndex = 6;
			this->btn_Ok->Text = L"OK";
			this->btn_Ok->UseVisualStyleBackColor = true;
			this->btn_Ok->Click += gcnew System::EventHandler(this, &TaskerUnitLogWindow::btn_Ok_Click);
			// 
			// btn_Clear
			// 
			this->btn_Clear->Location = System::Drawing::Point(358, 360);
			this->btn_Clear->Name = L"btn_Clear";
			this->btn_Clear->Size = System::Drawing::Size(90, 40);
			this->btn_Clear->TabIndex = 7;
			this->btn_Clear->Text = L"Clear";
			this->btn_Clear->UseVisualStyleBackColor = true;
			this->btn_Clear->Click += gcnew System::EventHandler(this, &TaskerUnitLogWindow::btn_Clear_Click);
			// 
			// TaskerUnitLogWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(460, 412);
			this->Controls->Add(this->btn_Clear);
			this->Controls->Add(this->btn_Ok);
			this->Controls->Add(this->LogBox);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"TaskerUnitLogWindow";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Log";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	public: property String^ log_text
	{
		String^ get()
		{
			return LogBox->Text;
		}
		void set(String^ input)
		{
			LogBox->Text = input;
		}
	}
#pragma endregion
	private: System::Void btn_Ok_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Close();
	}
	private: System::Void btn_Clear_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->LogBox->Text = nullptr;
	}
};
}
