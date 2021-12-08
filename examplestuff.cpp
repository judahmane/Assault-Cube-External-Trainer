#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <TlHelp32.h>
struct Vector3
{
    float x, y, z;
};

// Created with ReClass.NET 1.2 by KN4CK3R

class N00000052
{
public:
	Vector3 poshead; //0x0004
	char pad_0010[36]; //0x0010
	Vector3 Pos; //0x0034
	Vector3 ViewAngles; //0x0040
	char pad_004C[172]; //0x004C
	int32_t Health; //0x00F8
	char pad_00FC[293]; //0x00FC
	char Name[16]; //0x0221
	char pad_0231[323]; //0x0231
	class N0000019B* currweapon; //0x0374
	char pad_0378[244]; //0x0378

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
}; //Size: 0x046C
static_assert(sizeof(N00000052) == 0x46C); //fix these by changing language standard to C++17 in properties :)


class N00000187
{
public:
	char pad_0000[68]; //0x0000
}; //Size: 0x0044
static_assert(sizeof(N00000187) == 0x44);

class N0000019B
{
public:
	char pad_0000[20]; //0x0000
	class ammoclip* ammoptr; //0x0014
	char pad_0018[44]; //0x0018
}; //Size: 0x0044
static_assert(sizeof(N0000019B) == 0x44);

class ammoclip
{
public:
	int32_t Ammo; //0x0000
}; //Size: 0x0004
static_assert(sizeof(ammoclip) == 0x4);


template<int N>
class arrays
{
public:
	int ar[N];
	int print() { return N; }
};


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
			int health;
			ReadProcessMemory(pHandle, (LPVOID*)LocalPlayer, &health, sizeof(health), NULL); //dont read when assinging value of offset
			                                  //we must get the adddress 
			health = health + 0xF8;
			WriteProcessMemory(pHandle, (LPVOID*)health, &newhealth, sizeof(newhealth), NULL);
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

