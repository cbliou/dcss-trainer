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


	private: System::Windows::Forms::CheckBox^ nohunger;
	private: System::Windows::Forms::Timer^ GUITimer;
	private: System::Windows::Forms::Label^ attached;
	private: System::Windows::Forms::Label^ attachedtext;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Button^ applystats;

	private: System::Windows::Forms::StatusStrip^ statusStrip1;











	public:
		static MainForm^ instance;

		MainForm()
		{
			// initialize form
			InitializeComponent();
			instance = this;

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
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::Label^ label2;
			System::Windows::Forms::Label^ label1;
			System::Windows::Forms::Label^ label3;
			System::Windows::Forms::Label^ customstat;
			System::Windows::Forms::Label^ label5;
			this->dexterity = (gcnew System::Windows::Forms::TextBox());
			this->strength = (gcnew System::Windows::Forms::TextBox());
			this->intelligence = (gcnew System::Windows::Forms::TextBox());
			this->ConsoleLog = (gcnew System::Windows::Forms::ListBox());
			this->godmode = (gcnew System::Windows::Forms::CheckBox());
			this->infinitemana = (gcnew System::Windows::Forms::CheckBox());
			this->nohunger = (gcnew System::Windows::Forms::CheckBox());
			this->GUITimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->attached = (gcnew System::Windows::Forms::Label());
			this->attachedtext = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->applystats = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			label2 = (gcnew System::Windows::Forms::Label());
			label1 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			customstat = (gcnew System::Windows::Forms::Label());
			label5 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			label2->Anchor = System::Windows::Forms::AnchorStyles::None;
			label2->Location = System::Drawing::Point(3, 2);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(74, 22);
			label2->TabIndex = 4;
			label2->Text = L"Strength";
			label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			label1->Location = System::Drawing::Point(3, 29);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(74, 19);
			label1->TabIndex = 3;
			label1->Text = L"Intelligence";
			label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			label3->Location = System::Drawing::Point(3, 57);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(74, 16);
			label3->TabIndex = 5;
			label3->Text = L"Dexterity";
			label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// customstat
			// 
			customstat->AutoSize = true;
			customstat->Location = System::Drawing::Point(141, 20);
			customstat->Name = L"customstat";
			customstat->Size = System::Drawing::Size(75, 15);
			customstat->TabIndex = 4;
			customstat->Text = L"Custom Stats";
			// 
			// label5
			// 
			label5->AutoSize = true;
			label5->Location = System::Drawing::Point(9, 20);
			label5->Name = L"label5";
			label5->Size = System::Drawing::Size(39, 15);
			label5->TabIndex = 0;
			label5->Text = L"Hacks";
			// 
			// dexterity
			// 
			this->dexterity->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->dexterity->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dexterity->Location = System::Drawing::Point(83, 54);
			this->dexterity->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dexterity->MaxLength = 3;
			this->dexterity->Name = L"dexterity";
			this->dexterity->Size = System::Drawing::Size(37, 22);
			this->dexterity->TabIndex = 0;
			this->dexterity->TextChanged += gcnew System::EventHandler(this, &MainForm::dexterity_TextChanged);
			// 
			// strength
			// 
			this->strength->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->strength->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel2->SetFlowBreak(this->strength, true);
			this->strength->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->strength->Location = System::Drawing::Point(83, 2);
			this->strength->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->strength->MaxLength = 3;
			this->strength->Name = L"strength";
			this->strength->Size = System::Drawing::Size(37, 22);
			this->strength->TabIndex = 0;
			this->strength->TextChanged += gcnew System::EventHandler(this, &MainForm::strength_TextChanged);
			// 
			// intelligence
			// 
			this->intelligence->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->intelligence->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->intelligence->Location = System::Drawing::Point(83, 28);
			this->intelligence->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->intelligence->MaxLength = 3;
			this->intelligence->Name = L"intelligence";
			this->intelligence->Size = System::Drawing::Size(37, 22);
			this->intelligence->TabIndex = 0;
			this->intelligence->TextChanged += gcnew System::EventHandler(this, &MainForm::intelligence_TextChanged);
			// 
			// ConsoleLog
			// 
			this->ConsoleLog->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->ConsoleLog->BackColor = System::Drawing::SystemColors::Control;
			this->ConsoleLog->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ConsoleLog->Enabled = false;
			this->ConsoleLog->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ConsoleLog->FormattingEnabled = true;
			this->ConsoleLog->ItemHeight = 15;
			this->ConsoleLog->Location = System::Drawing::Point(0, 294);
			this->ConsoleLog->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ConsoleLog->Name = L"ConsoleLog";
			this->ConsoleLog->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->ConsoleLog->Size = System::Drawing::Size(454, 15);
			this->ConsoleLog->TabIndex = 6;
			// 
			// godmode
			// 
			this->godmode->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->godmode->AutoSize = true;
			this->godmode->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->godmode->Location = System::Drawing::Point(3, 2);
			this->godmode->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->godmode->Name = L"godmode";
			this->godmode->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->godmode->Size = System::Drawing::Size(79, 19);
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
			this->infinitemana->Location = System::Drawing::Point(3, 25);
			this->infinitemana->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->infinitemana->Name = L"infinitemana";
			this->infinitemana->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->infinitemana->Size = System::Drawing::Size(96, 19);
			this->infinitemana->TabIndex = 0;
			this->infinitemana->Text = L"Infinite Mana";
			this->infinitemana->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->infinitemana->UseVisualStyleBackColor = true;
			this->infinitemana->CheckedChanged += gcnew System::EventHandler(this, &MainForm::infinitemana_CheckedChanged);
			// 
			// nohunger
			// 
			this->nohunger->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->nohunger->AutoSize = true;
			this->nohunger->Location = System::Drawing::Point(3, 48);
			this->nohunger->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->nohunger->Name = L"nohunger";
			this->nohunger->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->nohunger->Size = System::Drawing::Size(84, 19);
			this->nohunger->TabIndex = 7;
			this->nohunger->Text = L"No Hunger";
			this->nohunger->UseVisualStyleBackColor = true;
			this->nohunger->CheckedChanged += gcnew System::EventHandler(this, &MainForm::nohunger_CheckedChanged);
			// 
			// GUITimer
			// 
			this->GUITimer->Enabled = true;
			this->GUITimer->Interval = 200;
			this->GUITimer->Tick += gcnew System::EventHandler(this, &MainForm::GUITimer_Tick);
			// 
			// attached
			// 
			this->attached->AutoSize = true;
			this->attached->Location = System::Drawing::Point(460, 294);
			this->attached->Name = L"attached";
			this->attached->Size = System::Drawing::Size(0, 15);
			this->attached->TabIndex = 7;
			// 
			// attachedtext
			// 
			this->attachedtext->AutoSize = true;
			this->attachedtext->ForeColor = System::Drawing::SystemColors::ControlText;
			this->attachedtext->Location = System::Drawing::Point(416, 294);
			this->attachedtext->Name = L"attachedtext";
			this->attachedtext->Size = System::Drawing::Size(44, 15);
			this->attachedtext->TabIndex = 8;
			this->attachedtext->Text = L"Status: ";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel1->Controls->Add(this->godmode);
			this->flowLayoutPanel1->Controls->Add(this->infinitemana);
			this->flowLayoutPanel1->Controls->Add(this->nohunger);
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 38);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(116, 130);
			this->flowLayoutPanel1->TabIndex = 9;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->BackColor = System::Drawing::SystemColors::Control;
			this->flowLayoutPanel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->flowLayoutPanel2->Controls->Add(label2);
			this->flowLayoutPanel2->Controls->Add(this->strength);
			this->flowLayoutPanel2->Controls->Add(label1);
			this->flowLayoutPanel2->Controls->Add(this->intelligence);
			this->flowLayoutPanel2->Controls->Add(label3);
			this->flowLayoutPanel2->Controls->Add(this->dexterity);
			this->flowLayoutPanel2->Location = System::Drawing::Point(144, 38);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(127, 98);
			this->flowLayoutPanel2->TabIndex = 10;
			// 
			// applystats
			// 
			this->applystats->Location = System::Drawing::Point(144, 142);
			this->applystats->Name = L"applystats";
			this->applystats->Size = System::Drawing::Size(127, 26);
			this->applystats->TabIndex = 11;
			this->applystats->Text = L"Refresh + Apply Stats";
			this->applystats->UseVisualStyleBackColor = true;
			this->applystats->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 289);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(605, 22);
			this->statusStrip1->TabIndex = 13;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(605, 311);
			this->Controls->Add(this->attachedtext);
			this->Controls->Add(customstat);
			this->Controls->Add(label5);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->attached);
			this->Controls->Add(this->applystats);
			this->Controls->Add(this->ConsoleLog);
			this->Controls->Add(this->statusStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Lato", 8.999999F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::SystemColors::Desktop;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"DCSS v25.0 Trainer";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void set_stat(BYTE stat, Windows::Forms::TextBox^ text, uintptr_t addy);
	private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: System::Void godmode_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void infinitemana_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void intelligence_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dexterity_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void strength_TextChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void nohunger_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	//private: System::Void ConsoleLog_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void GUITimer_Tick(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};

};