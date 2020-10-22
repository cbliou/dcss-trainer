// dcsstrainer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "process.h"
#include "memory.h"

int main()
{
    wchar_t name[16] = L"crawl-tiles.exe";
    HANDLE process = 0;
    uintptr_t moduleBase = 0;
    bool godmode = false;

    // get process ID of crawl
    DWORD process_id = GetProcessID(name);

    // if successful
    if (process_id) {

        std::cout << "Process found.\n";

        // get handle
        process = OpenProcess(PROCESS_ALL_ACCESS, NULL, process_id);

        // get module base address
        moduleBase = ModuleBaseAddress(process_id, name);

    }
    else {
        std::cout << "Process not found. Please start crawl-tiles.exe before starting the trainer.\n";
        std::cout << "Press Enter to exit.\n";
        getchar();
        return 0;
    }

    // start hack loop and check if crawl is still open
    DWORD exit = 0;

    while (GetExitCodeProcess(process, &exit)) {

        // activate godmode
        if (GetAsyncKeyState(VK_F1) & 1) {

            godmode = !godmode;

            if (godmode) {

                std::cout << "Activating godmode.\n";
                // this function call is moving a certain value to decrement the player health by.
                // nopping this call sets all damage taken by the player to 0
                mem::Nop((BYTE*)moduleBase + 0x4A7FAE, 2, process);

            }

            else {

                std::cout << "Deactivating godmode.\n";
                // offset +4A7FAE
                // 29 D8 = sub eax, ebx
                mem::Patch((BYTE*)(moduleBase + 0x4A7FAE), (BYTE*)"\x29\xD8", 2, process);

            }

        }

    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
