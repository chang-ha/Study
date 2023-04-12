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
int StringCmp(const wchar_t* _String1, const wchar_t* _String2)
{
	int StringLength1 = GetLength(_String1);
	int StringLength2 = GetLength(_String2);
	int Result = 0;
	int i = 0;

	do
	{
		Result = _String1[i] - _String2[i];
		++i;
		if (i > StringLength1 || i > StringLength2)
		{
			break;
		}
	} while (Result == 0);

	if (Result > 0)
	{
		return 1;
	}
	else if (Result < 0)
	{
		return -1;
	}
	else if (Result == 0)
	{
		return 0;
	}
}
int main()
{
	wchar_t Test[10] = L"abc";
	wchar_t Big[10] = L"abcdb";
	wchar_t Small[10] = L"ab";

	printf_s("%d\n", StringCmp(Test, Test));
	printf_s("%d\n", StringCmp(Test, Big));
	printf_s("%d\n", StringCmp(Test, Small));
}