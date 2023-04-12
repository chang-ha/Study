// 037강. 문자열(3)

#include <iostream>
#include <wchar.h>

// 내가 만드는 wcslen
unsigned int GetLength(const wchar_t* _pStr)
{
	int i = 0;
	//while (true)
	//{
	//	wchar_t c = *(_pStr + i); // *(_pStr + i) == _pStr[i]
	//	if (0 == c) // 0 == '\0'
	//	{
	//		break;
	//	}
	//	++i;
	//}
	
	// 아래처럼 할 수도 있지만 의도파악이 힘듦 (가독성이 떨어짐)
	while ('\0' != _pStr[i])
	{
		++i;
	}
	return i;
}

int main()
{
	wchar_t szName[10] = L"Raimond";
	int iLen = wcslen(szName);

	iLen = GetLength(szName);
}
