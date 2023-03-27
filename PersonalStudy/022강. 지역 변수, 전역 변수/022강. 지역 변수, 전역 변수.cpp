#include <iostream>

// 변수의 종류
// 1. 지역변수
// 2. 전역변수 << 데이터영역
// 3. 정적변수 (static) << 데이터영역
// 4. 외부변수 (extern) << 데이터영역

// 메모리 영역
// 1. 코드영역(읽기 전용, ROM = ReadOnlyMemory)
// 2. 데이터영역
//		<< 우리 프로그램이 실행되면서(main함수가 호출되면서)
//		<< 동시에 데이터영역이 만들어짐
//		<< 종료 시 해체
//		<< 프로그램이 실행되는 내내 존재하고 있음
// 3. 힙영역
// 4. 스택영역


// 전역변수
// 데이터 영역
int i = 0;

void Test()
{
	int h = 0;
	++h;
	// Value = 100 << Main에 있는 Value는 인식할 수 없음
}

void GlobalTest()
{
	++i;
}

int main()
{
	// 지역변수
	int Value = 0;

	Test(); // << Test함수가 호출되어도 h값은 변하지 않음
	Test();
	Test();
	Test();

	GlobalTest(); // << GlobalTest함수가 호출되면 i값이 +1씩 증가
	GlobalTest();
	GlobalTest();
	GlobalTest();
}