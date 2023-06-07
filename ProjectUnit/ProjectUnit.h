#pragma once
#include "F:\Work\C++\Tasker\TaskerDefinitions.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using System::Collections::Generic::List;

namespace ProjectUnit
{

	/// <summary>
	/// Summary for MyUserControl
	/// </summary>
	public ref class ProjectUnit : public System::Windows::Forms::UserControl
	{
	public:

		ProjectUnit()
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ProjectUnit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^ proj_TabControl;
	protected:

	protected:
	private: int proj_num;
	private: String^ proj_name;
	private: static int active_proj;
	private: int units_num = 0;
	private: const int TAB_NUMBER = 5;
	private: List<::TaskerUnit::TaskerUnit^>^ taskerUnit_list = gcnew List<::TaskerUnit::TaskerUnit^>;
	private: List<System::Windows::Forms::TabPage^>^ pages_list = gcnew  List<System::Windows::Forms::TabPage^>;
	private: System::Windows::Forms::DataVisualization::Charting::Series^ graph = gcnew System::Windows::Forms::DataVisualization::Charting::Series;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->proj_TabControl = (gcnew System::Windows::Forms::TabControl());
			this->proj_TabControl->SuspendLayout();
			this->SuspendLayout();
			// 
			// proj_TabControl
			// 
			this->proj_TabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->proj_TabControl->Location = System::Drawing::Point(0, 0);
			this->proj_TabControl->MaximumSize = System::Drawing::Size(876, 420);
			this->proj_TabControl->Name = L"proj_TabControl";
			this->proj_TabControl->SelectedIndex = 0;
			this->proj_TabControl->Size = System::Drawing::Size(876, 420);
			this->proj_TabControl->TabIndex = 0;
			// 
			// tab_All
			// 
			for (int i = 0; i < TAB_NUMBER; i++)
			{
				TabPage^ page = gcnew TabPage();
				pages_list->Add(page);
				this->proj_TabControl->Controls->Add(pages_list[i]);
				this->pages_list[i]->AutoScroll = true;
				this->pages_list[i]->Location = System::Drawing::Point(4, 25);
				this->pages_list[i]->Padding = System::Windows::Forms::Padding(3);
				this->pages_list[i]->Size = System::Drawing::Size(868, 391);
				this->pages_list[i]->TabIndex = i;
				this->pages_list[i]->UseVisualStyleBackColor = true;
			}
			this->pages_list[0]->Text = L"All tasks";
			this->pages_list[0]->Enter += gcnew System::EventHandler(this, &ProjectUnit::tab_All_Enter);
			// 
			// tab_Active
			//
			this->pages_list[en_STATUS::st_ACTIVE]->Text = L"Active";
			this->pages_list[en_STATUS::st_ACTIVE]->Enter += gcnew System::EventHandler(this, &ProjectUnit::tab_Active_Enter);
			// 
			// tab_Finished
			// 
			this->pages_list[en_STATUS::st_FINISHED]->Text = L"Finished";
			this->pages_list[en_STATUS::st_FINISHED]->Enter += gcnew System::EventHandler(this, &ProjectUnit::tab_Finished_Enter);
			// 
			// tab_Cancelled
			// 
			this->pages_list[en_STATUS::st_CANCELLED]->Text = L"Cancelled";
			this->pages_list[en_STATUS::st_CANCELLED]->Enter += gcnew System::EventHandler(this, &ProjectUnit::tab_Cancelled_Enter);
			// 
			// tab_Revision
			// 
			this->pages_list[en_STATUS::st_REVISION]->Text = L"Revision";
			this->pages_list[en_STATUS::st_REVISION]->Enter += gcnew System::EventHandler(this, &ProjectUnit::tab_Revision_Enter);
			// 
			// ProjectUnit
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->Controls->Add(this->proj_TabControl);
			this->Name = L"ProjectUnit";
			this->Size = System::Drawing::Size(873, 450);
			this->proj_TabControl->ResumeLayout(false);
			this->ResumeLayout(false);
		}

public:	property int project_number
{
	int get()
	{
		return proj_num;
	}
	void set(int index)
	{
		proj_num = index;
	}
}

public:	property int task_number
{
	int get()
	{
		return units_num;
	}
	void set(int index)
	{
		units_num = index;
	}
}
		//property of Project Name. Contains string whith name of the project
public:	property String^ project_name
{
	String^ get()
	{
		if (proj_name == "")
			proj_name = "(Empty Name)";
		return proj_name;
	}
	void set(String^ text)
	{
		proj_name = text;
	}
}

public: property System::Windows::Forms::DataVisualization::Charting::Series^ tasks_graph
{
	System::Windows::Forms::DataVisualization::Charting::Series^ get()
	{
		return graph;
	}
}


public:	property String^ active_task_log
{
	String^ get()
	{
		return taskerUnit_list[::TaskerUnit::TaskerUnit::active_number]->Log;
	}

	void set(String^ text)
	{
		taskerUnit_list[::TaskerUnit::TaskerUnit::active_number]->Log = text;
	}
}

//property of Active Number. Contains number of object which was clicked in MainForm
static property int active_project
{
	int get()
	{
		return active_proj;
	}
	void set(int index)
	{
		active_proj = index;
	}
}

public: event EventHandler^ TaskActivated;
public: event EventHandler^ ProjectActivated;
public: event EventHandler^ PointsRefreshed;
public: Void AddTask()
{
	task_number++;
	::TaskerUnit::TaskerUnit^ unit = gcnew ::TaskerUnit::TaskerUnit();
	unit->Number = task_number - 1;
	unit->ActiveChanged += gcnew System::EventHandler(this, &ProjectUnit::ProjectUnit::OnActiveChanged);
	unit->DateChanged += gcnew System::EventHandler(this, &ProjectUnit::ProjectUnit::OnDateChanged);
	taskerUnit_list->Add(unit);
	if (task_number == 1)
	{
		taskerUnit_list[task_number - 1]->Location = Point(3, 3);
	}
	else
	{
		taskerUnit_list[task_number - 1]->Location = Point(3, taskerUnit_list[task_number - 2]->Bottom + 3);
	}
	this->pages_list[0]->Controls->Add(taskerUnit_list[task_number - 1]);
	Series_Init();
}

public: ::TaskerUnit::TaskerUnit^ AddTask(bool flag)
{
	task_number++;
	::TaskerUnit::TaskerUnit^ unit = gcnew ::TaskerUnit::TaskerUnit();
	unit->Number = task_number - 1;
	unit->ActiveChanged += gcnew System::EventHandler(this, &ProjectUnit::ProjectUnit::OnActiveChanged);
	taskerUnit_list->Add(unit);
	if (task_number == 1)
	{
		taskerUnit_list[task_number - 1]->Location = Point(3, 3);
	}
	else
	{
		taskerUnit_list[task_number - 1]->Location = Point(3, taskerUnit_list[task_number - 2]->Bottom + 3);
	}
	this->pages_list[0]->Controls->Add(taskerUnit_list[task_number - 1]);
	Series_Init();
	return unit;
}

public: Void DeleteTask()
{
	task_number--;
	taskerUnit_list->Remove(taskerUnit_list[::TaskerUnit::TaskerUnit::active_number]);
	for (int i = 0; i < taskerUnit_list->Count; i++)
	{
		taskerUnit_list[i]->Number = i;
		taskerUnit_list[i]->Location = Point(3, 63 * i + 3);
	}
	Series_Init();
	this->tab_Active_Enter(this, EventArgs::Empty);
	this->tab_Finished_Enter(this, EventArgs::Empty);
	this->tab_Cancelled_Enter(this, EventArgs::Empty);
	this->tab_Revision_Enter(this, EventArgs::Empty);
	this->tab_All_Enter(this, EventArgs::Empty);
}

private: Void OnActiveChanged(System::Object^ sender, System::EventArgs^ e)
{
	for each (::TaskerUnit::TaskerUnit ^ var in taskerUnit_list)
	{
		if (var->Number != ::TaskerUnit::TaskerUnit::active_number)
		{
			var->BorderStyle = System::Windows::Forms::BorderStyle::None;
		}
		TaskActivated(this, EventArgs::Empty);
	}
	Series_Init();
}
private: System::Void tab_Active_Enter(System::Object^ sender, System::EventArgs^ e)
{
	int count = 0;
	this->pages_list[st_ACTIVE]->Controls->Clear();
	for each (::TaskerUnit::TaskerUnit ^ var in taskerUnit_list)
	{
		if (var->status == st_ACTIVE)
		{
			this->pages_list[st_ACTIVE]->Controls->Add(var);
			var->Location = Point(3, 63 * count + 3);
			count++;
		}
	}
	Series_Init();
}
private: System::Void tab_Finished_Enter(System::Object^ sender, System::EventArgs^ e)
{
	int count = 0;
	this->pages_list[st_FINISHED]->Controls->Clear();
	for each (::TaskerUnit::TaskerUnit ^ var in taskerUnit_list)
	{
		if (var->status == st_FINISHED)
		{
			this->pages_list[st_FINISHED]->Controls->Add(var);
			var->Location = Point(3, 63 * count + 3);
			count++;
		}
	}
	Series_Init();
}

private: System::Void tab_Cancelled_Enter(System::Object^ sender, System::EventArgs^ e)
{
	int count = 0;
	this->pages_list[st_CANCELLED]->Controls->Clear();
	for each (::TaskerUnit::TaskerUnit ^ var in taskerUnit_list)
	{
		if (var->status == st_CANCELLED)
		{
			this->pages_list[st_CANCELLED]->Controls->Add(var);
			var->Location = Point(3, 63 * count + 3);
			count++;
		}
	}
	Series_Init();
}
private: System::Void tab_Revision_Enter(System::Object^ sender, System::EventArgs^ e)
{
	int count = 0;
	this->pages_list[st_REVISION]->Controls->Clear();
	for each (::TaskerUnit::TaskerUnit ^ var in taskerUnit_list)
	{
		if (var->status == st_REVISION)
		{
			this->pages_list[st_REVISION]->Controls->Add(var);
			var->Location = Point(3, 63 * count + 3);
			count++;
		}
	}
	Series_Init();
}
private: System::Void tab_All_Enter(System::Object^ sender, System::EventArgs^ e)
{
	int count = 0;
	this->pages_list[0]->Controls->Clear();
	for each (::TaskerUnit::TaskerUnit ^ var in taskerUnit_list)
	{
		this->pages_list[0]->Controls->Add(var);
		var->Location = Point(3, 63 * count + 3);
		count++;
	}
	Series_Init();
}

private: Void Series_Init()
{
	this->graph->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::RangeBar;
	this->graph->YValuesPerPoint = 2;
	this->graph->Points->Clear();
	for each (::TaskerUnit::TaskerUnit^ var in taskerUnit_list)
	{
		this->graph->Points->Add(var->Graph_Point);
	}
	PointsRefreshed(this, EventArgs::Empty);
}

public: Void SaveProjectDialog()
{
	SaveFileDialog^ saveFile = gcnew SaveFileDialog();
	saveFile->Filter = "Tasker file (*.tskf)|*.tskf|Text file (*.txt)|*.txt|All files (*.*)|*.*";
	saveFile->FilterIndex = 1;
	saveFile->RestoreDirectory = true;
	if (saveFile->ShowDialog() == DialogResult::OK)
	{
		String^ path = gcnew String(saveFile->FileName);
		if (saveFile->FilterIndex == 1)
		{
			SaveTSKF(path);
		}
		else if (saveFile->FilterIndex == 2)
		{
			SaveTXT(path);
		}
		MessageBox::Show("File saved", "Complete", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;	
	}
	MessageBox::Show("Saving failed", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
}

private: void SaveTSKF(String^ path)
{
	String^ log_path = gcnew String("");
	log_path = String::Copy(path);
	log_path = log_path->Replace(".tskf", "_log.txt");
	IO::TextWriter^ file = gcnew IO::StreamWriter(path);
	IO::TextWriter^ log_file = gcnew IO::StreamWriter(log_path);
	file->WriteLine("Tasker");
	file->WriteLine(project_name);
	file->WriteLine(task_number);
	for each (TaskerUnit::TaskerUnit ^ unit in taskerUnit_list)
	{
		file->WriteLine(unit->Number);
		file->WriteLine(unit->Task_Name);
		file->WriteLine(unit->Task_Performer);
		file->WriteLine(unit->Start_Date);
		file->WriteLine(unit->Finish_Date);
		file->WriteLine(unit->Deadline);
		file->WriteLine(unit->status);
		log_file->WriteLine(unit->Log);
		log_file->WriteLine("-@-");
	}
	file->Flush();
	file->Close();
	log_file->Flush();
	log_file->Close();
}

private: void SaveTXT(String^ path)
{
	String^ log_path = gcnew String("");
	log_path = String::Copy(path);
	String^ format1 = ".txt";
	String^ format2 = "_log.txt";
	log_path = log_path->Replace(format1, format2);
	IO::TextWriter^ log_file = gcnew IO::StreamWriter(log_path);
	IO::TextWriter^ file = gcnew IO::StreamWriter(path);
	String^ line = gcnew String("Tasker");
	String^ sep = gcnew String(",");
	file->WriteLine(line);
	line = "Project name" + sep + "Number of tasks";
		file->WriteLine(line);
	line = "";
	line = project_name + sep + task_number;
	file->WriteLine(line);
	line = "";
	line =  "Task number" + sep +
			"Task name" + sep +
			"Task performer" + sep +
			"Start date" + sep +
			"Finish date" + sep +
			"Deadline" + sep +
			"Status";
	file->WriteLine(line);

	for each (TaskerUnit::TaskerUnit ^ unit in taskerUnit_list)
	{
		int status_converted = (int)unit->status;
		line = "";
		line =  unit->Number + sep +
				unit->Task_Name + sep +
				unit->Task_Performer + sep +
				unit->Start_Date + sep +
				unit->Finish_Date + sep +
				unit->Deadline + sep +
				status_converted;
		file->WriteLine(line);
		log_file->WriteLine(unit->Task_Name);
		log_file->WriteLine("Task number " + unit->Number);
		log_file->WriteLine(unit->Log);
		log_file->WriteLine("-@-");
	}
	file->Flush();
	file->Close();
	log_file->Flush();
	log_file->Close();
}

public: Void OpenProject(IO::TextReader^ file, IO::TextReader^ log)
{
	file->ReadLine();
	project_name = file->ReadLine();
	task_number = Convert::ToInt64(file->ReadLine());
	for (int i = 0; i < task_number; i++)
	{
		::TaskerUnit::TaskerUnit^ unit = gcnew ::TaskerUnit::TaskerUnit();
		unit->ActiveChanged += gcnew System::EventHandler(this, &ProjectUnit::ProjectUnit::OnActiveChanged);
		taskerUnit_list->Add(unit);
		if (i == 0)
		{
			taskerUnit_list[i]->Location = Point(3, 3);
		}
		else
		{
			taskerUnit_list[i]->Location = Point(3, taskerUnit_list[i - 1]->Bottom + 3);
		}
		unit->Number = Convert::ToInt32(file->ReadLine());
		unit->Task_Name = file->ReadLine();
		unit->Task_Performer = file->ReadLine();
		unit->Start_Date = file->ReadLine();
		unit->Finish_Date = file->ReadLine();
		unit->Deadline = file->ReadLine();
		unit->status = (en_STATUS)Convert::ToInt32(file->ReadLine());
		String^ log_string = gcnew String("");
		log_string = log->ReadLine();
		while (log_string != "-@-")
		{
			unit->Log += log_string + Environment::NewLine;
			log_string = log->ReadLine();
		}
		this->pages_list[0]->Controls->Add(taskerUnit_list[i]);
		Series_Init();
	}
}

private: Void OnDateChanged(System::Object^ sender, System::EventArgs^ e)
{
	Series_Init();
}
};
}
#pragma endregion