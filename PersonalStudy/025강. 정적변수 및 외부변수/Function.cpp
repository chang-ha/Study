#include "Function.h"
#include "Common.h"

// Function.cpp에 콕 박혀있음
static int istatic = 0;

// 아무 파일에서나 실체를 만들어주면 된다.
// 한번에 취합될 때 나중에 링커가 연결을 해줌
// 실체를 안만들어주면 "확인할 수 없는 외부참조입니다"
int iextern = 0;
