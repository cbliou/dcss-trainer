// dcsstrainer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "process.h"
#include "memory.h"
#include <iterator>
#include <unordered_map>

/*
Takes in a unsigned byte integer and converts it to a hexadecimal char array

void byte_to_hex(int n, std::string buffer) {

    int i = 3, base = 16;

    do {
        
        buffer[i] = "0123456789ABCDEF"[n % base];
        --i;
        n = n / base;

    } while (n > 0);

}*/

int main()
{
    wchar_t name[16] = L"crawl-tiles.exe";
    HANDLE process = 0;
    uintptr_t moduleBase = 0;

    bool godmode = false;
    bool infinitemana = false;
    std::unordered_map<int, std::string> byte_to_hex({
        {0, "\x00"}, {1, "\x01"}, {2, "\x02"}, {3, "\x03"},
        {4, "\x04"}, {5, "\x05"}, {6, "\x06"}, {7, "\x07"},
        {8, "\x08"}, {9, "\x09"}, {10, "\x0a"}, {11, "\x0b"},
        {12, "\x0c"}, {13, "\x0d"}, {14, "\x0e"}, {15, "\x0f"},
        {16, "\x10"}, {17, "\x11"}, {18, "\x12"}, {19, "\x13"},
        {20, "\x14"}, {21, "\x15"}, {22, "\x16"}, {23, "\x17"},
        {24, "\x18"}, {25, "\x19"}, {26, "\x1a"}, {27, "\x1b"},
        {28, "\x1c"}, {29, "\x1d"}, {30, "\x1e"}, {31, "\x1f"},
        {32, "\x20"}, {33, "\x21"}, {34, "\x22"}, {35, "\x23"},
        {36, "\x24"}, {37, "\x25"}, {38, "\x26"}, {39, "\x27"},
        {40, "\x28"}, {41, "\x29"}, {42, "\x2a"}, {43, "\x2b"},
        {44, "\x2c"}, {45, "\x2d"}, {46, "\x2e"}, {47, "\x2f"},
        {48, "\x30"}, {49, "\x31"}, {50, "\x32"}, {51, "\x33"},
        {52, "\x34"}, {53, "\x35"}, {54, "\x36"}, {55, "\x37"},
        {56, "\x38"}, {57, "\x39"}, {58, "\x3a"}, {59, "\x3b"},
        {60, "\x3c"}, {61, "\x3d"}, {62, "\x3e"}, {63, "\x3f"},
        {64, "\x40"}, {65, "\x41"}, {66, "\x42"}, {67, "\x43"},
        {68, "\x44"}, {69, "\x45"}, {70, "\x46"}, {71, "\x47"},
        {72, "\x48"}, {73, "\x49"}, {74, "\x4a"}, {75, "\x4b"},
        {76, "\x4c"}, {77, "\x4d"}, {78, "\x4e"}, {79, "\x4f"},
        {80, "\x50"}, {81, "\x51"}, {82, "\x52"}, {83, "\x53"},
        {84, "\x54"}, {85, "\x55"}, {86, "\x56"}, {87, "\x57"},
        {88, "\x58"}, {89, "\x59"}, {90, "\x5a"}, {91, "\x5b"},
        {92, "\x5c"}, {93, "\x5d"}, {94, "\x5e"}, {95, "\x5f"},
        {96, "\x60"}, {97, "\x61"}, {98, "\x62"}, {99, "\x63"},
        {100, "\x64"}, {101, "\x65"}, {102, "\x66"}, {103, "\x67"},
        {104, "\x68"}, {105, "\x69"}, {106, "\x6a"}, {107, "\x6b"},
        {108, "\x6c"}, {109, "\x6d"}, {110, "\x6e"}, {111, "\x6f"},
        {112, "\x70"}, {113, "\x71"}, {114, "\x72"}, {115, "\x73"},
        {116, "\x74"}, {117, "\x75"}, {118, "\x76"}, {119, "\x77"},
        {120, "\x78"}, {121, "\x79"}, {122, "\x7a"}, {123, "\x7b"},
        {124, "\x7c"}, {125, "\x7d"}, {126, "\x7e"}, {127, "\x7f"}
        });

    // get process ID of crawl
    DWORD process_id = GetProcessID(name);

    // if successful
    if (process_id) {

        std::cout << "Found crawl-tiles.exe. Locating base address...\n";

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

    std::cout << "Located address.\n";

    // start hack loop and check if crawl is still open
    DWORD exit = 0;

    while (GetExitCodeProcess(process, &exit) && exit > 0) {



        // activate godmode
        if (GetAsyncKeyState(VK_F1) & 1) {

            godmode = !godmode;

            if (godmode) {

                std::cout << "Activating godmode.\n";
                // this function call is subtracting the value of ebx from eax
                // nopping this call sets all damage taken by the player to 0 as no decrement is processed
                mem::Nop((BYTE*)moduleBase + 0x4A7FAE, 2, process);

            }

            else {

                std::cout << "Deactivating godmode.\n";
                // offset 4A7FAE
                // 29 D8 - sub eax, ebx
                mem::Patch((BYTE*)(moduleBase + 0x4A7FAE), (BYTE*)"\x29\xD8", 2, process);

            }

        }

        // activate infinite mana
        if (GetAsyncKeyState(VK_F2) & 1) {

            infinitemana = !infinitemana;

            if (infinitemana) {

                std::cout << "Activating infinite mana.\n";
                // this address is the lowest one out of the three that write to mana
                mem::Nop((BYTE*)moduleBase + 0x4A83B9, 5, process);

            }

            else {

                std::cout << "Deactivating infinite mana.\n";
                // offset 4A83B9
                // 29 D8 - sub eax, ebx
                // 0F 48 C2 - cmovs eax, edx
                mem::Patch((BYTE*)(moduleBase + 0x4A83B9), (BYTE*)"\x29\xD8\x0F\x48\xC2", 5, process);

            }

        }

        // set str
        if (GetAsyncKeyState(VK_F3) & 1) {

            int strength;

            std::cout << "Enter a number between 0 and 127 to set your strength value to: " << std::dec;

            std::cin >> strength;
            std::cin.sync();
            
            if (strength < 0 || strength > 127) {
                std::cout << "Your desired value is not between 0 and 127.\nClipping value at the storage bounds.\n";
                if (strength > 127) {
                    strength = 127;
                }
                else {
                    strength = 0;
                }

            }
            std::cout << "Setting strength to " << strength << "\n";
            mem::Patch((BYTE*)(moduleBase + 0xE7BD73), (BYTE*)(byte_to_hex[strength].c_str()), 1, process);

        }

        Sleep(20);

        // set int
        if (GetAsyncKeyState(VK_F4) & 1) {

            int intelligence;

            std::cout << "Enter a number between 0 and 127 to set your intelligence value to: " << std::dec;

            std::cin >> intelligence;
            std::cin.sync();

            if (intelligence < 0 || intelligence > 127) {
                std::cout << "Your desired value is not between 0 and 127.\nClipping value at the storage bounds.\n";
                if (intelligence > 127) {
                    intelligence = 127;
                }
                else {
                    intelligence = 0;
                }

            }
            std::cout << "Setting intelligence to " << intelligence << "\n";
            mem::Patch((BYTE*)(moduleBase + 0xE7BD74), (BYTE*)(byte_to_hex[intelligence].c_str()), 1, process);

        }

        // set dex
        if (GetAsyncKeyState(VK_F5) & 1) {

            int dex;

            std::cout << "Enter a number between 0 and 127 to set your dexterity value to: " << std::dec;

            std::cin >> dex;
            std::cin.sync();

            if (dex < 0 || dex > 127) {
                std::cout << "Your desired value is not between 0 and 127.\nClipping value at the storage bounds.\n";
                if (dex > 127) {
                    dex = 127;
                }
                else {
                    dex = 0;
                }

            }
            std::cout << "Setting dexterity to " << dex << "\n";
            mem::Patch((BYTE*)(moduleBase + 0xE7BD75), (BYTE*)(byte_to_hex[dex].c_str()), 1, process);

        }

    }

    std::cout << "Crawl has been closed. Closing the trainer...\n";
    Sleep(2000);

}
