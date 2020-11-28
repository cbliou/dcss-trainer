#pragma once
#include <unordered_map>

// in a function call
static const uintptr_t godModeAddy					= 0x4A7FAE;
static const uintptr_t infiniteManaAddy				= 0x4A83B9;
static const uintptr_t noHungerAddy					= 0x198008;

// player 
static const uintptr_t strAddy						= 0xE7BD73;
static const uintptr_t intAddy						= 0xE7BD74;
static const uintptr_t dexAddy						= 0xE7BD75;
static const uintptr_t hungerAddy					= 0xE7BD78;

// skills
static const uintptr_t fightingAddy					= 0xE7E62C;
static const uintptr_t sBladeAddy					= fightingAddy + 0x04;
static const uintptr_t lBladeAddy					= fightingAddy + 0x08;
static const uintptr_t axeAddy						= fightingAddy + 0x0C; // not sure why these two are reversed lol
static const uintptr_t maceAddy						= fightingAddy + 0x10;
static const uintptr_t polearmAddy					= fightingAddy + 0x14;
static const uintptr_t stavesAddy					= fightingAddy + 0x18;
static const uintptr_t unarmedAddy					= fightingAddy + 0x44;

static const uintptr_t slingsAddy					= fightingAddy + 0x1C;
static const uintptr_t bowsAddy						= fightingAddy + 0x20;
static const uintptr_t xbowAddy						= fightingAddy + 0x24;
static const uintptr_t throwingAddy					= fightingAddy + 0x28;

//not sure about offset 0x38, 0x40

static const uintptr_t armourAddy					= fightingAddy + 0x2C;
static const uintptr_t dodgingAddy					= fightingAddy + 0x30;
static const uintptr_t shieldsAddy					= fightingAddy + 0x3C;

static const uintptr_t invocationsAddy				= fightingAddy + 0x7C;
static const uintptr_t evocationsAddy				= fightingAddy + 0x80;
static const uintptr_t stealthAddy					= fightingAddy + 0x34;

static const uintptr_t spellcastingAddy				= fightingAddy + 0x48;
static const uintptr_t conjurationAddy				= fightingAddy + 0x4C;
static const uintptr_t hexesAddy					= fightingAddy + 0x50;
static const uintptr_t charmsAddy					= fightingAddy + 0x54;
static const uintptr_t summoningAddy				= fightingAddy + 0x58;
static const uintptr_t necromancyAddy				= fightingAddy + 0x5C;
static const uintptr_t translocationsAddy			= fightingAddy + 0x60;
static const uintptr_t transmmutationAddy			= fightingAddy + 0x64;
static const uintptr_t fireMagicAddy				= fightingAddy + 0x68;
static const uintptr_t iceMagicAddy					= fightingAddy + 0x6C;
static const uintptr_t airMagicAddy					= fightingAddy + 0x70;
static const uintptr_t earthMagicAddy				= fightingAddy + 0x74;
static const uintptr_t poisonMagicAddy				= fightingAddy + 0x78;

// inventory
// items are either in the inventory or in the environment

struct itemFlags {
	static const uintptr_t identMask						= 0x0F;
	static const uintptr_t curse							= 0x01;
};

struct inventoryAddrs {
	static const uintptr_t firstInventorySlot		= 0xE7CC90;
	// how many bytes each item_def takes up
	static const uintptr_t inventoryOffset			= 0x5C;
	static const uintptr_t itemTypeOffset			= 0x40;
	static const uintptr_t subItemTypeOffset		= 0x41;
	static const uintptr_t numItemsOffset			= 0x4E;
	static const uintptr_t idStatusFlagOffset		= 0x50;
	static const uintptr_t curseStatusFlagOffset	= 0x51;
};

struct envAddrs {
	static const uintptr_t firstEnvItemSlot			= 0xE81204;
	static const uintptr_t inventoryOffset			= 0x5C;
	static const uintptr_t itemTypeOffset			= 0x40;
	static const uintptr_t subItemTypeOffset		= 0x41;
	static const uintptr_t numItemsOffset			= 0x4E;
	static const uintptr_t idStatusFlagOffset		= 0x50;
	static const uintptr_t curseStatusFlagOffset	= 0x51;
};


// the displayed level follows a linear relationship between exp for level n and n + 1
static std::unordered_map<int, int> leveltoEXP = {
	{0, 0}, {1, 50}, {2, 150}, {3, 300}, {4, 500}, {5, 750},			// 0-5
	{6, 1050}, {7, 1400}, {8, 1800}, {9, 2250}, {10, 2800},				// 6-10
	{11, 3450}, {12, 4200}, {13, 5050}, {14, 6000}, {15, 7050},			// 11-15
	{16, 8200}, {17, 9450}, {18, 10800}, {19, 12300}, {20, 13950},		// 16-20
	{21, 15750}, {22, 17700}, {23, 19800}, {24, 22050}, {25, 24450},	// 21-25
	{26, 27000}, {27, 29750}
};

static std::unordered_map<int, int> exptoLevel = {
	{0, 0}, {50, 1}, {150, 2}, {300, 3}, {500, 4}, {750, 5},			// 0-5
	{1050, 6}, {1400, 7}, {1800, 8}, {2250, 9}, {2800, 10},				// 6-10
	{3450, 11}, {4200, 12}, {5050, 13}, {6000, 14}, {7050, 15},			// 11-15
	{8200, 16}, {9450, 17}, {10800, 18}, {12300, 19}, {13950, 20},		// 16-20
	{15750, 21}, {17700, 22}, {19800, 23}, {22050, 24}, {24450, 25},	// 21-25
	{27000, 26}, {29750, 27}
};

/*
notes:

- casts come before addition
- item ID is 2 byte value, 100 means empty
 - first byte is something
 - second represent something else

- for environment items, flags comes before (x, y)
- for inventory, flags also comes before (x, y) but is -1, -1

items
- kept track of either in the env or inventory
- there is one item in the player struct but it's also the first item in the inventory ???? wdf
- seems like items are generated once you enter. possible autoid hack
- if you have n items in your inventory, there are n+1 contiguous blocks of memory ready to recieve the inventory items
- there is no deallocation if you drop items
- thus you must look for reliable inventory slot id, which is always +1 from the last if the spot has been allocated before
   - technically you don't need to, the env items seem to be laid out right after the inventory ones
   - ID all env ones so items will stack properly

primary id's
potion: 7
scrolls: 5

05 10 is acquirement
0A 00 is orb of zot lmfao

*/