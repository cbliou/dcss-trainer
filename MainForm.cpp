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

// forward declarations
void attach_crawl();

// globals
static BYTE sdexterity, sintelligence, sstrength;
static bool isAttached = false;
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
		HANDLE process = 0;
		uintptr_t moduleBase = 0;
		DWORD processID = 0;
	}

}

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

void MainForm::set_stat(BYTE stat, Windows::Forms::TextBox^ param, uintptr_t addy) {

	// check if empty
	if (param->Text == "") {
		BYTE chr[1] = { 0 };
		
		mem::Read((BYTE*)(moduleBase + addy), chr, 1, process);
		param->Text = Convert::ToString(Convert::ToByte(*chr));
		logger::WriteLinetoConsole("bad" + param->Text);
		return;
	}
	// if not, check if converts
	try {
		stat = Convert::ToByte(param->Text);
		// setting global to the new value
		mem::Patch((BYTE*)(moduleBase + addy), (BYTE*)static_cast<char*>(static_cast<void*>(&stat)), 1, process);
	
	}
	catch (Exception^) {
		BYTE chr[1] = { 0 };
		mem::Read((BYTE*)(moduleBase + addy), chr, 1, process);
		param->Text = Convert::ToString(Convert::ToByte(*chr));
	}
	
}



void MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {

	// Apply stats
	set_stat(sintelligence, this->intelligence, intAddy);
	set_stat(sdexterity, this->dexterity, dexAddy);
	set_stat(sstrength, this->strength, strAddy);

	logger::WriteLinetoConsole("Updated/Refreshed stat values.");

}


void MainForm::intelligence_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	/*
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
	*/

}

void MainForm::dexterity_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	/*
	try {
		sdexterity = System::Convert::ToByte(this->dexterity->Text);
		if (sdexterity < 0 || sdexterity > 127)
			throw;
		else
			mem::Patch((BYTE*)(moduleBase + dexAddy), (BYTE*) static_cast<char*>(static_cast<void*>(&sdexterity)), 1, process);
	}
	catch (Exception^) {
		logger::WriteLinetoConsole("Please enter an integer from 0 to 127.");
	}*/
}
void MainForm::strength_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	/*
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
	*/
}
void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

