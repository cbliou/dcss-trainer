#pragma once
#include <math.h>
#include "stdafx.h"
#include "MainForm.h"
#include "process.h"
#include "memory.h"
#include "addresses.h"
#include "logger.h"
#include "util.h"
#include "hooks.h"

using namespace dcsstrainer;
using namespace System;

// forward declarations
//void attach_crawl();
void set_stat(Windows::Forms::TextBox^ text, uintptr_t addy);
void set_skill(Windows::Forms::TextBox^ param, uintptr_t addy);

// globals
static bool isAttached = false, autoIdentify = false, oneHP = false, freeze = false, sleep = false;
static bool maxItems = false;
//uintptr_t moduleBase = NULL;

[STAThread]
DWORD APIENTRY Main() {
	moduleBase = (uintptr_t)GetModuleHandle(L"crawl_tiles.exe");
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm());
	Application::Exit();
	return 0;

}

// needed to tell complier this is unmanaged code
#pragma unmanaged
BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpvReserved) {

	//
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&Main, NULL, 0, NULL));
		break;
	case DLL_PROCESS_DETACH:
		FreeLibraryAndExitThread(hModule, 0);
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	default:
		break;
	}
	return TRUE;
}

#pragma managed
// every 200ms, do this
void MainForm::GUITimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	// figure out how to just do this once lmfao
	moduleBase = (uintptr_t)GetModuleHandle(NULL);
	/*
	attach_crawl();

	if (isAttached) {
		attached->Text = "Attached to Crawl!";
		attached->ForeColor = System::Drawing::Color::DarkGreen;
	}
	else {
		attached->Text = "Game not running!";
		attached->ForeColor = System::Drawing::Color::DarkRed;
	}
	*/
	if (autoIdentify) {
		mem::PatchItemFlag((uintptr_t*)moduleBase, &itemFlags::identMask);
	}
	

	if (oneHP) {
		uintptr_t hp = 1;
		mem::EntityPatch((uintptr_t*)moduleBase, &hp, 4, envAddrs::hpOffset);
	}

	if (freeze) {
		// uintptr_t speed = 0;
		// this works but to undo it, you need to keep pointers to alive enemies
		// mem::EntityPatch((uintptr_t*)moduleBase, &speed, 4, envAddrs::speedOffset, process);
		mem::EntityPatch((uintptr_t*)moduleBase, &statusMasks::petrify, 4, envAddrs::statusOffset);
	}
	else {
		mem::EntityPatch((uintptr_t*)moduleBase, &statusMasks::nomask, 4, envAddrs::statusOffset);
	}

	if (sleep) {
		uintptr_t mask = 0x02;
		mem::EntityPatch((uintptr_t*)moduleBase, &mask, 1, envAddrs::sleepOffset);
	}
	else {
		uintptr_t mask = 0x00;
		mem::EntityPatch((uintptr_t*)moduleBase, &mask, 1, envAddrs::sleepOffset);
	}

}

//change this to a button
void MainForm::maxitems_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->maxitems->Checked) {
		uintptr_t arr[1] = {0xFF};
		mem::InventoryPatch((uintptr_t*)moduleBase, arr, 1, inventoryAddrs::numItemsOffset);
		logger::WriteLinetoConsole("Setting items to max amount.");
	}
	else {
		logger::WriteLinetoConsole("not sure what to do yet.");
	}
}

// permasleep
void MainForm::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->permasleep->Checked) {
		sleep = true;
		logger::WriteLinetoConsole("Putting monsters to sleep.");
	}
	else {
		sleep = false;
		logger::WriteLinetoConsole("Waking monsters up.");
	}
}

void MainForm::instakill_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->instakill->Checked) {
		instakillRetAddy = moduleBase + instakillAddy + 7;
		hooks::Hook(moduleBase, instakillAddy, hooks::instakill, 7);
		logger::WriteLinetoConsole("Enabled instakill.");
	}
	else {
		//crawl - tiles.exe + 43FE3B - 29 F0 - sub eax, esi
		//crawl - tiles.exe + 43FE3D - 39 D0 - cmp eax, edx
		//crawl - tiles.exe + 43FE3F - 89 43 54 - mov[ebx + 54], eax

		mem::Patch((uintptr_t*)(moduleBase + instakillAddy), (uintptr_t*)"\x29\xF0\x39\xD0\x89\x43\x54", 7);
		logger::WriteLinetoConsole("Disabled instakill.");
	}
}

// hook the x and y moves, disable them
void MainForm::disablemovement_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->disablemovement->Checked) {
		// we somehow need to update the ret addy relative to module. why not do it here?
		disablexRetAddy = moduleBase + disablexAddy + 8;
		disableyRetAddy = moduleBase + disableyAddy + 6;
		// overwriting 8 bytes
		hooks::Hook(moduleBase, disablexAddy, hooks::disableX, 8);
		hooks::Hook(moduleBase, disableyAddy, hooks::disableY, 6);
		logger::WriteLinetoConsole("Disabled enemy movement. They can still attack you tho!");
	}
	else {
		//crawl - tiles.exe + A53BB9 - 03 10 - add edx, [eax]
		//crawl - tiles.exe + A53BBB - 8B 85 60FFFFFF - mov eax, [ebp - 000000A0]
		mem::Patch((uintptr_t*) (moduleBase + disablexAddy), (uintptr_t*)"\x03\x10\x8B\x85\x60\xFF\xFF\xFF", 8);
		//crawl - tiles.exe + A53BC4 - 03 43 04 - add eax, [ebx + 04]
		//crawl - tiles.exe + A53BC7 - 8D 4A FF - lea ecx, [edx - 01]
		mem::Patch((uintptr_t*) (moduleBase + disableyAddy), (uintptr_t*)"\x03\x43\x04\x8D\x4A\xFF", 6);
		logger::WriteLinetoConsole("Enabled enemy movement.");

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

// set to 1 hp
void MainForm::onehp_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->onehp->Checked) {
		oneHP = true;
		logger::WriteLinetoConsole("Activated One HP monsters.");
	}
	else {
		oneHP = false;
		logger::WriteLinetoConsole("Deactivated One HP monsters.");
	}
}

// monster freeze
// resets when you change map
// should keep track of old speeds 
void MainForm::mfreeze_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->mfreeze->Checked) {
		freeze = true;
		logger::WriteLinetoConsole("Activated monster freeze.");
	}
	else {
		freeze = false;
		logger::WriteLinetoConsole("Deactivated monster freeze.");
	}
}

//godmode
void MainForm::godmode_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->godmode->Checked) {
		mem::Nop((uintptr_t*) (moduleBase + godModeAddy), 2);//, process);
		logger::WriteLinetoConsole("Activated godmode.");
	}
		
	else {
		// sub eax, ebx
		mem::Patch((uintptr_t*) (moduleBase + godModeAddy), (uintptr_t*)"\x29\xD8", 2);
		logger::WriteLinetoConsole("Deactivated godmode.");
	}
		

}

// infinite mana
void MainForm::infinitemana_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->infinitemana->Checked) {
		mem::Nop((uintptr_t*) (moduleBase + infiniteManaAddy), 5);//, process);
		logger::WriteLinetoConsole("Activated infinite mana.");
	}
		
	else {
		// 29 D8 - sub eax, ebx
		// 0F 48 C2 - cmovs eax, edx
		mem::Patch((uintptr_t*) (moduleBase + infiniteManaAddy), (uintptr_t*)"\x29\xD8\x0F\x48\xC2", 5);
		logger::WriteLinetoConsole("Deactivated infinite mana.");
	}


}

// no hunger
void MainForm::nohunger_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	// 29 D8 - sub eax, ebx
	// 0F48 C2 - cmovs eax, edx 
	// this is moving the subtracted value only if the hunger value was subtracted (cmovs is move if sign, 48 is the negative flavor)
	if (this->nohunger->Checked) {
		mem::Nop((uintptr_t*) (moduleBase + noHungerAddy), 5);//, process);
		logger::WriteLinetoConsole("Activated no hunger.");
	}
		
	else {
		mem::Patch((uintptr_t*) (moduleBase + noHungerAddy), (uintptr_t*)"\x29\xD8\x0F\x48\xC2", 5);
		logger::WriteLinetoConsole("Deactivated no hunger.");
	}
		
}

void set_stat(Windows::Forms::TextBox^ param, uintptr_t addy) {

	// check if empty
	if (param->Text == "") {
		uintptr_t chr[1] = { 0 };
		
		mem::Read((uintptr_t*)(moduleBase + addy), chr, 1);
		param->Text = Convert::ToString(Convert::ToByte(*chr));
		return;
	}
	// if not, check if converts
	try {
		BYTE stat = Convert::ToByte(param->Text);
		// setting global to the new value
		mem::Patch((uintptr_t*) (moduleBase + addy), (uintptr_t*) &stat, 1);
	
	}
	catch (Exception^) {
		uintptr_t chr[1] = { 0 };
		mem::Read((uintptr_t*) (moduleBase + addy), chr, 1);
		param->Text = Convert::ToString(Convert::ToByte(*chr));
	}
	
}

// called when skill is empty or an exception occured.
// sets value of skill to one found in memory.
void set_empty_skill(Windows::Forms::TextBox^ param, uintptr_t addy) {

	float closestLevel = 27;
	uintptr_t chr[2] = { 0, 0 };
	short read_exp;

	mem::Read((uintptr_t*)(moduleBase + addy), chr, 2);
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
	short normalizer = leveltoEXP.at(closestLevel + 1) - leveltoEXP.at(closestLevel);
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
			mem::Patch((uintptr_t*)(moduleBase + addy), (uintptr_t*) &actualEXP, 2);//, process);
		}
		else {
			mem::Patch((uintptr_t*)(moduleBase + addy), (uintptr_t*) &leveltoEXP.at(27), 2);//, process);
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

// on close
void MainForm::MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

	Application::Exit();
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



