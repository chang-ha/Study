#pragma once

typedef struct _tagNode
{
	// 구현되어야 할 것
	// 저장해야하는 데이터
	int iData;
	// 다음 노드의 주소
	_tagNode* pNextNode;
}tNode;

typedef struct _tagList
{
public:
	// 원소의 갯수를 알아야함
	int iCount;
	// 첫번째 노드의 주소값
	tNode* pHeadNode;
protected:

private:

}tLinkedList;

// 연결형 리스트 초기화
void InitList(tLinkedList* _pList);

// 연결형 리스트 데이터 추가
void PushBack(tLinkedList* _pList, int _iData);

// 연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* _pList);
