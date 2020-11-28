#pragma once
#include <math.h>
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
void set_stat(Windows::Forms::TextBox^ text, uintptr_t addy);
void set_skill(Windows::Forms::TextBox^ param, uintptr_t addy);

// globals
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



void set_stat(Windows::Forms::TextBox^ param, uintptr_t addy) {

	// check if empty
	if (param->Text == "") {
		uintptr_t chr[1] = { 0 };
		
		mem::Read((uintptr_t*) (moduleBase + addy), chr, 1, process);
		param->Text = Convert::ToString(Convert::ToByte(*chr));
		return;
	}
	// if not, check if converts
	try {
		BYTE stat = Convert::ToByte(param->Text);
		// setting global to the new value
		mem::Patch((uintptr_t*) (moduleBase + addy), (uintptr_t*) &stat, 1, process);
	
	}
	catch (Exception^) {
		uintptr_t chr[1] = { 0 };
		mem::Read((uintptr_t*) (moduleBase + addy), chr, 1, process);
		param->Text = Convert::ToString(Convert::ToByte(*chr));
	}
	
}

// called when skill is empty or an exception occured.
// sets value of skill to one found in memory.
void set_empty_skill(Windows::Forms::TextBox^ param, uintptr_t addy) {

	float closestLevel = 27;
	uintptr_t chr[2] = { 0, 0 };
	short read_exp;

	mem::Read((uintptr_t*)(moduleBase + addy), chr, 2, process);
	read_exp = Convert::ToInt16(*chr);

	// get level rounded up
	for (const auto& exp : exptoLevel) {
		short expdiff = exp.first - read_exp;
		if (expdiff > 0 && exp.second < closestLevel) {
			closestLevel = exp.second;
		}
	}

	// round down
	closestLevel = closestLevel - 1;

	// find difference
	// logger::WriteLinetoConsole(gcnew String(Convert::ToString(leveltoEXP.at(closestLevel))));
	short normalizer = leveltoEXP.at(closestLevel + 1) - leveltoEXP.at(closestLevel);
	// logger::WriteLinetoConsole(gcnew String(Convert::ToString((float) (read_exp - leveltoEXP.at((int)closestLevel)) / normalizer)));
	closestLevel += round((float)(read_exp - leveltoEXP.at(closestLevel)) / normalizer, 1);

	param->Text = Convert::ToString(closestLevel);

}

// set skill values
void set_skill(Windows::Forms::TextBox^ param, uintptr_t addy) {
	// user will enter a float from 0.0 to 27.0
	// convert to exp, then patch a short
	// todo: deal with class skill modifiers

	// if empty
	if (param->Text == "") {

		set_empty_skill(param, addy);
		return;
	}

	// else apply user input
	try {
		float rawLevel = (float)Convert::ToDecimal(param->Text);
		short roundedLevel = trunc(rawLevel);
		if (roundedLevel < 27) {
			// if negative, just ignore the user
			if (roundedLevel < 0) {
				throw;
			}
			// add remaining exp
			short actualEXP = leveltoEXP.at((int)roundedLevel) + (rawLevel - roundedLevel) * (leveltoEXP.at(roundedLevel + 1) - leveltoEXP.at(roundedLevel));
			mem::Patch((uintptr_t*)(moduleBase + addy), (uintptr_t*) &actualEXP, 2, process);
		}
		else {
			mem::Patch((uintptr_t*)(moduleBase + addy), (uintptr_t*) &leveltoEXP.at(27), 2, process);
		}


		

	}
	catch (Exception^) {
		set_empty_skill(param, addy);
	}



}



void MainForm::button1_Click(System::Object^ sender, System::EventArgs^ e) {

	// Apply stats
	set_stat(this->intelligence, intAddy);
	set_stat(this->dexterity, dexAddy);
	set_stat(this->strength, strAddy);
	
	// apply skills
	set_skill(this->fighting, fightingAddy);
	set_skill(this->shortblades, sBladeAddy);
	set_skill(this->longblades, lBladeAddy);
	set_skill(this->maces, maceAddy);
	set_skill(this->axes, axeAddy);
	set_skill(this->polearms, polearmAddy);
	set_skill(this->staves, stavesAddy);
	set_skill(this->unarmedcombat, unarmedAddy);
	set_skill(this->bows, bowsAddy);
	set_skill(this->crossbows, xbowAddy);
	set_skill(this->throwing, throwingAddy);
	set_skill(this->slings, slingsAddy);
	set_skill(this->armour, armourAddy);
	set_skill(this->dodging, dodgingAddy);
	set_skill(this->shields, shieldsAddy);
	set_skill(this->spellcasting, spellcastingAddy);
	set_skill(this->conjurations, conjurationAddy);
	set_skill(this->hexes, hexesAddy);
	set_skill(this->charms, charmsAddy);
	set_skill(this->summonings, summoningAddy);
	set_skill(this->necromancy, necromancyAddy);
	set_skill(this->translocations, translocationsAddy);
	set_skill(this->transmutations, transmmutationAddy);
	set_skill(this->firemagic, fireMagicAddy);
	set_skill(this->icemagic, iceMagicAddy);
	set_skill(this->airmagic, airMagicAddy);
	set_skill(this->earthmagic, earthMagicAddy);
	set_skill(this->poisonmagic, poisonMagicAddy);
	set_skill(this->invocations, invocationsAddy);
	set_skill(this->evocations, evocationsAddy);
	set_skill(this->stealth, stealthAddy);

	logger::WriteLinetoConsole("Refreshed/Updated stat and skill values.");

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



