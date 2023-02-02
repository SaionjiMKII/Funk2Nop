#include <Windows.h>
#include <iostream>

#pragma optimize( "", off )

typedef LPVOID(*pAlloc)();
LPVOID Valloc();

VOID WINAPI Entry(VOID) 
{
    int sss = 0;
    LPVOID Done = Valloc();
    
    DWORD oldProtect;
    size_t functionSize = 97;
    VirtualProtect(Valloc, functionSize, PAGE_EXECUTE_READWRITE, &oldProtect);

    for (size_t i = 0; i < functionSize; ++i) {
        *((char*)Valloc + i) = 0x90;
        sss = i;
    }
    VirtualProtect(Valloc, functionSize, oldProtect, &oldProtect);

    pAlloc functionPointer = Valloc;
    if(sss != 0)
	    MessageBoxA(NULL, "NOP success!", "SHC", MB_OK);
	if (sss == 0)
	    MessageBoxA(NULL, "NOP failed!", "SHC", MB_OK);
    
    while (true)
    {
        sss++;
    }
}

LPVOID Valloc()

{
    LPVOID lpvResult;

    lpvResult = VirtualAlloc(NULL, 320, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    if (lpvResult == NULL)
    {
        MessageBoxA(NULL, "VirtualAlloc failed!", "SHC", MB_OK);
        return 0;
    }
    VirtualFree(lpvResult, 0, MEM_RELEASE);
	MessageBoxA(NULL, "VirtualAlloc success!", "SHC", MB_OK);
    
    return lpvResult;
}