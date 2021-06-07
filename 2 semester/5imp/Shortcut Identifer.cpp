// Shortcut Identifer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
using namespace std;

#include "windows.h"
#include "conio.h"

#ifndef CTRL
#define CTRL(c) ((c) & 037)
#endif

int main(){
	HWND window;
	AllocConsole();
	window = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(window, 0);

	char Selector;

	Selector = _getch();

	if (Selector == CTRL('T')) {
		ShellExecute(NULL, L"open", L"E:/a.txt", NULL, NULL, SW_SHOWDEFAULT);
	}
	else if (GetKeyState(VK_SHIFT) & 0x8000) {
		ShellExecute(NULL, L"open", L"E:/b.txt", NULL, NULL, SW_SHOWDEFAULT);
	}
	//if (GetKeyState(VK_SHIFT) & 0x8000 && GetKeyState(VK_CONTROL) & 0x8000)  //CTRL + SHIFT

	//You should handle WM_KEYDOWN and WM_KEYUP messages, and track the state(up or down) for all of these keys : VK_SHIFT, VK_CONTROL, VK_MENU.

	return 0;
}

