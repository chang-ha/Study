#include<iostream>
int Add(int _a, int _b)
{
	return _a + _b;
}

int main()
{
	{
		int iData = Add(100, 200);


		// 우리가 쓰는 프로그램은 한가지 기능 딱 하고 꺼지는 프로그램이 아님
		// 그럼 프로그램이 왜 안꺼지나??
		// 무언가 프로그램이 종료되지 않도록 하는 기능이 있다는 것
		// 반복문
		// 대표적인 2가지
		// 1. for문
		for ( /*반복자(i) 초기화, 딱 한번만 실행됨*/
			; /*반복자(i)의 조건을 체크하는 부분 == 조건이 틀릴경우 반복문 정지 (true or false가 들어와야 함*/
			; /*반복자(i) 변경 << 반복자가 바뀌지 않으면 무한히 for문 반복함*/)
		{

			// for문 안도 외부와 단절된 지역
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			printf("for문\n");
			if (i % 2 == 1)
			{
				continue;
			}
			printf("Output Test\n");
			// continue; << continue를 만나면 아래를 실행하지 않고 다시 반복실행
			// break; << break를 만나는 순간 반복문이 아예 종료되어버림
		}

		// 2. while문
		int i = 0;
		while (/*반복자 조건 체크*/i < 2)
		{
			printf("while문\n");
			printf("Output Test\n");
			++i;
		}
	}
	//scanf();
	return 0;
}