#include <iostream>

int main()
{
	{
		// 배열
		int iArray[10] = {};
		// 개별요소는 어떻게 접근하나??
		// 인덱스 접근
		iArray[4] = 10; // 5번째 요소에 접근 (제로카운트)
		// iArray[10]에 접근하면 터진다....
		// 특히 인덱스값이 변수이면 조심해야함
		
		// 배열은 메모리가 연속적인 구조
		// int가 10개 연속으로 존재함
		// {iArray[0], iArray[1], iArray[2], iArray[3], ..., iArray[9]}
	}



}