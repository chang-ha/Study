// 1~2강. Win32API기본
//

#include "framework.h"
#include "1~2강. Win32API기본.h"

#define MAX_LOADSTRING 100

// WCHAR << wchar_t 이름을 재정의 한 것
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다. << wchar_t[100]짜리 배열 선언
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다. << wchar_t[100]짜리 배열 선언

// 함수 전방선언 해 둔 것
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 여기가 WinAPI에서의 Main함수
// _In_처럼 보라색인 글자 << 어떤 지역변수 앞에 해당 변수의 의미(용도)를 적어놓은 것 == "SAL"이라고 부름 (소스코드주석언어) << 크게 알필요 없음
// _In_ : 데이터가 함수에 입력이 된다
// _In_opt_ : opt(optional) == 부가적으로 들어온 변수이다. (딱히 필수는 아닌??)

// hInstance : 프로세스가 시작되는 메모리 주소

// hPrevInstance : 나보다 이전에 실행된 프로세스의 시작 주소 << 내가 만든 프로그램을 여러 개 동시에 실행할 수 있으니까
                // << 초창기버전의 window의 잔재같은 느낌 << 지금 Window는 내가 같은 프로그램을 여러 개 실행해도 hInstance가 같은 값이 나옴
                // ??? 이것은 마치 int를 여러 개 선언했는데 다 주소값이 같다는 것과 같은 의미
                // 왜 이런 현상이 일어나냐?? Windows가 가상메모리라는 시스템을 쓰기 때문임 << 자기만의 가상메모리의 주소를 지칭하는 것
                //                          << 각 프로세스마다의 0번지는 물리적(실제) 주소는 다르지만, 프로세스 관점에서는 0번지는 시작지점을 의미하는 것임

// lpCmdLine(문자열(wchar_t)* 타입) : 커맨드 라인 << 우리가 프로그램을 시작할 떄 문자열 같은 것을 넣어줄 수 있음 << 우리가 프로그램을 윈도우 명령 프롬프트로 실행할 떄 들어오는 문자열
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    // UNREFERENCED_PARAMETER << 참조되지 않은 변수입니다
    // 아래 두녀석은 딱히 중요한 인자가 아니라는것을 알려주는 것 
    // 별로 안쓰이니까 신경쓰지마~
    UNREFERENCED_PARAMETER(hPrevInstance); // == hPrevInstance << 어떤 인자를 넣어주면 그냥 그대로 다시 나오는 매크로...(변수를 아무 의미없이 적은 것) << 이게 뭐야 
    UNREFERENCED_PARAMETER(lpCmdLine); // == ipCmdLine

    // szTitle << 프로그램 실행될 떄 프로그램의 Title(제목) << 해당값은 리소스 뷰에가면 볼 수 있음 (수정도 가능??)
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY12WIN32API, szWindowClass, MAX_LOADSTRING);

    // 윈도우 정보 등록 << 윈도우를 띄우기 전에 어떤 형태로 윈도우(창)을 띄울것인지 정보를 등록하는 곳
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    // 여기서 윈도우(창)를 생성
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // 단축키 테이블 << 리소스뷰의 Accelerator에 보면 있음
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY12WIN32API));

    MSG msg;

    // 기본 메시지 루프입니다: << 무한 반복문을 돌고 있음
    // 단축키 테이블에 등록되어 있는 키가 눌리면 확인해주는 부분
    // GetMessage << 현재 포커싱중인 프로그램쪽으로 발생한 메시지큐를 꺼내보는 함수(나한테 도착한 메시지가 있나???)
    // 내 의견 << 메시지 : 마우스 클릭이나 키보드로 누른 키 등... 내가 활동한 내용??? 그런 것인듯
    // &msg << 발생한 메시지를 MSG구조체에 채우려고 주소값으로 받음
    // msg.hwnd << 해당 메시지가 발생한 Window를 의미하는 것
    // 하나의 프로세스 안에서 창을 여러개 만들 수 있음

    // GetMessage의 중요 특징
    // 메시지 큐에서 메시지가 없으면 함수가 종료되지 않고, 메시지를 확인할 떄 까지 대기
    // GetMessage가 false를 리턴하면 while문이 실패를 하게 됨 << 이 프로그램이 종료됨
    // 언제 GetMessage가 false를 리턴할까??? 
    // msg.message의 type이 msg.message == WM_QUIT 일때 false를 반환
    // WM_QUIT이 메시지큐에 있었단 뜻은 우리가 실행하던 프로그램의 Window가 다 꺼지고 이제 프로그램이 안전하게 종료되어도 된다는 의미
    // 그래서 WM_QUIT이 발생하기 전에 Window들이 종료하는 메시지들이 발생한다는 뜻(다 완료되어야 WM_QUIT이 발생)
    // 우리가 사용하는 프로그램들은 메시지가 없으면 작동하지 않는 방식으로 설계되어 있고
    // 해당 메시지들을 처리하는 방식으로 작동하고 있음(메시지반응형)
    // 그래서 해당 방식은 우리가 게임클라이언트로 작동하기에는 부적합함 << 그래서 기본제공 구조를 고칠것임
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        // 윈도우가 종료된다고 판단되면 While문이 종료되면서 Main함수가 종료되는 구조임
        // 그렇다고 프로세스 == Window???XXXXXXXXXX 프로세스 != Window << 백그라운드에서 실행되는 프로세스들도 많이 있음
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



ATOM MyRegisterClass(HINSTANCE hInstance)
{
    // WindowClass확장
    // 해당 구조체들의 멤버를 채우고 있음
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY12WIN32API));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY12WIN32API);  // 윈도우창의 메뉴바 (nullptr)로 세팅하면 메뉴바를 사용하지 않겠다는 뜻임
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    // 결국 윈도우에서 제공하는 함수를 쓰고 있음(내부코드는 볼 수 없음)
    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    // Main함수가 실행할 떄 받았던 인자인 hInstance를 전역변수인 hInst가 받음
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
            // 윈도우 헨들 << 
            // 윈도우 좌표값 << (0,0)은 윈도우창의 좌상단, 1단위는 1픽셀단위
            // 윈도우DC(HDC)
            Rectangle(hdc, 10, 10, 110, 110);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
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
