// 047강. 정렬 과제(Bubble Sort)


#include <iostream>
#include <Arr/Arr.h>
#include <time.h>
void BubbleSort(tArr* _tArr);

int main()
{
	printf_s("Before BubbleSort\n");
	tArr TestArr = {};
	InitArr(&TestArr);
	srand(time(nullptr));
	for (int i = 10; i > 0; --i)
	{
		int TempInt = rand() % 100;
		PushBack(&TestArr, TempInt);
		printf_s("%d\n", TempInt);
	}

	BubbleSort(&TestArr);
	printf_s("After BubbleSort\n");
	for (int i = 0; i < TestArr.iCount; i++)
	{
		printf_s("%d\n", TestArr.pInt[i]);
	}

	ReleaseArr(&TestArr);
}

void BubbleSort(tArr* _tArr)
{
	// 1. 1번째 원소와 2번째 원소를 비교
	// 2-1. 1번째 원소가 2번째 원소보다 크면 위치를 서로 변경
	// 2-2. 1번째 원소가 2번째 원소보다 작으면 현위치 그대로
	// 2-3. 1번째 원소가 3번째 원소보다 크면 위치를 서로 변경
	// 2-4. 1번째 원소가 3번째 원소보다 작으면 현위치 그대로...
	// 3. 1번째 원소가 n번째 원소와 비교...
	// 4. n-1번째 원소까지 비교 후 정렬

	if (_tArr->iCount <= 1)
	{
		return;
	}

	for (int i = 0; i < _tArr->iCount - 1; i++)
	{
		for (int i = 0; i < _tArr->iCount - 1 ; i++)
		{
			int* NowData = &_tArr->pInt[i];
			int* NextData = &_tArr->pInt[i + 1];
			if (*NowData > *NextData)
			{
				int temp = *NowData;
				*NowData = *NextData;
				*NextData = temp;
			}
			else if (*NowData <= *NextData)
			{
				continue;
			}
		}
	}
}