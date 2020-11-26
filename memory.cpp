#include "stdafx.h"
#include "memory.h"

void mem::Patch(BYTE* dst, BYTE* src, unsigned int size, HANDLE process)
{
	DWORD oldprotect;
	// change the read/write permissions of the memory location
	VirtualProtectEx(process, dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	// patch the bytes
	WriteProcessMemory(process, dst, src, size, nullptr);
	// change the permissions back
	VirtualProtectEx(process, dst, size, oldprotect, &oldprotect);
}

void mem::Read(BYTE* dst, BYTE* arr, unsigned int size, HANDLE process) {

	DWORD oldprotect;
	// change the read/write permissions of the memory location
	VirtualProtectEx(process, dst, size, PAGE_EXECUTE_READWRITE, &oldprotect);
	// patch the bytes
	ReadProcessMemory(process, dst, arr, size, nullptr);
	// change the permissions back
	VirtualProtectEx(process, dst, size, oldprotect, &oldprotect);
}

void mem::Nop(BYTE* dst, unsigned int size, HANDLE process)
{
	BYTE* nopArray = new BYTE[size];
	memset(nopArray, 0x90, size);
	Patch(dst, nopArray, size, process);
	delete[] nopArray;
}

