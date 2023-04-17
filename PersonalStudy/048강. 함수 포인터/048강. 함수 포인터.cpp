// 048강. 함수 포인터


#include <iostream>
#include <time.h>
#include <Arr/Arr.h>
//void BubbleSort(int* _pData, int _iCount)
//{
//	if (_iCount <= 1)
//	{
//		return;
//	}
//
//	while (true)
//	{
//		bool bFinish = true;
//		int iLoop = _iCount - 1;
//		for (int i = 0; i < iLoop; i++)
//		{
//			if (_pData[i] > _pData[i + 1])
//			{
//				int iTemp = _pData[i];
//				_pData[i] = _pData[i + 1];
//				_pData [i + 1] = iTemp;
//				bFinish = false;
//			}
//		}
//
//		if (false == bFinish)
//		{
//			break;
//		}
//	}
//}

void Test(void)
{

}

int main()
{
	// 반환타입이 void, 인자가 void인 함수를 받는 *pFunc
	void(*pFunc)(void) = nullptr;
	pFunc = Test;
	// pFunc(); << Test함수를 호출한다는 뜻

	tArr s1 = {};
	InitArr(&s1);
	srand(time(nullptr));
	for (int i = 0; i < 10; i++)
	{
		int iRand = rand() % 10 + 1;
		PushBack(&s1, iRand);
	}

	// 변수의 주소뿐만 아니라 함수의 주소도 얻어올 수 있다
	// 아래와 같은 기능(함수)를 인자로 넣고 싶음
	// int iArr[10] = {87, 644, 21, 55, 879, 654, 55, 131};
	// BubbleSort(iArr, 10);

	// 함수를 인자로 넣을때는 &를 붙여도 되고 안붙여도 됨
	Sort(&s1, &BubbleSort);
	

	ReleaseArr(&s1);
}