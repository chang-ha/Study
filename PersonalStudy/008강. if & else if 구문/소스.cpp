int main()
{
	{
		// 구문(if esle구문, switch case구문)
		// if else 구문
		int data = 0;
		if (100 && 200) // ()안에 true라서 실행됨
		{
			data = 100;
		}

		if (0 && 200) // ()안에 false라 실행되지 않음
		{
			data = 200;
		}

		if (data == 200) // data는 거짓이라 실행되지 않음
		{

		}

		// 컴파일러 최적화로 인해 if의 조건문이 거짓이면
		// if문이 실행되지 않으니 해당 코드는 지워버림
		// Debug모드면 하나하나 다 실행, Release모드로 하면 최적화해버림

		if (true)
		{
			// 조건이 true면 실행
		}
		else
		{
			// 조건이 false면 실행
		}

		// else if는 계속 달 수 있음
		if (true)
		{

		}
		else if (true)
		{

		}
		else if (true)
		{

		}
		else
		{

		}

	}

	// else는 없어도 되긴 함

}