// 3~4강. Win32API 핸들, DC, 윈도우 이벤트


#include "framework.h"
#include "3~4강. Win32API 핸들, DC, 윈도우 이벤트.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MY34WIN32APIDC, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY34WIN32APIDC));

	MSG msg;

	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY34WIN32APIDC));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY34WIN32APIDC);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance;

	// 우리는 운영체제의 Kernel Object값들에 접근할 수 없음 (윈도우 창의 사이즈나 이런걸 임의 조작 불가능, 대부분이 커널오브젝트일것임)
	// 그래서 OS가 우리에게 프로그램이 실행되면 ID값을 하나 줌(어떤 규칙으로 만들어서 주는건 알 수 없음)
	// 이 ID값이 윈도우 핸들임(여러가지 종류가 있음 HWND, HDC 등등... 윈도우를 조작하는 느낌인듯???)
	// ID값으로(여기서는 hWnd) 함수를 통해 OS에 행동을 요청하는 것임
	// ex. 해당 프로그램의 창을 숨겨주세요 등...
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}


//전역변수 설정 (사각형이 키입력에 따라 움직이는 것 처럼 보이게 하기 위해)
POINT g_ptObjPos = { 500, 300 }; // 좌표정보
POINT g_ptObjScale = { 100, 100 }; // 크기정보

// wParam, lParam << message가 들어올 떄 부연적으로 들어오는 값들임
// ex. messsage가 마우스 클릭 << lParam에 마우스 좌표가 들어옴
// ex. messsage가 키 클릭 << wParam에 눌러진 키가 들어옴
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
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
	}
	break;
	case WM_PAINT: // Window의 무효화 영역(Invalidate Rect)이 발생한 경우 WM_PAINT를 발생시킴
		// 무효화 영역이란?? Window(창)을 완전히 최소화 했다가 킬 떄
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps); // Device Context(그리기 관련 커널 오브젝트)를 만들어서 ID값을 얻어온 것임
		// HDC나 HWND 이런 윈도우 핸들들은 안에 int값 하나를 들고있는 구조체에 불과함 (결국 ID값 하나를 받기위한 구조체(자료형)임)
		// 왜 이렇게 구조체로 나눠놨을까?? 그냥 ID를 받는 구조체로 통일해버리면
		// 1. 지금 내가 받은 ID가 무엇을 위한 ID인지 알 수 없음....(그리기위한 ID인지, 창을 띄우기 위한 ID인지...)
		// 2. 함수의 인자로 사용할 떄 실수로 다른 ID를 넣을수도 있음 (창을 띄우는 ID를 넣어야 하는데 펜을 담당하는 ID를 넣어버릴 수 있음) << 구조체명이 다르면 문법적으로 걸림
		// 그래서 맨 앞에 H가 붙어있으면 다 Handle형태의 자료형이라는 뜻임

		// Device Context << 그리기 작업, 렌더링 등 작업에 필요한 Data의 집합 
		// Window에 무언가를 그리려면 무조건 Device Context를 써야함

		// HDC hdc = BeginPaint(hWnd, &ps); 
		// DC의 목적지는 hWnd
		// DC의 펜은 Default값(검은색)
		// DC의 브러쉬는 Default값(하얀색)

		// 직접 Pen을 만들어서 DC에 제공
		// 함수 인자로는 무엇을 넣어야할까??? MSDN에 검색해보자(모든 함수를 외우기는 불가능)
		HPEN hRedPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0)); // 커널오브젝트를 만들었으니 받아야함 (HPEN, 윈도우핸들로)

		// CreateBrush도 있지만 우리가 자주 쓰는 펜이나 브러쉬는 만들어 놓은게 있음 << 이런 애들은 오히려 삭제하면 안됨 
		// HBRUSH hBlueBrush = GetStockObject();

		// 혹은 CreateSolidBrush()라는 함수도 있음 << 컬러만 지정해 주면 됨
		HBRUSH hBlueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// 이제 내가 만든 펜으로 그림을 그리고 싶으니
		// DC에 내가 그린 펜의 정보를 줘야함

		// DC한테 내가 만든 hRedPen을 준 것임
		// SelectObject(hdc, hRedPen);

		// 그럼 원래 들고있던 펜은...?? 어떻게
		// 함수의 return으로 돌려줌

		// HPEN DefaultPen = SelectObject(hdc, hRedPen);
		// 근데 자료형이 HPEN이면 오류 발생함
		// HGDIOBJ자료형으로 받아야한데 << 그냥 void* 타입임
		// return값이 void*형이니까 내가 casting 해줘야함
		// 왜 이렇게 작동하냐?? 범용적인 함수이기 때문에 어떤 자료형이 올 지 모름 그래서 void*로 받고 void*로 반환함
		HPEN hDefaultPen = (HPEN)SelectObject(hdc, hRedPen);
		HBRUSH hDefaultBrush = (HBRUSH)SelectObject(hdc, hBlueBrush);

		Rectangle(hdc
			, g_ptObjPos.x - g_ptObjScale.x / 2
			, g_ptObjPos.y - g_ptObjScale.y / 2
			, g_ptObjPos.x + g_ptObjScale.x / 2
			, g_ptObjPos.y + g_ptObjScale.y / 2);
		// Rectangle(hdc, 10, 10, 100, 100);

		// 그리고 난 뒤에는 DefaultPen을 돌려줘야함
		SelectObject(hdc, hDefaultPen);
		SelectObject(hdc, hDefaultBrush);

		// 그리고 쓸모를 다한 RedPen은 삭제해야하는데
		// 삭제할때도 OS에 부탁해야함
		DeleteObject(hRedPen);
		DeleteObject(hBlueBrush);


		// TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
	{
		// lParam << __int64 (4바이트 정수)
		int x = LOWORD(lParam); // 마우스의 좌표는 값이 2개인데 어떻게 4바이트 안에 담을 수 있는가??? 2바이트로 나눠서 반은 X좌표 반은 Y좌표값 저장
		int y = HIWORD(lParam); // HIWORD는 Y좌표용(오른쪽으로 16비트 shift한 값 (>>) )
	}
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_UP:
			g_ptObjPos.y -= 10;
			InvalidateRect(hWnd, nullptr, true); // WM_PAINT가 발생하도록 InvalidateRect함수 사용
			break;
		case VK_DOWN:
			g_ptObjPos.y += 10;
			InvalidateRect(hWnd, nullptr, true);
			break;
		case VK_LEFT:
			g_ptObjPos.x -= 10;
			InvalidateRect(hWnd, nullptr, true);
			break;
		case VK_RIGHT:
			g_ptObjPos.x += 10;
			InvalidateRect(hWnd, nullptr, true);
			break;
		default:
			break;
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
