#include <iostream>

void Test(int _a)
{
	_a = 500;
}

void Test_Ptr(int* _a)
{
	*_a = 500;
}
int main()
{
	// 문제 1.
	short sArr[10] = { 1,2,3,4,5,6,7,8,9,10 }; // short 포인터
	int* pI = (int*)sArr; // short포인터를 강제로 int포인터로 바꿈
	int iData = *((short*)(pI + 2)); // int포인터에서 +2를 의미하는 것 == 주소값이 8바이트 증가 << 이를 다시 short배열로 바꿔서 접근 (int포인터로 접근하면 이상한 값으로 나옴)
	printf("1번 문제 정답 : %d\n", iData);

	// 문제 2.
	char cArr[2] = { 1, 1 }; // 100번지에 1, 101번지에 1
	short* pS = (short*)cArr; // short포인터로 바꿈
	iData = *pS; // 값을 short로 보고 있음 == 0b0000000100000001 == 257 (2^8 + 2^0) << short포인터로 접근해서 나오는 에러?? (의도한 값이랑 다른 값이 나옴)
	printf("2번 문제 정답 : %d\n", iData);

	int a = 100;
	Test(a);
	printf("출력 : %d\n", a); // 100이 출력됨

	Test_Ptr(&a);
	printf("출력 : %d\n", a); // 500이 출력됨

	// 왜 scanf_s는 주소값을 받았을까?
	// 내가 입력한 데이터의 주소값을 받아오기 위해
	// scanf_s("%d", &a);
	return 0;

}

