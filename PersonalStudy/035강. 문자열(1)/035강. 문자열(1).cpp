// 035강. 문자열(1)


#include <iostream>
int main()
{
	// 문자
	// char(1), wchar(2)
	char c = 'a';
	wchar_t wc = L'a'; // 2바이트 문자형은 앞에 L을 붙여줘야한다.

	char szChar[10] = "abedef";
	wchar_t szWChar[10] = L"abcdef"; // == szWChar[10] = {97, 98, 99, 100, 101, 102};

	// 포인터로 초기화도 가능
	// 1. 문자열은 주소값을 반환하기 때문에 포인터로 받을 수 있음 << 시작주소(a의 주소)를 받음
	
	const wchar_t* pChar = L"abcdef";

	// szWChar은 2바이트 10개짜리 배열을 만들어서 거기에 'a' ... 'f'까지 "값을 복사한 것"
	// pChar은 "abcdef"의 시작 "주소를 가리키고 있는 것"

	// szWChar배열의 2번째 칸에 'z'값을 넣는다(복사한다)
	szWChar[1] = 'z';

	// pChar[1] = 'z'; == *(pChar + 1) = 'z' << 이것은 10 = 11과 비슷한 뜻임
	// 내가 작성한 "abcdef"에 접근해서 b를 z로 바꿔라 << 프로그램 실행 중 코드영역을 수정하는 꼴이 되어버림 
	// 코드영역은 Read Only Memory (읽기전용) 이라서 절대 바뀌면 안됨
	// 그래서 pChar를 const로 받은 것임 << 코드영역에 있는 문자열을 수정하면 안되기 때문
	// wchar_t* pChar = L"abcdef"; << 컴파일러가 허용하지 않음
}
