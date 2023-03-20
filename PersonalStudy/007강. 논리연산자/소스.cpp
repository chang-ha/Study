

int main()
{
	{
		// 논리연산자
		// ! = 논리 반전(역) << 논리를 반전시킴 (참은 거짓으로, 거짓은 참으로)
		//  &&(AND 연산자) = 논리 곱 << 양쪽의 피 연산자가 둘 다 참일때 참, 둘 중 하나라도 거짓이면 거짓
		//  ||(OR 연산자) = 논리 합 << 둘 중 하나라도 참이면 참, 둘다 거짓이면 거짓
		// 참(true)과 거짓(false)
		// 참(true) : 0이 아닌 모든수는 참 (대표적으로 1) << 참을 정수로 바꾸면 1을 줌
		// 거짓(false) : 0
		int value = true;
		bool truefalse = true;
		bool Inttrue = 100; // true로 받아들임
		int size = sizeof(Inttrue); // 1byte
		truefalse = !truefalse;

		// !연산자는 일반 자료형에도 통함
		int value1 = 100;
		value1 = !value1; // 0이 아닌수는 다 참으로 받아들임, true를 반전해서 false로 바뀌고 정수형으로 바뀌어 0의 값이 들어감

		// &&(AND) 연산자
		truefalse = 100 && 200; // true
		value1 = 100 && 200; // 1
		truefalse = 0 && 200; // false

		// ||(OR) 연산자
		truefalse = 0 || 200; // true
		truefalse = 0 || 0; // false

		// 비교연산자
		// == << 양쪽 피 연산자가 같은지 비교하는 연산자
		// != << 양쪽 피 연산자가 다른지 비교하는 연산자
		// >, <, >=, <=  << 양쪽 피 연산자를 비교했을 때 오른쪽 or 왼쪽이 더 큰지 비교하는 연산자

		// bool 자료형에 값을 넣으면 무조건 0(false)과 1(true)로 바뀌어버림
	}

}