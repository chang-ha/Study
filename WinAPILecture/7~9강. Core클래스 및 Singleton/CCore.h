#pragma once
// 정적멤버를 데이터영역에 올려서 쓰는 방법
#include "define.h"

class CCore
{
public:
	// 정적함수로 정적멤버를 받아오는 것은 동일
	//static CCore* GetInst()
	//{
	//	// 데이터영역 메모리를 사용(core객체 생성)
	//	// 정적변수는 최초에만 초기화되고 그 후에는 무시함
	//	// 정적변수는 해당 함수 안에서만 접근 가능하지만, return값이 주소값으로 주어졌으니 외부에서 해당 주소로 접근가능
	//	// + 메모리 해제는 신경쓸 필요가 없음(동적할당이 아니기 때문)
	//	//	 위의 사항이 항상 장점인가??? XX
	//	//	 단점 : 내가 원하는 때에 싱글톤 객체를 지울수(해제할수)없다. << 그럼 동적할당과 해당 방법 중 정답이 있냐?? X << 코딩에 정답이 어딨어 << 상황에 맞게 사용하면 됨
	//	static CCore core;
	//	return &core;
	//}
	
	// 매크로로 싱글톤패턴 
	SINGLE(CCore);

	int init(HWND _hWnd, POINT _ptResolution);
	void progress();
protected:

private:
	HWND m_hWnd;		  // 메인 윈도우 핸들
	POINT m_ptResoultion; // 메인 윈도우 해상도
	CCore();
	~CCore();
};

