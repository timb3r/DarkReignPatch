#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include "DarkReignPatch.h"

#define PtrFromRva( base, rva ) ( ( ( PBYTE ) base ) + rva )

typedef BOOL(WINAPI* GetVolumeInformationA_t)(LPCSTR, LPSTR, DWORD, LPDWORD, LPDWORD, LPDWORD, LPSTR, DWORD);
GetVolumeInformationA_t fnGetVolumeInformation;

typedef UINT(WINAPI* GetDriveTypeA_t)(LPCSTR);
GetDriveTypeA_t fnGetDriveTypeA;

typedef DWORD(WINAPI* GetLogicalDrives_t)();
GetLogicalDrives_t fnGetLogicalDrives;

BOOL HookIAT(const char* szModuleName, const char* szFuncName, PVOID pNewFunc, PVOID* pOldFunc)
{
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)GetModuleHandle(NULL);
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)PtrFromRva(pDosHeader, pDosHeader->e_lfanew);

	// Make sure we have valid data
	if (pNtHeader->Signature != IMAGE_NT_SIGNATURE)
		return FALSE;

	// Grab a pointer to the import data directory
	PIMAGE_IMPORT_DESCRIPTOR pImportDescriptor = (PIMAGE_IMPORT_DESCRIPTOR)PtrFromRva(pDosHeader, pNtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);

	for (UINT uIndex = 0; pImportDescriptor[uIndex].Characteristics != 0; uIndex++)
	{
		char* szDllName = (char*)PtrFromRva(pDosHeader, pImportDescriptor[uIndex].Name);

		// Is this our module?
		if (_strcmpi(szDllName, szModuleName) != 0)
			continue;

		if (!pImportDescriptor[uIndex].FirstThunk || !pImportDescriptor[uIndex].OriginalFirstThunk)
			return FALSE;

		PIMAGE_THUNK_DATA pThunk = (PIMAGE_THUNK_DATA)PtrFromRva(pDosHeader, pImportDescriptor[uIndex].FirstThunk);
		PIMAGE_THUNK_DATA pOrigThunk = (PIMAGE_THUNK_DATA)PtrFromRva(pDosHeader, pImportDescriptor[uIndex].OriginalFirstThunk);

		for (; pOrigThunk->u1.Function != NULL; pOrigThunk++, pThunk++)
		{
			// We can't process ordinal imports just named
			if (pOrigThunk->u1.Ordinal & IMAGE_ORDINAL_FLAG)
				continue;

			PIMAGE_IMPORT_BY_NAME import = (PIMAGE_IMPORT_BY_NAME)PtrFromRva(pDosHeader, pOrigThunk->u1.AddressOfData);

			// Is this our function?
			if (_strcmpi(szFuncName, (char*)import->Name) != 0)
				continue;

			DWORD dwJunk = 0;
			MEMORY_BASIC_INFORMATION mbi;

			// Make the memory section wri	table
			VirtualQuery(pThunk, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
			if (!VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &mbi.Protect))
				return FALSE;

			// Save the old pointer
			*pOldFunc = (PVOID*)(DWORD_PTR)pThunk->u1.Function;

			// Write the new pointer based on CPU type
#ifdef _WIN64
			pThunk->u1.Function = (ULONGLONG)(DWORD_PTR)pNewFunc;
#else
			pThunk->u1.Function = (DWORD)(DWORD_PTR)pNewFunc;
#endif

			if (VirtualProtect(mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &dwJunk))
				return TRUE;
		}
	}
	return FALSE;
}

BOOL WINAPI HookGetVolumeInformation(LPCSTR a, LPSTR b, DWORD c, LPDWORD d, LPDWORD e, LPDWORD f, LPSTR g, DWORD h)
{
	if (a[0] == 'a' || a[0] == 'A') {
		char systemDrive[5] = { 0 };
		GetEnvironmentVariable("SystemDrive", systemDrive, 5); systemDrive[2] = '\\';
		
		bool bRet = fnGetVolumeInformation(systemDrive, b, c, d, e, f, g, h);

		if (!bRunExpansion && strstr(GetCommandLineA(), "-expansion")) {
			bRunExpansion = true;
		}

		sprintf(b, bRunExpansion ? "Shadowhand" : "Dkreign");
		return bRet;
	}
	return fnGetVolumeInformation(a, b, c, d, e, f, g, h);
}

UINT WINAPI HookGetDriveType(LPCSTR a)
{
	if (a[0] == 'a' || a[0] == 'A')
		return DRIVE_CDROM;
	return fnGetDriveTypeA(a);
}

DWORD WINAPI HookGetLogicalDrives()
{
	DWORD drivesMask = fnGetLogicalDrives();
	drivesMask = drivesMask & 0xFE | 0x01;
	return drivesMask;
}

DWORD WINAPI InitialisePatch(LPVOID p)
{	
	HookIAT("kernel32.dll", "GetVolumeInformationA", HookGetVolumeInformation, (LPVOID*)& fnGetVolumeInformation);
	HookIAT("kernel32.dll", "GetDriveTypeA", HookGetDriveType, (LPVOID*)& fnGetDriveTypeA);
	HookIAT("kernel32.dll", "GetLogicalDrives", HookGetLogicalDrives, (LPVOID*)& fnGetLogicalDrives);
	return 0;
}