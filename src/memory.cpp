#pragma once
#include "stdafx.h"
#include "memory.h"
#include "constants.h"

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
		//WriteProcessMemory(process, 
		//	start + (inventoryAddrs::firstInventorySlot + inventoryAddrs::idStatusFlagOffset + i * inventoryAddrs::inventoryOffset) / sizeof(inventoryAddrs::idStatusFlagOffset),
		//	flag, 1, nullptr);
	}
	VirtualProtect(start + inventoryAddrs::firstInventorySlot, 2000 * inventoryAddrs::inventoryOffset, oldprotect, &oldprotect);

	// do the same for all environment items
	VirtualProtect(start + envAddrs::firstEnvItemSlot, 2000 * envAddrs::inventoryOffset, PAGE_EXECUTE_READWRITE, &oldprotect);
	for (unsigned int i = 0; i < 2000; ++i) {
		memcpy(
			start + (envAddrs::firstEnvItemSlot + envAddrs::idStatusFlagOffset + i * envAddrs::inventoryOffset) / sizeof(envAddrs::idStatusFlagOffset),
			flag, 1);
		//WriteProcessMemory(process, 
		//	start + (envAddrs::firstEnvItemSlot + envAddrs::idStatusFlagOffset + i * envAddrs::inventoryOffset) / sizeof(envAddrs::idStatusFlagOffset),
		//	flag, 1, nullptr);
	}
	VirtualProtect(start + envAddrs::firstEnvItemSlot, 2000 * envAddrs::inventoryOffset, oldprotect, &oldprotect);
	
}

void mem::EntityPatch(uintptr_t* start, const uintptr_t* bytes, int numBytes, uintptr_t offset) {

	DWORD oldprotect;

	// change the read/write permissions of the entity location
	VirtualProtect(start + envAddrs::firstEntityAddr, 701 * envAddrs::entityOffset, PAGE_EXECUTE_READWRITE, &oldprotect);
	// intptr_t hp[4] = { 0xFF, 0xFF, 0xFF, 0xFF };
	// loop through entity list, set hp to 0
	for (unsigned int i = 0; i <= 701; ++i) {
		memcpy(start + (envAddrs::firstEntityAddr + offset + i * envAddrs::entityOffset) / sizeof(offset), bytes, numBytes);
		//WriteProcessMemory(
		//	start + (envAddrs::firstEntityAddr + offset + i * envAddrs::entityOffset) / sizeof(offset),
		//	bytes, numBytes, nullptr);
	}

	VirtualProtect( start + envAddrs::firstEntityAddr, 701 * envAddrs::entityOffset, oldprotect, &oldprotect);

}


void mem::Patch(uintptr_t* dst, uintptr_t* src, unsigned int size){
	DWORD oldprotect;
	// change the read/write permissions of the memory location
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	// patch the bytes
	//WriteProcessMemory(process, dst, src, size, nullptr);
	// change the permissions back
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

void mem::Read(uintptr_t* dst, uintptr_t* arr, unsigned int size) {

	DWORD oldprotect;
	// change the read/write permissions of the memory location
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	// read bytes
	memcpy(arr, dst, size);
	//ReadProcessMemory(process, dst, arr, size, nullptr);
	// change the permissions back
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}

void mem::Nop(uintptr_t* dst, unsigned int size) {

	DWORD oldprotect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	memset(dst, 0x90, size);
	VirtualProtect(dst, size, oldprotect, &oldprotect);
}



