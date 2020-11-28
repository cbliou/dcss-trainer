#pragma once
#include "stdafx.h"
#include "MainForm.h"
#include "process.h"
#include "memory.h"
#include "constants.h"
#include "logger.h"

using namespace dcsstrainer;
using namespace System;

// forward declarations
void attach_crawl();

// globals
static BYTE sdexterity, sintelligence, sstrength;
static bool isAttached = false, autoIdentify = false;
DWORD processID = 0, dcssExit = 0;
HANDLE process = 0;
uintptr_t moduleBase = 0;
wchar_t crawlName[16] = L"crawl-tiles.exe";

[STAThread]
void Main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm());
	Application::Exit();

}

void attach_crawl() {

	// attach to crawl
	if (!isAttached) {

		processID = GetProcessID(crawlName);

		// if successful
		if (processID) {

			// get handle
			process = OpenProcess(PROCESS_ALL_ACCESS, NULL, processID);

			// get module base address
			moduleBase = ModuleBaseAddress(processID, crawlName);

			isAttached = true;
		}

	}

	// detach crawl
	if (!GetExitCodeProcess(process, &dcssExit) || !(dcssExit > 0)) {
		isAttached = false;
		process = 0;
		moduleBase = 0;
		processID = 0;
	}

}

// every 200ms, do this
void MainForm::GUITimer_Tick(System::Object^ sender, System::EventArgs^ e) {

	attach_crawl();

	if (isAttached) {
		attached->Text = "Attached to Crawl!";
		attached->ForeColor = System::Drawing::Color::DarkGreen;
	}
	else {
		attached->Text = "Game not running!";
		attached->ForeColor = System::Drawing::Color::DarkRed;
	}

	if (autoIdentify) {
		mem::PatchItemFlag((uintptr_t*) moduleBase, &itemFlags::identMask, process);
	}
		
		 
}

// start setting flags
void MainForm::idinven_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->idinven->Checked) {
		autoIdentify = true;
		logger::WriteLinetoConsole("Activated automatic inventory item identification.");
	}
		
	else {
		autoIdentify = false;
		logger::WriteLinetoConsole("Deactivated automatic inventory item identification.");
	}
}


// on close
void MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

	Application::Exit();
}

//godmode
void MainForm::godmode_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->godmode->Checked) {
		mem::Nop((uintptr_t*) (moduleBase + godModeAddy), 2, process);
		logger::WriteLinetoConsole("Activated godmode.");
	}
		
	else {
		// sub eax, ebx
		mem::Patch((uintptr_t*) (moduleBase + godModeAddy), (uintptr_t*)"\x29\xD8", 2, process);
		logger::WriteLinetoConsole("Deactivated godmode.");
	}
		

}

// infinite mana
void MainForm::infinitemana_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->infinitemana->Checked) {
		mem::Nop((uintptr_t*) (moduleBase + infiniteManaAddy), 5, process);
		logger::WriteLinetoConsole("Activated infinite mana.");
	}
		
	else {
		// 29 D8 - sub eax, ebx
		// 0F 48 C2 - cmovs eax, edx
		mem::Patch((uintptr_t*) (moduleBase + infiniteManaAddy), (uintptr_t*)"\x29\xD8\x0F\x48\xC2", 5, process);
		logger::WriteLinetoConsole("Deactivated infinite mana.");
	}


}

// no hunger
void MainForm::nohunger_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	// 29 D8 - sub eax, ebx
	// 0F48 C2 - cmovs eax, edx 
	// this is moving the subtracted value only if the hunger value was subtracted (cmovs is move if sign, 48 is the negative flavor)
	if (this->nohunger->Checked) {
		mem::Nop((uintptr_t*) (moduleBase + noHungerAddy), 5, process);
		logger::WriteLinetoConsole("Activated no hunger.");
	}
		
	else {
		mem::Patch((uintptr_t*) (moduleBase + noHungerAddy), (uintptr_t*)"\x29\xD8\x0F\x48\xC2", 5, process);
		logger::WriteLinetoConsole("Deactivated no hunger.");
	}
		

}



void MainForm::set_stat(BYTE stat, Windows::Forms::TextBox^ param, uintptr_t addy) {

	// check if empty
	if (param->Text == "") {
		uintptr_t chr[1] = { 0 };
		
		mem::Read((uintptr_t*) (moduleBase + addy), chr, 1, process);
		param->Text = Convert::ToString(Convert::ToByte(*chr));
		return;
	}
	// if not, check if converts
	try {
		stat = Convert::ToByte(param->Text);
		// setting global to the new value
		mem::Patch((uintptr_t*) (moduleBase + addy), (uintptr_t*)static_cast<char*>(static_cast<void*>(&stat)), 1, process);
	
	}
	catch (Exception^) {
		uintptr_t chr[1] = { 0 };
		mem::Read((uintptr_t*) (moduleBase + addy), chr, 1, process);
		param->Text = Convert::ToString(Convert::ToByte(*chr));
	}
	
}

void MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {

	// Apply stats
	set_stat(sintelligence, this->intelligence, intAddy);
	set_stat(sdexterity, this->dexterity, dexAddy);
	set_stat(sstrength, this->strength, strAddy);

	logger::WriteLinetoConsole("Refreshed/Updated stat values.");

}


void MainForm::intelligence_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
void MainForm::dexterity_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
void MainForm::strength_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {}

/* testing section

this is the actual fighting addy
crawl - tiles.exe + 522752 - 8B 04 85 2CE60E01 - mov eax, [eax * 4 + crawl - tiles.exe + E7E62C]
crawl - tiles.exe + 522759 - 89 44 24 08 - mov[esp + 08], eax
crawl - tiles.exe + 52275D - 8B 45 08 - mov eax, [ebp + 08]
this is the fighting addy used in the attack calculation?
crawl - tiles.exe + 522760 - 0FB6 80 74E40E01 - movzx eax, byte ptr[eax + crawl - tiles.exe + E7E474]*/



