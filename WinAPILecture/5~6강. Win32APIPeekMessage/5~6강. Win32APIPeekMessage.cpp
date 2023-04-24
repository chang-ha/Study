// 5~6강. Win32APIPeekMessage
// 지난 강의에서 보여준 코딩스타일의 문제점
// 물체가 많이 존재하면??? 각 물체마다 물체의 좌표와 크기정보가 있어야함
// 그리고 작업이 굉장히 반복적으로 수행되어야함 (모든 물체들중 하나라도 조금의 변화가 생기면 전부 지우고 다시 그려야함)




#include "framework.h"
#include "5~6강. Win32APIPeekMessage.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);



ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY56WIN32APIPEEKMESSAGE));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_MY56WIN32APIPEEKMESSAGE);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_MY56WIN32APIPEEKMESSAGE, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY56WIN32APIPEEKMESSAGE));

	MSG msg;

	// 메세지 기반 처리방식은 굉장히 비효율적임
	// 그래서 최대한 이용하지 않는 방식으로 구조를 변경할 것임
	// 현재 구조를 사용할 수 밖에 없는 이유는 GetMessage()함수 때문
	// GetMessage는 Message큐에서 메세지를 꺼내오는데 메세지가 들어올 떄 까지 대기상태로 있음(프로그램이 멈춰있음)
	// 그래서 구조를 바꾸기 위해 메세지가 있던 없던 반환을 하는 함수를 사용할 것임
	// PeekMessage(); // 메세지를 보다 << 메세지큐에 메세지가 있던 없던 대기할 이유가 없음(메세지를 가져오는게 아님)
	// 인자가 하나 늘어남 << 확인한 메세지가 있을 경우 해당 메세지를 제거할지 말지 결정하는 인자
	// PeekMessage << 메세지 유무와 관계없이 반환
	while (true)
	{
		// 메세지가 있으면 true, 메세지가 없으면 false 를 반환
		// 꺼내온 메세지가 있어야 어떤 일을 처리할 수 있기 떄문에 if문의 조건으로 사용
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			// 만약 들어온 메세지가 WM_QUIT이면 while문 탈출
			if (WM_QUIT == msg.message)
			{
				break;
			}
			// 메세지가 들어오면 아래 함수들을 처리
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		// 99%이상은 메세지가 발생하지 않는 시간임
		else
		{
			// 메세지가 없는동안 호출 
			// 여기서 GameCode를 수행할 것임
			// 디자인 패턴 (설계를 하는 유형) << 알면 좋긴한데 상황에 따라 다름 (굳이 다 알아야 하나....?)
			// 그치만 꼭 알아야 하는 것 << 싱글톤 패턴 (너무 기본설계 유형임)
		}
	}

	return (int)msg.wParam;
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance;

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

struct tObjInfo
{
	POINT g_ptObjPos;
	POINT g_ptObjScale;
};

#include <vector>

std::vector<tObjInfo> g_vecInfo;

// 좌상단으로 설정할 데이터(Left Top)
POINT g_ptLT;

// 우하단으로 설정할 데이터(Right Bottom)
POINT g_ptRB;

bool bLbtnDown = false;

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
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// 벡터에 저장할 사각형을 그림(미리보기 느낌)
		if (bLbtnDown)
		{
			Rectangle(hdc
				, g_ptLT.x
				, g_ptLT.y
				, g_ptRB.x
				, g_ptRB.y);
		}

		// 벡터에 추가된 사각형들을 그려줌
		for (size_t i = 0; i < g_vecInfo.size(); i++)
		{
			Rectangle(hdc
				, g_vecInfo[i].g_ptObjPos.x - g_vecInfo[i].g_ptObjScale.x / 2
				, g_vecInfo[i].g_ptObjPos.y - g_vecInfo[i].g_ptObjScale.y / 2
				, g_vecInfo[i].g_ptObjPos.x + g_vecInfo[i].g_ptObjScale.x / 2
				, g_vecInfo[i].g_ptObjPos.y + g_vecInfo[i].g_ptObjScale.y / 2);
		}

		// 벡터에 추가되는 물체가 늘어나면 늘어날수록 화면의 깜빡임이 심함
		// 왜 그럴까???
		// 사람이 인지하지 못하는 순간에 컴퓨터가 사각형을 계속 그렸다 지웠다 반복하는데
		// 컴퓨터가 사각형을 그리던 중에 사람이 인지해서 어떨때는 사각형이 몇 개 없는 것으로 보이기도 하고
		// 어떨때는 사각형이 전부 그려진 순간을 인지해서 전부 있는것처럼 보이고
		// 이러한 인지차이때문에 계속 깜빡이는걸로 보임

		// 이러한 현상은 어떻게 해결하는가??
		// 우리가 그릴 윈도우 창의 픽셀데이터를 2개를 관리할 것임 (현재 그림을 그리는 창이 1개임)
		// 이유 : 사각형을 전부 그린 창을 사용자에게 보여주면 그리는 과정을 보지 못하므로 깜빡임이 없다고 느낌
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
	{
		g_ptLT.x = LOWORD(lParam);
		g_ptLT.y = HIWORD(lParam);
		bLbtnDown = true;
	}
	break;
	case WM_MOUSEMOVE:
		g_ptRB.x = LOWORD(lParam);
		g_ptRB.y = HIWORD(lParam);
		InvalidateRect(hWnd, nullptr, true);
		break;
	case WM_LBUTTONUP: // LBUTTON에서 손을 뗄 때
	{
		 tObjInfo info = {};
		info.g_ptObjPos.x = (g_ptLT.x + g_ptRB.x) / 2;
		info.g_ptObjPos.y = (g_ptLT.y + g_ptRB.y) / 2;

		info.g_ptObjScale.x = abs(g_ptLT.x - g_ptRB.x);
		info.g_ptObjScale.y = abs(g_ptLT.y - g_ptRB.y);

		g_vecInfo.push_back(info);
		bLbtnDown = false;
		InvalidateRect(hWnd, nullptr, true);
	}
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
