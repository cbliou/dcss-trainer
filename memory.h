#pragma once
#include "stdafx.h"


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

	/*
	Reads `size` bytes from memory location `dst`. `arr` is a pointer to a buffer holding the read data.
	*/
	void Read(BYTE* dst, BYTE* arr, unsigned int size, HANDLE process);
}