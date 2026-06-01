/*-------------------------------------------------------------------

*   ``~ Main code file for memedit (Written by haeoro) ~``
*
*   Small program written to make modifications to a memory address  
*   within a software application.
*
*   The program is nowhere near as sophisticated as some of the popular
*   memory scanners out there, as it is a beginner project. Hell, it doesn't
*   even have a memory scanning feature. 
*
*   I thought I'd come back to this project and implement some argument passing
*   functionality, as opposed to it's initial method of input: std::cin. 

-------------------------------------------------------------------*/


#include <windows.h>
#include <iostream>
#include <vector>

int programUsageHelper(const int argc) 
{
    std::string usageMsg = "Usage: memedit -m [memory address] -v [value] -p [process id]";
    if (argc == 1 || argc > 1) 
    {
        std::cout << usageMsg << '\n';
        return 1;
    }
    return 0;
}

void writeMemory(HANDLE pHandle, LPVOID bAddress, LPCVOID uValue) {
    BOOL wMem =  WriteProcessMemory(
        pHandle,
        bAddress,
        uValue,
        (SIZE_T)sizeof(DWORD),
        NULL
    );  
    std::cout << writeMemory; 
    if (!writeMemory) 
    {
        int memoryOperation = GetLastError();
        std::cout << memoryOperation;
        if (memoryOperation == 6) 
        {
            std::cout << "memedit: Please specify a valid process id.";
        }
    }
    else if (writeMemory)
    {
        std::cout << "\nMemory operation successfully completed! ";
    }
}

int searchArgs(int argc, char *args[]) 
{
    short counter = 0;
    const char *switches[] = {"-m", "-v", "-p"};
    for (int o = 1; o < argc; o++) 
    {
        for (int i = 0; i < ((sizeof(switches))/8); i++) 
        {
            if (!strcmp(args[o], switches[i])) 
            {
                counter++;
                if (counter == 3) 
                {
                    return 0;
                }
            }
        }
    }
    programUsageHelper(argc);
    return 1;
}

int main(int argc, char *argv[]) 
{
    LPVOID bAddress = nullptr; 
    LPCVOID uValue = nullptr;
    if (searchArgs(argc, argv)) 
    {
        return 1;
    }
    DWORD pId = std::stoi(argv[6]);
    HANDLE pHandle = OpenProcess(
        PROCESS_VM_OPERATION | PROCESS_VM_WRITE, 
        FALSE, 
        pId
    );
    writeMemory(pHandle, bAddress, uValue);
}