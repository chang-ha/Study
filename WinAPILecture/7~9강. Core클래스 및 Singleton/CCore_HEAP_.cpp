#include "CCore_HEAP_.h"
#include "pch.h"

// 정적멤버의 실체를 구현해줘야함 (안해주면 LINK에러 발생)
CCore_HEAP_* CCore_HEAP_::g_pInst = nullptr;