#pragma once
#include "process.h"
#include "memory.h"
#include "logger.h"

namespace dcsstrainer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{

	private: System::Windows::Forms::TextBox^ dexterity;
	private: System::Windows::Forms::TextBox^ strength;
	private: System::Windows::Forms::TextBox^ intelligence;
	private: System::Windows::Forms::CheckBox^ godmode;
	private: System::Windows::Forms::CheckBox^ infinitemana;
	public: System::Windows::Forms::ListBox^ ConsoleLog;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;

	public:
		
		static MainForm^ instance;
		DWORD process_id;
		HANDLE process;

		uintptr_t moduleBase;

		MainForm()
		{
			// initialize form
			InitializeComponent();
			instance = this;

			// look for crawl
			wchar_t name[16] = L"crawl-tiles.exe";

			// get process ID of crawl
			MainForm::process_id = GetProcessID(name);

			// if successful
			if (MainForm::process_id) {

				logger::WriteLinetoConsole("Found crawl-tiles.exe. Locating base address...");

				// get handle
				MainForm::process = OpenProcess(PROCESS_ALL_ACCESS, NULL, process_id);

				// get module base address
				MainForm::moduleBase = ModuleBaseAddress(process_id, name);

			}
			else {
				logger::WriteLinetoConsole("Process not found. Please start crawl-tiles.exe before starting the trainer.");
				return;
			}
			logger::WriteLinetoConsole("Located address. Enjoy the trainer.");

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
			System::Windows::Forms::Label^ label2;
			System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Label^ label3;
			System::Windows::Forms::Label^ customstat;
			System::Windows::Forms::Label^ label5;
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->intelligence = (gcnew System::Windows::Forms::TextBox());
			this->dexterity = (gcnew System::Windows::Forms::TextBox());
			this->strength = (gcnew System::Windows::Forms::TextBox());
			this->ConsoleLog = (gcnew System::Windows::Forms::ListBox());
			this->godmode = (gcnew System::Windows::Forms::CheckBox());
			this->infinitemana = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			label2 = (gcnew System::Windows::Forms::Label());
			label1 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			customstat = (gcnew System::Windows::Forms::Label());
			label5 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			label2->Location = System::Drawing::Point(25, 6);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(47, 13);
			label2->TabIndex = 4;
			label2->Text = L"Strength";
			// 
			// label1
			// 
			label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			label1->Location = System::Drawing::Point(11, 32);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(61, 13);
			label1->TabIndex = 3;
			label1->Text = L"Intelligence";
			// 
			// label3
			// 
			label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			label3->Location = System::Drawing::Point(24, 59);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(48, 13);
			label3->TabIndex = 5;
			label3->Text = L"Dexterity";
			// 
			// customstat
			// 
			customstat->AutoSize = true;
			customstat->Location = System::Drawing::Point(126, 43);
			customstat->Name = L"customstat";
			customstat->Size = System::Drawing::Size(69, 13);
			customstat->TabIndex = 4;
			customstat->Text = L"Custom Stats";
			// 
			// label5
			// 
			label5->AutoSize = true;
			label5->Location = System::Drawing::Point(9, 43);
			label5->Name = L"label5";
			label5->Size = System::Drawing::Size(38, 13);
			label5->TabIndex = 5;
			label5->Text = L"Hacks";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->tableLayoutPanel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				64.28571F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35.71429F)));
			this->tableLayoutPanel1->Controls->Add(label2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(label1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(label3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->intelligence, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->dexterity, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->strength, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(129, 59);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33333F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(119, 81);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// intelligence
			// 
			this->intelligence->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->intelligence->Location = System::Drawing::Point(78, 29);
			this->intelligence->MaxLength = 3;
			this->intelligence->Name = L"intelligence";
			this->intelligence->Size = System::Drawing::Size(36, 20);
			this->intelligence->TabIndex = 0;
			this->intelligence->TextChanged += gcnew System::EventHandler(this, &MainForm::intelligence_TextChanged);
			// 
			// dexterity
			// 
			this->dexterity->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dexterity->Location = System::Drawing::Point(78, 55);
			this->dexterity->MaxLength = 3;
			this->dexterity->Name = L"dexterity";
			this->dexterity->Size = System::Drawing::Size(36, 20);
			this->dexterity->TabIndex = 0;
			this->dexterity->TextChanged += gcnew System::EventHandler(this, &MainForm::dexterity_TextChanged);
			// 
			// strength
			// 
			this->strength->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->strength->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->strength->Location = System::Drawing::Point(78, 3);
			this->strength->MaxLength = 3;
			this->strength->Name = L"strength";
			this->strength->Size = System::Drawing::Size(36, 20);
			this->strength->TabIndex = 0;
			this->strength->TextChanged += gcnew System::EventHandler(this, &MainForm::strength_TextChanged);
			// 
			// ConsoleLog
			// 
			this->ConsoleLog->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ConsoleLog->Enabled = false;
			this->ConsoleLog->FormattingEnabled = true;
			this->ConsoleLog->Location = System::Drawing::Point(12, 175);
			this->ConsoleLog->Name = L"ConsoleLog";
			this->ConsoleLog->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->ConsoleLog->Size = System::Drawing::Size(460, 82);
			this->ConsoleLog->TabIndex = 6;
			// 
			// godmode
			// 
			this->godmode->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->godmode->AutoSize = true;
			this->godmode->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->godmode->Location = System::Drawing::Point(34, 3);
			this->godmode->Name = L"godmode";
			this->godmode->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->godmode->Size = System::Drawing::Size(72, 15);
			this->godmode->TabIndex = 0;
			this->godmode->Text = L"Godmode";
			this->godmode->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->godmode->UseVisualStyleBackColor = true;
			this->godmode->CheckedChanged += gcnew System::EventHandler(this, &MainForm::godmode_CheckedChanged);
			// 
			// infinitemana
			// 
			this->infinitemana->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->infinitemana->AutoSize = true;
			this->infinitemana->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->infinitemana->Location = System::Drawing::Point(19, 24);
			this->infinitemana->Name = L"infinitemana";
			this->infinitemana->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->infinitemana->Size = System::Drawing::Size(87, 16);
			this->infinitemana->TabIndex = 0;
			this->infinitemana->Text = L"Infinite Mana";
			this->infinitemana->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->infinitemana->UseVisualStyleBackColor = true;
			this->infinitemana->CheckedChanged += gcnew System::EventHandler(this, &MainForm::infinitemana_CheckedChanged);
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->infinitemana, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->godmode, 0, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(12, 59);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(111, 45);
			this->tableLayoutPanel2->TabIndex = 3;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(485, 269);
			this->Controls->Add(this->ConsoleLog);
			this->Controls->Add(label5);
			this->Controls->Add(customstat);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"DCSS v25.0 Trainer";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void godmode_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void infinitemana_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void intelligence_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dexterity_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void strength_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);




//private: System::Void ConsoleLog_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
};

};