// 033강. void


#include <iostream>
int main()
{
	// void
	// 1. 함수가 반환할 게 없다

	// 2. void*
	// 주소를 저장하는 변수지만 해당 위치로 갔을떄
	// 자료형을 뭐로 판단할 지 정하지 않은(void) 포인터
	void* pVoid = nullptr;

	// 자료형이 정해지지 않았다 == 어떤 변수의 주소값이든지 받을 수 있다.
	int i = 0;
	float f = 0.f;
	double d = 0.;
	long long ll = 0;

	// void*는 주소를 넣어줬을 때 해당 주소의 원형을 특정 데이터타입으로 해석하지 않음
	pVoid = &i;
	pVoid = &f;
	pVoid = &d;
	pVoid = &ll;

	// 그래서 역참조가 불가능
	// *pVoid << 불가능
	// 역참조를 하려면 해당 주소가 가리키고 있는 주소를 해석하는 자료형이 필요
	// 그래서 접근하는 주소가 몇 바이트인지??, 해당 주소의 비트를 어떻게 해석할지 (int?? double??) 정할 수 있다.

	// 주소연산도 당연히 안됨
	// pVoid + 1;
	// == pVoid의 주소값 + 1 * sizeof(pVoid의 자료형 바이트 크기)


}