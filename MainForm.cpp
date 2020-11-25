#pragma once
#include "stdafx.h"
#include "MainForm.h"
#include "process.h"
#include "memory.h"
#include "constants.h"
#include "logger.h"
#include "util.h"

using namespace dcsstrainer;
using namespace System;

void attach_process();
inline const char* const BoolToString(bool b);

// globals

static BYTE sdexterity, sintelligence, sstrength;
static bool isAttached = false;
DWORD process_id = 0, dcss_exit = 0;
HANDLE process = 0;
uintptr_t moduleBase = 0;
wchar_t name[16] = L"crawl-tiles.exe";


[STAThread]
void Main() {

	

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//this->isattached->Text = gcnew System::String(BoolToString(dcsstrainer::attached));
	Application::Run(gcnew MainForm());
	Application::Exit();

}

void MainForm::GUITimer_Tick(System::Object^ sender, System::EventArgs^ e) {

	// attach to crawl
	if (!isAttached) {

		process_id = GetProcessID(name);

		// if successful
		if (process_id) {

			//logger::WriteLinetoConsole("Found crawl-tiles.exe. Locating base address...");

			// get handle
			process = OpenProcess(PROCESS_ALL_ACCESS, NULL, process_id);

			// get module base address
			moduleBase = ModuleBaseAddress(process_id, name);

			isAttached = true;
			//logger::WriteLinetoConsole("Located address. Enjoy the trainer.");
		}

	}

	if (!GetExitCodeProcess(process, &dcss_exit) || !(dcss_exit > 0)) {
		isAttached = false;
		//logger::WriteLinetoConsole("Crawl has been closed.");
	}

	// update GUI
	attached->Text = "Attached: " + gcnew System::String(BoolToString(isAttached));

}

// on close
void MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	Application::Exit();
}

//godmode
void MainForm::godmode_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->godmode->Checked)
		mem::Nop((BYTE*)(moduleBase + godModeAddy), 2, process);
	else
		// sub eax, ebx
		mem::Patch((BYTE*)(moduleBase + godModeAddy), (BYTE*)"\x29\xD8", 2, process); 

}

// infinite mana
void MainForm::infinitemana_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->infinitemana->Checked)
		mem::Nop((BYTE*)(moduleBase + infiniteManaAddy), 5, process);
	else
		// 29 D8 - sub eax, ebx
		// 0F 48 C2 - cmovs eax, edx
		mem::Patch((BYTE*)(moduleBase + infiniteManaAddy), (BYTE*)"\x29\xD8\x0F\x48\xC2", 5, process);


}

// no hunger
void MainForm::nohunger_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	// 29 D8 - sub eax, ebx
	// 0F48 C2 - cmovs eax, edx 
	// this is moving the subtracted value only if the hunger value was subtracted (cmovs is move if sign, 48 is the negative flavor)
	if (this->nohunger->Checked)
		mem::Nop((BYTE*)(moduleBase + noHungerAddy), 5, process);
	else
		mem::Patch((BYTE*)(moduleBase + noHungerAddy), (BYTE*)"\x29\xD8\x0F\x48\xC2", 5, process);


}

void MainForm::intelligence_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	try {
		sintelligence = System::Convert::ToByte(this->intelligence->Text);
		if (sintelligence < 0 || sintelligence > 127)
			throw;
		else
			mem::Patch((BYTE*)(moduleBase + intAddy), (BYTE*)static_cast<char*>(static_cast<void*>(&sintelligence)), 1, process);
	}
	catch (Exception^) {
		logger::WriteLinetoConsole("Please enter an integer from 0 to 127.");
	}

}
void MainForm::dexterity_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	try {
		sdexterity = System::Convert::ToByte(this->dexterity->Text);
		if (sdexterity < 0 || sdexterity > 127)
			throw;
		else
			mem::Patch((BYTE*)(moduleBase + dexAddy), (BYTE*) static_cast<char*>(static_cast<void*>(&sdexterity)), 1, process);
	}
	catch (Exception^) {
		logger::WriteLinetoConsole("Please enter an integer from 0 to 127.");
	}
}
void MainForm::strength_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	try {
		sstrength = System::Convert::ToByte(this->strength->Text);
		if (sstrength < 0 || sstrength > 127)
			throw;
		else
			mem::Patch((BYTE*)(moduleBase + strAddy), (BYTE*) static_cast<char*>(static_cast<void*>(&sstrength)), 1, process);
	}
	catch (Exception^) {
		logger::WriteLinetoConsole("Please enter an integer from 0 to 127.");
	}
}
void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

