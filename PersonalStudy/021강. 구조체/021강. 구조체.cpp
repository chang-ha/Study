#include <iostream>

// 사용자 정의 자료형
// typedef << type을 재정의
// 컴파일러는 INT == int로 본다
typedef int INT;

// struct _tagMySt를 MYST로 재정의 한 것임 << MYST만 써도 변수선언 가능해짐 (C스타일)
// C++에서는 굳이 이렇게 할 필요가 없음
typedef struct _tagMySt
{
	int a;
	float f;
}MYST;
 
typedef struct _tagBig
{
	// 구조체 안에 또 구조체를 넣을 수 있다.
	MYST k;
	int i;
	char c;
}BIG;

// C++스타일
struct MyStruct
{
	int i;
	short s;
};
int main()
{
	{
		// 구조체
		MYST t = {100, 3.14f}; // 배열초기화와 유사함
		int iSize = sizeof(MYST);
		// 자료형 내부의 멤버를 사용하기 위해선 .을 눌러야함
		// t.a = 10;
		// t.f = 10.2312f
	}
	return 0;
}
