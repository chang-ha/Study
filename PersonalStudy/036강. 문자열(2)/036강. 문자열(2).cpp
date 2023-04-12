﻿// 036강. 문자열(2)


#include <iostream>
#include <wchar.h> // wcslen을 쓰려고
int main()
{
	// ' '앞에 L이 붙으면 2바이트로 취급하고
	// ' '앞에 L이 안붙으면 1바이트로 취급??????XXX
	// 정확히 말하면 멀티바이트셋이라고 인자길이에 따라 가변적으로 받아들인다 (Multi : 동시에, 여러개 << 어떨때는 1바이트, 어떨때는 2바이트 등...)
	// 그래서 한글도 들어갈 수 있음 (한글은 2바이트)
	// 현재는 쓰이지 않고 있음 (마이크로소프트에서만 이전 윈도우와의 호완을 위해 사용 중)
	// 문제점
	//	1. 어떤 문자는 1바이트, 어떤 문자는 2바이트 일때
	//	내가 문자가 몇 개 인지 세고 싶은데 기준은????
	//	그래서 값을 확인해보면
	//	한 = 199, 209 (2바이트로 보면 5만얼마)
	//	글 =		, 219 (2바이트로 보면 4만얼마)
	//	2바이트 부분에 해당하는 곳 비트를 보면 110x xxxx로 되어 있음
	//	맨 앞에 110 비트가 의미한느 것이 2바이트 짜리로 읽어라는 뜻임
	//	그래서 2바이트를 1글자로 인식할 수 있음 << 불편함, 그냥 와이드바이트하자....;;
	char szTest[10] = "abc한글";

	// 멀티바이트는 다른것(UTF-8등)과의 호완성이 잘 맞지 않아서
	// 와이드바이트(모든 문자를 2바이트로)인 유니코드로 하는게 호완성이 더 좋음
	wchar_t szTestW[10] = L"abc한글"; // << 한칸 한칸이 2바이트

	wchar_t szName[10] = L"Raimond";
	int iLen = wcslen(szName); // << wcslen은 문자열의 길이를 알려주는 함수
	// wcslen은 인자로 왜 *로 받을까??? 범용적으로 쓰일려면 어떤 문자열을 주더라도 길이를 알려줄 수 있어야함
	// 그래서 함수가 문자열에 접근해 봐야 하니까 문자열의 시작주소를 인자로 줘야함
}
