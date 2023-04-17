// 047강. 정렬 과제풀이 정답


#include <iostream>
#include <Arr/Arr.h>
#include <time.h>

void Sort(tArr* _pArr)
{
	if (_pArr->iCount <= 1)
	{
		return;
	}

	while (true)
	{
		bool bFinish = true;
		int iLoop = _pArr->iCount - 1;
		for (int i = 0; i < iLoop; i++)
		{
			if (_pArr->pInt[i] > _pArr->pInt[i + 1])
			{
				int iTemp = _pArr->pInt[i];
				_pArr->pInt[i] = _pArr->pInt[1];
				_pArr->pInt[i + 1] = iTemp;
				bFinish = false;
			}
		}

		if (false == bFinish)
		{
			break;
		}
	}
}
int main()
{
	tArr s1 = {};
	InitArr(&s1);

	// 난수(랜덤)
	srand(time(nullptr));
	for (int i = 0; i < 10; i++)
	{
		int iRand = rand() % 100 + 1;
		PushBack(&s1, iRand);
		printf_s("%d\n", iRand);
	}

	Sort(&s1);
	ReleaseArr(&s1);
}