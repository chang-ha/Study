#pragma once

typedef struct _tabArr
{
public:
	int* pInt; // �����͸� �����ų ���� �����ּҸ� �˾ƾ� ��
	int iCount; // ���� �����͸� �־���� ��Ҹ� �˾ƾ� �ϴ�, �� ���� �����͸� ������ �ִ��� �˾ƾ���
	int iMaxCount;
protected:

private:

}tArr;

// �迭�� �ʱ�ȭ �Լ�
// ���Ǻ� ����� ����Ű
// Ctrl + . (Ű�е� .�� ����) or Alt + enter
void InitArr(tArr* _pArr);

// �迭�� �޸�(������) ���� �Լ�
void ReleaseArr(tArr* _pArr);

// �����͸� �־��ִ� �Լ�
void PushBack(tArr* _pArr, int _iData);

// �������� ������ ���Ҵ��ϴ� �Լ�
void Reallocte(tArr* _pArr);