// Small program to update data for memory addresses.
// ovh.feminine216@passinbox.com

#include <windows.h>
#include <iostream>

int writeMemory(HANDLE pHandle, DWORD hAddress, DWORD uValue) {
    BOOL wMem =  WriteProcessMemory(
        (HANDLE)pHandle,
        (LPVOID)hAddress,
        (LPCVOID)&uValue,
        (SIZE_T)sizeof(DWORD),
        NULL
    );   
    if (wMem == 0) {
        cout << "\nMemory write failed with ERROR code: " << GetLastError();
    }
    else if (wMem == 1) {
        cout << "\nMemory operation successfully completed! ";
    }
}

int main() {
    DWORD pId;
    DWORD hAddress; 
    DWORD uValue;

    cout << "\nEnter PID: ";
    cin >> pId;
    cout << "Enter memory address: ";
    scanf("%X", &hAddress);
    cout << "Enter new value: ";
    cin >> uValue;
    HANDLE pHandle = OpenProcess(
        PROCESS_VM_OPERATION | PROCESS_VM_WRITE, 
        FALSE, 
        pId
    );
    writeMemory(pHandle, hAddress, uValue);
}
