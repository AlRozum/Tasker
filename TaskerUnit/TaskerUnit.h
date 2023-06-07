#pragma once
#include "TaskerUnitDialog.h"
#include "TaskerUnitLogWindow.h"
#include "F:\Work\C++\Tasker\TaskerDefinitions.h"
#include "../TaskerDefinitions.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



namespace TaskerUnit {

	/// <summary>
	/// Summary for TaskerUnit
	/// </summary>
	public ref class TaskerUnit : public System::Windows::Forms::UserControl
	{
	public:
		TaskerUnit(void)
		{
			InitializeComponent();
		}

	public:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TaskerUnit()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: int num;
	private: static int active_num;
	private: String^ log;
	private: DateTime start_date;
	private: DateTime finish_date;
	private: DateTime deadline;
	private: en_STATUS stat;
	private: array<double>^ graph_points = gcnew array<double>(3);
	private: System::Windows::Forms::DataVisualization::Charting::DataPoint^ point = gcnew System::Windows::Forms::DataVisualization::Charting::DataPoint;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ts_Status;
	private: System::Windows::Forms::ToolStripMenuItem^ ts_Active;
	private: System::Windows::Forms::ToolStripMenuItem^ ts_Finished;
	private: System::Windows::Forms::ToolStripMenuItem^ ts_Cancelled;
	private: System::Windows::Forms::ToolStripMenuItem^ ts_Revision;
	private: System::Windows::Forms::Label^ str_TaskNum;
	private: System::Windows::Forms::Label^ str_TaskPerformer;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ pick_Start;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DateTimePicker^ pick_Finish;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DateTimePicker^ pick_Deadline;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ txt_Log;
	private: System::Windows::Forms::Label^ str_TaskName;



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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ts_Status = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ts_Active = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ts_Finished = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ts_Cancelled = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ts_Revision = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->str_TaskNum = (gcnew System::Windows::Forms::Label());
			this->str_TaskPerformer = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pick_Start = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pick_Finish = (gcnew System::Windows::Forms::DateTimePicker());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pick_Deadline = (gcnew System::Windows::Forms::DateTimePicker());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_Log = (gcnew System::Windows::Forms::Label());
			this->str_TaskName = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::Color::Transparent;
			this->menuStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ts_Status });
			this->menuStrip1->Location = System::Drawing::Point(759, 16);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(71, 28);
			this->menuStrip1->TabIndex = 10;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ts_Status
			// 
			this->ts_Status->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->ts_Active,
					this->ts_Finished, this->ts_Cancelled, this->ts_Revision
			});
			this->ts_Status->Name = L"ts_Status";
			this->ts_Status->Size = System::Drawing::Size(63, 24);
			this->ts_Status->Text = L"Status";
			this->ts_Status->Click += gcnew System::EventHandler(this, &TaskerUnit::TaskerUnit_Click);
			// 
			// ts_Active
			// 
			this->ts_Active->Name = L"ts_Active";
			this->ts_Active->Size = System::Drawing::Size(157, 26);
			this->ts_Active->Text = L"Active";
			this->ts_Active->Click += gcnew System::EventHandler(this, &TaskerUnit::ts_Active_Click);
			// 
			// ts_Finished
			// 
			this->ts_Finished->Name = L"ts_Finished";
			this->ts_Finished->Size = System::Drawing::Size(157, 26);
			this->ts_Finished->Text = L"Finished";
			this->ts_Finished->Click += gcnew System::EventHandler(this, &TaskerUnit::ts_Finished_Click);
			// 
			// ts_Cancelled
			// 
			this->ts_Cancelled->Name = L"ts_Cancelled";
			this->ts_Cancelled->Size = System::Drawing::Size(157, 26);
			this->ts_Cancelled->Text = L"Cancelled";
			this->ts_Cancelled->Click += gcnew System::EventHandler(this, &TaskerUnit::ts_Cancelled_Click);
			// 
			// ts_Revision
			// 
			this->ts_Revision->Name = L"ts_Revision";
			this->ts_Revision->Size = System::Drawing::Size(157, 26);
			this->ts_Revision->Text = L"Revision";
			this->ts_Revision->Click += gcnew System::EventHandler(this, &TaskerUnit::ts_Revision_Click);
			// 
			// str_TaskNum
			// 
			this->str_TaskNum->AutoSize = true;
			this->str_TaskNum->BackColor = System::Drawing::Color::Transparent;
			this->str_TaskNum->Location = System::Drawing::Point(6, 22);
			this->str_TaskNum->Name = L"str_TaskNum";
			this->str_TaskNum->Size = System::Drawing::Size(44, 16);
			this->str_TaskNum->TabIndex = 0;
			this->str_TaskNum->Text = L"label1";
			this->str_TaskNum->Click += gcnew System::EventHandler(this, &TaskerUnit::TaskerUnit_Click);
			// 
			// str_TaskPerformer
			// 
			this->str_TaskPerformer->AutoSize = true;
			this->str_TaskPerformer->BackColor = System::Drawing::Color::Transparent;
			this->str_TaskPerformer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->str_TaskPerformer->Location = System::Drawing::Point(168, 22);
			this->str_TaskPerformer->Name = L"str_TaskPerformer";
			this->str_TaskPerformer->Size = System::Drawing::Size(114, 16);
			this->str_TaskPerformer->TabIndex = 2;
			this->str_TaskPerformer->Text = L"(Empty performer)";
			this->str_TaskPerformer->Click += gcnew System::EventHandler(this, &TaskerUnit::TaskerUnit_Click);
			this->str_TaskPerformer->DoubleClick += gcnew System::EventHandler(this, &TaskerUnit::str_TaskName_DoubleClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(318, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Start Date";
			this->label1->Click += gcnew System::EventHandler(this, &TaskerUnit::TaskerUnit_Click);
			// 
			// pick_Start
			// 
			this->pick_Start->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->pick_Start->Location = System::Drawing::Point(321, 29);
			this->pick_Start->Name = L"pick_Start";
			this->pick_Start->Size = System::Drawing::Size(88, 22);
			this->pick_Start->TabIndex = 4;
			this->pick_Start->ValueChanged += gcnew System::EventHandler(this, &TaskerUnit::pick_Start_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(436, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 16);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Finish Date";
			this->label2->Click += gcnew System::EventHandler(this, &TaskerUnit::TaskerUnit_Click);
			// 
			// pick_Finish
			// 
			this->pick_Finish->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->pick_Finish->Location = System::Drawing::Point(439, 29);
			this->pick_Finish->Name = L"pick_Finish";
			this->pick_Finish->Size = System::Drawing::Size(88, 22);
			this->pick_Finish->TabIndex = 6;
			this->pick_Finish->ValueChanged += gcnew System::EventHandler(this, &TaskerUnit::pick_Finish_ValueChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(553, 10);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 16);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Deadline";
			this->label3->Click += gcnew System::EventHandler(this, &TaskerUnit::TaskerUnit_Click);
			// 
			// pick_Deadline
			// 
			this->pick_Deadline->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->pick_Deadline->Location = System::Drawing::Point(556, 29);
			this->pick_Deadline->Name = L"pick_Deadline";
			this->pick_Deadline->Size = System::Drawing::Size(88, 22);
			this->pick_Deadline->TabIndex = 8;
			this->pick_Deadline->ValueChanged += gcnew System::EventHandler(this, &TaskerUnit::pick_Deadline_ValueChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label4->Location = System::Drawing::Point(712, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(44, 16);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Status";
			this->label4->Click += gcnew System::EventHandler(this, &TaskerUnit::TaskerUnit_Click);
			// 
			// txt_Log
			// 
			this->txt_Log->AutoSize = true;
			this->txt_Log->BackColor = System::Drawing::Color::Transparent;
			this->txt_Log->Cursor = System::Windows::Forms::Cursors::Hand;
			this->txt_Log->Location = System::Drawing::Point(664, 22);
			this->txt_Log->Name = L"txt_Log";
			this->txt_Log->Size = System::Drawing::Size(30, 16);
			this->txt_Log->TabIndex = 11;
			this->txt_Log->Text = L"Log";
			this->txt_Log->Click += gcnew System::EventHandler(this, &TaskerUnit::TaskerUnit_Click);
			this->txt_Log->DoubleClick += gcnew System::EventHandler(this, &TaskerUnit::txt_Log_DoubleClick);
			// 
			// str_TaskName
			// 
			this->str_TaskName->AutoSize = true;
			this->str_TaskName->BackColor = System::Drawing::Color::Transparent;
			this->str_TaskName->Cursor = System::Windows::Forms::Cursors::Hand;
			this->str_TaskName->Location = System::Drawing::Point(54, 22);
			this->str_TaskName->Name = L"str_TaskName";
			this->str_TaskName->Size = System::Drawing::Size(90, 16);
			this->str_TaskName->TabIndex = 12;
			this->str_TaskName->Text = L"(Empty name)";
			this->str_TaskName->Click += gcnew System::EventHandler(this, &TaskerUnit::TaskerUnit_Click);
			this->str_TaskName->DoubleClick += gcnew System::EventHandler(this, &TaskerUnit::str_TaskName_DoubleClick);
			// 
			// TaskerUnit
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->Controls->Add(this->str_TaskName);
			this->Controls->Add(this->txt_Log);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pick_Deadline);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pick_Finish);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pick_Start);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->str_TaskPerformer);
			this->Controls->Add(this->str_TaskNum);
			this->Controls->Add(this->menuStrip1);
			this->MaximumSize = System::Drawing::Size(840, 60);
			this->MinimumSize = System::Drawing::Size(840, 60);
			this->Name = L"TaskerUnit";
			this->Size = System::Drawing::Size(840, 60);
			this->Click += gcnew System::EventHandler(this, &TaskerUnit::TaskerUnit_Click);
			start_date = System::DateTime::Today;
			finish_date = System::DateTime::Today;
			deadline = System::DateTime::Today;
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
			TaskerUnit::BackColor = System::Drawing::Color::LightGoldenrodYellow;
			this->point->Color = System::Drawing::Color::LightGoldenrodYellow;
			ts_Status->Text = "Active";
			stat = en_STATUS::st_ACTIVE;
			RefreshPoint();
		}
#pragma endregion


	//property of Task Name field
public:	property String^ Task_Name
	{
		String^ get()
		{
			return str_TaskName->Text;
		}
		void set(String^ txt)
		{
			str_TaskName->Text = txt;
		}
	}
public:	property String^ Log
	{
		String^ get()
		{
			return log;
		}
		void set(String^ txt)
		{
			log = txt;
		}
	}

	//property of Task Description field
public:	property String^ Task_Performer
	{
		String^ get()
		{
			return str_TaskPerformer->Text;
		}
		void set(String^ txt)
		{
			str_TaskPerformer->Text = txt;
		}
	}
	//property of Task Number. Contains number of object received from list in MainForm
public:	property int Number
	{
		int get()
		{
			return num;
		}
		void set(int index)
		{
			num = index;
			str_TaskNum->Text = num.ToString();
		}
	}
	//property of Active Number. Contains number of object which was clicked in MainForm
public:static property int active_number
	{
		int get()
		{
			return active_num;
		}
		void set(int index)
		{
			active_num = index;
		}
	}
public: property en_STATUS status
{
	en_STATUS get()
	{
		return stat;
	}

	void set(en_STATUS input)
	{
		switch (input)
		{
		case st_ACTIVE:
			ts_Active_Click(this, System::EventArgs::Empty);
			break;
		case st_FINISHED:
			ts_Finished_Click(this, System::EventArgs::Empty);
			break;
		case st_CANCELLED:
			ts_Cancelled_Click(this, System::EventArgs::Empty);
			break;
		case st_REVISION:
			ts_Revision_Click(this, System::EventArgs::Empty);
			break;
		default:
			ts_Active_Click(this, System::EventArgs::Empty);
			break;
		}

	}
}

public: property String^ Start_Date
{
	String^ get()
	{
		return start_date.ToShortDateString();
	}

	Void set(String^ input)
	{
		DateTime::TryParse(input, start_date);
		graph_points[0] = start_date.DayOfYear;
		this->pick_Start->Value = start_date;
		RefreshPoint();
	}
}
public: property String^ Finish_Date
{
	String^ get()
	{
		return finish_date.ToShortDateString();
	}

	Void set(String^ input)
	{
		DateTime::TryParse(input, finish_date);
		graph_points[1] = finish_date.DayOfYear;
		this->pick_Finish->Value = finish_date;
		RefreshPoint();
	}
}

public: property String^ Deadline
{
	String^ get()
	{
		return deadline.ToShortDateString();
	}

	Void set(String^ input)
	{
		DateTime::TryParse(input, deadline);
		graph_points[2] = deadline.DayOfYear;
		this->pick_Deadline->Value = deadline;
		RefreshPoint();
	}
}

public: property System::Windows::Forms::DataVisualization::Charting::DataPoint ^ Graph_Point
{
	System::Windows::Forms::DataVisualization::Charting::DataPoint^ get()
	{
		return point;
	}
}

public: event EventHandler^ ActiveChanged;
public: event EventHandler^ DateChanged;

private: System::Void ts_Active_Click(System::Object^ sender, System::EventArgs^ e)
{
	TaskerUnit_Click(this, EventArgs::Empty);
	TaskerUnit::BackColor = System::Drawing::Color::LightGoldenrodYellow;
	this->point->Color = System::Drawing::Color::LightGoldenrodYellow;
	ts_Status->Text = "Active";
	stat = en_STATUS::st_ACTIVE;
	ActiveChanged(this, EventArgs::Empty);
	RefreshPoint();
}
private: System::Void ts_Finished_Click(System::Object^ sender, System::EventArgs^ e)
{
	TaskerUnit_Click(this, EventArgs::Empty);
	TaskerUnit::BackColor = System::Drawing::Color::LightGreen;
	this->point->Color = System::Drawing::Color::LightGreen;
	ts_Status->Text = "Finished";
	stat = en_STATUS::st_FINISHED;
	ActiveChanged(this, EventArgs::Empty);
	RefreshPoint();
}
private: System::Void ts_Cancelled_Click(System::Object^ sender, System::EventArgs^ e)
{
	TaskerUnit_Click(this, EventArgs::Empty);
	TaskerUnit::BackColor = System::Drawing::Color::Salmon;
	this->point->Color = System::Drawing::Color::Salmon;
	ts_Status->Text = "Cancelled";
	stat = en_STATUS::st_CANCELLED;
	ActiveChanged(this, EventArgs::Empty);
	RefreshPoint();
}
private: System::Void ts_Revision_Click(System::Object^ sender, System::EventArgs^ e)
{
	TaskerUnit_Click(this, EventArgs::Empty);
	TaskerUnit::BackColor = System::Drawing::Color::LightBlue;
	this->point->Color = System::Drawing::Color::LightBlue;
	ts_Status->Text = "Revision";
	stat = en_STATUS::st_REVISION;
	ActiveChanged(this, EventArgs::Empty);
	RefreshPoint();
}
private: System::Void pick_Start_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	TaskerUnit_Click(this, EventArgs::Empty);
	if (DateTime::Compare(pick_Start->Value, pick_Finish->Value) > 0)
	{
		finish_date = this->pick_Start->Value;
		this->pick_Finish->Value = this->pick_Start->Value;
	}
	if (DateTime::Compare(pick_Start->Value, pick_Deadline->Value) > 0)
	{
		deadline = this->pick_Start->Value;
		this->pick_Deadline->Value = this->pick_Start->Value;
	}
	start_date = this->pick_Start->Value;
	graph_points[0] = start_date.DayOfYear;
	RefreshPoint();
}
private: System::Void pick_Finish_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	TaskerUnit_Click(this, EventArgs::Empty);
	if (DateTime::Compare(pick_Start->Value, pick_Finish->Value) <= 0)
	{
		finish_date = this->pick_Finish->Value;
	}
	else
	{
		MessageBox::Show(this, "Finish date cannot be earlier than start date", "Wrong date", MessageBoxButtons::OK);
		finish_date = this->pick_Start->Value;
		this->pick_Finish->Value = this->pick_Start->Value;
	}
	graph_points[1] = finish_date.DayOfYear;
	RefreshPoint();
}
private: System::Void pick_Deadline_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	TaskerUnit_Click(this, EventArgs::Empty);
	if (DateTime::Compare(pick_Start->Value, pick_Deadline->Value) <= 0)
	{
		deadline = this->pick_Deadline->Value;
	}
	else
	{
		MessageBox::Show(this, "Deadline date cannot be earlier than start date", "Wrong date", MessageBoxButtons::OK);
		deadline = this->pick_Start->Value;
		this->pick_Deadline->Value = this->pick_Start->Value;
	}
	graph_points[2] = deadline.DayOfYear;
	RefreshPoint();
}
private: System::Void TaskerUnit_Click(System::Object^ sender, System::EventArgs^ e)
{
	active_num = num;
	this->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
	ActiveChanged(this, EventArgs::Empty);
}
private: System::Void str_TaskName_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	TaskerUnit_Click(this, EventArgs::Empty);
	TaskerUnitDialog^ dialog = gcnew TaskerUnitDialog(str_TaskName->Text, str_TaskPerformer->Text);
	dialog->ShowDialog();
	str_TaskName->Text = dialog->Get_TaskName();
	str_TaskPerformer->Text = dialog->Get_TaskPerformer();
	RefreshPoint();
}
private: System::Void txt_Log_DoubleClick(System::Object^ sender, System::EventArgs^ e)
{
	TaskerUnit_Click(this, EventArgs::Empty);
	TaskerUnitLogWindow^ dialog = gcnew TaskerUnitLogWindow(Task_Name, Log);
	dialog->ShowDialog();
	Log = dialog->log_text;
}
private: System::Void RefreshPoint()
{
	this->point->XValue = Number + 1;
	this->point->AxisLabel = Task_Name;
	this->point->YValues = graph_points;
	DateChanged(this, EventArgs::Empty);
}
};
}



