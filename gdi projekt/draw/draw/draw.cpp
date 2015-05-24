// draw.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "draw.h"
#include <Windows.h>
#include <queue>

using namespace std;

#define MAX_LOADSTRING 100
#define TMR_1 1

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

INT value = 0;
int pietro;
int licznik = 0;
queue  <int> pietro_kolejka;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
HWND PrzyciskP, Przycisk1, Przycisk2, Przycisk3, Przycisk4, Przycisk5;
HWND PrzyciskPP, Przycisk1P, Przycisk2P, Przycisk3P, Przycisk4P, Przycisk5P;
HWND hWnd;



void MyOnPaint(HDC hdc)
{
	if (!pietro_kolejka.empty())
	{
		if (value < pietro_kolejka.front() * 110) value++;
		if (value > pietro_kolejka.front() * 110) value--;
		if (value == pietro_kolejka.front() * 110)
		{
			licznik++;
			if (value < pietro_kolejka.front() * 110 && licznik < 50) value--;
			if (value > pietro_kolejka.front() * 110 && licznik < 50) value++;
			if (licznik >= 50)
			{
				pietro_kolejka.pop();
				licznik = 0;
			}
		}	
	}




	

	
	Graphics graphics(hdc);
	Font font(&FontFamily(L"Arial"), 40);
	SolidBrush brush_pietra(Color::Red);
	Pen pen_sciana(Color(255, 0, 0, 0), 2);
	Pen pen_lina(Color(255, 0, 0, 0), 1);
	Pen pen_winda(Color(255, 0, 0, 255), 2);
	Pen pen_pietra(Color(255, 0, 0, 0), 10);
	graphics.DrawLine(&pen_sciana, 100, 30, 100, 680);
	graphics.DrawLine(&pen_sciana, 170, 30, 170, 680);
	graphics.DrawRectangle(&pen_winda, 102, 30 + value, 66, 100);
	graphics.DrawLine(&pen_lina, 135, 30, 135, 30 + value);

	graphics.DrawLine(&pen_pietra, 50, 25, 220, 25);

	graphics.DrawString(L"5", -1, &font, PointF(50, 80), &brush_pietra);
	graphics.DrawLine(&pen_pietra, 50, 134, 100, 134);
	graphics.DrawLine(&pen_pietra, 170, 134, 220, 134);

	graphics.DrawString(L"4", -1, &font, PointF(50, 190), &brush_pietra);
	graphics.DrawLine(&pen_pietra, 50, 244, 100, 244);
	graphics.DrawLine(&pen_pietra, 170, 244, 220, 244);

	graphics.DrawString(L"3", -1, &font, PointF(50, 300), &brush_pietra);
	graphics.DrawLine(&pen_pietra, 50, 354, 100, 354);
	graphics.DrawLine(&pen_pietra, 170, 354, 220, 354);

	graphics.DrawString(L"2", -1, &font, PointF(50, 410), &brush_pietra);
	graphics.DrawLine(&pen_pietra, 50, 464, 100, 464);
	graphics.DrawLine(&pen_pietra, 170, 464, 220, 464);

	graphics.DrawString(L"1", -1, &font, PointF(50, 520), &brush_pietra);
	graphics.DrawLine(&pen_pietra, 50, 574, 100, 574);
	graphics.DrawLine(&pen_pietra, 170, 574, 220, 574);

	graphics.DrawString(L"P", -1, &font, PointF(50, 630), &brush_pietra);
	graphics.DrawLine(&pen_pietra, 50, 684, 220, 684);


}


int OnCreate(HWND window)
{
   SetTimer(window, TMR_1, 25, 0);
   return 0;
}



int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	
	
 	// TODO: Place code here.

	

	MSG msg;
	HACCEL hAccelTable;


	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);



	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	Przycisk5 = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "5", WS_CHILD | WS_VISIBLE,
		400, 100, 50, 50, hWnd, NULL, hInstance, NULL);

	Przycisk4 = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "4", WS_CHILD | WS_VISIBLE,
		400, 150, 50, 50, hWnd, NULL, hInstance, NULL);

	Przycisk3 = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "3", WS_CHILD | WS_VISIBLE,
		400, 200, 50, 50, hWnd, NULL, hInstance, NULL);

	Przycisk2 = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "2", WS_CHILD | WS_VISIBLE,
		400, 250, 50, 50, hWnd, NULL, hInstance, NULL);

	Przycisk1 = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "1", WS_CHILD | WS_VISIBLE,
		400, 300, 50, 50, hWnd, NULL, hInstance, NULL);

	PrzyciskP = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "P", WS_CHILD | WS_VISIBLE,
		400, 350, 50, 50, hWnd, NULL, hInstance, NULL);

	Przycisk5P = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "", WS_CHILD | WS_VISIBLE,
		175, 88, 40, 40, hWnd, NULL, hInstance, NULL);

	Przycisk4P = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "", WS_CHILD | WS_VISIBLE,
		175, 198, 40, 40, hWnd, NULL, hInstance, NULL);

	Przycisk3P = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "", WS_CHILD | WS_VISIBLE,
		175, 308, 40, 40, hWnd, NULL, hInstance, NULL);

	Przycisk2P = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "", WS_CHILD | WS_VISIBLE,
		175, 418, 40, 40, hWnd, NULL, hInstance, NULL);

	Przycisk1P = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "", WS_CHILD | WS_VISIBLE,
		175, 528, 40, 40, hWnd, NULL, hInstance, NULL);

	PrzyciskPP = CreateWindowEx(WS_EX_CLIENTEDGE, "BUTTON", "", WS_CHILD | WS_VISIBLE,
		175, 638, 40, 40, hWnd, NULL, hInstance, NULL);


















	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	GdiplusShutdown(gdiplusToken);

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage are only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{


   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);
   
   OnCreate(hWnd);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	//OnCreate(hWnd,wParam,lParam);
	//OnTimer(hWnd,wParam,lParam);

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		if ((HWND)lParam == Przycisk5) pietro_kolejka.push(0);
		if ((HWND)lParam == Przycisk4) pietro_kolejka.push(1);
		if ((HWND)lParam == Przycisk3) pietro_kolejka.push(2);
		if ((HWND)lParam == Przycisk2) pietro_kolejka.push(3);
		if ((HWND)lParam == Przycisk1) pietro_kolejka.push(4);
		if ((HWND)lParam == PrzyciskP) pietro_kolejka.push(5);
		if ((HWND)lParam == Przycisk5P) pietro_kolejka.push(0);
		if ((HWND)lParam == Przycisk4P) pietro_kolejka.push(1);
		if ((HWND)lParam == Przycisk3P) pietro_kolejka.push(2);
		if ((HWND)lParam == Przycisk2P) pietro_kolejka.push(3);
		if ((HWND)lParam == Przycisk1P) pietro_kolejka.push(4);
		if ((HWND)lParam == PrzyciskPP) pietro_kolejka.push(5);








		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here...
		MyOnPaint(hdc);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
			case TMR_1:
				//force window to repaint
				InvalidateRect(hWnd, NULL, TRUE);
				hdc = BeginPaint(hWnd, &ps);
				MyOnPaint(hdc);
				EndPaint(hWnd, &ps);
			break;
		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
