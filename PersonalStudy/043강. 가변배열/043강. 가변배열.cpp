﻿// 043강. 가변배열


#include <iostream>
#include "Arr.h"
int main()
{
	// 이전까지 배운 배열의 크기는 고정되어 있었음
	int arr[10] = {};

	// 아래는 될수가 없음
	// 안되는 이유 : a는 변수다 << 변수는 프로그램을 실행해봐야 알수있는 값 << 배열의 갯수가 런타임중에 결정되는것
	// 런타임중에 결정되는 건 동적할당
	// 함수는 메모리해제를 신경안써도 되는 이유와 연관됨
	// 내가 작성한 코드가 컴파일 될 떄 메인 함수가 사용하는 메모리 크기는 정해져있어야 자동으로 해제해주는 것
	// 그치만 배열의 갯수를 인자로 받으면 메인함수의 스택 크기를 컴파일러가 알 수 없음
	// int a = 100;
	// int brr[a] = {};

	// 가변배열
	// 프로그램이 실행하는 도중에 필요한 만큼 줄어들었다 늘어났다 하는 배열을 만들고 싶음
	// 지역변수로는 불가능

	// 구조체(사용자가 만든 자료형) 내부에서도 동일하게 적용됨
	// 구조체가 몇 바이트인지 결정이 안됨
	// 자료형이기 때문에 class A라고 했을 떄 A가 의미하는 바는 정해져야함
	//class A
	//{
	//	 int a = 100;
	//   int arr[a] = {};
	//};

	// 그래서 힙 메모리 영역을 배울 것임
	// 객체(Instance)
	// int a ; << 여기서 "int는 자료형" "객체는 a" << int라는 자료형을 실제로 a라는 이름으로 구현을 한 것임

	tArr arr0;
	tArr arr1;
	tArr arr2;
}
