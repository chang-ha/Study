// 040강. 구조체 포인터



#include <iostream>
typedef struct _tagMyst
{
	// "구조체 안에 있는것은 변수가 아닌 멤버!!!"
	int a; // 4바이트
	float f; // 4바이트
}MYST;
int main()
{
	// 구조체 포인터
	MYST s;

	// 변수
	int a = 0;
	// 변수(구조체)
	s;
	// 변수의 멤버(int 파트)
	s.a;

	
	MYST* sPtr = &s;
	// sPtr + 1; // +1 하면 8바이트씩 계산
	(*sPtr).a = 100; // sPtr->a = 100;
}