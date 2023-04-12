// 039강. 문자열 문제 풀이


#include <iostream>
int GetLength(const wchar_t* _String)
{
	int i = 0;
	while (true)
	{
		if (0 == _String[i])
		{
			break;
		}
		++i;
	}
	return i;
}
int StrCmp(const wchar_t* _Left, const wchar_t* _Right)
{
	int leftlen = GetLength(_Left);
	int rightlen = GetLength(_Right);

	int iLoop = leftlen;
	int iReturn = 0;

	if (leftlen < rightlen)
	{
		iLoop = leftlen;
		iReturn = -1;
	}
	else if(leftlen > rightlen)
	{
		iLoop = rightlen;
		iReturn = 1;
	}

	for (int i = 0; i < iLoop; i++)
	{
		if (_Left[i] < _Right[i])
		{
			return -1;
		}
		else if (_Left[i] > _Right[i])
		{
			return 1;
		}
	}

	return iReturn;
}
int main()
{
	wchar_t Test[10] = L"abc";
	wchar_t Big[10] = L"abd";
	wchar_t Small[10] = L"abb";

	printf_s("%d\n", StringCmp(Test, Test));
	printf_s("%d\n", StringCmp(Test, Big));
	printf_s("%d\n", StringCmp(Test, Small));
}