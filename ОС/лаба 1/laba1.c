#include <windows.h>
#include <stdio.h>

void main(){
    char buffer[100]="Text";
    DWORD actlen;
    HANDLE hstdin, hstdout;
    BOOL rc;
    hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if(hstdout == INVALID_HANDLE_VALUE) return;
    hstdin = GetStdHandle(STD_INPUT_HANDLE);
    if(hstdin == INVALID_HANDLE_VALUE) return;
    rc = ReadFile(hstdin, buffer+18, 80, &actlen, NULL);
    if(!rc) return;
    actlen += 18;
    WriteFile(hstdout, buffer, actlen, &actlen, 0);
    getchar();
}