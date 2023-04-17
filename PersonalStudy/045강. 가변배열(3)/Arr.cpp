#include "Arr.h"
#include <iostream>

void InitArr(tArr* _pArr)
{
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
	_pArr->pInt = (int*)malloc(sizeof(int) * 2);
}

void ReleaseArr(tArr* _pArr)
{
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void PushBack(tArr* _pArr, int _iData)
{
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		Reallocte(_pArr);
	}
	_pArr->pInt[_pArr->iCount++] = _iData;
}

void Reallocte(tArr* _pArr)
{
	// malloc()함수의 작동원리
	// malloc(40)을하면 40바이트를 힙영역 어딘가에 할당해줌
	// 내가 원하는 곳에 할당받을수 있나??? XX
	// Heap Corruption힙영역의 잘못된 주소에 접근하여 메모리를 손상시키는 현상 << 포인터를 잘못썻기 때문에 나오는 오류

	// 내가 8바이트를 할당받고 있다가 
	// 그 뒤에 8바이트를 더 할당받을 수 있을까?? XX
	//    << 한번에 16바이트 공간을 할당 받아야함

	// 2배씩 공간을 늘린다고 가정
	// 1. 힙공간을 할당받은 주소를 지역변수(임시)로 받아놓기
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));

	// 2. 기존 공간에 있던 데이터를을 새로 할당한 공간으로 복사한다
	for (int i = 0; i < _pArr->iCount; i++)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. 기존 공간은 메모리 해제
	free(_pArr->pInt);

	// 4. 배열이 새로 할당된 공간을 가리키게 한다.
	_pArr->pInt = pNew;

	// 5. MaxCount 변경점 적용
	_pArr->iMaxCount *= 2;
}

