#pragma once
#include "stdafx.h"
#include "memory.h"
#include "constants.h"

void mem::PatchItemFlag(uintptr_t* start, const uintptr_t* flag, HANDLE process) {

	DWORD oldprotect;

	// change the read/write permissions of the inventory location
	VirtualProtectEx(process, start + inventoryAddrs::firstInventorySlot, 52 * inventoryAddrs::inventoryOffset, PAGE_EXECUTE_READWRITE, &oldprotect);
	// for each inventory slot, set the item_flag to flag
	for (unsigned int i = 0; i <= 52; ++i) {
		// flags are 4 bytes, pointer arithmetic
		WriteProcessMemory(process, 
			start + (inventoryAddrs::firstInventorySlot + inventoryAddrs::idStatusFlagOffset + i * inventoryAddrs::inventoryOffset) / sizeof(inventoryAddrs::idStatusFlagOffset),
			flag, 1, nullptr);
	}
	VirtualProtectEx(process, start + inventoryAddrs::firstInventorySlot, 2000 * inventoryAddrs::inventoryOffset, oldprotect, &oldprotect);

	// do the same for all environment items
	VirtualProtectEx(process, start + envAddrs::firstEnvItemSlot, 2000 * envAddrs::inventoryOffset, PAGE_EXECUTE_READWRITE, &oldprotect);
	for (unsigned int i = 0; i < 2000; ++i) {
		WriteProcessMemory(process, 
			start + (envAddrs::firstEnvItemSlot + envAddrs::idStatusFlagOffset + i * envAddrs::inventoryOffset) / sizeof(envAddrs::idStatusFlagOffset),
			flag, 1, nullptr);
	}
	VirtualProtectEx(process, start + envAddrs::firstEnvItemSlot, 2000 * envAddrs::inventoryOffset, oldprotect, &oldprotect);
	
}

void mem::Patch(uintptr_t* dst, uintptr_t* src, unsigned int size, HANDLE process){
	DWORD oldprotect;
	// change the read/write permissions of the memory location
	VirtualProtectEx(process, dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	// patch the bytes
	WriteProcessMemory(process, dst, src, size, nullptr);
	// change the permissions back
	VirtualProtectEx(process, dst, size, oldprotect, &oldprotect);
}

void mem::Read(uintptr_t* dst, uintptr_t* arr, unsigned int size, HANDLE process) {

	DWORD oldprotect;
	// change the read/write permissions of the memory location
	VirtualProtectEx(process, dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	// patch the bytes
	ReadProcessMemory(process, dst, arr, size, nullptr);
	// change the permissions back
	VirtualProtectEx(process, dst, size, oldprotect, &oldprotect);
}

void mem::Nop(uintptr_t* dst, unsigned int size, HANDLE process) {
	uintptr_t* nopArray = new uintptr_t[size];
	memset(nopArray, 0x90, size);
	Patch(dst, nopArray, size, process);
	delete[] nopArray;
}



