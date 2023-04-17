#include "Arr.h"
#include <iostream> // malloc을 위해

void InitArr(tArr* _pArr)
{
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
	_pArr->pInt = (int*)malloc(sizeof(int)*2);
}

void ReleaseArr(tArr* _pArr)
{
	// 할당한 힙 메모리 해제
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void PushBack(tArr* _pArr, int _iData)
{
	// 힙 영역에 할당한 공간이 다 참
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		// 힙영역의 공간을 재할당
		Reallocte(_pArr);
	}

	// 데이터 추가
	_pArr->pInt[_pArr->iCount++] = _iData;
}

void Reallocte(tArr* _pArr)
{

}

