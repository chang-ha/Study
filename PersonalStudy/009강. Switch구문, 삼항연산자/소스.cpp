int main()
{
	// switch구문은 else if구문과 유사함
	// switch구문
	// case와 동일한 값이면 실행
	switch (10)
	{
	case 10:

		break;
	case 20:

		break;
	default:

		break;
	}
	// break가 없으면 코드는 밑으로 계속 실행

	// switch구문을 else if로 바꿔보면
	// else if 구문
	// if문은 조건이 길어지면 가독성이 떨어짐
	int iTest = 10;
	if (iTest == 10)
	{

	}
	else if (iTest == 20)
	{

	}
	else
	{

	}

	if (iTest == 10 || iTest == 20 || iTest == 30)
	{

	}
	else
	{

	}


	// 삼항연산자 << 자칫 가독성이 떨어질 수도 있음
	// iTest == 20이 참이면 iTest = 100, 거짓이면 iTest = 200
	iTest == 20 ? iTest = 100 : iTest = 200;

	// if, else if 구문으로 바꾸면
	if (iTest == 20)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}
}