// 025강. 정적변수 및 외부변수

#include <iostream>
#include "Common.h"
// 자료형 앞에 static을 붙이면 된다.
// static == 정적이다 (<=> dynamic == 동적인 : 움직인다)'
// 정적이다 == 안움직인다 의미 : 내가 선언된 곳에 박혀서 움직이지 않는다.
// 아래 istatic은 main.cpp 파일에 콕 박혀있는것
// 다른 cpp파일에 선언되면 거기에 콕 박혀있음
// 다른 cpp파일에 있는 istatic은 신경안씀
// 각자 자기 파일 전용으로 만들어진 것이라서
// 같은 이름처럼보이지만 실상은 다른 이름임
static int istatic = 0;

int Test()
{
	// 그럼 함수 안에서 static을 선언하면???
	// Test안에 콕 박혀있는 변수임
	// static 변수니까 데이터 영역에 선언(생성)되어 있음
	// i는 Test안에서만 동작한다.
	// 데이터 영역에 생성되니까 함수가 호출되거나 종료되어도 메모리를 유지하지만
	// 해당 함수 안에서만 사용할 수 있다.
	// 전역변수와 다른점은 static은 해당 위치(Test)에서만 사용가능함
	// 오히려 제한을 걸어주는게 기능임 (전역변수와의 차이)
	// 호출될 때 마다 i=0을 하는것이 아님
	// 정적변수를 최초 초기화할 때만 0으로 초기화 하는 것임
	// 최초함수호출 이후에는 static변수 선언은 스킵됨
	static int i = 0;
	i++;

	// 일반 변수는 함수가 호출될 떄 스택 메모리 영역에 생성됨
	int a = 0;
	return i;
}
int main()
{
	// Test함수 안에서만 사용가능한 static 변수니까 main에서 사용 불가능
	// i = 100;
	Test();
	Test();
	Test();
	Test();
	int Value = Test();

	printf_s("Test 함수 호출횟수 : %d\n", Value);
}