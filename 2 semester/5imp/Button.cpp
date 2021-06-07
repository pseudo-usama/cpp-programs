
#include "stdafx.h"

#include "iostream"
#include <Windows.h>
using namespace std;

int main()
{
	MSG msg;
	//if you add WS_CHILD flag,CreateWindow will fail because there is no parent window.
	HWND hWnd = CreateWindow(TEXT("button"), TEXT("Eay"), WS_VISIBLE | WS_POPUP,
		200, 200, 210, 210, NULL, NULL, NULL, NULL);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	//return (int)msg.wParam;
	return 0;


}








