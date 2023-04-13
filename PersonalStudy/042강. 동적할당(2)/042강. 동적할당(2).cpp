// 042강. 동적할당(2)


#include <iostream>
void Test(int a)
{
	printf_s("%d\n", a);
}
int main()
{
	// 동적할당
	// 1. 런타임 중에 대응 가능
	// 2. 사용자가 직접 메모리를 관리해줘야함(해제)

	Test(10);

	int iInput = 0;
	scanf_s("%d", &iInput);

	int* iPtr = nullptr;
	if (100 == iInput)
	{
		iPtr = (int*)malloc(100);
	}

	if (nullptr != iPtr)
	{
		// free함수는 내가 가리키는 주소의 
		// "힙메모리를 해제하는 함수"
		// "반드시 힙메모리의 주소를 넣어줘야함"
		// iPtr이 해제되는건 아님
		free(iPtr);
	}
}