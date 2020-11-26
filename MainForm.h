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


	private: System::Windows::Forms::Button^ applystats;

	private: System::Windows::Forms::StatusStrip^ statusStrip1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ stealth;

	private: System::Windows::Forms::Label^ label60;
	private: System::Windows::Forms::TextBox^ evocations;

	private: System::Windows::Forms::Label^ label61;
	private: System::Windows::Forms::TextBox^ invocations;

	private: System::Windows::Forms::Label^ label62;
	private: System::Windows::Forms::TextBox^ transmutations;



	private: System::Windows::Forms::Label^ label33;
	private: System::Windows::Forms::TextBox^ poisonmagic;

	private: System::Windows::Forms::Label^ label34;
	private: System::Windows::Forms::TextBox^ earthmagic;

	private: System::Windows::Forms::Label^ label35;
	private: System::Windows::Forms::TextBox^ airmagic;

	private: System::Windows::Forms::Label^ label36;
	private: System::Windows::Forms::TextBox^ icemagic;

	private: System::Windows::Forms::Label^ label37;
	private: System::Windows::Forms::TextBox^ firemagic;

	private: System::Windows::Forms::Label^ label38;
	private: System::Windows::Forms::TextBox^ translocations;

	private: System::Windows::Forms::Label^ label39;
	private: System::Windows::Forms::TextBox^ necromancy;

	private: System::Windows::Forms::Label^ label40;
	private: System::Windows::Forms::TextBox^ summonings;

	private: System::Windows::Forms::Label^ label41;
	private: System::Windows::Forms::TextBox^ charms;

	private: System::Windows::Forms::Label^ label42;
	private: System::Windows::Forms::TextBox^ hexes;

	private: System::Windows::Forms::Label^ label43;
	private: System::Windows::Forms::Label^ label44;
	private: System::Windows::Forms::TextBox^ conjurations;

	private: System::Windows::Forms::TextBox^ fighting;

	private: System::Windows::Forms::Label^ label45;
	private: System::Windows::Forms::TextBox^ spellcasting;

	private: System::Windows::Forms::Label^ label46;
	private: System::Windows::Forms::Label^ label47;
	private: System::Windows::Forms::TextBox^ shortblades;
	private: System::Windows::Forms::TextBox^ shields;


	private: System::Windows::Forms::TextBox^ unarmedcombat;

	private: System::Windows::Forms::Label^ label48;
	private: System::Windows::Forms::Label^ label49;
	private: System::Windows::Forms::TextBox^ dodging;

	private: System::Windows::Forms::Label^ label50;
	private: System::Windows::Forms::Label^ label51;
	private: System::Windows::Forms::TextBox^ staves;

	private: System::Windows::Forms::Label^ label52;
	private: System::Windows::Forms::TextBox^ slings;

	private: System::Windows::Forms::TextBox^ longblades;

	private: System::Windows::Forms::Label^ label32;
	private: System::Windows::Forms::TextBox^ throwing;

	private: System::Windows::Forms::TextBox^ polearms;

	private: System::Windows::Forms::Label^ label53;
	private: System::Windows::Forms::Label^ label54;
	private: System::Windows::Forms::TextBox^ crossbows;

	private: System::Windows::Forms::Label^ label55;
	private: System::Windows::Forms::Label^ label56;
	private: System::Windows::Forms::TextBox^ axes;
	private: System::Windows::Forms::TextBox^ bows;



	private: System::Windows::Forms::Label^ label57;
	private: System::Windows::Forms::Label^ label58;
	private: System::Windows::Forms::TextBox^ maces;



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
			this->applystats = (gcnew System::Windows::Forms::Button());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->stealth = (gcnew System::Windows::Forms::TextBox());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->evocations = (gcnew System::Windows::Forms::TextBox());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->invocations = (gcnew System::Windows::Forms::TextBox());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->transmutations = (gcnew System::Windows::Forms::TextBox());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->poisonmagic = (gcnew System::Windows::Forms::TextBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->earthmagic = (gcnew System::Windows::Forms::TextBox());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->airmagic = (gcnew System::Windows::Forms::TextBox());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->icemagic = (gcnew System::Windows::Forms::TextBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->firemagic = (gcnew System::Windows::Forms::TextBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->translocations = (gcnew System::Windows::Forms::TextBox());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->necromancy = (gcnew System::Windows::Forms::TextBox());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->summonings = (gcnew System::Windows::Forms::TextBox());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->charms = (gcnew System::Windows::Forms::TextBox());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->hexes = (gcnew System::Windows::Forms::TextBox());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->conjurations = (gcnew System::Windows::Forms::TextBox());
			this->fighting = (gcnew System::Windows::Forms::TextBox());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->spellcasting = (gcnew System::Windows::Forms::TextBox());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->shortblades = (gcnew System::Windows::Forms::TextBox());
			this->shields = (gcnew System::Windows::Forms::TextBox());
			this->unarmedcombat = (gcnew System::Windows::Forms::TextBox());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->dodging = (gcnew System::Windows::Forms::TextBox());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->staves = (gcnew System::Windows::Forms::TextBox());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->slings = (gcnew System::Windows::Forms::TextBox());
			this->longblades = (gcnew System::Windows::Forms::TextBox());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->throwing = (gcnew System::Windows::Forms::TextBox());
			this->polearms = (gcnew System::Windows::Forms::TextBox());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->crossbows = (gcnew System::Windows::Forms::TextBox());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->axes = (gcnew System::Windows::Forms::TextBox());
			this->bows = (gcnew System::Windows::Forms::TextBox());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->maces = (gcnew System::Windows::Forms::TextBox());
			label2 = (gcnew System::Windows::Forms::Label());
			label1 = (gcnew System::Windows::Forms::Label());
			label3 = (gcnew System::Windows::Forms::Label());
			customstat = (gcnew System::Windows::Forms::Label());
			label5 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			label2->Location = System::Drawing::Point(365, 10);
			label2->Name = L"label2";
			label2->Size = System::Drawing::Size(52, 15);
			label2->TabIndex = 4;
			label2->Text = L"Strength";
			label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			label1->Location = System::Drawing::Point(365, 36);
			label1->Name = L"label1";
			label1->Size = System::Drawing::Size(68, 22);
			label1->TabIndex = 3;
			label1->Text = L"Intelligence";
			label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label3
			// 
			label3->Location = System::Drawing::Point(365, 66);
			label3->Name = L"label3";
			label3->Size = System::Drawing::Size(68, 22);
			label3->TabIndex = 5;
			label3->Text = L"Dexterity";
			label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// customstat
			// 
			customstat->AutoSize = true;
			customstat->Location = System::Drawing::Point(149, 20);
			customstat->Name = L"customstat";
			customstat->Size = System::Drawing::Size(75, 15);
			customstat->TabIndex = 4;
			customstat->Text = L"Custom Stats";
			// 
			// label5
			// 
			label5->AutoSize = true;
			label5->Location = System::Drawing::Point(8, 20);
			label5->Name = L"label5";
			label5->Size = System::Drawing::Size(39, 15);
			label5->TabIndex = 0;
			label5->Text = L"Hacks";
			// 
			// dexterity
			// 
			this->dexterity->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dexterity->Location = System::Drawing::Point(461, 68);
			this->dexterity->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dexterity->MaxLength = 3;
			this->dexterity->Name = L"dexterity";
			this->dexterity->Size = System::Drawing::Size(37, 22);
			this->dexterity->TabIndex = 2;
			this->dexterity->TextChanged += gcnew System::EventHandler(this, &MainForm::dexterity_TextChanged);
			// 
			// strength
			// 
			this->strength->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->strength->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->strength->Location = System::Drawing::Point(461, 8);
			this->strength->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->strength->MaxLength = 3;
			this->strength->Name = L"strength";
			this->strength->Size = System::Drawing::Size(37, 22);
			this->strength->TabIndex = 0;
			this->strength->TextChanged += gcnew System::EventHandler(this, &MainForm::strength_TextChanged);
			// 
			// intelligence
			// 
			this->intelligence->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->intelligence->Location = System::Drawing::Point(461, 38);
			this->intelligence->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->intelligence->MaxLength = 3;
			this->intelligence->Name = L"intelligence";
			this->intelligence->Size = System::Drawing::Size(37, 22);
			this->intelligence->TabIndex = 1;
			this->intelligence->TextChanged += gcnew System::EventHandler(this, &MainForm::intelligence_TextChanged);
			// 
			// ConsoleLog
			// 
			this->ConsoleLog->BackColor = System::Drawing::SystemColors::Control;
			this->ConsoleLog->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->ConsoleLog->Enabled = false;
			this->ConsoleLog->ForeColor = System::Drawing::SystemColors::ControlText;
			this->ConsoleLog->FormattingEnabled = true;
			this->ConsoleLog->ItemHeight = 15;
			this->ConsoleLog->Location = System::Drawing::Point(0, 582);
			this->ConsoleLog->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->ConsoleLog->Name = L"ConsoleLog";
			this->ConsoleLog->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->ConsoleLog->Size = System::Drawing::Size(597, 15);
			this->ConsoleLog->TabIndex = 6;
			// 
			// godmode
			// 
			this->godmode->AutoSize = true;
			this->godmode->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->godmode->Location = System::Drawing::Point(5, 6);
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
			this->infinitemana->AutoSize = true;
			this->infinitemana->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->infinitemana->Location = System::Drawing::Point(5, 29);
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
			this->nohunger->AutoSize = true;
			this->nohunger->Location = System::Drawing::Point(5, 52);
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
			this->attached->Location = System::Drawing::Point(614, 582);
			this->attached->Name = L"attached";
			this->attached->Size = System::Drawing::Size(0, 15);
			this->attached->TabIndex = 7;
			// 
			// attachedtext
			// 
			this->attachedtext->AutoSize = true;
			this->attachedtext->ForeColor = System::Drawing::SystemColors::ControlText;
			this->attachedtext->Location = System::Drawing::Point(570, 582);
			this->attachedtext->Name = L"attachedtext";
			this->attachedtext->Size = System::Drawing::Size(44, 15);
			this->attachedtext->TabIndex = 8;
			this->attachedtext->Text = L"Status: ";
			// 
			// applystats
			// 
			this->applystats->Location = System::Drawing::Point(371, 470);
			this->applystats->Name = L"applystats";
			this->applystats->Size = System::Drawing::Size(127, 26);
			this->applystats->TabIndex = 11;
			this->applystats->Text = L"Refresh + Apply Stats";
			this->applystats->UseVisualStyleBackColor = true;
			this->applystats->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 575);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(752, 22);
			this->statusStrip1->TabIndex = 13;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->nohunger);
			this->panel2->Controls->Add(this->godmode);
			this->panel2->Controls->Add(this->infinitemana);
			this->panel2->Location = System::Drawing::Point(11, 38);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(116, 160);
			this->panel2->TabIndex = 15;
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->stealth);
			this->panel1->Controls->Add(this->applystats);
			this->panel1->Controls->Add(this->label60);
			this->panel1->Controls->Add(label3);
			this->panel1->Controls->Add(this->evocations);
			this->panel1->Controls->Add(this->label61);
			this->panel1->Controls->Add(this->invocations);
			this->panel1->Controls->Add(this->label62);
			this->panel1->Controls->Add(label2);
			this->panel1->Controls->Add(this->dexterity);
			this->panel1->Controls->Add(this->transmutations);
			this->panel1->Controls->Add(this->label33);
			this->panel1->Controls->Add(this->poisonmagic);
			this->panel1->Controls->Add(this->intelligence);
			this->panel1->Controls->Add(this->label34);
			this->panel1->Controls->Add(this->strength);
			this->panel1->Controls->Add(this->earthmagic);
			this->panel1->Controls->Add(label1);
			this->panel1->Controls->Add(this->label35);
			this->panel1->Controls->Add(this->airmagic);
			this->panel1->Controls->Add(this->label36);
			this->panel1->Controls->Add(this->icemagic);
			this->panel1->Controls->Add(this->label37);
			this->panel1->Controls->Add(this->firemagic);
			this->panel1->Controls->Add(this->label38);
			this->panel1->Controls->Add(this->translocations);
			this->panel1->Controls->Add(this->label39);
			this->panel1->Controls->Add(this->necromancy);
			this->panel1->Controls->Add(this->label40);
			this->panel1->Controls->Add(this->summonings);
			this->panel1->Controls->Add(this->label41);
			this->panel1->Controls->Add(this->charms);
			this->panel1->Controls->Add(this->label42);
			this->panel1->Controls->Add(this->hexes);
			this->panel1->Controls->Add(this->label43);
			this->panel1->Controls->Add(this->label44);
			this->panel1->Controls->Add(this->conjurations);
			this->panel1->Controls->Add(this->fighting);
			this->panel1->Controls->Add(this->label45);
			this->panel1->Controls->Add(this->spellcasting);
			this->panel1->Controls->Add(this->label46);
			this->panel1->Controls->Add(this->label47);
			this->panel1->Controls->Add(this->shortblades);
			this->panel1->Controls->Add(this->shields);
			this->panel1->Controls->Add(this->unarmedcombat);
			this->panel1->Controls->Add(this->label48);
			this->panel1->Controls->Add(this->label49);
			this->panel1->Controls->Add(this->dodging);
			this->panel1->Controls->Add(this->label50);
			this->panel1->Controls->Add(this->label51);
			this->panel1->Controls->Add(this->staves);
			this->panel1->Controls->Add(this->label52);
			this->panel1->Controls->Add(this->slings);
			this->panel1->Controls->Add(this->longblades);
			this->panel1->Controls->Add(this->label32);
			this->panel1->Controls->Add(this->throwing);
			this->panel1->Controls->Add(this->polearms);
			this->panel1->Controls->Add(this->label53);
			this->panel1->Controls->Add(this->label54);
			this->panel1->Controls->Add(this->crossbows);
			this->panel1->Controls->Add(this->label55);
			this->panel1->Controls->Add(this->label56);
			this->panel1->Controls->Add(this->axes);
			this->panel1->Controls->Add(this->bows);
			this->panel1->Controls->Add(this->label57);
			this->panel1->Controls->Add(this->label58);
			this->panel1->Controls->Add(this->maces);
			this->panel1->Location = System::Drawing::Point(152, 38);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(524, 517);
			this->panel1->TabIndex = 71;
			// 
			// stealth
			// 
			this->stealth->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->stealth->Location = System::Drawing::Point(295, 488);
			this->stealth->MaxLength = 2;
			this->stealth->Name = L"stealth";
			this->stealth->Size = System::Drawing::Size(37, 22);
			this->stealth->TabIndex = 78;
			// 
			// label60
			// 
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(188, 490);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(43, 15);
			this->label60->TabIndex = 77;
			this->label60->Text = L"Stealth";
			// 
			// evocations
			// 
			this->evocations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->evocations->Location = System::Drawing::Point(295, 458);
			this->evocations->MaxLength = 2;
			this->evocations->Name = L"evocations";
			this->evocations->Size = System::Drawing::Size(37, 22);
			this->evocations->TabIndex = 76;
			// 
			// label61
			// 
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(188, 460);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(65, 15);
			this->label61->TabIndex = 75;
			this->label61->Text = L"Evocations";
			// 
			// invocations
			// 
			this->invocations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->invocations->Location = System::Drawing::Point(295, 428);
			this->invocations->MaxLength = 2;
			this->invocations->Name = L"invocations";
			this->invocations->Size = System::Drawing::Size(37, 22);
			this->invocations->TabIndex = 74;
			// 
			// label62
			// 
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(188, 430);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(69, 15);
			this->label62->TabIndex = 73;
			this->label62->Text = L"Invocations";
			// 
			// transmutations
			// 
			this->transmutations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->transmutations->Location = System::Drawing::Point(295, 218);
			this->transmutations->MaxLength = 2;
			this->transmutations->Name = L"transmutations";
			this->transmutations->Size = System::Drawing::Size(37, 22);
			this->transmutations->TabIndex = 70;
			// 
			// label33
			// 
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(188, 220);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(89, 15);
			this->label33->TabIndex = 69;
			this->label33->Text = L"Transmutations";
			// 
			// poisonmagic
			// 
			this->poisonmagic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->poisonmagic->Location = System::Drawing::Point(295, 368);
			this->poisonmagic->MaxLength = 2;
			this->poisonmagic->Name = L"poisonmagic";
			this->poisonmagic->Size = System::Drawing::Size(37, 22);
			this->poisonmagic->TabIndex = 68;
			// 
			// label34
			// 
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(188, 370);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(77, 15);
			this->label34->TabIndex = 67;
			this->label34->Text = L"Poison Magic";
			// 
			// earthmagic
			// 
			this->earthmagic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->earthmagic->Location = System::Drawing::Point(295, 338);
			this->earthmagic->MaxLength = 2;
			this->earthmagic->Name = L"earthmagic";
			this->earthmagic->Size = System::Drawing::Size(37, 22);
			this->earthmagic->TabIndex = 66;
			// 
			// label35
			// 
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(188, 340);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(70, 15);
			this->label35->TabIndex = 65;
			this->label35->Text = L"Earth Magic";
			// 
			// airmagic
			// 
			this->airmagic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->airmagic->Location = System::Drawing::Point(295, 308);
			this->airmagic->MaxLength = 2;
			this->airmagic->Name = L"airmagic";
			this->airmagic->Size = System::Drawing::Size(37, 22);
			this->airmagic->TabIndex = 64;
			// 
			// label36
			// 
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(188, 310);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(57, 15);
			this->label36->TabIndex = 63;
			this->label36->Text = L"Air Magic";
			// 
			// icemagic
			// 
			this->icemagic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->icemagic->Location = System::Drawing::Point(295, 278);
			this->icemagic->MaxLength = 2;
			this->icemagic->Name = L"icemagic";
			this->icemagic->Size = System::Drawing::Size(37, 22);
			this->icemagic->TabIndex = 62;
			// 
			// label37
			// 
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(188, 280);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(57, 15);
			this->label37->TabIndex = 61;
			this->label37->Text = L"Ice Magic";
			// 
			// firemagic
			// 
			this->firemagic->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->firemagic->Location = System::Drawing::Point(295, 248);
			this->firemagic->MaxLength = 2;
			this->firemagic->Name = L"firemagic";
			this->firemagic->Size = System::Drawing::Size(37, 22);
			this->firemagic->TabIndex = 60;
			// 
			// label38
			// 
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(188, 250);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(62, 15);
			this->label38->TabIndex = 59;
			this->label38->Text = L"Fire Magic";
			// 
			// translocations
			// 
			this->translocations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->translocations->Location = System::Drawing::Point(295, 188);
			this->translocations->MaxLength = 2;
			this->translocations->Name = L"translocations";
			this->translocations->Size = System::Drawing::Size(37, 22);
			this->translocations->TabIndex = 58;
			// 
			// label39
			// 
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(188, 190);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(84, 15);
			this->label39->TabIndex = 57;
			this->label39->Text = L"Translocations";
			// 
			// necromancy
			// 
			this->necromancy->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->necromancy->Location = System::Drawing::Point(295, 158);
			this->necromancy->MaxLength = 2;
			this->necromancy->Name = L"necromancy";
			this->necromancy->Size = System::Drawing::Size(37, 22);
			this->necromancy->TabIndex = 56;
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(188, 160);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(75, 15);
			this->label40->TabIndex = 55;
			this->label40->Text = L"Necromancy";
			// 
			// summonings
			// 
			this->summonings->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->summonings->Location = System::Drawing::Point(295, 128);
			this->summonings->MaxLength = 2;
			this->summonings->Name = L"summonings";
			this->summonings->Size = System::Drawing::Size(37, 22);
			this->summonings->TabIndex = 54;
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(188, 130);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(75, 15);
			this->label41->TabIndex = 53;
			this->label41->Text = L"Summonings";
			// 
			// charms
			// 
			this->charms->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->charms->Location = System::Drawing::Point(295, 98);
			this->charms->MaxLength = 2;
			this->charms->Name = L"charms";
			this->charms->Size = System::Drawing::Size(37, 22);
			this->charms->TabIndex = 52;
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(188, 100);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(48, 15);
			this->label42->TabIndex = 51;
			this->label42->Text = L"Charms";
			// 
			// hexes
			// 
			this->hexes->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->hexes->Location = System::Drawing::Point(295, 68);
			this->hexes->MaxLength = 2;
			this->hexes->Name = L"hexes";
			this->hexes->Size = System::Drawing::Size(37, 22);
			this->hexes->TabIndex = 50;
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(188, 70);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(39, 15);
			this->label43->TabIndex = 49;
			this->label43->Text = L"Hexes";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(12, 10);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(50, 15);
			this->label44->TabIndex = 17;
			this->label44->Text = L"Fighting";
			// 
			// conjurations
			// 
			this->conjurations->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->conjurations->Location = System::Drawing::Point(295, 38);
			this->conjurations->MaxLength = 2;
			this->conjurations->Name = L"conjurations";
			this->conjurations->Size = System::Drawing::Size(37, 22);
			this->conjurations->TabIndex = 48;
			// 
			// fighting
			// 
			this->fighting->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->fighting->Location = System::Drawing::Point(118, 8);
			this->fighting->MaxLength = 2;
			this->fighting->Name = L"fighting";
			this->fighting->Size = System::Drawing::Size(37, 22);
			this->fighting->TabIndex = 18;
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(188, 40);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(76, 15);
			this->label45->TabIndex = 47;
			this->label45->Text = L"Conjurations";
			// 
			// spellcasting
			// 
			this->spellcasting->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->spellcasting->Location = System::Drawing::Point(295, 8);
			this->spellcasting->MaxLength = 2;
			this->spellcasting->Name = L"spellcasting";
			this->spellcasting->Size = System::Drawing::Size(37, 22);
			this->spellcasting->TabIndex = 46;
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(12, 40);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(73, 15);
			this->label46->TabIndex = 19;
			this->label46->Text = L"Short Blades";
			// 
			// label47
			// 
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(188, 10);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(69, 15);
			this->label47->TabIndex = 45;
			this->label47->Text = L"Spellcasting";
			// 
			// shortblades
			// 
			this->shortblades->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->shortblades->Location = System::Drawing::Point(118, 38);
			this->shortblades->MaxLength = 2;
			this->shortblades->Name = L"shortblades";
			this->shortblades->Size = System::Drawing::Size(37, 22);
			this->shortblades->TabIndex = 20;
			// 
			// shields
			// 
			this->shields->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->shields->Location = System::Drawing::Point(118, 488);
			this->shields->MaxLength = 2;
			this->shields->Name = L"shields";
			this->shields->Size = System::Drawing::Size(37, 22);
			this->shields->TabIndex = 44;
			// 
			// unarmedcombat
			// 
			this->unarmedcombat->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->unarmedcombat->Location = System::Drawing::Point(118, 218);
			this->unarmedcombat->MaxLength = 2;
			this->unarmedcombat->Name = L"unarmedcombat";
			this->unarmedcombat->Size = System::Drawing::Size(37, 22);
			this->unarmedcombat->TabIndex = 32;
			// 
			// label48
			// 
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(12, 490);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(44, 15);
			this->label48->TabIndex = 43;
			this->label48->Text = L"Shields";
			// 
			// label49
			// 
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(12, 220);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(101, 15);
			this->label49->TabIndex = 31;
			this->label49->Text = L"Unarmed Combat";
			// 
			// dodging
			// 
			this->dodging->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->dodging->Location = System::Drawing::Point(118, 458);
			this->dodging->MaxLength = 2;
			this->dodging->Name = L"dodging";
			this->dodging->Size = System::Drawing::Size(37, 22);
			this->dodging->TabIndex = 42;
			// 
			// label50
			// 
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(12, 70);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(70, 15);
			this->label50->TabIndex = 21;
			this->label50->Text = L"Long Blades";
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(12, 460);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(52, 15);
			this->label51->TabIndex = 41;
			this->label51->Text = L"Dodging";
			// 
			// staves
			// 
			this->staves->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->staves->Location = System::Drawing::Point(118, 188);
			this->staves->MaxLength = 2;
			this->staves->Name = L"staves";
			this->staves->Size = System::Drawing::Size(37, 22);
			this->staves->TabIndex = 30;
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(12, 190);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(40, 15);
			this->label52->TabIndex = 29;
			this->label52->Text = L"Staves";
			// 
			// slings
			// 
			this->slings->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->slings->Location = System::Drawing::Point(118, 368);
			this->slings->MaxLength = 2;
			this->slings->Name = L"slings";
			this->slings->Size = System::Drawing::Size(37, 22);
			this->slings->TabIndex = 40;
			// 
			// longblades
			// 
			this->longblades->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->longblades->Location = System::Drawing::Point(118, 68);
			this->longblades->MaxLength = 2;
			this->longblades->Name = L"longblades";
			this->longblades->Size = System::Drawing::Size(37, 22);
			this->longblades->TabIndex = 22;
			// 
			// label32
			// 
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(12, 370);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(37, 15);
			this->label32->TabIndex = 39;
			this->label32->Text = L"Slings";
			// 
			// throwing
			// 
			this->throwing->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->throwing->Location = System::Drawing::Point(118, 338);
			this->throwing->MaxLength = 2;
			this->throwing->Name = L"throwing";
			this->throwing->Size = System::Drawing::Size(37, 22);
			this->throwing->TabIndex = 38;
			// 
			// polearms
			// 
			this->polearms->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->polearms->Location = System::Drawing::Point(118, 158);
			this->polearms->MaxLength = 2;
			this->polearms->Name = L"polearms";
			this->polearms->Size = System::Drawing::Size(37, 22);
			this->polearms->TabIndex = 28;
			// 
			// label53
			// 
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(12, 340);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(58, 15);
			this->label53->TabIndex = 37;
			this->label53->Text = L"Throwing";
			// 
			// label54
			// 
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(12, 160);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(56, 15);
			this->label54->TabIndex = 27;
			this->label54->Text = L"Polearms";
			// 
			// crossbows
			// 
			this->crossbows->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->crossbows->Location = System::Drawing::Point(118, 308);
			this->crossbows->MaxLength = 2;
			this->crossbows->Name = L"crossbows";
			this->crossbows->Size = System::Drawing::Size(37, 22);
			this->crossbows->TabIndex = 36;
			// 
			// label55
			// 
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(12, 100);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(92, 15);
			this->label55->TabIndex = 23;
			this->label55->Text = L"Maces and Flails";
			// 
			// label56
			// 
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(12, 310);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(65, 15);
			this->label56->TabIndex = 35;
			this->label56->Text = L"Crossbows";
			// 
			// axes
			// 
			this->axes->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->axes->Location = System::Drawing::Point(118, 128);
			this->axes->MaxLength = 2;
			this->axes->Name = L"axes";
			this->axes->Size = System::Drawing::Size(37, 22);
			this->axes->TabIndex = 26;
			// 
			// bows
			// 
			this->bows->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->bows->Location = System::Drawing::Point(118, 278);
			this->bows->MaxLength = 2;
			this->bows->Name = L"bows";
			this->bows->Size = System::Drawing::Size(37, 22);
			this->bows->TabIndex = 34;
			// 
			// label57
			// 
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(12, 130);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(32, 15);
			this->label57->TabIndex = 25;
			this->label57->Text = L"Axes";
			// 
			// label58
			// 
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(12, 280);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(36, 15);
			this->label58->TabIndex = 33;
			this->label58->Text = L"Bows";
			// 
			// maces
			// 
			this->maces->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->maces->Location = System::Drawing::Point(118, 98);
			this->maces->MaxLength = 2;
			this->maces->Name = L"maces";
			this->maces->Size = System::Drawing::Size(37, 22);
			this->maces->TabIndex = 24;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(752, 597);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->attachedtext);
			this->Controls->Add(customstat);
			this->Controls->Add(label5);
			this->Controls->Add(this->attached);
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
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
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