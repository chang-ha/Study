// 038강. 문자열(4)


#include <iostream>
#include <wchar.h>
#include <assert.h>
// 함수 오버로딩 (클래스의 "함수 오버라이딩"이랑 헷갈리지 말자)
void Test()
{

}

void Test(int _a)
{

}

void Test(float _a)
{

}

int GetLength(const wchar_t* _pStr)
{
	int i = 0;
	while (true)
	{
		wchar_t c = _pStr[i];
		if (0 == c)
		{
			break;
		}
		++i;
	}
	return i;
}

// 문자열 이어붙이기 함수
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
	int iDestLen = GetLength(_pDest);
	int iSrcLen = GetLength(_pSrc);
	if (_iBufferSize < iDestLen + iSrcLen + 1 ) // null문자까지 계산해서 + 1
	{
		assert(nullptr);
	}

	// 만들어야 할 것(해야할 일)
	// 1. Dest 문자열의 끝을 확인 (문자열이 이어 붙일 시작 위치)
	// 2. 반복적으로 Src 문자열을 Dest 끝 위치에 복사하기
	// 3. Src 문자열의 끝을 만나면 반복 종료

	// 1.
	iDestLen; // 해당 인덱스가 Dest 문자열의 null 문자위치

	// 2, 3.
	for (int i = 0; i < iSrcLen + 1; i++) // iSrcLen + 1 인 이유는 null 문자도 문자열에 넣어야 해서 
	{
		_pDest[iDestLen + i] = _pSrc[i];
	}
}

int main()
{
	wchar_t szStirng[100] = L"abc";
	wchar_t szStirng1[100] = L"abc";

	// 인자 3개
	// 인자 1. 이어붙여질 문자열 (목적지)
	// 인자 2. 이어붙일 문자열의 최대 크기 (목적지배열의 크기)
	// 인자 3. 이어붙일 문자열
	wcscat_s(szStirng, 100, L"def");
	wcscat_s(szStirng, 100, L"ghi");

	StrCat(szStirng1, 100, L"def");

	// wcscmp는
	// 두개의 문자열을 전달받아서
	// 양쪽 문자열의 상태를 비교체크하는 함수
	// 두 문자열이 완벽히 일치하면 0
	// 왼쪽 문자열이 우열이 높으면 -1
	// 오른쪽 문자열이 우열이 높으면 1
	// ** 우열이 높다는 뜻은 사전적으로 a b c 순서...
	// wcscmp();

	printf_s("%d", wcscmp(L"abc", L"abca"));
}
