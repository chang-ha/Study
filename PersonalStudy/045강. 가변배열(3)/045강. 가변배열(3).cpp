// 044강. 가변배열(3)


#include <iostream>
#include "Arr.h"
int main()
{
	tArr s0 = {};

	InitArr(&s0);

	for (int i = 0; i < 10; i++)
	{
		PushBack(&s0, i);
	}

	for (int i = 0; i < s0.iCount; i++)
	{
		printf_s("%d", s0.pInt[i]);
	}

	ReleaseArr(&s0);
}