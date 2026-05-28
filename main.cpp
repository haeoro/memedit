// Small program to update data for memory addresses.
// ovh.feminine216@passinbox.com

#include <windows.h>
#include <iostream>
#include <vector>

void writeMemory(HANDLE pHandle, LPVOID bAddress, LPCVOID uValue) {
    BOOL wMem =  WriteProcessMemory(
        (HANDLE)pHandle,
        bAddress,
        uValue,
        (SIZE_T)sizeof(DWORD),
        NULL
    );   
    if (wMem == 0) {
        std::cout << "\nMemory write failed with ERROR code: " << GetLastError();
    }
    else if (wMem == 1) {
        std::cout << "\nMemory operation successfully completed! ";
    }
}

void searchArgs(int argc, char *args[]) 
{
    const char *arguments[] = {"-m", "-s"};
    for (int o = 0; o < argc; o++) 
    {
        for (int i = 0; i < 2; i++) 
        {
            if (!strcmp(args[o], arguments[i])) 
            {
                std::cout << "found match:" << args[o] << arguments[i];
            }
        }
    }
    std::cout << "no match found.";
}

int main(int argc, char *argv[]) {
    DWORD pId = 0;
    LPVOID bAddress = nullptr; 
    LPCVOID uValue = nullptr;
    searchArgs(argc, argv);
    return 1;
    HANDLE pHandle = OpenProcess(
        PROCESS_VM_OPERATION | PROCESS_VM_WRITE, 
        FALSE, 
        pId
    );
    writeMemory(pHandle, bAddress, uValue);
}

/*

    TO-DO

    ~ make main take 2 arguments, -m for memory address and -v for value.
    ~ create some file documentation at the start, make it nice and neat. 

*/