#pragma once

typedef struct _tagNode
{
	// �����Ǿ�� �� ��
	// �����ؾ��ϴ� ������
	int iData;
	// ���� ����� �ּ�
	_tagNode* pNextNode;
}tNode;

typedef struct _tagList
{
public:
	// ������ ������ �˾ƾ���
	int iCount;
	// ù��° ����� �ּҰ�
	tNode* pHeadNode;
protected:

private:

}tLinkedList;

// ������ ����Ʈ �ʱ�ȭ
void InitList(tLinkedList* _pList);

// ������ ����Ʈ ������ �߰�
void PushBack(tLinkedList* _pList, int _iData);

// ������ ����Ʈ �޸� ����
void ReleaseList(tLinkedList* _pList);
