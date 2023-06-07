#pragma once
#include "NewProjectDialog.h"

namespace Tasker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using System::Collections::Generic::List;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ToolStrip^ ts_TopMenu;
	protected:

	protected:
	private: System::Windows::Forms::ToolStripDropDownButton^ btn_File;
	private: System::Windows::Forms::ToolStripMenuItem^ file_NewProject;
	private: System::Windows::Forms::ToolStripMenuItem^ file_OpenProject;
	private: System::Windows::Forms::ToolStripMenuItem^ file_Exit;
	private: System::Windows::Forms::TabControl^ main_TabControl;
	private: System::Windows::Forms::Panel^ pnl_Main;
	private: System::Windows::Forms::ToolStripMenuItem^ file_Save;

	//List of projects
	private: List<::ProjectUnit::ProjectUnit^>^ project_list = gcnew List<::ProjectUnit::ProjectUnit^>;

	private: int project_num = 0;
	private: System::Windows::Forms::ToolStripDropDownButton^ btn_Edit;
	private: System::Windows::Forms::ToolStripMenuItem^ edit_AddTask;
	private: System::Windows::Forms::ToolStripMenuItem^ edit_DelTask;
	private: System::Windows::Forms::ToolStripMenuItem^ edit_DelProject;
	private: System::Windows::Forms::TextBox^ txt_MainLog;
	private: System::Windows::Forms::Label^ lbl_MainLog;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ main_Gantt;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			this->ts_TopMenu = (gcnew System::Windows::Forms::ToolStrip());
			this->btn_File = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->file_NewProject = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->file_OpenProject = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->file_Save = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->file_Exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btn_Edit = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->edit_AddTask = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->edit_DelTask = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->edit_DelProject = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pnl_Main = (gcnew System::Windows::Forms::Panel());
			this->main_TabControl = (gcnew System::Windows::Forms::TabControl());
			this->txt_MainLog = (gcnew System::Windows::Forms::TextBox());
			this->lbl_MainLog = (gcnew System::Windows::Forms::Label());
			this->main_Gantt = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->ts_TopMenu->SuspendLayout();
			this->pnl_Main->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_Gantt))->BeginInit();
			this->SuspendLayout();
			// 
			// ts_TopMenu
			// 
			this->ts_TopMenu->BackColor = System::Drawing::SystemColors::ControlLight;
			this->ts_TopMenu->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->ts_TopMenu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->ts_TopMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->btn_File, this->btn_Edit });
			this->ts_TopMenu->Location = System::Drawing::Point(0, 0);
			this->ts_TopMenu->Name = L"ts_TopMenu";
			this->ts_TopMenu->Size = System::Drawing::Size(897, 27);
			this->ts_TopMenu->TabIndex = 0;
			this->ts_TopMenu->Text = L"toolStrip1";
			// 
			// btn_File
			// 
			this->btn_File->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->btn_File->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->file_NewProject,
					this->file_OpenProject, this->file_Save, this->file_Exit
			});
			this->btn_File->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_File.Image")));
			this->btn_File->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_File->Name = L"btn_File";
			this->btn_File->Size = System::Drawing::Size(46, 24);
			this->btn_File->Text = L"File";
			// 
			// file_NewProject
			// 
			this->file_NewProject->Name = L"file_NewProject";
			this->file_NewProject->Size = System::Drawing::Size(224, 26);
			this->file_NewProject->Text = L"New project";
			this->file_NewProject->Click += gcnew System::EventHandler(this, &MainForm::file_NewProject_Click);
			// 
			// file_OpenProject
			// 
			this->file_OpenProject->Name = L"file_OpenProject";
			this->file_OpenProject->Size = System::Drawing::Size(224, 26);
			this->file_OpenProject->Text = L"Open project";
			this->file_OpenProject->Click += gcnew System::EventHandler(this, &MainForm::file_OpenProject_Click);
			// 
			// file_Save
			// 
			this->file_Save->Enabled = false;
			this->file_Save->Name = L"file_Save";
			this->file_Save->Size = System::Drawing::Size(224, 26);
			this->file_Save->Text = L"Save project";
			this->file_Save->Click += gcnew System::EventHandler(this, &MainForm::file_Save_Click);
			// 
			// file_Exit
			// 
			this->file_Exit->Name = L"file_Exit";
			this->file_Exit->Size = System::Drawing::Size(224, 26);
			this->file_Exit->Text = L"Exit";
			this->file_Exit->Click += gcnew System::EventHandler(this, &MainForm::file_Exit_Click);
			// 
			// btn_Edit
			// 
			this->btn_Edit->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->btn_Edit->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->edit_AddTask,
					this->edit_DelTask, this->edit_DelProject
			});
			this->btn_Edit->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_Edit.Image")));
			this->btn_Edit->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->btn_Edit->Name = L"btn_Edit";
			this->btn_Edit->Size = System::Drawing::Size(49, 24);
			this->btn_Edit->Text = L"Edit";
			// 
			// edit_AddTask
			// 
			this->edit_AddTask->Enabled = false;
			this->edit_AddTask->Name = L"edit_AddTask";
			this->edit_AddTask->Size = System::Drawing::Size(224, 26);
			this->edit_AddTask->Text = L"Add task";
			this->edit_AddTask->Click += gcnew System::EventHandler(this, &MainForm::edit_AddTask_Click);
			// 
			// edit_DelTask
			// 
			this->edit_DelTask->Enabled = false;
			this->edit_DelTask->Name = L"edit_DelTask";
			this->edit_DelTask->Size = System::Drawing::Size(224, 26);
			this->edit_DelTask->Text = L"Delete task";
			this->edit_DelTask->Click += gcnew System::EventHandler(this, &MainForm::edit_DelTask_Click);
			// 
			// edit_DelProject
			// 
			this->edit_DelProject->Enabled = false;
			this->edit_DelProject->Name = L"edit_DelProject";
			this->edit_DelProject->Size = System::Drawing::Size(224, 26);
			this->edit_DelProject->Text = L"Delete project";
			this->edit_DelProject->Click += gcnew System::EventHandler(this, &MainForm::edit_DelProject_Click);
			// 
			// pnl_Main
			// 
			this->pnl_Main->BackColor = System::Drawing::Color::White;
			this->pnl_Main->Controls->Add(this->main_TabControl);
			this->pnl_Main->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnl_Main->Location = System::Drawing::Point(0, 27);
			this->pnl_Main->Name = L"pnl_Main";
			this->pnl_Main->Size = System::Drawing::Size(897, 426);
			this->pnl_Main->TabIndex = 1;
			// 
			// main_TabControl
			// 
			this->main_TabControl->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->main_TabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->main_TabControl->Location = System::Drawing::Point(0, 0);
			this->main_TabControl->Name = L"main_TabControl";
			this->main_TabControl->SelectedIndex = 0;
			this->main_TabControl->Size = System::Drawing::Size(897, 426);
			this->main_TabControl->TabIndex = 0;
			this->main_TabControl->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::main_TabControl_MouseClick);
			this->main_TabControl->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::main_TabControl_MouseDoubleClick);
			// 
			// txt_MainLog
			// 
			this->txt_MainLog->Enabled = false;
			this->txt_MainLog->Location = System::Drawing::Point(622, 30);
			this->txt_MainLog->Multiline = true;
			this->txt_MainLog->Name = L"txt_MainLog";
			this->txt_MainLog->Size = System::Drawing::Size(260, 411);
			this->txt_MainLog->TabIndex = 3;
			this->txt_MainLog->Visible = false;
			this->txt_MainLog->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::txt_MainLog_KeyUp);
			// 
			// lbl_MainLog
			// 
			this->lbl_MainLog->AutoSize = true;
			this->lbl_MainLog->Enabled = true;
			this->lbl_MainLog->Location = System::Drawing::Point(490, 27);
			this->lbl_MainLog->Name = L"lbl_MainLog";
			this->lbl_MainLog->Size = System::Drawing::Size(30, 16);
			this->lbl_MainLog->TabIndex = 4;
			this->lbl_MainLog->Text = L"Log";
			this->lbl_MainLog->Visible = false;
			// 
			// main_Gantt
			// 
			chartArea1->Name = L"ChartArea1";
			this->main_Gantt->ChartAreas->Add(chartArea1);
			this->main_Gantt->ChartAreas[0]->AxisY->IntervalAutoMode = DataVisualization::Charting::IntervalAutoMode::FixedCount;
			this->main_Gantt->ChartAreas[0]->AxisY->IntervalType = System::Windows::Forms::DataVisualization::Charting::DateTimeIntervalType::Days;
			this->main_Gantt->ChartAreas[0]->AxisY->Minimum = 0;
			this->main_Gantt->ChartAreas[0]->AxisY->Maximum = 365;
			this->main_Gantt->Enabled = false;
			this->main_Gantt->Location = System::Drawing::Point(101, 70);
			this->main_Gantt->Name = L"main_Gantt";
			this->main_Gantt->Size = System::Drawing::Size(300, 300);
			this->main_Gantt->TabIndex = 5;
			this->main_Gantt->Visible = false;
			// 
			// MainForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(897, 453);
			this->Controls->Add(this->main_Gantt);
			this->Controls->Add(this->pnl_Main);
			this->Controls->Add(this->ts_TopMenu);
			this->Controls->Add(this->txt_MainLog);
			this->Controls->Add(this->lbl_MainLog);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MinimumSize = System::Drawing::Size(915, 500);
			this->Name = L"MainForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Tasker";
			this->SizeChanged += gcnew System::EventHandler(this, &MainForm::MainForm_SizeChanged);
			this->ts_TopMenu->ResumeLayout(false);
			this->ts_TopMenu->PerformLayout();
			this->pnl_Main->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->main_Gantt))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void file_Exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}

private: System::Void file_NewProject_Click(System::Object^ sender, System::EventArgs^ e)
{
	Create_Project("","");
}

private: System::Void main_TabControl_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	NewProjectDialog^ dialog = gcnew NewProjectDialog(this->main_TabControl->SelectedTab->Text);
	dialog->ShowDialog();
	project_list[::ProjectUnit::ProjectUnit::active_project]->project_name = dialog->Get_ProjName();
	this->main_TabControl->SelectedTab->Text = project_list[::ProjectUnit::ProjectUnit::active_project]->project_name;
}

private: System::Void main_TabControl_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	::ProjectUnit::ProjectUnit::active_project = this->main_TabControl->SelectedIndex;
	this->main_Gantt->Series->Clear();
	this->main_Gantt->Series->Add(project_list[::ProjectUnit::ProjectUnit::active_project]->tasks_graph);
}

private: System::Void edit_DelProject_Click(System::Object^ sender, System::EventArgs^ e)
{
	project_num--;
	main_TabControl->TabPages->RemoveAt(::ProjectUnit::ProjectUnit::active_project);
	project_list->RemoveAt(::ProjectUnit::ProjectUnit::active_project);
	this->main_Gantt->Series->Clear();
	for (int i = 0; i < project_list->Count; i++)
	{
		project_list[i]->project_number = i;
	}
	if (project_num == 0)
	{
		this->edit_DelProject->Enabled = false;
		this->edit_AddTask->Enabled = false;
		this->edit_DelTask->Enabled = false;
		this->file_Save->Enabled = false;
		this->txt_MainLog->Text = "";
		this->txt_MainLog->Enabled = false;
	}
}
private: System::Void edit_AddTask_Click(System::Object^ sender, System::EventArgs^ e)
{
	project_list[::ProjectUnit::ProjectUnit::active_project]->AddTask();
	this->edit_DelTask->Enabled = true;
	this->txt_MainLog->Enabled = true;
}
private: System::Void edit_DelTask_Click(System::Object^ sender, System::EventArgs^ e)
{
	project_list[::ProjectUnit::ProjectUnit::active_project]->DeleteTask();
	if (project_list[::ProjectUnit::ProjectUnit::active_project]->task_number == 0)
	{
		this->edit_DelTask->Enabled = false;
		this->txt_MainLog->Enabled = false;
	}
	this->txt_MainLog->Text = "";
}
private: System::Void MainForm_SizeChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (this->WindowState == FormWindowState::Maximized)
	{
		this->pnl_Main->Dock = System::Windows::Forms::DockStyle::None;
		this->pnl_Main->Size = System::Drawing::Size(894, 466);
		this->main_TabControl->Size = System::Drawing::Size(894, 466);
		this->lbl_MainLog->Left = this->pnl_Main->Right + 3;
		this->lbl_MainLog->Top = 27;
		this->lbl_MainLog->Visible = true;
		this->txt_MainLog->Left = this->pnl_Main->Right + 3;
		this->txt_MainLog->Top = this->lbl_MainLog->Bottom + 3;
		this->txt_MainLog->Width = this->Right - this->pnl_Main->Right - 15;
		this->txt_MainLog->Height = this->pnl_Main->Height - this->lbl_MainLog->Height - 4;
		this->txt_MainLog->Visible = true;
		this->main_Gantt->Enabled = true;
		this->main_Gantt->Visible = true;
		this->main_Gantt->Left = this->pnl_Main->Left;
		this->main_Gantt->Top = this->pnl_Main->Bottom + 3;
		this->main_Gantt->Dock = System::Windows::Forms::DockStyle::Bottom;
		if (project_num != 0)
			this->txt_MainLog->Enabled = true;
	}
	else
	{
		this->txt_MainLog->Text = "";
		this->txt_MainLog->Enabled = false;
		this->txt_MainLog->Visible = false;
		this->lbl_MainLog->Enabled = false;
		this->lbl_MainLog->Visible = false;
		this->main_Gantt->Enabled = false;
		this->main_Gantt->Visible = false;
	}
}
private: System::Void txt_MainLog_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	if ((project_num != 0) || (project_list[::ProjectUnit::ProjectUnit::active_project]->task_number == 0))
		project_list[::ProjectUnit::ProjectUnit::active_project]->active_task_log = this->txt_MainLog->Text;
	else
		this->txt_MainLog->Text = "";
}

void Tasker::MainForm::OnTaskActivated(System::Object^ sender, System::EventArgs^ e)
{
	this->txt_MainLog->Text = project_list[::ProjectUnit::ProjectUnit::active_project]->active_task_log;
}
void Tasker::MainForm::OnPointsRefreshed(System::Object^ sender, System::EventArgs^ e)
{
	this->main_Gantt->Series->Clear();
	this->main_Gantt->Series->Add(project_list[::ProjectUnit::ProjectUnit::active_project]->tasks_graph);
}
private: System::Void file_Save_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (project_num != 0)
	{
		project_list[::ProjectUnit::ProjectUnit::active_project]->SaveProjectDialog();
	}
}
private: System::Void file_OpenProject_Click(System::Object^ sender, System::EventArgs^ e)
{
	OpenFileDialog^ openFile = gcnew OpenFileDialog();
	openFile->Filter = "Tasker file (*.tskf)|*.tskf|All files (*.*)|*.*";
	openFile->FilterIndex = 1;
	openFile->RestoreDirectory = true;
	OpenFileDialog^ openLog = gcnew OpenFileDialog();
	openLog->Filter = "Tasker file (*.txt)|*.txt|All files (*.*)|*.*";
	openLog->FilterIndex = 1;
	openLog->RestoreDirectory = true;
	if (openFile->ShowDialog() == System::Windows::Forms::DialogResult::OK &&
		openLog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		String^ path = gcnew String(openFile->FileName);
		String^ log = gcnew String(openLog->FileName);
		IO::TextReader^ file = gcnew IO::StreamReader(path);
		String^ line = gcnew String("");
		line = file->ReadLine();
		if (line != "Tasker")
		{
			MessageBox::Show("Incorrect file", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		else
		{
			Create_Project(path, log);
			this->txt_MainLog->Enabled = true;
		}
		file->Close();
	}
}

private: System::Void Create_Project(String^ path, String^ log_path)
{
	project_num++;
	::ProjectUnit::ProjectUnit^ project = gcnew ::ProjectUnit::ProjectUnit();
	project->project_number = project_num;
	TabPage^ page = gcnew TabPage;
	page->AutoScroll = true;
	page->Width = this->main_TabControl->Width - 12;
	project->Width = page->Width - 15;
	page->Text = project->project_name;
	project->TaskActivated += gcnew System::EventHandler(this, &Tasker::MainForm::OnTaskActivated);
	project->PointsRefreshed += gcnew System::EventHandler(this, &Tasker::MainForm::OnPointsRefreshed);
	project_list->Add(project);
	page->Controls->Add(project_list[project_num - 1]);
	main_TabControl->TabPages->Add(page);
	this->edit_DelProject->Enabled = true;
	this->edit_AddTask->Enabled = true;
	this->file_Save->Enabled = true;
	if (path == "")
	{
		NewProjectDialog^ dialog = gcnew NewProjectDialog;
		dialog->ShowDialog();
		project->project_name = dialog->Get_ProjName();
	}
	else
	{
		IO::TextReader^ file = gcnew IO::StreamReader(path);
		IO::TextReader^ log = gcnew IO::StreamReader(log_path);
		project->OpenProject(file, log);
	}
	page->Text = project->project_name;
	if (project->task_number > 0)
	{
		this->edit_DelTask->Enabled = true;
	}
}
};
}






