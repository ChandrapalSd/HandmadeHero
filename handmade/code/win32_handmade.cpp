#include <windows.h>


LRESULT CALLBACK
MainWindowCallback(HWND Window, UINT Message, WPARAM WParam, LPARAM LParam)
{
	LRESULT Result = 0;
	switch (Message)
	{
		case WM_SIZE:
		{
			OutputDebugStringA("WN_SIZE\n");
		} break;

		case WM_DESTROY:
		{
			OutputDebugStringA("WM_DESTROY\n");
		} break;

		case WM_CLOSE:
		{
			OutputDebugStringA("WM_CLOSE\n");
		} break;

		case WM_ACTIVATEAPP:
		{
			OutputDebugStringA("WM_ACTIVATEAPP\n");
		} break;

		case WM_PAINT:
		{
			OutputDebugStringA("WM_PAINT\n");
			PAINTSTRUCT paint;

			HDC DeviceContext = BeginPaint(Window, &paint);

			int X = paint.rcPaint.left;
			int Y = paint.rcPaint.top;
			int Height = paint.rcPaint.bottom - paint.rcPaint.top;
			int Width = paint.rcPaint.right - paint.rcPaint.left;

			static DWORD Operation = WHITENESS;
			PatBlt(DeviceContext, X, Y, Width, Height, Operation);

			if (Operation == WHITENESS)
			{
				Operation = BLACKNESS;
			}
			else
			{
				Operation = WHITENESS;
			}

			EndPaint(Window, &paint);
		} break;

		default:
		{
			Result = DefWindowProcA(Window, Message, WParam, LParam);
			//OutputDebugStringA("default\n");
		} break;

	}

	return Result;
}

int CALLBACK WinMain(HINSTANCE Instance, HINSTANCE PrevInstance, LPSTR CommandLine, int ShowCode)
{

	WNDCLASS WindowClass = {};


	WindowClass.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	WindowClass.lpfnWndProc = MainWindowCallback;
	WindowClass.hInstance = Instance;
	//WindowClass.hIcon;
	WindowClass.lpszClassName = "HandmadeHeroWindowClass";

	if (RegisterClassA(&WindowClass)) 
	{
		HWND WindowHandle = CreateWindowExA(
			0,
			WindowClass.lpszClassName,
			"Handmade Hero",
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			0,
			0,
			Instance,
			0);

		if (WindowHandle)
		{
			MSG Message;

			for (;;)
			{
				BOOL MessageResult = GetMessageA(&Message, 0, 0, 0) != WM_QUIT;
				if(MessageResult > 0)
				{
					TranslateMessage(&Message);
					DispatchMessageA(&Message);	
				}
				else
				{
					break;
				}
			}
			
		}
		else
		{
			//TODO Log message
		}

	}
	else
	{
		//TODO Log message
	}

	return 0;
}