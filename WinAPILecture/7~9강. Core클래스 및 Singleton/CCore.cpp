#include "CCore.h"
#include "pch.h"

CCore::CCore()
{

}

CCore::~CCore()
{

}

// ������ �ϸ� S_OK(0), S_FALSE(1) E_FAIL(16���� ������)
int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	// �����찡 �����ϴ� �Լ� ��κ� return���� hr(long)
	// �̰ɷ� FAILED üũ �غ����
	//HRESULT hr = S_OK;
	// FAILED��ũ�� << ���ڰ� ������ true << �����ߴٴ� ��
	//if (FAILED(hr/*E_FAIL*/))
	//{

	//}

	m_hWnd = _hWnd;
	m_ptResoultion = _ptResolution;

	// ���� �ػ� ũ�⿡ �°� ������ ũ�� ����

	return S_OK;
}

void CCore::progress()
{

}