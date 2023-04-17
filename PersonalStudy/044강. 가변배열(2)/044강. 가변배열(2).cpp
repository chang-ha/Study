// 044강. 가변배열(2)


#include <iostream>
#include "Arr.h"
int main()
{
	// 만약 최초에 malloc(400)을 할당받았을 떄
	// 후에 데이터를 더 넣고싶으면??? 또 malloc을 한다??? XXXX
	// 
	// malloc();
	tArr s0 = {};
	tArr s1 = {};
	tArr s2 = {};
	
	// tArr의 초기화함수
	InitArr(&s0);
	InitArr(&s1);
	InitArr(&s2);

	// s 객체는 언제 해제되는가??
	// main함수가 종료될 떄
	// 그럼 s객체가 할당한 heap영역의 메모리는 언제 해제되는가??
	// 내가 해제하지 않으면 해제되지 않음 << 메모리 누수로 이어짐

	// 배열에 데이터를 넣는 함수
	for (int i = 0; i < 10; i++)
	{
		PushBack(&s0, i);
	}

	// tArr의 할당한 힙 메모리 해제 함수
	ReleaseArr(&s0);
	ReleaseArr(&s1);
	ReleaseArr(&s2);
}