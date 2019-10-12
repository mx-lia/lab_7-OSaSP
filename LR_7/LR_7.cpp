#include <windows.h>
#include <iostream>
#include "string.h"
#include <tchar.h>

int number;

DWORD WINAPI reader(void* lpParameter)
{
	std::cout << number << std::endl;
	return 0;
}



DWORD WINAPI writer(void* lpParameter)
{
	int my_counter = 0;
	for (int i = 1; i <= 10; i++)
	{
		number = i;
		DWORD readerID;
		HANDLE reader_handle = CreateThread(0, 0, reader, &my_counter, 0, &readerID);
		Sleep(500);
	}
	return 0;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int my_counter = 0;
	DWORD writerID;
	HANDLE writer_handle = CreateThread(0, 0, writer, &my_counter, 0, &writerID);
	getchar();
	return 0;
}
