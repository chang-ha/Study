#include "LinkedList.h"
#include <iostream>
// LinkedList

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}
void PushBack(tLinkedList* _pList, int _iData)
{
	// 데이터를 저장할 노드를 생성
	// 데이터를 복사
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// 추가한 데이터가 처음인지 따져봐야함
	if (nullptr == _pList->pHeadNode) // 0 == _pList->iCount
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// 현재 가장 마지막 노드를 찾아서 
		// 해당 노드의 pNext를 현재 노드(pNode)의 주소로 채움
		tNode* pCurFinalNode = _pList->pHeadNode;
		while (true)
		{
			if (nullptr == pCurFinalNode->pNextNode)
			{
				break;
			}

			pCurFinalNode = pCurFinalNode->pNextNode;
		}
		pCurFinalNode->pNextNode = pNode;
	}

	++_pList->iCount;
}

// 재귀함수버전
// "좋은 방법은 아님" << 스택메모리가 크지 않기 때문에 터져버림
//void Release(tNode* _pNode)
//{
//	if (nullptr == _pNode)
//	{
//		return;
//	}
//	Release(_pNode->pNextNode);
//	free(_pNode);
//}
//
//void ReleaseList(tLinkedList* _pList)
//{
//	Release(_pList->pHeadNode);
//}

void ReleaseList(tLinkedList* _pList)
{
	tNode* pDeleteNode = _pList->pHeadNode;
	while (nullptr == pDeleteNode)
	{
		tNode* pNext = pDeleteNode->pNextNode;
		free(pDeleteNode);
		pDeleteNode = pNext;
	}
}