#include <stdio.h> // << 전처리기 (먼저 작업하는 내용)

int main()
{
	// 콘솔창에 내가 원하는 문자열을 띄우는 기능
	{ 
		// printf
		//5printf("abcdef %d \n", 10);
		for (int i = 0; i < 10; i++)
		{
			printf("Output i : %d\n", i); // 정수형
		}
		for (float i = 0; i < 10; i++)
		{
			printf("Output i : %f\n", i); // 실수형
		}
	}

	{
		// scanf << 콘솔창으로 부터 내가 지정한 변수를 입력 받을것임
		int iInput = 0;
		scanf_s("%d", &iInput);
		int a = 0;
	}

	return 0;
}
