#pragma once
#include "stdafx.h"
#include <Windows.h>

namespace mem
{
	/*
	Patches a memory location.
	dst : pointer to the memory location
	src : the bytes you wish to patch the location with
	size: how many bytes you are patching
	process : handle to the process you are patching
	*/
	void Patch(BYTE* dst, BYTE* src, unsigned int size, HANDLE process);

	/*
	Patches a memory location with bytes representing nop
	*/
	void Nop(BYTE* dst, unsigned int size, HANDLE process);
}