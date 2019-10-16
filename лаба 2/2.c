#include <windows.h>
#include <stdio.h>

void main()
{
	char buffer[100];
	DWORD len, actlean;
	HANDLE one, two, three, oneOut, twoOut, threeOut;
	BOOL rc1, rc2, rc3;
	char fNameOne[100] = "myresult.txt";
	len = strlen(buffer);
	one = CreateFile(fNameOne, FILE_SHARE_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	DuplicateHandle(GetCurrentProcess(), one, GetCurrentProcess(), &two, 0, FALSE, DUPLICATE_SAME_ACCESS);
	CloseHandle(one);
	CloseHandle(two);
	three = CreateFile(fNameOne, FILE_SHARE_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if(one == INVALID_HANDLE_VALUE) return;
	if(two == INVALID_HANDLE_VALUE) return;
	if(three == INVALID_HANDLE_VALUE) return;
	printf("1-%d, 2-%d, 3-%d\n", one, two, three);

	oneOut = GetStdHandle(STD_OUTPUT_HANDLE);
	twoOut = GetStdHandle(STD_OUTPUT_HANDLE);
	threeOut = GetStdHandle(STD_OUTPUT_HANDLE);

	rc1 = ReadFile(one, buffer, 7, &actlean, NULL);
	//if(!rc1) return;
	WriteFile(oneOut, buffer, actlean, &actlean, NULL);

	rc2 = ReadFile(two, buffer, 7, &actlean, NULL);
	if(!rc2) return;
	//WriteFile(twoOut, buffer, actlean, &actlean, NULL);

	rc3 = ReadFile(three, buffer, 7, &actlean, NULL);
	if(!rc3) return;
	WriteFile(threeOut, buffer, actlean, &actlean, NULL);
}