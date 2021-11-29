#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

int main()
{
	DWORD processID;

	//Offset = DWORD
	DWORD LocalPlayer = 0x509B74;
	int Base; 

	HWND hwnd = FindWindowA(0, ("AssaultCube"));
	GetWindowThreadProcessId(hwnd, &processID);

	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
	if (pHandle == 0) // 0 > NULL (its just the way it is)
	{
		std::cout << "Assault Cube Not Found";
	}

	std::cout << "F8 For Health\n";
	std::cout << "F9 For Armor\n";
	std::cout << "F10 For Rifle Ammo\n";

	while (1)
	{
		if (GetAsyncKeyState(VK_F8))
		{
			int newhealth = 10000;
			ReadProcessMemory(pHandle, (LPVOID*)LocalPlayer, &Base, sizeof(Base), NULL);
			Base += 0xF8;
			WriteProcessMemory(pHandle, (LPVOID*)Base, &newhealth, sizeof(newhealth), NULL);
			std::cin.ignore();
		}
		if (GetAsyncKeyState(VK_F9))
		{
			int newArmor = 8888;
			ReadProcessMemory(pHandle, (LPVOID*)LocalPlayer, &Base, sizeof(Base), NULL);
			Base += 0xFC;
			WriteProcessMemory(pHandle, (LPVOID*)Base, &newArmor, sizeof(newArmor), NULL);
			std::cin.ignore();
		}
		if (GetAsyncKeyState(VK_F10))
		{
			int newRammo = 10000;
			ReadProcessMemory(pHandle, (LPVOID*)LocalPlayer, &Base, sizeof(Base), NULL);
			Base += 0x150;
			WriteProcessMemory(pHandle, (LPVOID*)Base, &newRammo, sizeof(newRammo), NULL);
			std::cin.ignore();
		}
	}
}
