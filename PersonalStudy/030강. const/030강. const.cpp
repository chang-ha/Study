// 030강. const


#include <iostream>
int main()
{
	{
		// const
		// 변수의 앞에 const를 붙일 수 있음
		const int Value = 100;
		// const를 붙이면 변수가 상수화가 되어버림
		// 값이 바뀔수 없는 상태가 되어버림
		// 이런 값들(바뀔수 없는 값들)을 R-Value(상수)라고 한다
		// 바뀔수 있는 값들은 L-Value(변수)라고 한다.

		// Value = 10; << 말이 안됨 (100 = 10과 동일한 코드)

		// 그럼 Value와 상수 100은 차이가 전혀 없는가?????? X
		// 문법적으로 Value에 const가 붙어서 바꿀수 없는거지
		// 메모리적으로 못바꾸는건 아님 (100은 절대 바꿀수 없음)
		// ex)
		int* pInt = (int*)&Value;
		*pInt = 300;
		printf_s("Value : %d\n", Value);
	}
}