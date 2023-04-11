// 031강. const와 포인터


#include <iostream>
int main()
{
	// const와 포인터
	int a = 0;
	int b = 1;
	int* intPtr = &a;

	// 포인터변수는 아래와 같이 2가지 값을 바꿀 수 있음
	// 1. 가리키는 대상의 값(a)의 값을 바꾼다
	*intPtr = 1;

	// 2. 가리키는 대상을 바꾼다.
	intPtr = nullptr;


	// 그래서 포인터에서는 const가 2가지 기능이 있음.
	// 1. 가리키는 대상의 값을 못바꾸게(상수화) 한다.
	const int* pConstInt = &a;
	// *pConstInt = 100; << 불가능(식이 수정할 수 있는 lvalue여야 합니다. 지금은 rvalue라는 뜻임)
	// 가리키는 대상은 바꿀수 있다.
	pConstInt = &b;

	// 2. 가리키는 대상을 못바꾸게 한다.(==Reference)
	int* const pIntConst = &a;
	// 가리키는 대상의 값은 바꿀 수 있다.
	*pIntConst = 100;
	// pIntConst = &b;
	// 가리키는 대상은 바꿀수 없다.

	// 둘 다 붙일수도 있다.
	const int* const pConstIntConst = nullptr;
}