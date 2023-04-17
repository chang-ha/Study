#include "Arr.h"
#include <iostream> // malloc�� ����

void InitArr(tArr* _pArr)
{
	_pArr->iCount = 0;
	_pArr->iMaxCount = 2;
	_pArr->pInt = (int*)malloc(sizeof(int)*2);
}

void ReleaseArr(tArr* _pArr)
{
	// �Ҵ��� �� �޸� ����
	free(_pArr->pInt);
	_pArr->iCount = 0;
	_pArr->iMaxCount = 0;
}

void PushBack(tArr* _pArr, int _iData)
{
	// �� ������ �Ҵ��� ������ �� ��
	if (_pArr->iMaxCount <= _pArr->iCount)
	{
		// �������� ������ ���Ҵ�
		Reallocte(_pArr);
	}

	// ������ �߰�
	_pArr->pInt[_pArr->iCount++] = _iData;
}

void Reallocte(tArr* _pArr)
{

}

