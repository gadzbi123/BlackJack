#include "pch.h"
// JAApp.cpp : Defines the entry point for the console application.
//
#include <windows.h>

extern "C" int _stdcall MyProc1(DWORD x, DWORD y);


int main()
{
	int x = 4, y = 3, z = 0;

	z = MyProc1(x, y);  // call to library assemmbler procedure

	return 0;
}
