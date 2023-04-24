#pragma once
// 자주 사용하는 함수는 매크로로 만들어 둘 것임
// 매크로의 주의점
// 1. 함수가 아니기 때문에 (치환문법) 그냥 매크로에 적힌대로 복붙해야 결과값을 오해하지 않음

// #define SINGLE(type) static type* GetInst() {static type mgr; return &mgr;}
// 매크로 함수를 보기좋게 하려면 \를 뒤에 넣으면 됨

#define SINGLE(type) static type* GetInst() \
{\
	static type mgr;\
	return &mgr;\
}