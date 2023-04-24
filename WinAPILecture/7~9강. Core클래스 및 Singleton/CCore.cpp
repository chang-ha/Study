#include "CCore.h"
#include "pch.h"

CCore::CCore()
{

}

CCore::~CCore()
{

}

// 성공을 하면 S_OK(0), S_FALSE(1) E_FAIL(16진수 음수값)
int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	// 윈도우가 제공하는 함수 대부분 return값이 hr(long)
	// 이걸로 FAILED 체크 해보라고
	//HRESULT hr = S_OK;
	// FAILED매크로 << 인자가 음수면 true << 실패했다는 뜻
	//if (FAILED(hr/*E_FAIL*/))
	//{

	//}

	m_hWnd = _hWnd;
	m_ptResoultion = _ptResolution;

	// 들어온 해상도 크기에 맞게 윈도우 크기 조정

	return S_OK;
}

void CCore::progress()
{

}