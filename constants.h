#pragma once
#include <unordered_map>

// in a function call
uintptr_t godModeAddy		= 0x4A7FAE;
uintptr_t infiniteManaAddy	= 0x4A83B9;
uintptr_t noHungerAddy		= 0x198008;

// player 
uintptr_t strAddy			= 0xE7BD73;
uintptr_t intAddy			= 0xE7BD74;
uintptr_t dexAddy			= 0xE7BD75;
uintptr_t hungerAddy		= 0xE7BD78;

// skills
uintptr_t fightingAddy			= 0xE7E62C;
uintptr_t sBladeAddy			= fightingAddy + 0x04;
uintptr_t lBladeAddy			= fightingAddy + 0x08;
uintptr_t axeAddy				= fightingAddy + 0x0C; // not sure why these two are reversed lol
uintptr_t maceAddy				= fightingAddy + 0x10;
uintptr_t polearmAddy			= fightingAddy + 0x14;
uintptr_t stavesAddy			= fightingAddy + 0x18;
uintptr_t unarmedAddy			= fightingAddy + 0x44; // this is an interesting hint into figuring out inventory pointers

uintptr_t slingsAddy			= fightingAddy + 0x1C;
uintptr_t bowsAddy				= fightingAddy + 0x20;
uintptr_t xbowAddy				= fightingAddy + 0x24;
uintptr_t throwingAddy			= fightingAddy + 0x28;

//not sure about offset 0x2C, 0x38, 0x40

uintptr_t dodgingAddy			= fightingAddy + 0x30;
uintptr_t shieldsAddy			= fightingAddy + 0x3C;

uintptr_t invocationsAddy		= fightingAddy + 0x7C;
uintptr_t evocationsAddy		= fightingAddy + 0x80;
uintptr_t stealthAddy			= fightingAddy + 0x34;

uintptr_t spellcastingAddy		= fightingAddy + 0x48;
uintptr_t conjurationAddy		= fightingAddy + 0x4C;
uintptr_t hexesAddy				= fightingAddy + 0x50;
uintptr_t charmsAddy			= fightingAddy + 0x54;
uintptr_t summoningAddy			= fightingAddy + 0x58;
uintptr_t necromancyAddy		= fightingAddy + 0x5C;
uintptr_t translocationsAddy	= fightingAddy + 0x60;
uintptr_t transmmutationAddy	= fightingAddy + 0x64;
uintptr_t fireMagicAddy			= fightingAddy + 0x68;
uintptr_t iceMagicAddy			= fightingAddy + 0x6C;
uintptr_t airMagicAddy			= fightingAddy + 0x70;
uintptr_t earthMagicAddy		= fightingAddy + 0x74;
uintptr_t poisonMagicAddy		= fightingAddy + 0x78;


// the displayed level follows a linear relationship between exp for level n and n + 1
std::unordered_map<int, int> level_to_exp = {
	{0, 0}, {1, 50}, {2, 150}, {3, 300}, {4, 500}, {5, 750},			// 0-5
	{6, 1050}, {7, 1400}, {8, 1800}, {9, 2250}, {10, 2800},				// 6-10
	{11, 3450}, {12, 4200}, {13, 5050}, {14, 6000}, {15, 7050},			// 11-15
	{16, 8200}, {17, 9450}, {18, 10800}, {19, 12300}, {20, 13950},		// 16-20
	{21, 15750}, {22, 17700}, {23, 19800}, {24, 22050}, {25, 24450},	// 21-25
	{26, 27000}, {27, 29750}
};