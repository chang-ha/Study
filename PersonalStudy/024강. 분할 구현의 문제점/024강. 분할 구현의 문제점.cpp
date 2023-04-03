// 024강. 분할 구현의 문제점


#include "Function.h"

// 헤더와 cpp파일을 나누면
// 앞서 배운 내용인 Global변수가 의미가 없어져버림
// 다른 헤더나 cpp파일에서 사용하고 싶은데 거기서는 전역변수를 알수가 없음
// 그럼 헤더에 전역변수 선언하면 되지않나???
// #include는 복붙형태로 불러오는 것이기 때문에 헤더에서 전역변수 선언을 하면
// 그 헤더를 #include한 cpp파일 전부에 전역변수가 선언되어버림
// 그래서 같은 이름의 변수를 여러번 정의한 꼴이 되어서 에러가 발생
// 이를 해결하기 위해 나온것이
// 1. 정적변수(static)
// 2. 외부변수(extern)
int main()
{
	Function NewFunction;
	int Value = NewFunction.Mul(10, 20);
}