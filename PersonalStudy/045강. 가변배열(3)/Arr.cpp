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
	// malloc()�Լ��� �۵�����
	// malloc(40)���ϸ� 40����Ʈ�� ������ ��򰡿� �Ҵ�����
	// ���� ���ϴ� ���� �Ҵ������ �ֳ�??? XX
	// Heap Corruption�������� �߸��� �ּҿ� �����Ͽ� �޸𸮸� �ջ��Ű�� ���� << �����͸� �߸����� ������ ������ ����

	// ���� 8����Ʈ�� �Ҵ�ް� �ִٰ� 
	// �� �ڿ� 8����Ʈ�� �� �Ҵ���� �� ������?? XX
	//    << �ѹ��� 16����Ʈ ������ �Ҵ� �޾ƾ���

	// 2�辿 ������ �ø��ٰ� ����
	// 1. �������� �Ҵ���� �ּҸ� ��������(�ӽ�)�� �޾Ƴ���
	int* pNew = (int*)malloc(_pArr->iMaxCount * 2 * sizeof(int));

	// 2. ���� ������ �ִ� �����͸��� ���� �Ҵ��� �������� �����Ѵ�
	for (int i = 0; i < _pArr->iCount; i++)
	{
		pNew[i] = _pArr->pInt[i];
	}

	// 3. ���� ������ �޸� ����
	free(_pArr->pInt);

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	_pArr->pInt = pNew;

	// 5. MaxCount ������ ����
	_pArr->iMaxCount *= 2;
}

