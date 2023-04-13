// 041강. 동적할당(1)


#include <iostream>
int main()
{
	// 메모리 할당 함수
	// 내가 지정한 사이즈만큼 힙영역에 메모리를 생성시켜줌
	// 100을넣으면 100바이트
	// 그리고 그 주소를 리턴해줌 (포인터변수)
	
	// malloc함수의 리턴값은 원래 void* 임
	// 내 의견 : 주소의 사이즈 크기가 안정해져있어서 그런듯???
	int* pInt = (int*)malloc(100);

	float* pF = (float*)malloc(4);
	*pF = 1.24f;
}
