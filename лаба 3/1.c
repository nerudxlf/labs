#include <windows.h>
#include <stdio.h>

void main()
{
	char buffer[100];
	DWORD len, actlen;
	HANDLE hstdin, fhandle, hstdout;
	char fname[100]="lol.txt";
	BOOL rc;
	int Error;
	len = strlen(buffer); // вычисляет длину текста в буфере
	hstdin = GetStdHandle(STD_INPUT_HANDLE);
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hstdin == INVALID_HANDLE_VALUE) return;
	fhandle=CreateFile(fname,  FILE_SHARE_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (fhandle == INVALID_HANDLE_VALUE){
		Error = GetLastError();
		if(Error == 32){
			printf("The process cannot access the file because it is being used by another process.\n");
			while(1){
				if(fhandle != INVALID_HANDLE_VALUE) break;
				fhandle=CreateFile(fname,  FILE_SHARE_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
				rc=ReadFile(fhandle, buffer, 80, &actlen, NULL);
				WriteFile(hstdout, buffer, actlen, &actlen, NULL);
			}
		}
		if(Error == 2){
			printf("The system cannot find the file specified\n");
		}
	}
	getchar();
	CloseHandle(fhandle);
	CloseHandle(hstdin);
	CloseHandle(hstdout);
	return;
}