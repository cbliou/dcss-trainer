#pragma once
#include "stdafx.h"

namespace hooks {

	/*
	Inserts a hook at `hookAddress` to jump to jumpAddress. Fails if size if < 5.
	Don't do pointer arithmetic (but really, we should treat these as pointers...)
	*/
	bool Hook(uintptr_t moduleBase, uintptr_t hookAddress, void* jumpAddress, unsigned int size) {
		if (size < 5) {
			return false;
		}

		DWORD oldprotect;
		VirtualProtect((LPVOID*)(moduleBase + hookAddress), size, PAGE_EXECUTE_READWRITE, &oldprotect);
		// jmp jumpAddress
		// write jmp first
		memset((uintptr_t*)(moduleBase + hookAddress), 0xE9, 1);
		// calculate relative offset as the PC increments then jumps
		uintptr_t relativeAddress = (uintptr_t)jumpAddress - hookAddress - moduleBase - 5;
		// you need to increment one byte, dereference then add to just add one byte
		*(uintptr_t*)(moduleBase + hookAddress + 1) = (uintptr_t)relativeAddress;
		// this won't work unless u have a buffer
		//memcpy((uintptr_t*) (moduleBase + hookAddress + 1), jumpAddress, 4);
		// then however many bytes are left, write nops
		memset((uintptr_t*)(moduleBase + hookAddress + 5), 0x90, size - 5);
		VirtualProtect((LPVOID*)(moduleBase + hookAddress), size, oldprotect, &oldprotect);
		return true;
		
	}
	
	// edx stores change in x
	void __declspec(naked) disableX(void) {
		__asm {
			add edx, 0x0
			mov eax, [ebp - 0xA0]
			jmp [disablexRetAddy]
		}
	}

	// eax stores change in y
	void _declspec(naked) disableY(void) {
		__asm {
			add eax, 0x0
			lea ecx, [edx - 0x01]
			jmp [disableyRetAddy]
		}
	}

	void __declspec(naked) instakill(void) {
		__asm {
			sub eax, esi
			cmp eax, edx
			mov [ebx + 0x54], 0x0
			jmp [instakillRetAddy]
		}
	}


}