﻿// 027강. 포인터


int main()
{
	// 포인터 변수
	// 포인터는 주소를 가리키는 기능
	// 포인터 변수는 그런 기능을 수행하는 변수
	
	// 이 포인터가 아무것도 가리키지 않는다고 초기화
	// *을 안붙이면 내가 선언한 변수는 int자료형
	// int자료형은 4바이트, *이 붙는순간 int*자료형
	// int를 가리키는 자료형
	int* intPtr = nullptr; // << 0을 넣은것임(실제 데이터 관점)

	// i의 주소를 저장하고 있는 iPtr
	// c++의 강점 : 주소를 직접 쓸 수 있다. (받아올 수 있다)
	// 포인터는 표현방식이 정수일까? 실수일까? << 정수타입
	// 주소의 단위 ex) 100번지와 105번지는??? 몇 차이인가??? << 5바이트 차이(비트 아님)
	// 세부적으로 비트를 부여할 수 있나??? X ("주소값 최소단위가 바이트단위")
	int i = 0;
	int* iPtr = &i;

	// iPtr의 주소를 참조하겠다 (해당 주소로 가봅시다)
	// 주소로 접근해서 값을 수정하는 문법
	*iPtr = 100;

	// 그럼 왜 *만 붙이면 되지 왜 자료형을 붙여서 구분할까??
	// 포인터가 알고있는건 주소 그 자체
	// 그 주소에 있는게 int인지 char인지 알아야 하기 때문에
	// 해당 주소로 가서 몇 바이트 접근하는지도 중요
	// int면 4바이트, char는 1바이트

	float f = 3.f;
	// 강제 캐스팅을 통해 int* 변수에 float* 변수를 넣어줌
	// int와 float는 둘 다 4바이트 이지만 표현방식이 다름
	int* iPtr = (int*) & f;
	// float변수의 주소를 강제로 int*에 넣고
	// 그 값을 다시 int로 받아서 확인해보면 이상한 값이 나옴
	// 실수와 정수가 표현방식이 다르기 때문
	int l = *iPtr;
}

