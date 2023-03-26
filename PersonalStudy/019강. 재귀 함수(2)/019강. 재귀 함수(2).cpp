#include <iostream>

// 재귀함수를 이용한 Factorial
int Factorial_Recursion(int _iNum)
{
	// 7! == 7 * 6!
	// 6! == 6 * 5! ...
	if (_iNum == 1) // 1! == 1
	{
		return 1;
	}
	return _iNum * Factorial_Recursion(_iNum - 1);
}

// 피보나치 수열 (1 1 2 3 5 8 13 21 34 55...)
int Fibonacci(int _iNum)
{
	if (_iNum == 1 || _iNum == 2)
	{
		return 1;
	}
	// 3번쨰 숫자(2)를 구하려면 연산을 1번 해야함
	// 4번쨰 숫자(3)를 구하려면 연산을 2번 해야함...
	// n번째 숫자(x)를 구하려면 연산을 n-2번 해야함
	// 변수1, 변수2에 1,1을 넣어놓고 << 그 후에 변수1에 변수2, 변수2에 더한 결과값을 넣어줌...
	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue = 0;

	for (int i = 0; i < _iNum - 2; ++i)
	{
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}
	return iValue;
}

int Fibonacci_Recursion(int _iNum)
{
	int iVaule = 0;
	if (_iNum == 1 || _iNum == 2)
	{
		return 1;
	}
	return Fibonacci_Recursion(_iNum - 1) + Fibonacci_Recursion(_iNum - 2);
}
int main()
{
	{
		int iVaule = Factorial_Recursion(10);
	}
	{
	}
}
int iVaule = Fibonacci(10);

#include <iostream>

// 재귀함수를 이용한 Factorial
int Factorial_Recursion(int _iNum)
{
	// 7! == 7 * 6!
	// 6! == 6 * 5! ...
	if (_iNum == 1) // 1! == 1
	{
		return 1;
	}
	return _iNum * Factorial_Recursion(_iNum - 1);
}

// 피보나치 수열 (1 1 2 3 5 8 13 21 34 55...)
int Fibonacci(int _iNum)
{
	if (_iNum == 1 || _iNum == 2)
	{
		return 1;
	}
	// 3번쨰 숫자(2)를 구하려면 연산을 1번 해야함
	// 4번쨰 숫자(3)를 구하려면 연산을 2번 해야함...
	// n번째 숫자(x)를 구하려면 연산을 n-2번 해야함
	// 변수1, 변수2에 1,1을 넣어놓고 << 그 후에 변수1에 변수2, 변수2에 더한 결과값을 넣어줌...
	int iPrev1 = 1;
	int iPrev2 = 1;
	int iValue = 0;

	for (int i = 0; i < _iNum - 2; ++i)
	{
		iValue = iPrev1 + iPrev2;
		iPrev1 = iPrev2;
		iPrev2 = iValue;
	}
	return iValue;
}

int Fibonacci_Recursion(int _iNum)
{
	int iVaule = 0;
	if (_iNum == 1 || _iNum == 2)
	{
		return 1;
	}
	return Fibonacci_Recursion(_iNum - 1) + Fibonacci_Recursion(_iNum - 2);
}
int main()
{
	{
		int iVaule = Factorial_Recursion(10);
	}
	{
		int iValue = Fibonacci(10);
		iValue = Fibonacci_Recursion(10);
		// 재귀함수로 피보나치를 만들면 엄청나게 느림
		// 함수호출횟수가 2의 제곱승수만큼 늘어남...
		// 재귀함수는 충분히 고려하고 함부로 쓰면 안됨
	}
}

