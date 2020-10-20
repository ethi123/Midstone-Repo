// (windows.h)
//#include "WindowsMessageMap.h"
//
//LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static WindowsMessageMap mm;
//	OutputDebugString(mm(msg, lParam, wParam).c_str());
//
//
//	switch (msg) //Use switch for future use when processing many different messages
//	{
//	case WM_CLOSE:
//		PostQuitMessage(99);
//		break;
//	case WM_KEYDOWN:
//		switch (wParam)
//		{
//		case VK_F1:
//			SetWindowText(hWnd, "1D Perlin Noise"); //https://docs.microsoft.com/en-us/windows/win32/inputdev/using-keyboard-input
//			break;
//		case VK_F2:
//			SetWindowText(hWnd, "2D Perlin Noise");
//			break;
//		case VK_F3:
//			SetWindowText(hWnd, "Terrain Generation");
//			break;
//		}
//	}
//	return DefWindowProc(hWnd, msg, wParam, lParam);
//}
//
//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
//
//
//{
//	const auto pClassName = "GameEngine";
//
//	//register window class
//	//LINK https://docs.microsoft.com/en-us/windows/win32/api/winuser/ns-winuser-wndclassexa
//	WNDCLASSEXA wc = { 0 };
//	wc.cbSize = sizeof(wc);
//	wc.style = CS_OWNDC;
//	wc.lpfnWndProc = WndProc; //Doesnt Assume (Will Close Window But Not App, good for multiple windows)
//	wc.cbClsExtra = 0;
//	wc.cbWndExtra = 0;
//	wc.hInstance = hInstance;
//	wc.hIcon = nullptr;
//	wc.hCursor = nullptr;
//	wc.hbrBackground = nullptr;
//	wc.lpszMenuName = nullptr;
//	wc.lpszClassName = pClassName; //Error Explanation 9823675.png
//	wc.hIconSm = nullptr;
//	RegisterClassExA( &wc);
//
//	//create window instance
//	HWND hWnd = CreateWindowEx(
//		0, pClassName,
//		"Engine",
//		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
//		200, 200, 640, 480,
//		nullptr, nullptr, hInstance, nullptr
//	);
//
//	//show window
//	ShowWindow(hWnd, SW_SHOW);


#include "WCSM.h"
#include "WindowsMessageMap.h" 

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	try
	{
		Window wnd( 800, 300, "Game Engine"); //Create Instance/s

		//message pipe
		MSG msg;
		BOOL gResult;
		while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) //-1 = no message/error
		{
			TranslateMessage(&msg); //For WM_Char
			DispatchMessage(&msg);
		}

		if (gResult == -1)
		{
			return -1;
		}
		else {
			return msg.wParam;
		}
	}
	catch(const hException& e)
	{ 
		MessageBox(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception & e)
	{
		MessageBox(nullptr, e.what(), "Standard Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...)
	{
		MessageBox(nullptr, "No details available", "Unkown Exception",MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}