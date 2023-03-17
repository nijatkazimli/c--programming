#include "framework.h"
#include "main.h"
#include <string>
#include <tchar.h>
#include <commdlg.h>
#include <vector>
#define MAX_LOADSTRING 100

HINSTANCE hInst;

HWND MainHandler;
HWND PaddleHandler;
HWND BallHandler;
HWND TrailHandler;

WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowMainClass[MAX_LOADSTRING];
WCHAR szWindowPaddleClass[MAX_LOADSTRING];
WCHAR szWindowBallClass[MAX_LOADSTRING];


COLORREF background_color = RGB(144, 238, 144);

HBITMAP background_bitmap = NULL;

WCHAR szFileName[MAX_PATH] = { 0 };

int main_width = 500;
int main_height = 350;
int paddle_width = 20;
int paddle_height = 100;


int ball_pos_x = 70;
int ball_pos_y = 70;
int ball_diam = 20;
int ball_dx = 5;
int ball_dy = 5;

int missed = 0;
int not_missed = 0;

bool isStreched = false;

ATOM MyRegisterMainClass(HINSTANCE hInstance);
ATOM MyRegisterPaddleClass(HINSTANCE hInstance);
ATOM MyRegisterBallClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK PaddleWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK BallWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDS_MAIN_CLASS_NAME, szWindowMainClass, MAX_LOADSTRING);
	LoadStringW(hInstance, IDS_PADDLE_CLASS_NAME, szWindowPaddleClass, MAX_LOADSTRING);
	LoadStringW(hInstance, IDS_BALL_CLASS_NAME, szWindowBallClass, MAX_LOADSTRING);

	MyRegisterMainClass(hInstance);
	MyRegisterPaddleClass(hInstance);
	MyRegisterBallClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance,MAKEINTRESOURCE(IDR_ACCELERATOR1));

	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return static_cast<int>(msg.wParam);
}

ATOM MyRegisterMainClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON2));
	wcex.hCursor = LoadCursor(hInst, MAKEINTRESOURCE(IDC_ARROW));
	wcex.hbrBackground = CreateSolidBrush(background_color);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wcex.lpszClassName = szWindowMainClass;
	wcex.hIconSm = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);
}

ATOM MyRegisterPaddleClass(HINSTANCE hInstance)
{

	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = PaddleWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = nullptr;
	wcex.hbrBackground = CreateSolidBrush(GetSysColor(COLOR_ACTIVECAPTION));
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = szWindowPaddleClass;
	wcex.hIconSm = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);
}

ATOM MyRegisterBallClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = BallWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));
	wcex.hCursor = nullptr;
	wcex.hbrBackground = CreateSolidBrush(RGB(255,0,0));
	wcex.lpszMenuName = nullptr;
	wcex.lpszClassName = szWindowBallClass;
	wcex.hIconSm = LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1));

	return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance;
	MainHandler = CreateWindowW(szWindowMainClass, szTitle,
		WS_OVERLAPPEDWINDOW & ~(WS_THICKFRAME | WS_MAXIMIZEBOX),
		GetSystemMetrics(SM_CXSCREEN)/2-main_width/2,
		GetSystemMetrics(SM_CYSCREEN) / 2 - main_height / 2,
		main_width,
		main_height,
		nullptr,
		nullptr,
		hInstance,
		nullptr);

	RECT rc;
	GetClientRect(MainHandler, &rc);
	PaddleHandler = CreateWindowW(szWindowPaddleClass, szTitle,
		WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		rc.right-paddle_width,
		(rc.bottom - rc.top  ) / 2 - paddle_height / 2,
		paddle_width,
		paddle_height,
		MainHandler,
		nullptr,
		hInstance,
		nullptr);

	BallHandler = CreateWindowW(szWindowBallClass, szTitle,
		WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		ball_pos_x,
		ball_pos_y,
		ball_diam,
		ball_diam,
		MainHandler,
		nullptr,
		hInstance,
		nullptr);
	SetTimer(BallHandler, 1, 50, NULL);
	

	if (!MainHandler || !PaddleHandler || !BallHandler)
	{
		return FALSE;
	}
	HRGN region = CreateEllipticRgn(0, 0, ball_diam, ball_diam);
	SetWindowRgn(BallHandler, region, TRUE);


	SetWindowLong(MainHandler, GWL_EXSTYLE, GetWindowLong(MainHandler, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(MainHandler, 0, (255 * 80) / 100, LWA_ALPHA);
	ShowWindow(MainHandler, nCmdShow);
	ShowWindow(PaddleHandler, nCmdShow);
	ShowWindow(BallHandler, nCmdShow);

	UpdateWindow(MainHandler);
	UpdateWindow(PaddleHandler);
	UpdateWindow(BallHandler);
	UpdateWindow(TrailHandler);
	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int command;
	int y_pos;
	switch (message)
	{
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		RECT rc;
		HDC hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &rc);
		SetDCBrushColor(hdc, background_color);
		FillRect(hdc, &rc, (HBRUSH)GetStockObject(DC_BRUSH));
		if (background_bitmap)
		{
			HDC hdcMem = CreateCompatibleDC(hdc);
			HBITMAP hOldBitmap = (HBITMAP)SelectObject(hdcMem, background_bitmap);
			BITMAP bmp;
			GetObject(background_bitmap, sizeof(BITMAP), &bmp);
			int bitmap_width = bmp.bmWidth;
			int bitmap_height = bmp.bmHeight;
			RECT rect;
			GetClientRect(hWnd, &rect);
			if (!isStreched)
				BitBlt(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top, hdcMem, 0, 0, SRCCOPY);
			else
			{
				SetStretchBltMode(hdc, HALFTONE);
				StretchBlt(hdc, 0, 0, rc.right, rc.bottom, hdcMem, 0, 0, bitmap_width, bitmap_height, SRCCOPY);
			}
			SelectObject(hdcMem, hOldBitmap);
			DeleteDC(hdcMem);
		}
		EndPaint(hWnd, &ps);
		return 0;
	}
	case WM_CREATE:
		SetTimer(BallHandler, 1, 50, NULL);
		break;
	case WM_DESTROY:
		PostQuitMessage(EXIT_SUCCESS);
		break;
	case WM_MOUSEMOVE:
		POINT mousePos;
		RECT rc;
		GetClientRect(hWnd, &rc);
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);
		y_pos = mousePos.y - paddle_height / 2;
		if (mousePos.y + paddle_height / 2 <= rc.bottom && mousePos.y - paddle_height / 2 >= rc.top)
			MoveWindow(PaddleHandler, rc.right - paddle_width, y_pos, paddle_width, paddle_height, TRUE);
		return 0;
	case WM_COMMAND:
		command = LOWORD(wParam);
		switch (command)
		{
		case ID_FILE_NEWGAME:
		{
			ball_pos_x = 70;
			ball_pos_y = 70;
			if (ball_dx < 0)
				ball_dx = -ball_dx;
			if (ball_dy < 0)
				ball_dy = -ball_dy;
			missed = 0;
			not_missed = 0;
		}
		break;
		case ID_FILE_EXIT:
		{
			DestroyWindow(MainHandler);
			PostQuitMessage(EXIT_SUCCESS);
		}
		break;
		case ID_BACKGROUND_COLOR:
		{
			/*
			* https://www.functionx.com/visualc/controls/dlgcolor.htm	
			* https://learn.microsoft.com/en-us/windows/win32/api/commdlg/ns-commdlg-choosecolora-r1
			*/
			CHOOSECOLOR cc;
			static COLORREF acrCustClr[16];
			ZeroMemory(&cc, sizeof(cc));
			cc.lStructSize = sizeof(cc);
			cc.hwndOwner = hWnd;
			cc.lpCustColors = (LPDWORD)acrCustClr;
			cc.rgbResult = RGB(255, 255, 255);
			cc.Flags = CC_FULLOPEN | CC_RGBINIT;
			if (ChooseColor(&cc) == TRUE)
			{
				if (background_bitmap)
				{
					DeleteObject(background_bitmap);
					background_bitmap = NULL;
					CheckMenuItem(GetMenu(hWnd), ID_BACKGROUND_TILE, MF_BYCOMMAND & MF_CHECKED);
					CheckMenuItem(GetMenu(hWnd), ID_BACKGROUND_STRECH, MF_BYCOMMAND & MF_CHECKED);
					EnableMenuItem(GetMenu(hWnd), ID_BACKGROUND_TILE, MF_BYCOMMAND | MF_DISABLED);
					EnableMenuItem(GetMenu(hWnd), ID_BACKGROUND_STRECH, MF_BYCOMMAND | MF_DISABLED);
				}

				background_color = cc.rgbResult;
				InvalidateRect(hWnd, NULL, TRUE);
			}
			break;
		}
		case ID_HELP_ABOUT:
		{
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUT), hWnd, About);
		}
		break;
		case ID_BACKGROUND_BITMAP:
		{
			/*
			* https://stackoverflow.com/questions/8820484/win32-c-using-a-openfilename-and-displaying-a-bitmap-file
			* It gave me the idea how to use it properly
			*/
			EnableMenuItem(GetMenu(hWnd), ID_BACKGROUND_TILE, MF_BYCOMMAND | MF_ENABLED);
			EnableMenuItem(GetMenu(hWnd), ID_BACKGROUND_STRECH, MF_BYCOMMAND | MF_ENABLED);
			CheckMenuItem(GetMenu(hWnd), ID_BACKGROUND_TILE, MF_BYCOMMAND | MF_CHECKED);
			OPENFILENAME ofn = { 0 };
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hWnd;
			ofn.lpstrFilter = L"A bitmap file (*.bmp)\0*.bmp\0All Files (*.*)\0*.*\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFile = szFileName;
			ofn.nMaxFile = MAX_PATH;
			ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_READONLY | OFN_HIDEREADONLY;
			if (GetOpenFileName(&ofn) == TRUE)
			{
				background_bitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
				InvalidateRect(hWnd, NULL, TRUE);
			}
			return 0;
		}
		break;
		case ID_BACKGROUND_TILE:
		{
			if (isStreched)
			{
				CheckMenuItem(GetMenu(hWnd), ID_BACKGROUND_TILE, MF_BYCOMMAND | MF_CHECKED);
				CheckMenuItem(GetMenu(hWnd), ID_BACKGROUND_STRECH, MF_BYCOMMAND & MF_CHECKED);
				isStreched = false;
				InvalidateRect(hWnd, NULL, TRUE);
			}
		}
		break;
		case ID_BACKGROUND_STRECH:
		{
			if (!isStreched)
			{
				CheckMenuItem(GetMenu(hWnd), ID_BACKGROUND_TILE, MF_BYCOMMAND & MF_CHECKED);
				CheckMenuItem(GetMenu(hWnd), ID_BACKGROUND_STRECH, MF_BYCOMMAND | MF_CHECKED);
				isStreched = true;
				InvalidateRect(hWnd, NULL, TRUE);
			}
		}
		break;
	}
	case WM_TIMER:
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
LRESULT CALLBACK PaddleWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, message, wParam, lParam);
}

LRESULT CALLBACK BallWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT rc_main;
	RECT rc_paddle;
	RECT rc_ball;
	RECT temp;
	switch(message)
	{
	case WM_TIMER:
	{
		ball_pos_x += ball_dx;
		ball_pos_y += ball_dy;
		GetClientRect(GetParent(hWnd), &rc_main);
		GetWindowRect(PaddleHandler, &rc_paddle);
		GetWindowRect(BallHandler, &rc_ball);

		if (IntersectRect(&temp,&rc_paddle, &rc_ball)) // CHANGED HERE
		{
			if (ball_dx > 0)
				ball_dx = -ball_dx;
			not_missed++;
		}
		
		if (ball_pos_x <= 0 || ball_pos_x + ball_diam >= rc_main.right)
			ball_dx = -ball_dx;
		if (ball_pos_x + ball_diam >= rc_main.right)
			missed++;
		if (ball_pos_y <= 0 || ball_pos_y + ball_diam >= rc_main.bottom)
			ball_dy = -ball_dy;
		MoveWindow(hWnd, ball_pos_x, ball_pos_y, ball_diam, ball_diam, TRUE);
	}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) 
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return static_cast <INT_PTR>(TRUE);
		
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
		EndDialog(hDlg, LOWORD(wParam));
		return static_cast <INT_PTR>(TRUE);
		}
		break;
	}
	return static_cast <INT_PTR>(FALSE);
}