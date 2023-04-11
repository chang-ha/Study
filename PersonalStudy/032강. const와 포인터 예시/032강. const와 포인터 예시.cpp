// 032강. const와 포인터 예시


#include <iostream>
// 함수의 parameter를 그냥 int로 받으면
// 새로운 int _a가 생성되어 값을 복사붙여넣기 하는 것임
// 지금은 간단하니까 상관없지만 나중에 paramter의 바이트크기가 커지면 비효율
//void Output(int _a)
//{
//
//}

// 그래서 parameter(변수)를 참조형(포인터)로 받으면 효율적임
//void Output(int* _a)
//{
//
//}
// 그런데 a입장에서 보면
// 함수에서 데이터 달라해서 줬는데 함수가 마음대로 값을 바꾸면????
// 나는 그걸 원하지 않았음

// 그럴때 인자 앞에 const를 붙임
void Output(const int* _a)
{
	// *_a = 100; << 불가능
}
int main()
{
	{
		int a = 100;
		Output(&a);
	}
}
