#include <iostream>

// 함수
// Factorial
// !8
int Factorial(int _iNum)
{
	int iValue = 1;
	for (int j = 0; j < _iNum - 1; ++j)
	{
		iValue *= (j + 2);
	}
	return iValue;
}

int main()
{
	// !i 만드는 함수
	// main에서 만들면 매번 사용할 때 마다 복붙해서 써야하기 때문에 불편함
	// 그래서 모듈화를 위해 함수를 따로 만들어 놓기
	int iValue = Factorial(4);
	iValue = Factorial(10);

	return 0;
}
