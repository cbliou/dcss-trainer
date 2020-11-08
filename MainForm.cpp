#include "stdafx.h"
#include "MainForm.h"
#include "process.h"
#include "memory.h"
#include "constants.h"

using namespace dcsstrainer;


[STAThread]
void Main() {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm());
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
}
void MainForm::dexterity_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
void MainForm::strength_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
void MainForm::MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

