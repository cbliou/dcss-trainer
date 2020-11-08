#pragma once
#include "stdafx.h"
#include "MainForm.h"
#include "process.h"
#include "memory.h"
#include "constants.h"
#include "logger.h"
#include <typeinfo>

using namespace dcsstrainer;
using namespace System;

// globals
static BYTE sdexterity, sintelligence, sstrength;


[STAThread]
void Main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm());
	Application::Exit();
}

// on close
void MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	Application::Exit();
}

//godmode
void MainForm::godmode_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->godmode->Checked)
		mem::Nop((BYTE*)moduleBase + godModeAddy, 2, process);
	else
		// sub eax, ebx
		mem::Patch((BYTE*)(moduleBase + godModeAddy), (BYTE*)"\x29\xD8", 2, process); 

}

// infinite mana
void MainForm::infinitemana_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->infinitemana->Checked)
		mem::Nop((BYTE*)moduleBase + infiniteManaAddy, 5, process);
	else
		// 29 D8 - sub eax, ebx
		// 0F 48 C2 - cmovs eax, edx
		mem::Patch((BYTE*)(moduleBase + infiniteManaAddy), (BYTE*)"\x29\xD8\x0F\x48\xC2", 5, process);


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

