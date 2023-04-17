#pragma once

typedef struct _tabArr
{
public:
	int* pInt; // 데이터를 저장시킬 곳의 시작주소를 알아야 함
	int iCount; // 현재 데이터를 넣어야할 장소를 알아야 하니, 몇 개의 데이터를 가지고 있는지 알아야함
	int iMaxCount;
protected:

private:

}tArr;

// 배열의 초기화 함수
// 정의부 만들기 단축키
// Ctrl + . (키패드 .은 제외) or Alt + enter
void InitArr(tArr* _pArr);

// 배열의 메모리(힙영역) 해제 함수
void ReleaseArr(tArr* _pArr);

// 데이터를 넣어주는 함수
void PushBack(tArr* _pArr, int _iData);

// 힙영역의 공간을 재할당하는 함수
void Reallocte(tArr* _pArr);