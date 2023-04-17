#include "Arr.h"
#include <iostream>

void BubbleSort(int* _pData, int _iCount)
{
	if (_iCount <= 1)
	{
		return;
	}

	while (true)
	{
		bool bFinish = true;
		int iLoop = _iCount - 1;
		for (int i = 0; i < iLoop; i++)
		{
			if (_pData[i] > _pData[i + 1])
			{
				int iTemp = _pData[i];
				_pData[i] = _pData[i + 1];
				_pData[i + 1] = iTemp;
				bFinish = false;
			}
		}

		if (false == bFinish)
		{
			break;
		}
	}
}

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
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));

	for (int i = 0; i < _pArr->iCount; i++)
	{
		pNew[i] = _pArr->pInt[i];
	}
	free(_pArr->pInt);

	_pArr->pInt = pNew;

	_pArr->iMaxCount *= 2;
}

void Sort(tArr* _pArr, void(*SortFunc)(int*, int))
{
	SortFunc(_pArr->pInt, _pArr->iCount);
}

