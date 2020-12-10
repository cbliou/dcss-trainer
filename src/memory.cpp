#pragma once
#include "stdafx.h"
#include "memory.h"
#include "addresses.h"
#include "logger.h"

using namespace System;

void mem::PatchItemFlag(uintptr_t* start, const uintptr_t* flag) {

	DWORD oldprotect;
	// change the read/write permissions of the inventory location
	VirtualProtect(start + inventoryAddrs::firstInventorySlot, 52 * inventoryAddrs::inventoryOffset, PAGE_EXECUTE_READWRITE, &oldprotect);
	// for each inventory slot, set the item_flag to flag
	for (unsigned int i = 0; i <= 52; ++i) {
		// flags are 4 bytes, pointer arithmetic
		memcpy(	
			start + (inventoryAddrs::firstInventorySlot + inventoryAddrs::idStatusFlagOffset + i * inventoryAddrs::inventoryOffset) / sizeof(inventoryAddrs::idStatusFlagOffset),
			flag, 1);
	}
	VirtualProtect(start + inventoryAddrs::firstInventorySlot, 52 * inventoryAddrs::inventoryOffset, oldprotect, &oldprotect);

	// do the same for all environment items
	VirtualProtect(start + envAddrs::firstEnvItemSlot, 2000 * envAddrs::inventoryOffset, PAGE_EXECUTE_READWRITE, &oldprotect);
	for (unsigned int i = 0; i < 2000; ++i) {
		memcpy(
			start + (envAddrs::firstEnvItemSlot + envAddrs::idStatusFlagOffset + i * envAddrs::inventoryOffset) / sizeof(envAddrs::idStatusFlagOffset),
			flag, 1);
	}
	VirtualProtect(start + envAddrs::firstEnvItemSlot, 2000 * envAddrs::inventoryOffset, oldprotect, &oldprotect);
	
}

void mem::InventoryPatch(uintptr_t* start, uintptr_t* bytes, int numBytes, uintptr_t offset) {

	DWORD oldprotect;
	// change the read/write permissions of the inventory location
	VirtualProtect(start + inventoryAddrs::firstInventorySlot, 52 * inventoryAddrs::inventoryOffset, PAGE_EXECUTE_READWRITE, &oldprotect);
	for (unsigned int i = 0; i <= 52; ++i) {
		
		// check if item ID is jewellery, armor, weapon, or the chunks of flesh (flesh was causing crashes)
		BYTE* itemID = (BYTE*)((uintptr_t)start + inventoryAddrs::firstInventorySlot + inventoryAddrs::itemTypeOffset + i * inventoryAddrs::inventoryOffset);
		// 0 weapon, 2 armor, 6 jewellery,
		if (*itemID == 0 || *itemID == 2 || *itemID == 6) {
			continue;
		}
		// 4, 21 chunks of flesh
		BYTE* itemSubID = (BYTE*)((uintptr_t)start + inventoryAddrs::firstInventorySlot + inventoryAddrs::subItemTypeOffset + i * inventoryAddrs::inventoryOffset);
		if (*itemID == 4 && *itemSubID == 21) {
			continue;
		}

		// check if the inventory slot has been filled yet
		uintptr_t* memLoc = (uintptr_t*)((uintptr_t)start + inventoryAddrs::firstInventorySlot + offset + i * inventoryAddrs::inventoryOffset);
		uintptr_t arr[2] = { 0, 0 };
		memcpy(arr, memLoc, numBytes);
		if (Convert::ToInt16(*arr) == 0) {
			logger::WriteLinetoConsole("Location " + i + " failed");
			continue;
		}

		// if not, we good
		memcpy(memLoc, bytes, numBytes);
	}
	VirtualProtect(start + inventoryAddrs::firstInventorySlot, 52 * inventoryAddrs::inventoryOffset, oldprotect, &oldprotect);

}

void mem::EntityPatch(uintptr_t* start, const uintptr_t* bytes, int numBytes, uintptr_t offset) {

	DWORD oldprotect;

	// change the read/write permissions of the entity location
	VirtualProtect(start + envAddrs::firstEntityAddr, 701 * envAddrs::entityOffset, PAGE_EXECUTE_READWRITE, &oldprotect);
	// loop through entity list, set hp to 1
	for (unsigned int i = 0; i <= 701; ++i) {
		memcpy(start + (envAddrs::firstEntityAddr + offset + i * envAddrs::entityOffset) / sizeof(offset), bytes, numBytes);
	}

	VirtualProtect(start + envAddrs::firstEntityAddr, 701 * envAddrs::entityOffset, oldprotect, &oldprotect);

}


void mem::Patch(uintptr_t* dst, uintptr_t* src, unsigned int size){
	DWORD oldprotect;
	// change the read/write permissions of the memory location
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	// patch the bytes
	memcpy(dst, src, size);
	// change the permissions back
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

void mem::Read(uintptr_t* dst, uintptr_t* arr, unsigned int size) {

	DWORD oldprotect;
	// change the read/write permissions of the memory location
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	// read bytes
	memcpy(arr, dst, size);
	// change the permissions back
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

void mem::Nop(uintptr_t* dst, unsigned int size) {

	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}


